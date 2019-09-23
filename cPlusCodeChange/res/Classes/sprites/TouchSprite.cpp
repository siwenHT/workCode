#include "TouchSprite.h"
#include "CCLuaEngine.h"

USING_NS_CC;

TouchSprite::TouchSprite():
	m_scriptSelectedHandler(NULL),
	m_beginPoint(Vec2::ZERO),
	m_isClick(true),
	m_scriptUnselectedHandler(NULL),
	m_touchType(1),
	m_swallowTouch(true)
{
	m_select_action = NULL;
	m_unselect_action = NULL;
}

TouchSprite::~TouchSprite(void)
{
}


bool TouchSprite::isTouchInside(Touch* touch)
{
	Point touch_ = touch->getLocation();
	Point localPos = getParent()->convertToNodeSpace(touch_);
	Rect touch_rect = getBoundingBox();

	return	touch_rect.containsPoint(localPos);
}

void TouchSprite::setTouchEnable(bool enable)
{
	if(enable)
		initTouch();
	m_touch_enable = enable;
}
void TouchSprite::setEnable(bool enable)
{
	if(enable)
	{
		initTouch();
		removeColorGray();
	}
	else
	{
		addColorGray();
	}
	m_touch_enable = enable;
}

void TouchSprite::setSwallowTouch(bool swallow)
{
	m_swallowTouch = swallow;
	setTouchEnable(m_touch_enable);
}
bool TouchSprite::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListenersForTarget(this);
	auto myListener = EventListenerTouchOneByOne::create();

    myListener->setSwallowTouches(m_swallowTouch);

	myListener->onTouchBegan = [=](Touch* touch,Event* event)
	{
		if(!m_touch_enable|| !isVisible())
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
		if(isTouchInside(touch))
		{
			if(m_select_action != NULL)
			{
				//runAction(m_select_action);
			}
			m_beginPoint = touch->getLocation();
			m_isClick = true;

			if (!m_scriptSelectedHandler) 
				return true;
			onTouchDown();

			return true;  
		}
		return false;
	};

	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
		if(touch->getLocation().distance(m_beginPoint) > 20){
			m_isClick = false;
		}
	};

	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(m_unselect_action != NULL)
		{
			//runAction(m_unselect_action);
		}
		if (!m_scriptUnselectedHandler) 
			return;
		if(m_isClick || m_touchType == 2){
			onClick(1);
		}else{
			onClick(0);
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);

	return true;
}

//state 1表示点击正常  0表示失败
void TouchSprite::onClick(int state){
	if(!m_scriptUnselectedHandler)
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;
	pStack->pushObject(this, "TouchSprite");
	pStack->pushInt(state);
	pStack->executeFunctionByHandler(m_scriptUnselectedHandler, 2);
	pStack->clean();
}

void TouchSprite::onTouchDown(){
	if (!m_scriptSelectedHandler) 
		return;
	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	if (pStack == NULL)
		return;

	pStack->pushObject(this, "TouchSprite");
	pStack->executeFunctionByHandler(m_scriptSelectedHandler, 1);
	pStack->clean();
}

TouchSprite *TouchSprite::create(const std::string&pszFileName,bool enable)
{
    TouchSprite *pRet = new TouchSprite();
    if (pRet && pRet->initWithFile(pszFileName))
    {
		pRet->setTouchEnable(enable);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

TouchSprite *TouchSprite::create()
{
    TouchSprite *pRet = new TouchSprite();
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

void TouchSprite::registerTouchDownHandler(int handler)
{
	m_scriptSelectedHandler = handler;
}

void TouchSprite::registerTouchUpHandler(int handler)
{
	m_scriptUnselectedHandler = handler;
}

void  TouchSprite::setSelectAction(Action* action)
{
	m_select_action = action;
}
void  TouchSprite::setUnSelectAction(Action* action)
{
	m_unselect_action = action;
}
