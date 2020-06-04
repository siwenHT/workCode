#include "AsyncSprite.h"
#include "AsyncDownloadManager.h"
#include "vsdef.h"
USING_NS_CC;

AsyncSprite::AsyncSprite()
// :m_defaultFileName("res/shadow.png")
:m_state(NORMAL)
,m_customlistener(nullptr)
{
	int tmpSymbolKey[] = {}; //"res/shadow.png"
	m_defaultFileName = HandleString(tmpSymbolKey, STRNUMSIG);
}
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
	//TODO 检测默认纹理路径是否存在
	if(defaultFileName != "" && FileUtils::getInstance()->isFileExist(defaultFileName)){
		m_defaultFileName = defaultFileName;
	}
	else{
		//CCLOG("m_defaultFileName path not found,please check:%s",defaultFileName.c_str());
	}
	//TODO 检测目标纺纹理路径是否存在
	std::string showPath = m_pszFileName;
	if(!FileUtils::getInstance()->isFileExist(showPath)){
		//TODO 目标纹理不存在
		//TODO 显示替代纹理
		//TODO 开启纹理下载刷新监听
		//TODO 调用下载管理器，开启下载
		showPath = m_defaultFileName;
		m_state = WAITDOWNLOAD;
		m_customlistener = _eventDispatcher->addCustomEventListener(m_pszFileName.c_str(), [this](EventCustom* event){
			//TODO 刷新显示
			//TODO 移除监听
			//TODO 加载纹理，并刷新显示
			//setTexture(m_pszFileName);
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
