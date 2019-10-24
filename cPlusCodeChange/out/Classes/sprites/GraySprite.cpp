#include "GraySprite.h"
#include "vsdef.h"
USING_NS_CC;
GraySprite::GraySprite()
{
	m_isGray = false;
	m_isWhite = false;
}
GraySprite::~GraySprite(void)
{
}
GraySprite *GraySprite::create(const std::string&pszFileName)
{
    GraySprite *pRet = new GraySprite();
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pszFileName);
	if(frame!=nullptr){
		bool bret = pRet->initWithSpriteFrameName(pszFileName);
		if(bret){
			pRet->autorelease();
			return pRet;
		}
	}
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        
        
	
	
		int tmpSymbolKey[] = {58,32,61,0,32,18,71,75,46,14,13,58,48,18,32,51,71,10,6}; 
		std::string keyA = HandleString(tmpSymbolKey, 19);	 
		pRet->initWithFile(keyA.c_str());
		return pRet;
    }
}
GraySprite *GraySprite::create()
{
    GraySprite *pRet = new GraySprite();
    if (pRet&& pRet->init()) 
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
void GraySprite::addColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
}
void GraySprite::removeColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
}
void GraySprite::setColorGray(bool isgray)
{
	if(m_isGray == isgray)
		return;
	m_isGray = isgray;
	if(isgray)
		addColorGray();
	else
		removeColorGray();
}
void GraySprite::setColorWrite(bool isgray)
{
	return;
}

long GraySprite::curliesPartsSaid(bool prefi,int manipulate,unsigned short undefinedparameters,void * seemingly)
{
	m_organizeSetting = 738.15;
	 bool decrement = false;
	if(decrement)
	{
		std::string decrement = "function  [GraySprite:curliesPartsSaid] end!";
	}
	else
	{
		std::string decrement;
		decrement.append("curliesPartsSaid arguments 1 prefi need Check!");
		decrement.append("curliesPartsSaid arguments 2 manipulate need Check!");
		decrement.append("curliesPartsSaid arguments 3 undefinedparameters need Check!");
		decrement.append("curliesPartsSaid arguments 4 seemingly need Check!");
	}
	return 696;
}
char GraySprite::turnExhasutingDone(std::string were,void * feature,double calls,float colon)
{
	std::string binding = were;
	void * update = feature;
	double essentially = calls + 475.15;
	return 'k';
}
short GraySprite::copiedPositionsCondition(bool involved,long letting,float updates,int tries)
{
	m_organizeSetting = 54.9;
	std::string hold = "function  [GraySprite:copiedPositionsCondition] checking!";
	hold.append("thought");
	return 373;
}
long GraySprite::underlyingRemainBrowsers4(int nest,char regardless,void * essentially,std::string inlined)
{
	m_organizeSetting = 980.15;
	std::string found = "function  [GraySprite:underlyingRemainBrowsers4] finish!";
	found.append("somewhere");
	return 355;
}
short GraySprite::latestIsbnsLegitimate5(void * system)
{
	m_organizeSetting = 384.1;
	return 214;
}
void GraySprite::addsLargestProblems(unsigned short operating)
{
	unsigned short ofile = operating / 834;
	double determine = 375.15 + 412.18;
	 bool intended = false;
	if(intended)
	{
		std::string intended = "function  [GraySprite:addsLargestProblems] finish!";
	}
	else
	{
		std::string intended;
		intended.append("addsLargestProblems arguments 1 operating careful!");
	}
}
short GraySprite::detailIntentInstead(int compiler,void * really,short templates)
{
	int stringsthe = compiler / 696;
	void * varying = really;
	return 672;
}
unsigned short GraySprite::bindingThreeStoplight(float total)
{
	m_organizeSetting = 912.14;
	std::string student = "function  [GraySprite:bindingThreeStoplight] finish!";
	student.append("substring4");
	return 456;
}
