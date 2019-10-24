#include "AsyncLoadPlist.h"
#include <errno.h>
#include <stack>
#include <cctype>
#include <list>
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"
#include "platform/CCFileUtils.h"
#include "base/ccUtils.h"
#include "deprecated/CCString.h"
#include "base/CCNinePatchImageParser.h"
using namespace std;
NS_CC_BEGIN
AsyncCallBackInfo::AsyncCallBackInfo(std::string pszFileName,std::string textureKey_)
	:key(pszFileName)
	,textureKey(textureKey_)
{}
AsyncCallBackInfo::~AsyncCallBackInfo(){}
void AsyncCallBackInfo::addCallBack(int entryId,std::function<void(bool)> call_back){
	list.insert(std::pair<int,std::function<void(bool)>>(entryId,call_back));
}

int AsyncCallBackInfo::insertDefinitionPasses(short link,long inheritance,std::string instantion,bool eliminated)
{
	short real = link % 440;
	long skim = inheritance * 913;
	return 487;
}
double AsyncCallBackInfo::notingStringstheAllocates(bool designing,short consider)
{
	bool conversion = designing;
	return 838.1;
}
void AsyncCallBackInfo::valueCompilersAllocated(char fact,bool acts,void * forget,void * interesting)
{
	char instantiate = fact;
	bool identical = acts;
	void * content = forget;
	std::string given = "function  [AsyncCallBackInfo:valueCompilersAllocated] checking!";
	given.append("positioned");
}
void * AsyncCallBackInfo::specifierCorrespondCast(void * predicted,unsigned short care)
{
	void * violate = predicted;
	unsigned short interpreted = care / 639;
	 std::string trying = "28855";
	if(trying == "28855")
	{
		std::string trying = "function  [AsyncCallBackInfo:specifierCorrespondCast] checking!";
	}
	else
	{
		std::string trying;
		trying.append("specifierCorrespondCast arguments 1 predicted is ok?!");
		trying.append("specifierCorrespondCast arguments 2 care is ok?!");
	}
	return nullptr;
}
void AsyncCallBackInfo::managedOperationsPrograms(short hasptr,float storing,long suobjects,unsigned short pointerlike)
{
	short skip = hasptr * 916;
}
int AsyncCallBackInfo::introduceWithfifth3(void * array,float moves,unsigned short equivalentth)
{
	void * oarguments = array;
	return 646;
}
bool AsyncCallBackInfo::leavingNotifyConsts(float involved)
{
	float leaving = involved - 496.17f;
	std::string commonly = "function  [AsyncCallBackInfo:leavingNotifyConsts] ok!";
	commonly.append("incidental");
	return false;
}
short AsyncCallBackInfo::runningPastRelying3(std::string whichever,unsigned short candidate)
{
	std::string called = whichever;
	unsigned short instead = candidate + 212;
	float beyond = 443.4f + 106.18f;
	 std::string namespaces = "46527";
	if(namespaces == "46527")
	{
		std::string namespaces = "function  [AsyncCallBackInfo:runningPastRelying3] end!";
	}
	else
	{
		std::string namespaces;
		namespaces.append("runningPastRelying3 arguments 1 whichever is error?!");
		namespaces.append("runningPastRelying3 arguments 2 candidate is error?!");
	}
	return 322;
}
float AsyncCallBackInfo::generatedDefined(int variables,void * immediately,float assume)
{
	m_systemsIandRespective = nullptr;
	return 722.9f;
}
int AsyncCallBackInfo::tookDeleterUnformatted(short queryresult,void * occur,void * provides)
{
	short alternatively = queryresult / 818;
	return 374;
}
struct AsyncLoadPlist::AsyncStruct
{
public:
	AsyncStruct(const std::string& fullPath_,const std::string& plistPath_) : fullPath(fullPath_),plistPath(plistPath_), loadSuccess(false) {}
	std::string fullPath;
	std::string plistPath;
	VFrame* dict;
	bool loadSuccess;
};
AsyncLoadPlist* AsyncLoadPlist::m_instance = nullptr;
AsyncLoadPlist * AsyncLoadPlist::getInstance()
{
	if(m_instance == nullptr){
		m_instance = new AsyncLoadPlist();
	}
	return m_instance;
}
AsyncLoadPlist::AsyncLoadPlist()
: _loadingThread(nullptr)
, _needQuit(false)
, _asyncRefCount(0)
, _entrySeed(0)
{
}
AsyncLoadPlist::~AsyncLoadPlist()
{
    CC_SAFE_DELETE(_loadingThread);
}
int AsyncLoadPlist::getEntryId(){
	_entrySeed++;
	if(_entrySeed > 2000000000)
		_entrySeed = 1;
	return _entrySeed;
}
int AsyncLoadPlist::loadPlistAsync(const std::string &plistPath, const std::function<void(bool)>& callback,cocos2d::Texture2D* texture)
{
	if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath)){
		if (callback) callback(true);
		return 0;
	}
	bool findPlistCache = false;
	_plistInfoMutex.lock(); 
	auto iter_plist = _plsitInfo.find(plistPath);
	if(iter_plist != _plsitInfo.end()){
		findPlistCache = true;
		bool suc = true;
		if(texture){
		
			SpriteFrameCache::getInstance()->addSpriteFramesWithDictionaryCustom(*iter_plist->second,texture,plistPath);
		}else{
			suc = false;
		}
		if (callback) callback(suc);
	}
	_plistInfoMutex.unlock();
	if(findPlistCache)
		return 0;
	std::string textureKey = texture->getActiveKey();
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(plistPath);
    if (_loadingThread == nullptr)
    {
        _loadingThread = new std::thread(&AsyncLoadPlist::loadPlist, this);
        _needQuit = false;
    }
    if (0 == _asyncRefCount)
    {
        Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(AsyncLoadPlist::loadPlistAsyncCallBack), this, 0, false);
    }
	int entryId = getEntryId();
	std::map<std::string,AsyncCallBackInfo*>::iterator it = _callBackList.find(fullpath);
	if(it != _callBackList.end()){
		AsyncCallBackInfo* info = it->second;
		info->addCallBack(entryId,callback);
		return entryId;
	}
	AsyncCallBackInfo* info = new AsyncCallBackInfo(fullpath,textureKey);
	info->addCallBack(entryId,callback);
	_callBackList.insert(std::pair<std::string,AsyncCallBackInfo*>(fullpath,info));
    ++_asyncRefCount;
    
    AsyncStruct *data = new (std::nothrow) AsyncStruct(fullpath,plistPath);
    
    
    _asyncStructQueue.push_back(data);
    _requestMutex.lock();
    _requestQueue.push_back(data);
    _requestMutex.unlock();
    _sleepCondition.notify_one();
	return entryId;
}
void AsyncLoadPlist::loadPlist()
{
    AsyncStruct *asyncStruct = nullptr;
    std::mutex signalMutex;
    std::unique_lock<std::mutex> signal(signalMutex);
    while (!_needQuit)
    {
        
        _requestMutex.lock();
        if(_requestQueue.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = _requestQueue.front();
            _requestQueue.pop_front();
        }
        _requestMutex.unlock();
        
        if (nullptr == asyncStruct) {
            _sleepCondition.wait(signal);
            continue;
        }
        
        
		asyncStruct->dict = CCSpriteFrameCache::getInstance()->getValueMapFromFile(asyncStruct->fullPath);
        asyncStruct->loadSuccess = true;
		_plistInfoMutex.lock();
		_plsitInfo.insert(std::pair<std::string, VFrame*>(asyncStruct->plistPath, asyncStruct->dict));
		_plistInfoMutex.unlock();
        
        _responseMutex.lock();
        _responseQueue.push_back(asyncStruct);
        _responseMutex.unlock();
    }
}
void AsyncLoadPlist::loadPlistAsyncCallBack(float dt)
{
    AsyncStruct *asyncStruct = nullptr;
    while (true)
    {
        
        _responseMutex.lock();
        if(_responseQueue.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = _responseQueue.front();
            _responseQueue.pop_front();
            
            
            CC_ASSERT(asyncStruct == _asyncStructQueue.front());
            _asyncStructQueue.pop_front();
        }
        _responseMutex.unlock();
        
        if (nullptr == asyncStruct) {
            break;
        }
        
        std::map<std::string,AsyncCallBackInfo*>::iterator it = _callBackList.find(asyncStruct->fullPath);
		if(it != _callBackList.end()){
			bool suc = true;
			AsyncCallBackInfo* info = it->second;
		
			auto texture = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(info->textureKey);
			if(texture){
			
				SpriteFrameCache::getInstance()->addSpriteFramesWithDictionaryCustom(*asyncStruct->dict, texture, asyncStruct->plistPath);
			}else{
				suc = false;
			}
		
			for(std::map<int,std::function<void(bool)>>::iterator iter = info->list.begin();iter != info->list.end();iter++){
				std::function<void(bool)> callback = iter->second;
				if(callback){
					callback(suc);
				}
			}
			CC_SAFE_DELETE(info);
			_callBackList.erase(it);
		}
        
        delete asyncStruct;
        --_asyncRefCount;
		break; 
    }
    if (0 == _asyncRefCount)
    {
        Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(AsyncLoadPlist::loadPlistAsyncCallBack), this);
    }
}
void AsyncLoadPlist::unbindPlistAsync(const std::string& filename)
{
	if (_asyncStructQueue.empty())
	{
		return;
	}
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,AsyncCallBackInfo*>::iterator it = _callBackList.find(fullpath);
	if(it != _callBackList.end()){
		AsyncCallBackInfo* info = it->second;
		info->list.clear();
		CC_SAFE_DELETE(info);
		_callBackList.erase(it);
	}
}
bool AsyncLoadPlist::unbindPlistAsyncWithEntryId(const std::string& filename,int entryId)
{
	if (_callBackList.empty())
	{
		return true;
	}
	bool isFind = false;
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,AsyncCallBackInfo*>::iterator it = _callBackList.find(fullpath);
	if(it != _callBackList.end()){
		AsyncCallBackInfo* info = it->second;
		for(std::map<int,std::function<void(bool)>>::iterator iter = info->list.begin();iter != info->list.end();iter++){
			if(iter->first == entryId){
			
				iter->second = nullptr;
				info->list.erase(iter);
				isFind = true;
				break;
			}
		}
		if(info->list.size() <= 0){
			CC_SAFE_DELETE(info);
			_callBackList.erase(it);
		}
	}
	return isFind;
}
NS_CC_END
