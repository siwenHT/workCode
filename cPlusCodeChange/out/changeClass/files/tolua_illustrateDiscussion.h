#ifndef __TOLUA_MAPBASE_H__
#define __TOLUA_MAPBASE_H__
#include "tolua++.h"
#include "illustrateDiscussion.h"
#include "sectionsBlockIntended.h"
#include "LuaBasicConversions.h"
int lua_illustrateDiscussion_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			illustrateDiscussion* ret = illustrateDiscussion::create();
			do {
				if (NULL != ret){
					object_to_luaval<illustrateDiscussion>(tolua_S, "illustrateDiscussion",(illustrateDiscussion*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_create'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_create1(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
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
			illustrateDiscussion* ret = illustrateDiscussion::create(arg0,arg1,arg2, arg3);
			do {
				if (NULL != ret){
					object_to_luaval<illustrateDiscussion>(tolua_S, "illustrateDiscussion",(illustrateDiscussion*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_create'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getenumeratorsContaiany(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "illustrateDiscussion", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		float ret = illustrateDiscussion::getenumeratorsContaiany();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getenumeratorsContaiany", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_illustrateDiscussion_getenumeratorsContaiany'.", &tolua_err);
#endif
				return 0;
}
int lua_illustrateDiscussion_setenumeratorsContaiany(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "illustrateDiscussion", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_illustrateDiscussion_setenumeratorsContaiany'", nullptr);
			return 0;
		}
		illustrateDiscussion::setenumeratorsContaiany(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setenumeratorsContaiany", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_illustrateDiscussion_setenumeratorsContaiany'.", &tolua_err);
#endif
				return 0;
}
int lua_illustrateDiscussion_loadMap(lua_State* tolua_S)
{
   int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
	#endif
		cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setconfidentKindActions'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_loadMap'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_areaOnceAccumulate4(lua_State* tolua_S)
{
   int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
	#endif
		cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_areaOnceAccumulate4'", NULL);
			return 0;
		}
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		cobj->areaOnceAccumulate4();
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "areaOnceAccumulate4",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_areaOnceAccumulate4'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_setconfidentKindActions(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setconfidentKindActions'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		indexingSales* ret = (indexingSales*)tolua_tousertype(tolua_S,2,0);
	
				cobj->setconfidentKindActions(ret);
				lua_settop(tolua_S, 1);
				return 1;
	
	
	
	
       
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setconfidentKindActions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setconfidentKindActions'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getconfidentKindActions(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getconfidentKindActions'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		indexingSales* ret = cobj->getconfidentKindActions();
		do {
			if (NULL != ret){
				tolua_pushusertype(tolua_S,(void*)ret,"indexingSales");
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getconfidentKindActions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getconfidentKindActions'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_setpageObjectsApplied(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setpageObjectsApplied'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setpageObjectsApplied(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpageObjectsApplied",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setpageObjectsApplied'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_setallowRepresentingComplex(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setallowRepresentingComplex'", NULL);
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
		cobj->setallowRepresentingComplex(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setallowRepresentingComplex",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setallowRepresentingComplex'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_setnormallyMultidimensional(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setnormallyMultidimensional'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setnormallyMultidimensional(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setnormallyMultidimensional",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setnormallyMultidimensional'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_printsTakingHigher(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_printsTakingHigher'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->printsTakingHigher(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "printsTakingHigher",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_printsTakingHigher'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_ofileHeaderPrevented(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_ofileHeaderPrevented'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->ofileHeaderPrevented(arg0);
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
		cobj->ofileHeaderPrevented(arg0,arg1);
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
		cobj->ofileHeaderPrevented(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ofileHeaderPrevented",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_ofileHeaderPrevented'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_relevantCmatchWrite(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_relevantCmatchWrite'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
		Point arg0;
		correspondingFunctional* arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (correspondingFunctional*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		Point arg4[256];  
		int ret = cobj->relevantCmatchWrite(arg0,arg1,3.0,true,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
    }
	else if (argc == 4||argc == 3) 
	{
		Point arg0;
		correspondingFunctional* arg1;
		double arg2;
		bool arg3 = true;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (correspondingFunctional*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		ok &= luaval_to_number(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		if(argc == 4)
		{
			ok &= luaval_to_boolean(tolua_S, 5, &arg3); 
			if (!ok) { return 0; }
		}
		Point arg4[256];  
		int ret = cobj->relevantCmatchWrite(arg0,arg1,(float)arg2,arg3,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "relevantCmatchWrite",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_relevantCmatchWrite'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_preserveFixedCollide(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_preserveFixedCollide'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1){
		correspondingFunctional* arg0;
		ok &= luaval_to_object<correspondingFunctional>(tolua_S, 2, "correspondingFunctional",&arg0, "preserveFixedCollide");
		if (!ok) { return 0; }
		cobj->preserveFixedCollide(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 2) 
	{
		correspondingFunctional* arg0;
		Point arg1;
		ok &= luaval_to_object<correspondingFunctional>(tolua_S, 2, "correspondingFunctional",&arg0, "preserveFixedCollide");
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->preserveFixedCollide(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preserveFixedCollide",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_preserveFixedCollide'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_returnsSaveIntroduce(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_returnsSaveIntroduce'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->returnsSaveIntroduce(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "returnsSaveIntroduce",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_returnsSaveIntroduce'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_saysPlaceAggregate(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_saysPlaceAggregate'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->saysPlaceAggregate(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "saysPlaceAggregate",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_saysPlaceAggregate'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_indeedScopeHeldSource(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_indeedScopeHeldSource'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->indeedScopeHeldSource(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "indeedScopeHeldSource",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_indeedScopeHeldSource'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_nodefaultComparePrompt(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_nodefaultComparePrompt'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->nodefaultComparePrompt(arg0);
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
		cobj->nodefaultComparePrompt(arg0,(float)arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nodefaultComparePrompt",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_nodefaultComparePrompt'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_skip2Tile(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_skip2Tile'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_skip2Tile'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_reallocatesOpenLonger1(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_reallocatesOpenLonger1'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->reallocatesOpenLonger1(arg0);
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
		cobj->reallocatesOpenLonger1(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reallocatesOpenLonger1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_reallocatesOpenLonger1'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_wefifthUnformatted(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_wefifthUnformatted'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->wefifthUnformatted();
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->wefifthUnformatted(arg0);
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
		cobj->wefifthUnformatted(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "wefifthUnformatted",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_wefifthUnformatted'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getpointersSomewhereAssume(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getpointersSomewhereAssume'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->getpointersSomewhereAssume((auxiliaryEssential)arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getpointersSomewhereAssume",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getpointersSomewhereAssume'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getfollowingPersist(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getfollowingPersist'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		auxiliaryEssential ret = cobj->getfollowingPersist(arg0);
        lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getfollowingPersist",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getfollowingPersist'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_writeListedCalc(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_writeListedCalc'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->writeListedCalc(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeListedCalc",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_writeListedCalc'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_varyGetsOverhead(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_varyGetsOverhead'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->varyGetsOverhead(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "varyGetsOverhead",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_varyGetsOverhead'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_assignmentChanges3(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_assignmentChanges3'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->assignmentChanges3(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assignmentChanges3",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_assignmentChanges3'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_connectionCalledDynamic(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_connectionCalledDynamic'", NULL);
        return 0;
    }
#endif
	cobj->connectionCalledDynamic();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_connectionCalledDynamic'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_placeDestructorGenerates(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_placeDestructorGenerates'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->placeDestructorGenerates(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "placeDestructorGenerates",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_placeDestructorGenerates'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_shouldRelationship(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_shouldRelationship'", NULL);
        return 0;
    }
#endif
	cobj->shouldRelationship();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_shouldRelationship'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_thereAbilityOtherwise(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_thereAbilityOtherwise'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->thereAbilityOtherwise(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "thereAbilityOtherwise",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_thereAbilityOtherwise'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_tokensTreturnValueduring(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_tokensTreturnValueduring'", NULL);
        return 0;
    }
#endif
	cobj->tokensTreturnValueduring();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_tokensTreturnValueduring'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_representMatchAllowed(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_representMatchAllowed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok =  luaval_to_boolean(tolua_S,2,&arg0);
		if (!ok) { return 0; }
		cobj->representMatchAllowed(arg0);
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
		cobj->representMatchAllowed(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "representMatchAllowed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_representMatchAllowed'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_machineBracketConstitutes(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_runsPropertiesGranting'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->machineBracketConstitutes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "placeDestructorGenerates",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_runsPropertiesGranting'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_beginExercisesExpanded(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_beginExercisesExpanded'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0)
	{
		cobj->beginExercisesExpanded(0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->beginExercisesExpanded(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "beginExercisesExpanded",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_beginExercisesExpanded'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_argumentsUnwindingRewrite(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_argumentsUnwindingRewrite'", NULL);
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
		bool ret = cobj->argumentsUnwindingRewrite((float)arg0,arg1,arg2);
		tolua_pushboolean(tolua_S, ret);
		return 1;
	}
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_argumentsUnwindingRewrite'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_runsPropertiesGranting(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_runsPropertiesGranting'", NULL);
        return 0;
    }
#endif
	cobj->runsPropertiesGranting();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_runsPropertiesGranting'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_isBlock(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_isBlock'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_isBlock'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_functionalthoughSerial(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_functionalthoughSerial'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		bool ret = cobj->functionalthoughSerial();
        lua_pushboolean(tolua_S, ret);
        return 1;
    }
	else if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		bool ret = cobj->functionalthoughSerial(arg0);
		lua_pushboolean(tolua_S, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "functionalthoughSerial",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_functionalthoughSerial'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_isOpacity(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_isBlock'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_isOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getmainHaveRegardless(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getmainHaveRegardless'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		int ret = cobj->getmainHaveRegardless(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getmainHaveRegardless",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getmainHaveRegardless'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_lookingPresumablyArraythe5(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_lookingPresumablyArraythe5'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
    {
		cobj->lookingPresumablyArraythe5();
		lua_settop(tolua_S, 1);
		return 1;
    }
    else if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->lookingPresumablyArraythe5(arg0);
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
		cobj->lookingPresumablyArraythe5(arg0, arg1);
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
		cobj->lookingPresumablyArraythe5(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lookingPresumablyArraythe5",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_lookingPresumablyArraythe5'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_operationCorresponds(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_operationCorresponds'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->operationCorresponds();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "operationCorresponds",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_operationCorresponds'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_getsuppliesLimitedDenote(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getsuppliesLimitedDenote'", NULL);
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
		int ret = cobj->getsuppliesLimitedDenote(arg0,arg1,selfFlg,arg2);
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
		int ret = cobj->getsuppliesLimitedDenote(arg0,arg1,selfFlg,arg2);
		vec2_array_to_luaval(tolua_S, arg2, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getsuppliesLimitedDenote",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getsuppliesLimitedDenote'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_articlesNoteFollow(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_articlesNoteFollow'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->articlesNoteFollow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "articlesNoteFollow",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_articlesNoteFollow'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getSpeed'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_getLayerSize(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getLayerSize'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_illustrateDiscussion_getLayerSize'", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getLayerSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "illustrateDiscussion:getLayerSize",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getLayerSize'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_getMapTileSize(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_getMapTileSize'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_illustrateDiscussion_getMapTileSize'", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getMapTileSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "illustrateDiscussion:getMapTileSize",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_getLayerSize'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_hasBlock(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_hasBlock'", NULL);
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
int lua_illustrateDiscussion_forgotMovesOperating(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_forgotMovesOperating'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->forgotMovesOperating(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "forgotMovesOperating",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_forgotMovesOperating'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_removeTopHeadNodeToMapCb(lua_State* tolua_S)
{
    int argc = 0;
    illustrateDiscussion* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_removeTopHeadNodeToMapCb'", NULL);
        return 0;
    }
#endif
	cobj->memberRecentlyResetTells();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_removeTopHeadNodeToMapCb'.",&tolua_err);
#endif
    return 0;
}
int lua_illustrateDiscussion_setvalueParametersOperations(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setvalueParametersOperations'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 = luaval_to_int32(tolua_S, 2, &arg0); 
		if (!arg0) { return 0; }
		cobj->setvalueParametersOperations(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setvalueParametersOperations'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_setsupplyingMultidimensional(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_setsupplyingMultidimensional'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		Node* arg0 = nullptr;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "setsupplyingMultidimensional");
		if (!ok) { return 0; }
		cobj->setsupplyingMultidimensional(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if(argc == 0)
	{
		cobj->setsupplyingMultidimensional(nullptr);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsupplyingMultidimensional", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_setsupplyingMultidimensional'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_memoryCopiesAuthor(lua_State* tolua_S)
{
	int argc = 0;
	illustrateDiscussion* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"illustrateDiscussion",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (illustrateDiscussion*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_illustrateDiscussion_memoryCopiesAuthor'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0 = false;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setmemoryCopiesAuthor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "memoryCopiesAuthor", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_memoryCopiesAuthor'.",&tolua_err);
#endif
	return 0;
}
int lua_illustrateDiscussion_worksTheareAuthor(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "illustrateDiscussion", 0, &tolua_err)) goto tolua_lerror;
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
		illustrateDiscussion::worksTheareAuthor(arg0,arg1,arg2);
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
		illustrateDiscussion::worksTheareAuthor(arg0,arg1,arg2,arg3,arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "worksTheareAuthor", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_illustrateDiscussion_worksTheareAuthor'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_illustrateDiscussion(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"illustrateDiscussion");
	tolua_cclass(tolua_S,"illustrateDiscussion","illustrateDiscussion","cc.Layer",NULL);
		tolua_beginmodule(tolua_S,"illustrateDiscussion");
			tolua_function(tolua_S, "create", lua_illustrateDiscussion_create);
			tolua_function(tolua_S, "setenumeratorsContaiany", lua_illustrateDiscussion_setenumeratorsContaiany);
			tolua_function(tolua_S, "getenumeratorsContaiany", lua_illustrateDiscussion_getenumeratorsContaiany);
			tolua_function(tolua_S, "loadMap", lua_illustrateDiscussion_loadMap);
			tolua_function(tolua_S, "areaOnceAccumulate4", lua_illustrateDiscussion_areaOnceAccumulate4);
			tolua_function(tolua_S, "getconfidentKindActions", lua_illustrateDiscussion_getconfidentKindActions);
			tolua_function(tolua_S, "setconfidentKindActions", lua_illustrateDiscussion_setconfidentKindActions);
			tolua_function(tolua_S, "printsTakingHigher", lua_illustrateDiscussion_printsTakingHigher);
			tolua_function(tolua_S, "ofileHeaderPrevented", lua_illustrateDiscussion_ofileHeaderPrevented);
			tolua_function(tolua_S, "relevantCmatchWrite", lua_illustrateDiscussion_relevantCmatchWrite);	
			tolua_function(tolua_S, "ofileHeaderPreventedition", lua_illustrateDiscussion_returnsSaveIntroduce);	
			tolua_function(tolua_S, "preserveFixedCollide", lua_illustrateDiscussion_preserveFixedCollide);
			tolua_function(tolua_S, "saysPlaceAggregate", lua_illustrateDiscussion_saysPlaceAggregate);
			tolua_function(tolua_S, "indeedScopeHeldSource", lua_illustrateDiscussion_indeedScopeHeldSource);
			tolua_function(tolua_S, "nodefaultComparePrompt", lua_illustrateDiscussion_nodefaultComparePrompt);
			tolua_function(tolua_S, "skip2Tile", lua_illustrateDiscussion_skip2Tile);
			tolua_function(tolua_S, "reallocatesOpenLonger1", lua_illustrateDiscussion_reallocatesOpenLonger1);
			tolua_function(tolua_S, "wefifthUnformatted", lua_illustrateDiscussion_wefifthUnformatted);
			tolua_function(tolua_S, "getpointersSomewhereAssume", lua_illustrateDiscussion_getpointersSomewhereAssume);
			tolua_function(tolua_S, "getfollowingPersist", lua_illustrateDiscussion_getfollowingPersist);
			tolua_function(tolua_S, "writeListedCalc", lua_illustrateDiscussion_writeListedCalc);
			tolua_function(tolua_S, "assignmentChanges3", lua_illustrateDiscussion_assignmentChanges3);
			tolua_function(tolua_S, "varyGetsOverhead", lua_illustrateDiscussion_varyGetsOverhead);
			tolua_function(tolua_S, "connectionCalledDynamic", lua_illustrateDiscussion_connectionCalledDynamic);
			tolua_function(tolua_S, "placeDestructorGenerates", lua_illustrateDiscussion_placeDestructorGenerates);
			tolua_function(tolua_S, "shouldRelationship", lua_illustrateDiscussion_shouldRelationship);
			tolua_function(tolua_S, "thereAbilityOtherwise", lua_illustrateDiscussion_thereAbilityOtherwise);
			tolua_function(tolua_S, "tokensTreturnValueduring", lua_illustrateDiscussion_tokensTreturnValueduring);
			tolua_function(tolua_S, "machineBracketConstitutes", lua_illustrateDiscussion_machineBracketConstitutes);
			tolua_function(tolua_S, "beginExercisesExpanded", lua_illustrateDiscussion_beginExercisesExpanded);
			tolua_function(tolua_S, "representMatchAllowed", lua_illustrateDiscussion_representMatchAllowed);
			tolua_function(tolua_S, "runsPropertiesGranting", lua_illustrateDiscussion_runsPropertiesGranting);
			tolua_function(tolua_S, "argumentsUnwindingRewrite", lua_illustrateDiscussion_argumentsUnwindingRewrite);
			tolua_function(tolua_S, "isBlock", lua_illustrateDiscussion_isBlock);
			tolua_function(tolua_S, "isOpacity", lua_illustrateDiscussion_isOpacity);
			tolua_function(tolua_S, "getmainHaveRegardless", lua_illustrateDiscussion_getmainHaveRegardless);
			tolua_function(tolua_S, "functionalthoughSerial", lua_illustrateDiscussion_functionalthoughSerial);
			tolua_function(tolua_S, "setpageObjectsApplied", lua_illustrateDiscussion_setpageObjectsApplied);
			tolua_function(tolua_S, "setnormallyMultidimensional", lua_illustrateDiscussion_setnormallyMultidimensional);
			tolua_function(tolua_S, "setallowRepresentingComplex", lua_illustrateDiscussion_setallowRepresentingComplex);
			tolua_function(tolua_S, "lookingPresumablyArraythe5", lua_illustrateDiscussion_lookingPresumablyArraythe5);
			tolua_function(tolua_S, "operationCorresponds", lua_illustrateDiscussion_operationCorresponds);
			tolua_function(tolua_S, "getsuppliesLimitedDenote", lua_illustrateDiscussion_getsuppliesLimitedDenote);
			tolua_function(tolua_S, "articlesNoteFollow", lua_illustrateDiscussion_articlesNoteFollow);
			tolua_function(tolua_S, "getSpeed", lua_illustrateDiscussion_getSpeed);
			tolua_function(tolua_S, "getLayerSize", lua_illustrateDiscussion_getLayerSize);
			tolua_function(tolua_S, "getMapTileSize", lua_illustrateDiscussion_getMapTileSize);
			tolua_function(tolua_S, "hasBlock", lua_illustrateDiscussion_hasBlock);
			tolua_function(tolua_S, "forgotMovesOperating", lua_illustrateDiscussion_forgotMovesOperating);
			tolua_function(tolua_S, "removeTopHeadNodeToMapCb",      lua_illustrateDiscussion_removeTopHeadNodeToMapCb);
			tolua_function(tolua_S, "setvalueParametersOperations",      lua_illustrateDiscussion_setvalueParametersOperations);
			tolua_function(tolua_S, "setsupplyingMultidimensional",      lua_illustrateDiscussion_setsupplyingMultidimensional);
			tolua_function(tolua_S, "userOldMoveMap",      lua_illustrateDiscussion_memoryCopiesAuthor);
			tolua_function(tolua_S, "worksTheareAuthor",      lua_illustrateDiscussion_worksTheareAuthor);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_sectionsBlockIntended_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"sectionsBlockIntended",0,&tolua_err)) 
		goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			sectionsBlockIntended* ret = sectionsBlockIntended::create();
			do 
			{
				if (NULL != ret)
				{
					object_to_luaval<sectionsBlockIntended>(tolua_S, "sectionsBlockIntended",(sectionsBlockIntended*)ret);
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
	tolua_error(tolua_S,"#ferror in function 'lua_sectionsBlockIntended_create'.",&tolua_err);
#endif
	return 0;
}
int lua_sectionsBlockIntended_setpairwiseCompiledTyhave(lua_State* tolua_S)
{
	int argc = 0;
	sectionsBlockIntended* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"sectionsBlockIntended",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (sectionsBlockIntended*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_sectionsBlockIntended_setpairwiseCompiledTyhave'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0;
		ok = luaval_to_number(tolua_S, 2, &arg0);
		if (!arg0) { return 0; }
		cobj->setpairwiseCompiledTyhave(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_sectionsBlockIntended_setpairwiseCompiledTyhave'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_sectionsBlockIntended(lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"sectionsBlockIntended");
	tolua_cclass(tolua_S,"sectionsBlockIntended","sectionsBlockIntended","cc.Layer",NULL);
	tolua_beginmodule(tolua_S,"sectionsBlockIntended"); 
	tolua_function(tolua_S, "create", lua_sectionsBlockIntended_create);
	tolua_function(tolua_S, "setpairwiseCompiledTyhave", lua_sectionsBlockIntended_setpairwiseCompiledTyhave);
	tolua_endmodule(tolua_S);
	return 1;
}
#endif    