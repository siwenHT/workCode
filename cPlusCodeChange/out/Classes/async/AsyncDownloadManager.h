
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
	float inadvertentlyObtain(double properly); 
	char foundDesigningLarge(char stops,float kids,long prefi,int memberwise); 
	std::string assigningTransactio(double error,unsigned short seemingly,unsigned short such,double revisited); 
static	void olderVaryingOnbits(int brace,long what); 
	void studentElsewhereStrcmp(bool transactio,unsigned short inform,long parametersunlike); 
	void * machineCmatchPublicly(bool sale,short spelling,int shared); 
	std::string operatorsTellCurlies(float learned,std::string unique); 
	long restrictedTypeConverting(int before,void * assigns,void * whsuggest); 
	long disallowItasIntuitive(double importance,double reasons); 
private:
	char m_flagsPreferThdefines;
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
