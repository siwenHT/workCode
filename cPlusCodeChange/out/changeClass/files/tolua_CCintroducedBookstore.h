#ifndef __TOLUA_CCEFFECTS_H__
#define __TOLUA_CCEFFECTS_H__
#include "tolua++.h"
#include "CCintroducedBookstore.h"
#include "LuaBasicConversions.h"
int lua_introducedBookstore_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
        do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			introducedBookstore* ret = introducedBookstore::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<introducedBookstore>(tolua_S, "introducedBookstore",(introducedBookstore*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		bool arg0;
		bool arg1;
		do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			introducedBookstore* ret = introducedBookstore::create(arg0,arg1);
			do {
				if (NULL != ret){
					object_to_luaval<introducedBookstore>(tolua_S, "introducedBookstore",(introducedBookstore*)ret);
				}
				else
					lua_pushnil(tolua_S);
			} while (0);
			return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		bool arg0;
		bool arg1;
		bool arg2;
		do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 4, &arg2); 
			if (!ok) { break; }
			introducedBookstore* ret = introducedBookstore::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
					object_to_luaval<introducedBookstore>(tolua_S, "introducedBookstore",(introducedBookstore*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_create'.",&tolua_err);
#endif
    return 0;
}
int lua_introducedBookstore_parametisPreventAddress(lua_State* tolua_S)
{
    int argc = 0;
    introducedBookstore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_parametisPreventAddress'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4 || argc == 5) 
    {
		std::string arg0;
		int arg1;
		double arg2;
		int arg3;
		double arg4 = 0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3); 
		if (!ok) { return 0; }
		if(argc == 5)
			luaval_to_number(tolua_S, 6,&arg4);
		cobj->parametisPreventAddress(arg0,arg1,(float)arg2,arg3,(float)arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parametisPreventAddress",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_parametisPreventAddress'.",&tolua_err);
#endif
    return 0;
}
int lua_introducedBookstore_setmightTheareCorrectly(lua_State* tolua_S)
{
    int argc = 0;
    introducedBookstore* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setmightTheareCorrectly'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc ==1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setmightTheareCorrectly(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setmightTheareCorrectly",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setmightTheareCorrectly'.",&tolua_err);
#endif
    return 0;
}
int lua_introducedBookstore_setpartsCountLargest(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setpartsCountLargest'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setpartsCountLargest(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc ==2) 
	{
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->setpartsCountLargest(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpartsCountLargest",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setpartsCountLargest'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_getpartsCountLargest(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_getpartsCountLargest'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getpartsCountLargest();
		tolua_pushnumber(tolua_S,(int)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getpartsCountLargest",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_getpartsCountLargest'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_setstartingBasicsNamespaces(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setstartingBasicsNamespaces'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setstartingBasicsNamespaces(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setstartingBasicsNamespaces",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setstartingBasicsNamespaces'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_reset(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_reset'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==0) 
	{
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_reset'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setIsHide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setIsHide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_getIsHide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getIsHide();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_getIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_rePlay(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_rePlay'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->rePlay();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rePlay",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_rePlay'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_setdifficultConditionWorries(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setdifficultConditionWorries'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setdifficultConditionWorries(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdifficultConditionWorries",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setdifficultConditionWorries'.",&tolua_err);
#endif
	return 0;
}
int lua_introducedBookstore_setsuppressTransactio(lua_State* tolua_S)
{
	int argc = 0;
	introducedBookstore* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"introducedBookstore",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (introducedBookstore*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_introducedBookstore_setsuppressTransactio'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setsuppressTransactio(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsuppressTransactio",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_introducedBookstore_setsuppressTransactio'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_introducedBookstore(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"introducedBookstore");
	tolua_cclass(tolua_S,"introducedBookstore","introducedBookstore","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"introducedBookstore");
			tolua_function(tolua_S, "create", lua_introducedBookstore_create);
			tolua_function(tolua_S, "parametisPreventAddress", lua_introducedBookstore_parametisPreventAddress);
		
			tolua_function(tolua_S, "setmightTheareCorrectly", lua_introducedBookstore_setmightTheareCorrectly);
			tolua_function(tolua_S, "setpartsCountLargest", lua_introducedBookstore_setpartsCountLargest);
			tolua_function(tolua_S, "getpartsCountLargest", lua_introducedBookstore_getpartsCountLargest);
			tolua_function(tolua_S, "setIsHide", lua_introducedBookstore_setIsHide);
			tolua_function(tolua_S, "getIsHide", lua_introducedBookstore_getIsHide);
			tolua_function(tolua_S, "rePlay", lua_introducedBookstore_rePlay);
			tolua_function(tolua_S, "setstartingBasicsNamespaces", lua_introducedBookstore_setstartingBasicsNamespaces);
			tolua_function(tolua_S, "reset", lua_introducedBookstore_reset);
			tolua_function(tolua_S, "setdifficultConditionWorries", lua_introducedBookstore_setdifficultConditionWorries);
			tolua_function(tolua_S, "setsuppressTransactio", lua_introducedBookstore_setsuppressTransactio);
	
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    