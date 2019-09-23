/*
** Lua binding: YGirdView
** Generated automatically by tolua++-1.0.92 on 04/10/14 04:29:48.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_YGirdView_open (lua_State* tolua_S);

#include "GUI/ScrollView/YGirdView.h"
USING_NS_YOUNG
USING_NS_CC;

#define KEY_YGirdView_DATA_SOURCE  "YGirdViewDataSource"
#define KEY_YGirdView_DELEGATE     "YGirdViewDelegate"

static int YGirdView_setDelegate(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    YGirdView* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (YGirdView*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'YGirdView_setDelegate'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        LUA_YGirdViewDelegate* delegate = new LUA_YGirdViewDelegate();
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
        
        userDict->setObject(delegate, KEY_YGirdView_DELEGATE);
        self->setDelegate(delegate);
        delegate->release();
        
        return 0;
    }
    
    CCLOG("'YGirdView_setDelegate' function of YGirdView wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'YGirdView_setDelegate'.",&tolua_err);
    return 0;
#endif
}

static int YGirdView_setDataSource(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    YGirdView* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(L,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = (YGirdView*)  tolua_tousertype(L,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (nullptr == self)
    {
        tolua_error(L,"invalid 'self' in function 'YGirdView_setDataSource'\n", nullptr);
		return 0;
    }
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (0 == argc)
    {
        LUA_YGirdViewDataSource* dataSource = new LUA_YGirdViewDataSource();
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
        
        userDict->setObject(dataSource, KEY_YGirdView_DATA_SOURCE);
        
        self->setDataSource(dataSource);
        
        dataSource->release();
        
        return 0;
    }
    
    CCLOG("'YGirdView_setDataSource' function of TableView wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'YGirdView_setDataSource'.",&tolua_err);
    return 0;
#endif
}


static int YGirdView_create(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = 0;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertable(L,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(L) - 1;
    
    if (1 == argc)
    {
        LUA_YGirdViewDataSource* dataSource = new LUA_YGirdViewDataSource();
        Size size;
        ok &= luaval_to_size(L, 2, &size);
        
        YGirdView* ret = nullptr;
        
        ret = YGirdView::create(dataSource, size);
        
        if (nullptr ==  ret)
            return 0;
        
        __Dictionary* userDict = new __Dictionary();
        userDict->setObject(dataSource, KEY_YGirdView_DATA_SOURCE);
        ret->setUserObject(userDict);
        userDict->release();
        
        dataSource->release();
        
        int  nID = (int)ret->_ID;
        int* pLuaID =  &ret->_luaID;
        toluafix_pushusertype_ccobject(L, nID, pLuaID, (void*)ret,"YGirdView");
        
        return 1;
    }
    CCLOG("'create' function of YGirdView wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'create'.",&tolua_err);
    return 0;
#endif
}

static int YGirdView_registerEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    YGirdView* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<YGirdView*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'YGirdView_registerEventHandler'\n", NULL);
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
        YGirdView::HandlerType handlerType = (YGirdView::HandlerType)( (int)tolua_tonumber(L,3,0) );
        
        self->addHandler(handler, handlerType);
		
        return 0;
    }
    
    CCLOG("'YGirdView_registerEventHandler' function of YGirdView has wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'YGirdView_registerEventHandler'.",&tolua_err);
    return 0;
#endif
}

static int YGirdView_unregisterEventHandler(lua_State* L)
{
    if (NULL == L)
        return 0;
    
    int argc = 0;
    YGirdView* self = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
	if (!tolua_isusertype(L,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif
    
    self = static_cast<YGirdView*>(tolua_tousertype(L,1,0));
    
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(L,"invalid 'self' in function 'YGirdView_unregisterEventHandler'\n", NULL);
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
        YGirdView::HandlerType handlerType = (YGirdView::HandlerType)( (int)tolua_tonumber(L,2,0) );
        self->removeHandler(handlerType);
        return 0;
    }
    
    CCLOG("'YGirdView_unregisterEventHandler' function of YGirdView  has wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'YGirdView_unregisterEventHandler'.",&tolua_err);
    return 0;
#endif
}

static void extendYGirdView(lua_State* L)
{
    lua_pushstring(L, "YGirdView");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
		tolua_constant(L, "VIEW_SCROLL", (int)YGirdView::HandlerType::VIEW_SCROLL);
		tolua_constant(L, "VIEW_STOPPED", (int)YGirdView::HandlerType::VIEW_STOPPED);
		tolua_constant(L, "CELL_LONG_TOUCHED", (int)YGirdView::HandlerType::CELL_LONG_TOUCHED);
		tolua_constant(L, "CELL_TOUCHED", (int)YGirdView::HandlerType::CELL_TOUCHED);
		tolua_constant(L, "CELL_HIGHLIGHT", (int)YGirdView::HandlerType::CELL_HIGHLIGHT);
		tolua_constant(L, "CELL_UNHIGHLIGHT", (int)YGirdView::HandlerType::CELL_UNHIGHLIGHT);
		tolua_constant(L, "CELL_WILL_RECYCLE", (int)YGirdView::HandlerType::CELL_WILL_RECYCLE);
		tolua_constant(L, "IS_CELLSIZE_IDENTICAL", (int)YGirdView::HandlerType::IS_CELLSIZE_IDENTICAL);
		tolua_constant(L, "SIZE_FOR_CELL", (int)YGirdView::HandlerType::SIZE_FOR_CELL);
		tolua_constant(L, "CELL_AT_INDEX", (int)YGirdView::HandlerType::CELL_AT_INDEX);
		tolua_constant(L, "NUMS_IN_GIRD", (int)YGirdView::HandlerType::NUMS_IN_GIRD);
		tolua_constant(L, "NUMS_IN_GROUP", (int)YGirdView::HandlerType::NUMS_IN_GROUP);
		tolua_function(L, "create", YGirdView_create);
		tolua_function(L, "registerEventHandler", YGirdView_registerEventHandler);
        tolua_function(L, "unregisterEventHandler", YGirdView_unregisterEventHandler);
        tolua_function(L, "setDelegate", YGirdView_setDelegate);
        tolua_function(L, "setDataSource", YGirdView_setDataSource);
    }
    lua_pop(L, 1);
}

/******************************************************************************************************************************/
int YGirdView_getPositionFromIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_getPositionFromIndex'", nullptr);
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
			
        cocos2d::Point ret = cobj->getPositionFromIndex(arg0);
		lua_pushnumber(tolua_S, ret.x);
		lua_pushnumber(tolua_S, ret.y);
        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPositionFromIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_getPositionFromIndex'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_getIndexFromPoint(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_getIndexFromPoint'", nullptr);
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
			
        long ret = cobj->getIndexFromPoint(arg0);
		lua_pushnumber(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIndexFromPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_getIndexFromPoint'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_updateCellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_updateCellAtIndex'", nullptr);
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
        cobj->updateCellAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateCellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_updateCellAtIndex'.",&tolua_err);
#endif

    return 0;
}


int YGirdView_scrollViewDidZoom(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_scrollViewDidZoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YScrollView* arg0;

        ok &= luaval_to_object<YScrollView>(tolua_S, 2, "YScrollView",&arg0);
        if(!ok)
            return 0;
        cobj->scrollViewDidZoom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollViewDidZoom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_scrollViewDidZoom'.",&tolua_err);
#endif

    return 0;
}



int YGirdView_removeCellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_removeCellAtIndex'", nullptr);
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
        cobj->removeCellAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeCellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_removeCellAtIndex'.",&tolua_err);
#endif

    return 0;
}


int YGirdView_scrollViewDidScroll(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_scrollViewDidScroll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        YScrollView* arg0;

        ok &= luaval_to_object<YScrollView>(tolua_S, 2, "YScrollView",&arg0);
        if(!ok)
            return 0;
        cobj->scrollViewDidScroll(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollViewDidScroll",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_scrollViewDidScroll'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_reloadData'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_insertCellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_insertCellAtIndex'", nullptr);
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
        cobj->insertCellAtIndex(arg0);
        return 0;
    }
	
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertCellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_insertCellAtIndex'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_cellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_cellAtIndex'", nullptr);
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
        YGirdViewCell* ret = cobj->cellAtIndex(arg0);
        object_to_luaval<YGirdViewCell>(tolua_S, "YGirdViewCell",(YGirdViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_cellAtIndex'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_dequeueCell(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_dequeueCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        YGirdViewCell* ret = cobj->dequeueCell();
        object_to_luaval<YGirdViewCell>(tolua_S, "YGirdViewCell",(YGirdViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_dequeueCell'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_viewSizeSelfAdaption(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_viewSizeSelfAdaption'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg = lua_toboolean(tolua_S, 2);
        cobj->viewSizeSelfAdaption(arg);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_viewSizeSelfAdaption'.",&tolua_err);
#endif

    return 0;
}

int YGirdView_getGroupAndInGroupFromIndex(lua_State* tolua_S)
{
    int argc = 0;
    YGirdView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"YGirdView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (YGirdView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'YGirdView_getGroupAndInGroupFromIndex'", nullptr);
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
        cobj->getGroupAndInGroupFromIndex(arg0, &group, &inGroup);
		lua_pushnumber(tolua_S, group);
		lua_pushnumber(tolua_S, inGroup);

        return 2;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'YGirdView_getGroupAndInGroupFromIndex'.",&tolua_err);
#endif

    return 0;
}

/* Open function */
TOLUA_API int tolua_YGirdView_open (lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "YGirdView");
	tolua_cclass(tolua_S, "YGirdView", "YGirdView", "YScrollView", nullptr);
	
	tolua_beginmodule(tolua_S, "YGirdView");
		tolua_function(tolua_S, "create", YGirdView_create);
		tolua_function(tolua_S, "scrollViewDidScroll", YGirdView_scrollViewDidScroll);
		tolua_function(tolua_S, "scrollViewDidZoom", YGirdView_scrollViewDidZoom);
		tolua_function(tolua_S, "getIndexFromPoint", YGirdView_getIndexFromPoint);
		tolua_function(tolua_S, "getPositionFromIndex", YGirdView_getPositionFromIndex);
		tolua_function(tolua_S, "updateCellAtIndex", YGirdView_updateCellAtIndex);
		tolua_function(tolua_S, "insertCellAtIndex", YGirdView_insertCellAtIndex);
		tolua_function(tolua_S, "removeCellAtIndex", YGirdView_removeCellAtIndex);
		tolua_function(tolua_S, "cellAtIndex", YGirdView_cellAtIndex);
		tolua_function(tolua_S, "dequeueCell", YGirdView_dequeueCell);
		tolua_function(tolua_S, "viewSizeSelfAdaption", YGirdView_viewSizeSelfAdaption);
		tolua_function(tolua_S, "reloadData", YGirdView_reloadData);
		tolua_function(tolua_S, "getGroupAndInGroupFromIndex", YGirdView_getGroupAndInGroupFromIndex);
	tolua_endmodule(tolua_S);
	
	extendYGirdView(tolua_S);
	
	return 0;
}

