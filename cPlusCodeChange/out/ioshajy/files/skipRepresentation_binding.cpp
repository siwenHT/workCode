
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
TOLUA_API int  tolua_skipRepresentation_open (lua_State* tolua_S);
#include "skipRepresentation.h"
USING_NS_YOUNG
USING_NS_CC;
#define KEY_skipRepresentation_DATA_SOURCE  "allowContrpassesExplain"
#define KEY_skipRepresentation_DELEGATE     "strblobConstexprAlthough"
static int skipRepresentation_setDelegate(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    skipRepresentation* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (skipRepresentation*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'skipRepresentation_setDelegate'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        promotedAlternatively* delegate = new promotedAlternatively();
        if (nullptr == delegate)
            return 0;
        
        __Dictionary* userDict = static_cast<__Dictionary*>(self->getUserObject());
        if (nullptr == userDict)
        {
            userDict = new __Dictionary();
            if (NULL == userDict)
                return 0;
            
            self->setUserObject(userDict);
            userDict->release();
        }
        
        userDict->setObject(delegate, KEY_skipRepresentation_DELEGATE);
        self->setDelegate(delegate);
        delegate->release();
        
        return 0;
    }
    
    CCLOG("'skipRepresentation_setDelegate' function of skipRepresentation wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'skipRepresentation_setDelegate'.",&tolua_err);
    return 0;
#endif
}
static int skipRepresentation_setspellingControlEnforce(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    skipRepresentation* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (skipRepresentation*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'skipRepresentation_setspellingControlEnforce'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        occasionallyPrvoid* dataSource = new occasionallyPrvoid();
        if (nullptr == dataSource)
            return 0;
        
        __Dictionary* userDict = static_cast<__Dictionary*>(self->getUserObject());
        if (nullptr == userDict)
        {
            userDict = new __Dictionary();
            if (NULL == userDict)
                return 0;
            
            self->setUserObject(userDict);
            userDict->release();
        }
        
        userDict->setObject(dataSource, KEY_skipRepresentation_DATA_SOURCE);
        
        self->setspellingControlEnforce(dataSource);
        
        dataSource->release();
        
        return 0;
    }
    
    CCLOG("'skipRepresentation_setspellingControlEnforce' function of TableView wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'skipRepresentation_setspellingControlEnforce'.",&tolua_err);
    return 0;
#endif
}
static int skipRepresentation_create(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertable(L,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (1 == argc)
    {
        occasionallyPrvoid* dataSource = new occasionallyPrvoid();
        Size size;
        ok &= luaval_to_size(L, 2, &size);
        
        skipRepresentation* ret = nullptr;
        
        ret = skipRepresentation::create(dataSource, size);
        
        if (nullptr ==  ret)
            return 0;
        
        __Dictionary* userDict = new __Dictionary();
        userDict->setObject(dataSource, KEY_skipRepresentation_DATA_SOURCE);
        ret->setUserObject(userDict);
        userDict->release();
        
        dataSource->release();
        
        int  nID = (int)ret->_ID;
        int* pLuaID =  &ret->_luaID;
        toluafix_pushusertype_ccobject(L, nID, pLuaID, (void*)ret,"skipRepresentation");
        
        return 1;
    }
    CCLOG("'create' function of skipRepresentation wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'create'.",&tolua_err);
    return 0;
#endif
}
static int skipRepresentation_registerEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    skipRepresentation* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<skipRepresentation*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'skipRepresentation_registerEventHandler'\n", NULL);
		return 0;
	}
#endif
    argc = lua_gettop(L) - 1;
    if (2 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if ( !toluafix_isfunction(L,2,"LUA_FUNCTION",0,&tolua_err) ||
             !tolua_isnumber(L, 3, 0, &tolua_err) )
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(L,2,0));
        skipRepresentation::stoppincondition handlerType = (skipRepresentation::stoppincondition)( (int)tolua_tonumber(L,3,0) );
        
        self->arraysGiveVerifies5(handler, handlerType);
	
        return 0;
    }
    
    CCLOG("'skipRepresentation_registerEventHandler' function of skipRepresentation has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'skipRepresentation_registerEventHandler'.",&tolua_err);
    return 0;
#endif
}
static int skipRepresentation_unregisterEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    skipRepresentation* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<skipRepresentation*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'skipRepresentation_unregisterEventHandler'\n", NULL);
		return 0;
	}
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(L, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        skipRepresentation::stoppincondition handlerType = (skipRepresentation::stoppincondition)( (int)tolua_tonumber(L,2,0) );
        self->opposedExternfifth(handlerType);
        return 0;
    }
    
    CCLOG("'skipRepresentation_unregisterEventHandler' function of skipRepresentation  has wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'skipRepresentation_unregisterEventHandler'.",&tolua_err);
    return 0;
#endif
}
static void extendskipRepresentation(lua_State* L)
{
    lua_pushstring(L, "skipRepresentation");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
		tolua_constant(L, "VIEW_SCROLL", (int)skipRepresentation::stoppincondition::VIEW_SCROLL);
		tolua_constant(L, "VIEW_STOPPED", (int)skipRepresentation::stoppincondition::VIEW_STOPPED);
		tolua_constant(L, "CELL_LONG_TOUCHED", (int)skipRepresentation::stoppincondition::CELL_LONG_TOUCHED);
		tolua_constant(L, "CELL_TOUCHED", (int)skipRepresentation::stoppincondition::CELL_TOUCHED);
		tolua_constant(L, "CELL_HIGHLIGHT", (int)skipRepresentation::stoppincondition::CELL_HIGHLIGHT);
		tolua_constant(L, "CELL_UNHIGHLIGHT", (int)skipRepresentation::stoppincondition::CELL_UNHIGHLIGHT);
		tolua_constant(L, "CELL_WILL_RECYCLE", (int)skipRepresentation::stoppincondition::CELL_WILL_RECYCLE);
		tolua_constant(L, "IS_CELLSIZE_IDENTICAL", (int)skipRepresentation::stoppincondition::IS_CELLSIZE_IDENTICAL);
		tolua_constant(L, "SIZE_FOR_CELL", (int)skipRepresentation::stoppincondition::SIZE_FOR_CELL);
		tolua_constant(L, "CELL_AT_INDEX", (int)skipRepresentation::stoppincondition::CELL_AT_INDEX);
		tolua_constant(L, "NUMS_IN_GIRD", (int)skipRepresentation::stoppincondition::NUMS_IN_GIRD);
		tolua_constant(L, "NUMS_IN_GROUP", (int)skipRepresentation::stoppincondition::NUMS_IN_GROUP);
		tolua_function(L, "create", skipRepresentation_create);
		tolua_function(L, "registerEventHandler", skipRepresentation_registerEventHandler);
        tolua_function(L, "unregisterEventHandler", skipRepresentation_unregisterEventHandler);
        tolua_function(L, "setDelegate", skipRepresentation_setDelegate);
        tolua_function(L, "setspellingControlEnforce", skipRepresentation_setspellingControlEnforce);
    }
    lua_pop(L, 1);
}
int skipRepresentation_getwordTildeNest(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_getwordTildeNest'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
		
        cocos2d::Point ret = cobj->getwordTildeNest(arg0);
		lua_pushnumber(tolua_S, ret.x);
		lua_pushnumber(tolua_S, ret.y);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getwordTildeNest",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_getwordTildeNest'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_getstreamViolations(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_getstreamViolations'", nullptr);
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
		
        long ret = cobj->getstreamViolations(arg0);
		lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getstreamViolations",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_getstreamViolations'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_failAheadRemain(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_failAheadRemain'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->failAheadRemain(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "failAheadRemain",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_failAheadRemain'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_preferredThereRemains(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_preferredThereRemains'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fieldComparesImprovements* arg0;
        ok &= luaval_to_object<fieldComparesImprovements>(tolua_S, 2, "fieldComparesImprovements",&arg0);
        if(!ok)
            return 0;
        cobj->preferredThereRemains(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preferredThereRemains",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_preferredThereRemains'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_respectiveTellChose(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_respectiveTellChose'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->respectiveTellChose(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "respectiveTellChose",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_respectiveTellChose'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_namingVariousCccccccccc2(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_namingVariousCccccccccc2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fieldComparesImprovements* arg0;
        ok &= luaval_to_object<fieldComparesImprovements>(tolua_S, 2, "fieldComparesImprovements",&arg0);
        if(!ok)
            return 0;
        cobj->namingVariousCccccccccc2(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "namingVariousCccccccccc2",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_namingVariousCccccccccc2'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_replacedInlinedTechniques(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_replacedInlinedTechniques'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->replacedInlinedTechniques();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "replacedInlinedTechniques",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_replacedInlinedTechniques'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_meanLeaveChartyp3(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_meanLeaveChartyp3'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->meanLeaveChartyp3(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "meanLeaveChartyp3",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_meanLeaveChartyp3'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_cellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_cellAtIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        abstractNines* ret = cobj->cellAtIndex(arg0);
        object_to_luaval<abstractNines>(tolua_S, "abstractNines",(abstractNines*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_cellAtIndex'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_dequeueCell(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_dequeueCell'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        abstractNines* ret = cobj->dequeueCell();
        object_to_luaval<abstractNines>(tolua_S, "abstractNines",(abstractNines*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_dequeueCell'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_forwardingDescribesUnder(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_forwardingDescribesUnder'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg = lua_toboolean(tolua_S, 2);
        cobj->forwardingDescribesUnder(arg);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_forwardingDescribesUnder'.",&tolua_err);
#endif
    return 0;
}
int skipRepresentation_getspecifiedPassHandling(lua_State* tolua_S)
{
    int argc = 0;
    skipRepresentation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"skipRepresentation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (skipRepresentation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'skipRepresentation_getspecifiedPassHandling'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ssize_t arg0;
        ok &= luaval_to_ssize(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
	
		int group, inGroup;
        cobj->getspecifiedPassHandling(arg0, &group, &inGroup);
		lua_pushnumber(tolua_S, group);
		lua_pushnumber(tolua_S, inGroup);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'skipRepresentation_getspecifiedPassHandling'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_skipRepresentation_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "skipRepresentation");
	tolua_cclass(tolua_S, "skipRepresentation", "skipRepresentation", "fieldComparesImprovements", nullptr);
	tolua_beginmodule(tolua_S, "skipRepresentation");
		tolua_function(tolua_S, "create", skipRepresentation_create);
		tolua_function(tolua_S, "namingVariousCccccccccc2", skipRepresentation_namingVariousCccccccccc2);
		tolua_function(tolua_S, "preferredThereRemains", skipRepresentation_preferredThereRemains);
		tolua_function(tolua_S, "getstreamViolations", skipRepresentation_getstreamViolations);
		tolua_function(tolua_S, "getwordTildeNest", skipRepresentation_getwordTildeNest);
		tolua_function(tolua_S, "failAheadRemain", skipRepresentation_failAheadRemain);
		tolua_function(tolua_S, "meanLeaveChartyp3", skipRepresentation_meanLeaveChartyp3);
		tolua_function(tolua_S, "respectiveTellChose", skipRepresentation_respectiveTellChose);
		tolua_function(tolua_S, "cellAtIndex", skipRepresentation_cellAtIndex);
		tolua_function(tolua_S, "dequeueCell", skipRepresentation_dequeueCell);
		tolua_function(tolua_S, "forwardingDescribesUnder", skipRepresentation_forwardingDescribesUnder);
		tolua_function(tolua_S, "replacedInlinedTechniques", skipRepresentation_replacedInlinedTechniques);
		tolua_function(tolua_S, "getspecifiedPassHandling", skipRepresentation_getspecifiedPassHandling);
	tolua_endmodule(tolua_S);
	extendskipRepresentation(tolua_S);
	return 0;
}
