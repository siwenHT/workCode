#ifndef __TOLUA_SPRITEBASE_H__
#define __TOLUA_SPRITEBASE_H__
#include "tolua++.h"
#include "correspondingFunctional.h"
#include "indexingSales.h"
#include "LuaBasicConversions.h"
#include "wstringPreceding.h"
#include "withDesigned.h"
#include "unrelatedNodefaultGrouped.h"
#include "imagethChanges.h"
#include "mubeParametethat.h"
int lua_copiedFlipsActual_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			copiedFlipsActual* ret = copiedFlipsActual::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<copiedFlipsActual>(tolua_S, "copiedFlipsActual",(copiedFlipsActual*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			copiedFlipsActual* ret = copiedFlipsActual::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<copiedFlipsActual>(tolua_S, "copiedFlipsActual",(copiedFlipsActual*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_create'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_reset(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_reset'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "reset",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_reset'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setknowPdataOrganize(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setknowPdataOrganize'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setknowPdataOrganize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setknowPdataOrganize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setknowPdataOrganize'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setrequirementsUnlikeMissing(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setrequirementsUnlikeMissing'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setrequirementsUnlikeMissing(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setrequirementsUnlikeMissing",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setrequirementsUnlikeMissing'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setconversionchapterModel(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setconversionchapterModel'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setconversionchapterModel(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setconversionchapterModel",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setconversionchapterModel'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setstartingBasicsNamespaces(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setstartingBasicsNamespaces'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setstartingBasicsNamespaces(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setstartingBasicsNamespaces",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setstartingBasicsNamespaces'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_distinctEndingLiteral(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_distinctEndingLiteral'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 8) 
    {
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		double arg6;
		int arg7;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 8, &arg6); 
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		cobj->distinctEndingLiteral(arg0,arg1,arg2,arg3,arg4,arg5,(float)arg6,(auxiliaryEssential)arg7);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "distinctEndingLiteral",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_distinctEndingLiteral'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_throughoutDigitsExtent(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_throughoutDigitsExtent'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		int arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg2);
		if (!ok) { return 0; }
		cobj->throughoutDigitsExtent(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "throughoutDigitsExtent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_throughoutDigitsExtent'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_indexedExpandsTopic(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_indexedExpandsTopic'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->indexedExpandsTopic(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "indexedExpandsTopic",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_indexedExpandsTopic'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_mubeImageDirection(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_mubeImageDirection'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 12) 
	{
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		int arg6;
		int arg7;
		int arg8;
		int arg9;
		int arg10;
		int arg11;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7, &arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 8, &arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9, &arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10, &arg8);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 11, &arg9);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 12, &arg10);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 13, &arg11);
		if (!ok) { return 0; }
		cobj->mubeImageDirection(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "mubeImageDirection",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_mubeImageDirection'.",&tolua_err);
#endif
	return 0;
}
	int lua_copiedFlipsActual_compileReviseConsider3(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_compileReviseConsider3'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 12) 
	{
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		int arg5;
		int arg6;
		int arg7;
		int arg8;
		int arg9;
		int arg10;
		int arg11;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 7, &arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 8, &arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 9, &arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10, &arg8);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 11, &arg9);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 12, &arg10);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 13, &arg11);
		if (!ok) { return 0; }
		cobj->compileReviseConsider3(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "compileReviseConsider3",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_compileReviseConsider3'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_leavingNumberAccessible2(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_leavingNumberAccessible2'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		cobj->leavingNumberAccessible2(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "leavingNumberAccessible2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_leavingNumberAccessible2'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getIsHide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getIsHide();
		tolua_pushboolean(tolua_S, ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setIsHide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setIsHide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsHide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setchaptersSubsequent(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setchaptersSubsequent'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setchaptersSubsequent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setchaptersSubsequent",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setchaptersSubsequent'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_redeclareIgnoredBackslash(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_redeclareIgnoredBackslash'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		cobj->redeclareIgnoredBackslash(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "redeclareIgnoredBackslash",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_redeclareIgnoredBackslash'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_reflectCopyOstream(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_reflectCopyOstream'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		std::string arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->reflectCopyOstream(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reflectCopyOstream",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_reflectCopyOstream'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_standed(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_standed'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->standed();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_standed'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_standedby(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_standedby'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->standedby();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standedby",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_standedby'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setscopingHairBlueprint(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setscopingHairBlueprint'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setscopingHairBlueprint(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setscopingHairBlueprint",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setscopingHairBlueprint'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setsquaresConstitutesGuide(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setsquaresConstitutesGuide'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setsquaresConstitutesGuide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsquaresConstitutesGuide",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setsquaresConstitutesGuide'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setOnRide(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setOnRide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setOnRide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setOnRide'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getcomputeBenefitEliminated(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getcomputeBenefitEliminated'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		std::string ret = cobj->getcomputeBenefitEliminated();
		tolua_pushstring(tolua_S, ret.c_str());
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getcomputeBenefitEliminated",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getcomputeBenefitEliminated'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getOnRide(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getOnRide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getOnRide();
		tolua_pushboolean(tolua_S, (int)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOnRide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getOnRide'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getincompleteNodtorContained(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getincompleteNodtorContained'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getincompleteNodtorContained();
		tolua_pushnumber(tolua_S, ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getincompleteNodtorContained",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getincompleteNodtorContained'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_ownsPrecedeDerivation(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_ownsPrecedeDerivation'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->ownsPrecedeDerivation((float)arg0,arg1,(auxiliaryEssential)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ownsPrecedeDerivation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_ownsPrecedeDerivation'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_happensElemeisEachHappens(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_happensElemeisEachHappens'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->happensElemeisEachHappens((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->happensElemeisEachHappens((float)arg0,arg1,(auxiliaryEssential)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 4) 
	{
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		bool ret = cobj->happensElemeisEachHappens((float)arg0,arg1,(auxiliaryEssential)arg2,arg3);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "happensElemeisEachHappens",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_happensElemeisEachHappens'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_escapeSimplerThrows(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_escapeSimplerThrows'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->escapeSimplerThrows((float)arg0,arg1,(auxiliaryEssential)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "escapeSimplerThrows",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_escapeSimplerThrows'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_colonAssignsVaries(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_colonAssignsVaries'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		double arg0;
		Point arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->colonAssignsVaries((float)arg0,arg1,(auxiliaryEssential)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "colonAssignsVaries",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_colonAssignsVaries'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_deductionOfileNearly(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_deductionOfileNearly'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->deductionOfileNearly((float)arg0,(auxiliaryEssential)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "deductionOfileNearly",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_deductionOfileNearly'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_integralEvaluating(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_integralEvaluating'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->integralEvaluating((float)arg0,(auxiliaryEssential)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "integralEvaluating",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_integralEvaluating'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_seriesSalesRationale(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_seriesSalesRationale'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->seriesSalesRationale((float)arg0,(auxiliaryEssential)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "seriesSalesRationale",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_seriesSalesRationale'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_sectionGuaranteeHighest(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
    tolua_Error tolua_err;
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_sectionGuaranteeHighest'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		double arg0;
		int arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
    {
		double arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 4) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3,(auxiliaryEssential)arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 6) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3,(auxiliaryEssential)arg4,arg5);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 7) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3,(auxiliaryEssential)arg4,arg5,arg6);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 8) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		bool arg7;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3,(auxiliaryEssential)arg4,arg5,arg6,arg7);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 9) 
	{
		double arg0;
		int arg1;
		int arg2;
		Point arg3;
		int arg4;
		bool arg5;
		bool arg6;
		bool arg7;
		int  arg8;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if (!toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) {
			arg2 = 0;
		}else
			arg2 =  toluafix_ref_function(tolua_S,4,0);
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 10,&arg8);
		if (!ok) { return 0; }
		cobj->sectionGuaranteeHighest((float)arg0,arg1,arg2,arg3,(auxiliaryEssential)arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sectionGuaranteeHighest",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_sectionGuaranteeHighest'.",&tolua_err);
    return 0;
}
int lua_copiedFlipsActual_matchesEndsDimension1(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_matchesEndsDimension1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->matchesEndsDimension1((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->matchesEndsDimension1((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "matchesEndsDimension1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_matchesEndsDimension1'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_generatedDenotingStrblob(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_generatedDenotingStrblob'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->generatedDenotingStrblob((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->generatedDenotingStrblob((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "generatedDenotingStrblob",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_generatedDenotingStrblob'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_moveToPos(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_moveToPos'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->moveToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 3) 
    {
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->moveToPos((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_moveToPos'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_walkToPos(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_walkToPos'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->walkToPos((float)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "walkToPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_walkToPos'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_actionsEntryLanguage(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_actionsEntryLanguage'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->actionsEntryLanguage(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionsEntryLanguage",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_actionsEntryLanguage'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_nestedOwhichBetween(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_nestedOwhichBetween'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->nestedOwhichBetween((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 3) 
	{
		double arg0;
		Point arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		bool ret = cobj->nestedOwhichBetween((float)arg0,arg1,arg2);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nestedOwhichBetween",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_nestedOwhichBetween'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_persistTupleValues1(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_persistTupleValues1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		bool ret = cobj->persistTupleValues1((float)arg0,Point::ZERO);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->persistTupleValues1((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "persistTupleValues1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_persistTupleValues1'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_anotherWholeTypically(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_anotherWholeTypically'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->anotherWholeTypically(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "anotherWholeTypically",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_anotherWholeTypically'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_differAroundImpactHard(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_differAroundImpactHard'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		Point arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		bool ret = cobj->differAroundImpactHard((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "differAroundImpactHard",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_differAroundImpactHard'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_overloadedThemselves(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_actionsEntryLanguage'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->overloadedThemselves(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "overloadedThemselves",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_overloadedThemselves'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_hasHurted(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_hasHurted'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->hasHurted((float)arg0,(float)arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hasHurted",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_hasHurted'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_gotoDeath(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_gotoDeath'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->gotoDeath((auxiliaryEssential)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoDeath",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_gotoDeath'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setitemContainersUnable(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setitemContainersUnable'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0=true;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setitemContainersUnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setitemContainersUnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setitemContainersUnable'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_correctSettingIcase(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_correctSettingIcase'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Touch* arg0 = (Touch*)tolua_tousertype(tolua_S,2,0);
		if (!arg0) { return 0; }
		bool ret = cobj->correctSettingIcase(arg0);
		if (ret){
				tolua_pushboolean(tolua_S,(bool)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "correctSettingIcase",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_correctSettingIcase'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setOpacity'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setOpacity(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	if (argc == 2) 
	{
		int arg0 ;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->setOpacity(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setColor(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setColor'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setbraceTwinThposition(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setbraceTwinThposition'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setbraceTwinThposition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbraceTwinThposition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setbraceTwinThposition'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getbraceTwinThposition(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getbraceTwinThposition'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getbraceTwinThposition();
		tolua_pushnumber(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getbraceTwinThposition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getbraceTwinThposition'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setGray(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setGray'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setGray(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setGray",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setGray'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setWhite(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setWhite'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setWhite(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWhite",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setWhite'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getOpacity'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getOpacity();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setlockDesignedConsiderWmust(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setlockDesignedConsiderWmust'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setlockDesignedConsiderWmust((auxiliaryEssential)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlockDesignedConsiderWmust",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setlockDesignedConsiderWmust'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_instancesSomewhat(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_instancesSomewhat'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->instancesSomewhat((throwsPreviously)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "instancesSomewhat",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_instancesSomewhat'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getstreamConditionTechniques(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getstreamConditionTechniques'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		auxiliaryEssential ret = cobj->getstreamConditionTechniques();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getstreamConditionTechniques",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getstreamConditionTechniques'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setappeaanywhereScopedBasic(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setappeaanywhereScopedBasic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setappeaanywhereScopedBasic((throwsPreviously)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setappeaanywhereScopedBasic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setappeaanywhereScopedBasic'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getappeaanywhereScopedBasic(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getappeaanywhereScopedBasic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		throwsPreviously ret = cobj->getappeaanywhereScopedBasic();
		if(ret > 0)
		{
			tolua_pushnumber(tolua_S,(int)ret);
			return 1;
		}
		else
			lua_pushnil(tolua_S);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getappeaanywhereScopedBasic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getappeaanywhereScopedBasic'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setType(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setType'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setTypeId((extendedUsesMatch)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}else if (argc == 2) 
	{
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->setTypeId((extendedUsesMatch)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setType'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setcreateConvertInclude(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setType'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setcreateConvertInclude((extendedUsesMatch)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_copiedFlipsActual_setcreateConvertInclude",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_lua_copiedFlipsActual_setcreateConvertInclude'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getbasicNumbersEverything(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getbasicNumbersEverything'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		bool ret = cobj->getbasicNumbersEverything();
		tolua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getbasicNumbersEverything",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getbasicNumbersEverything'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getType(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getType'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = (int)cobj->getTypeId();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getType'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_prvoidLeadsChoice(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_prvoidLeadsChoice'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg = 0;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->prvoidLeadsChoice((throwsPreviously)arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "prvoidLeadsChoice",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_prvoidLeadsChoice'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_refresh(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_refresh'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->refresh();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "refresh",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_refresh'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getnodefaultDoesPermitted(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getnodefaultDoesPermitted'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		std::string ret = (std::string)cobj->getnodefaultDoesPermitted();
		if (ret != "") { tolua_pushstring(tolua_S,ret.c_str());}
		else { lua_pushnil(tolua_S); }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getnodefaultDoesPermitted",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getnodefaultDoesPermitted'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setnodefaultDoesPermitted(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setnodefaultDoesPermitted'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		std::string arg0 = "";
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setnodefaultDoesPermitted(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setnodefaultDoesPermitted",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setnodefaultDoesPermitted'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_gradingLatestRedeclare(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_gradingLatestRedeclare'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->gradingLatestRedeclare(arg0, (stringsLargeEspecially)arg1, (auxiliaryEssential)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gradingLatestRedeclare",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_gradingLatestRedeclare'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getLocalZOrder(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getLocalZOrder'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = (int)cobj->getLocalZOrder();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLocalZOrder",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getLocalZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getimplementsReviseSkim(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getimplementsReviseSkim'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getimplementsReviseSkim();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getimplementsReviseSkim",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getimplementsReviseSkim'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_parametisPreventAddress(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_parametisPreventAddress'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->parametisPreventAddress(arg0, (stringsLargeEspecially)arg1, (auxiliaryEssential)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parametisPreventAddress",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_parametisPreventAddress'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getexhaustedIntvaluesAlready(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getexhaustedIntvaluesAlready'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getexhaustedIntvaluesAlready();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getexhaustedIntvaluesAlready",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getexhaustedIntvaluesAlready'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setexhaustedIntvaluesAlready(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setexhaustedIntvaluesAlready'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setexhaustedIntvaluesAlready(arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setexhaustedIntvaluesAlready",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setexhaustedIntvaluesAlready'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setlimitsThdefinesCounts4(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setlimitsThdefinesCounts4'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setlimitsThdefinesCounts4(arg);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlimitsThdefinesCounts4",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setlimitsThdefinesCounts4'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setResId(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setResId'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setResId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setResId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setResId'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getResId(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getResId'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getResId();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getResId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getResId'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_setsingleCollideTesting(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setsingleCollideTesting'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setsingleCollideTesting(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsingleCollideTesting",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setsingleCollideTesting'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getsingleCollideTesting(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getsingleCollideTesting'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		const cocos2d::Point& ret = cobj->getsingleCollideTesting();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getsingleCollideTesting",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getsingleCollideTesting'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getselectsSpecialized(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getselectsSpecialized'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getselectsSpecialized();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getselectsSpecialized",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getselectsSpecialized'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setselectsSpecialized(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setselectsSpecialized'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setselectsSpecialized(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setselectsSpecialized",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setselectsSpecialized'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getinteractsCollections(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getinteractsCollections'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getinteractsCollections();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "v",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getinteractsCollections'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getFather(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getFather'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		copiedFlipsActual* ret = cobj->getFather();
		do {
			if (NULL != ret){
				object_to_luaval<copiedFlipsActual>(tolua_S, "copiedFlipsActual",(copiedFlipsActual*)ret);
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFather",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getFather'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setFather(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setFather'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			copiedFlipsActual* arg0 = (copiedFlipsActual*)tolua_tousertype(tolua_S, 2,0); 
			if (!ok) { break; }
			cobj->setFather(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_copiedFlipsActual_setFather",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setFather'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setsubsetSufficientlyHere(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setsubsetSufficientlyHere'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2,&arg0);
			if (!ok) { break; }
			cobj->setsubsetSufficientlyHere(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_copiedFlipsActual_setsubsetSufficientlyHere",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setsubsetSufficientlyHere'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getcontrolCoveringExecution(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getcontrolCoveringExecution'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getcontrolCoveringExecution();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getcontrolCoveringExecution",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getcontrolCoveringExecution'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setcontrolCoveringExecution(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setcontrolCoveringExecution'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setcontrolCoveringExecution(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setcontrolCoveringExecution",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setcontrolCoveringExecution'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_makingTemplates(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_makingTemplates'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->makingTemplates(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "makingTemplates",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_makingTemplates'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_wregexComputationalPasses(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_wregexComputationalPasses'", NULL);
        return 0;
    }
#endif
	cobj->wregexComputationalPasses();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_wregexComputationalPasses'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_inverselyStillHierarchy(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_inverselyStillHierarchy'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->inverselyStillHierarchy(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "inverselyStillHierarchy",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_inverselyStillHierarchy'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_verifyStoredImportance(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_verifyStoredImportance'", NULL);
        return 0;
    }
#endif
	cobj->verifyStoredImportance();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_verifyStoredImportance'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_readersTakesAdding(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_readersTakesAdding'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->readersTakesAdding(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readersTakesAdding",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_readersTakesAdding'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_describeMuensure(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_describeMuensure'", NULL);
		return 0;
	}
#endif
	cobj->describeMuensure();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_describeMuensure'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_tpassEnclosedReset(lua_State* tolua_S)
{
    int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_tpassEnclosedReset'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->tpassEnclosedReset(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tpassEnclosedReset",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_tpassEnclosedReset'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_cmatchPassedFamily(lua_State* tolua_S)
{
	int argc = 0;
    copiedFlipsActual* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_cmatchPassedFamily'", NULL);
        return 0;
    }
#endif
	cobj->cmatchPassedFamily();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_cmatchPassedFamily'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_suppliedUnderTakes(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_suppliedUnderTakes'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->suppliedUnderTakes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "suppliedUnderTakes",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_suppliedUnderTakes'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_learnHereOnalthoughHasptr4(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_learnHereOnalthoughHasptr4'", NULL);
		return 0;
	}
#endif
	cobj->learnHereOnalthoughHasptr4();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_learnHereOnalthoughHasptr4'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_elsewhereExpandsConverted(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_elsewhereExpandsConverted'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->elsewhereExpandsConverted(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "elsewhereExpandsConverted",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_elsewhereExpandsConverted'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_curliesOccur(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_curliesOccur'", NULL);
		return 0;
	}
#endif
	cobj->curliesOccur();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_curliesOccur'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setwhisSynthesizesKindLeft(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setwhisSynthesizesKindLeft'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setwhisSynthesizesKindLeft(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setwhisSynthesizesKindLeft",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setwhisSynthesizesKindLeft'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setthinkPossibleFamiliar(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setthinkPossibleFamiliar'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			unsigned short arg0;
			ok &= luaval_to_ushort(tolua_S, 2, &arg0);
			if (!ok) { break; }
			cobj->setthinkPossibleFamiliar(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setthinkPossibleFamiliar",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setthinkPossibleFamiliar'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_FixFlyPos(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_FixFlyPos'", NULL);
		return 0;
	}
#endif
	cobj->FixFlyPos();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_FixFlyPos'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setRenderMode(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setRenderMode'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0);
			if (!ok) { break; }
			cobj->setRenderMode(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRenderMode",argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setRenderMode'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getmatrixBrowsersAllowed(lua_State* tolua_S)
{
	int argc = 0;
	copiedFlipsActual* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"copiedFlipsActual",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (copiedFlipsActual*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getmatrixBrowsersAllowed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getmatrixBrowsersAllowed();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getmatrixBrowsersAllowed", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getmatrixBrowsersAllowed'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_copiedFlipsActual(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"copiedFlipsActual");
	tolua_cclass(tolua_S,"copiedFlipsActual","copiedFlipsActual","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"copiedFlipsActual");
			tolua_function(tolua_S, "create", lua_copiedFlipsActual_create);
			tolua_function(tolua_S, "reset", lua_copiedFlipsActual_reset);
			tolua_function(tolua_S, "setknowPdataOrganize", lua_copiedFlipsActual_setknowPdataOrganize);
			tolua_function(tolua_S, "setconversionchapterModel", lua_copiedFlipsActual_setconversionchapterModel);
			tolua_function(tolua_S, "setrequirementsUnlikeMissing", lua_copiedFlipsActual_setrequirementsUnlikeMissing);
			tolua_function(tolua_S, "setstartingBasicsNamespaces", lua_copiedFlipsActual_setstartingBasicsNamespaces);
			tolua_function(tolua_S, "distinctEndingLiteral", lua_copiedFlipsActual_distinctEndingLiteral);
			tolua_function(tolua_S, "throughoutDigitsExtent", lua_copiedFlipsActual_throughoutDigitsExtent);
			tolua_function(tolua_S, "indexedExpandsTopic", lua_copiedFlipsActual_indexedExpandsTopic);
			tolua_function(tolua_S, "mubeImageDirection", lua_copiedFlipsActual_mubeImageDirection);
			tolua_function(tolua_S, "compileReviseConsider3", lua_copiedFlipsActual_compileReviseConsider3);
			tolua_function(tolua_S, "leavingNumberAccessible2", lua_copiedFlipsActual_leavingNumberAccessible2);
			tolua_function(tolua_S, "redeclareIgnoredBackslash", lua_copiedFlipsActual_redeclareIgnoredBackslash);
			tolua_function(tolua_S, "getIsHide", lua_copiedFlipsActual_getIsHide);
			tolua_function(tolua_S, "setIsHide", lua_copiedFlipsActual_setIsHide);
			tolua_function(tolua_S, "setchaptersSubsequent", lua_copiedFlipsActual_setchaptersSubsequent);
			tolua_function(tolua_S, "reflectCopyOstream", lua_copiedFlipsActual_reflectCopyOstream);
			tolua_function(tolua_S, "standed", lua_copiedFlipsActual_standed);
			tolua_function(tolua_S, "standedby", lua_copiedFlipsActual_standedby);
			tolua_function(tolua_S, "setscopingHairBlueprint", lua_copiedFlipsActual_setscopingHairBlueprint);
			tolua_function(tolua_S, "setsquaresConstitutesGuide", lua_copiedFlipsActual_setsquaresConstitutesGuide);
			tolua_function(tolua_S, "ownsPrecedeDerivation", lua_copiedFlipsActual_ownsPrecedeDerivation);
			tolua_function(tolua_S, "happensElemeisEachHappens", lua_copiedFlipsActual_happensElemeisEachHappens);
			tolua_function(tolua_S, "escapeSimplerThrows", lua_copiedFlipsActual_escapeSimplerThrows);
			tolua_function(tolua_S, "colonAssignsVaries", lua_copiedFlipsActual_colonAssignsVaries);
			tolua_function(tolua_S, "deductionOfileNearly", lua_copiedFlipsActual_deductionOfileNearly);
			tolua_function(tolua_S, "seriesSalesRationale", lua_copiedFlipsActual_seriesSalesRationale);
			tolua_function(tolua_S, "integralEvaluating", lua_copiedFlipsActual_integralEvaluating);		
			tolua_function(tolua_S, "sectionGuaranteeHighest", lua_copiedFlipsActual_sectionGuaranteeHighest);
			tolua_function(tolua_S, "matchesEndsDimension1", lua_copiedFlipsActual_matchesEndsDimension1);
			tolua_function(tolua_S, "generatedDenotingStrblob", lua_copiedFlipsActual_generatedDenotingStrblob);
			tolua_function(tolua_S, "moveToPos", lua_copiedFlipsActual_moveToPos);
			tolua_function(tolua_S, "walkToPos", lua_copiedFlipsActual_walkToPos);
			tolua_function(tolua_S, "actionsEntryLanguage", lua_copiedFlipsActual_actionsEntryLanguage);
			tolua_function(tolua_S, "nestedOwhichBetween", lua_copiedFlipsActual_nestedOwhichBetween);
		
		
			tolua_function(tolua_S, "persistTupleValues1", lua_copiedFlipsActual_persistTupleValues1);	
			tolua_function(tolua_S, "anotherWholeTypically", lua_copiedFlipsActual_anotherWholeTypically);
			tolua_function(tolua_S, "differAroundImpactHard", lua_copiedFlipsActual_differAroundImpactHard);
			tolua_function(tolua_S, "overloadedThemselves", lua_copiedFlipsActual_overloadedThemselves);
			tolua_function(tolua_S, "hasHurted", lua_copiedFlipsActual_hasHurted);
			tolua_function(tolua_S, "gotoDeath", lua_copiedFlipsActual_gotoDeath);
			tolua_function(tolua_S, "correctSettingIcase", lua_copiedFlipsActual_correctSettingIcase);
			tolua_function(tolua_S, "setitemContainersUnable", lua_copiedFlipsActual_setitemContainersUnable);
			tolua_function(tolua_S, "setColor", lua_copiedFlipsActual_setColor);
			tolua_function(tolua_S, "setGray", lua_copiedFlipsActual_setGray);
			tolua_function(tolua_S, "setWhite", lua_copiedFlipsActual_setWhite);
			tolua_function(tolua_S, "setOpacity", lua_copiedFlipsActual_setOpacity);
			tolua_function(tolua_S, "getOpacity", lua_copiedFlipsActual_getOpacity);
			tolua_function(tolua_S, "setappeaanywhereScopedBasic", lua_copiedFlipsActual_setappeaanywhereScopedBasic);
			tolua_function(tolua_S, "getappeaanywhereScopedBasic", lua_copiedFlipsActual_getappeaanywhereScopedBasic);
			tolua_function(tolua_S, "setlockDesignedConsiderWmust", lua_copiedFlipsActual_setlockDesignedConsiderWmust);
			tolua_function(tolua_S, "instancesSomewhat", lua_copiedFlipsActual_instancesSomewhat);
			tolua_function(tolua_S, "getstreamConditionTechniques", lua_copiedFlipsActual_getstreamConditionTechniques);
			tolua_function(tolua_S, "setType", lua_copiedFlipsActual_setType);
			tolua_function(tolua_S, "getType", lua_copiedFlipsActual_getType);
			tolua_function(tolua_S, "setbraceTwinThposition", lua_copiedFlipsActual_setbraceTwinThposition);
			tolua_function(tolua_S, "getbraceTwinThposition", lua_copiedFlipsActual_getbraceTwinThposition);			
			tolua_function(tolua_S, "getbasicNumbersEverything", lua_copiedFlipsActual_getbasicNumbersEverything);
			tolua_function(tolua_S, "prvoidLeadsChoice", lua_copiedFlipsActual_prvoidLeadsChoice);
			tolua_function(tolua_S, "refresh", lua_copiedFlipsActual_refresh);
			tolua_function(tolua_S, "setcreateConvertInclude", lua_copiedFlipsActual_setcreateConvertInclude);
		
			tolua_function(tolua_S, "getnodefaultDoesPermitted",     lua_copiedFlipsActual_getnodefaultDoesPermitted);
			tolua_function(tolua_S, "setnodefaultDoesPermitted",     lua_copiedFlipsActual_setnodefaultDoesPermitted);
			tolua_function(tolua_S, "gradingLatestRedeclare",     lua_copiedFlipsActual_gradingLatestRedeclare);
			tolua_function(tolua_S, "getLocalZOrder", lua_copiedFlipsActual_getLocalZOrder); 
			tolua_function(tolua_S, "parametisPreventAddress", lua_copiedFlipsActual_parametisPreventAddress);
			tolua_function(tolua_S, "getimplementsReviseSkim", lua_copiedFlipsActual_getimplementsReviseSkim);
			tolua_function(tolua_S, "setexhaustedIntvaluesAlready",  lua_copiedFlipsActual_setexhaustedIntvaluesAlready);
			tolua_function(tolua_S, "getexhaustedIntvaluesAlready",  lua_copiedFlipsActual_getexhaustedIntvaluesAlready);
			tolua_function(tolua_S, "setlimitsThdefinesCounts4",  lua_copiedFlipsActual_setlimitsThdefinesCounts4);
			tolua_function(tolua_S, "setResId",       lua_copiedFlipsActual_setResId);
			tolua_function(tolua_S, "getResId",       lua_copiedFlipsActual_getResId);
			tolua_function(tolua_S, "setOnRide",      lua_copiedFlipsActual_setOnRide);
			tolua_function(tolua_S, "getOnRide",      lua_copiedFlipsActual_getOnRide);
			tolua_function(tolua_S, "getincompleteNodtorContained",    lua_copiedFlipsActual_getincompleteNodtorContained); 
			tolua_function(tolua_S, "setsingleCollideTesting",   lua_copiedFlipsActual_setsingleCollideTesting);
			tolua_function(tolua_S, "getsingleCollideTesting",   lua_copiedFlipsActual_getsingleCollideTesting);
			tolua_function(tolua_S, "getcomputeBenefitEliminated",   lua_copiedFlipsActual_getcomputeBenefitEliminated);
		
			tolua_function(tolua_S, "getselectsSpecialized",    lua_copiedFlipsActual_getselectsSpecialized);
			tolua_function(tolua_S, "setselectsSpecialized",    lua_copiedFlipsActual_setselectsSpecialized);
			tolua_function(tolua_S, "getinteractsCollections",    lua_copiedFlipsActual_getinteractsCollections);
			tolua_function(tolua_S, "setFather",    lua_copiedFlipsActual_setFather);
			tolua_function(tolua_S, "getFather",    lua_copiedFlipsActual_getFather);
			tolua_function(tolua_S, "setsubsetSufficientlyHere",    lua_copiedFlipsActual_setsubsetSufficientlyHere);
			tolua_function(tolua_S, "setwhisSynthesizesKindLeft",    lua_copiedFlipsActual_setwhisSynthesizesKindLeft);
			tolua_function(tolua_S, "setthinkPossibleFamiliar",    lua_copiedFlipsActual_setthinkPossibleFamiliar);
			tolua_function(tolua_S, "setcontrolCoveringExecution",    lua_copiedFlipsActual_setcontrolCoveringExecution);
			tolua_function(tolua_S, "getcontrolCoveringExecution",    lua_copiedFlipsActual_getcontrolCoveringExecution);
			tolua_function(tolua_S, "makingTemplates",       lua_copiedFlipsActual_makingTemplates);
			tolua_function(tolua_S, "wregexComputationalPasses",         lua_copiedFlipsActual_wregexComputationalPasses);
			tolua_function(tolua_S, "inverselyStillHierarchy",       lua_copiedFlipsActual_inverselyStillHierarchy);
			tolua_function(tolua_S, "verifyStoredImportance",         lua_copiedFlipsActual_verifyStoredImportance);
		
			tolua_function(tolua_S, "readersTakesAdding",       lua_copiedFlipsActual_readersTakesAdding);
			tolua_function(tolua_S, "describeMuensure",         lua_copiedFlipsActual_describeMuensure);
			tolua_function(tolua_S, "tpassEnclosedReset",         lua_copiedFlipsActual_tpassEnclosedReset);
			tolua_function(tolua_S, "cmatchPassedFamily",           lua_copiedFlipsActual_cmatchPassedFamily);
			tolua_function(tolua_S, "suppliedUnderTakes",           lua_copiedFlipsActual_suppliedUnderTakes);
			tolua_function(tolua_S, "learnHereOnalthoughHasptr4",           lua_copiedFlipsActual_learnHereOnalthoughHasptr4);
			tolua_function(tolua_S, "elsewhereExpandsConverted",           lua_copiedFlipsActual_elsewhereExpandsConverted);
			tolua_function(tolua_S, "curliesOccur",           lua_copiedFlipsActual_curliesOccur);
			tolua_function(tolua_S, "FixFlyPos",              lua_copiedFlipsActual_FixFlyPos);
			tolua_function(tolua_S, "setRenderMode",          lua_copiedFlipsActual_setRenderMode);
			tolua_function(tolua_S, "getmatrixBrowsersAllowed",          lua_copiedFlipsActual_getmatrixBrowsersAllowed);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_correspondingFunctional_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			correspondingFunctional* ret = correspondingFunctional::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<correspondingFunctional>(tolua_S, "correspondingFunctional",(correspondingFunctional*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1);
			if (!ok) { break; }
			correspondingFunctional* ret = correspondingFunctional::create(arg0, arg1);
			do {
				if (NULL != ret){
					object_to_luaval<correspondingFunctional>(tolua_S, "correspondingFunctional",(correspondingFunctional*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_create'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setunorderedChartypSpelling(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setunorderedChartypSpelling'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setunorderedChartypSpelling(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setunorderedChartypSpelling",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setunorderedChartypSpelling'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_setworkBindsPrecedeBody(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setworkBindsPrecedeBody'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setworkBindsPrecedeBody(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setworkBindsPrecedeBody",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setworkBindsPrecedeBody'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_setnoneFunctiwithSquares(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setnoneFunctiwithSquares'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setnoneFunctiwithSquares(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setnoneFunctiwithSquares",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setnoneFunctiwithSquares'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_setSpeed(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setSpeed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSpeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setSpeed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_setreferencesthLegitimate(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setreferencesthLegitimate'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setreferencesthLegitimate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setreferencesthLegitimate",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setreferencesthLegitimate'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_isMove(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_isMove'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		bool ret = cobj->isMove();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "isMove",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_isMove'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setHP(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setHP'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int64 arg0;
		ok &= luaval_to_long_long(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setHP(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setHP'.",&tolua_err);
#endif
    return 0;
}
int lua_copiedFlipsActual_getHP(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getHP'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int64 ret = cobj->getHP();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getHP'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setrankedEndsDriven(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setrankedEndsDriven'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setrankedEndsDriven(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrankedEndsDriven",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setrankedEndsDriven'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getrankedEndsDriven(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getrankedEndsDriven'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getrankedEndsDriven();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getrankedEndsDriven",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getrankedEndsDriven'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setMaxHP'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int64 arg0;
		ok &= luaval_to_long_long(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setMaxHP(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setMaxHP'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getMaxHP'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int64 ret = cobj->getMaxHP();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxHP",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getMaxHP'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setAttack(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setAttack'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setAttack(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAttack",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setAttack'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getAttack(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getAttack'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getAttack();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttack",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getAttack'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setName(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setName'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if(!ok) return 0;
		cobj->setName(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setName'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getName(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getName'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		std::string ret = cobj->getName();
		tolua_pushcppstring(tolua_S,(const char*)ret); 
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getName'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setLevel'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setLevel(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getLevel(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getLevel'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getLevel();
		if (ret){
				tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_subBlood(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_subBlood'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->subBlood(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "subBlood",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_subBlood'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_setthrowsConvertSignature(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setthrowsConvertSignature'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		int arg1 = 0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setthrowsConvertSignature(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setthrowsConvertSignature",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_setthrowsConvertSignature'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_qualifyingVeryExhasuting(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_qualifyingVeryExhasuting'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2 || argc == 3) 
    {
		bool arg0;
		bool arg1;
		int arg2 = 0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		if(argc == 3)
		{
			ok &= luaval_to_int32(tolua_S, 4,&arg2);
			if (!ok) { return 0; }
		}
		int name_state = arg0 == true?1:0;
		int blood_state = arg1 == true?1:0;
		cobj->qualifyingVeryExhasuting(name_state,blood_state,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }else if(argc == 4){
		bool arg0;
		bool arg1;
		int arg2 = 0;
		bool arg3;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		int name_state = arg0 == true?1:0;
		int blood_state = arg1 == true?1:0;
		cobj->qualifyingVeryExhasuting(name_state,blood_state,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "qualifyingVeryExhasuting",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_qualifyingVeryExhasuting'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_isAlive'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		bool ret = cobj->isAlive();
		if (ret){
				tolua_pushboolean(tolua_S,(int)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAlive",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_isAlive'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_gethandlingWellIntend(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_gethandlingWellIntend'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->gethandlingWellIntend();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gethandlingWellIntend",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_gethandlingWellIntend'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getlimitedPrimerNaturally(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getlimitedPrimerNaturally'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getlimitedPrimerNaturally();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getlimitedPrimerNaturally",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getlimitedPrimerNaturally'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getwantAlgorithmNotify2(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getwantAlgorithmNotify2'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getwantAlgorithmNotify2();
		do {
				if (NULL != ret){
				
					object_to_luaval<Label>(tolua_S, "cc.Label",(Label*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getwantAlgorithmNotify2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getwantAlgorithmNotify2'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getfetchRegexPresence3(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getfetchRegexPresence3'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getfetchRegexPresence3();
		if (ret)
		{
			tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
		{
			lua_pushnil(tolua_S);
		}
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getfetchRegexPresence3",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getfetchRegexPresence3'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_backDoneDelegate(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_backDoneDelegate'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (1 == argc)
	{
		Point arg0;
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		cobj->backDoneDelegate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_backDoneDelegate'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_computationalCollection(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_computationalCollection'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (0 == argc)
	{
		cobj->computationalCollection();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (1 == argc)
	{
		bool arg0;
		if (!ok) { 
			return 0; 
		}
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		cobj->computationalCollection(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_computationalCollection'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_setenumerationOnlyFeatures(lua_State* tolua_S)
{
	int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_setenumerationOnlyFeatures'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
    if (1 == argc)
    {
        cocos2d::Size size;
        ok &= luaval_to_size(tolua_S, 2, &size, "correspondingFunctional:setenumerationOnlyFeatures");
        if (!ok) return 0;
		cobj->setenumerationOnlyFeatures(size);
        lua_settop(tolua_S, 1);
        return 1;
    }
    return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_sizeReferencesEarlier2'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_getenumerationOnlyFeatures(lua_State* tolua_S)
{
	int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_getenumerationOnlyFeatures'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_correspondingFunctional_getenumerationOnlyFeatures'", nullptr);
            return 0;
        }
		const cocos2d::Size& ret = cobj->getenumerationOnlyFeatures();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "correspondingFunctional:getenumerationOnlyFeatures",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_getenumerationOnlyFeatures'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_roomCloseSwap(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_roomCloseSwap'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->roomCloseSwap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "roomCloseSwap",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_roomCloseSwap'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_declarationsPossibly(lua_State* tolua_S)
{
	int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_declarationsPossibly'", NULL);
        return 0;
    }
#endif
	cobj->declarationsPossibly();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_declarationsPossibly'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_collidePageProcessing(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_collidePageProcessing'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->collidePageProcessing(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "collidePageProcessing",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_collidePageProcessing'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_reasonsCeaseEvery(lua_State* tolua_S)
{
	int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_reasonsCeaseEvery'", NULL);
        return 0;
    }
#endif
	cobj->reasonsCeaseEvery();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_reasonsCeaseEvery'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_readersTemporaries(lua_State* tolua_S)
{
    int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_readersTemporaries'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->readersTemporaries(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readersTemporaries",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_readersTemporaries'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_sizeReferencesEarlier2(lua_State* tolua_S)
{
	int argc = 0;
    correspondingFunctional* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_sizeReferencesEarlier2'", NULL);
        return 0;
    }
#endif
	cobj->sizeReferencesEarlier2();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_sizeReferencesEarlier2'.",&tolua_err);
#endif
    return 0;
}
int lua_correspondingFunctional_variadicExhasutingPage4(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_variadicExhasutingPage4'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->variadicExhasutingPage4(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "variadicExhasutingPage4",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_variadicExhasutingPage4'.",&tolua_err);
#endif
	return 0;
}
int lua_correspondingFunctional_expectationsObjecUlong(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_correspondingFunctional_expectationsObjecUlong'", NULL);
		return 0;
	}
#endif
	cobj->expectationsObjecUlong();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_correspondingFunctional_expectationsObjecUlong'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setaroundSpecialActually(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setaroundSpecialActually'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setaroundSpecialActually(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setaroundSpecialActually",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setaroundSpecialActually'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getaroundSpecialActually(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getaroundSpecialActually'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getaroundSpecialActually();
		if (ret){
			tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getaroundSpecialActually",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getaroundSpecialActually'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_setgoesMultipleStop(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_setgoesMultipleStop'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setgoesMultipleStop(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setgoesMultipleStop",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_setgoesMultipleStop'.",&tolua_err);
#endif
	return 0;
}
int lua_copiedFlipsActual_getgoesMultipleStop(lua_State* tolua_S)
{
	int argc = 0;
	correspondingFunctional* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"correspondingFunctional",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (correspondingFunctional*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_copiedFlipsActual_getgoesMultipleStop'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getgoesMultipleStop();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getgoesMultipleStop",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_copiedFlipsActual_getgoesMultipleStop'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_correspondingFunctional(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"correspondingFunctional");
	tolua_cclass(tolua_S,"correspondingFunctional","correspondingFunctional","copiedFlipsActual",NULL);
		tolua_beginmodule(tolua_S,"correspondingFunctional");
			tolua_function(tolua_S, "create", lua_correspondingFunctional_create);
			tolua_function(tolua_S, "setrankedEndsDriven", lua_correspondingFunctional_setrankedEndsDriven);
			tolua_function(tolua_S, "getrankedEndsDriven", lua_correspondingFunctional_getrankedEndsDriven);
			tolua_function(tolua_S, "setworkBindsPrecedeBody", lua_correspondingFunctional_setworkBindsPrecedeBody);
			tolua_function(tolua_S, "setunorderedChartypSpelling", lua_correspondingFunctional_setunorderedChartypSpelling);
			tolua_function(tolua_S, "setnoneFunctiwithSquares", lua_correspondingFunctional_setnoneFunctiwithSquares);
			tolua_function(tolua_S, "setSpeed", lua_correspondingFunctional_setSpeed);
			tolua_function(tolua_S, "setreferencesthLegitimate", lua_correspondingFunctional_setreferencesthLegitimate);
			tolua_function(tolua_S, "setHP", lua_copiedFlipsActual_setHP);
			tolua_function(tolua_S, "getHP", lua_copiedFlipsActual_getHP);
			tolua_function(tolua_S, "isMove", lua_correspondingFunctional_isMove);
			tolua_function(tolua_S, "setMaxHP", lua_correspondingFunctional_setMaxHP);
			tolua_function(tolua_S, "getMaxHP", lua_correspondingFunctional_getMaxHP);
			tolua_function(tolua_S, "setAttack", lua_correspondingFunctional_setAttack);
			tolua_function(tolua_S, "getAttack", lua_correspondingFunctional_getAttack);
			tolua_function(tolua_S, "setName", lua_correspondingFunctional_setName);
			tolua_function(tolua_S, "getName", lua_correspondingFunctional_getName);
			tolua_function(tolua_S, "setLevel", lua_correspondingFunctional_setLevel);
			tolua_function(tolua_S, "getLevel", lua_correspondingFunctional_getLevel);
			tolua_function(tolua_S, "subBlood", lua_correspondingFunctional_subBlood);
			tolua_function(tolua_S, "qualifyingVeryExhasuting", lua_correspondingFunctional_qualifyingVeryExhasuting);
			tolua_function(tolua_S, "setthrowsConvertSignature", lua_correspondingFunctional_setthrowsConvertSignature);
			tolua_function(tolua_S, "isAlive", lua_correspondingFunctional_isAlive);
			tolua_function(tolua_S, "gethandlingWellIntend", lua_correspondingFunctional_gethandlingWellIntend);
			tolua_function(tolua_S, "getlimitedPrimerNaturally", lua_correspondingFunctional_getlimitedPrimerNaturally);
			tolua_function(tolua_S, "getwantAlgorithmNotify2", lua_correspondingFunctional_getwantAlgorithmNotify2);
		
			tolua_function(tolua_S, "getfetchRegexPresence3",              lua_correspondingFunctional_getfetchRegexPresence3);
			tolua_function(tolua_S, "setenumerationOnlyFeatures",                lua_correspondingFunctional_setenumerationOnlyFeatures);
			tolua_function(tolua_S, "getenumerationOnlyFeatures",                lua_correspondingFunctional_getenumerationOnlyFeatures);
			tolua_function(tolua_S, "roomCloseSwap",   lua_correspondingFunctional_roomCloseSwap);
			tolua_function(tolua_S, "declarationsPossibly",     lua_correspondingFunctional_declarationsPossibly);
			tolua_function(tolua_S, "collidePageProcessing",      lua_correspondingFunctional_collidePageProcessing);
			tolua_function(tolua_S, "reasonsCeaseEvery",        lua_correspondingFunctional_reasonsCeaseEvery);
			tolua_function(tolua_S, "readersTemporaries", lua_correspondingFunctional_readersTemporaries);
			tolua_function(tolua_S, "sizeReferencesEarlier2",   lua_correspondingFunctional_sizeReferencesEarlier2);
			tolua_function(tolua_S, "variadicExhasutingPage4", lua_correspondingFunctional_variadicExhasutingPage4);
			tolua_function(tolua_S, "expectationsObjecUlong",   lua_correspondingFunctional_expectationsObjecUlong);
			tolua_function(tolua_S, "backDoneDelegate",   lua_correspondingFunctional_backDoneDelegate);
			tolua_function(tolua_S, "computationalCollection",   lua_correspondingFunctional_computationalCollection);
			tolua_function(tolua_S, "setaroundSpecialActually",   lua_copiedFlipsActual_setaroundSpecialActually);
			tolua_function(tolua_S, "getaroundSpecialActually",   lua_copiedFlipsActual_getaroundSpecialActually);
			tolua_function(tolua_S, "setgoesMultipleStop",   lua_copiedFlipsActual_setgoesMultipleStop);
			tolua_function(tolua_S, "getgoesMultipleStop",   lua_copiedFlipsActual_getgoesMultipleStop);
		
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_indexingSales_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			indexingSales* ret = indexingSales::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<indexingSales>(tolua_S, "indexingSales",(indexingSales*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		std::string arg0;
		std::string arg1;
		bool arg2;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 4, &arg2);
			if (!ok) { break; }
			indexingSales* ret = indexingSales::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
				
					object_to_luaval<indexingSales>(tolua_S, "indexingSales",(indexingSales*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_create'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_setpreferDelegateBetween(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setpreferDelegateBetween'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpreferDelegateBetween(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_indexingSales_setpreferDelegateBetween",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setpreferDelegateBetween'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_getpreferDelegateBetween(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getpreferDelegateBetween'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getpreferDelegateBetween();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_indexingSales_getpreferDelegateBetween",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getpreferDelegateBetween'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setpartsDelegateCccccccccc(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setpartsDelegateCccccccccc'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0 ;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpartsDelegateCccccccccc(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpartsDelegateCccccccccc",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setpartsDelegateCccccccccc'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setbestEmptySeparatesCacall(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setbestEmptySeparatesCacall'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 9) 
	{
		int arg0;
		Vec2 arg1;
		Vec2 arg2;
		Vec2 arg3;
		Vec2 arg4;
		Vec2 arg5;
		Vec2 arg6;
		Vec2 arg7;
		Vec2 arg8;
	
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 7,&arg5);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 8,&arg6);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 9,&arg7);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 10,&arg8);
		if (!ok) { return 0; }
	
		cobj->setbestEmptySeparatesCacall(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbestEmptySeparatesCacall",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setbestEmptySeparatesCacall'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setwithBoundthatMemberwise(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setwithBoundthatMemberwise'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setwithBoundthatMemberwise(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setwithBoundthatMemberwise",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setwithBoundthatMemberwise'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setinherentlySystemEqually(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setinherentlySystemEqually'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setinherentlySystemEqually(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setinherentlySystemEqually",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setinherentlySystemEqually'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_getinherentlySystemEqually(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getinherentlySystemEqually'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getinherentlySystemEqually();
		tolua_pushnumber(tolua_S,(float)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getinherentlySystemEqually",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getinherentlySystemEqually'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setSex(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setSex'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setSex'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getSex(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getSex'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getSex();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getSex'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_setbasicsAutomaticHandling1(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setbasicsAutomaticHandling1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setbasicsAutomaticHandling1(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbasicsAutomaticHandling1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setbasicsAutomaticHandling1'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getbasicsAutomaticHandling1(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getbasicsAutomaticHandling1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getbasicsAutomaticHandling1();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getbasicsAutomaticHandling1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getbasicsAutomaticHandling1'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_setSchool(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setSchool'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setSchool(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSchool",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setSchool'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getSchool(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getSchool'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getSchool();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSchool",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getSchool'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_articlesNoteFollow(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_articlesNoteFollow'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		if(cobj->articlesNoteFollow)
			cobj->articlesNoteFollow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "articlesNoteFollow",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_articlesNoteFollow'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getSpeed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		double speed = cobj->getSpeed();
		tolua_pushnumber(tolua_S, (lua_Number)speed);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpeed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_convertibleLegitimate2(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_convertibleLegitimate2'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0 ;
		Point arg1;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		cobj->convertibleLegitimate2(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		int arg0 ;
		Point arg1;
		double arg2;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->convertibleLegitimate2(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "convertibleLegitimate2",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_convertibleLegitimate2'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_equivalentthRedefinition(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_equivalentthRedefinition'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		copiedFlipsActual *arg0;
		int arg1;
		int arg2;
		arg0 = (copiedFlipsActual*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->equivalentthRedefinition(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "equivalentthRedefinition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_equivalentthRedefinition'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_savedPointsStarts(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_savedPointsStarts'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		copiedFlipsActual *arg0;
		arg0 = (copiedFlipsActual*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		cobj->savedPointsStarts(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "savedPointsStarts",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_savedPointsStarts'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_seriousCompatible(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_seriousCompatible'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->seriousCompatible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "seriousCompatible",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_seriousCompatible'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getnocopyBlueprintAuxiliary(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getnocopyBlueprintAuxiliary'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		float ret = cobj->getnocopyBlueprintAuxiliary();
		tolua_pushnumber(tolua_S,(float)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getnocopyBlueprintAuxiliary",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getnocopyBlueprintAuxiliary'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_setActive(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setActive'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setActive(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActive",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setActive'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_getActive(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_getActive'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getActive();
		tolua_pushboolean(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActive",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_getActive'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setqualifyOtheIntuitive(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setqualifyOtheIntuitive'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setqualifyOtheIntuitive(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setqualifyOtheIntuitive",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setqualifyOtheIntuitive'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_setfeaturesIncludeClose(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setfeaturesIncludeClose'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setfeaturesIncludeClose(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setfeaturesIncludeClose",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setfeaturesIncludeClose'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_setRoleId(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_setRoleId'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		std::string arg0 ;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setRoleId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRoleId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_setRoleId'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_exchangeUnwindingChanging(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_exchangeUnwindingChanging'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		bool ret = cobj->exchangeUnwindingChanging((float)arg0,arg1,arg2,arg3);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
	if (argc == 5) 
	{
		double arg0;
		Point arg1;
		int arg2;
		bool arg3;
		bool arg4;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5,&arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 6,&arg4);
		if (!ok) { return 0; }
		bool ret = cobj->exchangeUnwindingChanging((float)arg0,arg1,arg2,arg3,arg4);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "exchangeUnwindingChanging",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_exchangeUnwindingChanging'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_wordsTendsPlaced(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_wordsTendsPlaced'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->wordsTendsPlaced(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_wordsTendsPlaced'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_definitionBefriend4(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_definitionBefriend4'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->definitionBefriend4(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_definitionBefriend4'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_legitimateDifferent(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_legitimateDifferent'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 5) 
	{
		double arg0;
		int arg1;
		int  arg2;
		int arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		cobj->legitimateDifferent(arg0, (stringsLargeEspecially)arg1, (auxiliaryEssential)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "legitimateDifferent",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_legitimateDifferent'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_signatureAdaptors1(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_signatureAdaptors1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->signatureAdaptors1(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "signatureAdaptors1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_signatureAdaptors1'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_thanShareTilde(lua_State* tolua_S)
{
	int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_thanShareTilde'", NULL);
        return 0;
    }
#endif
	cobj->thanShareTilde();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_thanShareTilde'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_circumstancesSmatchDigits(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_circumstancesSmatchDigits'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->circumstancesSmatchDigits(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "circumstancesSmatchDigits",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_circumstancesSmatchDigits'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_associativeImage(lua_State* tolua_S)
{
	int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_associativeImage'", NULL);
        return 0;
    }
#endif
	cobj->associativeImage();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_associativeImage'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_undefinedDeclaredIand(lua_State* tolua_S)
{
    int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_undefinedDeclaredIand'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->undefinedDeclaredIand(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "undefinedDeclaredIand",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_undefinedDeclaredIand'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_indirectSketchDefinitions(lua_State* tolua_S)
{
	int argc = 0;
    indexingSales* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_indirectSketchDefinitions'", NULL);
        return 0;
    }
#endif
	cobj->indirectSketchDefinitions();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_indirectSketchDefinitions'.",&tolua_err);
#endif
    return 0;
}
int lua_indexingSales_resolvesIntend(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_resolvesIntend'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->resolvesIntend(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resolvesIntend",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_resolvesIntend'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_handlesVersionSyntactic(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_handlesVersionSyntactic'", NULL);
		return 0;
	}
#endif
	cobj->handlesVersionSyntactic();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_handlesVersionSyntactic'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_differsSmartHairNonstatic(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_differsSmartHairNonstatic'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		bool ok = false;
		int arg0;
		std::string arg1;
		ok =  luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok =  luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->differsSmartHairNonstatic((extendedUsesMatch)arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "differsSmartHairNonstatic",argc, 2);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_differsSmartHairNonstatic'.",&tolua_err);
#endif
	return 0;
}
int lua_indexingSales_lockToolsEnumerationEnds(lua_State* tolua_S)
{
	int argc = 0;
	indexingSales* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"indexingSales",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (indexingSales*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_lockToolsEnumerationEnds'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		bool ok = false;
		int arg0;
		double arg1;
		double arg2;
		ok =  luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok =  luaval_to_number(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok =  luaval_to_number(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->lockToolsEnumerationEnds(arg0, (float)arg1, (float)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lockToolsEnumerationEnds",argc, 3);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_indexingSales_lockToolsEnumerationEnds'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_indexingSales(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"indexingSales");
	tolua_cclass(tolua_S,"indexingSales","indexingSales","correspondingFunctional",NULL);
		tolua_beginmodule(tolua_S,"indexingSales");
			tolua_function(tolua_S, "create", lua_indexingSales_create);
			tolua_function(tolua_S, "setinherentlySystemEqually", lua_indexingSales_setinherentlySystemEqually);
			tolua_function(tolua_S, "getinherentlySystemEqually", lua_indexingSales_getinherentlySystemEqually);
			tolua_function(tolua_S, "setwithBoundthatMemberwise", lua_indexingSales_setwithBoundthatMemberwise);
			tolua_function(tolua_S, "setpartsDelegateCccccccccc", lua_indexingSales_setpartsDelegateCccccccccc);
			tolua_function(tolua_S, "setbestEmptySeparatesCacall", lua_indexingSales_setbestEmptySeparatesCacall);
			tolua_function(tolua_S, "setpreferDelegateBetween", lua_indexingSales_setpreferDelegateBetween);
			tolua_function(tolua_S, "getpreferDelegateBetween", lua_indexingSales_getpreferDelegateBetween);
			tolua_function(tolua_S, "setSex", lua_indexingSales_setSex);
			tolua_function(tolua_S, "getSex", lua_indexingSales_getSex);
			tolua_function(tolua_S, "setbasicsAutomaticHandling1", lua_indexingSales_setbasicsAutomaticHandling1);
			tolua_function(tolua_S, "getbasicsAutomaticHandling1", lua_indexingSales_getbasicsAutomaticHandling1);
			tolua_function(tolua_S, "setSchool", lua_indexingSales_setSchool);
			tolua_function(tolua_S, "getSchool", lua_indexingSales_getSchool);
			tolua_function(tolua_S, "articlesNoteFollow", lua_indexingSales_articlesNoteFollow);
			tolua_function(tolua_S, "getSpeed", lua_indexingSales_getSpeed);
			tolua_function(tolua_S, "convertibleLegitimate2", lua_indexingSales_convertibleLegitimate2);
			tolua_function(tolua_S, "equivalentthRedefinition", lua_indexingSales_equivalentthRedefinition);
			tolua_function(tolua_S, "savedPointsStarts", lua_indexingSales_savedPointsStarts);
			tolua_function(tolua_S, "seriousCompatible", lua_indexingSales_seriousCompatible);
			tolua_function(tolua_S, "getnocopyBlueprintAuxiliary", lua_indexingSales_getnocopyBlueprintAuxiliary);
			tolua_function(tolua_S, "setActive", lua_indexingSales_setActive);
			tolua_function(tolua_S, "getActive", lua_indexingSales_getActive);
			tolua_function(tolua_S, "setqualifyOtheIntuitive", lua_indexingSales_setqualifyOtheIntuitive);
			tolua_function(tolua_S, "setRoleId", lua_indexingSales_setRoleId);
			tolua_function(tolua_S, "setfeaturesIncludeClose", lua_indexingSales_setfeaturesIncludeClose);
			tolua_function(tolua_S, "exchangeUnwindingChanging", lua_indexingSales_exchangeUnwindingChanging);
			tolua_function(tolua_S, "wordsTendsPlaced", lua_indexingSales_wordsTendsPlaced);
			tolua_function(tolua_S, "definitionBefriend4", lua_indexingSales_definitionBefriend4);
			tolua_function(tolua_S, "legitimateDifferent", lua_indexingSales_legitimateDifferent);
			tolua_function(tolua_S, "signatureAdaptors1", lua_indexingSales_signatureAdaptors1);
			tolua_function(tolua_S, "thanShareTilde",   lua_indexingSales_thanShareTilde);
			tolua_function(tolua_S, "circumstancesSmatchDigits",              lua_indexingSales_circumstancesSmatchDigits);
			tolua_function(tolua_S, "associativeImage",                lua_indexingSales_associativeImage);
			tolua_function(tolua_S, "undefinedDeclaredIand",        lua_indexingSales_undefinedDeclaredIand);
			tolua_function(tolua_S, "indirectSketchDefinitions",          lua_indexingSales_indirectSketchDefinitions);
			tolua_function(tolua_S, "resolvesIntend",				lua_indexingSales_resolvesIntend);
			tolua_function(tolua_S, "handlesVersionSyntactic",               lua_indexingSales_handlesVersionSyntactic);
			tolua_function(tolua_S, "differsSmartHairNonstatic",         lua_indexingSales_differsSmartHairNonstatic);
			tolua_function(tolua_S, "lockToolsEnumerationEnds",                  lua_indexingSales_lockToolsEnumerationEnds);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_withDesigned_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"withDesigned",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			withDesigned* ret = withDesigned::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<withDesigned>(tolua_S, "withDesigned",(withDesigned*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 0)
	{
        do 
		{
			withDesigned* ret = withDesigned::create();
			do {
				if (NULL != ret){
				
					object_to_luaval<withDesigned>(tolua_S, "withDesigned",(withDesigned*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_withDesigned_create'.",&tolua_err);
#endif
    return 0;
}
int lua_withDesigned_temporariesChapters(lua_State* tolua_S)
{
    int argc = 0;
    withDesigned* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"withDesigned",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (withDesigned*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_withDesigned_temporariesChapters'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->temporariesChapters();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "temporariesChapters",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_withDesigned_temporariesChapters'.",&tolua_err);
#endif
    return 0;
}
int lua_withDesigned_addsBasicRecompile(lua_State* tolua_S)
{
    int argc = 0;
    withDesigned* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"withDesigned",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (withDesigned*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_withDesigned_addsBasicRecompile'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->addsBasicRecompile();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addsBasicRecompile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_withDesigned_addsBasicRecompile'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_withDesigned(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"withDesigned");
	tolua_cclass(tolua_S,"withDesigned","withDesigned","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"withDesigned");
			tolua_function(tolua_S, "create", lua_withDesigned_create);
			tolua_function(tolua_S, "temporariesChapters", lua_withDesigned_temporariesChapters);
			tolua_function(tolua_S, "addsBasicRecompile", lua_withDesigned_addsBasicRecompile);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_imagethChanges_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"imagethChanges",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			imagethChanges* ret = imagethChanges::create(arg0.c_str());
			do {
				if (NULL != ret){
				
					object_to_luaval<imagethChanges>(tolua_S, "imagethChanges",(imagethChanges*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_imagethChanges_create'.",&tolua_err);
#endif
    return 0;
}
int lua_imagethChanges_setentryGeneratingParts(lua_State* tolua_S)
{
    int argc = 0;
    imagethChanges* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagethChanges",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagethChanges*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagethChanges_setentryGeneratingParts'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "imagethChanges:setentryGeneratingParts");
            if (!ok) { break; }
            cobj->setentryGeneratingParts(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setentryGeneratingParts",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagethChanges_setentryGeneratingParts'.",&tolua_err);
#endif
    return 0;
}
int lua_imagethChanges_setbrownWstringNodefault(lua_State* tolua_S)
{
    int argc = 0;
    imagethChanges* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagethChanges",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagethChanges*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagethChanges_setbrownWstringNodefault'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "imagethChanges:setbrownWstringNodefault");
            if (!ok) { break; }
            cobj->setbrownWstringNodefault(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setbrownWstringNodefault",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagethChanges_setbrownWstringNodefault'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_imagethChanges(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"imagethChanges");
	tolua_cclass(tolua_S,"imagethChanges","imagethChanges","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"imagethChanges");
			tolua_function(tolua_S, "create", lua_imagethChanges_create);
			tolua_function(tolua_S, "setentryGeneratingParts", lua_imagethChanges_setentryGeneratingParts);
			tolua_function(tolua_S, "setbrownWstringNodefault", lua_imagethChanges_setbrownWstringNodefault);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_wstringPreceding_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			wstringPreceding* ret = wstringPreceding::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<wstringPreceding>(tolua_S, "wstringPreceding",(wstringPreceding*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 2)
	{
		std::string arg0;
		int arg1 =  toluafix_ref_function(tolua_S,3,0);
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			wstringPreceding* ret = wstringPreceding::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->resourcesEvaluateBinds(arg1);
				
					object_to_luaval<wstringPreceding>(tolua_S, "wstringPreceding",(wstringPreceding*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		std::string arg0;
		int arg2;
		int arg1 =  toluafix_ref_function(tolua_S,3,0);
		do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2); 
			if (!ok) { break; }
			wstringPreceding* ret = wstringPreceding::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->resourcesEvaluateBinds(arg1);
					ret->setpreciseApplicationArrays(arg2);
				
					object_to_luaval<wstringPreceding>(tolua_S, "wstringPreceding",(wstringPreceding*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_create'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_onClick(lua_State* tolua_S)
{
	int argc = 0;
	wstringPreceding* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_onClick'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->onClick();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onClick",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_onClick'.",&tolua_err);
#endif
	return 0;
}
int lua_wstringPreceding_expandsComputingNeeded(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_articlesNoteFollow'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->expandsComputingNeeded(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "expandsComputingNeeded",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_expandsComputingNeeded'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_resourcesEvaluateBinds(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_resourcesEvaluateBinds'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->resourcesEvaluateBinds(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resourcesEvaluateBinds",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_resourcesEvaluateBinds'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_setitemContainersUnable(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_setitemContainersUnable'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setitemContainersUnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setitemContainersUnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_setitemContainersUnable'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_setSwallowTouch(lua_State* tolua_S)
{
	int argc = 0;
	wstringPreceding* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_setSwallowTouch'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setSwallowTouch(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSwallowTouch",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_setSwallowTouch'.",&tolua_err);
#endif
	return 0;
}
int lua_wstringPreceding_setEnable(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_setEnable'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setEnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_setEnable'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_sethashPointerIndeedMovement4(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_wstringPreceding_sethashPointerIndeedMovement4'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_sethashPointerIndeedMovement4'.",&tolua_err);
#endif
    return 0;
}
int lua_wstringPreceding_setbecauseProblemThenReady(lua_State* tolua_S)
{
    int argc = 0;
    wstringPreceding* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"wstringPreceding",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (wstringPreceding*)tolua_tousertype(tolua_S,1,0);
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
    tolua_error(tolua_S,"#ferror in function 'lua_wstringPreceding_setbecauseProblemThenReady'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_wstringPreceding(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"wstringPreceding");
	tolua_cclass(tolua_S,"wstringPreceding","wstringPreceding","withDesigned",NULL);
		tolua_beginmodule(tolua_S,"wstringPreceding");
			tolua_function(tolua_S, "create", lua_wstringPreceding_create);
			tolua_function(tolua_S, "expandsComputingNeeded", lua_wstringPreceding_expandsComputingNeeded);
			tolua_function(tolua_S, "onClick", lua_wstringPreceding_onClick);
			tolua_function(tolua_S, "resourcesEvaluateBinds", lua_wstringPreceding_resourcesEvaluateBinds);
			tolua_function(tolua_S, "setitemContainersUnable", lua_wstringPreceding_setitemContainersUnable);
			tolua_function(tolua_S, "setSwallowTouch", lua_wstringPreceding_setSwallowTouch);
			tolua_function(tolua_S, "setEnable", lua_wstringPreceding_setEnable);
			tolua_function(tolua_S, "sethashPointerIndeedMovement4", lua_wstringPreceding_sethashPointerIndeedMovement4);
			tolua_function(tolua_S, "setbecauseProblemThenReady", lua_wstringPreceding_setbecauseProblemThenReady);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_unrelatedNodefaultGrouped_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 2)
	{
		const char* arg0 = tolua_tostring(tolua_S,2,0);
		Size arg1;
        do 
		{
			ok &=  luaval_to_size(tolua_S,3,&arg1);
			if (!ok) { break; }
			unrelatedNodefaultGrouped* ret = unrelatedNodefaultGrouped::create(arg0,arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<unrelatedNodefaultGrouped>(tolua_S, "unrelatedNodefaultGrouped",(unrelatedNodefaultGrouped*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
	else if(argc == 3)
	{
		const char* arg0 = tolua_tostring(tolua_S,2,0);
		Size arg1;
		int arg2 =  toluafix_ref_function(tolua_S,4,0);
        do 
		{
			ok &=  luaval_to_size(tolua_S,3,&arg1);
			if (!ok) { break; }
			unrelatedNodefaultGrouped* ret = unrelatedNodefaultGrouped::create(arg0,arg1);
			do {
				if (NULL != ret && arg2){
					ret->resourcesEvaluateBinds(arg2);
				
					object_to_luaval<unrelatedNodefaultGrouped>(tolua_S, "unrelatedNodefaultGrouped",(unrelatedNodefaultGrouped*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_create'.",&tolua_err);
#endif
    return 0;
}
int lua_unrelatedNodefaultGrouped_expandsComputingNeeded(lua_State* tolua_S)
{
    int argc = 0;
    unrelatedNodefaultGrouped* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (unrelatedNodefaultGrouped*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_indexingSales_articlesNoteFollow'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->expandsComputingNeeded(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "expandsComputingNeeded",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_expandsComputingNeeded'.",&tolua_err);
#endif
    return 0;
}
int lua_unrelatedNodefaultGrouped_resourcesEvaluateBinds(lua_State* tolua_S)
{
    int argc = 0;
    unrelatedNodefaultGrouped* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (unrelatedNodefaultGrouped*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_unrelatedNodefaultGrouped_resourcesEvaluateBinds'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->resourcesEvaluateBinds(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resourcesEvaluateBinds",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_resourcesEvaluateBinds'.",&tolua_err);
#endif
    return 0;
}
int lua_unrelatedNodefaultGrouped_setitemContainersUnable(lua_State* tolua_S)
{
    int argc = 0;
    unrelatedNodefaultGrouped* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (unrelatedNodefaultGrouped*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_unrelatedNodefaultGrouped_setitemContainersUnable'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setitemContainersUnable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setitemContainersUnable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_setitemContainersUnable'.",&tolua_err);
#endif
    return 0;
}
int lua_unrelatedNodefaultGrouped_setletsBecomeImplements(lua_State* tolua_S)
{
    int argc = 0;
    unrelatedNodefaultGrouped* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (unrelatedNodefaultGrouped*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_unrelatedNodefaultGrouped_setletsBecomeImplements'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setletsBecomeImplements(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setletsBecomeImplements",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_setletsBecomeImplements'.",&tolua_err);
#endif
    return 0;
}
int lua_unrelatedNodefaultGrouped_rvalueRequestedMeans1(lua_State* tolua_S)
{
	int argc = 0;
	unrelatedNodefaultGrouped* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"unrelatedNodefaultGrouped",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (unrelatedNodefaultGrouped*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_unrelatedNodefaultGrouped_rvalueRequestedMeans1'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Rect arg0;
		ok &= luaval_to_rect(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->rvalueRequestedMeans1(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rvalueRequestedMeans1",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_unrelatedNodefaultGrouped_rvalueRequestedMeans1'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_unrelatedNodefaultGrouped(lua_State* tolua_S)
{       
    tolua_usertype(tolua_S,"unrelatedNodefaultGrouped");
	tolua_cclass(tolua_S,"unrelatedNodefaultGrouped","unrelatedNodefaultGrouped","ccui.Scale9Sprite",NULL);
		tolua_beginmodule(tolua_S,"unrelatedNodefaultGrouped");
			tolua_function(tolua_S, "create", lua_unrelatedNodefaultGrouped_create);
			tolua_function(tolua_S, "expandsComputingNeeded", lua_unrelatedNodefaultGrouped_expandsComputingNeeded);
			tolua_function(tolua_S, "resourcesEvaluateBinds", lua_unrelatedNodefaultGrouped_resourcesEvaluateBinds);
			tolua_function(tolua_S, "setitemContainersUnable", lua_unrelatedNodefaultGrouped_setitemContainersUnable);
			tolua_function(tolua_S, "setletsBecomeImplements", lua_unrelatedNodefaultGrouped_setletsBecomeImplements);
			tolua_function(tolua_S, "rvalueRequestedMeans1", lua_unrelatedNodefaultGrouped_rvalueRequestedMeans1);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_mubeParametethat_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"mubeParametethat",0,&tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2)
	{
		std::string arg0;
		std::string arg1;
		do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			mubeParametethat* ret = mubeParametethat::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<mubeParametethat>(tolua_S, "mubeParametethat",(mubeParametethat*)ret);
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
	tolua_error(tolua_S,"#ferror in function 'lua_mubeParametethat_create'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeParametethat_setaggregateQuizMaking(lua_State* tolua_S)
{
	int argc = 0;
	mubeParametethat* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeParametethat",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeParametethat*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeParametethat_setaggregateQuizMaking'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1)
	{
		Vec2 arg0;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			cobj->setaggregateQuizMaking(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 2)
	{
		Vec2 arg0;
		int arg1;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			cobj->setaggregateQuizMaking(arg0, (float)arg1);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 3)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			cobj->setaggregateQuizMaking(arg0, (float)arg1, (float)arg2);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 4)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		int arg3;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 5, &arg3);
			if (!ok) { break; }
			cobj->setaggregateQuizMaking(arg0, (float)arg1, (float)arg2, (float) arg3);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	else if (argc == 5)
	{
		Vec2 arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		do 
		{
			ok &= luaval_to_point(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 4, &arg2);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 5, &arg3);
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 6, &arg4);
			if (!ok) { break; }
			cobj->setaggregateQuizMaking(arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setaggregateQuizMaking", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeParametethat_setaggregateQuizMaking'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeParametethat_standed(lua_State* tolua_S)
{
	int argc = 0;
	mubeParametethat* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeParametethat",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeParametethat*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeParametethat_standed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->standed();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "standed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeParametethat_standed'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_mubeParametethat(lua_State* tolua_S)
{       
	tolua_usertype(tolua_S,"mubeParametethat");
	tolua_cclass(tolua_S,"mubeParametethat","mubeParametethat","copiedFlipsActual",NULL);
	tolua_beginmodule(tolua_S,"mubeParametethat");
	tolua_function(tolua_S, "create", lua_mubeParametethat_create);
	tolua_function(tolua_S, "setaggregateQuizMaking", lua_mubeParametethat_setaggregateQuizMaking);
	tolua_function(tolua_S, "standed", lua_mubeParametethat_standed);
	tolua_endmodule(tolua_S);
	return 1;
}
#endif    