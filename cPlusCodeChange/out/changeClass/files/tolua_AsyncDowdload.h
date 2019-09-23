#ifndef __TOLUA_ASYNCDOWNLOAD_H__
#define __TOLUA_ASYNCDOWNLOAD_H__
#include "tolua++.h"
#include "emptyOrientedVice.h"
#include "LuaBasicConversions.h"
int lua_emptyOrientedVice_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"emptyOrientedVice",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			emptyOrientedVice* ret = emptyOrientedVice::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<emptyOrientedVice>(tolua_S, "emptyOrientedVice",(emptyOrientedVice*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_emptyOrientedVice_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_emptyOrientedVice_literalIostreamSuspended(lua_State* tolua_S)
{
    int argc = 0;
    emptyOrientedVice* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"emptyOrientedVice",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (emptyOrientedVice*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_emptyOrientedVice_literalIostreamSuspended'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->literalIostreamSuspended(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "literalIostreamSuspended",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_emptyOrientedVice_literalIostreamSuspended'.",&tolua_err);
#endif
    return 0;
}
int lua_emptyOrientedVice_setmanipulateTogether(lua_State* tolua_S)
{
	int argc = 0;
	emptyOrientedVice* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"emptyOrientedVice",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (emptyOrientedVice*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_emptyOrientedVice_setmanipulateTogether'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setmanipulateTogether(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setmanipulateTogether",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_emptyOrientedVice_setmanipulateTogether'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_emptyOrientedVice(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"emptyOrientedVice");
	tolua_cclass(tolua_S,"emptyOrientedVice","emptyOrientedVice","cc.Layer",NULL);
		tolua_beginmodule(tolua_S,"emptyOrientedVice");
			tolua_function(tolua_S, "getInstance", lua_emptyOrientedVice_getInstance);
			tolua_function(tolua_S, "literalIostreamSuspended", lua_emptyOrientedVice_literalIostreamSuspended);
			tolua_function(tolua_S, "setmanipulateTogether", lua_emptyOrientedVice_setmanipulateTogether);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    