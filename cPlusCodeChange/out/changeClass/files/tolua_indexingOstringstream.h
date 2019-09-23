#ifndef __TOLUA_MENUBUTTON_H__
#define __TOLUA_MENUBUTTON_H__
#include "tolua++.h"
#include "indexingOstringstream.h"
#include "LuaBasicConversions.h"
int lua_indexingOstringstream_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"indexingOstringstream",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			indexingOstringstream* ret = indexingOstringstream::create(arg0);
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"indexingOstringstream");
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
    tolua_error(tolua_S,"#ferror in function 'lua_identifyingActually_create'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingOstringstream_setkeywordCompiledCreated5(lua_State* tolua_S)
{
    int argc = 0;
    indexingOstringstream* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingOstringstream",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingOstringstream*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingOstringstream_setkeywordCompiledCreated5'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setkeywordCompiledCreated5(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setkeywordCompiledCreated5",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingOstringstream_setkeywordCompiledCreated5'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingOstringstream_sethashPointerIndeedMovement4(lua_State* tolua_S)
{
    int argc = 0;
    indexingOstringstream* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingOstringstream",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingOstringstream*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingOstringstream_sethashPointerIndeedMovement4'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->sethashPointerIndeedMovement4(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sethashPointerIndeedMovement4",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingOstringstream_sethashPointerIndeedMovement4'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingOstringstream_setbecauseProblemThenReady(lua_State* tolua_S)
{
    int argc = 0;
    indexingOstringstream* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingOstringstream",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingOstringstream*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingOstringstream_setbecauseProblemThenReady'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setbecauseProblemThenReady(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbecauseProblemThenReady",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingOstringstream_setbecauseProblemThenReady'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingOstringstream_setImages(lua_State* tolua_S)
{
    int argc = 0;
    indexingOstringstream* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingOstringstream",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingOstringstream*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingOstringstream_setImages'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_indexingOstringstream_setImages'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_indexingOstringstream(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"indexingOstringstream");
	tolua_cclass(tolua_S,"indexingOstringstream","indexingOstringstream","cc.MenuItemImage",NULL);
		tolua_beginmodule(tolua_S,"indexingOstringstream");
			tolua_function(tolua_S, "create", lua_indexingOstringstream_create);
			tolua_function(tolua_S, "setImages", lua_indexingOstringstream_setImages);
			tolua_function(tolua_S, "setkeywordCompiledCreated5", lua_indexingOstringstream_setkeywordCompiledCreated5);
			tolua_function(tolua_S, "sethashPointerIndeedMovement4", lua_indexingOstringstream_sethashPointerIndeedMovement4);
			tolua_function(tolua_S, "setbecauseProblemThenReady", lua_indexingOstringstream_setbecauseProblemThenReady);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    