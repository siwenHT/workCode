#ifndef __TOLUA_MAPBASE_H__
#define __TOLUA_MAPBASE_H__

#include "tolua++.h"
#include "MapView.h"
#include "MapBackLayer.h"
#include "LuaBasicConversions.h"

/* method: create of class  MapView */
int lua_MapView_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{

        do 
		{
			MapView* ret = MapView::create();
			do {
				if (NULL != ret){
					object_to_luaval<MapView>(tolua_S, "MapView",(MapView*)ret);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;

}

/* method: create of class  MapView */
int lua_MapView_create1(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
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
			MapView* ret = MapView::create(arg0,arg1,arg2, arg3);
			do {
				if (NULL != ret){
					object_to_luaval<MapView>(tolua_S, "MapView",(MapView*)ret);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;

}

/* method: getMapScale of class  MapView */
int lua_MapView_getMapScale(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "MapView", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		float ret = MapView::getMapScale();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "getMapScale", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "", &tolua_err);
#endif
				return 0;

}

/* method: setMapScale of class  MapView */
int lua_MapView_setMapScale(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "MapView", 0, &tolua_err)) goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		double arg0;

		ok &= luaval_to_number(tolua_S, 2, &arg0);
		if (!ok)
		{
			tolua_error(tolua_S, "", nullptr);
			return 0;
		}
		MapView::setMapScale(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d", "setMapScale", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "", &tolua_err);
#endif
				return 0;

}

/* method: loadMap of class  MapView */
int lua_MapView_loadMap(lua_State* tolua_S)
{
   int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif


	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
	#endif

		cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"", NULL);
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
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;

}
/* method: loadSpritesPre of class  MapView */
int lua_MapView_loadSpritesPre(lua_State* tolua_S)
{
   int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif


	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
	#endif

		cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

	#if COCOS2D_DEBUG >= 1
		if (!cobj) 
		{
			tolua_error(tolua_S,"", NULL);
			return 0;
		}
	#endif

    argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		cobj->loadSpritesPre();
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "loadSpritesPre",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif
    return 0;

}
/* method: setMainRole of class  MapView */
int lua_MapView_setMainRole(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		//if (NULL != ret){
				cobj->setMainRole(ret);
				lua_settop(tolua_S, 1);
				return 1;
		//	}
		//else {
		//	return 0;
		//}
       
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMainRole",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


/* method: getMainRole of class  MapView */
int lua_MapView_getMainRole(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		SpritePlayer* ret = cobj->getMainRole();
		do {
			if (NULL != ret){
				tolua_pushusertype(tolua_S,(void*)ret,"SpritePlayer");
			}
			else
				lua_pushnil(tolua_S);
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMainRole",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

/* method: setIsLoadFinished of class  MapView */
int lua_MapView_setIsLoadFinished(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setIsLoadFinished(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsLoadFinished",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

/* method: setMapSpan of class  MapView */
int lua_MapView_setMapSpan(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_int32(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->setMapSpan(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMapSpan",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

/* method: setIsResReady of class  MapView */
int lua_MapView_setIsResReady(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->setIsResReady(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIsResReady",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

/* method: systemMoveRoleToPos of class  MapView */
int lua_MapView_systemMoveRoleToPos(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->systemMoveRoleToPos(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "systemMoveRoleToPos",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

/* method: moveMapByPos of class  MapView */
int lua_MapView_moveMapByPos(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->moveMapByPos(arg0);
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
		cobj->moveMapByPos(arg0,arg1);
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
		cobj->moveMapByPos(arg0,arg1,arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveMapByPos",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

/* method: moveMonsterByPos of class  MapView */
int lua_MapView_moveMonsterByPos(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		SpriteMonster* arg1;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (SpriteMonster*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		Point arg4[256];  
		int ret = cobj->moveMonsterByPos(arg0,arg1,3.0,true,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
    }
	else if (argc == 4||argc == 3) 
	{
		Point arg0;
		SpriteMonster* arg1;
		double arg2;
		bool arg3 = true;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		arg1 = (SpriteMonster*)tolua_tousertype(tolua_S,3,0);
		if(arg1==NULL) return 0;
		ok &= luaval_to_number(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		if(argc == 4)
		{
			ok &= luaval_to_boolean(tolua_S, 5, &arg3); 
			if (!ok) { return 0; }
		}
		Point arg4[256];  
		int ret = cobj->moveMonsterByPos(arg0,arg1,(float)arg2,arg3,arg4);
		vec2_array_to_luaval(tolua_S, arg4, ret);
        return 1;
	}

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveMonsterByPos",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


int lua_MapView_stopMonsterByPos(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", NULL);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S)-1;
	if(argc == 1){
		SpriteMonster* arg0;
		ok &= luaval_to_object<SpriteMonster>(tolua_S, 2, "SpriteMonster",&arg0, "stopMonsterByPos");
		if (!ok) { return 0; }
		cobj->stopMonsterByPos(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 2) 
	{
		SpriteMonster* arg0;
		Point arg1;
		ok &= luaval_to_object<SpriteMonster>(tolua_S, 2, "SpriteMonster",&arg0, "stopMonsterByPos");
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		cobj->stopMonsterByPos(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}

	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopMonsterByPos",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

/* method: moveMapByTouch of class  MapView */
int lua_MapView_moveMapByTouch(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->moveMapByTouch(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveMapByTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_tile2Space(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->tile2Space(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tile2Space",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_space2Tile(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->space2Tile(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "space2Tile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_scroll2Tile(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->scroll2Tile(arg0);
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
		cobj->scroll2Tile(arg0,(float)arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scroll2Tile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_skip2Tile(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//lua_MapView_updateAllAddMapId
int lua_MapView_updateAllAddMapId(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->updateAllAddMapId(arg0);
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
		cobj->updateAllAddMapId(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateAllAddMapId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}



//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_initDataAndFunc(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		cobj->initDataAndFunc();
		lua_settop(tolua_S, 1);
		return 1;
    }
	else if (argc == 1) 
    {
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->initDataAndFunc(arg0);
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
		cobj->initDataAndFunc(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initDataAndFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_getTileByDir(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		const cocos2d::Point& ret = cobj->getTileByDir((Commen_Direction)arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTileByDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


//tile℅?㊣那℅a????℅?㊣那
int lua_MapView_getDirByTile(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		Commen_Direction ret = cobj->getDirByTile(arg0);
        lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirByTile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


int lua_MapView_registerWalkCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerWalkCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerWalkCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_registerSuddenCb(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerSuddenCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerSuddenCb",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

int lua_MapView_registerFlyCb(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerFlyCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerFlyCb",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

int lua_MapView_removeWalkCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeWalkCb();
	lua_settop(tolua_S, 1);
	return 1;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_registerRockerCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerRockerCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerRockerCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_removeRockerCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeRockerCb();
	lua_settop(tolua_S, 1);
	return 1;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_registerTouchMoveCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerTouchMoveCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerTouchMoveCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_removeTouchMoveCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeTouchMoveCb();
	lua_settop(tolua_S, 1);
	return 1;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//resetDisplay
int lua_MapView_resetDisplay(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		bool arg0;
		ok =  luaval_to_boolean(tolua_S,2,&arg0);
		if (!ok) { return 0; }
		cobj->resetDisplay(arg0);
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
		cobj->resetDisplay(arg0,arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetDisplay",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}


//registerResetDisplayCb
int lua_MapView_registerResetDisplayCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerResetDisplayCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerRockerCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_registerNoMoveCb(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		cobj->registerNoMoveCb(0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 1) 
	{
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerNoMoveCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerNoMoveCb",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

int lua_MapView_registerSuddenDistance(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		double arg0;
		double arg1;
		Point arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_number(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 4, &arg2); 
		if (!ok) { return 0; }
		bool ret = cobj->registerSuddenDistance((float)arg0,arg1,arg2);
		tolua_pushboolean(tolua_S, ret);
		return 1;
	}

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

//removeResetDisplayCb
int lua_MapView_removeResetDisplayCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeResetDisplayCb();
	lua_settop(tolua_S, 1);
	return 1;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}
//

//isBlock℅?㊣那℅a????℅?㊣那
int lua_MapView_isBlock(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_isLoadFinished(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		bool ret = cobj->isLoadFinished();
        lua_pushboolean(tolua_S, ret);
        return 1;
    }
	else if (argc == 1)
	{
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }

		bool ret = cobj->isLoadFinished(arg0);
		lua_pushboolean(tolua_S, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isLoadFinished",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//isOpacity℅?㊣那℅a????℅?㊣那
int lua_MapView_isOpacity(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_getFlagValue(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Point arg0;
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		int ret = cobj->getFlagValue(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFlagValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


int lua_MapView_cleanAstarPath(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		cobj->cleanAstarPath();
		lua_settop(tolua_S, 1);
		return 1;
    }
    else if (argc == 1) 
    {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->cleanAstarPath(arg0);
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

		cobj->cleanAstarPath(arg0, arg1);
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

		cobj->cleanAstarPath(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanAstarPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}


int lua_MapView_onMoveSpeedChangeAction(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		cobj->onMoveSpeedChangeAction();
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onMoveSpeedChangeAction",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}


//getPathByPos℅?㊣那℅a????℅?㊣那
int lua_MapView_getPathByPos(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		
		Point arg0;
		Point arg1;
		bool  selfFlg = false;
		Point arg2[1024];
		ok &= luaval_to_point(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		ok &= luaval_to_point(tolua_S, 3, &arg1); 
		if (!ok) { return 0; }
		int ret = cobj->getPathByPos(arg0,arg1,selfFlg,arg2);
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
		int ret = cobj->getPathByPos(arg0,arg1,selfFlg,arg2);
		vec2_array_to_luaval(tolua_S, arg2, ret);
		return 1;
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPathByPos",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

//getPathByPos℅?㊣那℅a????℅?㊣那
int lua_MapView_resetSpeed(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0); 
		if (!ok) { return 0; }
		cobj->resetSpeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_getSpeed(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		double speed = cobj->getSpeed();
		tolua_pushnumber(tolua_S, (lua_Number)speed);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpeed",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

int lua_MapView_getLayerSize(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getLayerSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getLayerSize",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}
int lua_MapView_getMapTileSize(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S)-1;
	if (argc == 0) 
	{
		if(!ok)
		{
			tolua_error(tolua_S,"", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getMapTileSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getMapTileSize",argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}

int lua_MapView_hasBlock(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
	tolua_error(tolua_S,"",&tolua_err);
#endif

	return 0;
}


//
int lua_MapView_registerAddTopHeadNodeToMapCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 =  toluafix_ref_function(tolua_S,2,0);
		if (!arg0) { return 0; }
		cobj->registerAddTopHeadNodeToMapCb(arg0);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerAddTopHeadNodeToMapCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}
//
int lua_MapView_removeTopHeadNodeToMapCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"", NULL);
        return 0;
    }
#endif
	cobj->removeAddTopHeadNodeToMapCb();
	lua_settop(tolua_S, 1);
	return 1;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"",&tolua_err);
#endif

    return 0;
}

int lua_MapView_setResetDisplayGap(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		int arg0;
		arg0 = luaval_to_int32(tolua_S, 2, &arg0); 
		if (!arg0) { return 0; }
		cobj->setResetDisplayGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_MapView_setFollowNode(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		Node* arg0 = nullptr;
		ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "setFollowNode");
		if (!ok) { return 0; }
		cobj->setFollowNode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if(argc == 0)
	{
		cobj->setFollowNode(nullptr);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFollowNode", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_MapView_UserOldMoveMap(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

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
		bool arg0 = false;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		if (!ok) { return 0; }

		cobj->setUserOldMoveMap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UserOldMoveMap", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_MapView_preAsyncLoadImg(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "MapView", 0, &tolua_err)) goto tolua_lerror;
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

		MapView::preAsyncLoadImg(arg0,arg1,arg2);
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

		MapView::preAsyncLoadImg(arg0,arg1,arg2,arg3,arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preAsyncLoadImg", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}


int lua_register_cocos2dx_MapView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapView");
	tolua_cclass(tolua_S,"MapView","MapView","cc.Layer",NULL);	
		tolua_beginmodule(tolua_S,"MapView");
			tolua_function(tolua_S, "create", lua_MapView_create);
			tolua_function(tolua_S, "setMapScale", lua_MapView_setMapScale);
			tolua_function(tolua_S, "getMapScale", lua_MapView_getMapScale);
			tolua_function(tolua_S, "loadMap", lua_MapView_loadMap);
			tolua_function(tolua_S, "loadSpritesPre", lua_MapView_loadSpritesPre);	
			tolua_function(tolua_S, "getMainRole", lua_MapView_getMainRole);
			tolua_function(tolua_S, "setMainRole", lua_MapView_setMainRole);
			tolua_function(tolua_S, "systemMoveRoleToPos", lua_MapView_systemMoveRoleToPos);
			tolua_function(tolua_S, "moveMapByPos", lua_MapView_moveMapByPos);
			tolua_function(tolua_S, "moveMonsterByPos", lua_MapView_moveMonsterByPos);		
			tolua_function(tolua_S, "moveMapByPosition", lua_MapView_moveMapByTouch);		
			tolua_function(tolua_S, "stopMonsterByPos", lua_MapView_stopMonsterByPos);
			tolua_function(tolua_S, "tile2Space", lua_MapView_tile2Space);
			tolua_function(tolua_S, "space2Tile", lua_MapView_space2Tile);
			tolua_function(tolua_S, "scroll2Tile", lua_MapView_scroll2Tile);
			tolua_function(tolua_S, "skip2Tile", lua_MapView_skip2Tile);
			tolua_function(tolua_S, "updateAllAddMapId", lua_MapView_updateAllAddMapId);
			tolua_function(tolua_S, "initDataAndFunc", lua_MapView_initDataAndFunc);
			tolua_function(tolua_S, "getTileByDir", lua_MapView_getTileByDir);
			tolua_function(tolua_S, "getDirByTile", lua_MapView_getDirByTile);
			tolua_function(tolua_S, "registerWalkCb", lua_MapView_registerWalkCb);
			tolua_function(tolua_S, "registerFlyCb", lua_MapView_registerFlyCb);
			tolua_function(tolua_S, "registerSuddenCb", lua_MapView_registerSuddenCb);
			tolua_function(tolua_S, "removeWalkCb", lua_MapView_removeWalkCb);
			tolua_function(tolua_S, "registerRockerCb", lua_MapView_registerRockerCb);
			tolua_function(tolua_S, "removeRockerCb", lua_MapView_removeRockerCb);
			tolua_function(tolua_S, "registerTouchMoveCb", lua_MapView_registerTouchMoveCb);
			tolua_function(tolua_S, "removeTouchMoveCb", lua_MapView_removeTouchMoveCb);
			tolua_function(tolua_S, "registerResetDisplayCb", lua_MapView_registerResetDisplayCb);
			tolua_function(tolua_S, "registerNoMoveCb", lua_MapView_registerNoMoveCb);
			tolua_function(tolua_S, "resetDisplay", lua_MapView_resetDisplay);
			tolua_function(tolua_S, "removeResetDisplayCb", lua_MapView_removeResetDisplayCb);
			tolua_function(tolua_S, "registerSuddenDistance", lua_MapView_registerSuddenDistance);
			tolua_function(tolua_S, "isBlock", lua_MapView_isBlock);
			tolua_function(tolua_S, "isOpacity", lua_MapView_isOpacity);
			tolua_function(tolua_S, "getFlagValue", lua_MapView_getFlagValue);
			tolua_function(tolua_S, "isLoadFinished", lua_MapView_isLoadFinished);
			tolua_function(tolua_S, "setIsLoadFinished", lua_MapView_setIsLoadFinished);
			tolua_function(tolua_S, "setIsResReady", lua_MapView_setIsResReady);
			tolua_function(tolua_S, "setMapSpan", lua_MapView_setMapSpan);
			tolua_function(tolua_S, "cleanAstarPath", lua_MapView_cleanAstarPath);
			tolua_function(tolua_S, "onMoveSpeedChangeAction", lua_MapView_onMoveSpeedChangeAction);
			tolua_function(tolua_S, "getPathByPos", lua_MapView_getPathByPos);
			tolua_function(tolua_S, "resetSpeed", lua_MapView_resetSpeed);
			tolua_function(tolua_S, "getSpeed", lua_MapView_getSpeed);
			tolua_function(tolua_S, "getLayerSize", lua_MapView_getLayerSize);
			tolua_function(tolua_S, "getMapTileSize", lua_MapView_getMapTileSize);
			tolua_function(tolua_S, "hasBlock", lua_MapView_hasBlock);

			tolua_function(tolua_S, "registerAddTopHeadNodeToMapCb", lua_MapView_registerAddTopHeadNodeToMapCb);
			tolua_function(tolua_S, "removeTopHeadNodeToMapCb",      lua_MapView_removeTopHeadNodeToMapCb);
			tolua_function(tolua_S, "setResetDisplayGap",      lua_MapView_setResetDisplayGap);
			tolua_function(tolua_S, "setFollowNode",      lua_MapView_setFollowNode);
			tolua_function(tolua_S, "userOldMoveMap",      lua_MapView_UserOldMoveMap);
			tolua_function(tolua_S, "preAsyncLoadImg",      lua_MapView_preAsyncLoadImg);
		tolua_endmodule(tolua_S);
    return 1;
}



int lua_MapBackLayer_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S,1,"MapBackLayer",0,&tolua_err)) 
		goto tolua_lerror;
#endif
	argc = lua_gettop(tolua_S)-1;
	if(argc == 0)
	{
		do 
		{
			MapBackLayer* ret = MapBackLayer::create();
			do 
			{
				if (NULL != ret)
				{
					object_to_luaval<MapBackLayer>(tolua_S, "MapBackLayer",(MapBackLayer*)ret);
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
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_MapBackLayer_setSpeedRate(lua_State* tolua_S)
{
	int argc = 0;
	MapBackLayer* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"MapBackLayer",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapBackLayer*)tolua_tousertype(tolua_S,1,0);

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
		double arg0;
		ok = luaval_to_number(tolua_S, 2, &arg0);
		if (!arg0) { return 0; }
		cobj->setSpeedRate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	return 1;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"",&tolua_err);
#endif
	return 0;
}

int lua_register_cocos2dx_MapBackLayer(lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"MapBackLayer");
	tolua_cclass(tolua_S,"MapBackLayer","MapBackLayer","cc.Layer",NULL);	
	tolua_beginmodule(tolua_S,"MapBackLayer"); 

	tolua_function(tolua_S, "create", lua_MapBackLayer_create);
	tolua_function(tolua_S, "setSpeedRate", lua_MapBackLayer_setSpeedRate);

	tolua_endmodule(tolua_S);
	return 1;
}


#endif    //__TOLUA_MAPBASE_H__