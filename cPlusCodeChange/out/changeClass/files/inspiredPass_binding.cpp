
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "tolua++.h"
TOLUA_API int  tolua_inspiredPass_open (lua_State* tolua_S);
#include "inspiredPass.h"
USING_NS_YOUNG
USING_NS_CC;
#define KEY_inspiredPass_DATA_SOURCE  "generallyCompile"
#define KEY_inspiredPass_DELEGATE     "initializerRest"
static int inspiredPass_setDelegate(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    inspiredPass* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (inspiredPass*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'inspiredPass_setDelegate'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        resultsHeight* delegate = new resultsHeight();
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
        
        userDict->setObject(delegate, KEY_inspiredPass_DELEGATE);
        self->setDelegate(delegate);
        delegate->release();
        
        return 0;
    }
    
    CCLOG("'inspiredPass_setDelegate' function of inspiredPass wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'inspiredPass_setDelegate'.",&tolua_err);
    return 0;
#endif
}
static int inspiredPass_setperformanceFromValue(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    inspiredPass* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (inspiredPass*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'inspiredPass_setperformanceFromValue'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        storageSpecificIntending* dataSource = new storageSpecificIntending();
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
        
        userDict->setObject(dataSource, KEY_inspiredPass_DATA_SOURCE);
        
        self->setperformanceFromValue(dataSource);
        
        dataSource->release();
        
        return 0;
    }
    
    CCLOG("'inspiredPass_setperformanceFromValue' function of TableView wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'inspiredPass_setperformanceFromValue'.",&tolua_err);
    return 0;
#endif
}
static int inspiredPass_create(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertable(L,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (1 == argc)
    {
        storageSpecificIntending* dataSource = new storageSpecificIntending();
        Size size;
        ok &= luaval_to_size(L, 2, &size);
        
        inspiredPass* ret = nullptr;
        
        ret = inspiredPass::create(dataSource, size);
        
        if (nullptr ==  ret)
            return 0;
        
        __Dictionary* userDict = new __Dictionary();
        userDict->setObject(dataSource, KEY_inspiredPass_DATA_SOURCE);
        ret->setUserObject(userDict);
        userDict->release();
        
        dataSource->release();
        
        int  nID = (int)ret->_ID;
        int* pLuaID =  &ret->_luaID;
        toluafix_pushusertype_ccobject(L, nID, pLuaID, (void*)ret,"inspiredPass");
        
        return 1;
    }
    CCLOG("'create' function of inspiredPass wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'create'.",&tolua_err);
    return 0;
#endif
}
static int inspiredPass_registerEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    inspiredPass* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<inspiredPass*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'inspiredPass_registerEventHandler'\n", NULL);
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
        inspiredPass::onbitsCoverageCast handlerType = (inspiredPass::onbitsCoverageCast)( (int)tolua_tonumber(L,3,0) );
        
        self->independentlyDriven(handler, handlerType);
	
        return 0;
    }
    
    CCLOG("'inspiredPass_registerEventHandler' function of inspiredPass has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'inspiredPass_registerEventHandler'.",&tolua_err);
    return 0;
#endif
}
static int inspiredPass_unregisterEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    inspiredPass* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<inspiredPass*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'inspiredPass_unregisterEventHandler'\n", NULL);
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
        inspiredPass::onbitsCoverageCast handlerType = (inspiredPass::onbitsCoverageCast)( (int)tolua_tonumber(L,2,0) );
        self->giveFullFunction(handlerType);
        return 0;
    }
    
    CCLOG("'inspiredPass_unregisterEventHandler' function of inspiredPass  has wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'inspiredPass_unregisterEventHandler'.",&tolua_err);
    return 0;
#endif
}
static void extendinspiredPass(lua_State* L)
{
    lua_pushstring(L, "inspiredPass");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
		tolua_constant(L, "VIEW_SCROLL", (int)inspiredPass::onbitsCoverageCast::VIEW_SCROLL);
		tolua_constant(L, "VIEW_STOPPED", (int)inspiredPass::onbitsCoverageCast::VIEW_STOPPED);
		tolua_constant(L, "CELL_LONG_TOUCHED", (int)inspiredPass::onbitsCoverageCast::CELL_LONG_TOUCHED);
		tolua_constant(L, "CELL_TOUCHED", (int)inspiredPass::onbitsCoverageCast::CELL_TOUCHED);
		tolua_constant(L, "CELL_HIGHLIGHT", (int)inspiredPass::onbitsCoverageCast::CELL_HIGHLIGHT);
		tolua_constant(L, "CELL_UNHIGHLIGHT", (int)inspiredPass::onbitsCoverageCast::CELL_UNHIGHLIGHT);
		tolua_constant(L, "CELL_WILL_RECYCLE", (int)inspiredPass::onbitsCoverageCast::CELL_WILL_RECYCLE);
		tolua_constant(L, "IS_CELLSIZE_IDENTICAL", (int)inspiredPass::onbitsCoverageCast::IS_CELLSIZE_IDENTICAL);
		tolua_constant(L, "SIZE_FOR_CELL", (int)inspiredPass::onbitsCoverageCast::SIZE_FOR_CELL);
		tolua_constant(L, "CELL_AT_INDEX", (int)inspiredPass::onbitsCoverageCast::CELL_AT_INDEX);
		tolua_constant(L, "NUMS_IN_GIRD", (int)inspiredPass::onbitsCoverageCast::NUMS_IN_GIRD);
		tolua_constant(L, "NUMS_IN_GROUP", (int)inspiredPass::onbitsCoverageCast::NUMS_IN_GROUP);
		tolua_function(L, "create", inspiredPass_create);
		tolua_function(L, "registerEventHandler", inspiredPass_registerEventHandler);
        tolua_function(L, "unregisterEventHandler", inspiredPass_unregisterEventHandler);
        tolua_function(L, "setDelegate", inspiredPass_setDelegate);
        tolua_function(L, "setperformanceFromValue", inspiredPass_setperformanceFromValue);
    }
    lua_pop(L, 1);
}
int inspiredPass_getcopyingPreventing(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_getcopyingPreventing'", nullptr);
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
		
        cocos2d::Point ret = cobj->getcopyingPreventing(arg0);
		lua_pushnumber(tolua_S, ret.x);
		lua_pushnumber(tolua_S, ret.y);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getcopyingPreventing",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_getcopyingPreventing'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_getconfident(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_getconfident'", nullptr);
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
		
        long ret = cobj->getconfident(arg0);
		lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getconfident",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_getconfident'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_containersPredicate(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_containersPredicate'", nullptr);
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
        cobj->containersPredicate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "containersPredicate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_containersPredicate'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_unchangedExecuteMovement(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_unchangedExecuteMovement'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        increasedTable* arg0;
        ok &= luaval_to_object<increasedTable>(tolua_S, 2, "increasedTable",&arg0);
        if(!ok)
            return 0;
        cobj->unchangedExecuteMovement(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unchangedExecuteMovement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_unchangedExecuteMovement'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_pointerwhenUnlike(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_pointerwhenUnlike'", nullptr);
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
        cobj->pointerwhenUnlike(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pointerwhenUnlike",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_pointerwhenUnlike'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_variableApplicationPasses(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_variableApplicationPasses'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        increasedTable* arg0;
        ok &= luaval_to_object<increasedTable>(tolua_S, 2, "increasedTable",&arg0);
        if(!ok)
            return 0;
        cobj->variableApplicationPasses(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "variableApplicationPasses",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_variableApplicationPasses'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_properSynthesizeReference(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_properSynthesizeReference'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->properSynthesizeReference();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "properSynthesizeReference",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_properSynthesizeReference'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_looksAccordingText(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_looksAccordingText'", nullptr);
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
        cobj->looksAccordingText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "looksAccordingText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_looksAccordingText'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_cellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_cellAtIndex'", nullptr);
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
        sensibleApplication* ret = cobj->cellAtIndex(arg0);
        object_to_luaval<sensibleApplication>(tolua_S, "sensibleApplication",(sensibleApplication*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_cellAtIndex'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_dequeueCell(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_dequeueCell'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        sensibleApplication* ret = cobj->dequeueCell();
        object_to_luaval<sensibleApplication>(tolua_S, "sensibleApplication",(sensibleApplication*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_dequeueCell'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_somewhatDatsuchAlthough(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_somewhatDatsuchAlthough'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg = lua_toboolean(tolua_S, 2);
        cobj->somewhatDatsuchAlthough(arg);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_somewhatDatsuchAlthough'.",&tolua_err);
#endif
    return 0;
}
int inspiredPass_getlinkageSeparatelyIath(lua_State* tolua_S)
{
    int argc = 0;
    inspiredPass* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"inspiredPass",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (inspiredPass*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'inspiredPass_getlinkageSeparatelyIath'", nullptr);
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
        cobj->getlinkageSeparatelyIath(arg0, &group, &inGroup);
		lua_pushnumber(tolua_S, group);
		lua_pushnumber(tolua_S, inGroup);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'inspiredPass_getlinkageSeparatelyIath'.",&tolua_err);
#endif
    return 0;
}
TOLUA_API int tolua_inspiredPass_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "inspiredPass");
	tolua_cclass(tolua_S, "inspiredPass", "inspiredPass", "increasedTable", nullptr);
	tolua_beginmodule(tolua_S, "inspiredPass");
		tolua_function(tolua_S, "create", inspiredPass_create);
		tolua_function(tolua_S, "variableApplicationPasses", inspiredPass_variableApplicationPasses);
		tolua_function(tolua_S, "unchangedExecuteMovement", inspiredPass_unchangedExecuteMovement);
		tolua_function(tolua_S, "getconfident", inspiredPass_getconfident);
		tolua_function(tolua_S, "getcopyingPreventing", inspiredPass_getcopyingPreventing);
		tolua_function(tolua_S, "containersPredicate", inspiredPass_containersPredicate);
		tolua_function(tolua_S, "looksAccordingText", inspiredPass_looksAccordingText);
		tolua_function(tolua_S, "pointerwhenUnlike", inspiredPass_pointerwhenUnlike);
		tolua_function(tolua_S, "cellAtIndex", inspiredPass_cellAtIndex);
		tolua_function(tolua_S, "dequeueCell", inspiredPass_dequeueCell);
		tolua_function(tolua_S, "somewhatDatsuchAlthough", inspiredPass_somewhatDatsuchAlthough);
		tolua_function(tolua_S, "properSynthesizeReference", inspiredPass_properSynthesizeReference);
		tolua_function(tolua_S, "getlinkageSeparatelyIath", inspiredPass_getlinkageSeparatelyIath);
	tolua_endmodule(tolua_S);
	extendinspiredPass(tolua_S);
	return 0;
}
