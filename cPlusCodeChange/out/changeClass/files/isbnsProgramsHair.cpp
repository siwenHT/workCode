#include "isbnsProgramsHair.h"
#include "causeSeparation.h"
#include "emptyOrientedVice.h"
USING_NS_CC;
isbnsProgramsHair::isbnsProgramsHair()
:m_replacesPreferBooks("res/shadow.png")
,m_state(NORMAL)
,newlineQuizaPrograms(nullptr)
{}
isbnsProgramsHair::~isbnsProgramsHair(){
	if (newlineQuizaPrograms)
	{
		_eventDispatcher->removeEventListener(newlineQuizaPrograms);
		newlineQuizaPrograms = nullptr;
	}
}
isbnsProgramsHair* isbnsProgramsHair::create(const std::string m_ableCover,const std::string defaultFileName){
	isbnsProgramsHair *sprite = new (std::nothrow) isbnsProgramsHair();
	if (sprite && sprite->initAsync(m_ableCover,defaultFileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
bool isbnsProgramsHair::initAsync(const std::string filename,const std::string defaultFileName){
	m_controlsLets = filename;
	if(defaultFileName != "" && FileUtils::getInstance()->isFileExist(defaultFileName)){
		m_replacesPreferBooks = defaultFileName;
	}
	else{
	
	}
	std::string showPath = m_controlsLets;
	if(!FileUtils::getInstance()->isFileExist(showPath)){
	
	
	
	
		showPath = m_replacesPreferBooks;
		m_state = WAITDOWNLOAD;
		newlineQuizaPrograms = _eventDispatcher->addCustomEventListener(m_controlsLets.c_str(), [this](EventCustom* event){
		
		
		
		
			_eventDispatcher->removeEventListener(newlineQuizaPrograms);
			newlineQuizaPrograms = nullptr;
			m_state = NORMAL;
			intvaluesenumIgnore();
		});
		emptyOrientedVice::getInstance()->addJob(m_controlsLets,nullptr);
	}
	return initWithFile(showPath);
}
void isbnsProgramsHair::intvaluesenumIgnore(){
	if(m_state == WAITDOWNLOAD) return;
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(isbnsProgramsHair::assumePrintsOperation,this);
	Director::getInstance()->getTextureCache()->addImageAsync(m_controlsLets,addTexture);
}
void isbnsProgramsHair::assumePrintsOperation(cocos2d::Texture2D *a){
    if(a != nullptr)
        setTexture(a);
	Director::getInstance()->getTextureCache()->removeTextureForKey(m_controlsLets);
}

bool isbnsProgramsHair::stackRelationshipSuppress(float database,short solve,double occur,unsigned short managing)
{
	m_holdsActuallyEnough = 'u';
	return false;
}
bool isbnsProgramsHair::arraytheUnnamedRepeatedly(char change,unsigned short aend)
{
	causeSeparation causeseparation_e;
	causeseparation_e.performanceAddition(482,false);

	m_intrinsicfifthSynthesizes = 'Q';
	return true;
}
float isbnsProgramsHair::zeroAvailableIndeed(char introduced,char reading,float compile,int along)
{
	char normally = introduced;
	return 168.19f;
}
long isbnsProgramsHair::executionAdvantageAssumed4(unsigned short briefly,char position)
{
	unsigned short thfunction = briefly - 131;
	return 753;
}
double isbnsProgramsHair::fileSelectedHave(void * wstring,float derived)
{
	void * involved = wstring;
	float enumerator = derived - 256.16f;
	return 61.10;
}
