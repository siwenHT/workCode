#ifndef YVSDKHELPER_H
#define YVSDKHELPER_H
typedef unsigned int uint;
#include <iostream>
#include "cocos2d.h"
class YVSdkHelper
{
public:
    static YVSdkHelper* getInstance();
    
    static void destroyInstance();
    YVSdkHelper();
    ~YVSdkHelper();
    
    
    
    void cpLogin(std::string nickname, std::string uid);
    
    
    
    
    void startRecord(std::string savePath, int speech = 0, std::string ext = "");
    
    
    void stopRecord();
    
    
    
    
    
    void playRecord(std::string url, std::string path, std::string ext = "");
    
    
    
    void stopPlay();
    
    
    
    
    
    void speechVoice(std::string path, std::string ext = "", bool isUpLoad = false);
    
    
    void setSpeechType(int inType, int outType);
    
    
    void upLoadFile(std::string path, std::string fileid = "");
    
    
    void downLoadFile(std::string url, std::string savePath, std::string fileid = "");
    
	void registerHandler(int handler);
	void doInitSDK(unsigned long _appId);
	void setRecordNum(int num);
	void threadLoginIn();
private:
    bool init();
    
    
private:
    cocos2d::Node* m_dispathMsgNode;
    void* m_imp;
	std::string roleName;
	std::string userID;
public:
	int m_handler;
	unsigned long m_appId;
};
#endif 