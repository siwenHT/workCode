#include "unrelatedNodefaultGrouped.h"
#include "takeFullDeclares.h"
#include "CCLuaEngine.h"
USING_NS_CC;
unrelatedNodefaultGrouped::unrelatedNodefaultGrouped()
		: quizStopPositionally(NULL)
	, initializedWell(NULL)
	,assumesPreventingDeclare(false)
	,readTestErrors(true)
	,m_goesPowerfulShould(true)
{
	cocos2d::Size win =  Director::getInstance()->getWinSize();
	m_assumesInfer = Rect(0, 0, win.width, win.height);
}
unrelatedNodefaultGrouped::~unrelatedNodefaultGrouped(void)
{
}
bool unrelatedNodefaultGrouped::correctSettingIcase(Touch* touch)
{
	takeFullDeclares takefulldeclares_e;
	takefulldeclares_e.natureNodefaultLvalue(232.11f,393.10f);

	Point touchs = touch->getLocation();
	Point localPos =  convertToNodeSpace(touchs);
	Size ss = getContentSize();
	Rect touch_rect = Rect(0,0,ss.width,ss.height);
	return	touch_rect.containsPoint(localPos);
}
void unrelatedNodefaultGrouped::setitemContainersUnable(bool enable)
{
	readTestErrors = enable;
}
bool unrelatedNodefaultGrouped::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(true);
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
		if(!m_assumesInfer.containsPoint(touch->getLocation()))
		{
			return false;
		}
		if(correctSettingIcase(touch))
		{
			if(m_goesPowerfulShould)
			{
				if(assumesPreventingDeclare)
					runAction(ScaleTo::create(0.15,1.15));
				else
					runAction(ScaleTo::create(0.15,0.75));
			}
			if (!quizStopPositionally) 
				return true;
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return false;
			pStack->pushObject(this, "unrelatedNodefaultGrouped");
			pStack->executeFunctionByHandler(quizStopPositionally, 1);
			pStack->clean();
			return true;  
		}
		return false;
	};
	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
	};
	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(m_goesPowerfulShould)
		{
			if(assumesPreventingDeclare)
				runAction(Sequence::create(ScaleTo::create(0.15,0.85),ScaleTo::create(0.05,1.0),NULL));
			else
				runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.05,1.0),NULL));
		}
		if (!initializedWell) 
			return;
		if(correctSettingIcase(touch))
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return;
			pStack->pushObject(this, "unrelatedNodefaultGrouped");
			pStack->executeFunctionByHandler(initializedWell, 1);
			pStack->clean();
		}
	};
	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);
	return true;
}
unrelatedNodefaultGrouped *unrelatedNodefaultGrouped::create(const char* file,const Size s)
{
    unrelatedNodefaultGrouped *pRet = new unrelatedNodefaultGrouped();
	if (pRet && pRet->initWithFile(file))
    {
		pRet->setContentSize(s);
		pRet->initTouch();
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
unrelatedNodefaultGrouped *unrelatedNodefaultGrouped::create()
{
    unrelatedNodefaultGrouped *pRet = new unrelatedNodefaultGrouped();
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
void unrelatedNodefaultGrouped::expandsComputingNeeded(int handler)
{
	quizStopPositionally = handler;
}
void unrelatedNodefaultGrouped::resourcesEvaluateBinds(int handler)
{
	initializedWell = handler;
}
