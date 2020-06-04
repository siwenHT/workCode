#ifndef __TOLUA_CCEFFECTS_H__
#define __TOLUA_CCEFFECTS_H__
#include "tolua++.h"
#include "CCEffects.h"
#include "LuaBasicConversions.h"
int lua_Effects_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
        do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			Effects* ret = Effects::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<Effects>(tolua_S, "Effects",(Effects*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		bool arg0;
		bool arg1;
		do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			Effects* ret = Effects::create(arg0,arg1);
			do {
				if (NULL != ret){
					object_to_luaval<Effects>(tolua_S, "Effects",(Effects*)ret);
				}
				else
					lua_pushnil(tolua_S);
			} while (0);
			return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		bool arg0;
		bool arg1;
		bool arg2;
		do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 4, &arg2); 
			if (!ok) { break; }
			Effects* ret = Effects::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
					object_to_luaval<Effects>(tolua_S, "Effects",(Effects*)ret);
				}
				else
					lua_pushnil(tolua_S);
			} while (0);
			return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Effects_playActionData(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4 || argc == 5) 
    {
		std::string arg0;
		int arg1;
		double arg2;
		int arg3;
		double arg4 = 0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3); 
		if (!ok) { return 0; }
		if(argc == 5)
			luaval_to_number(tolua_S, 6,&arg4);
		cobj->playActionData(arg0,arg1,(float)arg2,arg3,(float)arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playActionData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Effects_setPlistNum(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc ==1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setPlistNum(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPlistNum",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Effects_setOpacityCustom(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setOpacityCustom(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc ==2) 
	{
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->setOpacityCustom(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacityCustom",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_getOpacityCustom(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getOpacityCustom();
		tolua_pushnumber(tolua_S,(int)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacityCustom",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_setBasePosition(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setBasePosition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBasePosition",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_reset(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==0) 
	{
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setIsHide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getIsHide();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_rePlay(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->rePlay();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rePlay",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_setActionHide(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setActionHide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActionHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_Effects_setRestoreFirstFrame(lua_State* tolua_S)
{
	int argc = 0;
	Effects* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Effects*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setRestoreFirstFrame(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRestoreFirstFrame",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_Effects(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Effects");
	tolua_cclass(tolua_S,"Effects","Effects","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"Effects");
			tolua_function(tolua_S, "create", lua_Effects_create);
			tolua_function(tolua_S, "playActionData", lua_Effects_playActionData);
		
			tolua_function(tolua_S, "setPlistNum", lua_Effects_setPlistNum);
			tolua_function(tolua_S, "setOpacityCustom", lua_Effects_setOpacityCustom);
			tolua_function(tolua_S, "getOpacityCustom", lua_Effects_getOpacityCustom);
			tolua_function(tolua_S, "setIsHide", lua_Effects_setIsHide);
			tolua_function(tolua_S, "getIsHide", lua_Effects_getIsHide);
			tolua_function(tolua_S, "rePlay", lua_Effects_rePlay);
			tolua_function(tolua_S, "setBasePosition", lua_Effects_setBasePosition);
			tolua_function(tolua_S, "reset", lua_Effects_reset);
			tolua_function(tolua_S, "setActionHide", lua_Effects_setActionHide);
			tolua_function(tolua_S, "setRestoreFirstFrame", lua_Effects_setRestoreFirstFrame);
	
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    