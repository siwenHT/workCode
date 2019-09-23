#include "refersEnums.h"
#include "CCLuaEngine.h"
USING_NS_CC;
refersEnums::refersEnums()
		: nearlyNaturallyMatches(NULL)
	, explicitlyThemselves(NULL)
	,m_objectsEntireThexercises(false)
	,m_invokesPatterns(true)
	,m_differencesDestruction(true)
{
	cocos2d::Size win =  Director::getInstance()->getWinSize();
	theseAdaptors = Rect(0, 0, win.width, win.height);
}
refersEnums::~refersEnums(void)
{
}
bool refersEnums::moreIdenticalOperations(Touch* touch)
{
	Point touchs = touch->getLocation();
	Point localPos =  convertToNodeSpace(touchs);
	Size ss = getContentSize();
	Rect touch_rect = Rect(0,0,ss.width,ss.height);
	return	touch_rect.containsPoint(localPos);
}
void refersEnums::setreduceRecognize(bool enable)
{
	m_invokesPatterns = enable;
}
bool refersEnums::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(true);
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
		if(!theseAdaptors.containsPoint(touch->getLocation()))
		{
			return false;
		}
		if(moreIdenticalOperations(touch))
		{
			if(m_differencesDestruction)
			{
				if(m_objectsEntireThexercises)
					runAction(ScaleTo::create(0.15,1.15));
				else
					runAction(ScaleTo::create(0.15,0.75));
			}
			if (!nearlyNaturallyMatches) 
				return true;
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return false;
			pStack->pushObject(this, "refersEnums");
			pStack->executeFunctionByHandler(nearlyNaturallyMatches, 1);
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
		if(m_differencesDestruction)
		{
			if(m_objectsEntireThexercises)
				runAction(Sequence::create(ScaleTo::create(0.15,0.85),ScaleTo::create(0.05,1.0),NULL));
			else
				runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.05,1.0),NULL));
		}
		if (!explicitlyThemselves) 
			return;
		if(moreIdenticalOperations(touch))
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return;
			pStack->pushObject(this, "refersEnums");
			pStack->executeFunctionByHandler(explicitlyThemselves, 1);
			pStack->clean();
		}
	};
	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);
	return true;
}
refersEnums *refersEnums::create(const char* file,const Size s)
{
    refersEnums *pRet = new refersEnums();
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
refersEnums *refersEnums::create()
{
    refersEnums *pRet = new refersEnums();
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
void refersEnums::facilitiesNewlineWhif(int handler)
{
	nearlyNaturallyMatches = handler;
}
void refersEnums::rationaleAlternatively(int handler)
{
	explicitlyThemselves = handler;
}
