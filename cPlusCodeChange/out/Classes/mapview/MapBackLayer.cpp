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
void * MapBackLayer::strcmpIntroductoryItas(int inlined)
{
	int file = inlined % 354;
	float often = 579.17f * 673.8f;
	bool programmer = true;
	std::string number = "function  [MapBackLayer:strcmpIntroductoryItas] finish!";
	number.append("nocopy");
	return nullptr;
}
int MapBackLayer::specializationAlgorithms(unsigned short nonpointer,short doing)
{
	unsigned short omitting = nonpointer + 709;
	return 925;
}
char MapBackLayer::definitionThemExit5(unsigned short manager,void * limit)
{
	unsigned short returns = manager % 297;
	return 'C';
}
char MapBackLayer::knownMenuApplicable(unsigned short should)
{
	m_wordsRefersPointed = 404;
	 int evaluating = 77647;
	if(evaluating == 77647)
	{
		std::string evaluating = "function  [MapBackLayer:knownMenuApplicable] begin!";
	}
	else
	{
		std::string evaluating;
		evaluating.append("knownMenuApplicable arguments 1 should need Check!");
	}
	return 'W';
}
bool MapBackLayer::definitionsPresented(std::string aside)
{
	std::string given = aside;
	short constitutes = 828 + 839;
	 bool state = false;
	if(state)
	{
		std::string state = "function  [MapBackLayer:definitionsPresented] calling!";
	}
	else
	{
		std::string state;
		state.append("definitionsPresented arguments 1 aside Ok!");
	}
	return false;
}
int MapBackLayer::fallModifyList(long owhich,unsigned short initially,long type,short enumerations)
{
	long definition = owhich + 836;
	unsigned short consts = initially / 618;
	std::string reside = "function  [MapBackLayer:fallModifyList] ok!";
	reside.append("dereferences1");
	return 955;
}
float MapBackLayer::convertedSwappedTaking(unsigned short want)
{
	unsigned short access = want + 723;
	double idea = 807.14 * 643.1;
	std::string passed = "function  [MapBackLayer:convertedSwappedTaking] end!";
	passed.append("rewrites");
	return 463.8f;
}
int MapBackLayer::personExhasuting(std::string stringth,char find,double full,char exhasuting)
{
	std::string nontype = stringth;
	char control = find;
	double sure = full * 852.2;
	 int assumed = 46129;
	if(assumed == 46129)
	{
		std::string assumed = "function  [MapBackLayer:personExhasuting] ok!";
	}
	else
	{
		std::string assumed;
		assumed.append("personExhasuting arguments 1 stringth is woring!");
		assumed.append("personExhasuting arguments 2 find is woring!");
		assumed.append("personExhasuting arguments 3 full is woring!");
		assumed.append("personExhasuting arguments 4 exhasuting is woring!");
	}
	return 852;
}
