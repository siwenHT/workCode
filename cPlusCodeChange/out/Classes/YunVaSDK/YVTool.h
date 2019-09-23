#ifndef YunVaSDKUtils_h__
#define YunVaSDKUtils_h__
#include <map>
#include <vector>
#include "YVTypeDef.h"
#include "CYVSyncQueue.h"
#include "yvListern.h"
namespace YVSDK
{
	struct YAYACallBackObj;
	typedef std::vector<YAYACallBackObj*> YaYaMsgCallFuncList;
	typedef std::map<int, YaYaMsgCallFuncList> YaYaMsgMap;
	class YVTool
	{
	public:
		virtual ~YVTool(void);
		static YVTool* getInstance();
	
	
	
		void initSDK(unsigned long appId, std::string tempPath, bool isDebug = true, bool oversea=false);
	
		void cpLogin(std::string nickname = "1" , std::string uid = "1" );
	
		void cpLogout();
	
		void getCPUserInfo(uint32 appid, std::string uid);
	
		void registerMsgCallBack();
		void unRegisterMsgCallBack();
	
		void releaseSDK();
	
		void setRecord(unsigned int timeNum, bool isGetVolume);
	
		bool startRecord(std::string savePath, uint8 speech = 0, std::string ext = "");
	
		bool stopRecord();
		  
		bool playRecord(std::string Url, std::string path, std::string ext="");
        
          
        void getflow();
	
		bool playFromUrl(std::string Url, std::string ext = "");
	
		void stopPlay();
	
		void setSpeechType(yvimspeech_language inType, yvimspeech_outlanguage outType);
	
		bool upLoadFile(std::string path, std::string fileid = "");
	
		bool downLoadFile(std::string url, std::string savePath, std::string fileid = "");
	
		template<typename T>
		void registerMsg(int cmdid, T* obj, void (T::*func)(YaYaRespondBase*));
	
		void dispatchMsg(float t);
	
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
		bool _isSDKInit;  
		bool _isLoginSuccess; 
		bool _isRecording; 
		bool _isPlaying;  
		bool _isUsedSchedule;
		bool _lockInit;
		CYVLock m_recordLock;
		CYVLock m_playLock;
		static YaYaMsgMap* _msgCallBackMap;
	private:
		bool sendRequeset(YaYaRequestBase* request);
	
		void cpLoginRespond(YaYaRespondBase* respond);
	
		void reconnectionNotify(YaYaRespondBase* respond);
	
		void stopRecordRespond(YaYaRespondBase* respond);
	
		void finishPlayRespond(YaYaRespondBase* respond);
	
		void finishSpeechRespond(YaYaRespondBase* respond);
	
		void upLoadFileRespond(YaYaRespondBase* respond);
	
		void downLoadFileRespond(YaYaRespondBase* respond);
	
		void netWorkStateRespond(YaYaRespondBase* respond);
	
		void recordVoiceRespond(YaYaRespondBase* respond);
	
		void cpUserInfoRespond(YaYaRespondBase* respond);
	
		void downloadVoiceRespond(YaYaRespondBase* respond);
        
        
        void getflowRespond(YaYaRespondBase* respond);
	};
}
#endif 
