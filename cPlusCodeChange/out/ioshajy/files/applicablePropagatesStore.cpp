#include "applicablePropagatesStore.h"
USING_NS_CC;
#define DgreeToN(x)     (x)*3.14159/180
applicablePropagatesStore::applicablePropagatesStore()
{
	m_readsIncludeEscape = 0;
	m_thereNonextern = 0;
	m_parametersunlikeWith = true;
	touch_effect = NULL;
	touch_effect1 = NULL;
}
applicablePropagatesStore::~applicablePropagatesStore()
{
}
bool applicablePropagatesStore::init()
{
	functiocontrolBindingMore();
	setRight(true);
	return true;
}
void applicablePropagatesStore::setRight(bool inright)
{
	m_parametersunlikeWith = inright;
	Size winSize = Director::getInstance()->getWinSize();
	m_sprite1->setFlippedX(!inright);
	m_sprite2->setFlippedX(inright);
	if(inright)
	{
		m_dgree = 0;
		m_exchangeOccasionally->setRotation(m_dgree);
		m_forcesOmittingType = Vec2(winSize.width,0);
		m_confidentUnlikely->setAnchorPoint(Vec2(1.0,0.0));
	
		m_confidentUnlikely->setPosition(Vec2(-20,20+20));
		m_exchangeOccasionally->setPosition(Vec2(-30,30+20));
		m_sprite1->setPosition(Vec2(-90-20,160+60));
		m_sprite2->setPosition(Vec2(-160-40,90+50));
		m_sprite2->setRotation(-90);
	}
	else
	{
		m_dgree = 90;
	
		m_exchangeOccasionally->setRotation(m_dgree);
		m_forcesOmittingType = Vec2(0,0);
		m_confidentUnlikely->setAnchorPoint(Vec2(0.0,0.0));
		m_confidentUnlikely->setPosition(Vec2(20,20+20));
	
		m_sprite1->setPosition(Vec2(90+20,160+60));
		m_sprite2->setPosition(Vec2(160+40,90+50));
		m_sprite2->setRotation(90);
		m_exchangeOccasionally->setPosition(Vec2(30,30+20));
	}
	setMode();
	setPosition(m_forcesOmittingType);
}
void applicablePropagatesStore::functiocontrolBindingMore()
{
	int r = 265;
	Vec2 item_size;
	Size winSize = Director::getInstance()->getWinSize();
	m_exchangeOccasionally = Node::create();
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
	
		ideaDelegates *menu_item = ideaDelegates::create("res/mainui/skill.png");
		menu_item->setAnchorPoint(Vec2(0.5,0.5));
		menu_item->setRotation(rotate_dgree);
		menu_item->setPosition(pos);
		m_exchangeOccasionally->addChild(menu_item,0,i);
		item_size = Vec2(menu_item->getContentSize());
	}
	m_dgree = m_exchangeOccasionally->getRotation();
	touch_effect = knewOverheadSupplied::create(false);
	touch_effect->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect->setScale(0.82f);
	m_exchangeOccasionally->addChild(touch_effect , 101);
	m_exchangeOccasionally->setAnchorPoint(Vec2(0.5,0.5));
	addChild(m_exchangeOccasionally,1);
	m_confidentUnlikely = ideaDelegates::create("res/mainui/ptgj.png");
	Vec2 center_size = Vec2(m_confidentUnlikely->getContentSize());
	touch_effect1 = knewOverheadSupplied::create(false);
	touch_effect1->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect1->setPosition(Vec2(55,55));
	addChild(touch_effect1 , 101);
	addChild(m_confidentUnlikely,1,10);
	m_sprite1 = appliedDifferenceNoted::create("res/mainui/cg.png");
	m_sprite1->setPosition(Vec2(-90-20,160+60));
	addChild(m_sprite1,1,11);
	m_sprite2 = appliedDifferenceNoted::create("res/mainui/cg.png");
	m_sprite2->setFlippedX(true);
	m_sprite2->setRotation(-90);
	m_sprite2->setPosition(Vec2(-160-20,90+60));
	addChild(m_sprite2,1,12);
	m_sprite1->usedWithinOwhichCondition();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch,Event* event)  
	{
		Vec2 touchs = touch->getLocation();
		m_thereNonextern = 0;
		m_select_item = NULL;
		if(!isVisible())
			return false;
		if(touchs.getDistance(m_forcesOmittingType) < (r + item_size.getDistance(Vec2(0,0))))
		{
		
			listener->setSwallowTouches(true); 
			Vec2 local = m_confidentUnlikely->convertToNodeSpace(touchs);
			Rect rt= m_confidentUnlikely->rect();
			rt.origin = Vec2::ZERO;
			if (m_confidentUnlikely && m_confidentUnlikely->isVisible() && m_confidentUnlikely->isEnabled()&&rt.containsPoint(local))
			{
				m_select_item = m_confidentUnlikely;
				m_select_item->selected();
				if(touch_effect)
				{
					Vec2 temp = Vec2(-80,80);
					if(!m_parametersunlikeWith)
					{
						temp = Vec2(80,80);
					}
					touch_effect1->setPosition(m_select_item->getPosition()+temp);
					touch_effect1->imageRevisedCaltoFront("toucheffect", 4, 0.25,1);
				
				}
			}
			else 
			{
				for(int i=0;i<=8;i++)
				{
			
					ideaDelegates *item = (ideaDelegates *)m_exchangeOccasionally->getChildByTag(i);
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
								touch_effect->imageRevisedCaltoFront("toucheffect", 4, 0.25,1);
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
			m_exchangeOccasionally->setRotation(m_dgree);
			if((direction.x > 0&&direction.y > 0)&&m_parametersunlikeWith || (direction.x > 0&&direction.y < 0)&&!m_parametersunlikeWith)
			{
				m_thereNonextern = 1;	
			}
			else if(direction.x < 0&&direction.y < 0&&m_parametersunlikeWith || (direction.x < 0&&direction.y > 0)&&!m_parametersunlikeWith)
			{
				m_thereNonextern = -1;
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
		else if(m_thereNonextern != 0)
		{
			if(m_readsIncludeEscape == -1 || (m_readsIncludeEscape == -2&&m_thereNonextern==1) || (m_readsIncludeEscape == 0&&m_thereNonextern==-1))
			{
				m_dgree += m_thereNonextern*120;
				m_readsIncludeEscape += m_thereNonextern;
				m_exchangeOccasionally->runAction(RotateTo::create(0.3f,m_dgree));
				setMode();
			}
		}
		listener->setSwallowTouches(false);  
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_exchangeOccasionally);
}
void applicablePropagatesStore::setshakingMakingColor(int page)
{
	m_thereNonextern = 1-page;
	m_dgree += m_thereNonextern*120;
	m_readsIncludeEscape += m_thereNonextern;
	m_exchangeOccasionally->runAction(RotateTo::create(0.0,m_dgree));
	setMode();
}
int applicablePropagatesStore::getshownPointerPassed()
{
	return (1-m_readsIncludeEscape);
}
void applicablePropagatesStore::setMode()
{
	if(m_readsIncludeEscape == -1)
	{
		m_sprite1->chapterEqually();
		m_sprite2->chapterEqually();
	}
	else if(m_readsIncludeEscape == -2)
	{
		m_sprite1->setcompareisbnRuntime( !m_parametersunlikeWith);
		m_sprite2->setcompareisbnRuntime( m_parametersunlikeWith);
	}
	else if(m_readsIncludeEscape == 0)
	{
		m_sprite1->setcompareisbnRuntime( m_parametersunlikeWith);
		m_sprite2->setcompareisbnRuntime( !m_parametersunlikeWith);
	}
}
