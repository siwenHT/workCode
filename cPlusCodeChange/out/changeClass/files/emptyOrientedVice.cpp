#include "emptyOrientedVice.h"
#include "applicationsIostream.h"
#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif
USING_NS_CC;
USING_NS_CC_EXT;
static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
explainsOrdinary::explainsOrdinary()
:m_state(IDLE)
,m_callback(nullptr)
,m_manager(nullptr)
,base_url("")
,m_controlsLets("")
{
	m_surprisingIntvaluesenum = CC_CALLBACK_1(explainsOrdinary::pathComplicationIdentify, this);
	m_checkStoprocessing = CC_CALLBACK_1(explainsOrdinary::angleOnbitsReviewPrecise, this);
	m_skimCollide = CC_CALLBACK_0(explainsOrdinary::carsAuxiliaryDifferences, this);
}
explainsOrdinary::~explainsOrdinary(){
	CC_SAFE_DELETE(m_manager);
}
std::string explainsOrdinary::forwardQuizRequire(std::string path_ex){
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
explainsOrdinary* explainsOrdinary::create(std::function<void(void)> cb,std::string m_ableCover,std::string downUrl){
	explainsOrdinary* ret = new explainsOrdinary();
	if (ret && ret->init(cb,m_ableCover,downUrl))
	{
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
bool explainsOrdinary::init(std::function<void(void)> cb,std::string m_ableCover,std::string downUrl){
	m_callback = cb;
	m_controlsLets = m_ableCover;
	base_url = downUrl;
	if(m_manager == nullptr){
		std::string packageUrl = base_url + m_controlsLets;
		m_manager = AssetsManager::create(packageUrl.c_str(),"",explainsOrdinary::forwardQuizRequire().c_str(),m_surprisingIntvaluesenum,m_checkStoprocessing,m_skimCollide);
		m_manager->retain();
		m_manager->setConnectionTimeout(3);
	}
	std::string packageUrl = base_url + m_controlsLets;
	m_manager->setPackageUrl(packageUrl.c_str());
	return true;
}
void explainsOrdinary::pathComplicationIdentify(int errorCode){
	CCLOG("download error code:%d||path:%s,url:%s",errorCode,m_controlsLets.c_str(),m_manager->getPackageUrl());
	m_state = IDLE;
}
void explainsOrdinary::angleOnbitsReviewPrecise(int percent){
}
void explainsOrdinary::carsAuxiliaryDifferences(){
	if(m_callback) m_callback();
	m_state = IDLE;
	CCDirector::getInstance()->getEventDispatcher()->dispatchCustomEvent(m_controlsLets);
}
independentPath explainsOrdinary::getState(){
	return m_state;
}
void explainsOrdinary::start(){
	m_manager->update();
	m_state = WORKING;
}
advantagesPassingReject::advantagesPassingReject(std::string m_ableCover,std::function<void(void)> cb)
	:m_controlsLets(m_ableCover)
	,m_cb(cb)
{}
advantagesPassingReject::~advantagesPassingReject(){}

float advantagesPassingReject::separatelyRegularMust(short precede,float select)
{
	m_varyingRationale = 'q';
	return 334.0f;
}
long advantagesPassingReject::lookingFunctionality(double implementation,unsigned short character,unsigned short generally)
{
	double card = implementation - 51.9;
	return 115;
}
void advantagesPassingReject::avoidContrpasses(short explains)
{
	short onalthough = explains * 898;
	char operands = '8';
}
char advantagesPassingReject::deallocatingValuelike(int select,char references)
{
	m_varyingRationale = 'L';
	return '6';
}
void advantagesPassingReject::downTransactioElem(long bitset)
{
	long largely = bitset + 818;
	void * args = nullptr;
	int wide = 97 % 357;
}
void advantagesPassingReject::fifthPepperbyProvide(float generated,bool consider,float involve,int real)
{
	float declares = generated + 478.16f;
	bool subset = consider;
	float evaluating = involve - 154.3f;
}
unsigned short advantagesPassingReject::correctnessRemoved(double make,long prohibit)
{
	double execute = make * 661.5;
	long declaring = prohibit - 49;
	return 791;
}
unsigned short advantagesPassingReject::markerTransactions(char compare,float constant,double unrelated,unsigned short varying)
{
	char notify = compare;
	float loop = constant + 98.2f;
	double preventing = unrelated + 875.14;
	return 417;
}
emptyOrientedVice* emptyOrientedVice::m_encapsulatesIndicating = nullptr;
emptyOrientedVice::emptyOrientedVice():
m_functiocontrolNeedingHair(5)
,correspondsWhtheVaries(0)
,m_downUrl("")
{
	applicationsIostream applicationsiostream_e;
	applicationsiostream_e.optionsVersusOmitted2(694.15,950.9,'d',637);

	Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}
emptyOrientedVice::~emptyOrientedVice()
{
	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}
emptyOrientedVice* emptyOrientedVice::getInstance(){
	if(m_encapsulatesIndicating == nullptr){
		m_encapsulatesIndicating = new emptyOrientedVice();
		m_encapsulatesIndicating->init();
	}
	return m_encapsulatesIndicating;
}
void emptyOrientedVice::init(){
	for(int i=1;i<=m_functiocontrolNeedingHair;i++){
		explainsOrdinary* ret = explainsOrdinary::create(nullptr,"",m_downUrl);
		m_operatesSufficiently.push_back(ret);
	}
}
void emptyOrientedVice::setmanipulateTogether(std::string url){
	m_downUrl = url;
}
void emptyOrientedVice::addJob(std::string m_ableCover,std::function<void(void)> cb){
	if(thusBehaviorSpecialize(m_ableCover)) return;
	advantagesPassingReject* job = new advantagesPassingReject(m_ableCover,cb);
	m_jobList.push(job);
	m_redeclareUsed.push_back(m_ableCover);
}
bool emptyOrientedVice::thusBehaviorSpecialize(std::string m_ableCover){
	for(std::vector<std::string>::iterator iter = m_redeclareUsed.begin();iter != m_redeclareUsed.end();iter++){
		std::string tmp = *iter;
		if(tmp == m_ableCover){
			return true;
		}
	}
	return false;
}
explainsOrdinary* emptyOrientedVice::getlinkageOffsetsEquals(independentPath state){
	std::vector<explainsOrdinary*>::iterator iter = m_operatesSufficiently.begin();
	for(iter;iter != m_operatesSufficiently.end();iter++){
		explainsOrdinary* tmp = *iter;
		if(tmp->getState() == state) return tmp;
	}
	return nullptr;
}
void emptyOrientedVice::update(float dt){
	if (0 == m_operatesSufficiently.size()) 
		return;
	if (0 == m_jobList.size()) 
		return;
	explainsOrdinary* download = getlinkageOffsetsEquals(IDLE);
	if(nullptr == download) return;
	advantagesPassingReject* job = m_jobList.front();
	download->init(CC_CALLBACK_0(emptyOrientedVice::lessUserContainer,this,job->m_controlsLets,job->m_cb),job->m_controlsLets,m_downUrl);
	download->start();
	m_jobList.pop();
}
void emptyOrientedVice::lessUserContainer(std::string m_ableCover,std::function<void(void)> cb){
	if(cb) cb();
	for(std::vector<std::string>::iterator iter = m_redeclareUsed.begin();iter != m_redeclareUsed.end();iter++){
		std::string tmp = *iter;
		if(tmp == m_ableCover){
			m_redeclareUsed.erase(iter);
			break;;
		}
	}
	if(correspondsWhtheVaries != 0){
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushString(m_ableCover.c_str());
			pStack->executeFunctionByHandler(correspondsWhtheVaries, 1);
			pStack->clean();
		}
	}
}
void emptyOrientedVice::literalIostreamSuspended(int handler)
{
	correspondsWhtheVaries = handler;
}
