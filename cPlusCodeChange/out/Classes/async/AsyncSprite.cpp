#include "AsyncSprite.h"
#include "causeSeparation.h"
#include "AsyncDownloadManager.h"
USING_NS_CC;
AsyncSprite::AsyncSprite()
:m_defaultFileName("res/shadow.png")
,m_state(NORMAL)
,m_customlistener(nullptr)
{}
AsyncSprite::~AsyncSprite(){
	if (m_customlistener)
	{
		_eventDispatcher->removeEventListener(m_customlistener);
		m_customlistener = nullptr;
	}
}
AsyncSprite* AsyncSprite::create(const std::string pszFileName,const std::string defaultFileName){
	AsyncSprite *sprite = new (std::nothrow) AsyncSprite();
	if (sprite && sprite->initAsync(pszFileName,defaultFileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
bool AsyncSprite::initAsync(const std::string filename,const std::string defaultFileName){
	m_pszFileName = filename;
	if(defaultFileName != "" && FileUtils::getInstance()->isFileExist(defaultFileName)){
		m_defaultFileName = defaultFileName;
	}
	else{
	
	}
	std::string showPath = m_pszFileName;
	if(!FileUtils::getInstance()->isFileExist(showPath)){
	
	
	
	
		showPath = m_defaultFileName;
		m_state = WAITDOWNLOAD;
		m_customlistener = _eventDispatcher->addCustomEventListener(m_pszFileName.c_str(), [this](EventCustom* event){
		
		
		
		
			_eventDispatcher->removeEventListener(m_customlistener);
			m_customlistener = nullptr;
			m_state = NORMAL;
			addCacheSprites();
		});
		AsyncDownloadManager::getInstance()->addJob(m_pszFileName,nullptr);
	}
	return initWithFile(showPath);
}
void AsyncSprite::addCacheSprites(){
	if(m_state == WAITDOWNLOAD) return;
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(AsyncSprite::addTextureSprite,this);
	Director::getInstance()->getTextureCache()->addImageAsync(m_pszFileName,addTexture);
}
void AsyncSprite::addTextureSprite(cocos2d::Texture2D *a){
    if(a != nullptr)
        setTexture(a);
	Director::getInstance()->getTextureCache()->removeTextureForKey(m_pszFileName);
}

bool AsyncSprite::stackRelationshipSuppress(float database,short solve,double occur,unsigned short managing)
{
	m_holdsActuallyEnough = 'u';
	return false;
}
bool AsyncSprite::arraytheUnnamedRepeatedly(char change,unsigned short aend)
{
	causeSeparation causeseparation_e;
	causeseparation_e.performanceAddition(482,false);

	m_intrinsicfifthSynthesizes = 'Q';
	return true;
}
float AsyncSprite::zeroAvailableIndeed(char introduced,char reading,float compile,int along)
{
	char normally = introduced;
	return 168.19f;
}
long AsyncSprite::executionAdvantageAssumed4(unsigned short briefly,char position)
{
	unsigned short thfunction = briefly - 131;
	return 753;
}
double AsyncSprite::fileSelectedHave(void * wstring,float derived)
{
	void * involved = wstring;
	float enumerator = derived - 256.16f;
	return 61.10;
}
