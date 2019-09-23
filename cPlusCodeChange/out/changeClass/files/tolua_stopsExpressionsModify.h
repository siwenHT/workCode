#ifndef __TOLUA_OPERATE_LAYER_H__
#define __TOLUA_OPERATE_LAYER_H__
#include "tolua++.h"
#include "stopsExpressionsModify.h"
#include "LuaBasicConversions.h"
int lua_stopsExpressionsModify_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"stopsExpressionsModify",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			stopsExpressionsModify* ret = stopsExpressionsModify::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"stopsExpressionsModify");
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
    tolua_error(tolua_S,"#ferror in function 'lua_stopsExpressionsModify_create'.",&tolua_err);
#endif
    return 0;
}
int lua_stopsExpressionsModify_setHero(lua_State* tolua_S)
{
    int argc = 0;
    stopsExpressionsModify* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"stopsExpressionsModify",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (stopsExpressionsModify*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stopsExpressionsModify_setHero'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		indexingSales* pobj = (indexingSales*)tolua_tousertype(tolua_S,2,0);
        if(!pobj) { return 0; }
		cobj->setHero(pobj);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHero",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_stopsExpressionsModify_setHero'.",&tolua_err);
#endif
    return 0;
}
int lua_stopsExpressionsModify_setnestedEnumerations(lua_State* tolua_S)
{
    int argc = 0;
    stopsExpressionsModify* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"stopsExpressionsModify",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (stopsExpressionsModify*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_stopsExpressionsModify_setnestedEnumerations'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		cocos2d::Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setnestedEnumerations(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setnestedEnumerations",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_stopsExpressionsModify_setnestedEnumerations'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_stopsExpressionsModify(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"stopsExpressionsModify");
	tolua_cclass(tolua_S,"stopsExpressionsModify","stopsExpressionsModify","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"stopsExpressionsModify");
			tolua_function(tolua_S, "create", lua_stopsExpressionsModify_create);
			tolua_function(tolua_S, "setHero", lua_stopsExpressionsModify_setHero);
			tolua_function(tolua_S, "setnestedEnumerations", lua_stopsExpressionsModify_setnestedEnumerations);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    