#include "GraySprite.h"
#include "careFuntion.h"
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
        
        
		CCLOG("!!!!!!!!!!!!!!!!create GraySprite failure, filename %s",pszFileName.c_str());
		pRet->initWithFile("res/empty_frame.png");
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

float GraySprite::protectionVectorsReally5(float real,double ignored)
{
	float nonmember = real - 904.6f;
	double blobptr = ignored * 551.15;
	bool time = false;
	return 764.2f;
}
void * GraySprite::freeInteresting(bool emplace,double redeclare)
{
	bool analogously = emplace;
	double versions = redeclare - 752.19;
	unsigned short errors = 901 * 260;
	return nullptr;
}
double GraySprite::seesManipulateOfferEach(long inadvertently)
{
	long generic = inadvertently / 771;
	void * complex = nullptr;
	return 965.2;
}
int GraySprite::ostringstreamPrevent(unsigned short would,bool finding)
{
	m_reasonsCopiesConceptually = 871;
	return 281;
}
unsigned short GraySprite::conventionsSwappedPush(void * faced,void * initializes)
{
	void * changed = faced;
	return 139;
}
float GraySprite::unrelatedCountsPromotes(unsigned short isbn,float person,float terms,int knowledge)
{
	unsigned short flips = isbn - 947;
	return 342.11f;
}
void GraySprite::reversesContentsMutually(void * jumping,short technique,double propagates,short enumeration)
{
	careFuntion carefuntion_e;
	carefuntion_e.pointersHaveUnderlying(false);

	m_preventSaysOught = 402.5f;
}
int GraySprite::seeminglyInvalid(short specializes,unsigned short open)
{
	m_preventSaysOught = 11.15f;
	return 295;
}
void GraySprite::connectionBecomesTogether(float code,double framework,double certain,float convention)
{
	float fails = code + 342.6f;
	double commonly = framework * 235.8;
}
double GraySprite::purposeFailsUnderstand(int coverage,float cout)
{
	m_preventSaysOught = 139.13f;
	return 160.11;
}
short GraySprite::againInitializes(float destructor)
{
	float mube = destructor * 272.10f;
	short construct = 649 - 476;
	return 464;
}
