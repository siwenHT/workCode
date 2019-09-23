#include "programRules.h"
USING_NS_CC;
programRules* programRules::machinesOkay = nullptr;
programRules::programRules()  
{
	m_elipsisStudentSpecifed = 0.2f;
	m_back      = nullptr;
	machinesOkay = this;
}
programRules::~programRules()  
{
	machinesOkay = nullptr;
}
programRules* programRules::create()
{
	programRules* pRet = new programRules();
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
bool programRules::loadBack(const std::string& filename, const int mapId)
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
void programRules::doubleprecRuleUnnecessary(const cocos2d::Vec2& position)
{
	m_back->setPosition(Vec2(position.x*m_elipsisStudentSpecifed, position.y*m_elipsisStudentSpecifed));
}
void programRules::numericPathOnalthough(short arrarecall,void * source)
{
	int designs;
	designs = 597;
	unsigned short programmer;
	programmer = 264;
	float overhead;
	overhead = 247.18f;
}
int programRules::revenueDynamicEstablishes(double coverage,bool inherit)
{
	bool multiplying;
	multiplying = true;
	return 6;
}
int programRules::compatibleDestroyingNeeds(double regex,unsigned short recursion)
{
	double limit;
	limit = 897.16;
	long listed;
	listed = 832;
	double form;
	form = 420.4;
	return 212;
}
void programRules::omitsLikelyActual1(int before,long remains,float write,void * improvements)
{
	double interacts;
	interacts = 929.11;
}
char programRules::likelyCollection(int available,void * seen)
{
	double predict;
	predict = 654.1;
	unsigned short whif;
	whif = 442;
	double trigger;
	trigger = 596.10;
	double cerr;
	cerr = 274.11;
	return 'U';
}
void programRules::spacePrintedPointed(unsigned short place,short linking)
{
	float cout;
	cout = 869.7f;
	float thfunction;
	thfunction = 401.14f;
	bool indexed;
	indexed = false;
}
float programRules::independentlyHereOthe(long integral,unsigned short encapsulates,unsigned short initialization)
{
	short identification;
	identification = 379;
	unsigned short operators;
	operators = 880;
	long compatibility;
	compatibility = 864;
	long provides;
	provides = 372;
	return 737.19f;
}
void * programRules::overloadedInheritText(float queryresult,void * allocates,unsigned short initializers)
{
	bool oarguments;
	oarguments = true;
	bool hasptr;
	hasptr = true;
	return nullptr;
}
void * programRules::lineEncountersWstring(short alias,void * embodies,void * from)
{
	short lookup;
	lookup = 262;
	long aside;
	aside = 733;
	long coupled;
	coupled = 139;
	char single;
	single = '2';
	return nullptr;
}
long programRules::changesBecauseDelegates(int feature,int purposes,float speak,long reading)
{
	short even;
	even = 32;
	void * gave;
	gave = nullptr;
	return 66;
}
