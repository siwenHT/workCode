#ifndef __TOLUA_SKILL_CTRL_H__
#define __TOLUA_SKILL_CTRL_H__
#include "tolua++.h"
#include "SkillCtrl.h"
#include "LuaBasicConversions.h"
int lua_SkillCtrl_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			SkillCtrl* ret = SkillCtrl::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"SkillCtrl");
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
int lua_SkillCtrl_setHero(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		SpritePlayer* pobj = (SpritePlayer*)tolua_tousertype(tolua_S,2,0);
        if(!pobj) { return 0; }
		cobj->setHero(pobj);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHero",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SkillCtrl_setRight(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setRight(arg0);
		lua_settop(tolua_S, 1);
		return 1;;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRight",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SkillCtrl_setNextPage(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		cobj->setPageByIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNextPage",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SkillCtrl_getCenterItem(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		MenuButton* ret = cobj->getCenterItem();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"MenuButton");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCenterItem",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SkillCtrl_getCenterNode(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		Node* ret = cobj->getCenterNode();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"cc.Node");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCenterNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_SkillCtrl_getPageIndex(lua_State* tolua_S)
{
    int argc = 0;
    SkillCtrl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SkillCtrl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SkillCtrl*)tolua_tousertype(tolua_S,1,0);
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
		int ret = cobj->getPageIndex();
		tolua_pushnumber(tolua_S,ret);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPageIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_SkillCtrl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SkillCtrl");
	tolua_cclass(tolua_S,"SkillCtrl","SkillCtrl","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"SkillCtrl");
			tolua_function(tolua_S, "create", lua_SkillCtrl_create);
			tolua_function(tolua_S, "setHero", lua_SkillCtrl_setHero);
			tolua_function(tolua_S, "setRight", lua_SkillCtrl_setRight);
			tolua_function(tolua_S, "getCenterItem", lua_SkillCtrl_getCenterItem);
			tolua_function(tolua_S, "getCenterNode", lua_SkillCtrl_getCenterNode);
			tolua_function(tolua_S, "setPageByIndex", lua_SkillCtrl_setNextPage);
			tolua_function(tolua_S, "getPageIndex", lua_SkillCtrl_getPageIndex);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    