#ifndef __TOLUA_BTN_CONTAINER_H__
#define __TOLUA_BTN_CONTAINER_H__
#include "tolua++.h"
#include "ableSometimes.h"
#include "LuaBasicConversions.h"
int lua_ableSometimes_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"ableSometimes",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
        do 
		{
			ok &= luaval_to_number(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ableSometimes* ret = ableSometimes::create((float)arg0);
			do {
				if (NULL != ret){
					object_to_luaval<ableSometimes>(tolua_S, "ableSometimes",(ableSometimes*)ret);
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
		double arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ok &= luaval_to_number(tolua_S, 3,&arg1);
			if (!ok) { break; }
			ableSometimes* ret = ableSometimes::create(arg0,(float)arg1);
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"ableSometimes");
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
    tolua_error(tolua_S,"#ferror in function 'lua_ableSometimes_create'.",&tolua_err);
#endif
    return 0;
}
int lua_ableSometimes_createTopContainer(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"ableSometimes",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
        do 
		{
			ok &= luaval_to_number(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ableSometimes* ret = ableSometimes::createTopContainer((float)arg0);
			do {
				if (NULL != ret){
					object_to_luaval<ableSometimes>(tolua_S, "ableSometimes",(ableSometimes*)ret);
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
		double arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ok &= luaval_to_number(tolua_S, 3,&arg1);
			if (!ok) { break; }
			ableSometimes* ret = ableSometimes::createTopContainer(arg0,(float)arg1);
			do {
				if (NULL != ret){
					object_to_luaval<ableSometimes>(tolua_S, "ableSometimes",(ableSometimes*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createTopContainer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ableSometimes_createTopContainer'.",&tolua_err);
#endif
    return 0;
}
int lua_ableSometimes_addItem(lua_State* tolua_S)
{
    int argc = 0;
    ableSometimes* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ableSometimes",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ableSometimes*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ableSometimes_addItem'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		ideaDelegates* ret = (ideaDelegates*)tolua_tousertype(tolua_S,2,0);
		cobj->addItem(ret);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addItem",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ableSometimes_addItem'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_ableSometimes(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ableSometimes");
	tolua_cclass(tolua_S,"ableSometimes","ableSometimes","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"ableSometimes");
			tolua_function(tolua_S, "create", lua_ableSometimes_create);
			tolua_function(tolua_S, "createTopContainer", lua_ableSometimes_createTopContainer);
			tolua_function(tolua_S, "addItem", lua_ableSometimes_addItem);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    