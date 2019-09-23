#include "YVSdkHelper.h"

#include "YVTool.h"
#include "YVIMCmdDef.h"

#include "CCLuaEngine.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include <stdlib.h>
#include <string.h>


std::string GBKToUTF8(const char *inbuf)
{
    return inbuf;
    
    if (strlen(inbuf) == 0) return inbuf;
    
    int len = MultiByteToWideChar(0, 0, inbuf, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(0, 0, inbuf, -1, wstr, len);
    len = WideCharToMultiByte(65001, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(65001, 0, wstr, -1, str, len, NULL, NULL);
    if (wstr) delete[] wstr;
    std::string stdstr;
    stdstr.append(str);
    delete[] str;
    return stdstr;
}
#endif

static YVSdkHelper* m_instance = nullptr;


using namespace YVSDK;
USING_NS_CC;
using namespace std;

enum class YVSdkMsgType
{
    //登陆返回  "result|uid|msg"，result=0，登陆成功，否则msg有错误信息
    LOGIN = 1,
    
    /*
     *停止录音"time|path|ext"
     *time录音时长(以毫秒计)
     *path 录音保存文件路径名
     *ext 录音请求时传递过来的
     */
    STOP_RECORD = 2,
    
    /*语音识别 "err_id|err_msg|result|ext|url"
     *err_id 识别结果,不为 0 即为失败
     *err_msg 错误描述
     *result 识别后的文本(注意目前 SDK 提供给 win32 的是 GBK 编码,其它平台都是 UTF8 编码)
     *ext 请求识别传入的 ext
     *url 如果识别时加了上传,则这个值就有了
     */
    SPEECH_FINISH = 3,
    
    /*上传返回 "result|msg|fileid|fileurl|percent"
     *result 上传结果,不为 0 即为失败
     *msg 错误描述
     *fileid 请求上传接口传的值
     *fileurl 返回 URL 地址
     *percent 完成百分比
     */
    UPLOAD_FINISH = 4,
    
    //录音音量变化 0~100
    RECORD_VOICE = 5,
    
    /*
     *播放录音完成事件
     *result 播放完成为 0,失败为 1
     *describe 错误描述
     *ext 调用播放请求时,传递进来的值
     */
    PLAY_RECORD_OVER = 6
};

/*********************事件派发************************/
class DispatchMsgNode : public cocos2d::Node
{
public:
	bool init()
	{
		isschedule = false;
		return  Node::init();
	}
	CREATE_FUNC(DispatchMsgNode);
	void startDispatch()
	{
		if (isschedule) return;
		isschedule = true;
		Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
	}
	void stopDispatch()
	{
		if (!isschedule) return;
		isschedule = false;
		Director::getInstance()->getScheduler()->unscheduleUpdate(this);
	}
	void update(float dt)
	{
		YVTool::getInstance()->dispatchMsg(dt);
	}
private:
	bool isschedule;

};
/****************************end*********************************/

/****************************end*********************************/

class YVSdkHelper_Imp : public cocos2d::Ref,
public  YVListern::YVUpLoadFileListern,
public  YVListern::YVFinishPlayListern,
public  YVListern::YVFinishSpeechListern,
public  YVListern::YVStopRecordListern,
public  YVListern::YVReConnectListern,
public  YVListern::YVLoginListern,
public YVListern::YVRecordVoiceListern
{
public:
    YVSdkHelper_Imp(YVSdkHelper* helper) : m_helper(helper){
        init();
    }
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init()
    {
        addListern();
        return true;
    }
    
    void reSetLablePos();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void addListern()
    {
        YVTool::getInstance()->addFinishPlayListern(this);
        YVTool::getInstance()->addFinishSpeechListern(this);
        YVTool::getInstance()->addLoginListern(this);
        YVTool::getInstance()->addReConnectListern(this);
        YVTool::getInstance()->addStopRecordListern(this);
        YVTool::getInstance()->addUpLoadFileListern(this);
        YVTool::getInstance()->addRecordVoiceListern(this);
     }
    //登陆返回
    virtual void onLoginListern(CPLoginResponce* r)
    {
        uint32_t uid = 0u;
        string msg = "";
        if (r->result != 0) {
            msg = r->msg;
        }else{
            uid = r->userid;
            //YVTool::getInstance()->setRecord(60, true);
        }
        snprintf(m_buff, 512, "%u|%u|%u|%s", static_cast<uint>(YVSdkMsgType::LOGIN), r->result, uid, msg.c_str());
        string result(m_buff);
        callbackToLua(move(result));
    }
    //连接成功
    virtual void onReConnectListern(ReconnectionNotify* r)
    {
        //r->userid;
    }
    
    virtual void onStopRecordListern(RecordStopNotify* r)
    {
        uint32 time  = r->time;
        snprintf(m_buff, 512, "%u|%u|%s|%s", static_cast<uint>(YVSdkMsgType::STOP_RECORD), time == 0u ? 1 : time, r->strfilepath.c_str(), r->ext.c_str());
        string result(m_buff);
        callbackToLua(move(result));
    }
    //语音识别，r->result 为识别文本 
    virtual void onFinishSpeechListern(SpeechStopRespond* r)
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
        r->result = GBKToUTF8(r->result.c_str());
#endif
        std::string err_msg = r->err_msg;
        if(err_msg.length()<=0)
            err_msg = " ";
		CCLOG("speech msg:%s", r->result.c_str());
        snprintf(m_buff, 512, "%u|%u|%s|%s|%s|%s", static_cast<uint>(YVSdkMsgType::SPEECH_FINISH), r->err_id, err_msg.c_str(), r->result.c_str(), r->ext.c_str(), r->url.c_str());
        string result(m_buff);
        callbackToLua(move(result));
    }
    
    virtual void onFinishPlayListern(StartPlayVoiceRespond* r)
    {
        std::string describe = r->describe;
        if(describe.length()<=0)
            describe = " ";
        snprintf(m_buff, 512, "%u|%u|%s|%s", static_cast<uint>(YVSdkMsgType::PLAY_RECORD_OVER), r->result, describe.c_str(), r->ext.c_str());
        string result(m_buff);
        callbackToLua(move(result));
    }
    //上传成功
    virtual void onUpLoadFileListern(UpLoadFileRespond* r)
    {
        snprintf(m_buff, 512, "%u|%u|%s|%s|%s|%u", static_cast<uint>(YVSdkMsgType::UPLOAD_FINISH), r->result, r->msg.c_str(), r->fileid.c_str(), r->fileurl.c_str(), r->percent);
        string result(m_buff);
        callbackToLua(move(result));
    }
    
    virtual void onRecordVoiceListern(RecordVoiceNotify* r)
    {
        snprintf(m_buff, 512, "%u|%u", static_cast<uint>(YVSdkMsgType::RECORD_VOICE), r->volume);
        string result(m_buff);
        callbackToLua(move(result));
    }
    
private:
    /*
     * 回调到lua
     */
    void callbackToLua(std::string&& str)
    {
		if(m_helper->m_handler != 0){
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->pushString(str.c_str());
				pStack->executeFunctionByHandler(m_helper->m_handler, 1);
				pStack->clean();
			}
		}
    }
private:
    std::string url;
    YVSdkHelper* m_helper;
    char m_buff[512];
};

/**************************imp end*********************************/
YVSdkHelper::YVSdkHelper()
	:m_dispathMsgNode(nullptr),
	m_imp(nullptr),
	m_appId(0),
	m_handler(0)
{
	roleName = "";
	userID = "";
}

YVSdkHelper::~YVSdkHelper()
{
	YVTool::getInstance()->cpLogout();
	if (m_dispathMsgNode != nullptr)
	{
		static_cast<DispatchMsgNode*>(m_dispathMsgNode)->stopDispatch();
		m_dispathMsgNode->release();
		m_dispathMsgNode = nullptr;
	}
	if (m_imp) {
		delete static_cast<YVSdkHelper_Imp*>(m_imp);
		m_imp = nullptr;
	}
}

YVSdkHelper* YVSdkHelper::getInstance()
{
    if (nullptr == m_instance) {
        m_instance = new (std::nothrow) YVSdkHelper();
        CCASSERT(m_instance, "FATAL: Not enough memory");
        m_instance->init();
        
    }
    return m_instance;
}

void YVSdkHelper::destroyInstance()
{
    if (m_instance) {
        delete m_instance;
        m_instance = nullptr;
    }
}

bool YVSdkHelper::init()
{
	if (m_dispathMsgNode == NULL)
	{
		DispatchMsgNode* node = DispatchMsgNode::create();
		node->retain();
		node->startDispatch();
		m_dispathMsgNode = node;
	}
    m_imp = new YVSdkHelper_Imp(this);
    return true;
}

void YVSdkHelper::doInitSDK(unsigned long _appId){
	if(_appId != 0){
		//1000538
		m_appId = _appId;
		YVTool::getInstance()->initSDK(m_appId, cocos2d::FileUtils::getInstance()->getWritablePath(), false);
	}else{
		CCLOG("AppId unset YVSDK ERROR!!!");
	}
}

void YVSdkHelper::setRecordNum(int num)
{
	YVTool::getInstance()->setRecord(num, true);
}

void YVSdkHelper::cpLogin(std::string nickname, std::string uid)
{
	roleName = nickname;
	userID = uid;
	std::thread * load_Thread2 = new std::thread(&YVSdkHelper::threadLoginIn , this);
	load_Thread2->detach();
}

void YVSdkHelper::threadLoginIn()
{
	CCLOG("cpLogin Name:%s|uid:%s",roleName.c_str(),userID.c_str());
	YVTool::getInstance()->cpLogin(roleName, userID);
}

void YVSdkHelper::startRecord(std::string savePath, int speech, std::string ext)
{
	YVTool::getInstance()->startRecord(savePath, speech, ext);
}

void YVSdkHelper::stopRecord()
{
    YVTool::getInstance()->stopRecord();
}

void YVSdkHelper::playRecord(std::string url, std::string path, std::string ext)
{
    YVTool::getInstance()->playRecord(url, path, ext);
}

void YVSdkHelper::stopPlay()
{
	YVTool::getInstance()->stopPlay();
}

void YVSdkHelper::speechVoice(std::string path, std::string ext, bool isUpLoad)
{
	//YVTool::getInstance()->speechVoice(path, ext, isUpLoad);
}

void YVSdkHelper::setSpeechType(int inType, int outType)
{
	//yvimspeech_language it = static_cast<yvimspeech_language>(inType);
	//yvimspeech_outlanguage ot = static_cast<yvimspeech_outlanguage>(outType);
	//YVTool::getInstance()->setSpeechType(it,  ot);
}

void YVSdkHelper::upLoadFile(std::string path, std::string fileid)
{
	YVTool::getInstance()->upLoadFile(path, fileid);
}

void YVSdkHelper::downLoadFile(std::string url, std::string savePath, std::string fileid)
{
	YVTool::getInstance()->downLoadFile(url, savePath, fileid);
}

void YVSdkHelper::registerHandler(int handler){
	m_handler = handler;
}



