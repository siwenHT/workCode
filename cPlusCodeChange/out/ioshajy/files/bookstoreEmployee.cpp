#include "bookstoreEmployee.h"
#include "CCLuaEngine.h"
USING_NS_CC;
bookstoreEmployee::bookstoreEmployee():
	nearlyNaturallyMatches(NULL),
	blobptrShorttypDirection(Vec2::ZERO),
	m_isClick(true),
	explicitlyThemselves(NULL),
	m_bitwiseInversely(1),
	shouldCastConfusion(true)
{
	m_convertingFrontSection = NULL;
	termsExpects = NULL;
}
bookstoreEmployee::~bookstoreEmployee(void)
{
}
bool bookstoreEmployee::moreIdenticalOperations(Touch* touch)
{
	Point touch_ = touch->getLocation();
	Point localPos = getParent()->convertToNodeSpace(touch_);
	Rect touch_rect = getBoundingBox();
	return	touch_rect.containsPoint(localPos);
}
void bookstoreEmployee::setreduceRecognize(bool enable)
{
	if(enable)
		initTouch();
	m_invokesPatterns = enable;
}
void bookstoreEmployee::setEnable(bool enable)
{
	if(enable)
	{
		initTouch();
		chapterEqually();
	}
	else
	{
		usedWithinOwhichCondition();
	}
	m_invokesPatterns = enable;
}
void bookstoreEmployee::setSwallowTouch(bool swallow)
{
	shouldCastConfusion = swallow;
	setreduceRecognize(m_invokesPatterns);
}
bool bookstoreEmployee::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListenersForTarget(this);
	auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(shouldCastConfusion);
	myListener->onTouchBegan = [=](Touch* touch,Event* event)
	{
		if(!m_invokesPatterns|| !isVisible())
		{
			return false;
		}
		for (Node *c = getParent(); c != nullptr; c = c->getParent())
		{
			if (c->isVisible() == false)
			{
				return false;
			}
		}
		if(moreIdenticalOperations(touch))
		{
			if(m_convertingFrontSection != NULL)
			{
			
			}
			blobptrShorttypDirection = touch->getLocation();
			m_isClick = true;
			if (!nearlyNaturallyMatches) 
				return true;
			onTouchDown();
			return true;  
		}
		return false;
	};
	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
		if(touch->getLocation().distance(blobptrShorttypDirection) > 20){
			m_isClick = false;
		}
	};
	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(termsExpects != NULL)
		{
		
		}
		if (!explicitlyThemselves) 
			return;
		if(m_isClick || m_bitwiseInversely == 2){
			onClick(1);
		}else{
			onClick(0);
		}
	};
	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);
	return true;
}
void bookstoreEmployee::onClick(int state){
	if(!explicitlyThemselves)
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;
	pStack->pushObject(this, "bookstoreEmployee");
	pStack->pushInt(state);
	pStack->executeFunctionByHandler(explicitlyThemselves, 2);
	pStack->clean();
}
void bookstoreEmployee::onTouchDown(){
	if (!nearlyNaturallyMatches) 
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;
	pStack->pushObject(this, "bookstoreEmployee");
	pStack->executeFunctionByHandler(nearlyNaturallyMatches, 1);
	pStack->clean();
}
bookstoreEmployee *bookstoreEmployee::create(const std::string&m_unwindingOnalthough,bool enable)
{
    bookstoreEmployee *pRet = new bookstoreEmployee();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough))
    {
		pRet->setreduceRecognize(enable);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
bookstoreEmployee *bookstoreEmployee::create()
{
    bookstoreEmployee *pRet = new bookstoreEmployee();
    if (pRet && pRet->init()&& pRet->initTouch())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
void bookstoreEmployee::facilitiesNewlineWhif(int handler)
{
	nearlyNaturallyMatches = handler;
}
void bookstoreEmployee::rationaleAlternatively(int handler)
{
	explicitlyThemselves = handler;
}
void  bookstoreEmployee::setcodeFullyException(Action* action)
{
	m_convertingFrontSection = action;
}
void  bookstoreEmployee::setassumeManageLittle(Action* action)
{
	termsExpects = action;
}
