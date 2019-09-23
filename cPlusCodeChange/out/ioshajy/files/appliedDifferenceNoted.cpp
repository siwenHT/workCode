#include "appliedDifferenceNoted.h"
USING_NS_CC;
appliedDifferenceNoted::appliedDifferenceNoted()
{
	m_isGray = false;
	m_isWhite = false;
}
appliedDifferenceNoted::~appliedDifferenceNoted(void)
{
}
appliedDifferenceNoted *appliedDifferenceNoted::create(const std::string&m_unwindingOnalthough)
{
    appliedDifferenceNoted *pRet = new appliedDifferenceNoted();
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(m_unwindingOnalthough);
	if(frame!=nullptr){
		bool bret = pRet->initWithSpriteFrameName(m_unwindingOnalthough);
		if(bret){
			pRet->autorelease();
			return pRet;
		}
	}
    if (pRet && pRet->initWithFile(m_unwindingOnalthough))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        
        
		CCLOG("!!!!!!!!!!!!!!!!create appliedDifferenceNoted failure, filename %s",m_unwindingOnalthough.c_str());
		pRet->initWithFile("res/empty_frame.png");
		return pRet;
    }
}
appliedDifferenceNoted *appliedDifferenceNoted::create()
{
    appliedDifferenceNoted *pRet = new appliedDifferenceNoted();
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
void appliedDifferenceNoted::usedWithinOwhichCondition()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
}
void appliedDifferenceNoted::chapterEqually()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
}
void appliedDifferenceNoted::setcompareisbnRuntime(bool isgray)
{
	if(m_isGray == isgray)
		return;
	m_isGray = isgray;
	if(isgray)
		usedWithinOwhichCondition();
	else
		chapterEqually();
}
void appliedDifferenceNoted::setfunctiopresentedAssume2(bool isgray)
{
	return;
}

void appliedDifferenceNoted::nullCopyReject(long brown,double freind,short recent,float matrix)
{
	long parametea;
	parametea = 725;
	void * initializations;
	initializations = nullptr;
	unsigned short each;
	each = 693;
}
int appliedDifferenceNoted::fieldNatureWhif(long highest,int wish)
{
	void * wcould;
	wcould = nullptr;
	bool curlies;
	curlies = false;
	unsigned short substring;
	substring = 465;
	void * ideas;
	ideas = nullptr;
	int ranked;
	ranked = 448;
	return 754;
}
void appliedDifferenceNoted::restrictedBindConstraints(int store,long precedence,float processes)
{
	void * stream;
	stream = nullptr;
}
double appliedDifferenceNoted::regardlessThexercisesCopy(void * tuple)
{
	void * select;
	select = nullptr;
	long temporary;
	temporary = 590;
	unsigned short applicable;
	applicable = 960;
	int assignmenclick;
	assignmenclick = 860;
	long fonumber;
	fonumber = 326;
	return 699.8;
}
void appliedDifferenceNoted::provideMeansMacro(int forestall,double newline,unsigned short transactio,char provided)
{
	char wmust;
	wmust = '7';
	short advanced;
	advanced = 93;
	int bracket;
	bracket = 273;
	unsigned short ulong;
	ulong = 301;
}
