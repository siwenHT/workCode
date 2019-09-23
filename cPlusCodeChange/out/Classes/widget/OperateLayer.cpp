#include "OperateLayer.h"
#include "LuaSocket.h"
#include "MapView.h"
using namespace cocos2d;
using namespace std;
OperateLayer::OperateLayer():
	m_pJoystick(NULL),
	m_pJoystickBg(NULL),
	m_pHero(NULL)
{
}
OperateLayer::~OperateLayer()
{ 
}
bool OperateLayer::init()
{
	bool ret = false;
	do {
		CC_BREAK_IF( !Node::init() );
		m_pJoystick = Sprite::create("resNew/home/joystick.png");
	
		m_pJoystickBg = Sprite::create("resNew/home/joystick_bg.png");
		m_pJoystickBg->setScale(0.5);
		this->addChild(m_pJoystickBg,0,1);
		m_pJoystickBg->addChild(m_pJoystick, 1);
		this->hideJoystick();
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);  
		listener->onTouchBegan = [=](Touch* touch,Event* event)  
		{
			Size winSize = Director::getInstance()->getWinSize();
			Vec2 pos = touch->getLocation();
			float distance = pos.getDistance(m_point);
			if(!isVisible())
				return false;
			if(distance<150)
			{
				this->showJoystick(pos);
			
				LuaSocket::getInstance()->runLuaFunc("JoystickMoveBegin", NULL, 0);
				return true;
			}
			return false;
		};
		listener->onTouchMoved = [=](Touch* touch,Event* event)  
		{
			if(m_pJoystickBg->isVisible())
			{
				Size winSize = Director::getInstance()->getWinSize();
				Vec2 start = touch->getStartLocation();
				Vec2 dest = touch->getLocation();
				if(dest.x<=5 || dest.x>=(winSize.width-12) ||dest.y>=(winSize.height-12) ||dest.y<=5)
				{
					this->hideJoystick();
					if(m_pHero && m_pHero->stop != NULL&&m_pHero->getActive())
						m_pHero->stop();
					return;
				}
				float distance = start.getDistance(dest);
				Vec2 direction = (dest - start).getNormalized();
				if(distance<5) return;
				if(((direction.x >= -0.000001) &&(direction.x <= 0.000001) && (direction.y >= -0.000001)&& (direction.y <= 0.000001)) )
					return;
				Commen_Direction dir = dir_up;
				if((direction.x >= -0.000001) &&(direction.x <= 0.000001) )
				{
					if(direction.y > 0)
						dir = dir_up;
					else if(direction.y < 1)
						dir = dir_down;
				}
				else
				{
					float tanAngel = atan2(abs(direction.y),abs(direction.x));
					if(tanAngel < (PI/8))
					{
						if(direction.x < 0)
							dir = dir_left;
						else
							dir = dir_right;
					}
					else if(tanAngel > (PI*3/8))
					{
						if(direction.y > 0)
							dir = dir_up;
						else
							dir = dir_down;
					}
					else
					{
						if(direction.x < 0 && direction.y < 0)
							dir = dir_left_down;
						else if(direction.x < 0 && direction.y > 0)
							dir = dir_left_up;
						else if(direction.x > 0 && direction.y > 0)
							dir = dir_right_up;
						else
							dir = dir_right_down;
					}
				}
				this->updateJoystick(direction, distance);
				if(m_pHero && m_pHero->onWalk != NULL&&m_pHero->isAlive()){ 
					if (!m_pHero->getActive())
					{
						if (MapView::DefaultMapView && MapView::DefaultMapView->m_noMove_cb > 0)
						{
							LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
							if (pStack != nullptr)
							{
								pStack->pushInt(2);
								pStack->executeFunctionByHandler(MapView::DefaultMapView->m_noMove_cb, 1);
								pStack->clean();
							}
						}
					}
					else
					{
						m_pHero->onWalk(dir, distance,direction);
					}
				}
			}
		};
		 
		listener->onTouchEnded = [=](Touch* touch,Event* event)  
		{
			if(m_pJoystickBg->isVisible())
			{
				this->hideJoystick();
				if(m_pHero && m_pHero->stop != NULL&&m_pHero->getActive())
					m_pHero->stop();
			
				LuaSocket::getInstance()->runLuaFunc("JoystickMoveEnd", NULL, 0);
			}
		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		ret = true;
	} while(false);
	return ret;
}
void OperateLayer::showJoystick(Vec2 pos)
{
	m_pJoystickBg->setScale(1);
	m_pJoystickBg->setPosition(pos);
	m_pJoystickBg->setOpacity(205);
	m_pJoystick->setOpacity(205);
	m_pJoystickBg->setTexture("resNew/home/joystick_bg_1.png");
}
void OperateLayer::hideJoystick()
{
	m_pJoystickBg->setScale(0.75);
	m_pJoystickBg->setPosition(m_point);
	m_pJoystick->setPosition(m_start_point);
	m_pJoystickBg->setOpacity(105);
	m_pJoystick->setOpacity(105);
	m_pJoystickBg->setTexture("resNew/home/joystick_bg.png");
}
void OperateLayer::setCenterPoint(Vec2 pos)
{
	m_point = pos;
	Size bgsize = m_pJoystickBg->getContentSize();
	m_start_point = Vec2(bgsize.width/2,bgsize.height/2);
	m_pJoystickBg->setPosition(m_point);
	hideJoystick();
}
void OperateLayer::updateJoystick(Vec2 direction, float distance)
{
	if(distance < 150)
	{
		m_pJoystick->setPosition(m_start_point + (direction * distance));
	}
	else  
	{
		m_pJoystick->setPosition(m_start_point + (direction * 150));
	}
}
