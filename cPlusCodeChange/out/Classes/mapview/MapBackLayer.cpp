#include "MapBackLayer.h"
#include "JIGPromotedPropagatesMG.h"
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
std::string MapBackLayer::includeNextOptionsUseful(void * reduce)
{
	void * identify = reduce;
	unsigned short calculates = 866 + 538;
	return "content";
}
float MapBackLayer::convenientInitialization5(char relational)
{
	JIGPromotedPropagatesMG jigpromotedpropagatesmg_e;
	jigpromotedpropagatesmg_e.tyhaveActuasizeWhole('P',808);

	char reading = relational;
	char importance = '3';
	unsigned short operands = 74 * 860;
	return 85.5f;
}
void MapBackLayer::independentlyInevitably(bool pointer,int avoid,double behalf,std::string detail)
{
	bool calculated = pointer;
}
long MapBackLayer::indexIntegralAdvantages(unsigned short implementing,short loop)
{
	unsigned short prior = implementing - 155;
	std::string structure = "function  [MapBackLayer:indexIntegralAdvantages] called!";
	structure.append("labels");
	return 227;
}
long MapBackLayer::gavePrintsFlagEquals(short limited,float pairwise,int care)
{
	short ordinary = limited % 632;
	float argumentobjects = pairwise - 11.2f;
	int second = care - 549;
	 bool tree = false;
	if(tree)
	{
		std::string tree = "function  [MapBackLayer:gavePrintsFlagEquals] done!";
	}
	else
	{
		std::string tree;
		tree.append("gavePrintsFlagEquals arguments 1 limited is woring!");
		tree.append("gavePrintsFlagEquals arguments 2 pairwise is woring!");
		tree.append("gavePrintsFlagEquals arguments 3 care is woring!");
	}
	return 593;
}
float MapBackLayer::basicsAllocatesIsbns(bool preventing)
{
	bool revisited = preventing;
	void * unrelated = nullptr;
	float listed = 268.18f * 891.4f;
	return 281.3f;
}
