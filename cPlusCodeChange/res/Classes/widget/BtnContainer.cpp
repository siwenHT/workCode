#include "BtnContainer.h"


USING_NS_CC;

BtnContainer::BtnContainer() 
{
	m_count = 0;
	m_tag = 1;
}

BtnContainer::~BtnContainer() 
{
}

bool BtnContainer::initial(float pading)
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

BtnContainer *BtnContainer::create(const std::string&pszFileName,float pading)
{
    BtnContainer *pRet = new BtnContainer();
    if (pRet && pRet->initWithFile(pszFileName)&&pRet->initial(pading))
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

BtnContainer *BtnContainer::create(float pading)
{
    BtnContainer *pRet = new BtnContainer();
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

BtnContainer *BtnContainer::createTopContainer(float pading)
{
    BtnContainer *pRet = BtnContainer::create(pading);
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

BtnContainer *BtnContainer::createTopContainer(const std::string&pszFileName,float pading)
{
    BtnContainer *pRet = BtnContainer::create(pszFileName,pading);
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

void BtnContainer::addItem(MenuButton *item) 
{
	m_count++;
	if(item != NULL)
	{
		m_menu->addChild(item);
		item->setPosition(Point(38+m_tag*m_pading*m_count,35));
	}
} 

void BtnContainer::setFullMode() 
{
	if(changeMode(MODE_FULL))
	{
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
} 

void BtnContainer::setShortMode() 
{
	if(changeMode(MODE_SHORT))
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}
} 

void BtnContainer::onHide(int tag) 
{
	if(m_currMode <= MODE_SHORT)
	{
		if(tag>0)
			setFullMode();
		else
			setShortMode();
	}
} 

void BtnContainer::changeFullShortMode()
{
	if(!changeMode(COMPLETE_SHORT_MODE))
	{
		changeMode(MODE_FULL);
		runAction(MoveBy::create(0.5,Point(0,m_tag*200)));
	}
	else
	{
		runAction(MoveBy::create(0.3,Point(0,m_tag*(-200))));
	}

}

bool BtnContainer::changeMode(ModeState modeState) 
{
	if(modeState == m_currMode)
		return false;
	m_currMode = modeState;
	return true;
}