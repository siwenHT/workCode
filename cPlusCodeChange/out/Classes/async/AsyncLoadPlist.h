
#ifndef _ASYNCLOAD_PLIST_H__
#define _ASYNCLOAD_PLIST_H__
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <string>
#include <unordered_map>
#include <functional>
#include "base/CCValue.h"
#include "cocos2d.h"
#include "base/CCRef.h"
NS_CC_BEGIN
class AsyncCallBackInfo
{
public: 
	AsyncCallBackInfo(std::string pszFileName,std::string textureKey_);
	virtual ~AsyncCallBackInfo();
	void addCallBack(int entryId,std::function<void(bool)>);
	std::string key;                
	std::map<int,std::function<void(bool)>> list;
	std::string textureKey;
public:
	int insertDefinitionPasses(short link,long inheritance,std::string instantion,bool eliminated); 
	double notingStringstheAllocates(bool designing,short consider); 
	void valueCompilersAllocated(char fact,bool acts,void * forget,void * interesting); 
	void * specifierCorrespondCast(void * predicted,unsigned short care); 
	void managedOperationsPrograms(short hasptr,float storing,long suobjects,unsigned short pointerlike); 
	int introduceWithfifth3(void * array,float moves,unsigned short equivalentth); 
	bool leavingNotifyConsts(float involved); 
	short runningPastRelying3(std::string whichever,unsigned short candidate); 
	float generatedDefined(int variables,void * immediately,float assume); 
	int tookDeleterUnformatted(short queryresult,void * occur,void * provides); 
private:
	int m_inefficientDecideSimplify;
	double m_featureTransformation;
	int m_applyDesignerOperands;
	void * m_systemsIandRespective;
	double m_unscopedDrivenUnnamed;
};
class AsyncLoadPlist : public Ref
{
public:
	static AsyncLoadPlist* getInstance();
public:
    AsyncLoadPlist();
    virtual ~AsyncLoadPlist();
	virtual int loadPlistAsync(const std::string &plistPath, const std::function<void(bool)>& callback,cocos2d::Texture2D* texture);
	virtual void unbindPlistAsync(const std::string &filename);
	virtual bool unbindPlistAsyncWithEntryId(const std::string& filename,int id);
private:
    void loadPlistAsyncCallBack(float dt);
	void loadPlist();
	int getEntryId();
public:
protected:
	static AsyncLoadPlist* m_instance;
    struct AsyncStruct;
    
    std::thread* _loadingThread;
    std::deque<AsyncStruct*> _asyncStructQueue;
    std::deque<AsyncStruct*> _requestQueue;
    std::deque<AsyncStruct*> _responseQueue;
	std::map<std::string,AsyncCallBackInfo*> _callBackList;
    std::mutex _requestMutex;
    std::mutex _responseMutex;
	std::mutex _plistInfoMutex;
    
    std::condition_variable _sleepCondition;
    bool _needQuit;
    int _asyncRefCount;
	int _entrySeed;
    std::unordered_map<std::string, VFrame*> _plsitInfo;
};
NS_CC_END
#endif 
