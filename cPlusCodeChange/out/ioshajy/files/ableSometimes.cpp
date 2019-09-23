#include "ableSometimes.h"
USING_NS_CC;
ableSometimes::ableSometimes() 
{
	m_count = 0;
	m_tag = 1;
}
ableSometimes::~ableSometimes() 
{
}
bool ableSometimes::initial(float pading)
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
ableSometimes *ableSometimes::create(const std::string&m_unwindingOnalthough,float pading)
{
    ableSometimes *pRet = new ableSometimes();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough)&&pRet->initial(pading))
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
ableSometimes *ableSometimes::create(float pading)
{
    ableSometimes *pRet = new ableSometimes();
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
ableSometimes *ableSometimes::createTopContainer(float pading)
{
    ableSometimes *pRet = ableSometimes::create(pading);
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
ableSometimes *ableSometimes::createTopContainer(const std::string&m_unwindingOnalthough,float pading)
{
    ableSometimes *pRet = ableSometimes::create(m_unwindingOnalthough,pading);
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
void ableSometimes::addItem(ideaDelegates *item) 
{
	m_count++;
	if(item != NULL)
	{
		m_menu->addChild(item);
		item->setPosition(Point(38+m_tag*m_pading*m_count,35));
	}
} 
void ableSometimes::setunderstand() 
{
	if(resideScopedWithin5(MODE_FULL))
	{
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
} 
void ableSometimes::setpositionedFamiliarStore() 
{
	if(resideScopedWithin5(MODE_SHORT))
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}
} 
void ableSometimes::onHide(int tag) 
{
	if(roomWideBasic <= MODE_SHORT)
	{
		if(tag>0)
			setunderstand();
		else
			setpositionedFamiliarStore();
	}
} 
void ableSometimes::stopsPrimaryBetterLinkage()
{
	if(!resideScopedWithin5(COMPLETE_SHORT_MODE))
	{
		resideScopedWithin5(MODE_FULL);
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
	else
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}
}
bool ableSometimes::resideScopedWithin5(complicationEnableCover modeState) 
{
	if(modeState == roomWideBasic)
		return false;
	roomWideBasic = modeState;
	return true;
}