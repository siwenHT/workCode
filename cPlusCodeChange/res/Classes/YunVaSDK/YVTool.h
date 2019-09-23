#ifndef YunVaSDKUtils_h__
#define YunVaSDKUtils_h__

/************************************************************************/
/* 云娃语音接入单元                                                     */
/************************************************************************/
#include <map>
#include <vector>
#include "YVTypeDef.h"
#include "CYVSyncQueue.h"
#include "yvListern.h"
namespace YVSDK
{
	//消息回调结构
	struct YAYACallBackObj;

	typedef std::vector<YAYACallBackObj*> YaYaMsgCallFuncList;
	typedef std::map<int, YaYaMsgCallFuncList> YaYaMsgMap;

	class YVTool
	{
	public:
		virtual ~YVTool(void);
		static YVTool* getInstance();

		/*初始化SDK*/
		//appId:由云娃分配，需要向商务申请；tempPath:语音保存路径；isDebug：true为测试环境，false为正式环境；
		//oversea:false为国内服务器版本，true为海外服务器版本。
		void initSDK(unsigned long appId, std::string tempPath, bool isDebug = true, bool oversea=false);

		/*CP登录*/
		void cpLogin(std::string nickname = "1" , std::string uid = "1" );

		/*注销登录*/
		void cpLogout();

		/*获取用户资料 */
		void getCPUserInfo(uint32 appid, std::string uid);

		/*注册相关处理函数*/
		void registerMsgCallBack();
		void unRegisterMsgCallBack();

		/*释放SDK*/
		void releaseSDK();

		/*设置录音,第一个参数为录音的时长单位为秒,默认是60秒
		第二个参数为是否获取录音时回调；注意这个接口只有登录成功后才能生效
		*/
		void setRecord(unsigned int timeNum, bool isGetVolume);

//        注意该接口:
//        speech=0 为普通录音，当调用停止录音接口时，会收到停止录音回调，返回 amr 格式 录音文件。
//        speech=1 为边录边上传加识别，当调用停止录音接口时，会收到停止录音回调和上传录 音返回回调以及语音识别的回调。(如果没有用到语音识别功能不建议传此参数，影响效率)。 停止录音回调接口返回 amr           录音文件，上传录音回调接口返回 amr 文件 url，识别回调接口 返回录音转文字结果。
//        speech=2 为边录边上传，当调用停止录音接口时，会收到停止录音回调和上传录音返回 回调。停止录音回调接口返回 amr 录音文件，上传录音回调接口返回 amr 文件 url。
//        speech=10 为普通录音，当调用停止录音接口时，会收到停止录音回调，返回 mp3 格式 录音文件。
//        speech=11 为边录边上传加识别，当调用停止录音接口时，会收到停止录音回调和上传 录音返回回调以及语音识别的回调。(如果没有用到语音识别功能不建议传此参数，影响效 率)。停止录音回调接口返回 mp3 录音文件，上传录音回调接口返回 mp3 文件 url，识别回 调接口返回录音转文字结果。
//        speech=12 为边录边上传，当调用停止录音接口时，会收到停止录音回调和上传录音返 回回调。停止录音回调接口返回 mp3 录音文件，上传录音回调接口返回 mp3 文件 url。
//        警示:如果是 2019 年 3 月之前的老用户，请不要使用【10，11，12】三个参数，因为 该参数返回的是 mp3 格式，不能与之前的接入的老版本互通兼容。
		//注意第一个参数不仅仅是语音的所在的路径，也包含语音文件名，后缀名注意不要改，注意要有录音设备而且是好的
		bool startRecord(std::string savePath, uint8 speech = 0, std::string ext = "");

		/*结束录音*/
		bool stopRecord();

		/*播放录音*/  
		bool playRecord(std::string Url, std::string path, std::string ext="");
        
        /*请求流量*/  
        void getflow();

		/*播放在线录音,注意云播放有二个回调，
		一个是DownloadVoice(用于做UI上的显示，如菊花) 
		一个是播放结束的回调*/
		bool playFromUrl(std::string Url, std::string ext = "");

		/*结束播放*/
		void stopPlay();

		/*设置语音识别类型*/
		void setSpeechType(yvimspeech_language inType, yvimspeech_outlanguage outType);

		/*请求上传文件*/
		bool upLoadFile(std::string path, std::string fileid = "");

		/*请求下载文件*/
		bool downLoadFile(std::string url, std::string savePath, std::string fileid = "");


		/*注册消息处理回调*/
		template<typename T>
		void registerMsg(int cmdid, T* obj, void (T::*func)(YaYaRespondBase*));

		//请在定时器运行
		void dispatchMsg(float t);

		/*反注册*/
		template<typename T>
		void unRegisterMsg(int cmdid, T* obj);

		inline bool isInitSDK(){ return _isSDKInit; };
	protected:
		YVTool(void);

		InitListern(Login, CPLoginResponce);
		InitListern(ReConnect, ReconnectionNotify);
		InitListern(StopRecord, RecordStopNotify);
		InitListern(FinishSpeech, SpeechStopRespond);
		InitListern(FinishPlay, StartPlayVoiceRespond);
		InitListern(UpLoadFile, UpLoadFileRespond);
		InitListern(DownLoadFile, DownLoadFileRespond);
		InitListern(NetWorkSate, NetWorkStateNotify); 
		InitListern(RecordVoice, RecordVoiceNotify);
		InitListern(CPUserInfo, GetCPUserInfoRespond);
		InitListern(DownloadVoice, DownloadVoiceRespond);
        InitListern(Flow, YunvaflowRespond);
	private:
		static YVTool* _shareHandler;
		bool _isSDKInit;  //SDK是否初始化完成
		bool _isLoginSuccess; //CP登录是否成功
		bool _isRecording; //正在录音
		bool _isPlaying;  //是否正在播放
		bool _isUsedSchedule;
		bool _lockInit;
		CYVLock m_recordLock;
		CYVLock m_playLock;

		static YaYaMsgMap* _msgCallBackMap;

	private:
		bool sendRequeset(YaYaRequestBase* request);

		/*相关消息返回*/
		void cpLoginRespond(YaYaRespondBase* respond);

		/*重连成功通知*/
		void reconnectionNotify(YaYaRespondBase* respond);

		/*停止录音返回*/
		void stopRecordRespond(YaYaRespondBase* respond);

		/*播放录音完成返回*/
		void finishPlayRespond(YaYaRespondBase* respond);

		/*语音识别完成返回*/
		void finishSpeechRespond(YaYaRespondBase* respond);

		/*上传文件请求返回*/
		void upLoadFileRespond(YaYaRespondBase* respond);

		/*下载文件请求返回*/
		void downLoadFileRespond(YaYaRespondBase* respond);

		/*网络状态通知*/
		void netWorkStateRespond(YaYaRespondBase* respond);

		/*录音音量通知*/
		void recordVoiceRespond(YaYaRespondBase* respond);

		/*用户信息*/
		void cpUserInfoRespond(YaYaRespondBase* respond);

		//云播放及云识别文件下载
		void downloadVoiceRespond(YaYaRespondBase* respond);
        
        //请求流量返回
        void getflowRespond(YaYaRespondBase* respond);
	};
}
#endif // YunVaSDKUtils_h__

