#include "YVTool.h"
#include "YVRespondFactory.h"
namespace YVSDK
{
	struct YVMsgData
	{
		unsigned int cmdid;
		YaYaRespondBase* r;
	};
	struct YAYACallBackObj
	{
		virtual ~YAYACallBackObj(){}
		virtual long getObjAddr() = 0;
		virtual void call(YaYaRespondBase* request) = 0;
	};
	template<typename T>
	struct YAYACallBackSlot :
		public YAYACallBackObj
	{
		T* t;
		typedef void (T::*SEL_DataEvent)(YaYaRespondBase* request);
		SEL_DataEvent f;
		YAYACallBackSlot(T* obj, SEL_DataEvent func)
		{
			t = obj;
			f = func;
		}
		long getObjAddr()
		{
			return (*reinterpret_cast<long*>(t));
		}
		void call(YaYaRespondBase* request)
		{
			(t->*f)(request);
		}
	};
	static CYVSyncQueue<YVMsgData> s_msgQueue;
	YVTool* YVTool::_shareHandler = NULL;
	YaYaMsgMap* YVTool::_msgCallBackMap = NULL;
	static void _stdcall myYVCallBack(enum CmdChannel type, unsigned int cmdid, YV_PARSER parser, unsigned long context)
	{
		YVMsgData data;
		data.cmdid = cmdid;
		data.r = YVRespondFactory::getSingletonPtr()->getRepsond(cmdid);
		if (data.r == NULL)
		{
			printf("YVRespondFactory not find: 0x%x \n", cmdid);
			return;
		}
		data.r->decode(parser);
		s_msgQueue.AddElement(data);
	}
	YVTool::YVTool(void)
	{
		_isPlaying = false;
		_isSDKInit = false;
		_isUsedSchedule = false;
		_isLoginSuccess = false;
		_isRecording = false;
		_lockInit = false;
		_msgCallBackMap = new YaYaMsgMap();
	}
	YVTool::~YVTool(void)
	{
		if (_isSDKInit)
			releaseSDK();
		_isSDKInit = false;
	
		if (_msgCallBackMap)
		{
			for (YaYaMsgMap::iterator it = _msgCallBackMap->begin(); it != _msgCallBackMap->end(); ++it)
			{
				for (YaYaMsgCallFuncList::iterator its = it->second.begin(); its != it->second.end(); ++its)
				{
					delete *its;
				}
				it->second.clear();
			}
			_msgCallBackMap->clear();
			delete _msgCallBackMap;
			_msgCallBackMap = NULL;
		}
		if (_shareHandler)
		{
			delete _shareHandler;
			_shareHandler = NULL;
		}
	}
	YVTool* YVTool::getInstance()
	{
		if (_shareHandler == NULL)
		{
			_shareHandler = new YVTool();
		}
		return _shareHandler;
	}
	void YVTool::initSDK(unsigned long appId, std::string tempPath, bool isDebug, bool oversea)
	{
		if (_lockInit || _isSDKInit) return;
		_lockInit = true;
		auto ret = YVIM_Init(myYVCallBack, 0, appId, tempPath.c_str(), isDebug, oversea);
		_lockInit = false; 
		if (ret == 0)
		{
			_isSDKInit = true;
			printf("YVIM_Init: Success.\n");
			registerMsgCallBack();
		}
		else
		{
			_isSDKInit = false;
			printf("YVIM_Init: Fail.\n");
		}
	}
	bool YVTool::sendRequeset(YaYaRequestBase* request)
	{
		if (!_isSDKInit)
		{
			printf("YVSDK not Init.\n");
			return false;
		}
		auto ret = YVIM_SendCmd(request->m_requestChannel, request->m_requestCmd, request->encode());
		if (ret == 0)
		{
			printf("YVIM_SendCmd: 0x%x Success.\n", request->m_requestCmd);
			return true;
		}
		else
		{
			printf("YVIM_SendCmd: 0x%xFail.\n", request->m_requestCmd);
			return false;
		}
	}
	void YVTool::cpLogin(std::string nickname, std::string uid)
	{
		CPLoginRequest r;
		r.tt.append("{\"nickname\":\"");
		r.tt.append(nickname);
		r.tt.append("\",\"uid\":\"");
		r.tt.append(uid);
		r.tt.append("\"}");
		sendRequeset(&r);
	}
	void YVTool::cpLogout()
	{
		printf("request cp logout.\n");
		CPLogoutRequest r;
		sendRequeset(&r);
	}
	void YVTool::releaseSDK()
	{
		unRegisterMsgCallBack();
		YVIM_Release();
	}
	void YVTool::registerMsgCallBack()
	{
	
		registerMsg(IM_THIRD_LOGIN_RESP, this, &YVTool::cpLoginRespond);
		registerMsg(IM_RECONNECTION_NOTIFY, this, &YVTool::reconnectionNotify);
		registerMsg(IM_RECORD_STOP_RESP, this, &YVTool::stopRecordRespond);
		registerMsg(IM_RECORD_FINISHPLAY_RESP, this, &YVTool::finishPlayRespond);
		registerMsg(IM_SPEECH_STOP_RESP, this, &YVTool::finishSpeechRespond);
		registerMsg(IM_UPLOAD_FILE_RESP, this, &YVTool::upLoadFileRespond);
		registerMsg(IM_DOWNLOAD_FILE_RESP, this, &YVTool::downLoadFileRespond);
		registerMsg(IM_NET_STATE_NOTIFY, this, &YVTool::netWorkStateRespond);
		registerMsg(IM_RECORD_VOLUME_NOTIFY, this, &YVTool::recordVoiceRespond);
		registerMsg(IM_GET_THIRDBINDINFO_RESP, this, &YVTool::cpUserInfoRespond);
		registerMsg(IM_RECORD_PLAY_PERCENT_NOTIFY, this, &YVTool::downloadVoiceRespond);
        registerMsg(IM_TOOL_FLOW_RESP, this, &YVTool::getflowRespond);
	}
	void YVTool::unRegisterMsgCallBack()
	{
		unRegisterMsg(IM_THIRD_LOGIN_RESP, this);
		unRegisterMsg(IM_RECONNECTION_NOTIFY, this);
		unRegisterMsg(IM_RECORD_STOP_RESP, this);
		unRegisterMsg(IM_RECORD_FINISHPLAY_RESP, this);
		unRegisterMsg(IM_SPEECH_STOP_RESP, this);
		unRegisterMsg(IM_UPLOAD_FILE_RESP, this);
		unRegisterMsg(IM_DOWNLOAD_FILE_RESP, this);
		unRegisterMsg(IM_NET_STATE_NOTIFY, this);
		unRegisterMsg(IM_RECORD_VOLUME_NOTIFY, this);
		unRegisterMsg(IM_GET_THIRDBINDINFO_RESP, this);
		unRegisterMsg(IM_RECORD_PLAY_PERCENT_NOTIFY, this);
        unRegisterMsg(IM_TOOL_FLOW_RESP, this);
	}
	void YVTool::getCPUserInfo(uint32 appid, std::string uid)
	{
		GetCPUserInfoRequest q;
		q.appid = appid;
		q.uid.append(uid);
		sendRequeset(&q);
	}
	void YVTool::setRecord(unsigned int timeNum, bool isGetVolume)
	{
		SetRecordRequest q;
		q.times = timeNum;
		q.volume = isGetVolume ? 1 : 0;
		sendRequeset(&q);
	}
	bool YVTool::startRecord(std::string savePath, uint8 speech, std::string ext)
	{
		CYVAutoLock lock(m_recordLock);
		if (_isRecording)
		{
			printf("isRecording\n");
			return false;
		}
		
		_isRecording = true;
		StartRecordRequest q;
		q.strFilePath.append(savePath);
		q.ext.append(ext);
		q.speech = speech;
		if (sendRequeset(&q) == false)
		{
			_isRecording = false;
		}
		return _isRecording;
	}
	bool YVTool::stopRecord()
	{
		CYVAutoLock lock(m_recordLock);
		StopRecordRequest q;
        if(sendRequeset(&q) == false){
            _isRecording = false;
            _isPlaying = false;
            return false;
        }
        return true;
	}
	bool YVTool::playRecord(std::string Url, std::string path, std::string ext)
	{
		CYVAutoLock lock(m_playLock);
		if (_isPlaying)
		{
			printf("isPlaying\n");
			return false;
		}
		
		_isPlaying = true;
		StartPlayVoiceRequest q;
		q.strUrl.append(Url);
		q.strfilepath.append(path);
		q.ext.append(ext);
		if(sendRequeset(&q) == false)
		_isPlaying = false;
		return _isPlaying;
	}
	bool YVTool::playFromUrl(std::string url, std::string ext)
	{
		CYVAutoLock lock(m_playLock);
		if (_isPlaying) return true;
		StartPlayVoiceRequest q;
		q.strUrl.append(url);
		q.ext.append(ext);
		if(sendRequeset(&q))
		_isPlaying = true;
        return true;
	}
	void YVTool::stopPlay()
	{
		CYVAutoLock lock(m_playLock);
		if (!_isPlaying) return;
		StopPlayVoiceRequest q;
		sendRequeset(&q);
	}
    
    
    void YVTool::setSpeechType(yvimspeech_language inType, yvimspeech_outlanguage outType)
	{
		SpeechSetRequest q;
		q.inLanguage = (yvimspeech_language)inType;
		q.outLanguage = outType;
		sendRequeset(&q);
	}
	bool YVTool::upLoadFile(std::string path, std::string fileid)
	{
		UpLoadFileRequest q;
		q.filename.append(path);
		q.fileid.append(fileid);
		return  sendRequeset(&q);
        
	}
	bool YVTool::downLoadFile(std::string url, std::string savePath, std::string fileid)
	{
		DownLoadFileRequest q;
		q.url.append(url);
		q.filename.append(savePath);
		q.fileid.append(fileid);
		return  sendRequeset(&q);
	}
	template<typename T>
	void YVTool::registerMsg(int cmdid, T* obj, void (T::*func)(YaYaRespondBase*))
	{
		YAYACallBackSlot<T>* callObj = new YAYACallBackSlot<T>(obj, func);
		YaYaMsgMap::iterator it = _msgCallBackMap->find(cmdid);
		if (it != _msgCallBackMap->end())
		{
			it->second.push_back(callObj);
		}
		else
		{
			YaYaMsgCallFuncList callFuncList;
			callFuncList.push_back(callObj);
			_msgCallBackMap->insert(make_pair(cmdid, callFuncList));
		}
	}
	template<typename T>
	void YVTool::unRegisterMsg(int cmdid, T* obj)
	{
		YaYaMsgMap::iterator it = _msgCallBackMap->find(cmdid);
		if (it == _msgCallBackMap->end())
		{
			return;
		}
		YaYaMsgCallFuncList& funcList = it->second;
		long objAddr = *reinterpret_cast<long *>(obj);
		for (YaYaMsgCallFuncList::iterator its = funcList.begin();
			its != funcList.end(); ++its)
		{
			if ((*its)->getObjAddr() == objAddr)
			{
				delete *its;
				funcList.erase(its);
				break;
			}
		}
		if (funcList.size() == 0)
		{
			_msgCallBackMap->erase(it);
		}
	}
	void YVTool::dispatchMsg(float t)
	{
		static YVMsgData msgData;
		if (!s_msgQueue.PopElement(msgData))
		{
			return;
		}
		unsigned int cmdid = msgData.cmdid;
		YaYaMsgMap::iterator it = _msgCallBackMap->find(cmdid);
		if (it != _msgCallBackMap->end())
		{
			YaYaMsgCallFuncList& funcList = it->second;
			for (YaYaMsgCallFuncList::iterator its = funcList.begin();
				its != funcList.end(); ++its)
			{
				(*its)->call(msgData.r);
			}
		}
		else
		{
			printf("CallBackFunc not find: 0x%x \n", cmdid);
		}
		msgData.r->release();
	}
    
    void YVTool::getflow()
    {
        YunvaflowRequest q;
        sendRequeset(&q);
    }
    void YVTool::getflowRespond(YaYaRespondBase* respond)
    {
        YunvaflowRespond* r = static_cast<YunvaflowRespond*>(respond);
        
        callFlowListern(r);
        printf("YunVa Yunvaflow upflow：%d\n", r->upflow);
        printf("YunVa Yunvaflow downflow：%d\n", r->downflow);
        printf("YunVa Yunvaflow allflow：%d\n", r->allflow);
    }
    
	void YVTool::cpLoginRespond(YaYaRespondBase* respond)
	{
		CPLoginResponce* r = static_cast<CPLoginResponce*>(respond);
		callLoginListern(r);
		if (r->result == 0)
		{
			printf("YunVa CP Login Success.\n");
			YVTool::getInstance()->setSpeechType(im_speech_zn, im_speechout_simplified);
		}
		else
		{
			printf("YunVa CP Login Failed：%s\n", r->msg.c_str());
		}
		_isLoginSuccess = r->result == 0;
	}
	void YVTool::reconnectionNotify(YaYaRespondBase* respond)
	{
		ReconnectionNotify* r = static_cast<ReconnectionNotify*>(respond);
		callReConnectListern(r);
	}
	void YVTool::stopRecordRespond(YaYaRespondBase* respond)
	{
		_isRecording = false;
		RecordStopNotify* r = static_cast<RecordStopNotify*>(respond);
		callStopRecordListern(r);
	}
	void YVTool::finishPlayRespond(YaYaRespondBase* respond)
	{
		StartPlayVoiceRespond* r = static_cast<StartPlayVoiceRespond*>(respond);
		_isPlaying = false;
		callFinishPlayListern(r);
	}
	void YVTool::finishSpeechRespond(YaYaRespondBase* respond)
	{
		SpeechStopRespond* r = static_cast<SpeechStopRespond*>(respond);
		callFinishSpeechListern(r);
	}
	void YVTool::upLoadFileRespond(YaYaRespondBase* respond)
	{
		UpLoadFileRespond* r = static_cast<UpLoadFileRespond*>(respond);
		callUpLoadFileListern(r);
	}
	void YVTool::downLoadFileRespond(YaYaRespondBase* respond)
	{
		DownLoadFileRespond* r = static_cast<DownLoadFileRespond*>(respond);
		callDownLoadFileListern(r);
	}
	void YVTool::netWorkStateRespond(YaYaRespondBase* respond)
	{
		NetWorkStateNotify* r = static_cast<NetWorkStateNotify*>(respond);
		callNetWorkSateListern(r);
	}
	void YVTool::recordVoiceRespond(YaYaRespondBase* respond)
	{
		RecordVoiceNotify* r = static_cast<RecordVoiceNotify*>(respond);
		callRecordVoiceListern(r);
	}
	void YVTool::cpUserInfoRespond(YaYaRespondBase* respond)
	{
		GetCPUserInfoRespond* r = static_cast<GetCPUserInfoRespond*>(respond);
		callCPUserInfoListern(r);
	}
	void YVTool::downloadVoiceRespond(YaYaRespondBase* respond)
	{
		DownloadVoiceRespond* r = static_cast<DownloadVoiceRespond*>(respond);
		callDownloadVoiceListern(r);
	}
}
