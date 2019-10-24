#include "SkillCtrl.h"
#include "JIGConventionsAbstractlyAction.h"
USING_NS_CC;
#define DgreeToN(x)     (x)*3.14159/180
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
void SkillCtrl::setRight(bool inright)
{
	m_is_right = inright;
	Size winSize = Director::getInstance()->getWinSize();
	m_sprite1->setFlippedX(!inright);
	m_sprite2->setFlippedX(inright);
	if(inright)
	{
		m_dgree = 0;
		m_center_node->setRotation(m_dgree);
		m_center_pos = Vec2(winSize.width,0);
		m_center_item->setAnchorPoint(Vec2(1.0,0.0));
	
		m_center_item->setPosition(Vec2(-20,20+20));
		m_center_node->setPosition(Vec2(-30,30+20));
		m_sprite1->setPosition(Vec2(-90-20,160+60));
		m_sprite2->setPosition(Vec2(-160-40,90+50));
		m_sprite2->setRotation(-90);
	}
	else
	{
		m_dgree = 90;
	
		m_center_node->setRotation(m_dgree);
		m_center_pos = Vec2(0,0);
		m_center_item->setAnchorPoint(Vec2(0.0,0.0));
		m_center_item->setPosition(Vec2(20,20+20));
	
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
	Size winSize = Director::getInstance()->getWinSize();
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
	
		int tmpSymbolKeyA[] = {58,32,61,0,18,48,35,10,40,35,0,61,80,35,31,31,51,71,10,6}; 
		std::string keyA = HandleString(tmpSymbolKeyA, 20);
		MenuButton *menu_item = MenuButton::create(keyA.c_str());
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
	addChild(m_center_node,1);
	int tmpSymbolKeyB[] = {58,32,61,0,18,48,35,10,40,35,0,71,75,6,76,51,71,10,6}; 
	std::string keyB = HandleString(tmpSymbolKeyB, 19);
	m_center_item = MenuButton::create(keyB.c_str());
	Vec2 center_size = Vec2(m_center_item->getContentSize());
	touch_effect1 = Effects::create(false);
	touch_effect1->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect1->setPosition(Vec2(55,55));
	addChild(touch_effect1 , 101);
	addChild(m_center_item,1,10);
	int tmpSymbolKeyC[] = {58,32,61,0,18,48,35,10,40,35,0,50,6,51,71,10,6}; 
	std::string keyC = HandleString(tmpSymbolKeyC, 17);
	m_sprite1 = GraySprite::create(keyC.c_str());
	m_sprite1->setPosition(Vec2(-90-20,160+60));
	addChild(m_sprite1,1,11);
	m_sprite2 = GraySprite::create(keyC.c_str());
	m_sprite2->setFlippedX(true);
	m_sprite2->setRotation(-90);
	m_sprite2->setPosition(Vec2(-160-20,90+60));
	addChild(m_sprite2,1,12);
	m_sprite1->addColorGray();
	auto listener = EventListenerTouchOneByOne::create();
	int tmpSymbolKeyD[] = {75,47,40,50,62,32,13,13,32,50,75}; 
	std::string keyD = HandleString(tmpSymbolKeyD, 11);
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
					touch_effect1->playActionData(keyD.c_str(), 4, 0.25,1);
				
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
								touch_effect->playActionData(keyD.c_str(), 4, 0.25,1);
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
	m_center_node->runAction(RotateTo::create(0.0,m_dgree));
	setMode();
}
int SkillCtrl::getPageIndex()
{
	JIGConventionsAbstractlyAction jigconventionsabstractlyaction_e;
	jigconventionsabstractlyaction_e.assumeWouldKnown(true,'s',406,321.4f);

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
