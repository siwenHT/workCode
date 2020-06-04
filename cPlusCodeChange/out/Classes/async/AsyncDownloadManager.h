
#ifndef _ASYNC_DOWNLOAD_MANAGER_H_
#define _ASYNC_DOWNLOAD_MANAGER_H_
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
typedef enum {
	IDLE = 0,							
	WORKING = 1,						
}AsyncDownloadState;
class AsyncDownload
{
public:
	AsyncDownload();
	virtual ~AsyncDownload(void);
	static AsyncDownload* create(std::function<void(void)> cb,std::string pszFileName,std::string downUrl);
	static std::string createDownloadDir(std::string path_ex = "");
	bool init(std::function<void(void)> cb,std::string packageUrl,std::string downUrl);
	AsyncDownloadState getState();
	void start();
private:
	AsyncDownloadState m_state;
	cocos2d::extension::AssetsManager* m_manager;
	cocos2d::extension::AssetsManager::ErrorCallback errorCallback;
	cocos2d::extension::AssetsManager::ProgressCallback progressCallback;
	cocos2d::extension::AssetsManager::SuccessCallback successCallback; 
	std::function<void(void)> m_callback;
	std::string m_pszFileName;
	std::string base_url;
	void _errorCallback(int errorCode);
	void _progressCallback(int percent);
	void _successCallback();
};
class AsyncJob
{
public:
	AsyncJob(std::string pszFileName,std::function<void(void)> cb);
	virtual ~AsyncJob();
	std::string m_pszFileName;
	std::function<void(void)> m_cb;
public:
static	double quizIgnoreParameteth(short variaband); 
	void * namingDoesSomewhat(double compound,double site); 
static	bool treatConstant(void * ctype); 
	std::string membersFlagsSubscript(unsigned short doesndiffer,double release,unsigned short memory); 
	long iostreamWithDivide(double icase,void * well,short absolute,int concept); 
	std::string sameLogicalComeWcould2(float argumepassed,bool worries,long action); 
private:
	bool m_handlingPathObjectsth;
	std::string m_specializingAliases4;
	void * m_illustrateThusWorth;
	int m_oughtForwardingAffected;
};
class AsyncDownloadManager : public cocos2d::Ref
{
public: 
	AsyncDownloadManager();
	virtual ~AsyncDownloadManager(void);
	static AsyncDownloadManager* getInstance();
	void init();
	void setDownloadUrl(std::string url);
	void addJob(std::string pszFileName,std::function<void(void)> cb);
	bool isDownloadingOrJob(std::string pszFileName);
	void update(float dt);
	void registerDownloadSucCb(int handler);
protected:
	AsyncDownload* getManagerByState(AsyncDownloadState state);
	static AsyncDownloadManager* m_instance;
	void downloadFinish(std::string pszFileName,std::function<void(void)> cb);
private:
	int m_managerInitNum;							
	std::vector<AsyncDownload*> m_managerList;		
	std::queue<AsyncJob*> m_jobList;				
	std::vector<std::string> m_pszFileNameList;		
	std::string m_downUrl;							
	int m_downsuc_cb;								
};
#endif
