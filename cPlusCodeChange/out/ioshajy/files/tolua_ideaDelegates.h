#ifndef __TOLUA_MENUBUTTON_H__
#define __TOLUA_MENUBUTTON_H__
#include "tolua++.h"
#include "ideaDelegates.h"
#include "LuaBasicConversions.h"
int lua_ideaDelegates_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"ideaDelegates",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ideaDelegates* ret = ideaDelegates::create(arg0);
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"ideaDelegates");
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
int lua_ideaDelegates_setpassedDeclaringPurposes(lua_State* tolua_S)
{
    int argc = 0;
    ideaDelegates* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ideaDelegates",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ideaDelegates*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ideaDelegates_setpassedDeclaringPurposes'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpassedDeclaringPurposes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpassedDeclaringPurposes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ideaDelegates_setpassedDeclaringPurposes'.",&tolua_err);
#endif
    return 0;
}
int lua_ideaDelegates_setcodeFullyException(lua_State* tolua_S)
{
    int argc = 0;
    ideaDelegates* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ideaDelegates",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ideaDelegates*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ideaDelegates_setcodeFullyException'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setcodeFullyException(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setcodeFullyException",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ideaDelegates_setcodeFullyException'.",&tolua_err);
#endif
    return 0;
}
int lua_ideaDelegates_setassumeManageLittle(lua_State* tolua_S)
{
    int argc = 0;
    ideaDelegates* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ideaDelegates",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ideaDelegates*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ideaDelegates_setassumeManageLittle'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setassumeManageLittle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setassumeManageLittle",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ideaDelegates_setassumeManageLittle'.",&tolua_err);
#endif
    return 0;
}
int lua_ideaDelegates_setImages(lua_State* tolua_S)
{
    int argc = 0;
    ideaDelegates* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ideaDelegates",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ideaDelegates*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ideaDelegates_setImages'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setImages(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setImages",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ideaDelegates_setImages'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_ideaDelegates(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ideaDelegates");
	tolua_cclass(tolua_S,"ideaDelegates","ideaDelegates","cc.MenuItemImage",NULL);
		tolua_beginmodule(tolua_S,"ideaDelegates");
			tolua_function(tolua_S, "create", lua_ideaDelegates_create);
			tolua_function(tolua_S, "setImages", lua_ideaDelegates_setImages);
			tolua_function(tolua_S, "setpassedDeclaringPurposes", lua_ideaDelegates_setpassedDeclaringPurposes);
			tolua_function(tolua_S, "setcodeFullyException", lua_ideaDelegates_setcodeFullyException);
			tolua_function(tolua_S, "setassumeManageLittle", lua_ideaDelegates_setassumeManageLittle);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    