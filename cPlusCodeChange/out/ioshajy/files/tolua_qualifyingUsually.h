#ifndef __TOLUA_MAKENUMBERS_H__
#define __TOLUA_MAKENUMBERS_H__
#include "tolua++.h"
#include "qualifyingUsually.h"
#include "LuaBasicConversions.h"
int lua_qualifyingUsually_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"qualifyingUsually",0,&tolua_err)) goto tolua_lerror;
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
			qualifyingUsually* ret = qualifyingUsually::create(arg0,arg1,arg2);
			do {
				if (NULL != ret){
					object_to_luaval<qualifyingUsually>(tolua_S, "qualifyingUsually",(qualifyingUsually*)ret);
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
			qualifyingUsually* ret = qualifyingUsually::create(arg0,arg1,arg2,arg3);
			do {
				if (NULL != ret){
					object_to_luaval<qualifyingUsually>(tolua_S, "qualifyingUsually",(qualifyingUsually*)ret);
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
			qualifyingUsually* ret = qualifyingUsually::create(arg0,arg1,arg2,arg3,arg4);
			do {
				if (NULL != ret){
					object_to_luaval<qualifyingUsually>(tolua_S, "qualifyingUsually",(qualifyingUsually*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_qualifyingUsually_create'.",&tolua_err);
#endif
    return 0;
}
int lua_qualifyingUsually_buildsFactorial(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"qualifyingUsually",0,&tolua_err)) goto tolua_lerror;
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
			qualifyingUsually* ret = qualifyingUsually::buildsFactorial(arg0,arg1,arg2);
			do {
				if (NULL != ret){
					object_to_luaval<qualifyingUsually>(tolua_S, "qualifyingUsually",(qualifyingUsually*)ret);
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
			qualifyingUsually* ret = qualifyingUsually::buildsFactorial(arg0,arg1,arg2,arg3);
			do {
				if (NULL != ret){
					object_to_luaval<qualifyingUsually>(tolua_S, "qualifyingUsually",(qualifyingUsually*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_qualifyingUsually_create'.",&tolua_err);
#endif
    return 0;
}
int lua_qualifyingUsually_setmajorSupplyCoupled(lua_State* tolua_S)
{
	qualifyingUsually* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"qualifyingUsually",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (qualifyingUsually*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_qualifyingUsually_setmajorSupplyCoupled'", NULL);
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
			cobj->setmajorSupplyCoupled(arg1,10000);
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
			cobj->setmajorSupplyCoupled(arg1,arg2);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setmajorSupplyCoupled",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_qualifyingUsually_setmajorSupplyCoupled'.",&tolua_err);
#endif
	return 0;
}
int lua_qualifyingUsually_getWidth(lua_State* tolua_S)
{
	qualifyingUsually* cobj = nullptr;
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"qualifyingUsually",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (qualifyingUsually*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_qualifyingUsually_getWidth'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_qualifyingUsually_getWidth'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_qualifyingUsually(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"qualifyingUsually");
	tolua_cclass(tolua_S,"qualifyingUsually","qualifyingUsually","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"qualifyingUsually");
			tolua_function(tolua_S, "create", lua_qualifyingUsually_create);
			tolua_function(tolua_S, "buildsFactorial", lua_qualifyingUsually_buildsFactorial);
			tolua_function(tolua_S, "setmajorSupplyCoupled", lua_qualifyingUsually_setmajorSupplyCoupled);
			tolua_function(tolua_S, "getWidth", lua_qualifyingUsually_getWidth);
		
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    