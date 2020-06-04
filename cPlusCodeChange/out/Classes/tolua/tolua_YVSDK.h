#ifndef __TOLUA_YVSDKHELPER_H__
#define __TOLUA_YVSDKHELPER_H__
#include "tolua++.h"
#include "YunVaSDK/YVSdkHelper.h"
#include "LuaBasicConversions.h"
int lua_YVSdkHelper_getInstacne(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	do 
	{
		YVSdkHelper* ret = YVSdkHelper::getInstance();
		do {
			if (NULL != ret){
				tolua_pushusertype(tolua_S,(void*)ret,"YVSdkHelper");
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
		return 1;
	} while (0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getInstacne",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_YVSdkHelper_doInitSDK(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->doInitSDK(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doInitSDK",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_cpLogin(lua_State* tolua_S)
{
    int argc = 0;
    YVSdkHelper* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->cpLogin(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cpLogin",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_YVSdkHelper_setRecord(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setRecordNum(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRecord",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_startRecord(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->startRecord(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) 
	{
		std::string arg0;
		int arg1;
	
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->startRecord(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		std::string arg0;
		int arg1;
		std::string arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg2); 
		if (!ok) { return 0; }
		cobj->startRecord(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "startRecord", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_stopRecord(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	cobj->stopRecord();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_playRecord(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->playRecord(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		std::string arg0;
		std::string arg1;
		std::string arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		cobj->playRecord(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playRecord",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_stopPlay(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	cobj->stopPlay();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_upLoadFile(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->upLoadFile(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) 
	{
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->upLoadFile(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "upLoadFile",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_speechVoice(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->speechVoice(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) 
	{
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->speechVoice(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		std::string arg0;
		std::string arg1;
		bool arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		cobj->speechVoice(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "speechVoice",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_YVSdkHelper_registerHandler(lua_State* tolua_S)
{
	int argc = 0;
	YVSdkHelper* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YVSdkHelper",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (YVSdkHelper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerHandler(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerHandler",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_YVSdkHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"YVSdkHelper");
	tolua_cclass(tolua_S,"YVSdkHelper","YVSdkHelper","",NULL);
		tolua_beginmodule(tolua_S,"YVSdkHelper");
			tolua_function(tolua_S, "getInstance", lua_YVSdkHelper_getInstacne);
			tolua_function(tolua_S, "doInitSDK", lua_YVSdkHelper_doInitSDK);
			tolua_function(tolua_S, "cpLogin", lua_YVSdkHelper_cpLogin);
			tolua_function(tolua_S, "setRecord", lua_YVSdkHelper_setRecord);
			tolua_function(tolua_S, "startRecord", lua_YVSdkHelper_startRecord);
			tolua_function(tolua_S, "stopRecord", lua_YVSdkHelper_stopRecord);
			tolua_function(tolua_S, "playRecord", lua_YVSdkHelper_playRecord);
			tolua_function(tolua_S, "stopPlay", lua_YVSdkHelper_stopPlay);
			tolua_function(tolua_S, "upLoadFile", lua_YVSdkHelper_upLoadFile);
			tolua_function(tolua_S, "speechVoice", lua_YVSdkHelper_speechVoice);
			tolua_function(tolua_S, "registerHandler", lua_YVSdkHelper_registerHandler);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    