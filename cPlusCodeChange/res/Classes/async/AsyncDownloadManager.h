/**
    程序开始到AssetManager开始下载文件，如果没有HTTP请求动作
	那么AssetManager第一次下载文件，会被视为网络问题，无法下载
	具体原因待考证
**/
#ifndef _ASYNC_DOWNLOAD_MANAGER_H_
#define _ASYNC_DOWNLOAD_MANAGER_H_

#include "cocos2d.h"
#include "extensions/cocos-ext.h"


typedef enum {
	IDLE = 0,								//空闲
	WORKING = 1,							//工作
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
	int m_managerInitNum;								//管理器初始列表大小
	std::vector<AsyncDownload*> m_managerList;			//管理器列表
	std::queue<AsyncJob*> m_jobList;					//下载任务管理器
	std::vector<std::string> m_pszFileNameList;			//在JOB队列或者正在下载的纹理路径列表
	std::string m_downUrl;								//下载路径

	int m_downsuc_cb;									//下载成功回调
};
#endif//_ASYNC_SPRITE_H_
