#ifndef __TOLUA_OPERATE_LAYER_H__
#define __TOLUA_OPERATE_LAYER_H__
#include "tolua++.h"
#include "OperateLayer.h"
#include "LuaBasicConversions.h"
int lua_OperateLayer_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"OperateLayer",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			OperateLayer* ret = OperateLayer::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"OperateLayer");
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
    tolua_error(tolua_S,"#ferror in function 'lua_OperateLayer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_OperateLayer_setHero(lua_State* tolua_S)
{
    int argc = 0;
    OperateLayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"OperateLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (OperateLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_OperateLayer_setHero'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_OperateLayer_setHero'.",&tolua_err);
#endif
    return 0;
}
int lua_OperateLayer_setCenterPoint(lua_State* tolua_S)
{
    int argc = 0;
    OperateLayer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"OperateLayer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (OperateLayer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_OperateLayer_setCenterPoint'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		cocos2d::Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setCenterPoint(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCenterPoint",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_OperateLayer_setCenterPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_OperateLayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"OperateLayer");
	tolua_cclass(tolua_S,"OperateLayer","OperateLayer","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"OperateLayer");
			tolua_function(tolua_S, "create", lua_OperateLayer_create);
			tolua_function(tolua_S, "setHero", lua_OperateLayer_setHero);
			tolua_function(tolua_S, "setCenterPoint", lua_OperateLayer_setCenterPoint);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    