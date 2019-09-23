#include "wstringPreceding.h"
#include "CCLuaEngine.h"
USING_NS_CC;
wstringPreceding::wstringPreceding():
	quizStopPositionally(NULL),
	m_gradesLookupDoeth(Vec2::ZERO),
	m_isClick(true),
	initializedWell(NULL),
	remainderConversion(1),
	operandCircumstances(true)
{
	m_essentialBotherReview = NULL;
	m_preventInfrequently = NULL;
}
wstringPreceding::~wstringPreceding(void)
{
}
bool wstringPreceding::correctSettingIcase(Touch* touch)
{
	Point touch_ = touch->getLocation();
	Point localPos = getParent()->convertToNodeSpace(touch_);
	Rect touch_rect = getBoundingBox();
	return	touch_rect.containsPoint(localPos);
}
void wstringPreceding::setitemContainersUnable(bool enable)
{
	if(enable)
		initTouch();
	readTestErrors = enable;
}
void wstringPreceding::setEnable(bool enable)
{
	if(enable)
	{
		initTouch();
		addsBasicRecompile();
	}
	else
	{
		temporariesChapters();
	}
	readTestErrors = enable;
}
void wstringPreceding::setSwallowTouch(bool swallow)
{
	operandCircumstances = swallow;
	setitemContainersUnable(readTestErrors);
}
bool wstringPreceding::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListenersForTarget(this);
	auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(operandCircumstances);
	myListener->onTouchBegan = [=](Touch* touch,Event* event)
	{
		if(!readTestErrors|| !isVisible())
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
		if(correctSettingIcase(touch))
		{
			if(m_essentialBotherReview != NULL)
			{
			
			}
			m_gradesLookupDoeth = touch->getLocation();
			m_isClick = true;
			if (!quizStopPositionally) 
				return true;
			onTouchDown();
			return true;  
		}
		return false;
	};
	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
		if(touch->getLocation().distance(m_gradesLookupDoeth) > 20){
			m_isClick = false;
		}
	};
	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(m_preventInfrequently != NULL)
		{
		
		}
		if (!initializedWell) 
			return;
		if(m_isClick || remainderConversion == 2){
			onClick(1);
		}else{
			onClick(0);
		}
	};
	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);
	return true;
}
void wstringPreceding::onClick(int state){
	if(!initializedWell)
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;
	pStack->pushObject(this, "wstringPreceding");
	pStack->pushInt(state);
	pStack->executeFunctionByHandler(initializedWell, 2);
	pStack->clean();
}
void wstringPreceding::onTouchDown(){
	if (!quizStopPositionally) 
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;
	pStack->pushObject(this, "wstringPreceding");
	pStack->executeFunctionByHandler(quizStopPositionally, 1);
	pStack->clean();
}
wstringPreceding *wstringPreceding::create(const std::string&m_ableCover,bool enable)
{
    wstringPreceding *pRet = new wstringPreceding();
    if (pRet && pRet->initWithFile(m_ableCover))
    {
		pRet->setitemContainersUnable(enable);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
wstringPreceding *wstringPreceding::create()
{
    wstringPreceding *pRet = new wstringPreceding();
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
void wstringPreceding::expandsComputingNeeded(int handler)
{
	quizStopPositionally = handler;
}
void wstringPreceding::resourcesEvaluateBinds(int handler)
{
	initializedWell = handler;
}
void  wstringPreceding::sethashPointerIndeedMovement4(Action* action)
{
	m_essentialBotherReview = action;
}
void  wstringPreceding::setbecauseProblemThenReady(Action* action)
{
	m_preventInfrequently = action;
}
