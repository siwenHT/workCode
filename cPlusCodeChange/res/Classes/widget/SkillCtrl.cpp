#include "SkillCtrl.h"

USING_NS_CC;

//#define PI				3.14159
#define DgreeToN(x)     (x)*3.14159/180
//CCVec2 pt[4] = {ccp(-80,-5),ccp(-65,40),ccp(-30,70),ccp(15,80)};

SkillCtrl::SkillCtrl()
{
	m_beginNode = 0;
	m_rotateDrct = 0;
	m_is_right = true;
	touch_effect = NULL;
	touch_effect1 = NULL;
}
SkillCtrl::~SkillCtrl()
{
}

bool SkillCtrl::init()
{
	createChain();
	setRight(true);
	return true;
}

//void SkillCtrl::skillClick(Object*obj)
//{
//	for(int i=0;i<12;i++)
//	{
//		if((MenuItemImage*)obj == m_chain[i].btn && m_beginNode == i)
//		{
//			CCLOG("skill Id: %d",m_chain[i].skillId);
//			break;
//		}
//	}
//}

void SkillCtrl::setRight(bool inright)
{
	m_is_right = inright;
	//Vec2 span = Vec2(-10,10);
	Size winSize = Director::getInstance()->getWinSize();
	m_sprite1->setFlippedX(!inright);
	m_sprite2->setFlippedX(inright);
	//m_sprite1->setFlippedY(!inright);
	if(inright)
	{
		m_dgree = 0;
		m_center_node->setRotation(m_dgree);
		m_center_pos = Vec2(winSize.width,0);
		m_center_item->setAnchorPoint(Vec2(1.0,0.0));
		//m_center_item->setFlippedX(false);
		m_center_item->setPosition(Vec2(-20,20+20));
		m_center_node->setPosition(Vec2(-30,30+20));
		m_sprite1->setPosition(Vec2(-90-20,160+60));
		m_sprite2->setPosition(Vec2(-160-40,90+50));
		m_sprite2->setRotation(-90);
	}
	else
	{
		m_dgree = 90;
		//span = Vec2(10,10);
		m_center_node->setRotation(m_dgree);
		m_center_pos = Vec2(0,0);
		m_center_item->setAnchorPoint(Vec2(0.0,0.0));
		m_center_item->setPosition(Vec2(20,20+20));
		//m_center_item->setFlippedX(true);
		m_sprite1->setPosition(Vec2(90+20,160+60));
		m_sprite2->setPosition(Vec2(160+40,90+50));
		m_sprite2->setRotation(90);
		m_center_node->setPosition(Vec2(30,30+20));
	}
	setMode();
	setPosition(m_center_pos);
}

void SkillCtrl::createChain()
{
	int r = 265;
	Vec2 item_size;
	//Vector<MenuItem*> ar;
	Size winSize = Director::getInstance()->getWinSize();
	//m_skill_menu = Menu::create();
	m_center_node = Node::create();
	float start_dgree = 185;
	float rotate_dgree = -120;
	for(int i=0; i<=8; i++)
	{
		if(i%3 == 0)
		{
			start_dgree -= 15;
			rotate_dgree += 120;
		}
		Vec2 pos = Vec2(r*cos(DgreeToN(start_dgree-35*i)),r*sin(DgreeToN(start_dgree-35*i)));
		//Sprite *menu_item = Sprite::create("skill.png");
		MenuButton *menu_item = MenuButton::create("res/mainui/skill.png");
		menu_item->setAnchorPoint(Vec2(0.5,0.5));
		menu_item->setRotation(rotate_dgree);
		menu_item->setPosition(pos);
		m_center_node->addChild(menu_item,0,i);
		item_size = Vec2(menu_item->getContentSize());
	}
	m_dgree = m_center_node->getRotation();
	touch_effect = Effects::create(false);
	touch_effect->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect->setScale(0.82f);
	m_center_node->addChild(touch_effect , 101);

	m_center_node->setAnchorPoint(Vec2(0.5,0.5));
	//m_center_node->setPosition(Vec2(winSize.width-100,100));
	addChild(m_center_node,1);
	//m_center_item = Sprite::create("ptgj.png");
	m_center_item = MenuButton::create("res/mainui/ptgj.png");
	Vec2 center_size = Vec2(m_center_item->getContentSize());
	touch_effect1 = Effects::create(false);
	touch_effect1->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect1->setPosition(Vec2(55,55));
	addChild(touch_effect1 , 101);
	//m_center_item->setScale(0.8);
	addChild(m_center_item,1,10);

	m_sprite1 = GraySprite::create("res/mainui/cg.png");
	m_sprite1->setPosition(Vec2(-90-20,160+60));
	addChild(m_sprite1,1,11);
	m_sprite2 = GraySprite::create("res/mainui/cg.png");
	m_sprite2->setFlippedX(true);
	m_sprite2->setRotation(-90);
	m_sprite2->setPosition(Vec2(-160-20,90+60));
	addChild(m_sprite2,1,12);
	m_sprite1->addColorGray();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch* touch,Event* event)  
	{
		Vec2 touchs = touch->getLocation();
		m_rotateDrct = 0;
		m_select_item = NULL;
		if(!isVisible())
			return false;
		if(touchs.getDistance(m_center_pos) < (r + item_size.getDistance(Vec2(0,0))))
		{
			
			listener->setSwallowTouches(true); 
			Vec2 local = m_center_item->convertToNodeSpace(touchs);
			Rect rt= m_center_item->rect();
			rt.origin = Vec2::ZERO;
			if (m_center_item && m_center_item->isVisible() && m_center_item->isEnabled()&&rt.containsPoint(local))
			{
				m_select_item = m_center_item;
				m_select_item->selected();
				if(touch_effect)
				{
					Vec2 temp = Vec2(-80,80);
					if(!m_is_right)
					{
						temp = Vec2(80,80);
					}
					touch_effect1->setPosition(m_select_item->getPosition()+temp);
					touch_effect1->playActionData("toucheffect", 4, 0.25,1);
					//touch_effect1->setAnchorPoint(m_select_item->getAnchorVec2());
				}
			}
			else 
			{
				for(int i=0;i<=8;i++)
				{
				
					MenuButton *item = (MenuButton *)m_center_node->getChildByTag(i);
					if (item && item->isVisible() && item->isEnabled())
					{
						Vec2 local = item->convertToNodeSpace(touchs);
						Rect rt= item->rect();
						rt.origin = Vec2::ZERO;
						if(rt.containsPoint(local))
						{
							m_select_item = item;
							m_select_item->selected();
							if(touch_effect)
							{
								touch_effect->setPosition(m_select_item->getPosition());
								touch_effect->playActionData("toucheffect", 4, 0.25,1);
							}
						}
					}
				}
			}

			return true;
		}
		
		return false;
	};

	listener->onTouchMoved = [=](Touch* touch,Event* event) 
	{
		Vec2 start = touch->getStartLocation();
		Vec2 dest = touch->getLocation();
		Vec2 direction = (dest - start).getNormalized();
		if(dest.getDistance(start) > 30)
		{
			m_center_node->setRotation(m_dgree);
			if((direction.x > 0&&direction.y > 0)&&m_is_right || (direction.x > 0&&direction.y < 0)&&!m_is_right)
			{
				m_rotateDrct = 1;		
			}
			else if(direction.x < 0&&direction.y < 0&&m_is_right || (direction.x < 0&&direction.y > 0)&&!m_is_right)
			{
				m_rotateDrct = -1;
			}
			//float dgree = m_dgree + m_rotateDrct*120;
			//if(dgree < start_dgree  || dgree > (start_dgree+240))
			//{
			//	m_rotateDrct = 0;
			//}
			if(m_select_item != NULL)
			{
				m_select_item->unselected();
				m_select_item = NULL;
			}
		}

	};
	listener->onTouchEnded = [=](Touch* touch,Event* event) 
	{
		Vec2 touchs = touch->getLocation();
		Vec2 start = touch->getStartLocation();
		if(m_select_item != NULL)
		{
			//m_pHero->attack(m_select_item->getTag());
			m_select_item->unselected();
			m_select_item->activate();
			m_select_item = NULL;
		}
		else if(m_rotateDrct != 0)
		{
			if(m_beginNode == -1 || (m_beginNode == -2&&m_rotateDrct==1) || (m_beginNode == 0&&m_rotateDrct==-1))
			{
				m_dgree += m_rotateDrct*120;
				m_beginNode += m_rotateDrct;
				m_center_node->runAction(RotateTo::create(0.3f,m_dgree));
				setMode();
			}
		}

		listener->setSwallowTouches(false);  

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_center_node);
}

void SkillCtrl::setPageByIndex(int page)
{
	m_rotateDrct = 1-page;
	m_dgree += m_rotateDrct*120;
	m_beginNode += m_rotateDrct;
	//m_center_node:setRotation(m_dgree);
	m_center_node->runAction(RotateTo::create(0.0,m_dgree));
	setMode();
}

int SkillCtrl::getPageIndex()
{
	return (1-m_beginNode);
}

void SkillCtrl::setMode()
{
	if(m_beginNode == -1)
	{
		m_sprite1->removeColorGray();
		m_sprite2->removeColorGray();
	}
	else if(m_beginNode == -2)
	{
		m_sprite1->setColorGray( !m_is_right);
		m_sprite2->setColorGray( m_is_right);
	}
	else if(m_beginNode == 0)
	{
		m_sprite1->setColorGray( m_is_right);
		m_sprite2->setColorGray( !m_is_right);
	}
}

