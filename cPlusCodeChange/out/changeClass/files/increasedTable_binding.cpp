
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
TOLUA_API int  tolua_increasedTable_open (lua_State* tolua_S);
#include "increasedTable.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
USING_NS_YOUNG
static int increasedTable_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
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
            increasedTable* ret = increasedTable::create(arg0);
            object_to_luaval<increasedTable>(tolua_S, "increasedTable",(increasedTable*)ret);
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
            increasedTable* ret = increasedTable::create(arg0, arg1);
            object_to_luaval<increasedTable>(tolua_S, "increasedTable",(increasedTable*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_create'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_setimageUndefinedElsewhere(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_setimageUndefinedElsewhere'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        increasedTable::imageUndefinedElsewhere arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setimageUndefinedElsewhere(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setimageUndefinedElsewhere",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_setimageUndefinedElsewhere'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_getimageUndefinedElsewhere(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_getimageUndefinedElsewhere'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getimageUndefinedElsewhere();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getimageUndefinedElsewhere",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_getimageUndefinedElsewhere'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_setinspiredAccessible(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_setinspiredAccessible'", nullptr);
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
        cobj->setinspiredAccessible(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setinspiredAccessible",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_setinspiredAccessible'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_getinspiredAccessible(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_getinspiredAccessible'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getinspiredAccessible();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getinspiredAccessible",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_getinspiredAccessible'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_expressionExceptInlined(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_expressionExceptInlined'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->expressionExceptInlined();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "expressionExceptInlined",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_expressionExceptInlined'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_findProgramsAssigning(lua_State* tolua_S)
{
	int argc = 0;
	increasedTable* cobj = nullptr;
	bool ok  = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
	cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_findProgramsAssigning'", nullptr);
		return 0;
	}
#endif
	cobj->findProgramsAssigning(cobj);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'increasedTable_findProgramsAssigning'.",&tolua_err);
#endif
	return 0;
}
int increasedTable_setContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_setContentOffset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'increasedTable_setContentOffset'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_getContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_getContentOffset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'increasedTable_getContentOffset'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_accessedIncrementally(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_accessedIncrementally'", nullptr);
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
        cobj->accessedIncrementally(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "accessedIncrementally",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_accessedIncrementally'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_setpriceOtherGrades(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_setpriceOtherGrades'", nullptr);
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
        cobj->setpriceOtherGrades(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setpriceOtherGrades",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_setpriceOtherGrades'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_solveIndexingTreat(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_solveIndexingTreat'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->solveIndexingTreat();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "solveIndexingTreat",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'increasedTable_solveIndexingTreat'.",&tolua_err);
#endif
    return 0;
}
int increasedTable_updateTweenAction(lua_State* tolua_S)
{
    int argc = 0;
    increasedTable* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"increasedTable",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (increasedTable*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'increasedTable_updateTweenAction'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'increasedTable_updateTweenAction'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_increasedTable_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "increasedTable");
	tolua_cclass(tolua_S, "increasedTable", "increasedTable", "cc.Layer", nullptr);
	tolua_beginmodule(tolua_S, "increasedTable");
		tolua_constant(tolua_S, "HORIZONTAL", (int)increasedTable::imageUndefinedElsewhere::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (int)increasedTable::imageUndefinedElsewhere::VERTICAL);
		tolua_constant(tolua_S, "BOTH", (int)increasedTable::imageUndefinedElsewhere::BOTH);
		tolua_function(tolua_S, "create", increasedTable_create);
		tolua_function(tolua_S, "setimageUndefinedElsewhere", increasedTable_setimageUndefinedElsewhere);
		tolua_function(tolua_S, "getimageUndefinedElsewhere", increasedTable_getimageUndefinedElsewhere);
		tolua_function(tolua_S, "setinspiredAccessible", increasedTable_setinspiredAccessible);
		tolua_function(tolua_S, "getinspiredAccessible", increasedTable_getinspiredAccessible);
		tolua_function(tolua_S, "expressionExceptInlined", increasedTable_expressionExceptInlined);
		tolua_function(tolua_S, "setContentOffset", increasedTable_setContentOffset);
		tolua_function(tolua_S, "getContentOffset", increasedTable_getContentOffset);
		tolua_function(tolua_S, "accessedIncrementally", increasedTable_accessedIncrementally);
		tolua_function(tolua_S, "findProgramsAssigning", increasedTable_findProgramsAssigning);
		tolua_function(tolua_S, "setpriceOtherGrades", increasedTable_setpriceOtherGrades);
		tolua_function(tolua_S, "solveIndexingTreat", increasedTable_solveIndexingTreat);
		tolua_function(tolua_S, "updateTweenAction", increasedTable_updateTweenAction);
	tolua_endmodule(tolua_S);
	return 0;
}
