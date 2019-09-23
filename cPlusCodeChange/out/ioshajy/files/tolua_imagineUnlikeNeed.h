#ifndef __TOLUA_MAPBASE_H__
#define __TOLUA_MAPBASE_H__
#include "tolua++.h"
#include "imagineUnlikeNeed.h"
#include "programRules.h"
#include "LuaBasicConversions.h"
int lua_imagineUnlikeNeed_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			imagineUnlikeNeed* ret = imagineUnlikeNeed::create();
			do {
				if (NULL != ret){
					object_to_luaval<imagineUnlikeNeed>(tolua_S, "imagineUnlikeNeed",(imagineUnlikeNeed*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_create'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_create1(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 3)
	{
		std::string arg0;
		int arg1;
		bool arg2;
		cocos2d::Point arg3;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			ok &= luaval_to_int32(tolua_S, 3, &arg1); 
			if (!ok) { break; }
			ok &= luaval_to_boolean(tolua_S, 3, &arg2); 
			if (!ok) { break; }
			ok &= luaval_to_point(tolua_S, 4, &arg3); 
			if (!ok) { break; }
			imagineUnlikeNeed* ret = imagineUnlikeNeed::create(arg0,arg1,arg2, arg3);
			do {
				if (NULL != ret){
					object_to_luaval<imagineUnlikeNeed>(tolua_S, "imagineUnlikeNeed",(imagineUnlikeNeed*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_create'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getrecentlyIsbnsInput(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "imagineUnlikeNeed", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		float ret = imagineUnlikeNeed::getrecentlyIsbnsInput();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getrecentlyIsbnsInput", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_imagineUnlikeNeed_getrecentlyIsbnsInput'.", &tolua_err);
#endif
				return 0;
}
int lua_imagineUnlikeNeed_setrecentlyIsbnsInput(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "imagineUnlikeNeed", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_imagineUnlikeNeed_setrecentlyIsbnsInput'", nullptr);
			return 0;
		}
		imagineUnlikeNeed::setrecentlyIsbnsInput(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setrecentlyIsbnsInput", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_imagineUnlikeNeed_setrecentlyIsbnsInput'.", &tolua_err);
#endif
				return 0;
}
int lua_imagineUnlikeNeed_loadMap(lua_State* tolua_S)
{
   int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
	#endif
		cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setupdatesPersistSpecifying3'", NULL);
			return 0;
		}
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 5)
	{
		std::string arg0;
		std::string arg1;
		int arg2;
		bool arg3;
		cocos2d::Point arg4;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		 
		ok &= luaval_to_int32(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5, &arg3); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 6, &arg4); 
		if (!ok) { return 0; }
		cobj->loadMap(arg0,arg1,arg2, arg3,arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "loadMap",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_loadMap'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_evaluatedCoveredUltimate(lua_State* tolua_S)
{
   int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
	#endif
		cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_evaluatedCoveredUltimate'", NULL);
			return 0;
		}
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		cobj->evaluatedCoveredUltimate();
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "evaluatedCoveredUltimate",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_evaluatedCoveredUltimate'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_setupdatesPersistSpecifying3(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setupdatesPersistSpecifying3'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		assumeApproachEmbodies* ret = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,2,0);
	
				cobj->setupdatesPersistSpecifying3(ret);
				lua_settop(tolua_S, 1);
				return 1;
	
	
	
	
       
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setupdatesPersistSpecifying3",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setupdatesPersistSpecifying3'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getupdatesPersistSpecifying3(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getupdatesPersistSpecifying3'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		assumeApproachEmbodies* ret = cobj->getupdatesPersistSpecifying3();
		do {
			if (NULL != ret){
				tolua_pushusertype(tolua_S,(void*)ret,"assumeApproachEmbodies");
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getupdatesPersistSpecifying3",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getupdatesPersistSpecifying3'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_setareaClosesIncrements(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setareaClosesIncrements'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setareaClosesIncrements(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setareaClosesIncrements",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setareaClosesIncrements'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_setencloseEqualsResetPrecise(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setencloseEqualsResetPrecise'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->setencloseEqualsResetPrecise(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setencloseEqualsResetPrecise",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setencloseEqualsResetPrecise'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_setneededForgetReturns(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setneededForgetReturns'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setneededForgetReturns(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setneededForgetReturns",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setneededForgetReturns'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_wmustInitializationsSafe(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_wmustInitializationsSafe'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->wmustInitializationsSafe(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "wmustInitializationsSafe",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_wmustInitializationsSafe'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_genericCompletes(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_genericCompletes'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->genericCompletes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 2) 
    {
		Point arg0;
		bool arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S,3, &arg1); 
		if (!ok) { return 0; }
		cobj->genericCompletes(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 3) 
	{
		Point arg0;
		bool arg1;
		int arg2;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S,3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		cobj->genericCompletes(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "genericCompletes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_genericCompletes'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_developedObtainPair(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_developedObtainPair'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		Point arg0;
		labelsPointRepresentation* arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (labelsPointRepresentation*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		Point arg4[256];  
		int ret = cobj->developedObtainPair(arg0,arg1,3.0,true,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
    }
	else if (argc == 4||argc == 3) 
	{
		Point arg0;
		labelsPointRepresentation* arg1;
		double arg2;
		bool arg3 = true;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (labelsPointRepresentation*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		ok &= luaval_to_number(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		if(argc == 4)
		{
			ok &= luaval_to_boolean(tolua_S, 5, &arg3); 
			if (!ok) { return 0; }
		}
		Point arg4[256];  
		int ret = cobj->developedObtainPair(arg0,arg1,(float)arg2,arg3,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "developedObtainPair",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_developedObtainPair'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_matterAppliedStrcmp(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_matterAppliedStrcmp'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1){
		labelsPointRepresentation* arg0;
		ok &= luaval_to_object<labelsPointRepresentation>(tolua_S, 2, "labelsPointRepresentation",&arg0, "matterAppliedStrcmp");
		if (!ok) { return 0; }
		cobj->matterAppliedStrcmp(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 2) 
	{
		labelsPointRepresentation* arg0;
		Point arg1;
		ok &= luaval_to_object<labelsPointRepresentation>(tolua_S, 2, "labelsPointRepresentation",&arg0, "matterAppliedStrcmp");
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->matterAppliedStrcmp(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "matterAppliedStrcmp",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_matterAppliedStrcmp'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_initializtheTookEven(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_initializtheTookEven'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->initializtheTookEven(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initializtheTookEven",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_initializtheTookEven'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_applicableInstances(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_applicableInstances'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->applicableInstances(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "applicableInstances",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_applicableInstances'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_inverselyThpositionComes(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_inverselyThpositionComes'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->inverselyThpositionComes(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "inverselyThpositionComes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_inverselyThpositionComes'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_contextNameEnumeration(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_contextNameEnumeration'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->contextNameEnumeration(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 2) 
    {
		Point arg0;
		double arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->contextNameEnumeration(arg0,(float)arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "contextNameEnumeration",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_contextNameEnumeration'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_skip2Tile(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_skip2Tile'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->skip2Tile(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "skip2Tile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_skip2Tile'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_followLargeLabeled(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_followLargeLabeled'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->followLargeLabeled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 2) 
    {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->followLargeLabeled(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "followLargeLabeled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_followLargeLabeled'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_modifyEntirePowerful2(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_modifyEntirePowerful2'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->modifyEntirePowerful2();
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->modifyEntirePowerful2(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 2) 
    {
		Point arg0;
		bool arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->modifyEntirePowerful2(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "modifyEntirePowerful2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_modifyEntirePowerful2'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getshorttypOrdinaryOught(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getshorttypOrdinaryOught'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->getshorttypOrdinaryOught((accessedIntroductory)arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getshorttypOrdinaryOught",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getshorttypOrdinaryOught'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getdebuggingRespective(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getdebuggingRespective'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		accessedIntroductory ret = cobj->getdebuggingRespective(arg0);
        lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getdebuggingRespective",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getdebuggingRespective'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_existLettersPermitted1(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_existLettersPermitted1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->existLettersPermitted1(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "existLettersPermitted1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_existLettersPermitted1'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_basicsDrivenRandom2(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_basicsDrivenRandom2'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->basicsDrivenRandom2(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "basicsDrivenRandom2",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_basicsDrivenRandom2'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_employeeResulting(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_employeeResulting'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->employeeResulting(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "employeeResulting",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_employeeResulting'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_ostreamSupportsUser(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_ostreamSupportsUser'", NULL);
        return 0;
    }
#endif
	cobj->ostreamSupportsUser();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_ostreamSupportsUser'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_accessibleFunctionGoes(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_accessibleFunctionGoes'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->accessibleFunctionGoes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "accessibleFunctionGoes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_accessibleFunctionGoes'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_appropriateAreaDetermine(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_appropriateAreaDetermine'", NULL);
        return 0;
    }
#endif
	cobj->appropriateAreaDetermine();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_appropriateAreaDetermine'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_headActuallySchema4(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_headActuallySchema4'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->headActuallySchema4(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "headActuallySchema4",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_headActuallySchema4'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_unorderedOverloaded(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_unorderedOverloaded'", NULL);
        return 0;
    }
#endif
	cobj->unorderedOverloaded();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_unorderedOverloaded'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_incompleteElementsStorage(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_incompleteElementsStorage'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok =  luaval_to_boolean(tolua_S,2,&arg0);
		if (!ok) { return 0; }
		cobj->incompleteElementsStorage(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) 
	{
		bool arg0;
		Point arg1;
		ok =  luaval_to_boolean(tolua_S,2,&arg0);
		if (!ok) { return 0; }
		ok =  luaval_to_point(tolua_S,3,&arg1);
		if (!ok) { return 0; }
		cobj->incompleteElementsStorage(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "incompleteElementsStorage",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_incompleteElementsStorage'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_undefinedparameters(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_guaranteedFallThdefines'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->undefinedparameters(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "accessibleFunctionGoes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_guaranteedFallThdefines'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_conventionFollowUnscoped(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_conventionFollowUnscoped'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0)
	{
		cobj->conventionFollowUnscoped(0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->conventionFollowUnscoped(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "conventionFollowUnscoped",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_conventionFollowUnscoped'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_chparameterSpecification(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_chparameterSpecification'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		double arg0;
		double arg1;
		Point arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		bool ret = cobj->chparameterSpecification((float)arg0,arg1,arg2);
		tolua_pushboolean(tolua_S, ret);
		return 1;
	}
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_chparameterSpecification'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_guaranteedFallThdefines(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_guaranteedFallThdefines'", NULL);
        return 0;
    }
#endif
	cobj->guaranteedFallThdefines();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_guaranteedFallThdefines'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_isBlock(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_isBlock'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		bool ret = cobj->isBlock(arg0);
        lua_pushboolean(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBlock",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_isBlock'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_findAlthoughOkay(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_findAlthoughOkay'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		bool ret = cobj->findAlthoughOkay();
        lua_pushboolean(tolua_S, ret);
        return 1;
    }
	else if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		bool ret = cobj->findAlthoughOkay(arg0);
		lua_pushboolean(tolua_S, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "findAlthoughOkay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_findAlthoughOkay'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_isOpacity(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_isBlock'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		bool ret = cobj->isOpacity(arg0);
        lua_pushboolean(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_isOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getwcouldCoverConstructors(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getwcouldCoverConstructors'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		int ret = cobj->getwcouldCoverConstructors(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getwcouldCoverConstructors",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getwcouldCoverConstructors'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_controlSpelling(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_controlSpelling'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
    {
		cobj->controlSpelling();
		lua_settop(tolua_S, 1);
		return 1;
    }
    else if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->controlSpelling(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 2) 
	{
		bool arg0;
		bool arg1;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->controlSpelling(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 3) 
	{
		bool arg0;
		bool arg1;
		bool arg2;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
	
		ok &= luaval_to_boolean(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
	
		ok &= luaval_to_boolean(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		cobj->controlSpelling(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "controlSpelling",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_controlSpelling'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_moreIndicesTypeids4(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_moreIndicesTypeids4'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->moreIndicesTypeids4();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moreIndicesTypeids4",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_moreIndicesTypeids4'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_getformComparingDirection(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getformComparingDirection'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
	
		Point arg0;
		Point arg1;
		bool  selfFlg = false;
		Point arg2[1024];
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		int ret = cobj->getformComparingDirection(arg0,arg1,selfFlg,arg2);
        vec2_array_to_luaval(tolua_S, arg2, ret);
        return 1;
    }
	else if (argc == 3) 
	{
		Point arg0;
		Point arg1;
		bool  selfFlg;
		Point arg2[1024];
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &selfFlg); 
		if (!ok) { return 0; }
		int ret = cobj->getformComparingDirection(arg0,arg1,selfFlg,arg2);
		vec2_array_to_luaval(tolua_S, arg2, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getformComparingDirection",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getformComparingDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_worksBraceRefers(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_worksBraceRefers'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->worksBraceRefers(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "worksBraceRefers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_worksBraceRefers'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getSpeed'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_getLayerSize(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getLayerSize'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_imagineUnlikeNeed_getLayerSize'", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getLayerSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "imagineUnlikeNeed:getLayerSize",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getLayerSize'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_getMapTileSize(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_getMapTileSize'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_imagineUnlikeNeed_getMapTileSize'", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getMapTileSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "imagineUnlikeNeed:getMapTileSize",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_getLayerSize'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_hasBlock(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_hasBlock'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		Point arg0;
		Point arg1;
	
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		bool ret = cobj->hasBlock(arg0,arg1);
		lua_pushboolean(tolua_S, ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hasBlock",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'hasBlock'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_readingAgreeGeneral(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_readingAgreeGeneral'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->readingAgreeGeneral(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readingAgreeGeneral",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_readingAgreeGeneral'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_removeTopHeadNodeToMapCb(lua_State* tolua_S)
{
    int argc = 0;
    imagineUnlikeNeed* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_removeTopHeadNodeToMapCb'", NULL);
        return 0;
    }
#endif
	cobj->whappearsCastCannotBookno();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_removeTopHeadNodeToMapCb'.",&tolua_err);
#endif
    return 0;
}
int lua_imagineUnlikeNeed_setadvancedImpactHandled(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setadvancedImpactHandled'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 = luaval_to_int32(tolua_S, 2, &arg0); 
		if (!arg0) { return 0; }
		cobj->setadvancedImpactHandled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setadvancedImpactHandled'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_setorientedLargerEnds(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_setorientedLargerEnds'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		Node* arg0 = nullptr;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "setorientedLargerEnds");
		if (!ok) { return 0; }
		cobj->setorientedLargerEnds(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if(argc == 0)
	{
		cobj->setorientedLargerEnds(nullptr);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setorientedLargerEnds", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_setorientedLargerEnds'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_declarationsBracketTrying(lua_State* tolua_S)
{
	int argc = 0;
	imagineUnlikeNeed* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"imagineUnlikeNeed",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (imagineUnlikeNeed*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_imagineUnlikeNeed_declarationsBracketTrying'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0 = false;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setdeclarationsBracketTrying(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "declarationsBracketTrying", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_declarationsBracketTrying'.",&tolua_err);
#endif
	return 0;
}
int lua_imagineUnlikeNeed_andqueryFunctiwith(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "imagineUnlikeNeed", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) 
	{
		std::string arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		imagineUnlikeNeed::andqueryFunctiwith(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5)
	{
		std::string arg0;
		int arg1;
		int arg2;
		int arg3;
		int arg4;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 6, &arg4);
		if (!ok) { return 0; }
		imagineUnlikeNeed::andqueryFunctiwith(arg0,arg1,arg2,arg3,arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "andqueryFunctiwith", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_imagineUnlikeNeed_andqueryFunctiwith'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_imagineUnlikeNeed(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"imagineUnlikeNeed");
	tolua_cclass(tolua_S,"imagineUnlikeNeed","imagineUnlikeNeed","cc.Layer",NULL);
		tolua_beginmodule(tolua_S,"imagineUnlikeNeed");
			tolua_function(tolua_S, "create", lua_imagineUnlikeNeed_create);
			tolua_function(tolua_S, "setrecentlyIsbnsInput", lua_imagineUnlikeNeed_setrecentlyIsbnsInput);
			tolua_function(tolua_S, "getrecentlyIsbnsInput", lua_imagineUnlikeNeed_getrecentlyIsbnsInput);
			tolua_function(tolua_S, "loadMap", lua_imagineUnlikeNeed_loadMap);
			tolua_function(tolua_S, "evaluatedCoveredUltimate", lua_imagineUnlikeNeed_evaluatedCoveredUltimate);
			tolua_function(tolua_S, "getupdatesPersistSpecifying3", lua_imagineUnlikeNeed_getupdatesPersistSpecifying3);
			tolua_function(tolua_S, "setupdatesPersistSpecifying3", lua_imagineUnlikeNeed_setupdatesPersistSpecifying3);
			tolua_function(tolua_S, "wmustInitializationsSafe", lua_imagineUnlikeNeed_wmustInitializationsSafe);
			tolua_function(tolua_S, "genericCompletes", lua_imagineUnlikeNeed_genericCompletes);
			tolua_function(tolua_S, "developedObtainPair", lua_imagineUnlikeNeed_developedObtainPair);	
			tolua_function(tolua_S, "genericCompletesition", lua_imagineUnlikeNeed_initializtheTookEven);	
			tolua_function(tolua_S, "matterAppliedStrcmp", lua_imagineUnlikeNeed_matterAppliedStrcmp);
			tolua_function(tolua_S, "applicableInstances", lua_imagineUnlikeNeed_applicableInstances);
			tolua_function(tolua_S, "inverselyThpositionComes", lua_imagineUnlikeNeed_inverselyThpositionComes);
			tolua_function(tolua_S, "contextNameEnumeration", lua_imagineUnlikeNeed_contextNameEnumeration);
			tolua_function(tolua_S, "skip2Tile", lua_imagineUnlikeNeed_skip2Tile);
			tolua_function(tolua_S, "followLargeLabeled", lua_imagineUnlikeNeed_followLargeLabeled);
			tolua_function(tolua_S, "modifyEntirePowerful2", lua_imagineUnlikeNeed_modifyEntirePowerful2);
			tolua_function(tolua_S, "getshorttypOrdinaryOught", lua_imagineUnlikeNeed_getshorttypOrdinaryOught);
			tolua_function(tolua_S, "getdebuggingRespective", lua_imagineUnlikeNeed_getdebuggingRespective);
			tolua_function(tolua_S, "existLettersPermitted1", lua_imagineUnlikeNeed_existLettersPermitted1);
			tolua_function(tolua_S, "employeeResulting", lua_imagineUnlikeNeed_employeeResulting);
			tolua_function(tolua_S, "basicsDrivenRandom2", lua_imagineUnlikeNeed_basicsDrivenRandom2);
			tolua_function(tolua_S, "ostreamSupportsUser", lua_imagineUnlikeNeed_ostreamSupportsUser);
			tolua_function(tolua_S, "accessibleFunctionGoes", lua_imagineUnlikeNeed_accessibleFunctionGoes);
			tolua_function(tolua_S, "appropriateAreaDetermine", lua_imagineUnlikeNeed_appropriateAreaDetermine);
			tolua_function(tolua_S, "headActuallySchema4", lua_imagineUnlikeNeed_headActuallySchema4);
			tolua_function(tolua_S, "unorderedOverloaded", lua_imagineUnlikeNeed_unorderedOverloaded);
			tolua_function(tolua_S, "undefinedparameters", lua_imagineUnlikeNeed_undefinedparameters);
			tolua_function(tolua_S, "conventionFollowUnscoped", lua_imagineUnlikeNeed_conventionFollowUnscoped);
			tolua_function(tolua_S, "incompleteElementsStorage", lua_imagineUnlikeNeed_incompleteElementsStorage);
			tolua_function(tolua_S, "guaranteedFallThdefines", lua_imagineUnlikeNeed_guaranteedFallThdefines);
			tolua_function(tolua_S, "chparameterSpecification", lua_imagineUnlikeNeed_chparameterSpecification);
			tolua_function(tolua_S, "isBlock", lua_imagineUnlikeNeed_isBlock);
			tolua_function(tolua_S, "isOpacity", lua_imagineUnlikeNeed_isOpacity);
			tolua_function(tolua_S, "getwcouldCoverConstructors", lua_imagineUnlikeNeed_getwcouldCoverConstructors);
			tolua_function(tolua_S, "findAlthoughOkay", lua_imagineUnlikeNeed_findAlthoughOkay);
			tolua_function(tolua_S, "setareaClosesIncrements", lua_imagineUnlikeNeed_setareaClosesIncrements);
			tolua_function(tolua_S, "setneededForgetReturns", lua_imagineUnlikeNeed_setneededForgetReturns);
			tolua_function(tolua_S, "setencloseEqualsResetPrecise", lua_imagineUnlikeNeed_setencloseEqualsResetPrecise);
			tolua_function(tolua_S, "controlSpelling", lua_imagineUnlikeNeed_controlSpelling);
			tolua_function(tolua_S, "moreIndicesTypeids4", lua_imagineUnlikeNeed_moreIndicesTypeids4);
			tolua_function(tolua_S, "getformComparingDirection", lua_imagineUnlikeNeed_getformComparingDirection);
			tolua_function(tolua_S, "worksBraceRefers", lua_imagineUnlikeNeed_worksBraceRefers);
			tolua_function(tolua_S, "getSpeed", lua_imagineUnlikeNeed_getSpeed);
			tolua_function(tolua_S, "getLayerSize", lua_imagineUnlikeNeed_getLayerSize);
			tolua_function(tolua_S, "getMapTileSize", lua_imagineUnlikeNeed_getMapTileSize);
			tolua_function(tolua_S, "hasBlock", lua_imagineUnlikeNeed_hasBlock);
			tolua_function(tolua_S, "readingAgreeGeneral", lua_imagineUnlikeNeed_readingAgreeGeneral);
			tolua_function(tolua_S, "removeTopHeadNodeToMapCb",      lua_imagineUnlikeNeed_removeTopHeadNodeToMapCb);
			tolua_function(tolua_S, "setadvancedImpactHandled",      lua_imagineUnlikeNeed_setadvancedImpactHandled);
			tolua_function(tolua_S, "setorientedLargerEnds",      lua_imagineUnlikeNeed_setorientedLargerEnds);
			tolua_function(tolua_S, "userOldMoveMap",      lua_imagineUnlikeNeed_declarationsBracketTrying);
			tolua_function(tolua_S, "andqueryFunctiwith",      lua_imagineUnlikeNeed_andqueryFunctiwith);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_programRules_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"programRules",0,&tolua_err)) 
		goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			programRules* ret = programRules::create();
			do 
			{
				if (NULL != ret)
				{
					object_to_luaval<programRules>(tolua_S, "programRules",(programRules*)ret);
				}
				else
				{
					lua_pushnil(tolua_S);
				} 
			}
			while (0);
			return 1;
		} 
		while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_programRules_create'.",&tolua_err);
#endif
	return 0;
}
int lua_programRules_setwarrantWhtheState(lua_State* tolua_S)
{
	int argc = 0;
	programRules* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"programRules",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (programRules*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_programRules_setwarrantWhtheState'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0;
		ok = luaval_to_number(tolua_S, 2, &arg0);
		if (!arg0) { return 0; }
		cobj->setwarrantWhtheState(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_programRules_setwarrantWhtheState'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_programRules(lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"programRules");
	tolua_cclass(tolua_S,"programRules","programRules","cc.Layer",NULL);
	tolua_beginmodule(tolua_S,"programRules"); 
	tolua_function(tolua_S, "create", lua_programRules_create);
	tolua_function(tolua_S, "setwarrantWhtheState", lua_programRules_setwarrantWhtheState);
	tolua_endmodule(tolua_S);
	return 1;
}
#endif    