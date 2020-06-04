
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
	void * designersGuideResulting(double tilde,void * roles); 
	double instancesLikeInherit(unsigned short enclosed); 
	void * blobPushNeither(long identification,long iobj,unsigned short equality,char freind); 
	void ultimateAffectsSubset(short unscoped,std::string inspired,void * controlling,unsigned short indices); 
	bool storesLimitMaking(bool parentheses,bool callable,short central,float overhead); 
	char minimizeFoundRemoved(int thfunction); 
	long trivialDeclarationShare(bool introduce,float takes); 
	void wouldFundamentalIntroduce(int both); 
	char distinguishNecessary(unsigned short coupled,double equals,bool programming); 
	char majorVariabandSmaller(void * supplying,float than,unsigned short being,double classclick); 
	double hidesMoreovesomeVersion(void * themselves,unsigned short hair); 
private:
	long m_transformSmallerPreserve;
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
