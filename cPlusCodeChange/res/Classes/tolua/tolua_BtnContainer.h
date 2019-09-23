#ifndef __TOLUA_BTN_CONTAINER_H__
#define __TOLUA_BTN_CONTAINER_H__

#include "tolua++.h"
#include "BtnContainer.h"
#include "LuaBasicConversions.h"

/* method: create of class  BtnContainer */
int lua_BtnContainer_create(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
        do 
		{
			ok &= luaval_to_number(tolua_S, 2,&arg0);
			if (!ok) { break; }
			BtnContainer* ret = BtnContainer::create((float)arg0);
			do {
				if (NULL != ret){
					object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
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
		double arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ok &= luaval_to_number(tolua_S, 3,&arg1);
			if (!ok) { break; }
			BtnContainer* ret = BtnContainer::create(arg0,(float)arg1);
			do {
				if (NULL != ret){
					tolua_pushusertype(tolua_S,(void*)ret,"BtnContainer");
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
    tolua_error(tolua_S,"#ferror in function 'lua_BtnContainer_create'.",&tolua_err);
#endif
    return 0;

}


/* method: createTopContainer of class  BtnContainer */
int lua_BtnContainer_createTopContainer(lua_State* tolua_S)
{
	int argc = 0;
    bool ok  = true;
	#if COCOS2D_DEBUG >= 1
		tolua_Error tolua_err;
	#endif

	#if COCOS2D_DEBUG >= 1
		if (!tolua_isusertable(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
	#endif
    argc = lua_gettop(tolua_S)-1;
	if(argc == 1)
	{
		double arg0;
        do 
		{
			ok &= luaval_to_number(tolua_S, 2,&arg0);
			if (!ok) { break; }
			BtnContainer* ret = BtnContainer::createTopContainer((float)arg0);
			do {
				if (NULL != ret){
					object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
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
		double arg1;
        do 
		{
			ok &= luaval_to_std_string(tolua_S, 2,&arg0);
			if (!ok) { break; }
			ok &= luaval_to_number(tolua_S, 3,&arg1);
			if (!ok) { break; }
			BtnContainer* ret = BtnContainer::createTopContainer(arg0,(float)arg1);
			do {
				if (NULL != ret){
					object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
				}
				else
					lua_pushnil(tolua_S);
				} while (0);
			 return 1;
		} while (0);
	}
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createTopContainer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_BtnContainer_createTopContainer'.",&tolua_err);
#endif
    return 0;

}


/* method: addItem of class  BtnContainer */
int lua_BtnContainer_addItem(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_BtnContainer_addItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		MenuButton* ret = (MenuButton*)tolua_tousertype(tolua_S,2,0);
		cobj->addItem(ret);
		lua_settop(tolua_S, 1);
		return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_BtnContainer_addItem'.",&tolua_err);
#endif

    return 0;
}


int lua_register_cocos2dx_BtnContainer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BtnContainer");
	tolua_cclass(tolua_S,"BtnContainer","BtnContainer","cc.Sprite",NULL);	
		tolua_beginmodule(tolua_S,"BtnContainer");
			tolua_function(tolua_S, "create", lua_BtnContainer_create);
			tolua_function(tolua_S, "createTopContainer", lua_BtnContainer_createTopContainer);
			tolua_function(tolua_S, "addItem", lua_BtnContainer_addItem);
		tolua_endmodule(tolua_S);
    return 1;
}

#endif    //__TOLUA_BTN_CONTAINER_H__