#include "YVRespondFactory.h"
#include "YVTypeDef.h"
namespace YVSDK
{
	YVRespondFactory* YVRespondFactory::m_respondFactoryPtr = NULL;
	AutoRegisterRespond(IM_THIRD_LOGIN_RESP, CPLoginResponce);
	AutoRegisterRespond(IM_RECORD_STOP_RESP, RecordStopNotify);
	AutoRegisterRespond(IM_RECORD_FINISHPLAY_RESP, StartPlayVoiceRespond);
	AutoRegisterRespond(IM_SPEECH_STOP_RESP, SpeechStopRespond);
	AutoRegisterRespond(IM_UPLOAD_FILE_RESP, UpLoadFileRespond);
	AutoRegisterRespond(IM_DOWNLOAD_FILE_RESP, DownLoadFileRespond);
	AutoRegisterRespond(IM_RECONNECTION_NOTIFY, ReconnectionNotify);
	AutoRegisterRespond(IM_NET_STATE_NOTIFY, NetWorkStateNotify);
	AutoRegisterRespond(IM_RECORD_VOLUME_NOTIFY, RecordVoiceNotify);
	AutoRegisterRespond(IM_GET_THIRDBINDINFO_RESP, GetCPUserInfoRespond);
	AutoRegisterRespond(IM_RECORD_PLAY_PERCENT_NOTIFY, DownloadVoiceRespond);
    
    
    AutoRegisterRespond(IM_TOOL_FLOW_RESP, YunvaflowRespond);
};