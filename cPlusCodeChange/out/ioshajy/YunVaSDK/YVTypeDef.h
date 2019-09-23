#ifndef YVTypeDef_h__
#define YVTypeDef_h__
#include <string>
#include <iostream>
#include <vector>
#include "IMSDK.h"
#include "YVIMCmdDef.h"
#include "yvpacket_overloaded.h"
#include <time.h>
#define  YVSDK_Version "1.0.0"
namespace YVSDK
{
	typedef unsigned int uint32;
	typedef unsigned int uint8;
	class ARef
	{
	public:
		ARef(){ _refCount = 1; }
		virtual ~ARef(){};
		void addRef(){ ++_refCount; };
		void release(){ if ((--_refCount) <= 0)delete this; }
	private:
		unsigned int _refCount;
	};
	struct YaYaRequestBase :public  ARef
	{
		virtual ~YaYaRequestBase(){};
		CmdChannel m_requestChannel;
		uint32 m_requestCmd;
		YaYaRequestBase(CmdChannel channel, uint32 cmd)
		{
			m_requestChannel = channel;
			m_requestCmd = cmd;
		}
		virtual YV_PARSER encode(){ return  yvpacket_get_parser(); }
	};
	struct YaYaRespondBase :public ARef
	{
		virtual ~YaYaRespondBase(){};
		virtual void decode(YV_PARSER parser){}
	};
	struct LoginResponse :YaYaRespondBase
	{
		uint32 result; 
		std::string msg; 
		std::string nickname; 
		uint32 userId; 
		std::string iconurl; 
		void decode(YV_PARSER parser)
		{
			result = parser_get_uint32(parser, x11001::result);
			msg = parser_get_string(parser, x11001::msg);
			nickname = parser_get_string(parser, x11001::nickname);
			userId = parser_get_uint32(parser, x11001::userId);
			iconurl = parser_get_string(parser, x11001::iconurl);
		}
	};
	struct CPLoginRequest : public YaYaRequestBase
	{
		CPLoginRequest()
		:YaYaRequestBase(IM_LOGIN, IM_THIRD_LOGIN_REQ)
		{
		}
		std::string tt;  
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_cstring(parser, x11002::tt, tt.c_str());
			return parser;
		}
	};
	struct CPLoginResponce : public YaYaRespondBase
	{
		uint32 result; 
		std::string msg; 
		uint32 userid;
		std::string nickName;
		std::string iconUrl; 
		std::string thirdUserId; 
		std::string thirdUserName; 
		void decode(YV_PARSER parser)
		{
			this->result = parser_get_uint32(parser, x11003::result);
			this->msg = parser_get_string(parser, x11003::msg);
			this->userid = parser_get_uint32(parser, x11003::userid);
			this->nickName = parser_get_string(parser, x11003::nickName);
			this->iconUrl = parser_get_string(parser, x11003::iconUrl);
			this->thirdUserId = parser_get_string(parser, x11003::thirdUserId);
			this->thirdUserName = parser_get_string(parser, x11003::thirdUserName);
		}
	};
	struct CPLogoutRequest :YaYaRequestBase
	{
		CPLogoutRequest()
		:YaYaRequestBase(IM_LOGIN, IM_LOGOUT_REQ)
		{
		}
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			return parser;
		}
	};
	struct ReconnectionNotify : YaYaRespondBase
	{
		uint32	userid;
		void decode(YV_PARSER parser)
		{
			userid = parser_get_uint32(parser, x11013::userid);
		}
	};
	struct GetCPUserInfoRequest:YaYaRequestBase
	{
		uint32 appid;
		std::string uid;
		GetCPUserInfoRequest()
		:YaYaRequestBase(IM_LOGIN, IM_GET_THIRDBINDINFO_REQ)
		{
		}
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_uint32(parser, x11014::appid, appid);
			parser_set_cstring(parser, x11014::uid, uid.c_str());
			return parser;
		}
	};
	struct GetCPUserInfoRespond 
		: public YaYaRespondBase
	{
		uint32 result;
		std::string msg;
		uint32 yunvaid;
		std::string nickname;
		std::string iconUrl;
		std::string level;
		std::string vip;
		std::string ext;
	
		GetCPUserInfoRespond()
			:YaYaRespondBase()
		{
		}
		void decode(YV_PARSER parser)
		{
			result = parser_get_uint32(parser, x11015::result);
			msg = parser_get_string(parser, x11015::msg);
			yunvaid = parser_get_uint32(parser, x11015::yunvaid);
			nickname = parser_get_string(parser, x11015::nickname);
			iconUrl = parser_get_string(parser, x11015::iconUrl);
			level = parser_get_string(parser, x11015::level);
			vip = parser_get_string(parser, x11015::vip);
			ext = parser_get_string(parser, x11015::ext);
		}
	};
	struct NetWorkStateNotify :YaYaRespondBase
	{
		yv_net state;
		void decode(YV_PARSER parser)
		{
			state = (yv_net)parser_get_uint8(parser, x11016::state);
		}
	};
	struct SetRecordRequest :YaYaRequestBase
	{
		uint32 times;
		uint8 volume;
		SetRecordRequest()
			:YaYaRequestBase(IM_TOOLS, IM_RECORD_SETINFO_REQ)
		{
		}
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_uint32(parser, x19014::times, times);
			parser_set_uint8(parser, x19014::volume, volume);
			return parser;
		}
	};
	struct StartRecordRequest :YaYaRequestBase
	{
		std::string strFilePath;
		std::string  ext;
		uint8 speech;
		StartRecordRequest()
			:YaYaRequestBase(IM_TOOLS, IM_RECORD_STRART_REQ)
		{
		}
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_cstring(parser, x19000::strfilepath, strFilePath.c_str());
			parser_set_cstring(parser, x19000::ext, ext.c_str());
			parser_set_uint8(parser, x19000::speech, speech);
			return parser;
		}
	};
	struct StopRecordRequest :YaYaRequestBase
	{
		StopRecordRequest()
		:YaYaRequestBase(IM_TOOLS, IM_RECORD_STOP_REQ)
		{
		}
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			return parser;
		}
	};
	struct RecordStopNotify :YaYaRespondBase
	{
		uint32	time; 
		std::string	strfilepath; 
		std::string ext;
		uint32 result;
		void decode(YV_PARSER parser)
		{
			time = parser_get_uint32(parser, x19002::time);
			strfilepath = parser_get_string(parser, x19002::strfilepath);
			ext = parser_get_string(parser, x19002::ext);
			result = parser_get_uint32(parser, x19002::result);
		}
	};
	struct RecordVoiceNotify 
		:YaYaRespondBase
	{
		std::string ext;  
		uint8       volume;  
		void decode(YV_PARSER parser)
		{
			volume = parser_get_uint8(parser, x19015::volume);
			ext = parser_get_string(parser, x19015::ext);
		}
	};
	struct StartPlayVoiceRequest :YaYaRequestBase
	{
		StartPlayVoiceRequest()
		:YaYaRequestBase(IM_TOOLS, IM_RECORD_STARTPLAY_REQ)
		{
		}
		std::string	strUrl;      
		std::string	strfilepath;  
		std::string ext;
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_cstring(parser, x19003::strUrl, strUrl.c_str());
			parser_set_cstring(parser, x19003::strfilepath, strfilepath.c_str());
			parser_set_cstring(parser, x19003::ext, ext.c_str());
			return parser;
		}
	};
	struct StartPlayVoiceRespond :YaYaRespondBase
	{
		uint32    result; 
		std::string    describe; 
		std::string  ext;
		void decode(YV_PARSER parser)
		{
			result = parser_get_uint32(parser, x19004::result);
			describe = parser_get_string(parser, x19004::describe);
			ext = parser_get_string(parser, x19004::ext);
		}
	};
	struct StopPlayVoiceRequest :YaYaRequestBase
	{
		StopPlayVoiceRequest()
		:YaYaRequestBase(IM_TOOLS, IM_RECORD_STOPPLAY_REQ)
		{
		}
	};
	struct SpeechSetRequest :YaYaRequestBase
	{
		SpeechSetRequest()
		:YaYaRequestBase(IM_TOOLS, IM_SPEECH_SETLANGUAGE_REQ)
		{
		}
		yvimspeech_language inLanguage;
		yvimspeech_outlanguage outLanguage;
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_uint8(parser, x19008::inlanguage, inLanguage);
			parser_set_uint8(parser, x19008::outlanguage, outLanguage);
			return parser;
		}
	};
	struct SpeechStopRespond :YaYaRespondBase
	{
		uint32		err_id;   
		std::string		err_msg;  
		std::string		result;   
		std::string ext;
		std::string url;    
		void decode(YV_PARSER parser)
		{
			err_id = parser_get_uint32(parser, x19009::err_id);
			err_msg = parser_get_string(parser, x19009::err_msg);
			result = parser_get_string(parser, x19009::result);
			ext = parser_get_string(parser, x19009::ext);
			url = parser_get_string(parser, x19009::url);
		}
	};
	struct UpLoadFileRequest :YaYaRequestBase
	{
		UpLoadFileRequest()
		:YaYaRequestBase(IM_TOOLS, IM_UPLOAD_FILE_REQ)
		{
		}
		std::string filename;
		std::string fileid;
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_cstring(parser, x19010::filename, filename.c_str());
			parser_set_cstring(parser, x19010::fileid, fileid.c_str());
			return parser;
		}
	};
	struct UpLoadFileRespond :YaYaRespondBase
	{
		uint32	result;
		std::string  msg;        
		std::string  fileid;     
		std::string  fileurl;    
		uint32  percent;    
		void decode(YV_PARSER parser)
		{
			result = parser_get_uint32(parser, x19011::result);
			msg = parser_get_string(parser, x19011::msg);
			fileid = parser_get_string(parser, x19011::fileid);
			fileurl = parser_get_string(parser, x19011::fileurl);
			percent = parser_get_uint32(parser, x19011::percent);
		}
	};
	struct DownLoadFileRequest :YaYaRequestBase
	{
		DownLoadFileRequest()
		:YaYaRequestBase(IM_TOOLS, IM_DOWNLOAD_FILE_REQ)
		{
		}
		std::string url;
		std::string filename;
		std::string fileid;
		YV_PARSER encode()
		{
			YV_PARSER parser = yvpacket_get_parser();
			parser_set_cstring(parser, x19012::url, url.c_str());
			parser_set_cstring(parser, x19012::filename, filename.c_str());
			parser_set_cstring(parser, x19012::fileid, fileid.c_str());
			return parser;
		}
	};
	struct DownLoadFileRespond :YaYaRespondBase
	{
		uint32	result;     
		std::string  msg;        
		std::string  filename;   
		std::string  fileid;     
		uint32  percent;    
		void decode(YV_PARSER parser)
		{
			result = parser_get_uint32(parser, x19013::result);
			msg = parser_get_string(parser, x19013::msg);
			filename = parser_get_string(parser, x19013::filename);
			fileid = parser_get_string(parser, x19013::fileid);
			percent = parser_get_uint32(parser, x19013::percent);
		}
	};
	struct DownloadVoiceRespond
		: public YaYaRespondBase
	{
		uint8      percent;
		std::string     ext;
		void decode(YV_PARSER parser)
		{
			percent = parser_get_uint32(parser, x19016::percent);
			ext = parser_get_string(parser, x19016::ext);
		}
	};
    
    
    
    struct YunvaflowRespond :YaYaRespondBase
    {
        uint32    result; 
        std::string    msg; 
        uint32  upflow;
        uint32  downflow;
        uint32  allflow;
        void decode(YV_PARSER parser)
        {
            result   = parser_get_uint32(parser, x19022::result);
            msg      = parser_get_string(parser, x19022::msg);
            upflow   = parser_get_uint32(parser, x19022::upflow);
            downflow = parser_get_uint32(parser, x19022::downflow);
            allflow  = parser_get_uint32(parser, x19022::allflow);
        }
    };
    
    
    struct YunvaflowRequest :YaYaRequestBase
    {
        YunvaflowRequest()
        :YaYaRequestBase(IM_TOOLS, IM_TOOL_FLOW_REQ)
        {
        }
    };
    
}
#endif 
