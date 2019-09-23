#ifndef __TOLUA_SKILL_CTRL_H__
#define __TOLUA_SKILL_CTRL_H__
#include "tolua++.h"
#include "applicablePropagatesStore.h"
#include "LuaBasicConversions.h"
int lua_applicablePropagatesStore_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			applicablePropagatesStore* ret = applicablePropagatesStore::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"applicablePropagatesStore");
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
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_create'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_setHero(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_setHero'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		assumeApproachEmbodies* pobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,2,0);
        if(!pobj) { return 0; }
		cobj->setHero(pobj);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHero",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_setHero'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_setRight(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_setRight'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_setRight'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_setNextPage(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_setRight'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setshakingMakingColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNextPage",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_setNextPage'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_getrealizingMakingEnough(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_getrealizingMakingEnough'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		ideaDelegates* ret = cobj->getrealizingMakingEnough();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"ideaDelegates");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getrealizingMakingEnough",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_getrealizingMakingEnough'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_getcurrentlyDeclaration(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_getcurrentlyDeclaration'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getcurrentlyDeclaration();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"cc.Node");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getcurrentlyDeclaration",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_getcurrentlyDeclaration'.",&tolua_err);
#endif
    return 0;
}
int lua_applicablePropagatesStore_getshownPointerPassed(lua_State* tolua_S)
{
    int argc = 0;
    applicablePropagatesStore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"applicablePropagatesStore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (applicablePropagatesStore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_applicablePropagatesStore_getcurrentlyDeclaration'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getshownPointerPassed();
		tolua_pushnumber(tolua_S,ret);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getshownPointerPassed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_applicablePropagatesStore_getshownPointerPassed'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_applicablePropagatesStore(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"applicablePropagatesStore");
	tolua_cclass(tolua_S,"applicablePropagatesStore","applicablePropagatesStore","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"applicablePropagatesStore");
			tolua_function(tolua_S, "create", lua_applicablePropagatesStore_create);
			tolua_function(tolua_S, "setHero", lua_applicablePropagatesStore_setHero);
			tolua_function(tolua_S, "setRight", lua_applicablePropagatesStore_setRight);
			tolua_function(tolua_S, "getrealizingMakingEnough", lua_applicablePropagatesStore_getrealizingMakingEnough);
			tolua_function(tolua_S, "getcurrentlyDeclaration", lua_applicablePropagatesStore_getcurrentlyDeclaration);
			tolua_function(tolua_S, "setshakingMakingColor", lua_applicablePropagatesStore_setNextPage);
			tolua_function(tolua_S, "getshownPointerPassed", lua_applicablePropagatesStore_getshownPointerPassed);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    