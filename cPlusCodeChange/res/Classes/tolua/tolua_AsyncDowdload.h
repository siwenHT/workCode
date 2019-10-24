#ifndef __TOLUA_ASYNCDOWNLOAD_H__
#define __TOLUA_ASYNCDOWNLOAD_H__

#include "tolua++.h"
#include "AsyncDownloadManager.h"
#include "LuaBasicConversions.h"

/* method: getInstance of class  AsyncDownloadManager */
int lua_AsyncDownloadManager_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"AsyncDownloadManager",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{

        do 
		{
			AsyncDownloadManager* ret = AsyncDownloadManager::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<AsyncDownloadManager>(tolua_S, "AsyncDownloadManager",(AsyncDownloadManager*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;

}

int lua_AsyncDownloadManager_registerDownloadSucCb(lua_State* tolua_S)
{
    int argc = 0;
    AsyncDownloadManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AsyncDownloadManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (AsyncDownloadManager*)tolua_tousertype(tolua_S,1,0);

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
		cobj->registerDownloadSucCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerDownloadSucCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_AsyncDownloadManager_setDownloadUrl(lua_State* tolua_S)
{
	int argc = 0;
	AsyncDownloadManager* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"AsyncDownloadManager",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (AsyncDownloadManager*)tolua_tousertype(tolua_S,1,0);

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
		cobj->setDownloadUrl(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDownloadUrl",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}


int lua_register_cocos2dx_AsyncDownloadManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AsyncDownloadManager");
	tolua_cclass(tolua_S,"AsyncDownloadManager","AsyncDownloadManager","cc.Layer",NULL);	
		tolua_beginmodule(tolua_S,"AsyncDownloadManager");
			tolua_function(tolua_S, "getInstance", lua_AsyncDownloadManager_getInstance);
			tolua_function(tolua_S, "registerDownloadSucCb", lua_AsyncDownloadManager_registerDownloadSucCb);
			tolua_function(tolua_S, "setDownloadUrl", lua_AsyncDownloadManager_setDownloadUrl);
		tolua_endmodule(tolua_S);
    return 1;
}


#endif    //__TOLUA_MAPBASE_H__