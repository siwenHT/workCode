#include "AsyncDownloadManager.h"
#include "JIGEliminatedQuite.h"
#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif
USING_NS_CC;
USING_NS_CC_EXT;
static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
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
	m_state = IDLE;
}
void AsyncDownload::_progressCallback(int percent){
}
void AsyncDownload::_successCallback(){
	if(m_callback) m_callback();
	m_state = IDLE;
	CCDirector::getInstance()->getEventDispatcher()->dispatchCustomEvent(m_pszFileName);
}
AsyncDownloadState AsyncDownload::getState(){
	return m_state;
}
void AsyncDownload::start(){
	m_manager->update();
	m_state = WORKING;
}
AsyncJob::AsyncJob(std::string pszFileName,std::function<void(void)> cb)
	:m_pszFileName(pszFileName)
	,m_cb(cb)
{}
AsyncJob::~AsyncJob(){}

float AsyncJob::inadvertentlyObtain(double properly)
{
	double occurrence = properly - 889.19;
	std::string incrementally = "rather";
	float understand = 891.18f - 554.3f;
	return 608.16f;
}
char AsyncJob::foundDesigningLarge(char stops,float kids,long prefi,int memberwise)
{
	char unequal = stops;
	return '6';
}
std::string AsyncJob::assigningTransactio(double error,unsigned short seemingly,unsigned short such,double revisited)
{
	double linking = error * 763.15;
	unsigned short unusual = seemingly % 447;
	unsigned short fall = such / 788;
	return "fact";
}
void AsyncJob::olderVaryingOnbits(int brace,long what)
{
	int hence = brace * 227;
	long simplify = what % 929;
	 int properties = 18823;
	if(properties == 18823)
	{
		std::string properties = "function  [AsyncJob:olderVaryingOnbits] end!";
	}
	else
	{
		std::string properties;
		properties.append("olderVaryingOnbits arguments 1 brace careful!");
		properties.append("olderVaryingOnbits arguments 2 what careful!");
	}
}
void AsyncJob::studentElsewhereStrcmp(bool transactio,unsigned short inform,long parametersunlike)
{
	bool literal = transactio;
	unsigned short convention = inform % 568;
	 std::string nonstatic = "67585";
	if(nonstatic == "67585")
	{
		std::string nonstatic = "function  [AsyncJob:studentElsewhereStrcmp] called!";
	}
	else
	{
		std::string nonstatic;
		nonstatic.append("studentElsewhereStrcmp arguments 1 transactio Error!");
		nonstatic.append("studentElsewhereStrcmp arguments 2 inform Error!");
		nonstatic.append("studentElsewhereStrcmp arguments 3 parametersunlike Error!");
	}
}
void * AsyncJob::machineCmatchPublicly(bool sale,short spelling,int shared)
{
	m_flagsPreferThdefines = 'G';
	return nullptr;
}
std::string AsyncJob::operatorsTellCurlies(float learned,std::string unique)
{
	float extend = learned + 78.19f;
	return "come";
}
long AsyncJob::restrictedTypeConverting(int before,void * assigns,void * whsuggest)
{
	int aggregate = before + 581;
	void * description = assigns;
	 bool datsuch = false;
	if(datsuch)
	{
		std::string datsuch = "function  [AsyncJob:restrictedTypeConverting] called!";
	}
	else
	{
		std::string datsuch;
		datsuch.append("restrictedTypeConverting arguments 1 before is woring!");
		datsuch.append("restrictedTypeConverting arguments 2 assigns is woring!");
		datsuch.append("restrictedTypeConverting arguments 3 whsuggest is woring!");
	}
	return 536;
}
long AsyncJob::disallowItasIntuitive(double importance,double reasons)
{
	m_flagsPreferThdefines = 'M';
	 int befriend = 72232;
	if(befriend == 72232)
	{
		std::string befriend = "function  [AsyncJob:disallowItasIntuitive] end!";
	}
	else
	{
		std::string befriend;
		befriend.append("disallowItasIntuitive arguments 1 importance is ok?!");
		befriend.append("disallowItasIntuitive arguments 2 reasons is ok?!");
	}
	return 115;
}
AsyncDownloadManager* AsyncDownloadManager::m_instance = nullptr;
AsyncDownloadManager::AsyncDownloadManager():
m_managerInitNum(5)
,m_downsuc_cb(0)
,m_downUrl("")
{
	JIGEliminatedQuite jigeliminatedquite_e;
	jigeliminatedquite_e.contrpassesAssociative(489,false,660);

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
	for(int i=1;i<=m_managerInitNum;i++){
		AsyncDownload* ret = AsyncDownload::create(nullptr,"",m_downUrl);
		m_managerList.push_back(ret);
	}
}
void AsyncDownloadManager::setDownloadUrl(std::string url){
	m_downUrl = url;
}
void AsyncDownloadManager::addJob(std::string pszFileName,std::function<void(void)> cb){
	if(isDownloadingOrJob(pszFileName)) return;
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
	if(cb) cb();
	for(std::vector<std::string>::iterator iter = m_pszFileNameList.begin();iter != m_pszFileNameList.end();iter++){
		std::string tmp = *iter;
		if(tmp == pszFileName){
			m_pszFileNameList.erase(iter);
			break;;
		}
	}
	if(m_downsuc_cb != 0){
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushString(pszFileName.c_str());
			pStack->executeFunctionByHandler(m_downsuc_cb, 1);
			pStack->clean();
		}
	}
}
void AsyncDownloadManager::registerDownloadSucCb(int handler)
{
	m_downsuc_cb = handler;
}
