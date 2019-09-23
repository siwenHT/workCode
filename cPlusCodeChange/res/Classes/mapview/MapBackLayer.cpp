#include "MapBackLayer.h"
USING_NS_CC;

MapBackLayer* MapBackLayer::DefaultMapBackLayer = nullptr;
MapBackLayer::MapBackLayer()  
{
	m_speedRate = 0.2f;
	m_back      = nullptr;

	DefaultMapBackLayer = this;
}

MapBackLayer::~MapBackLayer()  
{
	DefaultMapBackLayer = nullptr;
}

MapBackLayer* MapBackLayer::create()
{
	MapBackLayer* pRet = new MapBackLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return nullptr;
}

bool MapBackLayer::loadBack(const std::string& filename, const int mapId)
{
	if(filename.length() <= 0 )
	{
		return false;
	}
	
	int indxe = filename.find (".");
	std::string backFileName = filename.substr(0,  indxe+1);
	backFileName += "png";

	m_back = Sprite::create(/*backFileName*/);
	m_back->setAnchorPoint(Vec2(0, 0));
	m_back->setPosition(Vec2(0, 0));
	addChild(m_back);

	return true;
}

void MapBackLayer::updatePosition(const cocos2d::Vec2& position)
{
	m_back->setPosition(Vec2(position.x*m_speedRate, position.y*m_speedRate));
	//CCLOG("%f ----------------- %f", x, y);
}