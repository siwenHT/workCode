#ifndef _IMSDK_H__
#define _IMSDK_H__
#include "yvpacket_sdk.h"
#ifdef _MSC_VER
#ifdef  _YVIM_EXPORTS
#define YVIM_API    extern "C" __declspec(dllexport)  
#else
#define YVIM_API    
#endif
#else
#define YVIM_API    
#define _stdcall    
#endif
#define  YV_RET_SUCC      0       
#define  YV_RET_FAIL      -1      
enum CmdChannel {
	IM_LOGIN   = 1,
	IM_FRIEND  = 2,
	IM_GROUPS  = 3,
	IM_CHAT    = 4,
	IM_CLOUND  = 5,
	IM_CHANNEL = 6,
	IM_TROOPS  = 7,
	IM_LBS     = 8,
	IM_TOOLS   = 9,
	IM_LIVE    = 10,
	IM_TROOPSU = 11,
	IM_AVRECORD = 12,
};
#ifdef __cplusplus
extern "C" {
#endif
typedef void (_stdcall *YVCallBack)(enum CmdChannel type, unsigned int cmdid, YV_PARSER parser, unsigned long context);
YVIM_API int   YVIM_Init(YVCallBack callback, unsigned long context, unsigned int appid, const char* path, bool test, bool oversea = 0);
YVIM_API void  YVIM_Release();
YVIM_API int    YVIM_SendCmd(enum CmdChannel type, unsigned int cmdid, YV_PARSER parser);
YVIM_API void   YVIM_SetCallBackMode(bool mode);
YVIM_API void   YVIM_SetCallBack(YVCallBack callback, unsigned long context);
YVIM_API  int   YVIM_SetShowSurface(int width, int height, void* h);
YVIM_API  void  YVIM_SetScreenDpi(int width, int height);
#ifdef __cplusplus
}
#endif
#endif