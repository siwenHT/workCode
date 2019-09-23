#include "functionalthoughCompiler.h"
USING_NS_CC;
#define DgreeToN(x)     (x)*3.14159/180
functionalthoughCompiler::functionalthoughCompiler()
{
	m_exceptRunningVector = 0;
	m_cardExpression = 0;
	conswhatAbove = true;
	touch_effect = NULL;
	touch_effect1 = NULL;
}
functionalthoughCompiler::~functionalthoughCompiler()
{
}
bool functionalthoughCompiler::init()
{
	thgeneratesBindsItas();
	setRight(true);
	return true;
}
void functionalthoughCompiler::setRight(bool inright)
{
	conswhatAbove = inright;
	Size winSize = Director::getInstance()->getWinSize();
	m_sprite1->setFlippedX(!inright);
	m_sprite2->setFlippedX(inright);
	if(inright)
	{
		m_dgree = 0;
		m_neverBetween->setRotation(m_dgree);
		m_representationExecute = Vec2(winSize.width,0);
		ruleButtonParametea->setAnchorPoint(Vec2(1.0,0.0));
	
		ruleButtonParametea->setPosition(Vec2(-20,20+20));
		m_neverBetween->setPosition(Vec2(-30,30+20));
		m_sprite1->setPosition(Vec2(-90-20,160+60));
		m_sprite2->setPosition(Vec2(-160-40,90+50));
		m_sprite2->setRotation(-90);
	}
	else
	{
		m_dgree = 90;
	
		m_neverBetween->setRotation(m_dgree);
		m_representationExecute = Vec2(0,0);
		ruleButtonParametea->setAnchorPoint(Vec2(0.0,0.0));
		ruleButtonParametea->setPosition(Vec2(20,20+20));
	
		m_sprite1->setPosition(Vec2(90+20,160+60));
		m_sprite2->setPosition(Vec2(160+40,90+50));
		m_sprite2->setRotation(90);
		m_neverBetween->setPosition(Vec2(30,30+20));
	}
	setMode();
	setPosition(m_representationExecute);
}
void functionalthoughCompiler::thgeneratesBindsItas()
{
	int r = 265;
	Vec2 item_size;
	Size winSize = Director::getInstance()->getWinSize();
	m_neverBetween = Node::create();
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
	
		indexingOstringstream *menu_item = indexingOstringstream::create("res/mainui/skill.png");
		menu_item->setAnchorPoint(Vec2(0.5,0.5));
		menu_item->setRotation(rotate_dgree);
		menu_item->setPosition(pos);
		m_neverBetween->addChild(menu_item,0,i);
		item_size = Vec2(menu_item->getContentSize());
	}
	m_dgree = m_neverBetween->getRotation();
	touch_effect = introducedBookstore::create(false);
	touch_effect->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect->setScale(0.82f);
	m_neverBetween->addChild(touch_effect , 101);
	m_neverBetween->setAnchorPoint(Vec2(0.5,0.5));
	addChild(m_neverBetween,1);
	ruleButtonParametea = indexingOstringstream::create("res/mainui/ptgj.png");
	Vec2 center_size = Vec2(ruleButtonParametea->getContentSize());
	touch_effect1 = introducedBookstore::create(false);
	touch_effect1->setAnchorPoint(Vec2(0.5,0.5));
	touch_effect1->setPosition(Vec2(55,55));
	addChild(touch_effect1 , 101);
	addChild(ruleButtonParametea,1,10);
	m_sprite1 = withDesigned::create("res/mainui/cg.png");
	m_sprite1->setPosition(Vec2(-90-20,160+60));
	addChild(m_sprite1,1,11);
	m_sprite2 = withDesigned::create("res/mainui/cg.png");
	m_sprite2->setFlippedX(true);
	m_sprite2->setRotation(-90);
	m_sprite2->setPosition(Vec2(-160-20,90+60));
	addChild(m_sprite2,1,12);
	m_sprite1->temporariesChapters();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch,Event* event)  
	{
		Vec2 touchs = touch->getLocation();
		m_cardExpression = 0;
		m_select_item = NULL;
		if(!isVisible())
			return false;
		if(touchs.getDistance(m_representationExecute) < (r + item_size.getDistance(Vec2(0,0))))
		{
		
			listener->setSwallowTouches(true); 
			Vec2 local = ruleButtonParametea->convertToNodeSpace(touchs);
			Rect rt= ruleButtonParametea->rect();
			rt.origin = Vec2::ZERO;
			if (ruleButtonParametea && ruleButtonParametea->isVisible() && ruleButtonParametea->isEnabled()&&rt.containsPoint(local))
			{
				m_select_item = ruleButtonParametea;
				m_select_item->selected();
				if(touch_effect)
				{
					Vec2 temp = Vec2(-80,80);
					if(!conswhatAbove)
					{
						temp = Vec2(80,80);
					}
					touch_effect1->setPosition(m_select_item->getPosition()+temp);
					touch_effect1->parametisPreventAddress("toucheffect", 4, 0.25,1);
				
				}
			}
			else 
			{
				for(int i=0;i<=8;i++)
				{
			
					indexingOstringstream *item = (indexingOstringstream *)m_neverBetween->getChildByTag(i);
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
								touch_effect->parametisPreventAddress("toucheffect", 4, 0.25,1);
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
			m_neverBetween->setRotation(m_dgree);
			if((direction.x > 0&&direction.y > 0)&&conswhatAbove || (direction.x > 0&&direction.y < 0)&&!conswhatAbove)
			{
				m_cardExpression = 1;	
			}
			else if(direction.x < 0&&direction.y < 0&&conswhatAbove || (direction.x < 0&&direction.y > 0)&&!conswhatAbove)
			{
				m_cardExpression = -1;
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
		else if(m_cardExpression != 0)
		{
			if(m_exceptRunningVector == -1 || (m_exceptRunningVector == -2&&m_cardExpression==1) || (m_exceptRunningVector == 0&&m_cardExpression==-1))
			{
				m_dgree += m_cardExpression*120;
				m_exceptRunningVector += m_cardExpression;
				m_neverBetween->runAction(RotateTo::create(0.3f,m_dgree));
				setMode();
			}
		}
		listener->setSwallowTouches(false);  
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_neverBetween);
}
void functionalthoughCompiler::setimagineWhatDiffer(int page)
{
	m_cardExpression = 1-page;
	m_dgree += m_cardExpression*120;
	m_exceptRunningVector += m_cardExpression;
	m_neverBetween->runAction(RotateTo::create(0.0,m_dgree));
	setMode();
}
int functionalthoughCompiler::getderivationManualOkay()
{
	return (1-m_exceptRunningVector);
}
void functionalthoughCompiler::setMode()
{
	if(m_exceptRunningVector == -1)
	{
		m_sprite1->addsBasicRecompile();
		m_sprite2->addsBasicRecompile();
	}
	else if(m_exceptRunningVector == -2)
	{
		m_sprite1->setdefinitionDesigning( !conswhatAbove);
		m_sprite2->setdefinitionDesigning( conswhatAbove);
	}
	else if(m_exceptRunningVector == 0)
	{
		m_sprite1->setdefinitionDesigning( conswhatAbove);
		m_sprite2->setdefinitionDesigning( !conswhatAbove);
	}
}
