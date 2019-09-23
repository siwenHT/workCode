#include "fieldComparesImprovements.h"
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
fieldComparesImprovements::fieldComparesImprovements()
: _delegate(nullptr)
, accumulateWhichever(multiplyingTarget::BOTH)
, _dragging(false)
, m_valueViceOptions(false)
, m_protectionCorrectlySoon(nullptr)
, m_positionsSupportEvaluates(false)
, quizWhichever(0.0f)
, _minScale(0.0f)
, _maxScale(0.0f)
, _touchListener(nullptr)
{
}
fieldComparesImprovements::~fieldComparesImprovements()
{
}
fieldComparesImprovements *fieldComparesImprovements::create(Size size, Node *container)
{
	fieldComparesImprovements *pRet = new fieldComparesImprovements();
    if ( pRet && pRet->presenceGreater(size, container) )
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}
bool fieldComparesImprovements::presenceGreater(Size size, Node *container)
{
	if ( Layer::init() )
    {
        m_protectionCorrectlySoon = container;
        
        if (!this->m_protectionCorrectlySoon) m_protectionCorrectlySoon = Layer::create();
	
		m_protectionCorrectlySoon->ignoreAnchorPointForPosition(false);
        m_protectionCorrectlySoon->setAnchorPoint( Point(0.0f, 0.0f) );
		m_protectionCorrectlySoon->setPosition(0.0f, 0.0f);
        
        this->setdereferenceAppearGave(size);
        
        settriggerScopingExecuting(true);
        
        _touches.reserve(EventTouch::MAX_TOUCHES);
        
        _delegate = nullptr;
        
        accumulateWhichever  = multiplyingTarget::BOTH;
        
        quizWhichever = 0.0f;
        
        this->addChild(m_protectionCorrectlySoon);
        _minScale = _maxScale = 1.0f;
        return true;
    }
    return false;
}
void fieldComparesImprovements::setdereferenceAppearGave(Size size)
{
    _viewSize = size;
    Layer::setContentSize(size);
}
const Size &fieldComparesImprovements::getContentSize() const
{
	return m_protectionCorrectlySoon->getContentSize();
}
void fieldComparesImprovements::setContentSize(const Size &size)
{
	if(m_protectionCorrectlySoon) m_protectionCorrectlySoon->setContentSize(size);
}
void fieldComparesImprovements::settriggerScopingExecuting(bool enabled)
{
    _eventDispatcher->removeEventListener(_touchListener);
    _touchListener = nullptr;
    if (enabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        _touchListener->onTouchBegan = CC_CALLBACK_2(fieldComparesImprovements::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(fieldComparesImprovements::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(fieldComparesImprovements::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(fieldComparesImprovements::onTouchCancelled, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _dragging = false;
        m_positionsSupportEvaluates = false;
        _touches.clear();
    }
}
bool fieldComparesImprovements::hideAdditionNontype() const
{
	return _touchListener != nullptr;
}
bool fieldComparesImprovements::fetchHavingSynonym4() const
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
bool fieldComparesImprovements::onTouchBegan(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->fetchHavingSynonym4())
    {
        return false;
    }
    
    Rect frame = pscreenInheritance();
    
    if ( _touches.size() > 2 ||
         m_positionsSupportEvaluates         ||
        !frame.containsPoint(touch->getLocation()) )
    {
        return false;
    }
	if(m_protectionCorrectlySoon->getActionByTag(1))
		return false;
    if ( std::find(_touches.begin(), _touches.end(), touch) == _touches.end() )
    {
        _touches.push_back(touch);
    }
    if (_touches.size() == 1) 
    {
        m_processOfferFamiliar     = this->convertTouchToNodeSpace(touch);
        m_positionsSupportEvaluates     = false;
        _dragging       = true; 
        m_delegatesWaysProgram = Point(0.0f, 0.0f);
        quizWhichever    = 0.0f;
    }
    else if (_touches.size() == 2) 
    {
        m_processOfferFamiliar = this->convertTouchToNodeSpace(_touches[0]).
        			  getMidpoint( this->convertTouchToNodeSpace(_touches[1]) );
        
        quizWhichever = m_protectionCorrectlySoon->convertTouchToNodeSpace(_touches[0]).
        			   getDistance( m_protectionCorrectlySoon->convertTouchToNodeSpace(_touches[1]) );
        
        _dragging  = false;
    }
    return true;
}
void fieldComparesImprovements::onTouchMoved(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->fetchHavingSynonym4())
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
            
            frame = pscreenInheritance();
            newPoint     = this->convertTouchToNodeSpace(_touches[0]);
            moveDistance = newPoint - m_processOfferFamiliar;
            
            float dis = 0.0f;
            if (accumulateWhichever == multiplyingTarget::VERTICAL)
                dis = moveDistance.y;
            else if (accumulateWhichever == multiplyingTarget::HORIZONTAL)
                dis = moveDistance.x;
            else
                dis = sqrtf(moveDistance.x * moveDistance.x + moveDistance.y * moveDistance.y);
            if (!m_positionsSupportEvaluates && fabs( convertDistanceFromPointToInch(dis) ) < MOVE_INCH)
                return; 
            
            if (!m_positionsSupportEvaluates) moveDistance = Point::ZERO;
            
            m_processOfferFamiliar = newPoint;
            m_positionsSupportEvaluates = true;
            
            if ( frame.containsPoint(this->convertToWorldSpace(newPoint)) )
            {
                switch (accumulateWhichever)
                {
                    case multiplyingTarget::VERTICAL:
                        moveDistance = Point(0.0f, moveDistance.y);
                        break;
                    case multiplyingTarget::HORIZONTAL:
                        moveDistance = Point(moveDistance.x, 0.0f);
                        break;
                    default:
                        break;
                }
                newX     = m_protectionCorrectlySoon->getPosition().x + moveDistance.x;
                newY     = m_protectionCorrectlySoon->getPosition().y + moveDistance.y;
                m_delegatesWaysProgram = moveDistance;
                this->setContentOffset( Point(newX, newY) );
            }
        }
        else if (_touches.size() == 2 && !_dragging) 
        {
            const float len = m_protectionCorrectlySoon->convertTouchToNodeSpace(_touches[0]).
            				  getDistance( m_protectionCorrectlySoon->convertTouchToNodeSpace(_touches[1]) );
            
        }
    }
}
void fieldComparesImprovements::onTouchEnded(Touch* touch, Event* event)
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
		        if (_touches.size() == 1 && m_positionsSupportEvaluates)
				{
					m_valueViceOptions = false;
		            this->schedule( schedule_selector(fieldComparesImprovements::whtheSupportsMatrix) );
				}
		        _touches.erase(touchIter);
	        }
        } while(false);
        if (_touches.size() == 0)
	    {
	        _dragging = false;    
	        m_positionsSupportEvaluates = false;
	    }
    }
}
void fieldComparesImprovements::onTouchCancelled(Touch* touch, Event* event)
{
    auto touchIter = std::find(_touches.begin(), _touches.end(), touch);
    _touches.erase(touchIter);
    
    if (_touches.size() == 0)
    {
        _dragging = false;    
        m_positionsSupportEvaluates = false;
    }
}
void fieldComparesImprovements::setContentOffset(Point offset, bool animated)
{
    if (animated) 
    {
    	this->nameMacroDestroyed(offset, BOUNCE_DURATION);
    }
    else 
    { 
        m_protectionCorrectlySoon->setPosition(offset);
        if (_delegate != NULL) _delegate->namingVariousCccccccccc2(this);
    }
}
Point fieldComparesImprovements::getContentOffset()
{
    return m_protectionCorrectlySoon->getPosition();
}
void fieldComparesImprovements::nameMacroDestroyed(Point offset, float dt)
{
    FiniteTimeAction *scroll, *expire;
    
    scroll = MoveTo::create(dt, offset);
    expire = CallFuncN::create( CC_CALLBACK_1(fieldComparesImprovements::operandsAndquerySuited3,this) );
	auto action =  Sequence::create(scroll, expire, NULL);
	action->setTag(1);
    m_protectionCorrectlySoon->runAction(action );
    this->schedule( schedule_selector(fieldComparesImprovements::harderAppliesIncrements) );
}
void fieldComparesImprovements::harderAppliesIncrements(float dt)
{
    if (_dragging)
    {
        this->unschedule( schedule_selector(fieldComparesImprovements::harderAppliesIncrements) );
        return;
    }
    if (_delegate != NULL) _delegate->namingVariousCccccccccc2(this);
}
void fieldComparesImprovements::operandsAndquerySuited3(Node * node)
{
    this->unschedule( schedule_selector(fieldComparesImprovements::harderAppliesIncrements) );
    
    if (_delegate != NULL) _delegate->namingVariousCccccccccc2(this);
	if (_delegate != NULL) _delegate->meddleManageWord(this);
}
void fieldComparesImprovements::whtheSupportsMatrix(float dt)
{
    if (_dragging)
    {
        this->unschedule(schedule_selector( fieldComparesImprovements::whtheSupportsMatrix) );
        return;
    }
    
    
    Size size = m_protectionCorrectlySoon->getContentSize();
	Point bl = m_protectionCorrectlySoon->getPosition();
	Point br = Point(bl.x + size.width, bl.y);
	Point tl = Point(bl.x, bl.y + size.height);
	Point tr = Point(bl.x + size.width, bl.y + size.height);
	float decay = m_valueViceOptions ? SCROLL_DEACCEL_RATE_FAST : SCROLL_DEACCEL_RATE_SLOW;
	m_delegatesWaysProgram     = m_delegatesWaysProgram * decay;
	float newX = bl.x + m_delegatesWaysProgram.x;
	float newY = bl.y + m_delegatesWaysProgram.y;
	bool needRelocateContainer = false;
	Point restore = Point(0.f, 0.f);
	float widthDiff = _viewSize.width - size.width;
	float heightDiff = _viewSize.height - size.height;
	float originX = (widthDiff <= 0) ? _viewSize.width : size.width;
	float limit = originX;
	if(bl.x > 0)
	{
		m_valueViceOptions = true;
		if(bl.x - 0 > limit/3) newX = bl.x;
		restore.x = -(newX - 0);
	}
	else if(br.x < originX)
	{
		m_valueViceOptions = true;
		if(originX - br.x > limit/3) newX = bl.x;
	
		restore.x = -(newX + size.width - originX);
	}
	float originY = (heightDiff <= 0) ? 0 : heightDiff;
	limit = (heightDiff <= 0) ? _viewSize.height : size.height;
	if(bl.y > originY)
	{
		m_valueViceOptions = true;
		if(bl.y - originY  > limit/3) newY = bl.y;
	
		restore.y = -(newY - originY);
	}
	else if(tl.y < _viewSize.height)
	{
		m_valueViceOptions = true;
		if(_viewSize.height - tl.y > limit/3) newY = bl.y;
	
		restore.y = -(newY + size.height - _viewSize.height);
	}
	this->setContentOffset( Point(newX, newY) );
    if(fabsf(m_delegatesWaysProgram.x) <= SCROLL_DEACCEL_DIST &&
       fabsf(m_delegatesWaysProgram.y) <= SCROLL_DEACCEL_DIST)
    {
        this->unschedule(schedule_selector( fieldComparesImprovements::whtheSupportsMatrix) );
        if(m_valueViceOptions)
		{
			this->linkingAroundCmatch(true, restore);
			m_valueViceOptions = false;
		}
		else
		{
			if (_delegate != NULL) _delegate->meddleManageWord(this);
		}
    }
}
void fieldComparesImprovements::linkingAroundCmatch(bool animated, Point restore)
{
    this->setContentOffset(m_protectionCorrectlySoon->getPosition() + restore, animated);
}
void fieldComparesImprovements::addChild(Node *child, int zOrder, int tag)
{
    if (m_protectionCorrectlySoon != child)
        m_protectionCorrectlySoon->addChild(child, zOrder, tag);
    else
        Layer::addChild(child, zOrder, tag);
}
void fieldComparesImprovements::addChild(Node *child, int zOrder)
{
    if (m_protectionCorrectlySoon != child)
        m_protectionCorrectlySoon->addChild(child, zOrder);
    else
        Layer::addChild(child, zOrder);
}
void fieldComparesImprovements::addChild(Node *child)
{
    if (m_protectionCorrectlySoon != child)
        m_protectionCorrectlySoon->addChild(child);
    else
        Layer::addChild(child);
}
void fieldComparesImprovements::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    
	if ( !isVisible() )
		return;
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    
    
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    int i = 0;
	this->incrementingTargetCalto();
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
void fieldComparesImprovements::incrementingTargetCalto()
{
    m_successfulPrecedence.init(_globalZOrder);
    m_successfulPrecedence.func = CC_CALLBACK_0(fieldComparesImprovements::becomeRewritesIntuitive, this);
    Director::getInstance()->getRenderer()->addCommand(&m_successfulPrecedence);
}
void fieldComparesImprovements::becomeRewritesIntuitive()
{
	m_inevitablyFollowing = false;
    Rect frame = pscreenInheritance();
    auto glview = Director::getInstance()->getOpenGLView();
    if ( glview->isScissorEnabled() )
    {
        m_inevitablyFollowing = true;
        m_conventionConsider = glview->getScissorRect();
        
        if ( frame.intersectsRect(m_conventionConsider) )
        {
            float x = MAX(frame.origin.x, m_conventionConsider.origin.x);
            float y = MAX(frame.origin.y, m_conventionConsider.origin.y);
            float xx = MIN(frame.origin.x+frame.size.width, m_conventionConsider.origin.x+m_conventionConsider.size.width);
            float yy = MIN(frame.origin.y+frame.size.height, m_conventionConsider.origin.y+m_conventionConsider.size.height);
            glview->setScissorInPoints(x, y, xx-x, yy-y);
        }
    }
    else
    {
        glEnable(GL_SCISSOR_TEST);
        glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    }
}
void fieldComparesImprovements::afterDraw()
{
    differencesExists.init(_globalZOrder);
    differencesExists.func = CC_CALLBACK_0(fieldComparesImprovements::familiarUnnamedThposition, this);
    Director::getInstance()->getRenderer()->addCommand(&differencesExists);
}
void fieldComparesImprovements::familiarUnnamedThposition()
{
    
    if (m_inevitablyFollowing)
    {
    
        auto glview = Director::getInstance()->getOpenGLView();
        glview->setScissorInPoints(m_conventionConsider.origin.x, m_conventionConsider.origin.y, m_conventionConsider.size.width, m_conventionConsider.size.height);
    }
    else
    {
        glDisable(GL_SCISSOR_TEST);
    }
}
Rect fieldComparesImprovements::pscreenInheritance()
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
void fieldComparesImprovements::updateTweenAction(float value, const std::string &key)
{
}
void fieldComparesImprovements::pause(Ref* sender)
{
    m_protectionCorrectlySoon->pause();
    auto &children = m_protectionCorrectlySoon->getChildren();
    for(const auto &child : children)
        child->pause();
}
void fieldComparesImprovements::resume(Ref* sender)
{
    auto &children = m_protectionCorrectlySoon->getChildren();
    for(const auto &child : children)
        child->resume();
    m_protectionCorrectlySoon->resume();
}

float fieldComparesImprovements::elsewhereWregexCalls(int print,float fragment,char contain,short support)
{
	void * typeinfo;
	typeinfo = nullptr;
	bool specifies;
	specifies = false;
	void * invalid;
	invalid = nullptr;
	return 210.0f;
}
void fieldComparesImprovements::salesSynthesizesHash(unsigned short lock,unsigned short objectsth,unsigned short indicated)
{
	unsigned short show;
	show = 654;
	char returned;
	returned = '1';
	void * directly;
	directly = nullptr;
	bool through;
	through = false;
	short assumes;
	assumes = 306;
}
unsigned short fieldComparesImprovements::changesSpecializing(char distinctive)
{
	long precedence;
	precedence = 135;
	void * wrote;
	wrote = nullptr;
	void * save;
	save = nullptr;
	return 338;
}
void fieldComparesImprovements::familyQuiteCopiesRevise(float developed,long chain,void * omitted,long adaptors)
{
	unsigned short containing;
	containing = 504;
	bool muensure;
	muensure = false;
	long strvec;
	strvec = 326;
	float declare;
	declare = 380.5f;
}
bool fieldComparesImprovements::seeminglyProhibitDiffers(unsigned short work,void * violate,double particular,bool want)
{
	short letters;
	letters = 17;
	bool indexed;
	indexed = false;
	long dynamic;
	dynamic = 984;
	return false;
}
void fieldComparesImprovements::thfunctionCastAside(long accessed,double initializers)
{
	bool sensible;
	sensible = true;
}
char fieldComparesImprovements::integralNestedDeveloped(int indexing,float remaining)
{
	long through;
	through = 752;
	short operands;
	operands = 222;
	bool macro;
	macro = true;
	return '9';
}
NS_YOUNG_END
