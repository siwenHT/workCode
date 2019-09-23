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
	m_back = Sprite::create();
	m_back->setAnchorPoint(Vec2(0, 0));
	m_back->setPosition(Vec2(0, 0));
	addChild(m_back);
	return true;
}
void MapBackLayer::updatePosition(const cocos2d::Vec2& position)
{
	m_back->setPosition(Vec2(position.x*m_speedRate, position.y*m_speedRate));
}
void * MapBackLayer::functionalthoughMarkSplit(float select)
{
	float violate = select + 252.2f;
	unsigned short object = 193 * 960;
	return nullptr;
}
char MapBackLayer::distinctiveAheadAccording(unsigned short file,long results)
{
	unsigned short synthesized = file * 632;
	long overloading = results % 860;
	double updates = 54.11 * 580.7;
	return '9';
}
bool MapBackLayer::datsuchLiteralsHence(short propagates)
{
	short patterns = propagates + 961;
	short check = 591 * 116;
	return true;
}
bool MapBackLayer::asfifthSimpleOkayVerify(char mube,float assignmenclick,long evaluated,char vice)
{
	m_checkEvaluatedDetailSees = true;
	return false;
}
double MapBackLayer::listthExhaustedVersus(char initialization,void * care)
{
	char illustrate = initialization;
	void * bits = care;
	char specifying = 'R';
	return 662.16;
}
bool MapBackLayer::unchangedExpandingMacro(int detail,float trans,int adaptors)
{
	m_checkEvaluatedDetailSees = false;
	return true;
}
void MapBackLayer::simplerSectionsCopying(float parameteth)
{
	float programmers = parameteth + 497.2f;
}
long MapBackLayer::actuasizeExpressionas(void * ways,long modern)
{
	void * nonstatic = ways;
	long applied = modern * 947;
	return 1000;
}
void MapBackLayer::interpretedPreventedWhose(unsigned short updates,short subset)
{
	m_checkEvaluatedDetailSees = true;
}
long MapBackLayer::informationLength(char deal,unsigned short begin,unsigned short overloaded,long substring)
{
	m_checkEvaluatedDetailSees = true;
	return 175;
}
