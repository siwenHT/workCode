#ifndef __TOLUA_SPRITEBASE_H__
#define __TOLUA_SPRITEBASE_H__
#include "tolua++.h"
#include "SpriteMonster.h"
#include "SpritePlayer.h"
#include "LuaBasicConversions.h"
#include "TouchSprite.h"
#include "GraySprite.h"
#include "Touch9Sprite.h"
#include "SpriteBlur.h"
#include "SpriteGuard.h"
int lua_SpriteBase_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			SpriteBase* ret = SpriteBase::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			SpriteBase* ret = SpriteBase::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
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
int lua_SpriteBase_reset(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "reset",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setBaseUrl(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setBaseUrl(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setBaseUrl",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setActionStateChange(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setActionStateChange(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setActionStateChange",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setBaseAnchorPoint(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setBaseAnchorPoint(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setBaseAnchorPoint",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setBasePosition(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setBasePosition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setBasePosition",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_initStandStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 8) 
    {
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		double arg6;
		int arg7;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 8, &arg6); 
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		cobj->initStandStatus(arg0,arg1,arg2,arg3,arg4,arg5,(float)arg6,(Commen_Direction)arg7);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initStandStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initFlyStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		int arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg2);
		if (!ok) { return 0; }
		cobj->initFlyStatus(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initFlyStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initRideStatus(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->initRideStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initRideStatus",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_initAttackModeStatus(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 12) 
	{
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		int arg6;
		int arg7;
		int arg8;
		int arg9;
		int arg10;
		int arg11;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7, &arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 8, &arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9, &arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10, &arg8);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 11, &arg9);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 12, &arg10);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 13, &arg11);
		if (!ok) { return 0; }
		cobj->initAttackModeStatus(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initAttackModeStatus",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
	int lua_SpriteBase_initWeaponEffFrames(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 12) 
	{
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		int arg6;
		int arg7;
		int arg8;
		int arg9;
		int arg10;
		int arg11;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7, &arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 8, &arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9, &arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10, &arg8);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 11, &arg9);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 12, &arg10);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 13, &arg11);
		if (!ok) { return 0; }
		cobj->initWeaponEffFrames(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWeaponEffFrames",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_initHurtIdleStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		cobj->initHurtIdleStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initHurtIdleStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		tolua_pushboolean(tolua_S, ret);
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
int lua_SpriteBase_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
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
int lua_SpriteBase_setIsAddRenderList(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setIsAddRenderList(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsAddRenderList",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_initHurtKneelStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		cobj->initHurtKneelStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initHurtKneelStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initAttackRushStatus(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		std::string arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->initAttackRushStatus(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initAttackRushStatus",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_standed(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->standed();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_standedby(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->standedby();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standedby",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setPlistsNum(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setPlistsNum(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPlistsNum",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setDirByNowPoint(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setDirByNowPoint(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirByNowPoint",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setOnRide(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setOnRide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getShowPlistPath(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		std::string ret = cobj->getShowPlistPath();
		tolua_pushstring(tolua_S, ret.c_str());
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getShowPlistPath",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getOnRide(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getOnRide();
		tolua_pushboolean(tolua_S, (int)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getOnRideId(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getOnRideId();
		tolua_pushnumber(tolua_S, ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOnRideId",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_walkInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->walkInTheDir((float)arg0,arg1,(Commen_Direction)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "walkInTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_moveInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->moveInTheDir((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->moveInTheDir((float)arg0,arg1,(Commen_Direction)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 4) 
	{
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		bool ret = cobj->moveInTheDir((float)arg0,arg1,(Commen_Direction)arg2,arg3);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveInTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_doStreakToTheDir(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->doStreakToTheDir((float)arg0,arg1,(Commen_Direction)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doStreakToTheDir",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_collideInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->collideInTheDir((float)arg0,arg1,(Commen_Direction)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "collideInTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_digToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->digToTheDir((float)arg0,(Commen_Direction)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "digToTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_createToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->createToTheDir((float)arg0,(Commen_Direction)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createToTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_excavateToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->excavateToTheDir((float)arg0,(Commen_Direction)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "excavateToTheDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_flyToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
    tolua_Error tolua_err;
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
    {
		double arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		cobj->flyToTheDir((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 4) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3,(Commen_Direction)arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 6) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3,(Commen_Direction)arg4,arg5);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 7) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3,(Commen_Direction)arg4,arg5,arg6);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 8) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		bool arg7;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3,(Commen_Direction)arg4,arg5,arg6,arg7);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 9) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		bool arg7;
		int  arg8;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10,&arg8);
		if (!ok) { return 0; }
		cobj->flyToTheDir((float)arg0,arg1,arg2,arg3,(Commen_Direction)arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "flyToTheDir",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
    return 0;
}
int lua_SpriteBase_hurtIdleToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->hurtIdleToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->hurtIdleToPos((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hurtIdleToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_hurtKneelToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->hurtKneelToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->hurtKneelToPos((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hurtKneelToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_moveToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->moveToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->moveToPos((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_walkToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->walkToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "walkToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initAttackStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->initAttackStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initAttackStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_attackToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->attackToPos((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 3) 
	{
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->attackToPos((float)arg0,arg1,arg2);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "attackToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_attackOneTime(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		bool ret = cobj->attackOneTime((float)arg0,Point::ZERO);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->attackOneTime((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "attackOneTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initMagicStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->initMagicStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initMagicStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_magicUpToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->magicUpToPos((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "magicUpToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_initHurtStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->initHurtStatus(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initHurtStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_hasHurted(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->hasHurted((float)arg0,(float)arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hasHurted",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_gotoDeath(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->gotoDeath((Commen_Direction)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoDeath",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setTouchEnable(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0=true;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setTouchEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_isTouchInside(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		Touch* arg0 = (Touch*)tolua_tousertype(tolua_S,2,0);
		if (!arg0) { return 0; }
		bool ret = cobj->isTouchInside(arg0);
		if (ret){
				tolua_pushboolean(tolua_S,(bool)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchInside",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setOpacity(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 2) 
	{
		int arg0 ;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->setOpacity(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setColor(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setShenbingStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setShenbingStatus(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setShenbingStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getShenbingStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getShenbingStatus();
		tolua_pushnumber(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getShenbingStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setGray(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setGray(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setGray",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setWhite(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setWhite(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWhite",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getOpacity();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setSpriteDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setSpriteDir((Commen_Direction)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSpriteDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_changeState(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->changeState((ActionState)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changeState",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getCurrectDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		Commen_Direction ret = cobj->getCurrectDir();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrectDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setCurrActionState(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setCurrActionState((ActionState)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCurrActionState",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getCurrActionState(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		ActionState ret = cobj->getCurrActionState();
		if(ret > 0)
		{
			tolua_pushnumber(tolua_S,(int)ret);
			return 1;
		}
		else
			lua_pushnil(tolua_S);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrActionState",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setType(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setTypeId((SpriteType)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}else if (argc == 2) 
	{
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->setTypeId((SpriteType)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setFatherType(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setFatherType((SpriteType)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_SpriteBase_setFatherType",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getResLoadStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getResLoadStatus();
		tolua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResLoadStatus",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getType(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = (int)cobj->getTypeId();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_stopInTheTime(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg = 0;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->stopInTheTime((ActionState)arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopInTheTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_refresh(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->refresh();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "refresh",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getActorId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		std::string ret = (std::string)cobj->getActorId();
		if (ret != "") { tolua_pushstring(tolua_S,ret.c_str());}
		else { lua_pushnil(tolua_S); }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActorId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setActorId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		std::string arg0 = "";
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setActorId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActorId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_playAction(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->playAction(arg0, (Commen_ActionToDo)arg1, (Commen_Direction)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playAction",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getLocalZOrder(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = (int)cobj->getLocalZOrder();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLocalZOrder",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getStandTime(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		float ret = cobj->getStandTime();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStandTime",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_playActionData(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->playActionData(arg0, (Commen_ActionToDo)arg1, (Commen_Direction)arg2, arg3, arg4);
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
int lua_SpriteBase_getAttackMode(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getAttackMode();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttackMode",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setAttackMode(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setAttackMode(arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAttackMode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setFlyMode(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setFlyMode(arg);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlyMode",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setResId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setResId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setResId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getResId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getResId();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_setOffsetPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setOffsetPos(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOffsetPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getOffsetPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		const cocos2d::Point& ret = cobj->getOffsetPos();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOffsetPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getVisibleState(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getVisibleState();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVisibleState",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setVisibleState(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setVisibleState(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisibleState",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getScreenVisible(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getScreenVisible();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "v",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getFather(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		SpriteBase* ret = cobj->getFather();
		do {
			if (NULL != ret){
				object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFather",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setFather(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			SpriteBase* arg0 = (SpriteBase*)tolua_tousertype(tolua_S, 2,0); 
			if (!ok) { break; }
			cobj->setFather(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_SpriteBase_setFather",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setSingleVisible(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2,&arg0);
			if (!ok) { break; }
			cobj->setSingleVisible(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_SpriteBase_setSingleVisible",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getIsFixAnimDir(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getIsFixAnimDir();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsFixAnimDir",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setIsFixAnimDir(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setIsFixAnimDir(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsFixAnimDir",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_registerSetOpacityCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSetOpacityCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetOpacityCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_removeSetOpacityCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetOpacityCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_registerSetVisibleCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSetVisibleCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetVisibleCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_removeSetVisibleCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetVisibleCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_registerSetVisibleScreenCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSetVisibleScreenCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetVisibleScreenCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_removeSetVisibleScreenCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->removeSetVisibleScreenCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_registerSetWhiteCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSetWhiteCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetWhiteCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_removeSetWhiteCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetWhiteCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_registerSyncChildActionCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSyncChildActionCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSyncChildActionCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_removeSyncChildActionCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->removeSyncChildActionCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_registerSpriteInitCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->registerSpriteInitCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSpriteInitCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_removeSpriteInitCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->removeSpriteInitCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setParentReorderChildDirty(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setParentReorderChildDirty(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setParentReorderChildDirty",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setZOrderFlag(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			unsigned short arg0;
			ok &= luaval_to_ushort(tolua_S, 2, &arg0);
			if (!ok) { break; }
			cobj->setZOrderFlag(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setZOrderFlag",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_FixFlyPos(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->FixFlyPos();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setRenderMode(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0);
			if (!ok) { break; }
			cobj->setRenderMode(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRenderMode",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getIsRepMode(lua_State* tolua_S)
{
	int argc = 0;
	SpriteBase* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getIsRepMode();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsRepMode", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_SpriteBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteBase");
	tolua_cclass(tolua_S,"SpriteBase","SpriteBase","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"SpriteBase");
			tolua_function(tolua_S, "create", lua_SpriteBase_create);
			tolua_function(tolua_S, "reset", lua_SpriteBase_reset);
			tolua_function(tolua_S, "setBaseUrl", lua_SpriteBase_setBaseUrl);
			tolua_function(tolua_S, "setBaseAnchorPoint", lua_SpriteBase_setBaseAnchorPoint);
			tolua_function(tolua_S, "setActionStateChange", lua_SpriteBase_setActionStateChange);
			tolua_function(tolua_S, "setBasePosition", lua_SpriteBase_setBasePosition);
			tolua_function(tolua_S, "initStandStatus", lua_SpriteBase_initStandStatus);
			tolua_function(tolua_S, "initFlyStatus", lua_SpriteBase_initFlyStatus);
			tolua_function(tolua_S, "initRideStatus", lua_SpriteBase_initRideStatus);
			tolua_function(tolua_S, "initAttackModeStatus", lua_SpriteBase_initAttackModeStatus);
			tolua_function(tolua_S, "initWeaponEffFrames", lua_SpriteBase_initWeaponEffFrames);
			tolua_function(tolua_S, "initHurtIdleStatus", lua_SpriteBase_initHurtIdleStatus);
			tolua_function(tolua_S, "initHurtKneelStatus", lua_SpriteBase_initHurtKneelStatus);
			tolua_function(tolua_S, "getIsHide", lua_SpriteBase_getIsHide);
			tolua_function(tolua_S, "setIsHide", lua_SpriteBase_setIsHide);
			tolua_function(tolua_S, "setIsAddRenderList", lua_SpriteBase_setIsAddRenderList);
			tolua_function(tolua_S, "initAttackRushStatus", lua_SpriteBase_initAttackRushStatus);
			tolua_function(tolua_S, "standed", lua_SpriteBase_standed);
			tolua_function(tolua_S, "standedby", lua_SpriteBase_standedby);
			tolua_function(tolua_S, "setPlistsNum", lua_SpriteBase_setPlistsNum);
			tolua_function(tolua_S, "setDirByNowPoint", lua_SpriteBase_setDirByNowPoint);
			tolua_function(tolua_S, "walkInTheDir", lua_SpriteBase_walkInTheDir);
			tolua_function(tolua_S, "moveInTheDir", lua_SpriteBase_moveInTheDir);
			tolua_function(tolua_S, "doStreakToTheDir", lua_SpriteBase_doStreakToTheDir);
			tolua_function(tolua_S, "collideInTheDir", lua_SpriteBase_collideInTheDir);
			tolua_function(tolua_S, "digToTheDir", lua_SpriteBase_digToTheDir);
			tolua_function(tolua_S, "excavateToTheDir", lua_SpriteBase_excavateToTheDir);
			tolua_function(tolua_S, "createToTheDir", lua_SpriteBase_createToTheDir);		
			tolua_function(tolua_S, "flyToTheDir", lua_SpriteBase_flyToTheDir);
			tolua_function(tolua_S, "hurtIdleToPos", lua_SpriteBase_hurtIdleToPos);
			tolua_function(tolua_S, "hurtKneelToPos", lua_SpriteBase_hurtKneelToPos);
			tolua_function(tolua_S, "moveToPos", lua_SpriteBase_moveToPos);
			tolua_function(tolua_S, "walkToPos", lua_SpriteBase_walkToPos);
			tolua_function(tolua_S, "initAttackStatus", lua_SpriteBase_initAttackStatus);
			tolua_function(tolua_S, "attackToPos", lua_SpriteBase_attackToPos);
		
		
			tolua_function(tolua_S, "attackOneTime", lua_SpriteBase_attackOneTime);	
			tolua_function(tolua_S, "initMagicStatus", lua_SpriteBase_initMagicStatus);
			tolua_function(tolua_S, "magicUpToPos", lua_SpriteBase_magicUpToPos);
			tolua_function(tolua_S, "initHurtStatus", lua_SpriteBase_initHurtStatus);
			tolua_function(tolua_S, "hasHurted", lua_SpriteBase_hasHurted);
			tolua_function(tolua_S, "gotoDeath", lua_SpriteBase_gotoDeath);
			tolua_function(tolua_S, "isTouchInside", lua_SpriteBase_isTouchInside);
			tolua_function(tolua_S, "setTouchEnable", lua_SpriteBase_setTouchEnable);
			tolua_function(tolua_S, "setColor", lua_SpriteBase_setColor);
			tolua_function(tolua_S, "setGray", lua_SpriteBase_setGray);
			tolua_function(tolua_S, "setWhite", lua_SpriteBase_setWhite);
			tolua_function(tolua_S, "setOpacity", lua_SpriteBase_setOpacity);
			tolua_function(tolua_S, "getOpacity", lua_SpriteBase_getOpacity);
			tolua_function(tolua_S, "setCurrActionState", lua_SpriteBase_setCurrActionState);
			tolua_function(tolua_S, "getCurrActionState", lua_SpriteBase_getCurrActionState);
			tolua_function(tolua_S, "setSpriteDir", lua_SpriteBase_setSpriteDir);
			tolua_function(tolua_S, "changeState", lua_SpriteBase_changeState);
			tolua_function(tolua_S, "getCurrectDir", lua_SpriteBase_getCurrectDir);
			tolua_function(tolua_S, "setType", lua_SpriteBase_setType);
			tolua_function(tolua_S, "getType", lua_SpriteBase_getType);
			tolua_function(tolua_S, "setShenbingStatus", lua_SpriteBase_setShenbingStatus);
			tolua_function(tolua_S, "getShenbingStatus", lua_SpriteBase_getShenbingStatus);			
			tolua_function(tolua_S, "getResLoadStatus", lua_SpriteBase_getResLoadStatus);
			tolua_function(tolua_S, "stopInTheTime", lua_SpriteBase_stopInTheTime);
			tolua_function(tolua_S, "refresh", lua_SpriteBase_refresh);
			tolua_function(tolua_S, "setFatherType", lua_SpriteBase_setFatherType);
		
			tolua_function(tolua_S, "getActorId",     lua_SpriteBase_getActorId);
			tolua_function(tolua_S, "setActorId",     lua_SpriteBase_setActorId);
			tolua_function(tolua_S, "playAction",     lua_SpriteBase_playAction);
			tolua_function(tolua_S, "getLocalZOrder", lua_SpriteBase_getLocalZOrder); 
			tolua_function(tolua_S, "playActionData", lua_SpriteBase_playActionData);
			tolua_function(tolua_S, "getStandTime", lua_SpriteBase_getStandTime);
			tolua_function(tolua_S, "setAttackMode",  lua_SpriteBase_setAttackMode);
			tolua_function(tolua_S, "getAttackMode",  lua_SpriteBase_getAttackMode);
			tolua_function(tolua_S, "setFlyMode",  lua_SpriteBase_setFlyMode);
			tolua_function(tolua_S, "setResId",       lua_SpriteBase_setResId);
			tolua_function(tolua_S, "getResId",       lua_SpriteBase_getResId);
			tolua_function(tolua_S, "setOnRide",      lua_SpriteBase_setOnRide);
			tolua_function(tolua_S, "getOnRide",      lua_SpriteBase_getOnRide);
			tolua_function(tolua_S, "getOnRideId",    lua_SpriteBase_getOnRideId); 
			tolua_function(tolua_S, "setOffsetPos",   lua_SpriteBase_setOffsetPos);
			tolua_function(tolua_S, "getOffsetPos",   lua_SpriteBase_getOffsetPos);
			tolua_function(tolua_S, "getShowPlistPath",   lua_SpriteBase_getShowPlistPath);
		
			tolua_function(tolua_S, "getVisibleState",    lua_SpriteBase_getVisibleState);
			tolua_function(tolua_S, "setVisibleState",    lua_SpriteBase_setVisibleState);
			tolua_function(tolua_S, "getScreenVisible",    lua_SpriteBase_getScreenVisible);
			tolua_function(tolua_S, "setFather",    lua_SpriteBase_setFather);
			tolua_function(tolua_S, "getFather",    lua_SpriteBase_getFather);
			tolua_function(tolua_S, "setSingleVisible",    lua_SpriteBase_setSingleVisible);
			tolua_function(tolua_S, "setParentReorderChildDirty",    lua_SpriteBase_setParentReorderChildDirty);
			tolua_function(tolua_S, "setZOrderFlag",    lua_SpriteBase_setZOrderFlag);
			tolua_function(tolua_S, "setIsFixAnimDir",    lua_SpriteBase_setIsFixAnimDir);
			tolua_function(tolua_S, "getIsFixAnimDir",    lua_SpriteBase_getIsFixAnimDir);
			tolua_function(tolua_S, "registerSetOpacityCb",       lua_SpriteBase_registerSetOpacityCb);
			tolua_function(tolua_S, "removeSetOpacityCb",         lua_SpriteBase_removeSetOpacityCb);
			tolua_function(tolua_S, "registerSetVisibleCb",       lua_SpriteBase_registerSetVisibleCb);
			tolua_function(tolua_S, "removeSetVisibleCb",         lua_SpriteBase_removeSetVisibleCb);
		
			tolua_function(tolua_S, "registerSetVisibleScreenCb",       lua_SpriteBase_registerSetVisibleScreenCb);
			tolua_function(tolua_S, "removeSetVisibleScreenCb",         lua_SpriteBase_removeSetVisibleScreenCb);
			tolua_function(tolua_S, "registerSetWhiteCb",         lua_SpriteBase_registerSetWhiteCb);
			tolua_function(tolua_S, "removeSetWhiteCb",           lua_SpriteBase_removeSetWhiteCb);
			tolua_function(tolua_S, "registerSyncChildActionCb",           lua_SpriteBase_registerSyncChildActionCb);
			tolua_function(tolua_S, "removeSyncChildActionCb",           lua_SpriteBase_removeSyncChildActionCb);
			tolua_function(tolua_S, "registerSpriteInitCb",           lua_SpriteBase_registerSpriteInitCb);
			tolua_function(tolua_S, "removeSpriteInitCb",           lua_SpriteBase_removeSpriteInitCb);
			tolua_function(tolua_S, "FixFlyPos",              lua_SpriteBase_FixFlyPos);
			tolua_function(tolua_S, "setRenderMode",          lua_SpriteBase_setRenderMode);
			tolua_function(tolua_S, "getIsRepMode",          lua_SpriteBase_getIsRepMode);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_SpriteMonster_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			SpriteMonster* ret = SpriteMonster::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<SpriteMonster>(tolua_S, "SpriteMonster",(SpriteMonster*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1);
			if (!ok) { break; }
			SpriteMonster* ret = SpriteMonster::create(arg0, arg1);
			do {
				if (NULL != ret){
					object_to_luaval<SpriteMonster>(tolua_S, "SpriteMonster",(SpriteMonster*)ret);
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
int lua_SpriteMonster_setNeedSyncPosToServer(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setNeedSyncPosToServer(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setNeedSyncPosToServer",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_setBloodType(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setBloodType(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setBloodType",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_setBloodVisible(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setBloodVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setBloodVisible",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_setSpeed(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSpeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setSpeed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_setShowBloodAnim(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setShowBloodAnim(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setShowBloodAnim",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_isMove(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		bool ret = cobj->isMove();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "isMove",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setHP(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int64 arg0;
		ok &= luaval_to_long_long(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setHP(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBase_getHP(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int64 ret = cobj->getHP();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setMonsterId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setMonsterId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMonsterId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getMonsterId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getMonsterId();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMonsterId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int64 arg0;
		ok &= luaval_to_long_long(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setMaxHP(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int64 ret = cobj->getMaxHP();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setAttack(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setAttack(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAttack",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getAttack(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getAttack();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttack",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setName(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		if(!ok) return 0;
		cobj->setName(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getName(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		std::string ret = cobj->getName();
		tolua_pushcppstring(tolua_S,(const char*)ret); 
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setLevel(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getLevel(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getLevel();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_subBlood(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->subBlood(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "subBlood",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_setNameAndBloodShow(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		int arg1 = 0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setNameAndBloodShow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNameAndBloodShow",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_showNameAndBlood(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2 || argc == 3) 
    {
		bool arg0;
		bool arg1;
		int arg2 = 0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if(argc == 3)
		{
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
		}
		int name_state = arg0 == true?1:0;
		int blood_state = arg1 == true?1:0;
		cobj->showNameAndBlood(name_state,blood_state,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }else if(argc == 4){
		bool arg0;
		bool arg1;
		int arg2 = 0;
		bool arg3;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		int name_state = arg0 == true?1:0;
		int blood_state = arg1 == true?1:0;
		cobj->showNameAndBlood(name_state,blood_state,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "showNameAndBlood",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->isAlive();
		if (ret){
				tolua_pushboolean(tolua_S,(int)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAlive",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getNameLabel(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		Node* ret = cobj->getNameLabel();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNameLabel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getTitleLabel(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		Node* ret = cobj->getTitleLabel();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTitleLabel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getTimeLabel(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		Node* ret = cobj->getTimeLabel();
		do {
				if (NULL != ret){
				
					object_to_luaval<Label>(tolua_S, "cc.Label",(Label*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTimeLabel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getShowHeight(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getShowHeight();
		if (ret)
		{
			tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
		{
			lua_pushnil(tolua_S);
		}
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getShowHeight",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_addMoveTarget(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (1 == argc)
	{
		Point arg0;
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		cobj->addMoveTarget(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_stopMoveAction(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (0 == argc)
	{
		cobj->stopMoveAction();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (1 == argc)
	{
		bool arg0;
		if (!ok) { 
			return 0; 
		}
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		cobj->stopMoveAction(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_setNameSize(lua_State* tolua_S)
{
	int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
    if (1 == argc)
    {
        cocos2d::Size size;
        ok &= luaval_to_size(tolua_S, 2, &size, "SpriteMonster:setNameSize");
        if (!ok) return 0;
		cobj->setNameSize(size);
        lua_settop(tolua_S, 1);
        return 1;
    }
    return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_getNameSize(lua_State* tolua_S)
{
	int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"", nullptr);
            return 0;
        }
		const cocos2d::Size& ret = cobj->getNameSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getNameSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_registerSetLocalZOrderCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerSetLocalZOrderCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetLocalZOrderCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_removeSetLocalZOrderCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetLocalZOrderCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_registerSetPositionCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerSetPositionCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetPositionCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_removeSetPositionCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetPositionCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_registerUpdateTopHeadPosCb(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerUpdateTopHeadPosCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerUpdateTopHeadPosCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_removeUpdateTopHeadPosCb(lua_State* tolua_S)
{
	int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeUpdateTopHeadPosCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteMonster_registerFootprintsCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerFootprintsCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerFootprintsCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteMonster_removeFootprintsCb(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->removeFootprintsCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setFootprintsGap(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setFootprintsGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFootprintsGap",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getFootprintsGap(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		float ret = cobj->getFootprintsGap();
		if (ret){
			tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFootprintsGap",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_setFootprintsOpen(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setFootprintsOpen(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFootprintsOpen",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteBase_getFootprintsOpen(lua_State* tolua_S)
{
	int argc = 0;
	SpriteMonster* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getFootprintsOpen();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFootprintsOpen",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_SpriteMonster(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteMonster");
	tolua_cclass(tolua_S,"SpriteMonster","SpriteMonster","SpriteBase",NULL);
		tolua_beginmodule(tolua_S,"SpriteMonster");
			tolua_function(tolua_S, "create", lua_SpriteMonster_create);
			tolua_function(tolua_S, "setMonsterId", lua_SpriteMonster_setMonsterId);
			tolua_function(tolua_S, "getMonsterId", lua_SpriteMonster_getMonsterId);
			tolua_function(tolua_S, "setBloodType", lua_SpriteMonster_setBloodType);
			tolua_function(tolua_S, "setNeedSyncPosToServer", lua_SpriteMonster_setNeedSyncPosToServer);
			tolua_function(tolua_S, "setBloodVisible", lua_SpriteMonster_setBloodVisible);
			tolua_function(tolua_S, "setSpeed", lua_SpriteMonster_setSpeed);
			tolua_function(tolua_S, "setShowBloodAnim", lua_SpriteMonster_setShowBloodAnim);
			tolua_function(tolua_S, "setHP", lua_SpriteBase_setHP);
			tolua_function(tolua_S, "getHP", lua_SpriteBase_getHP);
			tolua_function(tolua_S, "isMove", lua_SpriteMonster_isMove);
			tolua_function(tolua_S, "setMaxHP", lua_SpriteMonster_setMaxHP);
			tolua_function(tolua_S, "getMaxHP", lua_SpriteMonster_getMaxHP);
			tolua_function(tolua_S, "setAttack", lua_SpriteMonster_setAttack);
			tolua_function(tolua_S, "getAttack", lua_SpriteMonster_getAttack);
			tolua_function(tolua_S, "setName", lua_SpriteMonster_setName);
			tolua_function(tolua_S, "getName", lua_SpriteMonster_getName);
			tolua_function(tolua_S, "setLevel", lua_SpriteMonster_setLevel);
			tolua_function(tolua_S, "getLevel", lua_SpriteMonster_getLevel);
			tolua_function(tolua_S, "subBlood", lua_SpriteMonster_subBlood);
			tolua_function(tolua_S, "showNameAndBlood", lua_SpriteMonster_showNameAndBlood);
			tolua_function(tolua_S, "setNameAndBloodShow", lua_SpriteMonster_setNameAndBloodShow);
			tolua_function(tolua_S, "isAlive", lua_SpriteMonster_isAlive);
			tolua_function(tolua_S, "getNameLabel", lua_SpriteMonster_getNameLabel);
			tolua_function(tolua_S, "getTitleLabel", lua_SpriteMonster_getTitleLabel);
			tolua_function(tolua_S, "getTimeLabel", lua_SpriteMonster_getTimeLabel);
		
			tolua_function(tolua_S, "getShowHeight",              lua_SpriteMonster_getShowHeight);
			tolua_function(tolua_S, "setNameSize",                lua_SpriteMonster_setNameSize);
			tolua_function(tolua_S, "getNameSize",                lua_SpriteMonster_getNameSize);
			tolua_function(tolua_S, "registerSetLocalZOrderCb",   lua_SpriteMonster_registerSetLocalZOrderCb);
			tolua_function(tolua_S, "removeSetLocalZOrderCb",     lua_SpriteMonster_removeSetLocalZOrderCb);
			tolua_function(tolua_S, "registerSetPositionCb",      lua_SpriteMonster_registerSetPositionCb);
			tolua_function(tolua_S, "removeSetPositionCb",        lua_SpriteMonster_removeSetPositionCb);
			tolua_function(tolua_S, "registerUpdateTopHeadPosCb", lua_SpriteMonster_registerUpdateTopHeadPosCb);
			tolua_function(tolua_S, "removeUpdateTopHeadPosCb",   lua_SpriteMonster_removeUpdateTopHeadPosCb);
			tolua_function(tolua_S, "registerFootprintsCb", lua_SpriteMonster_registerFootprintsCb);
			tolua_function(tolua_S, "removeFootprintsCb",   lua_SpriteMonster_removeFootprintsCb);
			tolua_function(tolua_S, "addMoveTarget",   lua_SpriteMonster_addMoveTarget);
			tolua_function(tolua_S, "stopMoveAction",   lua_SpriteMonster_stopMoveAction);
			tolua_function(tolua_S, "setFootprintsGap",   lua_SpriteBase_setFootprintsGap);
			tolua_function(tolua_S, "getFootprintsGap",   lua_SpriteBase_getFootprintsGap);
			tolua_function(tolua_S, "setFootprintsOpen",   lua_SpriteBase_setFootprintsOpen);
			tolua_function(tolua_S, "getFootprintsOpen",   lua_SpriteBase_getFootprintsOpen);
		
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_SpritePlayer_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			SpritePlayer* ret = SpritePlayer::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<SpritePlayer>(tolua_S, "SpritePlayer",(SpritePlayer*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		std::string arg0;
		std::string arg1;
		bool arg2;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 4, &arg2);
			if (!ok) { break; }
			SpritePlayer* ret = SpritePlayer::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
				
					object_to_luaval<SpritePlayer>(tolua_S, "SpritePlayer",(SpritePlayer*)ret);
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
int lua_SpritePlayer_setPetOnRide(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setPetOnRide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_SpritePlayer_setPetOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_getPetOnRide(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getPetOnRide();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_SpritePlayer_getPetOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setWeaponEffectPath(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		std::string arg0 ;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setWeaponEffectPath(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWeaponEffectPath",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setWeaponEffectPosOffset(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 9) 
	{
		int arg0;
		Vec2 arg1;
		Vec2 arg2;
		Vec2 arg3;
		Vec2 arg4;
		Vec2 arg5;
		Vec2 arg6;
		Vec2 arg7;
		Vec2 arg8;
	
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 10,&arg8);
		if (!ok) { return 0; }
	
		cobj->setWeaponEffectPosOffset(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWeaponEffectPosOffset",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setSuddenSpeed(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSuddenSpeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSuddenSpeed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setSpeedFloatPercent(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSpeedFloatPercent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSpeedFloatPercent",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_getSpeedFloatPercent(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		float ret = cobj->getSpeedFloatPercent();
		tolua_pushnumber(tolua_S,(float)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpeedFloatPercent",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setSex(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getSex(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getSex();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_setConveyState(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setConveyState(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setConveyState",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getConveyState(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getConveyState();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getConveyState",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_setSchool(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSchool(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSchool",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getSchool(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getSchool();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSchool",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_resetSpeed(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		if(cobj->resetSpeed)
			cobj->resetSpeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetSpeed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		double speed = cobj->getSpeed();
		tolua_pushnumber(tolua_S, (lua_Number)speed);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpeed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_suddenToThePos(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		int arg0 ;
		Point arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->suddenToThePos(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		int arg0 ;
		Point arg1;
		double arg2;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->suddenToThePos(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "suddenToThePos",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_insertActionChild(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		SpriteBase *arg0;
		int arg1;
		int arg2;
		arg0 = (SpriteBase*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->insertActionChild(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertActionChild",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_removeActionChild(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		SpriteBase *arg0;
		arg0 = (SpriteBase*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		cobj->removeActionChild(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeActionChild",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_removeActionChildByTag(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->removeActionChildByTag(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeActionChildByTag",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getLeftTime(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		float ret = cobj->getLeftTime();
		tolua_pushnumber(tolua_S,(float)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLeftTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_setActive(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setActive(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActive",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_getActive(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool ret = cobj->getActive();
		tolua_pushboolean(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActive",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setUnToAttack(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setUnToAttack(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUnToAttack",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_setOnRideWithChildren(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setOnRideWithChildren(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnRideWithChildren",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_setRoleId(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		std::string arg0 ;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setRoleId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRoleId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_playerAttackToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		bool ret = cobj->playerAttackToPos((float)arg0,arg1,arg2,arg3);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 5) 
	{
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		bool arg4;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		bool ret = cobj->playerAttackToPos((float)arg0,arg1,arg2,arg3,arg4);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playerAttackToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_hideAllActionChild(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->hideAllActionChild(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_showAllActionChild(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->showAllActionChild(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_playActionWithChildren(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 5) 
	{
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->playActionWithChildren(arg0, (Commen_ActionToDo)arg1, (Commen_Direction)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playActionWithChildren",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_registerPlayActionWithChildrenCb(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerPlayActionWithChildrenCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerPlayActionWithChildrenCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_removePlayActionWithChildrenCb(lua_State* tolua_S)
{
	int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removePlayActionWithChildrenCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_registerGotoDeathCb(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerGotoDeathCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerGotoDeathCb",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_removeGotoDeathCb(lua_State* tolua_S)
{
	int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeGotoDeathCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_registerSetActorVisibleCd(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerSetActorVisibleCd(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSetActorVisibleCd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_removeSetActorVisibleCd(lua_State* tolua_S)
{
	int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeSetActorVisibleCd();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpritePlayer_registerMoveKeyPosCb(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerMoveKeyPosCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerMoveKeyPosCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_removeMoveKeyPosCb(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	cobj->removeMoveKeyPosCb();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_changeRePlayTypeAndResId(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
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
		bool ok = false;
		int arg0;
		std::string arg1;
		ok =  luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok =  luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->changeRePlayTypeAndResId((SpriteType)arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changeRePlayTypeAndResId",argc, 2);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpritePlayer_addWeaponEffect(lua_State* tolua_S)
{
	int argc = 0;
	SpritePlayer* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		bool ok = false;
		int arg0;
		double arg1;
		double arg2;
		ok =  luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok =  luaval_to_number(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok =  luaval_to_number(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->addWeaponEffect(arg0, (float)arg1, (float)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addWeaponEffect",argc, 3);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_SpritePlayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpritePlayer");
	tolua_cclass(tolua_S,"SpritePlayer","SpritePlayer","SpriteMonster",NULL);
		tolua_beginmodule(tolua_S,"SpritePlayer");
			tolua_function(tolua_S, "create", lua_SpritePlayer_create);
			tolua_function(tolua_S, "setSpeedFloatPercent", lua_SpritePlayer_setSpeedFloatPercent);
			tolua_function(tolua_S, "getSpeedFloatPercent", lua_SpritePlayer_getSpeedFloatPercent);
			tolua_function(tolua_S, "setSuddenSpeed", lua_SpritePlayer_setSuddenSpeed);
			tolua_function(tolua_S, "setWeaponEffectPath", lua_SpritePlayer_setWeaponEffectPath);
			tolua_function(tolua_S, "setWeaponEffectPosOffset", lua_SpritePlayer_setWeaponEffectPosOffset);
			tolua_function(tolua_S, "setPetOnRide", lua_SpritePlayer_setPetOnRide);
			tolua_function(tolua_S, "getPetOnRide", lua_SpritePlayer_getPetOnRide);
			tolua_function(tolua_S, "setSex", lua_SpritePlayer_setSex);
			tolua_function(tolua_S, "getSex", lua_SpritePlayer_getSex);
			tolua_function(tolua_S, "setConveyState", lua_SpritePlayer_setConveyState);
			tolua_function(tolua_S, "getConveyState", lua_SpritePlayer_getConveyState);
			tolua_function(tolua_S, "setSchool", lua_SpritePlayer_setSchool);
			tolua_function(tolua_S, "getSchool", lua_SpritePlayer_getSchool);
			tolua_function(tolua_S, "resetSpeed", lua_SpritePlayer_resetSpeed);
			tolua_function(tolua_S, "getSpeed", lua_SpritePlayer_getSpeed);
			tolua_function(tolua_S, "suddenToThePos", lua_SpritePlayer_suddenToThePos);
			tolua_function(tolua_S, "insertActionChild", lua_SpritePlayer_insertActionChild);
			tolua_function(tolua_S, "removeActionChild", lua_SpritePlayer_removeActionChild);
			tolua_function(tolua_S, "removeActionChildByTag", lua_SpritePlayer_removeActionChildByTag);
			tolua_function(tolua_S, "getLeftTime", lua_SpritePlayer_getLeftTime);
			tolua_function(tolua_S, "setActive", lua_SpritePlayer_setActive);
			tolua_function(tolua_S, "getActive", lua_SpritePlayer_getActive);
			tolua_function(tolua_S, "setUnToAttack", lua_SpritePlayer_setUnToAttack);
			tolua_function(tolua_S, "setRoleId", lua_SpritePlayer_setRoleId);
			tolua_function(tolua_S, "setOnRideWithChildren", lua_SpritePlayer_setOnRideWithChildren);
			tolua_function(tolua_S, "playerAttackToPos", lua_SpritePlayer_playerAttackToPos);
			tolua_function(tolua_S, "hideAllActionChild", lua_SpritePlayer_hideAllActionChild);
			tolua_function(tolua_S, "showAllActionChild", lua_SpritePlayer_showAllActionChild);
			tolua_function(tolua_S, "playActionWithChildren", lua_SpritePlayer_playActionWithChildren);
			tolua_function(tolua_S, "registerPlayActionWithChildrenCb", lua_SpritePlayer_registerPlayActionWithChildrenCb);
			tolua_function(tolua_S, "removePlayActionWithChildrenCb",   lua_SpritePlayer_removePlayActionWithChildrenCb);
			tolua_function(tolua_S, "registerGotoDeathCb",              lua_SpritePlayer_registerGotoDeathCb);
			tolua_function(tolua_S, "removeGotoDeathCb",                lua_SpritePlayer_removeGotoDeathCb);
			tolua_function(tolua_S, "registerSetActorVisibleCd",        lua_SpritePlayer_registerSetActorVisibleCd);
			tolua_function(tolua_S, "removeSetActorVisibleCd",          lua_SpritePlayer_removeSetActorVisibleCd);
			tolua_function(tolua_S, "registerMoveKeyPosCb",				lua_SpritePlayer_registerMoveKeyPosCb);
			tolua_function(tolua_S, "removeMoveKeyPosCb",               lua_SpritePlayer_removeMoveKeyPosCb);
			tolua_function(tolua_S, "changeRePlayTypeAndResId",         lua_SpritePlayer_changeRePlayTypeAndResId);
			tolua_function(tolua_S, "addWeaponEffect",                  lua_SpritePlayer_addWeaponEffect);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_GraySprite_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			GraySprite* ret = GraySprite::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<GraySprite>(tolua_S, "GraySprite",(GraySprite*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 0)
	{
        do 
		{
			GraySprite* ret = GraySprite::create();
			do {
				if (NULL != ret){
				
					object_to_luaval<GraySprite>(tolua_S, "GraySprite",(GraySprite*)ret);
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
int lua_GraySprite_addColorGray(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->addColorGray();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addColorGray",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_GraySprite_removeColorGray(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->removeColorGray();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeColorGray",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_GraySprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GraySprite");
	tolua_cclass(tolua_S,"GraySprite","GraySprite","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"GraySprite");
			tolua_function(tolua_S, "create", lua_GraySprite_create);
			tolua_function(tolua_S, "addColorGray", lua_GraySprite_addColorGray);
			tolua_function(tolua_S, "removeColorGray", lua_GraySprite_removeColorGray);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_SpriteBlur_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"SpriteBlur",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			SpriteBlur* ret = SpriteBlur::create(arg0.c_str());
			do {
				if (NULL != ret){
				
					object_to_luaval<SpriteBlur>(tolua_S, "SpriteBlur",(SpriteBlur*)ret);
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
int lua_SpriteBlur_setBlurRadius(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBlur* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBlur",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBlur*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBlur:setBlurRadius");
            if (!ok) { break; }
            cobj->setBlurRadius(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBlurRadius",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SpriteBlur_setBlurSampleNum(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBlur* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBlur",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SpriteBlur*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBlur:setBlurSampleNum");
            if (!ok) { break; }
            cobj->setBlurSampleNum(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBlurSampleNum",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_SpriteBlur(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteBlur");
	tolua_cclass(tolua_S,"SpriteBlur","SpriteBlur","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"SpriteBlur");
			tolua_function(tolua_S, "create", lua_SpriteBlur_create);
			tolua_function(tolua_S, "setBlurRadius", lua_SpriteBlur_setBlurRadius);
			tolua_function(tolua_S, "setBlurSampleNum", lua_SpriteBlur_setBlurSampleNum);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_TouchSprite_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			TouchSprite* ret = TouchSprite::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		std::string arg0;
		int arg1 =  toluafix_ref_function(tolua_S,3,0);
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			TouchSprite* ret = TouchSprite::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->registerTouchUpHandler(arg1);
				
					object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		std::string arg0;
		int arg2;
		int arg1 =  toluafix_ref_function(tolua_S,3,0);
		do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2); 
			if (!ok) { break; }
			TouchSprite* ret = TouchSprite::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->registerTouchUpHandler(arg1);
					ret->setTouchType(arg2);
				
					object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
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
int lua_TouchSprite_onClick(lua_State* tolua_S)
{
	int argc = 0;
	TouchSprite* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->onClick();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onClick",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_TouchSprite_registerTouchDownHandler(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerTouchDownHandler(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerTouchDownHandler",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_TouchSprite_registerTouchUpHandler(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerTouchUpHandler(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerTouchUpHandler",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_TouchSprite_setTouchEnable(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setTouchEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_TouchSprite_setSwallowTouch(lua_State* tolua_S)
{
	int argc = 0;
	TouchSprite* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setSwallowTouch(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSwallowTouch",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_TouchSprite_setEnable(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_TouchSprite_setSelectAction(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setSelectAction(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectAction",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_TouchSprite_setUnSelectAction(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);
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
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setUnSelectAction(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUnSelectAction",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_TouchSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TouchSprite");
	tolua_cclass(tolua_S,"TouchSprite","TouchSprite","GraySprite",NULL);
		tolua_beginmodule(tolua_S,"TouchSprite");
			tolua_function(tolua_S, "create", lua_TouchSprite_create);
			tolua_function(tolua_S, "registerTouchDownHandler", lua_TouchSprite_registerTouchDownHandler);
			tolua_function(tolua_S, "onClick", lua_TouchSprite_onClick);
			tolua_function(tolua_S, "registerTouchUpHandler", lua_TouchSprite_registerTouchUpHandler);
			tolua_function(tolua_S, "setTouchEnable", lua_TouchSprite_setTouchEnable);
			tolua_function(tolua_S, "setSwallowTouch", lua_TouchSprite_setSwallowTouch);
			tolua_function(tolua_S, "setEnable", lua_TouchSprite_setEnable);
			tolua_function(tolua_S, "setSelectAction", lua_TouchSprite_setSelectAction);
			tolua_function(tolua_S, "setUnSelectAction", lua_TouchSprite_setUnSelectAction);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_Touch9Sprite_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 2)
	{
		const char* arg0 = tolua_tostring(tolua_S,2,0);
		Size arg1;
        do 
		{
			ok &=  luaval_to_size(tolua_S,3,&arg1);
			if (!ok) { break; }
			Touch9Sprite* ret = Touch9Sprite::create(arg0,arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<Touch9Sprite>(tolua_S, "Touch9Sprite",(Touch9Sprite*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		const char* arg0 = tolua_tostring(tolua_S,2,0);
		Size arg1;
		int arg2 =  toluafix_ref_function(tolua_S,4,0);
        do 
		{
			ok &=  luaval_to_size(tolua_S,3,&arg1);
			if (!ok) { break; }
			Touch9Sprite* ret = Touch9Sprite::create(arg0,arg1);
			do {
				if (NULL != ret && arg2){
					ret->registerTouchUpHandler(arg2);
				
					object_to_luaval<Touch9Sprite>(tolua_S, "Touch9Sprite",(Touch9Sprite*)ret);
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
int lua_Touch9Sprite_registerTouchDownHandler(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerTouchDownHandler(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerTouchDownHandler",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Touch9Sprite_registerTouchUpHandler(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);
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
		cobj->registerTouchUpHandler(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerTouchUpHandler",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Touch9Sprite_setTouchEnable(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setTouchEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Touch9Sprite_setActionEnable(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);
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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setActionEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActionEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_Touch9Sprite_setViewRect(lua_State* tolua_S)
{
	int argc = 0;
	Touch9Sprite* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);
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
		cocos2d::Rect arg0;
		ok &= luaval_to_rect(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setViewRect(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setViewRect",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_Touch9Sprite(lua_State* tolua_S)
{       
    tolua_usertype(tolua_S,"Touch9Sprite");
	tolua_cclass(tolua_S,"Touch9Sprite","Touch9Sprite","ccui.Scale9Sprite",NULL);
		tolua_beginmodule(tolua_S,"Touch9Sprite");
			tolua_function(tolua_S, "create", lua_Touch9Sprite_create);
			tolua_function(tolua_S, "registerTouchDownHandler", lua_Touch9Sprite_registerTouchDownHandler);
			tolua_function(tolua_S, "registerTouchUpHandler", lua_Touch9Sprite_registerTouchUpHandler);
			tolua_function(tolua_S, "setTouchEnable", lua_Touch9Sprite_setTouchEnable);
			tolua_function(tolua_S, "setActionEnable", lua_Touch9Sprite_setActionEnable);
			tolua_function(tolua_S, "setViewRect", lua_Touch9Sprite_setViewRect);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_SpriteGuard_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"SpriteGuard",0,&tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
		do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			SpriteGuard* ret = SpriteGuard::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<SpriteGuard>(tolua_S, "SpriteGuard",(SpriteGuard*)ret);
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
int lua_SpriteGuard_setAutoInfo(lua_State* tolua_S)
{
	int argc = 0;
	SpriteGuard* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteGuard",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteGuard*)tolua_tousertype(tolua_S,1,0);
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
		Vec2 arg0;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setAutoInfo(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 2)
	{
		Vec2 arg0;
		int arg1;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			cobj->setAutoInfo(arg0, (float)arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 3)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			cobj->setAutoInfo(arg0, (float)arg1, (float)arg2);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 4)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		int arg3;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 5, &arg3);
			if (!ok) { break; }
			cobj->setAutoInfo(arg0, (float)arg1, (float)arg2, (float) arg3);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 5)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 5, &arg3);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 6, &arg4);
			if (!ok) { break; }
			cobj->setAutoInfo(arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setAutoInfo", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_SpriteGuard_standed(lua_State* tolua_S)
{
	int argc = 0;
	SpriteGuard* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"SpriteGuard",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (SpriteGuard*)tolua_tousertype(tolua_S,1,0);
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
		cobj->standed();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_SpriteGuard(lua_State* tolua_S)
{       
	tolua_usertype(tolua_S,"SpriteGuard");
	tolua_cclass(tolua_S,"SpriteGuard","SpriteGuard","SpriteBase",NULL);
	tolua_beginmodule(tolua_S,"SpriteGuard");
	tolua_function(tolua_S, "create", lua_SpriteGuard_create);
	tolua_function(tolua_S, "setAutoInfo", lua_SpriteGuard_setAutoInfo);
	tolua_function(tolua_S, "standed", lua_SpriteGuard_standed);
	tolua_endmodule(tolua_S);
	return 1;
}
#endif    