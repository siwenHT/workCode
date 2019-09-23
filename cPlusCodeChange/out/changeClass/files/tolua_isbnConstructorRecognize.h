#ifndef __TOLUA_ACTORACTIONMANAGEC_H__
#define __TOLUA_ACTORACTIONMANAGEC_H__
#include "tolua++.h"
#include "isbnConstructorRecognize.h"
#include "LuaBasicConversions.h"
int lua_isbnConstructorRecognize_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			isbnConstructorRecognize* ret = isbnConstructorRecognize::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<isbnConstructorRecognize>(tolua_S, "isbnConstructorRecognize",(isbnConstructorRecognize*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_isbnConstructorRecognize_squaresImagefifth(lua_State* tolua_S)
{
    int argc = 0;
    isbnConstructorRecognize* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_squaresImagefifth'", NULL);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "squaresImagefifth");
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		cobj->squaresImagefifth((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "squaresImagefifth",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_squaresImagefifth'.",&tolua_err);
#endif
    return 0;
}
int lua_isbnConstructorRecognize_nonexternAppearPointers(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_nonexternAppearPointers'", NULL);
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
		cobj->nonexternAppearPointers((ActorComponentType)arg0,arg1);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2, "nonexternAppearPointers");
		if (!ok) { return 0; }
		cobj->nonexternAppearPointers((ActorComponentType)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nonexternAppearPointers",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_nonexternAppearPointers'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_getlimitOnlyCompletely1(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_getlimitOnlyCompletely1'", NULL);
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
		auto ret = cobj->getlimitOnlyCompletely1((ActorComponentType)arg0,arg1);
		if (nullptr != ret){
			object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getlimitOnlyCompletely1",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_getlimitOnlyCompletely1'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setconfidentKindActions(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setconfidentKindActions'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setconfidentKindActions'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setcurliesMatchDestructors(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setcurliesMatchDestructors'", NULL);
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
		cobj->setcurliesMatchDestructors(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setcurliesMatchDestructors",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setcurliesMatchDestructors'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setrepresentingBother(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setrepresentingBother'", NULL);
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
		cobj->setrepresentingBother(arg0,arg1);
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
		cobj->setrepresentingBother(arg0,arg1,(extendedUsesMatch)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrepresentingBother",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setrepresentingBother'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_gotoDeath(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_gotoDeath'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_gotoDeath'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_eamightAnotherBrown(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_eamightAnotherBrown'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->eamightAnotherBrown(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "eamightAnotherBrown",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_eamightAnotherBrown'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setsoldTellsLookup(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setsoldTellsLookup'", NULL);
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
		cobj->setsoldTellsLookup(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsoldTellsLookup",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setsoldTellsLookup'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_executesOccurrence(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_executesOccurrence'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		cocos2d::Node* arg0;
		int arg1;
		std::string arg2;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "executesOccurrence");
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->executesOccurrence(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executesOccurrence",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_executesOccurrence'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_equivalentthSuited(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_equivalentthSuited'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "equivalentthSuited");
		if (!ok) { return 0; }
		cobj->equivalentthSuited(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "equivalentthSuited",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_equivalentthSuited'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_parametersunlike(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_parametersunlike'", NULL);
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
		cobj->parametersunlike(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parametersunlike",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_parametersunlike'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_bitwiseEqualCorresponding(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_bitwiseEqualCorresponding'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->bitwiseEqualCorresponding(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "bitwiseEqualCorresponding",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_bitwiseEqualCorresponding'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_implicitlyImplementing(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_implicitlyImplementing'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "implicitlyImplementing");
		if (!ok) { return 0; }
		cobj->implicitlyImplementing(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "implicitlyImplementing",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_implicitlyImplementing'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setensureReplacedVarious(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setensureReplacedVarious'", NULL);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "implicitlyImplementing");
		if (!ok) { return 0; }
		cobj->setensureReplacedVarious((ActorComponentType)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setensureReplacedVarious",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setensureReplacedVarious'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setVisible(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setVisible'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setVisible'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setnormallyUnableActual1(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setnormallyUnableActual1'", NULL);
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
		cobj->setnormallyUnableActual1((ActorComponentType)arg0,arg1,arg2);
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
		cobj->setnormallyUnableActual1((ActorComponentType)arg0,arg1,arg2,arg3);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 6, "cc.Node",&obj, "setnormallyUnableActual1");
		if (!ok) { return 0; }
		cobj->setnormallyUnableActual1((ActorComponentType)arg0,arg1,arg2,arg3,obj);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setnormallyUnableActual1",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setnormallyUnableActual1'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setpartsCountLargest(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setpartsCountLargest'", NULL);
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
		cobj->setpartsCountLargest((ActorComponentType)arg0,arg1,arg2);
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
		cobj->setpartsCountLargest((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpartsCountLargest",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setpartsCountLargest'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_clean(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_clean'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_clean'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setnoneLookConventions(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setnoneLookConventions'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setnoneLookConventions(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setnoneLookConventions",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setnoneLookConventions'.",&tolua_err);
#endif
	return 0;
}
int lua_isbnConstructorRecognize_setcontainedWorthSpecify(lua_State* tolua_S)
{
	int argc = 0;
	isbnConstructorRecognize* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"isbnConstructorRecognize",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (isbnConstructorRecognize*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_isbnConstructorRecognize_setcontainedWorthSpecify'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setcontainedWorthSpecify(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setcontainedWorthSpecify",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_isbnConstructorRecognize_setcontainedWorthSpecify'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_isbnConstructorRecognize(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"isbnConstructorRecognize");
	tolua_cclass(tolua_S,"isbnConstructorRecognize","isbnConstructorRecognize","cc.Ref",NULL);
		tolua_beginmodule(tolua_S,"isbnConstructorRecognize");
			tolua_function(tolua_S, "getInstance", lua_isbnConstructorRecognize_getInstance);
			tolua_function(tolua_S, "squaresImagefifth", lua_isbnConstructorRecognize_squaresImagefifth);
			tolua_function(tolua_S, "nonexternAppearPointers", lua_isbnConstructorRecognize_nonexternAppearPointers);
			tolua_function(tolua_S, "getlimitOnlyCompletely1", lua_isbnConstructorRecognize_getlimitOnlyCompletely1);
			tolua_function(tolua_S, "setconfidentKindActions", lua_isbnConstructorRecognize_setconfidentKindActions);
			tolua_function(tolua_S, "setcurliesMatchDestructors", lua_isbnConstructorRecognize_setcurliesMatchDestructors);
			tolua_function(tolua_S, "setrepresentingBother", lua_isbnConstructorRecognize_setrepresentingBother);
			tolua_function(tolua_S, "gotoDeath", lua_isbnConstructorRecognize_gotoDeath);
			tolua_function(tolua_S, "eamightAnotherBrown", lua_isbnConstructorRecognize_eamightAnotherBrown);
			tolua_function(tolua_S, "setsoldTellsLookup", lua_isbnConstructorRecognize_setsoldTellsLookup); 
			tolua_function(tolua_S, "executesOccurrence", lua_isbnConstructorRecognize_executesOccurrence);
			tolua_function(tolua_S, "equivalentthSuited", lua_isbnConstructorRecognize_equivalentthSuited);
			tolua_function(tolua_S, "parametersunlike", lua_isbnConstructorRecognize_parametersunlike);
			tolua_function(tolua_S, "bitwiseEqualCorresponding", lua_isbnConstructorRecognize_bitwiseEqualCorresponding);
			tolua_function(tolua_S, "implicitlyImplementing", lua_isbnConstructorRecognize_implicitlyImplementing);
			tolua_function(tolua_S, "setensureReplacedVarious", lua_isbnConstructorRecognize_setensureReplacedVarious);
		
			tolua_function(tolua_S, "setVisible", lua_isbnConstructorRecognize_setVisible);
			tolua_function(tolua_S, "setnormallyUnableActual1", lua_isbnConstructorRecognize_setnormallyUnableActual1);
			tolua_function(tolua_S, "setpartsCountLargest", lua_isbnConstructorRecognize_setpartsCountLargest);
			tolua_function(tolua_S, "clean", lua_isbnConstructorRecognize_clean);
			tolua_function(tolua_S, "setnoneLookConventions", lua_isbnConstructorRecognize_setnoneLookConventions);
			tolua_function(tolua_S, "setcontainedWorthSpecify", lua_isbnConstructorRecognize_setcontainedWorthSpecify);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    