#include "AsyncDownloadManager.h"

#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif

USING_NS_CC;
USING_NS_CC_EXT;

static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
/************************************************************************/
/*                          下载器                                            */
/************************************************************************/
AsyncDownload::AsyncDownload()
:m_state(IDLE)
,m_callback(nullptr)
,m_manager(nullptr)
,base_url("")
,m_pszFileName("")
{
	errorCallback = CC_CALLBACK_1(AsyncDownload::_errorCallback, this);
	progressCallback = CC_CALLBACK_1(AsyncDownload::_progressCallback, this);
	successCallback = CC_CALLBACK_0(AsyncDownload::_successCallback, this);
}
AsyncDownload::~AsyncDownload(){
	CC_SAFE_DELETE(m_manager);
}

std::string AsyncDownload::createDownloadDir(std::string path_ex){
	std::string pathToSave = FileUtils::getInstance()->getWritablePath();
	pathToSave += "files";
	pathToSave += "/";
	pathToSave += path_ex;

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	DIR *pDir = NULL;

	pDir = opendir (pathToSave.c_str());
	if (! pDir)
	{
		mkdir(pathToSave.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
	}else{
		closedir(pDir);
	}
#else
	if ((GetFileAttributesA(pathToSave.c_str())) == INVALID_FILE_ATTRIBUTES)
	{
		CreateDirectoryA(pathToSave.c_str(), 0);
	}
#endif
	return pathToSave;
}

AsyncDownload* AsyncDownload::create(std::function<void(void)> cb,std::string pszFileName,std::string downUrl){
	AsyncDownload* ret = new AsyncDownload();
	if (ret && ret->init(cb,pszFileName,downUrl))
	{
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool AsyncDownload::init(std::function<void(void)> cb,std::string pszFileName,std::string downUrl){
	m_callback = cb;
	m_pszFileName = pszFileName;
	base_url = downUrl;
	if(m_manager == nullptr){
		std::string packageUrl = base_url + m_pszFileName;
		m_manager = AssetsManager::create(packageUrl.c_str(),"",AsyncDownload::createDownloadDir().c_str(),errorCallback,progressCallback,successCallback);
		m_manager->retain();
		m_manager->setConnectionTimeout(3);
	}
	std::string packageUrl = base_url + m_pszFileName;
	m_manager->setPackageUrl(packageUrl.c_str());
	return true;
}

void AsyncDownload::_errorCallback(int errorCode){
	// CCLOG("download error code:%d||path:%s,url:%s",errorCode,m_pszFileName.c_str(),m_manager->getPackageUrl());
	m_state = IDLE;
}
void AsyncDownload::_progressCallback(int percent){

}
void AsyncDownload::_successCallback(){
	if(m_callback) m_callback();
	m_state = IDLE;

	//TODO 下载成功，派发下载成功事件
	//CCLOG("download finish dispatch:%s",m_pszFileName.c_str());
	CCDirector::getInstance()->getEventDispatcher()->dispatchCustomEvent(m_pszFileName);
}

AsyncDownloadState AsyncDownload::getState(){
	return m_state;
}
void AsyncDownload::start(){
	m_manager->update();
	m_state = WORKING;
}
//--



/************************************************************************/
/*                      下载任务                                                */
/************************************************************************/

AsyncJob::AsyncJob(std::string pszFileName,std::function<void(void)> cb)
	:m_pszFileName(pszFileName)
	,m_cb(cb)
{}
AsyncJob::~AsyncJob(){}
//--


/************************************************************************/
/* 下载管理器                                                                     */
/************************************************************************/
AsyncDownloadManager* AsyncDownloadManager::m_instance = nullptr;
AsyncDownloadManager::AsyncDownloadManager():
m_managerInitNum(5)
,m_downsuc_cb(0)
,m_downUrl("")
{
	//TODO 开启更新
	Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}
AsyncDownloadManager::~AsyncDownloadManager()
{
	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

AsyncDownloadManager* AsyncDownloadManager::getInstance(){
	if(m_instance == nullptr){
		m_instance = new AsyncDownloadManager();
		m_instance->init();
	}
	return m_instance;
}
void AsyncDownloadManager::init(){
	//TODO 根据管理器初始数量初始化管理器列表
	for(int i=1;i<=m_managerInitNum;i++){
		AsyncDownload* ret = AsyncDownload::create(nullptr,"",m_downUrl);
		m_managerList.push_back(ret);
	}
}

void AsyncDownloadManager::setDownloadUrl(std::string url){
	m_downUrl = url;
}

void AsyncDownloadManager::addJob(std::string pszFileName,std::function<void(void)> cb){
	//TODO 检果目标路径是否已在下载任务列表或者正在下载
	if(isDownloadingOrJob(pszFileName)) return;
	//CCLOG("new job:%s",pszFileName.c_str());
	AsyncJob* job = new AsyncJob(pszFileName,cb);
	m_jobList.push(job);
	m_pszFileNameList.push_back(pszFileName);
}

bool AsyncDownloadManager::isDownloadingOrJob(std::string pszFileName){
	for(std::vector<std::string>::iterator iter = m_pszFileNameList.begin();iter != m_pszFileNameList.end();iter++){
		std::string tmp = *iter;
		if(tmp == pszFileName){
			return true;
		}
	}
	return false;
}

AsyncDownload* AsyncDownloadManager::getManagerByState(AsyncDownloadState state){
	std::vector<AsyncDownload*>::iterator iter = m_managerList.begin();
	for(iter;iter != m_managerList.end();iter++){
		AsyncDownload* tmp = *iter;
		if(tmp->getState() == state) return tmp;
	}
	return nullptr;
}

void AsyncDownloadManager::update(float dt){
	if (0 == m_managerList.size()) 
		return;	
	if (0 == m_jobList.size()) 
		return;	
	AsyncDownload* download = getManagerByState(IDLE);
	if(nullptr == download) return;
	AsyncJob* job = m_jobList.front();
	download->init(CC_CALLBACK_0(AsyncDownloadManager::downloadFinish,this,job->m_pszFileName,job->m_cb),job->m_pszFileName,m_downUrl);
	download->start();
	m_jobList.pop();
}

void AsyncDownloadManager::downloadFinish(std::string pszFileName,std::function<void(void)> cb){
	//_infoMutex.lock();
	if(cb) cb();
	for(std::vector<std::string>::iterator iter = m_pszFileNameList.begin();iter != m_pszFileNameList.end();iter++){
		std::string tmp = *iter;
		if(tmp == pszFileName){
			m_pszFileNameList.erase(iter);
			break;;
		}
	}

	//调用LUA回调
	if(m_downsuc_cb != 0){
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushString(pszFileName.c_str());
			pStack->executeFunctionByHandler(m_downsuc_cb, 1);
			pStack->clean();
		}
	}
	//_infoMutex.unlock();
}

void AsyncDownloadManager::registerDownloadSucCb(int handler)
{
	m_downsuc_cb = handler;
}

