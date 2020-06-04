#ifndef __TOLUA_ACTORACTIONMANAGEC_H__
#define __TOLUA_ACTORACTIONMANAGEC_H__
#include "tolua++.h"
#include "ActorActionManageC.h"
#include "LuaBasicConversions.h"
int lua_ActorActionManageC_getInstance(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif
	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
        do 
		{
			ActorActionManageC* ret = ActorActionManageC::getInstance();
			do {
				if (NULL != ret){
					object_to_luaval<ActorActionManageC>(tolua_S, "ActorActionManageC",(ActorActionManageC*)ret);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_ActorActionManageC_addComponent(lua_State* tolua_S)
{
    int argc = 0;
    ActorActionManageC* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "addComponent");
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 5, &arg3);
		if (!ok) { return 0; }
		cobj->addComponent((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addComponent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;
}
int lua_ActorActionManageC_removeComponent(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->removeComponent((ActorComponentType)arg0,arg1);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2, "removeComponent");
		if (!ok) { return 0; }
		cobj->removeComponent((ActorComponentType)arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeComponent",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_getComponentByTypeAndId(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		auto ret = cobj->getComponentByTypeAndId((ActorComponentType)arg0,arg1);
		if (nullptr != ret){
			object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
		}
		else
			lua_pushnil(tolua_S);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getComponentByTypeAndId",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setMainRole(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		SpritePlayer* ret = (SpritePlayer*)tolua_tousertype(tolua_S,2,0);
		cobj->setMainRole(ret);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMainRole",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setVisibleRole(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->setVisibleRole(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisibleRole",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setHideWithChildren(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->setHideWithChildren(arg0,arg1);
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
		cobj->setHideWithChildren(arg0,arg1,(SpriteType)arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHideWithChildren",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_gotoDeath(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_gotoRevive(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->gotoRevive(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoRevive",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setWhiteCb(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->setWhiteCb(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWhiteCb",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_restoreMainRole(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 3) 
	{
		cocos2d::Node* arg0;
		int arg1;
		std::string arg2;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "restoreMainRole");
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1);
		if (!ok) { return 0; }
		ok &= luaval_to_std_string(tolua_S, 4, &arg2);
		if (!ok) { return 0; }
		cobj->restoreMainRole(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "restoreMainRole",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_retainMainRole(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "retainMainRole");
		if (!ok) { return 0; }
		cobj->retainMainRole(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "retainMainRole",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_copyMainRole(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->copyMainRole(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copyMainRole",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_removeActor(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->removeActor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeActor",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_cleanOtherActor(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		cocos2d::Node* arg0;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cleanOtherActor");
		if (!ok) { return 0; }
		cobj->cleanOtherActor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanOtherActor",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setShowLayer(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cleanOtherActor");
		if (!ok) { return 0; }
		cobj->setShowLayer((ActorComponentType)arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setShowLayer",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setVisible(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setVisibleCustom(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->setVisibleCustom((ActorComponentType)arg0,arg1,arg2);
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
		cobj->setVisibleCustom((ActorComponentType)arg0,arg1,arg2,arg3);
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
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 6, "cc.Node",&obj, "setVisibleCustom");
		if (!ok) { return 0; }
		cobj->setVisibleCustom((ActorComponentType)arg0,arg1,arg2,arg3,obj);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisibleCustom",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setOpacityCustom(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
		cobj->setOpacityCustom((ActorComponentType)arg0,arg1,arg2);
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
		cobj->setOpacityCustom((ActorComponentType)arg0,arg1,arg2,arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacityCustom",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_clean(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setMainRoleId(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0);
		if (!ok) { return 0; }
		cobj->setMainRoleId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMainRoleId",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_ActorActionManageC_setVersionChannel(lua_State* tolua_S)
{
	int argc = 0;
	ActorActionManageC* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"ActorActionManageC",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (ActorActionManageC*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setVersionChannel(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVersionChannel",argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}
int lua_register_cocos2dx_ActorActionManageC(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ActorActionManageC");
	tolua_cclass(tolua_S,"ActorActionManageC","ActorActionManageC","cc.Ref",NULL);
		tolua_beginmodule(tolua_S,"ActorActionManageC");
			tolua_function(tolua_S, "getInstance", lua_ActorActionManageC_getInstance);
			tolua_function(tolua_S, "addComponent", lua_ActorActionManageC_addComponent);
			tolua_function(tolua_S, "removeComponent", lua_ActorActionManageC_removeComponent);
			tolua_function(tolua_S, "getComponentByTypeAndId", lua_ActorActionManageC_getComponentByTypeAndId);
			tolua_function(tolua_S, "setMainRole", lua_ActorActionManageC_setMainRole);
			tolua_function(tolua_S, "setVisibleRole", lua_ActorActionManageC_setVisibleRole);
			tolua_function(tolua_S, "setHideWithChildren", lua_ActorActionManageC_setHideWithChildren);
			tolua_function(tolua_S, "gotoDeath", lua_ActorActionManageC_gotoDeath);
			tolua_function(tolua_S, "gotoRevive", lua_ActorActionManageC_gotoRevive);
			tolua_function(tolua_S, "setWhiteCb", lua_ActorActionManageC_setWhiteCb); 
			tolua_function(tolua_S, "restoreMainRole", lua_ActorActionManageC_restoreMainRole);
			tolua_function(tolua_S, "retainMainRole", lua_ActorActionManageC_retainMainRole);
			tolua_function(tolua_S, "copyMainRole", lua_ActorActionManageC_copyMainRole);
			tolua_function(tolua_S, "removeActor", lua_ActorActionManageC_removeActor);
			tolua_function(tolua_S, "cleanOtherActor", lua_ActorActionManageC_cleanOtherActor);
			tolua_function(tolua_S, "setShowLayer", lua_ActorActionManageC_setShowLayer);
		
			tolua_function(tolua_S, "setVisible", lua_ActorActionManageC_setVisible);
			tolua_function(tolua_S, "setVisibleCustom", lua_ActorActionManageC_setVisibleCustom);
			tolua_function(tolua_S, "setOpacityCustom", lua_ActorActionManageC_setOpacityCustom);
			tolua_function(tolua_S, "clean", lua_ActorActionManageC_clean);
			tolua_function(tolua_S, "setMainRoleId", lua_ActorActionManageC_setMainRoleId);
			tolua_function(tolua_S, "setVersionChannel", lua_ActorActionManageC_setVersionChannel);
		tolua_endmodule(tolua_S);
    return 1;
}
#endif    