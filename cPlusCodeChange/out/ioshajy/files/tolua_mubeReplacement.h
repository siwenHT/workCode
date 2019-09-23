#ifndef __TOLUA_ACTORACTIONMANAGEC_H__
#define __TOLUA_ACTORACTIONMANAGEC_H__
#include "tolua++.h"
#include "mubeReplacement.h"
#include "LuaBasicConversions.h"
int lua_mubeReplacement_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			mubeReplacement* ret = mubeReplacement::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<mubeReplacement>(tolua_S, "mubeReplacement",(mubeReplacement*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_mubeReplacement_nonexistentAccessible(lua_State* tolua_S)
{
    int argc = 0;
    mubeReplacement* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_nonexistentAccessible'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
		int arg0;
		cocos2d::Node* arg1;
		std::string arg2;
		int arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "nonexistentAccessible");
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		cobj->nonexistentAccessible((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nonexistentAccessible",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_nonexistentAccessible'.",&tolua_err);
#endif
    return 0;
}
int lua_mubeReplacement_leadsDoesndifferRest2(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_leadsDoesndifferRest2'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0;
		std::string arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->leadsDoesndifferRest2((ActorComponentType)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		int arg0;
		std::string arg1;
		cocos2d::Node* arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2, "leadsDoesndifferRest2");
		if (!ok) { return 0; }
		cobj->leadsDoesndifferRest2((ActorComponentType)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "leadsDoesndifferRest2",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_leadsDoesndifferRest2'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_getvaluesTellsProgramming(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_getvaluesTellsProgramming'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0;
		std::string arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		auto ret = cobj->getvaluesTellsProgramming((ActorComponentType)arg0,arg1);
		if (nullptr != ret){
			object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getvaluesTellsProgramming",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_getvaluesTellsProgramming'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setupdatesPersistSpecifying3(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setupdatesPersistSpecifying3'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setupdatesPersistSpecifying3'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setrealizeFollowedPointed4(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setrealizeFollowedPointed4'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0 = "";
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->setrealizeFollowedPointed4(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrealizeFollowedPointed4",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setrealizeFollowedPointed4'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setstoringRuleOtherwise(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setstoringRuleOtherwise'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0 = "";
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->setstoringRuleOtherwise(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) 
	{
		std::string arg0 = "";
		bool arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->setstoringRuleOtherwise(arg0,arg1,(wantedConvertibleGroup)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setstoringRuleOtherwise",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setstoringRuleOtherwise'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_gotoDeath(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_gotoDeath'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->gotoDeath(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoDeath",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_gotoDeath'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_errorsMimicScope(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_errorsMimicScope'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->errorsMimicScope(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "errorsMimicScope",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_errorsMimicScope'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setinsteadCollideConsult(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setinsteadCollideConsult'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->setinsteadCollideConsult(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setinsteadCollideConsult",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setinsteadCollideConsult'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_curlyAmongEvaluating(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_curlyAmongEvaluating'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		cocos2d::Node* arg0;
		int arg1;
		std::string arg2;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "curlyAmongEvaluating");
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->curlyAmongEvaluating(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "curlyAmongEvaluating",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_curlyAmongEvaluating'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_begunWilreferRevisited(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_begunWilreferRevisited'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "begunWilreferRevisited");
		if (!ok) { return 0; }
		cobj->begunWilreferRevisited(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "begunWilreferRevisited",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_begunWilreferRevisited'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_possibleSurprisinglyOlder(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_possibleSurprisinglyOlder'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->possibleSurprisinglyOlder(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "possibleSurprisinglyOlder",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_possibleSurprisinglyOlder'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_totalImportanceRest(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_totalImportanceRest'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->totalImportanceRest(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "totalImportanceRest",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_totalImportanceRest'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_identifiesRepresents(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_identifiesRepresents'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "identifiesRepresents");
		if (!ok) { return 0; }
		cobj->identifiesRepresents(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "identifiesRepresents",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_identifiesRepresents'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setdesignerRvalueAbility4(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setdesignerRvalueAbility4'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		int arg0;
		cocos2d::Node* arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "identifiesRepresents");
		if (!ok) { return 0; }
		cobj->setdesignerRvalueAbility4((ActorComponentType)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdesignerRvalueAbility4",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setdesignerRvalueAbility4'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setVisible(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setVisible'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 2) 
	{
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		cobj->setVisible(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisible",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setVisible'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_settechniqueGenerates(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_settechniqueGenerates'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		int arg0;
		std::string arg1;
		bool arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->settechniqueGenerates((ActorComponentType)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 4) 
	{
		int arg0;
		std::string arg1;
		bool arg2;
		bool arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		cobj->settechniqueGenerates((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5) 
	{
		int arg0;
		std::string arg1;
		bool arg2;
		bool arg3;
		cocos2d::Node* obj;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 6, "cc.Node",&obj, "settechniqueGenerates");
		if (!ok) { return 0; }
		cobj->settechniqueGenerates((ActorComponentType)arg0,arg1,arg2,arg3,obj);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "settechniqueGenerates",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_settechniqueGenerates'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setsupportedComputingRemoved(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setsupportedComputingRemoved'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		int arg0;
		std::string arg1;
		bool arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->setsupportedComputingRemoved((ActorComponentType)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 4) 
	{
		int arg0;
		std::string arg1;
		bool arg2;
		bool arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_boolean(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		cobj->setsupportedComputingRemoved((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsupportedComputingRemoved",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setsupportedComputingRemoved'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_clean(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_clean'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		cobj->clean();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clean",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_clean'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setfragmentSynthesized(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setfragmentSynthesized'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setfragmentSynthesized(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setfragmentSynthesized",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setfragmentSynthesized'.",&tolua_err);
#endif
	return 0;
}
int lua_mubeReplacement_setconcludesSuspendedNever(lua_State* tolua_S)
{
	int argc = 0;
	mubeReplacement* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"mubeReplacement",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (mubeReplacement*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_mubeReplacement_setconcludesSuspendedNever'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setconcludesSuspendedNever(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setconcludesSuspendedNever",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_mubeReplacement_setconcludesSuspendedNever'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_mubeReplacement(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"mubeReplacement");
	tolua_cclass(tolua_S,"mubeReplacement","mubeReplacement","cc.Ref",NULL);
		tolua_beginmodule(tolua_S,"mubeReplacement");
			tolua_function(tolua_S, "getInstance", lua_mubeReplacement_getInstance);
			tolua_function(tolua_S, "nonexistentAccessible", lua_mubeReplacement_nonexistentAccessible);
			tolua_function(tolua_S, "leadsDoesndifferRest2", lua_mubeReplacement_leadsDoesndifferRest2);
			tolua_function(tolua_S, "getvaluesTellsProgramming", lua_mubeReplacement_getvaluesTellsProgramming);
			tolua_function(tolua_S, "setupdatesPersistSpecifying3", lua_mubeReplacement_setupdatesPersistSpecifying3);
			tolua_function(tolua_S, "setrealizeFollowedPointed4", lua_mubeReplacement_setrealizeFollowedPointed4);
			tolua_function(tolua_S, "setstoringRuleOtherwise", lua_mubeReplacement_setstoringRuleOtherwise);
			tolua_function(tolua_S, "gotoDeath", lua_mubeReplacement_gotoDeath);
			tolua_function(tolua_S, "errorsMimicScope", lua_mubeReplacement_errorsMimicScope);
			tolua_function(tolua_S, "setinsteadCollideConsult", lua_mubeReplacement_setinsteadCollideConsult); 
			tolua_function(tolua_S, "curlyAmongEvaluating", lua_mubeReplacement_curlyAmongEvaluating);
			tolua_function(tolua_S, "begunWilreferRevisited", lua_mubeReplacement_begunWilreferRevisited);
			tolua_function(tolua_S, "possibleSurprisinglyOlder", lua_mubeReplacement_possibleSurprisinglyOlder);
			tolua_function(tolua_S, "totalImportanceRest", lua_mubeReplacement_totalImportanceRest);
			tolua_function(tolua_S, "identifiesRepresents", lua_mubeReplacement_identifiesRepresents);
			tolua_function(tolua_S, "setdesignerRvalueAbility4", lua_mubeReplacement_setdesignerRvalueAbility4);
		
			tolua_function(tolua_S, "setVisible", lua_mubeReplacement_setVisible);
			tolua_function(tolua_S, "settechniqueGenerates", lua_mubeReplacement_settechniqueGenerates);
			tolua_function(tolua_S, "setsupportedComputingRemoved", lua_mubeReplacement_setsupportedComputingRemoved);
			tolua_function(tolua_S, "clean", lua_mubeReplacement_clean);
			tolua_function(tolua_S, "setfragmentSynthesized", lua_mubeReplacement_setfragmentSynthesized);
			tolua_function(tolua_S, "setconcludesSuspendedNever", lua_mubeReplacement_setconcludesSuspendedNever);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    