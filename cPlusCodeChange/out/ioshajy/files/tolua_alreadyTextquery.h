#ifndef __TOLUA_OPERATE_LAYER_H__
#define __TOLUA_OPERATE_LAYER_H__
#include "tolua++.h"
#include "alreadyTextquery.h"
#include "LuaBasicConversions.h"
int lua_alreadyTextquery_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"alreadyTextquery",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			alreadyTextquery* ret = alreadyTextquery::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"alreadyTextquery");
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
    tolua_error(tolua_S,"#ferror in function 'lua_alreadyTextquery_create'.",&tolua_err);
#endif
    return 0;
}
int lua_alreadyTextquery_setHero(lua_State* tolua_S)
{
    int argc = 0;
    alreadyTextquery* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"alreadyTextquery",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (alreadyTextquery*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_alreadyTextquery_setHero'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_alreadyTextquery_setHero'.",&tolua_err);
#endif
    return 0;
}
int lua_alreadyTextquery_setbeenStrcmpTempting(lua_State* tolua_S)
{
    int argc = 0;
    alreadyTextquery* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"alreadyTextquery",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (alreadyTextquery*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_alreadyTextquery_setbeenStrcmpTempting'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		cocos2d::Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setbeenStrcmpTempting(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbeenStrcmpTempting",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_alreadyTextquery_setbeenStrcmpTempting'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_alreadyTextquery(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"alreadyTextquery");
	tolua_cclass(tolua_S,"alreadyTextquery","alreadyTextquery","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"alreadyTextquery");
			tolua_function(tolua_S, "create", lua_alreadyTextquery_create);
			tolua_function(tolua_S, "setHero", lua_alreadyTextquery_setHero);
			tolua_function(tolua_S, "setbeenStrcmpTempting", lua_alreadyTextquery_setbeenStrcmpTempting);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    