#ifndef __TOLUA_MAKENUMBERS_H__
#define __TOLUA_MAKENUMBERS_H__

#include "tolua++.h"
#include "MakeNumbers.h"
#include "LuaBasicConversions.h"

/* method: create of class  MakeNumbers */
int lua_MakeNumbers_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 3)
	{
        do 
		{
			std::string arg0;
			int arg1,arg2;
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
			MakeNumbers* ret = MakeNumbers::create(arg0,arg1,arg2);
			do {
				if (NULL != ret){
					object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	if(argc == 4)
	{
		do 
		{
			std::string arg0;
			int arg1,arg2;
			bool arg3;
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
			ok &= luaval_to_boolean(tolua_S, 5,&arg3);
			if (!ok) { return 0; }
			MakeNumbers* ret = MakeNumbers::create(arg0,arg1,arg2,arg3);
			do {
				if (NULL != ret){
					object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
				}
				else
					lua_pushnil(tolua_S);
			} while (0);
			return 1;
		} while (0);
	}
	if(argc == 5)
	{
		do 
		{
			std::string arg0;
			int arg1,arg2;
			bool arg3,arg4;
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
			ok &= luaval_to_boolean(tolua_S, 5,&arg3);
			if (!ok) { return 0; }
			ok &= luaval_to_boolean(tolua_S, 6,&arg4);
			if (!ok) { return 0; }
			MakeNumbers* ret = MakeNumbers::create(arg0,arg1,arg2,arg3,arg4);
			do {
				if (NULL != ret){
					object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
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


/* method: createWithSymbol of class  MakeNumbers */
int lua_MakeNumbers_createWithSymbol(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 3)
	{
        do 
		{
			std::string arg0;
			int arg1,arg2;
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
			MakeNumbers* ret = MakeNumbers::createWithSymbol(arg0,arg1,arg2);
			do {
				if (NULL != ret){
					object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	if(argc == 4)
	{
		do 
		{
			std::string arg0;
			int arg1,arg2;
			bool arg3;
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
			ok &= luaval_to_boolean(tolua_S, 5,&arg3);
			if (!ok) { return 0; }
			MakeNumbers* ret = MakeNumbers::createWithSymbol(arg0,arg1,arg2,arg3);
			do {
				if (NULL != ret){
					object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
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

/* method: setAttackNum of class  MakeNumbers */
int lua_MakeNumbers_setAttackNum(lua_State* tolua_S)
{
	MakeNumbers* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (MakeNumbers*)tolua_tousertype(tolua_S,1,0);
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
		do 
		{
			int arg1;
			ok &= luaval_to_int32(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			cobj->setAttackNum(arg1,10000);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	if(argc == 2)
	{
		do 
		{
			int arg1,arg2;
			ok &= luaval_to_int32(tolua_S, 2,&arg1);
			if (!ok) { return 0; }
			ok &= luaval_to_int32(tolua_S, 3,&arg2);
			if (!ok) { return 0; }
			cobj->setAttackNum(arg1,arg2);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setAttackNum",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;

}

/* method: getWidth of class  MakeNumbers */
int lua_MakeNumbers_getWidth(lua_State* tolua_S)
{
	MakeNumbers* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (MakeNumbers*)tolua_tousertype(tolua_S,1,0);
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
		float ret = cobj->getWidth();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getWidth",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_register_cocos2dx_MakeNumbers(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MakeNumbers");
	tolua_cclass(tolua_S,"MakeNumbers","MakeNumbers","cc.Node",NULL);	
		tolua_beginmodule(tolua_S,"MakeNumbers");
			tolua_function(tolua_S, "create", lua_MakeNumbers_create);
			tolua_function(tolua_S, "createWithSymbol", lua_MakeNumbers_createWithSymbol);
			tolua_function(tolua_S, "setAttackNum", lua_MakeNumbers_setAttackNum);
			tolua_function(tolua_S, "getWidth", lua_MakeNumbers_getWidth);
			
		tolua_endmodule(tolua_S);
    return 1;
}

#endif    //__TOLUA_MAKENUMBERS_H__