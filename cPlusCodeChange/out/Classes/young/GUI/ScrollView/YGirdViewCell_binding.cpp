
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
#include "GUI/ScrollView/YGirdViewCell.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
USING_NS_YOUNG
static int YGirdViewCell_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YGirdViewCell",0,&tolua_err)) goto tolua_lerror;
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        if(!ok)
            return 0;
        YGirdViewCell* ret = YGirdViewCell::create();
        object_to_luaval<YGirdViewCell>(tolua_S, "YGirdViewCell",(YGirdViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdViewCell_create'.",&tolua_err);
#endif
    return 0;
}
static int YGirdViewCell_setIdx(lua_State* tolua_S)
{
    int argc = 0;
    YGirdViewCell* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdViewCell",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YGirdViewCell*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdViewCell_setIdx'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'YGirdViewCell_setIdx'.",&tolua_err);
#endif
    return 0;
}
static int YGirdViewCell_getIdx(lua_State* tolua_S)
{
    int argc = 0;
    YGirdViewCell* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdViewCell",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YGirdViewCell*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdViewCell_getIdx'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'YGirdViewCell_getIdx'.",&tolua_err);
#endif
    return 0;
}
static int YGirdViewCell_reset(lua_State* tolua_S)
{
    int argc = 0;
    YGirdViewCell* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdViewCell",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (YGirdViewCell*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdViewCell_reset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'YGirdViewCell_reset'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_YGirdViewCell_open (lua_State *tolua_S)
{
	tolua_usertype(tolua_S, "YGirdViewCell");
	tolua_cclass(tolua_S, "YGirdViewCell", "YGirdViewCell", "cc.Node", nullptr);
	tolua_beginmodule(tolua_S, "YGirdViewCell");
		tolua_function(tolua_S, "create", YGirdViewCell_create);
		tolua_function(tolua_S, "setIdx", YGirdViewCell_setIdx);
		tolua_function(tolua_S, "getIdx", YGirdViewCell_getIdx);
		tolua_function(tolua_S, "reset", YGirdViewCell_reset);
	tolua_endmodule(tolua_S);
	return 0;
}
