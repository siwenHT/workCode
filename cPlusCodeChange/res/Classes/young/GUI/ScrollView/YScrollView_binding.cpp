/*
** Lua binding: YScrollView
** Generated automatically by tolua++-1.0.92 on 04/09/14 14:37:15.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_YScrollView_open (lua_State* tolua_S);

#include "GUI/ScrollView/YScrollView.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
USING_NS_YOUNG



static int YScrollView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);
            if (!ok) { break; }
            YScrollView* ret = YScrollView::create(arg0);
            object_to_luaval<YScrollView>(tolua_S, "YScrollView",(YScrollView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::Node* arg1;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1);
            if (!ok) { break; }
            YScrollView* ret = YScrollView::create(arg0, arg1);
            object_to_luaval<YScrollView>(tolua_S, "YScrollView",(YScrollView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_create'.",&tolua_err);
#endif
    return 0;
}

int YScrollView_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_setDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YScrollView::Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_setDirection'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_getDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_getDirection'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_setViewSize(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_setViewSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setViewSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setViewSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_setViewSize'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_getViewSize(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_getViewSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getViewSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getViewSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_getViewSize'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_getContainer(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_getContainer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getContainer();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContainer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_getContainer'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_stoppedAnimatedScroll(lua_State* tolua_S)
{
	int argc = 0;
	YScrollView* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_stoppedAnimatedScroll'", nullptr);
		return 0;
	}
#endif

	cobj->stoppedAnimatedScroll(cobj);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'YScrollView_stoppedAnimatedScroll'.",&tolua_err);
#endif
	return 0;
}

int YScrollView_setContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_setContentOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentOffset(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        bool arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setContentOffset(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_setContentOffset'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_getContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_getContentOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Point ret = cobj->getContentOffset();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_getContentOffset'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_setContentOffsetInDuration(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_setContentOffsetInDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        double arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setContentOffsetInDuration(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetInDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_setContentOffsetInDuration'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_setTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_setTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_setTouchEnabled'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_isTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_isTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_isTouchEnabled'.",&tolua_err);
#endif

    return 0;
}

int YScrollView_updateTweenAction(lua_State* tolua_S)
{
    int argc = 0;
    YScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YScrollView_updateTweenAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        std::string arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->updateTweenAction(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateTweenAction",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YScrollView_updateTweenAction'.",&tolua_err);
#endif

    return 0;
}

/* Open function */
TOLUA_API int tolua_YScrollView_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "YScrollView");
	tolua_cclass(tolua_S, "YScrollView", "YScrollView", "cc.Layer", nullptr);
	
	tolua_beginmodule(tolua_S, "YScrollView");
		tolua_constant(tolua_S, "HORIZONTAL", (int)YScrollView::Direction::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (int)YScrollView::Direction::VERTICAL);
		tolua_constant(tolua_S, "BOTH", (int)YScrollView::Direction::BOTH);
		tolua_function(tolua_S, "create", YScrollView_create);
		tolua_function(tolua_S, "setDirection", YScrollView_setDirection);
		tolua_function(tolua_S, "getDirection", YScrollView_getDirection);
		tolua_function(tolua_S, "setViewSize", YScrollView_setViewSize);
		tolua_function(tolua_S, "getViewSize", YScrollView_getViewSize);
		tolua_function(tolua_S, "getContainer", YScrollView_getContainer);
		tolua_function(tolua_S, "setContentOffset", YScrollView_setContentOffset);
		tolua_function(tolua_S, "getContentOffset", YScrollView_getContentOffset);
		tolua_function(tolua_S, "setContentOffsetInDuration", YScrollView_setContentOffsetInDuration);
		tolua_function(tolua_S, "stoppedAnimatedScroll", YScrollView_stoppedAnimatedScroll);
		tolua_function(tolua_S, "setTouchEnabled", YScrollView_setTouchEnabled);
		tolua_function(tolua_S, "isTouchEnabled", YScrollView_isTouchEnabled);
		tolua_function(tolua_S, "updateTweenAction", YScrollView_updateTweenAction);
	tolua_endmodule(tolua_S);
	
	return 0;
}

