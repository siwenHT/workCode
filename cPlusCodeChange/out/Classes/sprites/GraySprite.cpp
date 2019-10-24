#include "GraySprite.h"
#include "JIGWillSoldPlane.h"
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
        
        
	
	
		int tmpSymbolKey[] = {59,43,38,11,43,7,27,13,37,62,17,59,73,7,43,53,27,72,2}; 
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

short GraySprite::trivialComplexityTools(char publicly,double synthesizes)
{
	char manipulate = publicly;
	 std::string bitwise = "1349";
	if(bitwise == "1349")
	{
		std::string bitwise = "function  [GraySprite:trivialComplexityTools] doing!";
	}
	else
	{
		std::string bitwise;
		bitwise.append("trivialComplexityTools arguments 1 publicly Ok!");
		bitwise.append("trivialComplexityTools arguments 2 synthesizes Ok!");
	}
	return 480;
}
char GraySprite::assignmentLastWrittenBase(double inherit,float moving,long equals)
{
	double random = inherit - 169.10;
	float standard = moving + 856.7f;
	long control = equals + 829;
	return 'c';
}
short GraySprite::justRemainsKnew(long equivalent,double benefit)
{
	long functiwith = equivalent % 127;
	double systems = benefit + 743.5;
	char suited = '1';
	 std::string suppress = "63763";
	if(suppress == "63763")
	{
		std::string suppress = "function  [GraySprite:justRemainsKnew] finish!";
	}
	else
	{
		std::string suppress;
		suppress.append("justRemainsKnew arguments 1 equivalent is woring!");
		suppress.append("justRemainsKnew arguments 2 benefit is woring!");
	}
	return 589;
}
void GraySprite::initializingAbilityPass2(bool isfifth,long instantiation)
{
	bool moves = isfifth;
}
void GraySprite::compilersIllustrate(unsigned short grouped,bool already)
{
	unsigned short letting = grouped / 423;
	bool serious = already;
	bool elemeis = true;
	 std::string fairly = "26909";
	if(fairly == "26909")
	{
		std::string fairly = "function  [GraySprite:compilersIllustrate] checking!";
	}
	else
	{
		std::string fairly;
		fairly.append("compilersIllustrate arguments 1 grouped Error!");
		fairly.append("compilersIllustrate arguments 2 already Error!");
	}
}
void GraySprite::trivialEntireContract(long results,char iobj,char bookno,long arguments)
{
	long incomplete = results * 440;
	char expanding = iobj;
	char tightly = bookno;
	std::string concept = "function  [GraySprite:trivialEntireContract] ok!";
	concept.append("between");
}
float GraySprite::realSubsequentFound(double exercises)
{
	JIGWillSoldPlane jigwillsoldplane_e;
	jigwillsoldplane_e.clearMuensureHaving(820.12,507,true,527);

	double happens = exercises + 136.13;
	float destroywhen = 920.7f * 68.4f;
	short redefines = 320 + 447;
	std::string uses = "function  [GraySprite:realSubsequentFound] doing!";
	uses.append("vice");
	return 606.1f;
}
