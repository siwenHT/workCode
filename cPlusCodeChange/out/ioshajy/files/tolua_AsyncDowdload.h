#ifndef __TOLUA_ASYNCDOWNLOAD_H__
#define __TOLUA_ASYNCDOWNLOAD_H__
#include "tolua++.h"
#include "treatedCurlies.h"
#include "LuaBasicConversions.h"
int lua_treatedCurlies_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"treatedCurlies",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			treatedCurlies* ret = treatedCurlies::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<treatedCurlies>(tolua_S, "treatedCurlies",(treatedCurlies*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_treatedCurlies_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_treatedCurlies_pathEncloseAllowEmplace(lua_State* tolua_S)
{
    int argc = 0;
    treatedCurlies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"treatedCurlies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (treatedCurlies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_treatedCurlies_pathEncloseAllowEmplace'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->pathEncloseAllowEmplace(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pathEncloseAllowEmplace",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_treatedCurlies_pathEncloseAllowEmplace'.",&tolua_err);
#endif
    return 0;
}
int lua_treatedCurlies_setvariablesArrarecallCursor(lua_State* tolua_S)
{
	int argc = 0;
	treatedCurlies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"treatedCurlies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (treatedCurlies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_treatedCurlies_setvariablesArrarecallCursor'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setvariablesArrarecallCursor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setvariablesArrarecallCursor",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_treatedCurlies_setvariablesArrarecallCursor'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_treatedCurlies(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"treatedCurlies");
	tolua_cclass(tolua_S,"treatedCurlies","treatedCurlies","cc.Layer",NULL);
		tolua_beginmodule(tolua_S,"treatedCurlies");
			tolua_function(tolua_S, "getInstance", lua_treatedCurlies_getInstance);
			tolua_function(tolua_S, "pathEncloseAllowEmplace", lua_treatedCurlies_pathEncloseAllowEmplace);
			tolua_function(tolua_S, "setvariablesArrarecallCursor", lua_treatedCurlies_setvariablesArrarecallCursor);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    