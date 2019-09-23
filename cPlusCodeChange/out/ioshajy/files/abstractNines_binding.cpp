
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
#include "abstractNines.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
USING_NS_YOUNG
static int abstractNines_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"abstractNines",0,&tolua_err)) goto tolua_lerror;
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        if(!ok)
            return 0;
        abstractNines* ret = abstractNines::create();
        object_to_luaval<abstractNines>(tolua_S, "abstractNines",(abstractNines*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'abstractNines_create'.",&tolua_err);
#endif
    return 0;
}
static int abstractNines_setIdx(lua_State* tolua_S)
{
    int argc = 0;
    abstractNines* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"abstractNines",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (abstractNines*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'abstractNines_setIdx'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setIdx(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIdx",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'abstractNines_setIdx'.",&tolua_err);
#endif
    return 0;
}
static int abstractNines_getIdx(lua_State* tolua_S)
{
    int argc = 0;
    abstractNines* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"abstractNines",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (abstractNines*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'abstractNines_getIdx'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        ssize_t ret = cobj->getIdx();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIdx",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'abstractNines_getIdx'.",&tolua_err);
#endif
    return 0;
}
static int abstractNines_reset(lua_State* tolua_S)
{
    int argc = 0;
    abstractNines* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"abstractNines",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (abstractNines*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'abstractNines_reset'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reset();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'abstractNines_reset'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_abstractNines_open (lua_State *tolua_S)
{
	tolua_usertype(tolua_S, "abstractNines");
	tolua_cclass(tolua_S, "abstractNines", "abstractNines", "cc.Node", nullptr);
	tolua_beginmodule(tolua_S, "abstractNines");
		tolua_function(tolua_S, "create", abstractNines_create);
		tolua_function(tolua_S, "setIdx", abstractNines_setIdx);
		tolua_function(tolua_S, "getIdx", abstractNines_getIdx);
		tolua_function(tolua_S, "reset", abstractNines_reset);
	tolua_endmodule(tolua_S);
	return 0;
}
