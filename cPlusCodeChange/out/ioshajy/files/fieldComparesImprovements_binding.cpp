
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
TOLUA_API int  tolua_fieldComparesImprovements_open (lua_State* tolua_S);
#include "fieldComparesImprovements.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
USING_NS_YOUNG
static int fieldComparesImprovements_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
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
            fieldComparesImprovements* ret = fieldComparesImprovements::create(arg0);
            object_to_luaval<fieldComparesImprovements>(tolua_S, "fieldComparesImprovements",(fieldComparesImprovements*)ret);
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
            fieldComparesImprovements* ret = fieldComparesImprovements::create(arg0, arg1);
            object_to_luaval<fieldComparesImprovements>(tolua_S, "fieldComparesImprovements",(fieldComparesImprovements*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_create'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_setmultiplyingTarget(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_setmultiplyingTarget'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fieldComparesImprovements::multiplyingTarget arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setmultiplyingTarget(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setmultiplyingTarget",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_setmultiplyingTarget'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_getmultiplyingTarget(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_getmultiplyingTarget'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getmultiplyingTarget();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getmultiplyingTarget",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_getmultiplyingTarget'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_setdereferenceAppearGave(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_setdereferenceAppearGave'", nullptr);
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
        cobj->setdereferenceAppearGave(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setdereferenceAppearGave",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_setdereferenceAppearGave'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_getdereferenceAppearGave(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_getdereferenceAppearGave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getdereferenceAppearGave();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getdereferenceAppearGave",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_getdereferenceAppearGave'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_impactDetermineAddedStay(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_impactDetermineAddedStay'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->impactDetermineAddedStay();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "impactDetermineAddedStay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_impactDetermineAddedStay'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_operandsAndquerySuited3(lua_State* tolua_S)
{
	int argc = 0;
	fieldComparesImprovements* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_operandsAndquerySuited3'", nullptr);
		return 0;
	}
#endif
	cobj->operandsAndquerySuited3(cobj);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_operandsAndquerySuited3'.",&tolua_err);
#endif
	return 0;
}
int fieldComparesImprovements_setContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_setContentOffset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_setContentOffset'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_getContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_getContentOffset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_getContentOffset'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_nameMacroDestroyed(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_nameMacroDestroyed'", nullptr);
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
        cobj->nameMacroDestroyed(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "nameMacroDestroyed",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_nameMacroDestroyed'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_settriggerScopingExecuting(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_settriggerScopingExecuting'", nullptr);
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
        cobj->settriggerScopingExecuting(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "settriggerScopingExecuting",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_settriggerScopingExecuting'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_hideAdditionNontype(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_hideAdditionNontype'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->hideAdditionNontype();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hideAdditionNontype",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_hideAdditionNontype'.",&tolua_err);
#endif
    return 0;
}
int fieldComparesImprovements_updateTweenAction(lua_State* tolua_S)
{
    int argc = 0;
    fieldComparesImprovements* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fieldComparesImprovements",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fieldComparesImprovements*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'fieldComparesImprovements_updateTweenAction'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'fieldComparesImprovements_updateTweenAction'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_fieldComparesImprovements_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fieldComparesImprovements");
	tolua_cclass(tolua_S, "fieldComparesImprovements", "fieldComparesImprovements", "cc.Layer", nullptr);
	tolua_beginmodule(tolua_S, "fieldComparesImprovements");
		tolua_constant(tolua_S, "HORIZONTAL", (int)fieldComparesImprovements::multiplyingTarget::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (int)fieldComparesImprovements::multiplyingTarget::VERTICAL);
		tolua_constant(tolua_S, "BOTH", (int)fieldComparesImprovements::multiplyingTarget::BOTH);
		tolua_function(tolua_S, "create", fieldComparesImprovements_create);
		tolua_function(tolua_S, "setmultiplyingTarget", fieldComparesImprovements_setmultiplyingTarget);
		tolua_function(tolua_S, "getmultiplyingTarget", fieldComparesImprovements_getmultiplyingTarget);
		tolua_function(tolua_S, "setdereferenceAppearGave", fieldComparesImprovements_setdereferenceAppearGave);
		tolua_function(tolua_S, "getdereferenceAppearGave", fieldComparesImprovements_getdereferenceAppearGave);
		tolua_function(tolua_S, "impactDetermineAddedStay", fieldComparesImprovements_impactDetermineAddedStay);
		tolua_function(tolua_S, "setContentOffset", fieldComparesImprovements_setContentOffset);
		tolua_function(tolua_S, "getContentOffset", fieldComparesImprovements_getContentOffset);
		tolua_function(tolua_S, "nameMacroDestroyed", fieldComparesImprovements_nameMacroDestroyed);
		tolua_function(tolua_S, "operandsAndquerySuited3", fieldComparesImprovements_operandsAndquerySuited3);
		tolua_function(tolua_S, "settriggerScopingExecuting", fieldComparesImprovements_settriggerScopingExecuting);
		tolua_function(tolua_S, "hideAdditionNontype", fieldComparesImprovements_hideAdditionNontype);
		tolua_function(tolua_S, "updateTweenAction", fieldComparesImprovements_updateTweenAction);
	tolua_endmodule(tolua_S);
	return 0;
}
