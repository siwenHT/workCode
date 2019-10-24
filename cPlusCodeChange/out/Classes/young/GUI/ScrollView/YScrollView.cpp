#include "YScrollView.h"
NS_YOUNG_BEGIN
using namespace cocos2d;
#define SCROLL_DEACCEL_RATE_SLOW  0.95f
#define SCROLL_DEACCEL_RATE_FAST  0.75f
#define SCROLL_DEACCEL_DIST  2.0f
#define BOUNCE_DURATION      0.15f
#define INSET_RATIO          0.2f
#define MOVE_INCH            7.0f/160.0f
static float convertDistanceFromPointToInch(float pointDis)
{
    auto glview = Director::getInstance()->getOpenGLView();
    float factor = ( glview->getScaleX() + glview->getScaleY() ) / 2;
    return pointDis * factor / Device::getDPI();
}
YScrollView::YScrollView()
: _delegate(nullptr)
, _direction(Direction::BOTH)
, _dragging(false)
, _needRelocateContainer(false)
, _container(nullptr)
, _touchMoved(false)
, _touchLength(0.0f)
, _minScale(0.0f)
, _maxScale(0.0f)
, _touchListener(nullptr)
{
}
YScrollView::~YScrollView()
{
}
YScrollView *YScrollView::create(Size size, Node *container)
{
	YScrollView *pRet = new YScrollView();
    if ( pRet && pRet->initWithViewSize(size, container) )
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}
bool YScrollView::initWithViewSize(Size size, Node *container)
{
	if ( Layer::init() )
    {
        _container = container;
        
        if (!this->_container) _container = Layer::create();
	
		_container->ignoreAnchorPointForPosition(false);
        _container->setAnchorPoint( Point(0.0f, 0.0f) );
		_container->setPosition(0.0f, 0.0f);
        
        this->setViewSize(size);
        
        setTouchEnabled(true);
        
        _touches.reserve(EventTouch::MAX_TOUCHES);
        
        _delegate = nullptr;
        
        _direction  = Direction::BOTH;
        
        _touchLength = 0.0f;
        
        this->addChild(_container);
        _minScale = _maxScale = 1.0f;
        return true;
    }
    return false;
}
void YScrollView::setViewSize(Size size)
{
    _viewSize = size;
    Layer::setContentSize(size);
}
const Size &YScrollView::getContentSize() const
{
	return _container->getContentSize();
}
void YScrollView::setContentSize(const Size &size)
{
	if(_container) _container->setContentSize(size);
}
void YScrollView::setTouchEnabled(bool enabled)
{
    _eventDispatcher->removeEventListener(_touchListener);
    _touchListener = nullptr;
    if (enabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        _touchListener->onTouchBegan = CC_CALLBACK_2(YScrollView::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(YScrollView::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(YScrollView::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(YScrollView::onTouchCancelled, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _dragging = false;
        _touchMoved = false;
        _touches.clear();
    }
}
bool YScrollView::isTouchEnabled() const
{
	return _touchListener != nullptr;
}
bool YScrollView::hasVisibleParents() const
{
    auto parent = this->getParent();
    for( auto c = parent; c != nullptr; c = c->getParent() )
    {
        if( !c->isVisible() )
        {
            return false;
        }
    }
    return true;
}
bool YScrollView::onTouchBegan(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->hasVisibleParents())
    {
        return false;
    }
    
    Rect frame = getViewRect();
    
    if ( _touches.size() > 2 ||
         _touchMoved         ||
        !frame.containsPoint(touch->getLocation()) )
    {
        return false;
    }
	if(_container->getActionByTag(1))
		return false;
    if ( std::find(_touches.begin(), _touches.end(), touch) == _touches.end() )
    {
        _touches.push_back(touch);
    }
    if (_touches.size() == 1) 
    {
        _touchPoint     = this->convertTouchToNodeSpace(touch);
        _touchMoved     = false;
        _dragging       = true; 
        _scrollDistance = Point(0.0f, 0.0f);
        _touchLength    = 0.0f;
    }
    else if (_touches.size() == 2) 
    {
        _touchPoint = this->convertTouchToNodeSpace(_touches[0]).
        			  getMidpoint( this->convertTouchToNodeSpace(_touches[1]) );
        
        _touchLength = _container->convertTouchToNodeSpace(_touches[0]).
        			   getDistance( _container->convertTouchToNodeSpace(_touches[1]) );
        
        _dragging  = false;
    }
    return true;
}
void YScrollView::onTouchMoved(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->hasVisibleParents())
    {
        return;
    }
    if ( std::find(_touches.begin(), _touches.end(), touch) != _touches.end() )
    {
        if (_touches.size() == 1 && _dragging) 
        {
            Point moveDistance, newPoint;
            Rect  frame;
            float newX, newY;
            
            frame = getViewRect();
            newPoint     = this->convertTouchToNodeSpace(_touches[0]);
            moveDistance = newPoint - _touchPoint;
            
            float dis = 0.0f;
            if (_direction == Direction::VERTICAL)
                dis = moveDistance.y;
            else if (_direction == Direction::HORIZONTAL)
                dis = moveDistance.x;
            else
                dis = sqrtf(moveDistance.x * moveDistance.x + moveDistance.y * moveDistance.y);
            if (!_touchMoved && fabs( convertDistanceFromPointToInch(dis) ) < MOVE_INCH)
                return; 
            
            if (!_touchMoved) moveDistance = Point::ZERO;
            
            _touchPoint = newPoint;
            _touchMoved = true;
            
            if ( frame.containsPoint(this->convertToWorldSpace(newPoint)) )
            {
                switch (_direction)
                {
                    case Direction::VERTICAL:
                        moveDistance = Point(0.0f, moveDistance.y);
                        break;
                    case Direction::HORIZONTAL:
                        moveDistance = Point(moveDistance.x, 0.0f);
                        break;
                    default:
                        break;
                }
                newX     = _container->getPosition().x + moveDistance.x;
                newY     = _container->getPosition().y + moveDistance.y;
                _scrollDistance = moveDistance;
                this->setContentOffset( Point(newX, newY) );
            }
        }
        else if (_touches.size() == 2 && !_dragging) 
        {
            const float len = _container->convertTouchToNodeSpace(_touches[0]).
            				  getDistance( _container->convertTouchToNodeSpace(_touches[1]) );
            
        }
    }
}
void YScrollView::onTouchEnded(Touch* touch, Event* event)
{
    auto touchIter = std::find(_touches.begin(), _touches.end(), touch);
    
    if ( touchIter != _touches.end() )
    {
    	do
    	{
	    	if ( !this->isVisible() )
	    	{
	    		_touches.erase(touchIter);
	    		break;
	    	}
	    	else
	    	{
		        if (_touches.size() == 1 && _touchMoved)
				{
					_needRelocateContainer = false;
		            this->schedule( schedule_selector(YScrollView::deaccelerateScrolling) );
				}
		        _touches.erase(touchIter);
	        }
        } while(false);
        if (_touches.size() == 0)
	    {
	        _dragging = false;    
	        _touchMoved = false;
	    }
    }
}
void YScrollView::onTouchCancelled(Touch* touch, Event* event)
{
    auto touchIter = std::find(_touches.begin(), _touches.end(), touch);
    _touches.erase(touchIter);
    
    if (_touches.size() == 0)
    {
        _dragging = false;    
        _touchMoved = false;
    }
}
void YScrollView::setContentOffset(Point offset, bool animated)
{
    if (animated) 
    {
    	this->setContentOffsetInDuration(offset, BOUNCE_DURATION);
    }
    else 
    { 
        _container->setPosition(offset);
        if (_delegate != NULL) _delegate->scrollViewDidScroll(this);
    }
}
Point YScrollView::getContentOffset()
{
    return _container->getPosition();
}
void YScrollView::setContentOffsetInDuration(Point offset, float dt)
{
    FiniteTimeAction *scroll, *expire;
    
    scroll = MoveTo::create(dt, offset);
    expire = CallFuncN::create( CC_CALLBACK_1(YScrollView::stoppedAnimatedScroll,this) );
	auto action =  Sequence::create(scroll, expire, NULL);
	action->setTag(1);
    _container->runAction(action );
    this->schedule( schedule_selector(YScrollView::performedAnimatedScroll) );
}
void YScrollView::performedAnimatedScroll(float dt)
{
    if (_dragging)
    {
        this->unschedule( schedule_selector(YScrollView::performedAnimatedScroll) );
        return;
    }
    if (_delegate != NULL) _delegate->scrollViewDidScroll(this);
}
void YScrollView::stoppedAnimatedScroll(Node * node)
{
    this->unschedule( schedule_selector(YScrollView::performedAnimatedScroll) );
    
    if (_delegate != NULL) _delegate->scrollViewDidScroll(this);
	if (_delegate != NULL) _delegate->scrollViewDidStopped(this);
}
void YScrollView::deaccelerateScrolling(float dt)
{
    if (_dragging)
    {
        this->unschedule(schedule_selector( YScrollView::deaccelerateScrolling) );
        return;
    }
    
    
    Size size = _container->getContentSize();
	Point bl = _container->getPosition();
	Point br = Point(bl.x + size.width, bl.y);
	Point tl = Point(bl.x, bl.y + size.height);
	Point tr = Point(bl.x + size.width, bl.y + size.height);
	float decay = _needRelocateContainer ? SCROLL_DEACCEL_RATE_FAST : SCROLL_DEACCEL_RATE_SLOW;
	_scrollDistance     = _scrollDistance * decay;
	float newX = bl.x + _scrollDistance.x;
	float newY = bl.y + _scrollDistance.y;
	bool needRelocateContainer = false;
	Point restore = Point(0.f, 0.f);
	float widthDiff = _viewSize.width - size.width;
	float heightDiff = _viewSize.height - size.height;
	float originX = (widthDiff <= 0) ? _viewSize.width : size.width;
	float limit = originX;
	if(bl.x > 0)
	{
		_needRelocateContainer = true;
		if(bl.x - 0 > limit/3) newX = bl.x;
		restore.x = -(newX - 0);
	}
	else if(br.x < originX)
	{
		_needRelocateContainer = true;
		if(originX - br.x > limit/3) newX = bl.x;
	
		restore.x = -(newX + size.width - originX);
	}
	float originY = (heightDiff <= 0) ? 0 : heightDiff;
	limit = (heightDiff <= 0) ? _viewSize.height : size.height;
	if(bl.y > originY)
	{
		_needRelocateContainer = true;
		if(bl.y - originY  > limit/3) newY = bl.y;
	
		restore.y = -(newY - originY);
	}
	else if(tl.y < _viewSize.height)
	{
		_needRelocateContainer = true;
		if(_viewSize.height - tl.y > limit/3) newY = bl.y;
	
		restore.y = -(newY + size.height - _viewSize.height);
	}
	this->setContentOffset( Point(newX, newY) );
    if(fabsf(_scrollDistance.x) <= SCROLL_DEACCEL_DIST &&
       fabsf(_scrollDistance.y) <= SCROLL_DEACCEL_DIST)
    {
        this->unschedule(schedule_selector( YScrollView::deaccelerateScrolling) );
        if(_needRelocateContainer)
		{
			this->relocateContainer(true, restore);
			_needRelocateContainer = false;
		}
		else
		{
			if (_delegate != NULL) _delegate->scrollViewDidStopped(this);
		}
    }
}
void YScrollView::relocateContainer(bool animated, Point restore)
{
    this->setContentOffset(_container->getPosition() + restore, animated);
}
void YScrollView::addChild(Node *child, int zOrder, int tag)
{
    if (_container != child)
        _container->addChild(child, zOrder, tag);
    else
        Layer::addChild(child, zOrder, tag);
}
void YScrollView::addChild(Node *child, int zOrder)
{
    if (_container != child)
        _container->addChild(child, zOrder);
    else
        Layer::addChild(child, zOrder);
}
void YScrollView::addChild(Node *child)
{
    if (_container != child)
        _container->addChild(child);
    else
        Layer::addChild(child);
}
void YScrollView::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    
	if ( !isVisible() )
		return;
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    
    
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    int i = 0;
	this->beforeDraw();
    if(!_children.empty())
    {
        sortAllChildren();
        
        for( ; i < _children.size(); i++ )
        {
            auto node = _children.at(i);
            if (node && node->getLocalZOrder() < 0)
                node->visit(renderer, _modelViewTransform, flags);
            else
                break;
        }
        
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);
        for(auto it=_children.cbegin()+i; it != _children.cend(); ++it)
            (*it)->visit(renderer, _modelViewTransform, flags);
    }
    else if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }
	 this->afterDraw();
    _director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    
    
    
    
    
}
void YScrollView::beforeDraw()
{
    _beforeDrawCommand.init(_globalZOrder);
    _beforeDrawCommand.func = CC_CALLBACK_0(YScrollView::onBeforeDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&_beforeDrawCommand);
}
void YScrollView::onBeforeDraw()
{
	_scissorRestored = false;
    Rect frame = getViewRect();
    auto glview = Director::getInstance()->getOpenGLView();
    if ( glview->isScissorEnabled() )
    {
        _scissorRestored = true;
        _parentScissorRect = glview->getScissorRect();
        
        if ( frame.intersectsRect(_parentScissorRect) )
        {
            float x = MAX(frame.origin.x, _parentScissorRect.origin.x);
            float y = MAX(frame.origin.y, _parentScissorRect.origin.y);
            float xx = MIN(frame.origin.x+frame.size.width, _parentScissorRect.origin.x+_parentScissorRect.size.width);
            float yy = MIN(frame.origin.y+frame.size.height, _parentScissorRect.origin.y+_parentScissorRect.size.height);
            glview->setScissorInPoints(x, y, xx-x, yy-y);
        }
    }
    else
    {
        glEnable(GL_SCISSOR_TEST);
        glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    }
}
void YScrollView::afterDraw()
{
    _afterDrawCommand.init(_globalZOrder);
    _afterDrawCommand.func = CC_CALLBACK_0(YScrollView::onAfterDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&_afterDrawCommand);
}
void YScrollView::onAfterDraw()
{
    
    if (_scissorRestored)
    {
    
        auto glview = Director::getInstance()->getOpenGLView();
        glview->setScissorInPoints(_parentScissorRect.origin.x, _parentScissorRect.origin.y, _parentScissorRect.size.width, _parentScissorRect.size.height);
    }
    else
    {
        glDisable(GL_SCISSOR_TEST);
    }
}
Rect YScrollView::getViewRect()
{
    Point screenPos = this->convertToWorldSpace(Point::ZERO);
    
    float scaleX = this->getScaleX();
    float scaleY = this->getScaleY();
    
    for ( Node *p = _parent; p != NULL; p = p->getParent() )
    {
        scaleX *= p->getScaleX();
        scaleY *= p->getScaleY();
    }
    
    
    
    if(scaleX < 0.f)
    {
        screenPos.x += _viewSize.width*scaleX;
        scaleX = -scaleX;
    }
    if(scaleY < 0.f)
    {
        screenPos.y += _viewSize.height*scaleY;
        scaleY = -scaleY;
    }
    return Rect(screenPos.x, screenPos.y, _viewSize.width*scaleX, _viewSize.height*scaleY);
}
void YScrollView::updateTweenAction(float value, const std::string &key)
{
}
void YScrollView::pause(Ref* sender)
{
    _container->pause();
    auto &children = _container->getChildren();
    for(const auto &child : children)
        child->pause();
}
void YScrollView::resume(Ref* sender)
{
    auto &children = _container->getChildren();
    for(const auto &child : children)
        child->resume();
    _container->resume();
}

float YScrollView::updatesAbilityDriven(float nested,bool subsequent,int clear)
{
	float enclosed = nested + 714.2f;
	bool designing = subsequent;
	return 907.17f;
}
short YScrollView::operatesRepresenting(float between,std::string swapped)
{
	float vectors = between + 20.13f;
	std::string forestall = swapped;
	bool requires = false;
	 int versus = 70229;
	if(versus == 70229)
	{
		std::string versus = "function  [YScrollView:operatesRepresenting] doing!";
	}
	else
	{
		std::string versus;
		versus.append("operatesRepresenting arguments 1 between need Check!");
		versus.append("operatesRepresenting arguments 2 swapped need Check!");
	}
	return 848;
}
double YScrollView::generallyThingsTable(unsigned short here)
{
	m_compilersOverride = 915;
	return 144.1;
}
void YScrollView::causeArgsClassclick(unsigned short elem,unsigned short variable,std::string chosen)
{
	m_buildInfrequentlySuppress = 'H';
}
void YScrollView::changeInterestingHair(bool eamight)
{
	bool thexercises = eamight;
	float space = 798.17f - 512.9f;
	long promoted = 685 + 642;
	 bool whole = false;
	if(whole)
	{
		std::string whole = "function  [YScrollView:changeInterestingHair] doing!";
	}
	else
	{
		std::string whole;
		whole.append("changeInterestingHair arguments 1 eamight need Check!");
	}
}
void YScrollView::equivalentNonpublic(short ought)
{
	short itas = ought / 593;
	 bool requested = false;
	if(requested)
	{
		std::string requested = "function  [YScrollView:equivalentNonpublic] checking!";
	}
	else
	{
		std::string requested;
		requested.append("equivalentNonpublic arguments 1 ought is ok?!");
	}
}
short YScrollView::thanReflectRealize(bool disadvantages)
{
	bool easiest = disadvantages;
	bool mutually = true;
	std::string requirements = "function  [YScrollView:thanReflectRealize] called!";
	requirements.append("being");
	return 16;
}
float YScrollView::redeclareCollections(double reduce)
{
	double builds = reduce * 631.6;
	long deduce = 602 * 117;
	std::string central = "function  [YScrollView:redeclareCollections] done!";
	central.append("sense");
	return 112.11f;
}
void YScrollView::familyDrivenOperand(long author,long muensure,void * deduction,long similar)
{
	m_conversionchapterBind = nullptr;
}
float YScrollView::signatureUnderstand(void * further,double sample)
{
	m_flagTranslateAccording = 82.14;
	return 984.15f;
}
int YScrollView::predictInttypesReady(void * from,int compilation)
{
	void * through = from;
	int fact = compilation / 566;
	float typically = 895.15f * 619.15f;
	std::string prefer = "function  [YScrollView:predictInttypesReady] done!";
	prefer.append("timalthough4");
	return 552;
}
NS_YOUNG_END
