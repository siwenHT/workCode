#include "identifyingActually.h"
USING_NS_CC;
identifyingActually::identifyingActually() 
{
	m_count = 0;
	m_tag = 1;
}
identifyingActually::~identifyingActually() 
{
}
bool identifyingActually::initial(float pading)
{
	bool ret = false;
	do {
		setAnchorPoint(Point(0.0,0.0));
		m_menu = Menu::create();
		m_pading = pading;
		Size winSize = Director::getInstance()->getWinSize();
		m_menu->setPosition(Point());
		addChild(m_menu);
		ret = true;
	}while(false);
	return ret;
}
identifyingActually *identifyingActually::create(const std::string&m_ableCover,float pading)
{
    identifyingActually *pRet = new identifyingActually();
    if (pRet && pRet->initWithFile(m_ableCover)&&pRet->initial(pading))
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
identifyingActually *identifyingActually::create(float pading)
{
    identifyingActually *pRet = new identifyingActually();
    if (pRet && pRet->init()&&pRet->initial(pading))
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
identifyingActually *identifyingActually::createTopContainer(float pading)
{
    identifyingActually *pRet = identifyingActually::create(pading);
    if (pRet)
    {
		pRet->setTopTag(-1);
        return pRet;
    }
    else
    {
        return NULL;
    }
}
identifyingActually *identifyingActually::createTopContainer(const std::string&m_ableCover,float pading)
{
    identifyingActually *pRet = identifyingActually::create(m_ableCover,pading);
    if (pRet)
    {
		pRet->setTopTag(-1);
        return pRet;
    }
    else
    {
        return NULL;
    }
}
void identifyingActually::addItem(indexingOstringstream *item) 
{
	m_count++;
	if(item != NULL)
	{
		m_menu->addChild(item);
		item->setPosition(Point(38+m_tag*m_pading*m_count,35));
	}
} 
void identifyingActually::setuniqueCoutPositioned() 
{
	if(startsModelTypeinfoHeld(MODE_FULL))
	{
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
} 
void identifyingActually::setdetailsReferLetting() 
{
	if(startsModelTypeinfoHeld(MODE_SHORT))
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}
} 
void identifyingActually::onHide(int tag) 
{
	if(m_despiteApplicationsLonger <= MODE_SHORT)
	{
		if(tag>0)
			setuniqueCoutPositioned();
		else
			setdetailsReferLetting();
	}
} 
void identifyingActually::performanceGuideCalls()
{
	if(!startsModelTypeinfoHeld(COMPLETE_SHORT_MODE))
	{
		startsModelTypeinfoHeld(MODE_FULL);
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
	else
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}
}
bool identifyingActually::startsModelTypeinfoHeld(loopStoredModel modeState) 
{
	if(modeState == m_despiteApplicationsLonger)
		return false;
	m_despiteApplicationsLonger = modeState;
	return true;
}