#include "withDesigned.h"
#include "careFuntion.h"
USING_NS_CC;
withDesigned::withDesigned()
{
	m_isGray = false;
	m_isWhite = false;
}
withDesigned::~withDesigned(void)
{
}
withDesigned *withDesigned::create(const std::string&m_ableCover)
{
    withDesigned *pRet = new withDesigned();
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(m_ableCover);
	if(frame!=nullptr){
		bool bret = pRet->initWithSpriteFrameName(m_ableCover);
		if(bret){
			pRet->autorelease();
			return pRet;
		}
	}
    if (pRet && pRet->initWithFile(m_ableCover))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        
        
		CCLOG("!!!!!!!!!!!!!!!!create withDesigned failure, filename %s",m_ableCover.c_str());
		pRet->initWithFile("res/empty_frame.png");
		return pRet;
    }
}
withDesigned *withDesigned::create()
{
    withDesigned *pRet = new withDesigned();
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
void withDesigned::temporariesChapters()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
}
void withDesigned::addsBasicRecompile()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
}
void withDesigned::setdefinitionDesigning(bool isgray)
{
	if(m_isGray == isgray)
		return;
	m_isGray = isgray;
	if(isgray)
		temporariesChapters();
	else
		addsBasicRecompile();
}
void withDesigned::setpartsMattersSelects(bool isgray)
{
	return;
}

float withDesigned::protectionVectorsReally5(float real,double ignored)
{
	float nonmember = real - 904.6f;
	double blobptr = ignored * 551.15;
	bool time = false;
	return 764.2f;
}
void * withDesigned::freeInteresting(bool emplace,double redeclare)
{
	bool analogously = emplace;
	double versions = redeclare - 752.19;
	unsigned short errors = 901 * 260;
	return nullptr;
}
double withDesigned::seesManipulateOfferEach(long inadvertently)
{
	long generic = inadvertently / 771;
	void * complex = nullptr;
	return 965.2;
}
int withDesigned::ostringstreamPrevent(unsigned short would,bool finding)
{
	m_reasonsCopiesConceptually = 871;
	return 281;
}
unsigned short withDesigned::conventionsSwappedPush(void * faced,void * initializes)
{
	void * changed = faced;
	return 139;
}
float withDesigned::unrelatedCountsPromotes(unsigned short isbn,float person,float terms,int knowledge)
{
	unsigned short flips = isbn - 947;
	return 342.11f;
}
void withDesigned::reversesContentsMutually(void * jumping,short technique,double propagates,short enumeration)
{
	careFuntion carefuntion_e;
	carefuntion_e.pointersHaveUnderlying(false);

	m_preventSaysOught = 402.5f;
}
int withDesigned::seeminglyInvalid(short specializes,unsigned short open)
{
	m_preventSaysOught = 11.15f;
	return 295;
}
void withDesigned::connectionBecomesTogether(float code,double framework,double certain,float convention)
{
	float fails = code + 342.6f;
	double commonly = framework * 235.8;
}
double withDesigned::purposeFailsUnderstand(int coverage,float cout)
{
	m_preventSaysOught = 139.13f;
	return 160.11;
}
short withDesigned::againInitializes(float destructor)
{
	float mube = destructor * 272.10f;
	short construct = 649 - 476;
	return 464;
}
