#ifndef __TOLUA_SKILL_CTRL_H__
#define __TOLUA_SKILL_CTRL_H__
#include "tolua++.h"
#include "functionalthoughCompiler.h"
#include "LuaBasicConversions.h"
int lua_functionalthoughCompiler_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			functionalthoughCompiler* ret = functionalthoughCompiler::create();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"functionalthoughCompiler");
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
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_create'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_setHero(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_setHero'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_setHero'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_setRight(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_setRight'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_setRight'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_setNextPage(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_setRight'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setimagineWhatDiffer(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNextPage",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_setNextPage'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_getexactlyAkinCerr(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_getexactlyAkinCerr'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		indexingOstringstream* ret = cobj->getexactlyAkinCerr();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"indexingOstringstream");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getexactlyAkinCerr",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_getexactlyAkinCerr'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_getthoughtInitially(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_getthoughtInitially'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getthoughtInitially();
		if(ret)
		{
			tolua_pushusertype(tolua_S,(void*)ret,"cc.Node");
			return 1;
		}
		else
			lua_pushnil(tolua_S);
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getthoughtInitially",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_getthoughtInitially'.",&tolua_err);
#endif
    return 0;
}
int lua_functionalthoughCompiler_getderivationManualOkay(lua_State* tolua_S)
{
    int argc = 0;
    functionalthoughCompiler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"functionalthoughCompiler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (functionalthoughCompiler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_functionalthoughCompiler_getthoughtInitially'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getderivationManualOkay();
		tolua_pushnumber(tolua_S,ret);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getderivationManualOkay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_functionalthoughCompiler_getderivationManualOkay'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_functionalthoughCompiler(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"functionalthoughCompiler");
	tolua_cclass(tolua_S,"functionalthoughCompiler","functionalthoughCompiler","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"functionalthoughCompiler");
			tolua_function(tolua_S, "create", lua_functionalthoughCompiler_create);
			tolua_function(tolua_S, "setHero", lua_functionalthoughCompiler_setHero);
			tolua_function(tolua_S, "setRight", lua_functionalthoughCompiler_setRight);
			tolua_function(tolua_S, "getexactlyAkinCerr", lua_functionalthoughCompiler_getexactlyAkinCerr);
			tolua_function(tolua_S, "getthoughtInitially", lua_functionalthoughCompiler_getthoughtInitially);
			tolua_function(tolua_S, "setimagineWhatDiffer", lua_functionalthoughCompiler_setNextPage);
			tolua_function(tolua_S, "getderivationManualOkay", lua_functionalthoughCompiler_getderivationManualOkay);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    