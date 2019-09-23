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
    //登陆
    //@nickname 用户名称(由 CP 自己提供)
    //@uid 用户 ID,(由 CP 自己提供,请确保唯 一性)
    void cpLogin(std::string nickname, std::string uid);
    
    //开始录音请求
    //@savePath 带绝对路径的文件名(例:xx/test.amr)
    //@ext 希望传递给结束录音事件回调的值(有 点像 cocos2dx 中的 setUserData)
    void startRecord(std::string savePath, int speech = 0, std::string ext = "");
    
    //停止录音请求
    void stopRecord();
    
    //播放录音请求
    //@url 存放语音文件的(http)URL 地址
    //@path 带绝对路径的文件名(例:xx/test.amr)
    //@ext 希望传递给结束播放事件回调的值(有 点像 cocos2dx 中的 setUserData)
    void playRecord(std::string url, std::string path, std::string ext = "");
    
    
    //停止播放录音请求
    void stopPlay();
    
    //语音识别请求
    //@path 带绝对路径的文件名(例:xx/test.amr)
    //@ext 希望传递给识别结束事件回调的值(有 点像 cocos2dx 中的 setUserData)
    //@isUpLoad 是否识别后上传,会在识别完成后生成 一个远程的 url 地址
    void speechVoice(std::string path, std::string ext = "", bool isUpLoad = false);
    
    /*
     * 设置语音识别语言类型请求(非必需
     * @inType 识别语音类型(默认普通话) im_speech_zn = 1,im_speech_ct = 2,im_speech_en = 3,
     * @outType 输出语音的文本类型 im_speechout_simplified = 0, im_speechout_traditional = 1
     *
     */
    void setSpeechType(int inType, int outType);
    
    /*
     * 上传文件请求
     * @path 带绝对路径的文件名(例:xx/test.amr)
     * @fileid 希望传递给上传结束事件回调的值(有 点像 cocos2dx 中的 setTag)
     */
    void upLoadFile(std::string path, std::string fileid = "");
    
    /*
     * 下载文件请求
     * @url 所下载的文件所在的 URL 地址
     * @savePath 保存路径,带绝对路径的文件名(例:xx/test.amr)
     * @fileid 希望传递给下载结束事件回调的值(有 点像 cocos2dx 中的 setTag)
     */
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

#endif /* YVSDKHELPER_H */