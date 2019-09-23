#ifndef __TOLUA_CCEFFECTS_H__
#define __TOLUA_CCEFFECTS_H__
#include "tolua++.h"
#include "CCknewOverheadSupplied.h"
#include "LuaBasicConversions.h"
int lua_knewOverheadSupplied_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		bool arg0;
        do 
		{
			ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
			if (!ok) { break; }
			knewOverheadSupplied* ret = knewOverheadSupplied::create(arg0);
			do {
				if (NULL != ret){
					object_to_luaval<knewOverheadSupplied>(tolua_S, "knewOverheadSupplied",(knewOverheadSupplied*)ret);
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
			knewOverheadSupplied* ret = knewOverheadSupplied::create(arg0,arg1);
			do {
				if (NULL != ret){
					object_to_luaval<knewOverheadSupplied>(tolua_S, "knewOverheadSupplied",(knewOverheadSupplied*)ret);
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
			knewOverheadSupplied* ret = knewOverheadSupplied::create(arg0, arg1, arg2);
			do {
				if (NULL != ret){
					object_to_luaval<knewOverheadSupplied>(tolua_S, "knewOverheadSupplied",(knewOverheadSupplied*)ret);
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
    tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_create'.",&tolua_err);
#endif
    return 0;
}
int lua_knewOverheadSupplied_imageRevisedCaltoFront(lua_State* tolua_S)
{
    int argc = 0;
    knewOverheadSupplied* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_imageRevisedCaltoFront'", NULL);
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
		cobj->imageRevisedCaltoFront(arg0,arg1,(float)arg2,arg3,(float)arg4);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "imageRevisedCaltoFront",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_imageRevisedCaltoFront'.",&tolua_err);
#endif
    return 0;
}
int lua_knewOverheadSupplied_setstartStoplightZero(lua_State* tolua_S)
{
    int argc = 0;
    knewOverheadSupplied* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setstartStoplightZero'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc ==1) 
    {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setstartStoplightZero(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setstartStoplightZero",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setstartStoplightZero'.",&tolua_err);
#endif
    return 0;
}
int lua_knewOverheadSupplied_setsupportedComputingRemoved(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setsupportedComputingRemoved'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setsupportedComputingRemoved(arg0);
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
		cobj->setsupportedComputingRemoved(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsupportedComputingRemoved",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setsupportedComputingRemoved'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_getsupportedComputingRemoved(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_getsupportedComputingRemoved'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		int ret = cobj->getsupportedComputingRemoved();
		tolua_pushnumber(tolua_S,(int)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getsupportedComputingRemoved",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_getsupportedComputingRemoved'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_setreviseStringWhen(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setreviseStringWhen'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setreviseStringWhen(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setreviseStringWhen",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setreviseStringWhen'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_reset(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_reset'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_reset'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_setIsHide(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setIsHide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_getIsHide(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_getIsHide'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_getIsHide'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_rePlay(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_rePlay'", NULL);
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
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_rePlay'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_setexhaustedReferenceIntend(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setexhaustedReferenceIntend'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setexhaustedReferenceIntend(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setexhaustedReferenceIntend",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setexhaustedReferenceIntend'.",&tolua_err);
#endif
	return 0;
}
int lua_knewOverheadSupplied_setsmatchIllustratePoint(lua_State* tolua_S)
{
	int argc = 0;
	knewOverheadSupplied* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"knewOverheadSupplied",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (knewOverheadSupplied*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_knewOverheadSupplied_setsmatchIllustratePoint'", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc ==1) 
	{
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setsmatchIllustratePoint(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setsmatchIllustratePoint",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_knewOverheadSupplied_setsmatchIllustratePoint'.",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_knewOverheadSupplied(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"knewOverheadSupplied");
	tolua_cclass(tolua_S,"knewOverheadSupplied","knewOverheadSupplied","cc.Sprite",NULL);
		tolua_beginmodule(tolua_S,"knewOverheadSupplied");
			tolua_function(tolua_S, "create", lua_knewOverheadSupplied_create);
			tolua_function(tolua_S, "imageRevisedCaltoFront", lua_knewOverheadSupplied_imageRevisedCaltoFront);
		
			tolua_function(tolua_S, "setstartStoplightZero", lua_knewOverheadSupplied_setstartStoplightZero);
			tolua_function(tolua_S, "setsupportedComputingRemoved", lua_knewOverheadSupplied_setsupportedComputingRemoved);
			tolua_function(tolua_S, "getsupportedComputingRemoved", lua_knewOverheadSupplied_getsupportedComputingRemoved);
			tolua_function(tolua_S, "setIsHide", lua_knewOverheadSupplied_setIsHide);
			tolua_function(tolua_S, "getIsHide", lua_knewOverheadSupplied_getIsHide);
			tolua_function(tolua_S, "rePlay", lua_knewOverheadSupplied_rePlay);
			tolua_function(tolua_S, "setreviseStringWhen", lua_knewOverheadSupplied_setreviseStringWhen);
			tolua_function(tolua_S, "reset", lua_knewOverheadSupplied_reset);
			tolua_function(tolua_S, "setexhaustedReferenceIntend", lua_knewOverheadSupplied_setexhaustedReferenceIntend);
			tolua_function(tolua_S, "setsmatchIllustratePoint", lua_knewOverheadSupplied_setsmatchIllustratePoint);
	
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    