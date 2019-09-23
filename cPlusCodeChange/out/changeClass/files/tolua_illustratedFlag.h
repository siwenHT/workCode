#ifndef __TOLUA_ASYNCFILEOP_H__
#define __TOLUA_ASYNCFILEOP_H__
#include "tolua++.h"
#include "illustratedFlag.h"
#include "LuaBasicConversions.h"
int lua_illustratedFlag_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"illustratedFlag",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			illustratedFlag* ret = illustratedFlag::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<illustratedFlag>(tolua_S, "illustratedFlag",(illustratedFlag*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustratedFlag_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_illustratedFlag_write(lua_State* tolua_S)
{
    int argc = 0;
    illustratedFlag* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustratedFlag",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustratedFlag*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustratedFlag_write'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 3)
	{
		do 
		{
			const char* arg0;
			const char* arg1;
			int arg2;
			arg0 = tolua_tostring(tolua_S,2,0);
			arg1 = tolua_tostring(tolua_S,3,0);
			arg2= toluafix_ref_function(tolua_S, 4,0);
			cobj->write(arg0 ,arg1 , arg2);
		
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "write",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustratedFlag_write'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_illustratedFlag(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"illustratedFlag");
	tolua_cclass(tolua_S,"illustratedFlag","illustratedFlag","cc.Layer",NULL);
		tolua_beginmodule(tolua_S,"illustratedFlag");
			tolua_function(tolua_S, "getInstance", lua_illustratedFlag_getInstance);
			tolua_function(tolua_S, "write", lua_illustratedFlag_write);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    