#include "increasedTable.h"
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
increasedTable::increasedTable()
: _delegate(nullptr)
, m_tyhaveSketch(imageUndefinedElsewhere::BOTH)
, _dragging(false)
, m_parametersHardest(false)
, m_redefinesConceptually(nullptr)
, randomIndices(false)
, deletesCast(0.0f)
, _minScale(0.0f)
, _maxScale(0.0f)
, _touchListener(nullptr)
{
}
increasedTable::~increasedTable()
{
}
increasedTable *increasedTable::create(Size size, Node *container)
{
	increasedTable *pRet = new increasedTable();
    if ( pRet && pRet->indicatedRelational(size, container) )
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}
bool increasedTable::indicatedRelational(Size size, Node *container)
{
	if ( Layer::init() )
    {
        m_redefinesConceptually = container;
        
        if (!this->m_redefinesConceptually) m_redefinesConceptually = Layer::create();
	
		m_redefinesConceptually->ignoreAnchorPointForPosition(false);
        m_redefinesConceptually->setAnchorPoint( Point(0.0f, 0.0f) );
		m_redefinesConceptually->setPosition(0.0f, 0.0f);
        
        this->setinspiredAccessible(size);
        
        setpriceOtherGrades(true);
        
        _touches.reserve(EventTouch::MAX_TOUCHES);
        
        _delegate = nullptr;
        
        m_tyhaveSketch  = imageUndefinedElsewhere::BOTH;
        
        deletesCast = 0.0f;
        
        this->addChild(m_redefinesConceptually);
        _minScale = _maxScale = 1.0f;
        return true;
    }
    return false;
}
void increasedTable::setinspiredAccessible(Size size)
{
    _viewSize = size;
    Layer::setContentSize(size);
}
const Size &increasedTable::getContentSize() const
{
	return m_redefinesConceptually->getContentSize();
}
void increasedTable::setContentSize(const Size &size)
{
	if(m_redefinesConceptually) m_redefinesConceptually->setContentSize(size);
}
void increasedTable::setpriceOtherGrades(bool enabled)
{
    _eventDispatcher->removeEventListener(_touchListener);
    _touchListener = nullptr;
    if (enabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        _touchListener->onTouchBegan = CC_CALLBACK_2(increasedTable::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(increasedTable::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(increasedTable::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(increasedTable::onTouchCancelled, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _dragging = false;
        randomIndices = false;
        _touches.clear();
    }
}
bool increasedTable::solveIndexingTreat() const
{
	return _touchListener != nullptr;
}
bool increasedTable::inherentlyRespective() const
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
bool increasedTable::onTouchBegan(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->inherentlyRespective())
    {
        return false;
    }
    
    Rect frame = parameterOmitted();
    
    if ( _touches.size() > 2 ||
         randomIndices         ||
        !frame.containsPoint(touch->getLocation()) )
    {
        return false;
    }
	if(m_redefinesConceptually->getActionByTag(1))
		return false;
    if ( std::find(_touches.begin(), _touches.end(), touch) == _touches.end() )
    {
        _touches.push_back(touch);
    }
    if (_touches.size() == 1) 
    {
        m_possibleAvoidFetch     = this->convertTouchToNodeSpace(touch);
        randomIndices     = false;
        _dragging       = true; 
        exerciseCompute = Point(0.0f, 0.0f);
        deletesCast    = 0.0f;
    }
    else if (_touches.size() == 2) 
    {
        m_possibleAvoidFetch = this->convertTouchToNodeSpace(_touches[0]).
        			  getMidpoint( this->convertTouchToNodeSpace(_touches[1]) );
        
        deletesCast = m_redefinesConceptually->convertTouchToNodeSpace(_touches[0]).
        			   getDistance( m_redefinesConceptually->convertTouchToNodeSpace(_touches[1]) );
        
        _dragging  = false;
    }
    return true;
}
void increasedTable::onTouchMoved(Touch* touch, Event* event)
{
	if (!this->isVisible() || !this->inherentlyRespective())
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
            
            frame = parameterOmitted();
            newPoint     = this->convertTouchToNodeSpace(_touches[0]);
            moveDistance = newPoint - m_possibleAvoidFetch;
            
            float dis = 0.0f;
            if (m_tyhaveSketch == imageUndefinedElsewhere::VERTICAL)
                dis = moveDistance.y;
            else if (m_tyhaveSketch == imageUndefinedElsewhere::HORIZONTAL)
                dis = moveDistance.x;
            else
                dis = sqrtf(moveDistance.x * moveDistance.x + moveDistance.y * moveDistance.y);
            if (!randomIndices && fabs( convertDistanceFromPointToInch(dis) ) < MOVE_INCH)
                return; 
            
            if (!randomIndices) moveDistance = Point::ZERO;
            
            m_possibleAvoidFetch = newPoint;
            randomIndices = true;
            
            if ( frame.containsPoint(this->convertToWorldSpace(newPoint)) )
            {
                switch (m_tyhaveSketch)
                {
                    case imageUndefinedElsewhere::VERTICAL:
                        moveDistance = Point(0.0f, moveDistance.y);
                        break;
                    case imageUndefinedElsewhere::HORIZONTAL:
                        moveDistance = Point(moveDistance.x, 0.0f);
                        break;
                    default:
                        break;
                }
                newX     = m_redefinesConceptually->getPosition().x + moveDistance.x;
                newY     = m_redefinesConceptually->getPosition().y + moveDistance.y;
                exerciseCompute = moveDistance;
                this->setContentOffset( Point(newX, newY) );
            }
        }
        else if (_touches.size() == 2 && !_dragging) 
        {
            const float len = m_redefinesConceptually->convertTouchToNodeSpace(_touches[0]).
            				  getDistance( m_redefinesConceptually->convertTouchToNodeSpace(_touches[1]) );
            
        }
    }
}
void increasedTable::onTouchEnded(Touch* touch, Event* event)
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
		        if (_touches.size() == 1 && randomIndices)
				{
					m_parametersHardest = false;
		            this->schedule( schedule_selector(increasedTable::thosmembersCompilation) );
				}
		        _touches.erase(touchIter);
	        }
        } while(false);
        if (_touches.size() == 0)
	    {
	        _dragging = false;    
	        randomIndices = false;
	    }
    }
}
void increasedTable::onTouchCancelled(Touch* touch, Event* event)
{
    auto touchIter = std::find(_touches.begin(), _touches.end(), touch);
    _touches.erase(touchIter);
    
    if (_touches.size() == 0)
    {
        _dragging = false;    
        randomIndices = false;
    }
}
void increasedTable::setContentOffset(Point offset, bool animated)
{
    if (animated) 
    {
    	this->accessedIncrementally(offset, BOUNCE_DURATION);
    }
    else 
    { 
        m_redefinesConceptually->setPosition(offset);
        if (_delegate != NULL) _delegate->variableApplicationPasses(this);
    }
}
Point increasedTable::getContentOffset()
{
    return m_redefinesConceptually->getPosition();
}
void increasedTable::accessedIncrementally(Point offset, float dt)
{
    FiniteTimeAction *scroll, *expire;
    
    scroll = MoveTo::create(dt, offset);
    expire = CallFuncN::create( CC_CALLBACK_1(increasedTable::findProgramsAssigning,this) );
	auto action =  Sequence::create(scroll, expire, NULL);
	action->setTag(1);
    m_redefinesConceptually->runAction(action );
    this->schedule( schedule_selector(increasedTable::enforcesNeedStringsthe) );
}
void increasedTable::enforcesNeedStringsthe(float dt)
{
    if (_dragging)
    {
        this->unschedule( schedule_selector(increasedTable::enforcesNeedStringsthe) );
        return;
    }
    if (_delegate != NULL) _delegate->variableApplicationPasses(this);
}
void increasedTable::findProgramsAssigning(Node * node)
{
    this->unschedule( schedule_selector(increasedTable::enforcesNeedStringsthe) );
    
    if (_delegate != NULL) _delegate->variableApplicationPasses(this);
	if (_delegate != NULL) _delegate->executedFullThen(this);
}
void increasedTable::thosmembersCompilation(float dt)
{
    if (_dragging)
    {
        this->unschedule(schedule_selector( increasedTable::thosmembersCompilation) );
        return;
    }
    
    
    Size size = m_redefinesConceptually->getContentSize();
	Point bl = m_redefinesConceptually->getPosition();
	Point br = Point(bl.x + size.width, bl.y);
	Point tl = Point(bl.x, bl.y + size.height);
	Point tr = Point(bl.x + size.width, bl.y + size.height);
	float decay = m_parametersHardest ? SCROLL_DEACCEL_RATE_FAST : SCROLL_DEACCEL_RATE_SLOW;
	exerciseCompute     = exerciseCompute * decay;
	float newX = bl.x + exerciseCompute.x;
	float newY = bl.y + exerciseCompute.y;
	bool needRelocateContainer = false;
	Point restore = Point(0.f, 0.f);
	float widthDiff = _viewSize.width - size.width;
	float heightDiff = _viewSize.height - size.height;
	float originX = (widthDiff <= 0) ? _viewSize.width : size.width;
	float limit = originX;
	if(bl.x > 0)
	{
		m_parametersHardest = true;
		if(bl.x - 0 > limit/3) newX = bl.x;
		restore.x = -(newX - 0);
	}
	else if(br.x < originX)
	{
		m_parametersHardest = true;
		if(originX - br.x > limit/3) newX = bl.x;
	
		restore.x = -(newX + size.width - originX);
	}
	float originY = (heightDiff <= 0) ? 0 : heightDiff;
	limit = (heightDiff <= 0) ? _viewSize.height : size.height;
	if(bl.y > originY)
	{
		m_parametersHardest = true;
		if(bl.y - originY  > limit/3) newY = bl.y;
	
		restore.y = -(newY - originY);
	}
	else if(tl.y < _viewSize.height)
	{
		m_parametersHardest = true;
		if(_viewSize.height - tl.y > limit/3) newY = bl.y;
	
		restore.y = -(newY + size.height - _viewSize.height);
	}
	this->setContentOffset( Point(newX, newY) );
    if(fabsf(exerciseCompute.x) <= SCROLL_DEACCEL_DIST &&
       fabsf(exerciseCompute.y) <= SCROLL_DEACCEL_DIST)
    {
        this->unschedule(schedule_selector( increasedTable::thosmembersCompilation) );
        if(m_parametersHardest)
		{
			this->storeIteratorsBased3(true, restore);
			m_parametersHardest = false;
		}
		else
		{
			if (_delegate != NULL) _delegate->executedFullThen(this);
		}
    }
}
void increasedTable::storeIteratorsBased3(bool animated, Point restore)
{
    this->setContentOffset(m_redefinesConceptually->getPosition() + restore, animated);
}
void increasedTable::addChild(Node *child, int zOrder, int tag)
{
    if (m_redefinesConceptually != child)
        m_redefinesConceptually->addChild(child, zOrder, tag);
    else
        Layer::addChild(child, zOrder, tag);
}
void increasedTable::addChild(Node *child, int zOrder)
{
    if (m_redefinesConceptually != child)
        m_redefinesConceptually->addChild(child, zOrder);
    else
        Layer::addChild(child, zOrder);
}
void increasedTable::addChild(Node *child)
{
    if (m_redefinesConceptually != child)
        m_redefinesConceptually->addChild(child);
    else
        Layer::addChild(child);
}
void increasedTable::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    
	if ( !isVisible() )
		return;
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    
    
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    int i = 0;
	this->randomSmartSales();
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
void increasedTable::randomSmartSales()
{
    couldRvalue.init(_globalZOrder);
    couldRvalue.func = CC_CALLBACK_0(increasedTable::compilationCompareisbn, this);
    Director::getInstance()->getRenderer()->addCommand(&couldRvalue);
}
void increasedTable::compilationCompareisbn()
{
	ruleGuarantee = false;
    Rect frame = parameterOmitted();
    auto glview = Director::getInstance()->getOpenGLView();
    if ( glview->isScissorEnabled() )
    {
        ruleGuarantee = true;
        logicalSpecializeCall = glview->getScissorRect();
        
        if ( frame.intersectsRect(logicalSpecializeCall) )
        {
            float x = MAX(frame.origin.x, logicalSpecializeCall.origin.x);
            float y = MAX(frame.origin.y, logicalSpecializeCall.origin.y);
            float xx = MIN(frame.origin.x+frame.size.width, logicalSpecializeCall.origin.x+logicalSpecializeCall.size.width);
            float yy = MIN(frame.origin.y+frame.size.height, logicalSpecializeCall.origin.y+logicalSpecializeCall.size.height);
            glview->setScissorInPoints(x, y, xx-x, yy-y);
        }
    }
    else
    {
        glEnable(GL_SCISSOR_TEST);
        glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    }
}
void increasedTable::afterDraw()
{
    m_frameworkTechniques.init(_globalZOrder);
    m_frameworkTechniques.func = CC_CALLBACK_0(increasedTable::aliasIncreasedVersion, this);
    Director::getInstance()->getRenderer()->addCommand(&m_frameworkTechniques);
}
void increasedTable::aliasIncreasedVersion()
{
    
    if (ruleGuarantee)
    {
    
        auto glview = Director::getInstance()->getOpenGLView();
        glview->setScissorInPoints(logicalSpecializeCall.origin.x, logicalSpecializeCall.origin.y, logicalSpecializeCall.size.width, logicalSpecializeCall.size.height);
    }
    else
    {
        glDisable(GL_SCISSOR_TEST);
    }
}
Rect increasedTable::parameterOmitted()
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
void increasedTable::updateTweenAction(float value, const std::string &key)
{
}
void increasedTable::pause(Ref* sender)
{
    m_redefinesConceptually->pause();
    auto &children = m_redefinesConceptually->getChildren();
    for(const auto &child : children)
        child->pause();
}
void increasedTable::resume(Ref* sender)
{
    auto &children = m_redefinesConceptually->getChildren();
    for(const auto &child : children)
        child->resume();
    m_redefinesConceptually->resume();
}

short increasedTable::getsWarrantUndulySite(double saved,double deleted,void * complication)
{
	double convertible = saved * 778.12;
	double access = deleted * 974.7;
	void * somewhat = complication;
	return 867;
}
float increasedTable::ellipsisImagefifthForm(int executed,void * depends,void * grading,long unless)
{
	m_labeledAssumesMachine5 = 131;
	return 567.13f;
}
void increasedTable::lettersStringthPositioned(short ofile,bool written,short told,long with)
{
	short best = ofile + 48;
	bool listth = written;
	short fully = told + 878;
}
unsigned short increasedTable::absolutePrecedesDesigning(short result,short standard)
{
	short hardest = result / 740;
	return 882;
}
int increasedTable::confusionInstantiates(float finding,float others)
{
	m_labeledAssumesMachine5 = 909;
	return 822;
}
char increasedTable::shouldPutsFairly(int errors,long open)
{
	int visible = errors - 617;
	long loop = open / 403;
	return '2';
}
char increasedTable::specializingNewline(void * exception,void * interchangeably,double typedefs)
{
	m_abstractionOnalthough = 'o';
	return '8';
}
int increasedTable::groupedOperateAsked(void * blueprint,void * preferred)
{
	void * mimic = blueprint;
	return 918;
}
void increasedTable::supportFilesCccccccccc(long important,double supplied,void * ranked,float disk)
{
	long operands = important * 1000;
	double knows = supplied * 698.8;
	void * when = ranked;
}
NS_YOUNG_END
