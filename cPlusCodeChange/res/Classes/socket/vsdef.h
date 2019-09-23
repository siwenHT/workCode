// vsdef.h :
#pragma once

#pragma pack(push, 1)

// 只定义无符号的简单类型，便于书写
typedef unsigned char			uchar;
typedef unsigned short			ushort;
typedef unsigned int			uint;
typedef long long				int64;
typedef int						int32;
typedef short					int16;
typedef char					int8;
typedef unsigned long long		uint64;
typedef unsigned int			uint32;
typedef unsigned short			uint16;
typedef unsigned char			uint8;

#define NUMBER_TYPE				int32

#define CC_SWAP64(i)  ((i & 0x00000000000000ff) << 56 | (i & 0x000000000000ff00) << 40 | (i & 0x0000000000ff0000) << 24 | (i & 0x00000000ff000000) << 8 \
	                   |(i & 0x000000ff00000000) >> 8 | (i & 0x0000ff0000000000) >> 24 | (i & 0x00ff000000000000) >> 40 | (i & 0xff00000000000000) >> 56 )

#define MAX_PATH_LEN 16			//客户端与服务器同步路径最大步数，如果一次行走大于该步数，需要分段同步。（原来为512步，未做分段同步） aric xu 2009-12-23
#define RECONNECT_DELAY			(2 * 1000)
#define HEART_BEAT_PERIOD		5
#define GRID_DISTANCE_MAX		512
#define MAX_GATEWAY_COUNT		128
#define MAX_SCENE_SVR_COUNT		256
#define MAX_APP_MSG_LEN			(8 * 1024)
#define MAX_SINK_MSG_LEN		(MAX_APP_MSG_LEN - 12)
#define MAX_MAP_COUNT			1024
#define MAX_MAP_LOAD_CLS_COUNT	64
#define MAX_WLD_COUNT			1024
#define MAX_PROP_COUNT			256

#define INVALID_WLD_ID			-1
#define INVALID_DB_ID           -1
#define INVALID_ENTITY_ID		-1
#define INVALID_ARRIDX			-1
#define INVALID_MAP_ID			-1

/*服务器与客户端之间的通讯消息都以本消息格式开头*/
struct AppMsg
{
	unsigned short msgLen;	   //消息长度（包括本消息头），具体最大长度具体取决于实现
	unsigned char  msgCheck;   //校验位
	unsigned char  offset;     //偏移位
	unsigned int   msgId;	   //消息id
};
const int SIZEOF_APPMSG = sizeof(AppMsg);

/// 消息标志位
enum _AppMsgFlagTo
{
	MSG_FLAG_ENCRYPT = 0x01,			/**< 加密标志位*/
	MSG_FLAG_PART = 0x10			    /**< 部分消息标志，用来告知接收方该消息分多次发送 */
};

enum MsgID
{
	C2S_MOVE                   = 4002,      //移动
	C2S_STOP_MOVING            = 4004,      //停止移动
	C2S_SYNC_POS               = 4006       //同步位置
};

#include "cocos2d.h"
USING_NS_CC;

#ifndef ENABLE_CPLUSLOG
#define ENABLE_CPLUSLOG 1
#endif

#if (ENABLE_CPLUSLOG == 1)  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define CPLUSLog(format, ...)      	{SYSTEMTIME st = {0};\
	GetLocalTime(&st);\
	char str[50] = {};\
	std::string fmt = "%s ";\
	fmt += format;\
	sprintf_s(str, "%d-%02d-%02d %02d:%02d:%02d:%03d",  st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);\
	cocos2d::log(fmt.c_str(), str, ##__VA_ARGS__);\
}
#else 
#define CPLUSLog(format, ...)	      do {} while (0)
#endif 

#else
#define CPLUSLog(...)				 do {} while (0)
#endif

#pragma pack(pop)
