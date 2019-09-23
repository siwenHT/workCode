#ifndef __TOLUA_SPRITEBASE_H__
#define __TOLUA_SPRITEBASE_H__
#include "tolua++.h"
#include "labelsPointRepresentation.h"
#include "assumeApproachEmbodies.h"
#include "LuaBasicConversions.h"
#include "bookstoreEmployee.h"
#include "appliedDifferenceNoted.h"
#include "refersEnums.h"
#include "predictedReverseWhich.h"
#include "complicationAproblems.h"
int lua_addingRelies_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			addingRelies* ret = addingRelies::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<addingRelies>(tolua_S, "addingRelies",(addingRelies*)ret);
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
			addingRelies* ret = addingRelies::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<addingRelies>(tolua_S, "addingRelies",(addingRelies*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_create'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_reset(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_reset'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_reset'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setordinarilyUpdate(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setordinarilyUpdate'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setordinarilyUpdate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setordinarilyUpdate",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setordinarilyUpdate'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setembodiesSolveReplaces(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setembodiesSolveReplaces'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setembodiesSolveReplaces(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setembodiesSolveReplaces",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setembodiesSolveReplaces'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setappropriateMubeWorries(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setappropriateMubeWorries'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setappropriateMubeWorries(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setappropriateMubeWorries",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setappropriateMubeWorries'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setreviseStringWhen(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setreviseStringWhen'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setreviseStringWhen(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setreviseStringWhen",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setreviseStringWhen'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_nonexternTakingDeal(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_nonexternTakingDeal'", NULL);
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
		cobj->nonexternTakingDeal(arg0,arg1,arg2,arg3,arg4,arg5,(float)arg6,(accessedIntroductory)arg7);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nonexternTakingDeal",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_nonexternTakingDeal'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_overrideControlProhibit2(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_overrideControlProhibit2'", NULL);
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
		cobj->overrideControlProhibit2(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "overrideControlProhibit2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_overrideControlProhibit2'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_thumbLimitationAcross(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_thumbLimitationAcross'", NULL);
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
		cobj->thumbLimitationAcross(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "thumbLimitationAcross",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_thumbLimitationAcross'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_specifiesSignals(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_specifiesSignals'", NULL);
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
		cobj->specifiesSignals(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "specifiesSignals",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_specifiesSignals'.",&tolua_err);
#endif
	return 0;
}
	int lua_addingRelies_complexityTogetherForm(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_complexityTogetherForm'", NULL);
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
		cobj->complexityTogetherForm(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "complexityTogetherForm",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_complexityTogetherForm'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_olderDetailIdentifying(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_olderDetailIdentifying'", NULL);
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
		cobj->olderDetailIdentifying(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "olderDetailIdentifying",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_olderDetailIdentifying'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getIsHide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setIsHide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setinvokesTheyLook(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setinvokesTheyLook'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setinvokesTheyLook(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setinvokesTheyLook",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setinvokesTheyLook'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_noteArrowPrints(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_noteArrowPrints'", NULL);
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
		cobj->noteArrowPrints(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "noteArrowPrints",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_noteArrowPrints'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_parametisAllow(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_parametisAllow'", NULL);
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
		cobj->parametisAllow(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parametisAllow",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_parametisAllow'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_standed(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_standed'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_standed'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_standedby(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_standedby'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_standedby'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setoperationAssumeFriends(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setoperationAssumeFriends'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setoperationAssumeFriends(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setoperationAssumeFriends",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setoperationAssumeFriends'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setneedsTreturnDeclaration(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setneedsTreturnDeclaration'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setneedsTreturnDeclaration(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setneedsTreturnDeclaration",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setneedsTreturnDeclaration'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setOnRide(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setOnRide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setOnRide'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getprintsGenerateSearch(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getprintsGenerateSearch'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		std::string ret = cobj->getprintsGenerateSearch();
		tolua_pushstring(tolua_S, ret.c_str());
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getprintsGenerateSearch",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getprintsGenerateSearch'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getOnRide(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getOnRide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getOnRide'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getprimaryFactIterator(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getprimaryFactIterator'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getprimaryFactIterator();
		tolua_pushnumber(tolua_S, ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getprimaryFactIterator",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getprimaryFactIterator'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_existingLargerGrasp(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_existingLargerGrasp'", NULL);
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
		bool ret = cobj->existingLargerGrasp((float)arg0,arg1,(accessedIntroductory)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "existingLargerGrasp",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_existingLargerGrasp'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_reasonsHaveBecause(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_reasonsHaveBecause'", NULL);
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
		bool ret = cobj->reasonsHaveBecause((float)arg0,arg1);
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
		bool ret = cobj->reasonsHaveBecause((float)arg0,arg1,(accessedIntroductory)arg2);
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
		bool ret = cobj->reasonsHaveBecause((float)arg0,arg1,(accessedIntroductory)arg2,arg3);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reasonsHaveBecause",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_reasonsHaveBecause'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_occurrenceTightlySignals(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_occurrenceTightlySignals'", NULL);
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
		cobj->occurrenceTightlySignals((float)arg0,arg1,(accessedIntroductory)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "occurrenceTightlySignals",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_occurrenceTightlySignals'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_copiedMostPreferred(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_copiedMostPreferred'", NULL);
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
		bool ret = cobj->copiedMostPreferred((float)arg0,arg1,(accessedIntroductory)arg2);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copiedMostPreferred",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_copiedMostPreferred'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_informationDefineSees(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_informationDefineSees'", NULL);
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
		bool ret = cobj->informationDefineSees((float)arg0,(accessedIntroductory)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "informationDefineSees",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_informationDefineSees'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_othersBecauseAbstraction(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_othersBecauseAbstraction'", NULL);
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
		bool ret = cobj->othersBecauseAbstraction((float)arg0,(accessedIntroductory)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "othersBecauseAbstraction",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_othersBecauseAbstraction'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_occurStatementDimension(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_occurStatementDimension'", NULL);
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
		bool ret = cobj->occurStatementDimension((float)arg0,(accessedIntroductory)arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "occurStatementDimension",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_occurStatementDimension'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_whateverEvaluatesDerived(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
    tolua_Error tolua_err;
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_whateverEvaluatesDerived'", NULL);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,0);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3,(accessedIntroductory)arg4);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3,(accessedIntroductory)arg4,arg5);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3,(accessedIntroductory)arg4,arg5,arg6);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3,(accessedIntroductory)arg4,arg5,arg6,arg7);
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
		cobj->whateverEvaluatesDerived((float)arg0,arg1,arg2,arg3,(accessedIntroductory)arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "whateverEvaluatesDerived",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_whateverEvaluatesDerived'.",&tolua_err);
    return 0;
}
int lua_addingRelies_rewritesRedeclareLooth(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_rewritesRedeclareLooth'", NULL);
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
		cobj->rewritesRedeclareLooth((float)arg0,arg1);
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
		cobj->rewritesRedeclareLooth((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rewritesRedeclareLooth",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_rewritesRedeclareLooth'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_datsuchWhenDefinitions(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_datsuchWhenDefinitions'", NULL);
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
		cobj->datsuchWhenDefinitions((float)arg0,arg1);
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
		cobj->datsuchWhenDefinitions((float)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "datsuchWhenDefinitions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_datsuchWhenDefinitions'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_moveToPos(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_moveToPos'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_moveToPos'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_walkToPos(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_walkToPos'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_walkToPos'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_promotionBound(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_promotionBound'", NULL);
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
		cobj->promotionBound(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "promotionBound",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_promotionBound'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_unequalParticularFreed(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_unequalParticularFreed'", NULL);
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
		bool ret = cobj->unequalParticularFreed((float)arg0,arg1);
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
		bool ret = cobj->unequalParticularFreed((float)arg0,arg1,arg2);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unequalParticularFreed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_unequalParticularFreed'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_waysExonlyBackslashNever(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_waysExonlyBackslashNever'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		bool ret = cobj->waysExonlyBackslashNever((float)arg0,Point::ZERO);
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
		bool ret = cobj->waysExonlyBackslashNever((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "waysExonlyBackslashNever",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_waysExonlyBackslashNever'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_assumingFirstGenerally2(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_assumingFirstGenerally2'", NULL);
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
		cobj->assumingFirstGenerally2(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assumingFirstGenerally2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_assumingFirstGenerally2'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_parenthesesRelevant(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_parenthesesRelevant'", NULL);
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
		bool ret = cobj->parenthesesRelevant((float)arg0,arg1);
		lua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parenthesesRelevant",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_parenthesesRelevant'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_implementingAllocateIndex(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_promotionBound'", NULL);
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
		cobj->implementingAllocateIndex(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "implementingAllocateIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_implementingAllocateIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_hasHurted(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_hasHurted'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_hasHurted'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_gotoDeath(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_gotoDeath'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->gotoDeath((accessedIntroductory)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoDeath",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_gotoDeath'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setreduceRecognize(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setreduceRecognize'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0=true;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setreduceRecognize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setreduceRecognize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setreduceRecognize'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_moreIdenticalOperations(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_moreIdenticalOperations'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Touch* arg0 = (Touch*)tolua_tousertype(tolua_S,2,0);
		if (!arg0) { return 0; }
		bool ret = cobj->moreIdenticalOperations(arg0);
		if (ret){
				tolua_pushboolean(tolua_S,(bool)ret);
		}
		else
			lua_pushnil(tolua_S);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moreIdenticalOperations",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_moreIdenticalOperations'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setOpacity'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setColor(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setColor'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setgaveObjectsthBasic(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setgaveObjectsthBasic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setgaveObjectsthBasic(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setgaveObjectsthBasic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setgaveObjectsthBasic'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getgaveObjectsthBasic(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getgaveObjectsthBasic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getgaveObjectsthBasic();
		tolua_pushnumber(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getgaveObjectsthBasic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getgaveObjectsthBasic'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setGray(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setGray'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setGray'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setWhite(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setWhite'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setWhite'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getOpacity'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setisbnsConstexprBuild(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setisbnsConstexprBuild'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setisbnsConstexprBuild((accessedIntroductory)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setisbnsConstexprBuild",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setisbnsConstexprBuild'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_cerrResultsThroughCeases(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_cerrResultsThroughCeases'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->cerrResultsThroughCeases((pushBoundthat)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cerrResultsThroughCeases",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_cerrResultsThroughCeases'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getinstantiatingBindRegular(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getinstantiatingBindRegular'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		accessedIntroductory ret = cobj->getinstantiatingBindRegular();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getinstantiatingBindRegular",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getinstantiatingBindRegular'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setspecializedComplication(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setspecializedComplication'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0 ;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setspecializedComplication((pushBoundthat)arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setspecializedComplication",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setspecializedComplication'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getspecializedComplication(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getspecializedComplication'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		pushBoundthat ret = cobj->getspecializedComplication();
		if(ret > 0)
		{
			tolua_pushnumber(tolua_S,(int)ret);
			return 1;
		}
		else
			lua_pushnil(tolua_S);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getspecializedComplication",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getspecializedComplication'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setType(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setType'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setTypeId((wantedConvertibleGroup)arg0);
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
		cobj->setTypeId((wantedConvertibleGroup)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setType'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setfriendsSimplifyDeleter(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setType'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setfriendsSimplifyDeleter((wantedConvertibleGroup)arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_addingRelies_setfriendsSimplifyDeleter",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_lua_addingRelies_setfriendsSimplifyDeleter'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getthoughHighSure(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getthoughHighSure'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		bool ret = cobj->getthoughHighSure();
		tolua_pushboolean(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getthoughHighSure",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getthoughHighSure'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getType(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getType'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getType'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_booksChoseExploit(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_booksChoseExploit'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg = 0;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->booksChoseExploit((pushBoundthat)arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "booksChoseExploit",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_booksChoseExploit'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_refresh(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_refresh'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_refresh'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getrankedClauseHowevewe(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getrankedClauseHowevewe'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		std::string ret = (std::string)cobj->getrankedClauseHowevewe();
		if (ret != "") { tolua_pushstring(tolua_S,ret.c_str());}
		else { lua_pushnil(tolua_S); }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getrankedClauseHowevewe",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getrankedClauseHowevewe'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setrankedClauseHowevewe(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setrankedClauseHowevewe'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		std::string arg0 = "";
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setrankedClauseHowevewe(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrankedClauseHowevewe",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setrankedClauseHowevewe'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_bitsManyUnlike(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_bitsManyUnlike'", NULL);
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
		cobj->bitsManyUnlike(arg0, (soonAlongMemberwise)arg1, (accessedIntroductory)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "bitsManyUnlike",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_bitsManyUnlike'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getLocalZOrder(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getLocalZOrder'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getLocalZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getthreeLoopsOperatingMatter(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getthreeLoopsOperatingMatter'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getthreeLoopsOperatingMatter();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getthreeLoopsOperatingMatter",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getthreeLoopsOperatingMatter'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_imageRevisedCaltoFront(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_imageRevisedCaltoFront'", NULL);
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
		cobj->imageRevisedCaltoFront(arg0, (soonAlongMemberwise)arg1, (accessedIntroductory)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "imageRevisedCaltoFront",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_imageRevisedCaltoFront'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getpatternResultNodefault(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getpatternResultNodefault'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getpatternResultNodefault();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getpatternResultNodefault",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getpatternResultNodefault'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setpatternResultNodefault(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setpatternResultNodefault'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setpatternResultNodefault(arg);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpatternResultNodefault",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setpatternResultNodefault'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setprogrammingQualifying(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setprogrammingQualifying'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg;
		ok &= luaval_to_int32(tolua_S, 2, &arg);
		if (!ok) { return 0; }
		cobj->setprogrammingQualifying(arg);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setprogrammingQualifying",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setprogrammingQualifying'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setResId(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setResId'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setResId'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getResId(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getResId'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getResId'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_setdeductionNeverBehind(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setdeductionNeverBehind'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setdeductionNeverBehind(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdeductionNeverBehind",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setdeductionNeverBehind'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getdeductionNeverBehind(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getdeductionNeverBehind'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		const cocos2d::Point& ret = cobj->getdeductionNeverBehind();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getdeductionNeverBehind",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getdeductionNeverBehind'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getlookupRecompilingVector(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getlookupRecompilingVector'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getlookupRecompilingVector();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getlookupRecompilingVector",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getlookupRecompilingVector'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setlookupRecompilingVector(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setlookupRecompilingVector'", NULL);
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
			cobj->setlookupRecompilingVector(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlookupRecompilingVector",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setlookupRecompilingVector'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getdigitsParameteaWhat3(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getdigitsParameteaWhat3'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getdigitsParameteaWhat3();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "v",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getdigitsParameteaWhat3'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getFather(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getFather'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		addingRelies* ret = cobj->getFather();
		do {
			if (NULL != ret){
				object_to_luaval<addingRelies>(tolua_S, "addingRelies",(addingRelies*)ret);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getFather'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setFather(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setFather'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		do 
		{
			addingRelies* arg0 = (addingRelies*)tolua_tousertype(tolua_S, 2,0); 
			if (!ok) { break; }
			cobj->setFather(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_addingRelies_setFather",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setFather'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setcompilerStoprocessing(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setcompilerStoprocessing'", NULL);
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
			cobj->setcompilerStoprocessing(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_addingRelies_setcompilerStoprocessing",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setcompilerStoprocessing'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getaverageIdentification(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getaverageIdentification'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getaverageIdentification();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getaverageIdentification",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getaverageIdentification'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setaverageIdentification(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setaverageIdentification'", NULL);
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
			cobj->setaverageIdentification(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setaverageIdentification",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setaverageIdentification'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_printedClosePeppers(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_printedClosePeppers'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->printedClosePeppers(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "printedClosePeppers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_printedClosePeppers'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_operationDesigning(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_operationDesigning'", NULL);
        return 0;
    }
#endif
	cobj->operationDesigning();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_operationDesigning'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_assignReliesSeparator(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_assignReliesSeparator'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->assignReliesSeparator(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "assignReliesSeparator",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_assignReliesSeparator'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_compilationCerrIntended(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_compilationCerrIntended'", NULL);
        return 0;
    }
#endif
	cobj->compilationCerrIntended();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_compilationCerrIntended'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_relativeEcmascriptBuilt(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_relativeEcmascriptBuilt'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->relativeEcmascriptBuilt(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "relativeEcmascriptBuilt",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_relativeEcmascriptBuilt'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_tuplesCandidateTopics(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_tuplesCandidateTopics'", NULL);
		return 0;
	}
#endif
	cobj->tuplesCandidateTopics();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_tuplesCandidateTopics'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_wilreferKnowsInvolved(lua_State* tolua_S)
{
    int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_wilreferKnowsInvolved'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->wilreferKnowsInvolved(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "wilreferKnowsInvolved",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_wilreferKnowsInvolved'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_matrixExecutingCompilers(lua_State* tolua_S)
{
	int argc = 0;
    addingRelies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_matrixExecutingCompilers'", NULL);
        return 0;
    }
#endif
	cobj->matrixExecutingCompilers();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_matrixExecutingCompilers'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_strvecCurrentPushed(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_strvecCurrentPushed'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->strvecCurrentPushed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "strvecCurrentPushed",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_strvecCurrentPushed'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_unlessSupplyTreated(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_unlessSupplyTreated'", NULL);
		return 0;
	}
#endif
	cobj->unlessSupplyTreated();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_unlessSupplyTreated'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_effectEliminatedReference(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_effectEliminatedReference'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S, 2, 0);
		if (!arg0) { return 0; }
		cobj->effectEliminatedReference(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "effectEliminatedReference",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_effectEliminatedReference'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_parametersunlikeRemoved(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_parametersunlikeRemoved'", NULL);
		return 0;
	}
#endif
	cobj->parametersunlikeRemoved();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_parametersunlikeRemoved'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setprvoidExtensioindicating(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setprvoidExtensioindicating'", NULL);
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
			cobj->setprvoidExtensioindicating(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setprvoidExtensioindicating",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setprvoidExtensioindicating'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setiandRelativeAssigns(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setiandRelativeAssigns'", NULL);
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
			cobj->setiandRelativeAssigns(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setiandRelativeAssigns",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setiandRelativeAssigns'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_FixFlyPos(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_FixFlyPos'", NULL);
		return 0;
	}
#endif
	cobj->FixFlyPos();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_FixFlyPos'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setRenderMode(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setRenderMode'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setRenderMode'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getmemberEscapeHowevewe(lua_State* tolua_S)
{
	int argc = 0;
	addingRelies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"addingRelies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (addingRelies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getmemberEscapeHowevewe'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getmemberEscapeHowevewe();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getmemberEscapeHowevewe", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getmemberEscapeHowevewe'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_addingRelies(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"addingRelies");
	tolua_cclass(tolua_S,"addingRelies","addingRelies","cc.Node",NULL);
		tolua_beginmodule(tolua_S,"addingRelies");
			tolua_function(tolua_S, "create", lua_addingRelies_create);
			tolua_function(tolua_S, "reset", lua_addingRelies_reset);
			tolua_function(tolua_S, "setordinarilyUpdate", lua_addingRelies_setordinarilyUpdate);
			tolua_function(tolua_S, "setappropriateMubeWorries", lua_addingRelies_setappropriateMubeWorries);
			tolua_function(tolua_S, "setembodiesSolveReplaces", lua_addingRelies_setembodiesSolveReplaces);
			tolua_function(tolua_S, "setreviseStringWhen", lua_addingRelies_setreviseStringWhen);
			tolua_function(tolua_S, "nonexternTakingDeal", lua_addingRelies_nonexternTakingDeal);
			tolua_function(tolua_S, "overrideControlProhibit2", lua_addingRelies_overrideControlProhibit2);
			tolua_function(tolua_S, "thumbLimitationAcross", lua_addingRelies_thumbLimitationAcross);
			tolua_function(tolua_S, "specifiesSignals", lua_addingRelies_specifiesSignals);
			tolua_function(tolua_S, "complexityTogetherForm", lua_addingRelies_complexityTogetherForm);
			tolua_function(tolua_S, "olderDetailIdentifying", lua_addingRelies_olderDetailIdentifying);
			tolua_function(tolua_S, "noteArrowPrints", lua_addingRelies_noteArrowPrints);
			tolua_function(tolua_S, "getIsHide", lua_addingRelies_getIsHide);
			tolua_function(tolua_S, "setIsHide", lua_addingRelies_setIsHide);
			tolua_function(tolua_S, "setinvokesTheyLook", lua_addingRelies_setinvokesTheyLook);
			tolua_function(tolua_S, "parametisAllow", lua_addingRelies_parametisAllow);
			tolua_function(tolua_S, "standed", lua_addingRelies_standed);
			tolua_function(tolua_S, "standedby", lua_addingRelies_standedby);
			tolua_function(tolua_S, "setoperationAssumeFriends", lua_addingRelies_setoperationAssumeFriends);
			tolua_function(tolua_S, "setneedsTreturnDeclaration", lua_addingRelies_setneedsTreturnDeclaration);
			tolua_function(tolua_S, "existingLargerGrasp", lua_addingRelies_existingLargerGrasp);
			tolua_function(tolua_S, "reasonsHaveBecause", lua_addingRelies_reasonsHaveBecause);
			tolua_function(tolua_S, "occurrenceTightlySignals", lua_addingRelies_occurrenceTightlySignals);
			tolua_function(tolua_S, "copiedMostPreferred", lua_addingRelies_copiedMostPreferred);
			tolua_function(tolua_S, "informationDefineSees", lua_addingRelies_informationDefineSees);
			tolua_function(tolua_S, "occurStatementDimension", lua_addingRelies_occurStatementDimension);
			tolua_function(tolua_S, "othersBecauseAbstraction", lua_addingRelies_othersBecauseAbstraction);		
			tolua_function(tolua_S, "whateverEvaluatesDerived", lua_addingRelies_whateverEvaluatesDerived);
			tolua_function(tolua_S, "rewritesRedeclareLooth", lua_addingRelies_rewritesRedeclareLooth);
			tolua_function(tolua_S, "datsuchWhenDefinitions", lua_addingRelies_datsuchWhenDefinitions);
			tolua_function(tolua_S, "moveToPos", lua_addingRelies_moveToPos);
			tolua_function(tolua_S, "walkToPos", lua_addingRelies_walkToPos);
			tolua_function(tolua_S, "promotionBound", lua_addingRelies_promotionBound);
			tolua_function(tolua_S, "unequalParticularFreed", lua_addingRelies_unequalParticularFreed);
		
		
			tolua_function(tolua_S, "waysExonlyBackslashNever", lua_addingRelies_waysExonlyBackslashNever);	
			tolua_function(tolua_S, "assumingFirstGenerally2", lua_addingRelies_assumingFirstGenerally2);
			tolua_function(tolua_S, "parenthesesRelevant", lua_addingRelies_parenthesesRelevant);
			tolua_function(tolua_S, "implementingAllocateIndex", lua_addingRelies_implementingAllocateIndex);
			tolua_function(tolua_S, "hasHurted", lua_addingRelies_hasHurted);
			tolua_function(tolua_S, "gotoDeath", lua_addingRelies_gotoDeath);
			tolua_function(tolua_S, "moreIdenticalOperations", lua_addingRelies_moreIdenticalOperations);
			tolua_function(tolua_S, "setreduceRecognize", lua_addingRelies_setreduceRecognize);
			tolua_function(tolua_S, "setColor", lua_addingRelies_setColor);
			tolua_function(tolua_S, "setGray", lua_addingRelies_setGray);
			tolua_function(tolua_S, "setWhite", lua_addingRelies_setWhite);
			tolua_function(tolua_S, "setOpacity", lua_addingRelies_setOpacity);
			tolua_function(tolua_S, "getOpacity", lua_addingRelies_getOpacity);
			tolua_function(tolua_S, "setspecializedComplication", lua_addingRelies_setspecializedComplication);
			tolua_function(tolua_S, "getspecializedComplication", lua_addingRelies_getspecializedComplication);
			tolua_function(tolua_S, "setisbnsConstexprBuild", lua_addingRelies_setisbnsConstexprBuild);
			tolua_function(tolua_S, "cerrResultsThroughCeases", lua_addingRelies_cerrResultsThroughCeases);
			tolua_function(tolua_S, "getinstantiatingBindRegular", lua_addingRelies_getinstantiatingBindRegular);
			tolua_function(tolua_S, "setType", lua_addingRelies_setType);
			tolua_function(tolua_S, "getType", lua_addingRelies_getType);
			tolua_function(tolua_S, "setgaveObjectsthBasic", lua_addingRelies_setgaveObjectsthBasic);
			tolua_function(tolua_S, "getgaveObjectsthBasic", lua_addingRelies_getgaveObjectsthBasic);			
			tolua_function(tolua_S, "getthoughHighSure", lua_addingRelies_getthoughHighSure);
			tolua_function(tolua_S, "booksChoseExploit", lua_addingRelies_booksChoseExploit);
			tolua_function(tolua_S, "refresh", lua_addingRelies_refresh);
			tolua_function(tolua_S, "setfriendsSimplifyDeleter", lua_addingRelies_setfriendsSimplifyDeleter);
		
			tolua_function(tolua_S, "getrankedClauseHowevewe",     lua_addingRelies_getrankedClauseHowevewe);
			tolua_function(tolua_S, "setrankedClauseHowevewe",     lua_addingRelies_setrankedClauseHowevewe);
			tolua_function(tolua_S, "bitsManyUnlike",     lua_addingRelies_bitsManyUnlike);
			tolua_function(tolua_S, "getLocalZOrder", lua_addingRelies_getLocalZOrder); 
			tolua_function(tolua_S, "imageRevisedCaltoFront", lua_addingRelies_imageRevisedCaltoFront);
			tolua_function(tolua_S, "getthreeLoopsOperatingMatter", lua_addingRelies_getthreeLoopsOperatingMatter);
			tolua_function(tolua_S, "setpatternResultNodefault",  lua_addingRelies_setpatternResultNodefault);
			tolua_function(tolua_S, "getpatternResultNodefault",  lua_addingRelies_getpatternResultNodefault);
			tolua_function(tolua_S, "setprogrammingQualifying",  lua_addingRelies_setprogrammingQualifying);
			tolua_function(tolua_S, "setResId",       lua_addingRelies_setResId);
			tolua_function(tolua_S, "getResId",       lua_addingRelies_getResId);
			tolua_function(tolua_S, "setOnRide",      lua_addingRelies_setOnRide);
			tolua_function(tolua_S, "getOnRide",      lua_addingRelies_getOnRide);
			tolua_function(tolua_S, "getprimaryFactIterator",    lua_addingRelies_getprimaryFactIterator); 
			tolua_function(tolua_S, "setdeductionNeverBehind",   lua_addingRelies_setdeductionNeverBehind);
			tolua_function(tolua_S, "getdeductionNeverBehind",   lua_addingRelies_getdeductionNeverBehind);
			tolua_function(tolua_S, "getprintsGenerateSearch",   lua_addingRelies_getprintsGenerateSearch);
		
			tolua_function(tolua_S, "getlookupRecompilingVector",    lua_addingRelies_getlookupRecompilingVector);
			tolua_function(tolua_S, "setlookupRecompilingVector",    lua_addingRelies_setlookupRecompilingVector);
			tolua_function(tolua_S, "getdigitsParameteaWhat3",    lua_addingRelies_getdigitsParameteaWhat3);
			tolua_function(tolua_S, "setFather",    lua_addingRelies_setFather);
			tolua_function(tolua_S, "getFather",    lua_addingRelies_getFather);
			tolua_function(tolua_S, "setcompilerStoprocessing",    lua_addingRelies_setcompilerStoprocessing);
			tolua_function(tolua_S, "setprvoidExtensioindicating",    lua_addingRelies_setprvoidExtensioindicating);
			tolua_function(tolua_S, "setiandRelativeAssigns",    lua_addingRelies_setiandRelativeAssigns);
			tolua_function(tolua_S, "setaverageIdentification",    lua_addingRelies_setaverageIdentification);
			tolua_function(tolua_S, "getaverageIdentification",    lua_addingRelies_getaverageIdentification);
			tolua_function(tolua_S, "printedClosePeppers",       lua_addingRelies_printedClosePeppers);
			tolua_function(tolua_S, "operationDesigning",         lua_addingRelies_operationDesigning);
			tolua_function(tolua_S, "assignReliesSeparator",       lua_addingRelies_assignReliesSeparator);
			tolua_function(tolua_S, "compilationCerrIntended",         lua_addingRelies_compilationCerrIntended);
		
			tolua_function(tolua_S, "relativeEcmascriptBuilt",       lua_addingRelies_relativeEcmascriptBuilt);
			tolua_function(tolua_S, "tuplesCandidateTopics",         lua_addingRelies_tuplesCandidateTopics);
			tolua_function(tolua_S, "wilreferKnowsInvolved",         lua_addingRelies_wilreferKnowsInvolved);
			tolua_function(tolua_S, "matrixExecutingCompilers",           lua_addingRelies_matrixExecutingCompilers);
			tolua_function(tolua_S, "strvecCurrentPushed",           lua_addingRelies_strvecCurrentPushed);
			tolua_function(tolua_S, "unlessSupplyTreated",           lua_addingRelies_unlessSupplyTreated);
			tolua_function(tolua_S, "effectEliminatedReference",           lua_addingRelies_effectEliminatedReference);
			tolua_function(tolua_S, "parametersunlikeRemoved",           lua_addingRelies_parametersunlikeRemoved);
			tolua_function(tolua_S, "FixFlyPos",              lua_addingRelies_FixFlyPos);
			tolua_function(tolua_S, "setRenderMode",          lua_addingRelies_setRenderMode);
			tolua_function(tolua_S, "getmemberEscapeHowevewe",          lua_addingRelies_getmemberEscapeHowevewe);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_labelsPointRepresentation_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			labelsPointRepresentation* ret = labelsPointRepresentation::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<labelsPointRepresentation>(tolua_S, "labelsPointRepresentation",(labelsPointRepresentation*)ret);
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
			labelsPointRepresentation* ret = labelsPointRepresentation::create(arg0, arg1);
			do {
				if (NULL != ret){
					object_to_luaval<labelsPointRepresentation>(tolua_S, "labelsPointRepresentation",(labelsPointRepresentation*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_create'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setcontrolsPredicted(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setcontrolsPredicted'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setcontrolsPredicted(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setcontrolsPredicted",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setcontrolsPredicted'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_setpreciseSeparatedPscreen(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setpreciseSeparatedPscreen'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpreciseSeparatedPscreen(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setpreciseSeparatedPscreen",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setpreciseSeparatedPscreen'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_setcloseAbstractlyLookup(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setcloseAbstractlyLookup'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setcloseAbstractlyLookup(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setcloseAbstractlyLookup",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setcloseAbstractlyLookup'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_setSpeed(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setSpeed'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_setelsewhereImportanceStores(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setelsewhereImportanceStores'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setelsewhereImportanceStores(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setelsewhereImportanceStores",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setelsewhereImportanceStores'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_isMove(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_isMove'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_isMove'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setHP(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setHP'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setHP'.",&tolua_err);
#endif
    return 0;
}
int lua_addingRelies_getHP(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getHP'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getHP'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setoftenSurprisinglyAsked(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setoftenSurprisinglyAsked'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setoftenSurprisinglyAsked(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setoftenSurprisinglyAsked",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setoftenSurprisinglyAsked'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getoftenSurprisinglyAsked(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getoftenSurprisinglyAsked'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getoftenSurprisinglyAsked();
		tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getoftenSurprisinglyAsked",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getoftenSurprisinglyAsked'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setMaxHP'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setMaxHP'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getMaxHP'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getMaxHP'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setAttack(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setAttack'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setAttack'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getAttack(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getAttack'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getAttack'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setName(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setName'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setName'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getName(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getName'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getName'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setLevel'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getLevel(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getLevel'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_subBlood(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_subBlood'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_subBlood'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_setinefficientBeginning(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setinefficientBeginning'", NULL);
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
		cobj->setinefficientBeginning(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setinefficientBeginning",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_setinefficientBeginning'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_bitsetsKnewAlgorithm(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_bitsetsKnewAlgorithm'", NULL);
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
		cobj->bitsetsKnewAlgorithm(name_state,blood_state,arg2);
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
		cobj->bitsetsKnewAlgorithm(name_state,blood_state,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "bitsetsKnewAlgorithm",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_bitsetsKnewAlgorithm'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_isAlive(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_isAlive'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_isAlive'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getbookstoreWillConstant(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getbookstoreWillConstant'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getbookstoreWillConstant();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getbookstoreWillConstant",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getbookstoreWillConstant'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getremainNumericTransactions(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getremainNumericTransactions'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getremainNumericTransactions();
		do {
				if (NULL != ret){
					object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getremainNumericTransactions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getremainNumericTransactions'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getlibrariesOtherRewrites(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getlibrariesOtherRewrites'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		Node* ret = cobj->getlibrariesOtherRewrites();
		do {
				if (NULL != ret){
				
					object_to_luaval<Label>(tolua_S, "cc.Label",(Label*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getlibrariesOtherRewrites",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getlibrariesOtherRewrites'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getoughtFreindBypass(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getoughtFreindBypass'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getoughtFreindBypass();
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
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getoughtFreindBypass",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getoughtFreindBypass'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_greaterFunctiwith(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_greaterFunctiwith'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (1 == argc)
	{
		Point arg0;
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 2,&arg0);
		cobj->greaterFunctiwith(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_greaterFunctiwith'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_leastInspiredThing(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_leastInspiredThing'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (0 == argc)
	{
		cobj->leastInspiredThing();
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
		cobj->leastInspiredThing(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_leastInspiredThing'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_setcallpassSpeakMimic(lua_State* tolua_S)
{
	int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_setcallpassSpeakMimic'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
    if (1 == argc)
    {
        cocos2d::Size size;
        ok &= luaval_to_size(tolua_S, 2, &size, "labelsPointRepresentation:setcallpassSpeakMimic");
        if (!ok) return 0;
		cobj->setcallpassSpeakMimic(size);
        lua_settop(tolua_S, 1);
        return 1;
    }
    return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_highestHavingSubsequent'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_getcallpassSpeakMimic(lua_State* tolua_S)
{
	int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_getcallpassSpeakMimic'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_labelsPointRepresentation_getcallpassSpeakMimic'", nullptr);
            return 0;
        }
		const cocos2d::Size& ret = cobj->getcallpassSpeakMimic();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "labelsPointRepresentation:getcallpassSpeakMimic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_getcallpassSpeakMimic'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_nodtorAdvancedIntent(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_nodtorAdvancedIntent'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->nodtorAdvancedIntent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nodtorAdvancedIntent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_nodtorAdvancedIntent'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_reduceTyhaveGave(lua_State* tolua_S)
{
	int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_reduceTyhaveGave'", NULL);
        return 0;
    }
#endif
	cobj->reduceTyhaveGave();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_reduceTyhaveGave'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_debugdeleteWillAlways(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_debugdeleteWillAlways'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->debugdeleteWillAlways(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "debugdeleteWillAlways",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_debugdeleteWillAlways'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_whappearsSensibleOnce(lua_State* tolua_S)
{
	int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_whappearsSensibleOnce'", NULL);
        return 0;
    }
#endif
	cobj->whappearsSensibleOnce();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_whappearsSensibleOnce'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_aspectsWarrantConstraints(lua_State* tolua_S)
{
    int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_aspectsWarrantConstraints'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->aspectsWarrantConstraints(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "aspectsWarrantConstraints",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_aspectsWarrantConstraints'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_highestHavingSubsequent(lua_State* tolua_S)
{
	int argc = 0;
    labelsPointRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_highestHavingSubsequent'", NULL);
        return 0;
    }
#endif
	cobj->highestHavingSubsequent();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_highestHavingSubsequent'.",&tolua_err);
#endif
    return 0;
}
int lua_labelsPointRepresentation_recursionImagethSometimes(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_recursionImagethSometimes'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->recursionImagethSometimes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "recursionImagethSometimes",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_recursionImagethSometimes'.",&tolua_err);
#endif
	return 0;
}
int lua_labelsPointRepresentation_defininsideThathey(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_labelsPointRepresentation_defininsideThathey'", NULL);
		return 0;
	}
#endif
	cobj->defininsideThathey();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_labelsPointRepresentation_defininsideThathey'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setneverPointsRequire(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setneverPointsRequire'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setneverPointsRequire(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setneverPointsRequire",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setneverPointsRequire'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getneverPointsRequire(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getneverPointsRequire'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getneverPointsRequire();
		if (ret){
			tolua_pushnumber(tolua_S,(lua_Number)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getneverPointsRequire",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getneverPointsRequire'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_setimplicitlyCompatibility(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_setimplicitlyCompatibility'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setimplicitlyCompatibility(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setimplicitlyCompatibility",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_setimplicitlyCompatibility'.",&tolua_err);
#endif
	return 0;
}
int lua_addingRelies_getimplicitlyCompatibility(lua_State* tolua_S)
{
	int argc = 0;
	labelsPointRepresentation* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"labelsPointRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (labelsPointRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_addingRelies_getimplicitlyCompatibility'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getimplicitlyCompatibility();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getimplicitlyCompatibility",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_addingRelies_getimplicitlyCompatibility'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_labelsPointRepresentation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"labelsPointRepresentation");
	tolua_cclass(tolua_S,"labelsPointRepresentation","labelsPointRepresentation","addingRelies",NULL);
		tolua_beginmodule(tolua_S,"labelsPointRepresentation");
			tolua_function(tolua_S, "create", lua_labelsPointRepresentation_create);
			tolua_function(tolua_S, "setoftenSurprisinglyAsked", lua_labelsPointRepresentation_setoftenSurprisinglyAsked);
			tolua_function(tolua_S, "getoftenSurprisinglyAsked", lua_labelsPointRepresentation_getoftenSurprisinglyAsked);
			tolua_function(tolua_S, "setpreciseSeparatedPscreen", lua_labelsPointRepresentation_setpreciseSeparatedPscreen);
			tolua_function(tolua_S, "setcontrolsPredicted", lua_labelsPointRepresentation_setcontrolsPredicted);
			tolua_function(tolua_S, "setcloseAbstractlyLookup", lua_labelsPointRepresentation_setcloseAbstractlyLookup);
			tolua_function(tolua_S, "setSpeed", lua_labelsPointRepresentation_setSpeed);
			tolua_function(tolua_S, "setelsewhereImportanceStores", lua_labelsPointRepresentation_setelsewhereImportanceStores);
			tolua_function(tolua_S, "setHP", lua_addingRelies_setHP);
			tolua_function(tolua_S, "getHP", lua_addingRelies_getHP);
			tolua_function(tolua_S, "isMove", lua_labelsPointRepresentation_isMove);
			tolua_function(tolua_S, "setMaxHP", lua_labelsPointRepresentation_setMaxHP);
			tolua_function(tolua_S, "getMaxHP", lua_labelsPointRepresentation_getMaxHP);
			tolua_function(tolua_S, "setAttack", lua_labelsPointRepresentation_setAttack);
			tolua_function(tolua_S, "getAttack", lua_labelsPointRepresentation_getAttack);
			tolua_function(tolua_S, "setName", lua_labelsPointRepresentation_setName);
			tolua_function(tolua_S, "getName", lua_labelsPointRepresentation_getName);
			tolua_function(tolua_S, "setLevel", lua_labelsPointRepresentation_setLevel);
			tolua_function(tolua_S, "getLevel", lua_labelsPointRepresentation_getLevel);
			tolua_function(tolua_S, "subBlood", lua_labelsPointRepresentation_subBlood);
			tolua_function(tolua_S, "bitsetsKnewAlgorithm", lua_labelsPointRepresentation_bitsetsKnewAlgorithm);
			tolua_function(tolua_S, "setinefficientBeginning", lua_labelsPointRepresentation_setinefficientBeginning);
			tolua_function(tolua_S, "isAlive", lua_labelsPointRepresentation_isAlive);
			tolua_function(tolua_S, "getbookstoreWillConstant", lua_labelsPointRepresentation_getbookstoreWillConstant);
			tolua_function(tolua_S, "getremainNumericTransactions", lua_labelsPointRepresentation_getremainNumericTransactions);
			tolua_function(tolua_S, "getlibrariesOtherRewrites", lua_labelsPointRepresentation_getlibrariesOtherRewrites);
		
			tolua_function(tolua_S, "getoughtFreindBypass",              lua_labelsPointRepresentation_getoughtFreindBypass);
			tolua_function(tolua_S, "setcallpassSpeakMimic",                lua_labelsPointRepresentation_setcallpassSpeakMimic);
			tolua_function(tolua_S, "getcallpassSpeakMimic",                lua_labelsPointRepresentation_getcallpassSpeakMimic);
			tolua_function(tolua_S, "nodtorAdvancedIntent",   lua_labelsPointRepresentation_nodtorAdvancedIntent);
			tolua_function(tolua_S, "reduceTyhaveGave",     lua_labelsPointRepresentation_reduceTyhaveGave);
			tolua_function(tolua_S, "debugdeleteWillAlways",      lua_labelsPointRepresentation_debugdeleteWillAlways);
			tolua_function(tolua_S, "whappearsSensibleOnce",        lua_labelsPointRepresentation_whappearsSensibleOnce);
			tolua_function(tolua_S, "aspectsWarrantConstraints", lua_labelsPointRepresentation_aspectsWarrantConstraints);
			tolua_function(tolua_S, "highestHavingSubsequent",   lua_labelsPointRepresentation_highestHavingSubsequent);
			tolua_function(tolua_S, "recursionImagethSometimes", lua_labelsPointRepresentation_recursionImagethSometimes);
			tolua_function(tolua_S, "defininsideThathey",   lua_labelsPointRepresentation_defininsideThathey);
			tolua_function(tolua_S, "greaterFunctiwith",   lua_labelsPointRepresentation_greaterFunctiwith);
			tolua_function(tolua_S, "leastInspiredThing",   lua_labelsPointRepresentation_leastInspiredThing);
			tolua_function(tolua_S, "setneverPointsRequire",   lua_addingRelies_setneverPointsRequire);
			tolua_function(tolua_S, "getneverPointsRequire",   lua_addingRelies_getneverPointsRequire);
			tolua_function(tolua_S, "setimplicitlyCompatibility",   lua_addingRelies_setimplicitlyCompatibility);
			tolua_function(tolua_S, "getimplicitlyCompatibility",   lua_addingRelies_getimplicitlyCompatibility);
		
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_assumeApproachEmbodies_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
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
			assumeApproachEmbodies* ret = assumeApproachEmbodies::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<assumeApproachEmbodies>(tolua_S, "assumeApproachEmbodies",(assumeApproachEmbodies*)ret);
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
			assumeApproachEmbodies* ret = assumeApproachEmbodies::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
				
					object_to_luaval<assumeApproachEmbodies>(tolua_S, "assumeApproachEmbodies",(assumeApproachEmbodies*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_create'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setsalesWereTree2(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setsalesWereTree2'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		bool arg0 ;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setsalesWereTree2(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_assumeApproachEmbodies_setsalesWereTree2",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setsalesWereTree2'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_getsalesWereTree2(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getsalesWereTree2'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		bool ret = cobj->getsalesWereTree2();
		tolua_pushboolean(tolua_S,ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_assumeApproachEmbodies_getsalesWereTree2",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getsalesWereTree2'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setyieldsOverloadBeginning(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setyieldsOverloadBeginning'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0 ;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setyieldsOverloadBeginning(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setyieldsOverloadBeginning",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setyieldsOverloadBeginning'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setafterExistOperation(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setafterExistOperation'", NULL);
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
	
		cobj->setafterExistOperation(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setafterExistOperation",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setafterExistOperation'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setpairOstreamWita(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setpairOstreamWita'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpairOstreamWita(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpairOstreamWita",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setpairOstreamWita'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setunnamedWhereIobj5(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setunnamedWhereIobj5'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		double arg0 ;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setunnamedWhereIobj5(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setunnamedWhereIobj5",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setunnamedWhereIobj5'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_getunnamedWhereIobj5(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getunnamedWhereIobj5'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		float ret = cobj->getunnamedWhereIobj5();
		tolua_pushnumber(tolua_S,(float)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getunnamedWhereIobj5",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getunnamedWhereIobj5'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setSex(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setSex'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setSex'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getSex(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getSex'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getSex'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setexpressionasInvolveCode(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setexpressionasInvolveCode'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setexpressionasInvolveCode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setexpressionasInvolveCode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setexpressionasInvolveCode'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getexpressionasInvolveCode(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getexpressionasInvolveCode'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		int ret = cobj->getexpressionasInvolveCode();
		tolua_pushnumber(tolua_S,(int)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getexpressionasInvolveCode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getexpressionasInvolveCode'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setSchool(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setSchool'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setSchool'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getSchool(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getSchool'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getSchool'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_worksBraceRefers(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_worksBraceRefers'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		if(cobj->worksBraceRefers)
			cobj->worksBraceRefers(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "worksBraceRefers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_worksBraceRefers'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getSpeed'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getSpeed'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_discussioofListsHaveWhyou(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_discussioofListsHaveWhyou'", NULL);
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
		cobj->discussioofListsHaveWhyou(arg0,arg1);
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
		cobj->discussioofListsHaveWhyou(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "discussioofListsHaveWhyou",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_discussioofListsHaveWhyou'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_underlyingUndefined(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_underlyingUndefined'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
		addingRelies *arg0;
		int arg1;
		int arg2;
		arg0 = (addingRelies*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3,&arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4,&arg2);
		if (!ok) { return 0; }
		cobj->underlyingUndefined(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "underlyingUndefined",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_underlyingUndefined'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_everythingExploitImplicit(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_everythingExploitImplicit'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		addingRelies *arg0;
		arg0 = (addingRelies*)tolua_tousertype(tolua_S,2,0);
		if(!arg0) { return 0; }
		cobj->everythingExploitImplicit(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "everythingExploitImplicit",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_everythingExploitImplicit'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_hierarchyReleaseReady(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_hierarchyReleaseReady'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->hierarchyReleaseReady(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hierarchyReleaseReady",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_hierarchyReleaseReady'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getunusualPredicate(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getunusualPredicate'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		float ret = cobj->getunusualPredicate();
		tolua_pushnumber(tolua_S,(float)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getunusualPredicate",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getunusualPredicate'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setActive(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setActive'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setActive'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_getActive(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_getActive'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_getActive'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setpostfixWordIntrinsicfifth(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setpostfixWordIntrinsicfifth'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpostfixWordIntrinsicfifth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpostfixWordIntrinsicfifth",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setpostfixWordIntrinsicfifth'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setpreserveMeddleAccustomed1(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setpreserveMeddleAccustomed1'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2,&arg0);
		if (!ok) { return 0; }
		cobj->setpreserveMeddleAccustomed1(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpreserveMeddleAccustomed1",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setpreserveMeddleAccustomed1'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_setRoleId(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setRoleId'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setRoleId'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_thfunctionFamilyCombine4(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_thfunctionFamilyCombine4'", NULL);
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
		bool ret = cobj->thfunctionFamilyCombine4((float)arg0,arg1,arg2,arg3);
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
		bool ret = cobj->thfunctionFamilyCombine4((float)arg0,arg1,arg2,arg3,arg4);
		lua_pushboolean(tolua_S,ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "thfunctionFamilyCombine4",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_thfunctionFamilyCombine4'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_attentionCompiled(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_attentionCompiled'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->attentionCompiled(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_attentionCompiled'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_rewriteSupposeparateValue(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
	bool arg0 = false;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_rewriteSupposeparateValue'", NULL);
        return 0;
    }
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		ok =  luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
	}
    cobj->rewriteSupposeparateValue(arg0);
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_rewriteSupposeparateValue'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_elementPredicateCompiler1(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_elementPredicateCompiler1'", NULL);
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
		cobj->elementPredicateCompiler1(arg0, (soonAlongMemberwise)arg1, (accessedIntroductory)arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "elementPredicateCompiler1",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_elementPredicateCompiler1'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_compilersSafelyAdditional(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_compilersSafelyAdditional'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->compilersSafelyAdditional(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "compilersSafelyAdditional",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_compilersSafelyAdditional'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_setsWhichLooth1(lua_State* tolua_S)
{
	int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_setsWhichLooth1'", NULL);
        return 0;
    }
#endif
	cobj->setsWhichLooth1();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_setsWhichLooth1'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_randomItasContaiany(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_randomItasContaiany'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->randomItasContaiany(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "randomItasContaiany",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_randomItasContaiany'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_declaresAvailableArray(lua_State* tolua_S)
{
	int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_declaresAvailableArray'", NULL);
        return 0;
    }
#endif
	cobj->declaresAvailableArray();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_declaresAvailableArray'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_actuasizeIdentifyApplied(lua_State* tolua_S)
{
    int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_actuasizeIdentifyApplied'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->actuasizeIdentifyApplied(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actuasizeIdentifyApplied",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_actuasizeIdentifyApplied'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_functionalityThrows(lua_State* tolua_S)
{
	int argc = 0;
    assumeApproachEmbodies* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_functionalityThrows'", NULL);
        return 0;
    }
#endif
	cobj->functionalityThrows();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_functionalityThrows'.",&tolua_err);
#endif
    return 0;
}
int lua_assumeApproachEmbodies_sequentialWhatDeleter(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_sequentialWhatDeleter'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->sequentialWhatDeleter(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sequentialWhatDeleter",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_sequentialWhatDeleter'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_occurrenceMimicPart(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_occurrenceMimicPart'", NULL);
		return 0;
	}
#endif
	cobj->occurrenceMimicPart();
	lua_settop(tolua_S, 1);
	return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_occurrenceMimicPart'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_scopeMemberOperateActs(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_scopeMemberOperateActs'", NULL);
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
		cobj->scopeMemberOperateActs((wantedConvertibleGroup)arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scopeMemberOperateActs",argc, 2);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_scopeMemberOperateActs'.",&tolua_err);
#endif
	return 0;
}
int lua_assumeApproachEmbodies_representsTightly(lua_State* tolua_S)
{
	int argc = 0;
	assumeApproachEmbodies* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"assumeApproachEmbodies",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (assumeApproachEmbodies*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_representsTightly'", NULL);
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
		cobj->representsTightly(arg0, (float)arg1, (float)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "representsTightly",argc, 3);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_assumeApproachEmbodies_representsTightly'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_assumeApproachEmbodies(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"assumeApproachEmbodies");
	tolua_cclass(tolua_S,"assumeApproachEmbodies","assumeApproachEmbodies","labelsPointRepresentation",NULL);
		tolua_beginmodule(tolua_S,"assumeApproachEmbodies");
			tolua_function(tolua_S, "create", lua_assumeApproachEmbodies_create);
			tolua_function(tolua_S, "setunnamedWhereIobj5", lua_assumeApproachEmbodies_setunnamedWhereIobj5);
			tolua_function(tolua_S, "getunnamedWhereIobj5", lua_assumeApproachEmbodies_getunnamedWhereIobj5);
			tolua_function(tolua_S, "setpairOstreamWita", lua_assumeApproachEmbodies_setpairOstreamWita);
			tolua_function(tolua_S, "setyieldsOverloadBeginning", lua_assumeApproachEmbodies_setyieldsOverloadBeginning);
			tolua_function(tolua_S, "setafterExistOperation", lua_assumeApproachEmbodies_setafterExistOperation);
			tolua_function(tolua_S, "setsalesWereTree2", lua_assumeApproachEmbodies_setsalesWereTree2);
			tolua_function(tolua_S, "getsalesWereTree2", lua_assumeApproachEmbodies_getsalesWereTree2);
			tolua_function(tolua_S, "setSex", lua_assumeApproachEmbodies_setSex);
			tolua_function(tolua_S, "getSex", lua_assumeApproachEmbodies_getSex);
			tolua_function(tolua_S, "setexpressionasInvolveCode", lua_assumeApproachEmbodies_setexpressionasInvolveCode);
			tolua_function(tolua_S, "getexpressionasInvolveCode", lua_assumeApproachEmbodies_getexpressionasInvolveCode);
			tolua_function(tolua_S, "setSchool", lua_assumeApproachEmbodies_setSchool);
			tolua_function(tolua_S, "getSchool", lua_assumeApproachEmbodies_getSchool);
			tolua_function(tolua_S, "worksBraceRefers", lua_assumeApproachEmbodies_worksBraceRefers);
			tolua_function(tolua_S, "getSpeed", lua_assumeApproachEmbodies_getSpeed);
			tolua_function(tolua_S, "discussioofListsHaveWhyou", lua_assumeApproachEmbodies_discussioofListsHaveWhyou);
			tolua_function(tolua_S, "underlyingUndefined", lua_assumeApproachEmbodies_underlyingUndefined);
			tolua_function(tolua_S, "everythingExploitImplicit", lua_assumeApproachEmbodies_everythingExploitImplicit);
			tolua_function(tolua_S, "hierarchyReleaseReady", lua_assumeApproachEmbodies_hierarchyReleaseReady);
			tolua_function(tolua_S, "getunusualPredicate", lua_assumeApproachEmbodies_getunusualPredicate);
			tolua_function(tolua_S, "setActive", lua_assumeApproachEmbodies_setActive);
			tolua_function(tolua_S, "getActive", lua_assumeApproachEmbodies_getActive);
			tolua_function(tolua_S, "setpostfixWordIntrinsicfifth", lua_assumeApproachEmbodies_setpostfixWordIntrinsicfifth);
			tolua_function(tolua_S, "setRoleId", lua_assumeApproachEmbodies_setRoleId);
			tolua_function(tolua_S, "setpreserveMeddleAccustomed1", lua_assumeApproachEmbodies_setpreserveMeddleAccustomed1);
			tolua_function(tolua_S, "thfunctionFamilyCombine4", lua_assumeApproachEmbodies_thfunctionFamilyCombine4);
			tolua_function(tolua_S, "attentionCompiled", lua_assumeApproachEmbodies_attentionCompiled);
			tolua_function(tolua_S, "rewriteSupposeparateValue", lua_assumeApproachEmbodies_rewriteSupposeparateValue);
			tolua_function(tolua_S, "elementPredicateCompiler1", lua_assumeApproachEmbodies_elementPredicateCompiler1);
			tolua_function(tolua_S, "compilersSafelyAdditional", lua_assumeApproachEmbodies_compilersSafelyAdditional);
			tolua_function(tolua_S, "setsWhichLooth1",   lua_assumeApproachEmbodies_setsWhichLooth1);
			tolua_function(tolua_S, "randomItasContaiany",              lua_assumeApproachEmbodies_randomItasContaiany);
			tolua_function(tolua_S, "declaresAvailableArray",                lua_assumeApproachEmbodies_declaresAvailableArray);
			tolua_function(tolua_S, "actuasizeIdentifyApplied",        lua_assumeApproachEmbodies_actuasizeIdentifyApplied);
			tolua_function(tolua_S, "functionalityThrows",          lua_assumeApproachEmbodies_functionalityThrows);
			tolua_function(tolua_S, "sequentialWhatDeleter",				lua_assumeApproachEmbodies_sequentialWhatDeleter);
			tolua_function(tolua_S, "occurrenceMimicPart",               lua_assumeApproachEmbodies_occurrenceMimicPart);
			tolua_function(tolua_S, "scopeMemberOperateActs",         lua_assumeApproachEmbodies_scopeMemberOperateActs);
			tolua_function(tolua_S, "representsTightly",                  lua_assumeApproachEmbodies_representsTightly);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_appliedDifferenceNoted_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"appliedDifferenceNoted",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			appliedDifferenceNoted* ret = appliedDifferenceNoted::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<appliedDifferenceNoted>(tolua_S, "appliedDifferenceNoted",(appliedDifferenceNoted*)ret);
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
			appliedDifferenceNoted* ret = appliedDifferenceNoted::create();
			do {
				if (NULL != ret){
				
					object_to_luaval<appliedDifferenceNoted>(tolua_S, "appliedDifferenceNoted",(appliedDifferenceNoted*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_appliedDifferenceNoted_create'.",&tolua_err);
#endif
    return 0;
}
int lua_appliedDifferenceNoted_usedWithinOwhichCondition(lua_State* tolua_S)
{
    int argc = 0;
    appliedDifferenceNoted* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"appliedDifferenceNoted",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (appliedDifferenceNoted*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_appliedDifferenceNoted_usedWithinOwhichCondition'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->usedWithinOwhichCondition();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "usedWithinOwhichCondition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_appliedDifferenceNoted_usedWithinOwhichCondition'.",&tolua_err);
#endif
    return 0;
}
int lua_appliedDifferenceNoted_chapterEqually(lua_State* tolua_S)
{
    int argc = 0;
    appliedDifferenceNoted* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"appliedDifferenceNoted",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (appliedDifferenceNoted*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_appliedDifferenceNoted_chapterEqually'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
		cobj->chapterEqually();
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "chapterEqually",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_appliedDifferenceNoted_chapterEqually'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_appliedDifferenceNoted(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"appliedDifferenceNoted");
	tolua_cclass(tolua_S,"appliedDifferenceNoted","appliedDifferenceNoted","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"appliedDifferenceNoted");
			tolua_function(tolua_S, "create", lua_appliedDifferenceNoted_create);
			tolua_function(tolua_S, "usedWithinOwhichCondition", lua_appliedDifferenceNoted_usedWithinOwhichCondition);
			tolua_function(tolua_S, "chapterEqually", lua_appliedDifferenceNoted_chapterEqually);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_predictedReverseWhich_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"predictedReverseWhich",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			predictedReverseWhich* ret = predictedReverseWhich::create(arg0.c_str());
			do {
				if (NULL != ret){
				
					object_to_luaval<predictedReverseWhich>(tolua_S, "predictedReverseWhich",(predictedReverseWhich*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_predictedReverseWhich_create'.",&tolua_err);
#endif
    return 0;
}
int lua_predictedReverseWhich_setdesignersIndicateExcept(lua_State* tolua_S)
{
    int argc = 0;
    predictedReverseWhich* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"predictedReverseWhich",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (predictedReverseWhich*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_predictedReverseWhich_setdesignersIndicateExcept'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "predictedReverseWhich:setdesignersIndicateExcept");
            if (!ok) { break; }
            cobj->setdesignersIndicateExcept(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdesignersIndicateExcept",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_predictedReverseWhich_setdesignersIndicateExcept'.",&tolua_err);
#endif
    return 0;
}
int lua_predictedReverseWhich_setliteralSpecifiesIostream(lua_State* tolua_S)
{
    int argc = 0;
    predictedReverseWhich* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"predictedReverseWhich",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (predictedReverseWhich*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_predictedReverseWhich_setliteralSpecifiesIostream'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
	do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "predictedReverseWhich:setliteralSpecifiesIostream");
            if (!ok) { break; }
            cobj->setliteralSpecifiesIostream(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setliteralSpecifiesIostream",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_predictedReverseWhich_setliteralSpecifiesIostream'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_predictedReverseWhich(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"predictedReverseWhich");
	tolua_cclass(tolua_S,"predictedReverseWhich","predictedReverseWhich","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"predictedReverseWhich");
			tolua_function(tolua_S, "create", lua_predictedReverseWhich_create);
			tolua_function(tolua_S, "setdesignersIndicateExcept", lua_predictedReverseWhich_setdesignersIndicateExcept);
			tolua_function(tolua_S, "setliteralSpecifiesIostream", lua_predictedReverseWhich_setliteralSpecifiesIostream);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_bookstoreEmployee_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		std::string arg0;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			bookstoreEmployee* ret = bookstoreEmployee::create(arg0);
			do {
				if (NULL != ret){
				
					object_to_luaval<bookstoreEmployee>(tolua_S, "bookstoreEmployee",(bookstoreEmployee*)ret);
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
			bookstoreEmployee* ret = bookstoreEmployee::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->rationaleAlternatively(arg1);
				
					object_to_luaval<bookstoreEmployee>(tolua_S, "bookstoreEmployee",(bookstoreEmployee*)ret);
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
			bookstoreEmployee* ret = bookstoreEmployee::create(arg0);
			do {
				if (NULL != ret && arg1){
					ret->rationaleAlternatively(arg1);
					ret->setgreatlyCollideWhen(arg2);
				
					object_to_luaval<bookstoreEmployee>(tolua_S, "bookstoreEmployee",(bookstoreEmployee*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_create'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_onClick(lua_State* tolua_S)
{
	int argc = 0;
	bookstoreEmployee* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_onClick'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_onClick'.",&tolua_err);
#endif
	return 0;
}
int lua_bookstoreEmployee_facilitiesNewlineWhif(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_worksBraceRefers'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->facilitiesNewlineWhif(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "facilitiesNewlineWhif",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_facilitiesNewlineWhif'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_rationaleAlternatively(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_rationaleAlternatively'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->rationaleAlternatively(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rationaleAlternatively",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_rationaleAlternatively'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_setreduceRecognize(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_setreduceRecognize'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setreduceRecognize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setreduceRecognize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_setreduceRecognize'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_setSwallowTouch(lua_State* tolua_S)
{
	int argc = 0;
	bookstoreEmployee* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_setSwallowTouch'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_setSwallowTouch'.",&tolua_err);
#endif
	return 0;
}
int lua_bookstoreEmployee_setEnable(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_setEnable'", NULL);
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
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_setEnable'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_setcodeFullyException(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_bookstoreEmployee_setcodeFullyException'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setcodeFullyException(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setcodeFullyException",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_setcodeFullyException'.",&tolua_err);
#endif
    return 0;
}
int lua_bookstoreEmployee_setassumeManageLittle(lua_State* tolua_S)
{
    int argc = 0;
    bookstoreEmployee* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bookstoreEmployee",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (bookstoreEmployee*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ideaDelegates_setassumeManageLittle'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		Action* arg0;
		arg0 = (Action*)tolua_tousertype(tolua_S,2,0);
		cobj->setassumeManageLittle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setassumeManageLittle",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_bookstoreEmployee_setassumeManageLittle'.",&tolua_err);
#endif
    return 0;
}
int lua_register_cocos2dx_bookstoreEmployee(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bookstoreEmployee");
	tolua_cclass(tolua_S,"bookstoreEmployee","bookstoreEmployee","appliedDifferenceNoted",NULL);
		tolua_beginmodule(tolua_S,"bookstoreEmployee");
			tolua_function(tolua_S, "create", lua_bookstoreEmployee_create);
			tolua_function(tolua_S, "facilitiesNewlineWhif", lua_bookstoreEmployee_facilitiesNewlineWhif);
			tolua_function(tolua_S, "onClick", lua_bookstoreEmployee_onClick);
			tolua_function(tolua_S, "rationaleAlternatively", lua_bookstoreEmployee_rationaleAlternatively);
			tolua_function(tolua_S, "setreduceRecognize", lua_bookstoreEmployee_setreduceRecognize);
			tolua_function(tolua_S, "setSwallowTouch", lua_bookstoreEmployee_setSwallowTouch);
			tolua_function(tolua_S, "setEnable", lua_bookstoreEmployee_setEnable);
			tolua_function(tolua_S, "setcodeFullyException", lua_bookstoreEmployee_setcodeFullyException);
			tolua_function(tolua_S, "setassumeManageLittle", lua_bookstoreEmployee_setassumeManageLittle);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_refersEnums_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
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
			refersEnums* ret = refersEnums::create(arg0,arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<refersEnums>(tolua_S, "refersEnums",(refersEnums*)ret);
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
			refersEnums* ret = refersEnums::create(arg0,arg1);
			do {
				if (NULL != ret && arg2){
					ret->rationaleAlternatively(arg2);
				
					object_to_luaval<refersEnums>(tolua_S, "refersEnums",(refersEnums*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_create'.",&tolua_err);
#endif
    return 0;
}
int lua_refersEnums_facilitiesNewlineWhif(lua_State* tolua_S)
{
    int argc = 0;
    refersEnums* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (refersEnums*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_assumeApproachEmbodies_worksBraceRefers'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->facilitiesNewlineWhif(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "facilitiesNewlineWhif",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_facilitiesNewlineWhif'.",&tolua_err);
#endif
    return 0;
}
int lua_refersEnums_rationaleAlternatively(lua_State* tolua_S)
{
    int argc = 0;
    refersEnums* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (refersEnums*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_refersEnums_rationaleAlternatively'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->rationaleAlternatively(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rationaleAlternatively",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_rationaleAlternatively'.",&tolua_err);
#endif
    return 0;
}
int lua_refersEnums_setreduceRecognize(lua_State* tolua_S)
{
    int argc = 0;
    refersEnums* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (refersEnums*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_refersEnums_setreduceRecognize'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setreduceRecognize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setreduceRecognize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_setreduceRecognize'.",&tolua_err);
#endif
    return 0;
}
int lua_refersEnums_setdistinguishHidesOught2(lua_State* tolua_S)
{
    int argc = 0;
    refersEnums* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (refersEnums*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_refersEnums_setdistinguishHidesOught2'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setdistinguishHidesOught2(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdistinguishHidesOught2",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_setdistinguishHidesOught2'.",&tolua_err);
#endif
    return 0;
}
int lua_refersEnums_copiedIntrinsicfifth(lua_State* tolua_S)
{
	int argc = 0;
	refersEnums* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"refersEnums",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (refersEnums*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_refersEnums_copiedIntrinsicfifth'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Rect arg0;
		ok &= luaval_to_rect(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->copiedIntrinsicfifth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copiedIntrinsicfifth",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_refersEnums_copiedIntrinsicfifth'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_refersEnums(lua_State* tolua_S)
{       
    tolua_usertype(tolua_S,"refersEnums");
	tolua_cclass(tolua_S,"refersEnums","refersEnums","ccui.Scale9Sprite",NULL);
		tolua_beginmodule(tolua_S,"refersEnums");
			tolua_function(tolua_S, "create", lua_refersEnums_create);
			tolua_function(tolua_S, "facilitiesNewlineWhif", lua_refersEnums_facilitiesNewlineWhif);
			tolua_function(tolua_S, "rationaleAlternatively", lua_refersEnums_rationaleAlternatively);
			tolua_function(tolua_S, "setreduceRecognize", lua_refersEnums_setreduceRecognize);
			tolua_function(tolua_S, "setdistinguishHidesOught2", lua_refersEnums_setdistinguishHidesOught2);
			tolua_function(tolua_S, "copiedIntrinsicfifth", lua_refersEnums_copiedIntrinsicfifth);
		tolua_endmodule(tolua_S);
    return 1;
}
int lua_complicationAproblems_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"complicationAproblems",0,&tolua_err)) goto tolua_lerror;
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
			complicationAproblems* ret = complicationAproblems::create(arg0, arg1);
			do {
				if (NULL != ret){
				
					object_to_luaval<complicationAproblems>(tolua_S, "complicationAproblems",(complicationAproblems*)ret);
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
	tolua_error(tolua_S,"#ferror in function 'lua_complicationAproblems_create'.",&tolua_err);
#endif
	return 0;
}
int lua_complicationAproblems_settestCallableSpecifiers1(lua_State* tolua_S)
{
	int argc = 0;
	complicationAproblems* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"complicationAproblems",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (complicationAproblems*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_complicationAproblems_settestCallableSpecifiers1'", NULL);
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
			cobj->settestCallableSpecifiers1(arg0);
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
			cobj->settestCallableSpecifiers1(arg0, (float)arg1);
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
			cobj->settestCallableSpecifiers1(arg0, (float)arg1, (float)arg2);
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
			cobj->settestCallableSpecifiers1(arg0, (float)arg1, (float)arg2, (float) arg3);
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
			cobj->settestCallableSpecifiers1(arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4);
			lua_settop(tolua_S, 1);
			return 1;
		} while (0);
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "settestCallableSpecifiers1", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_complicationAproblems_settestCallableSpecifiers1'.",&tolua_err);
#endif
	return 0;
}
int lua_complicationAproblems_standed(lua_State* tolua_S)
{
	int argc = 0;
	complicationAproblems* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"complicationAproblems",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (complicationAproblems*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_complicationAproblems_standed'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_complicationAproblems_standed'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_complicationAproblems(lua_State* tolua_S)
{       
	tolua_usertype(tolua_S,"complicationAproblems");
	tolua_cclass(tolua_S,"complicationAproblems","complicationAproblems","addingRelies",NULL);
	tolua_beginmodule(tolua_S,"complicationAproblems");
	tolua_function(tolua_S, "create", lua_complicationAproblems_create);
	tolua_function(tolua_S, "settestCallableSpecifiers1", lua_complicationAproblems_settestCallableSpecifiers1);
	tolua_function(tolua_S, "standed", lua_complicationAproblems_standed);
	tolua_endmodule(tolua_S);
	return 1;
}
#endif    