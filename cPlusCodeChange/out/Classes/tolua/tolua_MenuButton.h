#ifndef __TOLUA_MENUBUTTON_H__
#define __TOLUA_MENUBUTTON_H__
#include "tolua++.h"
#include "MenuButton.h"
#include "LuaBasicConversions.h"
int lua_MenuButton_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			MenuButton* ret = MenuButton::create(arg0);
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"MenuButton");
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
int lua_MenuButton_setSmallToBigMode(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MenuButton*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setSmallToBigMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSmallToBigMode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_MenuButton_setSelectAction(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MenuButton*)tolua_tousertype(tolua_S,1,0);
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
int lua_MenuButton_setUnSelectAction(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MenuButton*)tolua_tousertype(tolua_S,1,0);
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
int lua_MenuButton_setImages(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MenuButton*)tolua_tousertype(tolua_S,1,0);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_MenuButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MenuButton");
	tolua_cclass(tolua_S,"MenuButton","MenuButton","cc.MenuItemImage",NULL);
		tolua_beginmodule(tolua_S,"MenuButton");
			tolua_function(tolua_S, "create", lua_MenuButton_create);
			tolua_function(tolua_S, "setImages", lua_MenuButton_setImages);
			tolua_function(tolua_S, "setSmallToBigMode", lua_MenuButton_setSmallToBigMode);
			tolua_function(tolua_S, "setSelectAction", lua_MenuButton_setSelectAction);
			tolua_function(tolua_S, "setUnSelectAction", lua_MenuButton_setUnSelectAction);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    