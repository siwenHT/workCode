#ifndef __TOLUA_TEXTUREMANAGER_H__
#define __TOLUA_TEXTUREMANAGER_H__
#include "tolua++.h"
#include "textureManager/TextureManager.h"
#include "LuaBasicConversions.h"
int lua_TextureManager_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			TextureManager* ret = TextureManager::getInstance();
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"TextureManager");
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_TextureManager_doTextureGC(lua_State* tolua_S)
{
    int argc = 0;
    TextureManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_doTextureGC'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->doTextureGC();
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doTextureGC",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_doTextureGC'.",&tolua_err);
#endif
    return 0;
}
int lua_TextureManager_doGC(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_doGC'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->doGC();
		return 1;
	}
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->doGC(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doGC",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_doGC'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_setIDleTime(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_setIDleTime'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setIDleTime(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIDleTime",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_setIDleTime'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_setMachineMemoryTYPE(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_setMachineMemoryTYPE'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setMachineMemoryTYPE(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMachineMemoryTYPE",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_setMachineMemoryTYPE'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_registerNotGCPath(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_registerNotGCPath'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->registerNotGCPath(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerNotGCPath",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_registerNotGCPath'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_registerNotGC(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_registerNotGC'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->registerNotGC(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerNotGC",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_registerNotGC'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_resetTextureActive(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_resetTextureActive'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->resetTextureActive(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetTextureActive",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_resetTextureActive'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_removeNotGC(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_removeNotGC'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->removeNotGC(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNotGC",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_removeNotGC'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_clearNotGC(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_clearNotGC'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->clearNotGC();
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clearNotGC",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_clearNotGC'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_setAllPngRGBA4444(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_setAllPngRGBA4444'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setAllPngRGBA4444(arg0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAllPngRGBA4444",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_setAllPngRGBA4444'.",&tolua_err);
#endif
	return 0;
}
int lua_TextureManager_getTotalByte(lua_State* tolua_S)
{
	int argc = 0;
	TextureManager* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"TextureManager",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (TextureManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_TextureManager_getTotalByte'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		long totalByte = cobj->getTotalByte();
		tolua_pushnumber(tolua_S, (lua_Number)totalByte);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTotalByte",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_TextureManager_getTotalByte'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_TextureManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TextureManager");
	tolua_cclass(tolua_S,"TextureManager","TextureManager","cc.Ref",NULL);
		tolua_beginmodule(tolua_S,"TextureManager");
			tolua_function(tolua_S, "getInstance", lua_TextureManager_getInstance);
			tolua_function(tolua_S, "doTextureGC", lua_TextureManager_doTextureGC);
			tolua_function(tolua_S, "registerNotGC", lua_TextureManager_registerNotGC);
			tolua_function(tolua_S, "registerNotGCPath", lua_TextureManager_registerNotGCPath);
			tolua_function(tolua_S, "removeNotGC", lua_TextureManager_removeNotGC);
			tolua_function(tolua_S, "clearNotGC", lua_TextureManager_clearNotGC);
			tolua_function(tolua_S, "getTotalByte", lua_TextureManager_getTotalByte);
			tolua_function(tolua_S, "doGC", lua_TextureManager_doGC);
			tolua_function(tolua_S, "setIDleTime", lua_TextureManager_setIDleTime);
			tolua_function(tolua_S, "setMachineMemoryTYPE", lua_TextureManager_setMachineMemoryTYPE);
			tolua_function(tolua_S, "resetTextureActive", lua_TextureManager_resetTextureActive);
			tolua_function(tolua_S, "setAllPngRGBA4444", lua_TextureManager_setAllPngRGBA4444);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    