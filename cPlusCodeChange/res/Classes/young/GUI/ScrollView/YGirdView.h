#ifndef __YGirdView_H__
#define __YGirdView_H__

#include "common/Ycommon.h"
#include "cocos2d.h"
#include "YScrollView.h"
#include "YGirdViewCell.h"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"
#include <algorithm>
#include <functional>

NS_YOUNG_BEGIN

class YGirdView;

/**
 * Sole purpose of this delegate is to single touch event in this version.
 */
class YGirdViewDelegate : public YScrollViewDelegate
{
public:
    /**
     * Delegate to respond touch event
     *
     * @param gird gird contains the given cell
     * @param cell  cell that is touched
     */
    virtual void girdCellTouched(YGirdView *gird, YGirdViewCell *cell) = 0;
	
	// 长按事件
	virtual void girdCellLongTouched(YGirdView* gird, YGirdViewCell* cell) {};

    /**
     * Delegate to respond a table cell press event.
     *
     * @param gird gird contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void girdCellHighlight(YGirdView *gird, YGirdViewCell *cell) {};

    /**
     * Delegate to respond a table cell release event
     *
     * @param gird gird contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void girdCellUnhighlight(YGirdView *gird, YGirdViewCell *cell) {};

    /**
     * Delegate called when the cell is about to be recycled. Immediately
     * after this call the cell will be removed from the scene graph and
     * recycled.
     *
     * @param gird gird contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void girdCellWillRecycle(YGirdView *gird, YGirdViewCell *cell) {};

};




/**
 * Data source that governs gird backend data.
 */
class YGirdViewDataSource
{
public:
	
    virtual ~YGirdViewDataSource() {}

    /**
     * cell size for a given index
     *
     * @param idx the index of a cell to get a size
     * @return size of a cell at given index
     */
    virtual cocos2d::Size girdCellSizeForIndex(YGirdView *gird, ssize_t idx) = 0;
	
	virtual bool cellSizeIdentical(YGirdView *gird) { return false; }
    
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual YGirdViewCell *girdCellAtIndex(YGirdView *gird, ssize_t idx) = 0;
    /**
     * Returns number of cells in a given gird view.
     *
     * @return number of cells
     */
    virtual ssize_t numberOfCellsInGirdView(YGirdView *gird) = 0;

    /**
     * Returns number of cells in a given gird's group.
     *
     * @return number of cells
     */
    virtual ssize_t numberOfCellsInGroup(YGirdView *gird) = 0;
};


class YGirdView : public YScrollView, public YScrollViewDelegate
{
public:
	enum class HandlerType: int
	{
		NODE = 0,
		VIEW_SCROLL,
		VIEW_STOPPED,
		CELL_LONG_TOUCHED,
        CELL_TOUCHED,
        CELL_HIGHLIGHT,
        CELL_UNHIGHLIGHT,
        CELL_WILL_RECYCLE,
		IS_CELLSIZE_IDENTICAL,
        SIZE_FOR_CELL,
        CELL_AT_INDEX,
        NUMS_IN_GIRD,
		NUMS_IN_GROUP,
		EVENT_NUMS,
	};
	
	typedef int Handler;
    typedef std::map<HandlerType, Handler> HandlerMap;
	
	inline void addHandler(int handler, HandlerType handlerType)
	{
		this->removeHandler(handlerType);
		if(handler)
			_handlers[handlerType] = handler;
	}
	
    inline void removeHandler(HandlerType handlerType)
	{
		auto iterMap = _handlers.find(handlerType);
		if (_handlers.end() != iterMap)
		{
			if(iterMap->second)
				cocos2d::LuaEngine::getInstance()->removeScriptHandler(iterMap->second);
			
			_handlers.erase(iterMap);
		}
	}
	
    inline int getHandler(HandlerType handlerType)
	{
		auto iterMap = _handlers.find(handlerType);
		if (_handlers.end() != iterMap)
			return iterMap->second;
		else
			return 0;
	}
	
    inline void removeAllHandlers()
	{
		auto iterMap = _handlers.begin();
		for(; iterMap != _handlers.end(); ++iterMap)
		{
			if(iterMap->second)
				cocos2d::LuaEngine::getInstance()->removeScriptHandler(iterMap->second);
		}
		
		_handlers.clear();
	}
	
public:
    YGirdView();
   
    virtual ~YGirdView();

    static YGirdView *create(YGirdViewDataSource *dataSource, cocos2d::Size size);
    bool initWithDataSource(YGirdViewDataSource *dataSource, cocos2d::Size size);

    void setDelegate(YGirdViewDelegate *pDelegate) { _girdViewDelegate = pDelegate; }
    YGirdViewDelegate *getDelegate() { return _girdViewDelegate; }

    void setDataSource(YGirdViewDataSource *source) { _dataSource = source; }
    YGirdViewDataSource *getDataSource() { return _dataSource; }


    int getIndexFromGroupAndInGroup(int group, int inGroup)
	{
		return group * _cellsInGroup + inGroup;
	}

	void getGroupAndInGroupFromIndex(int index, int *group, int *inGroup)
	{
		*group = index / _cellsInGroup;
    	*inGroup = index % _cellsInGroup;
	}

	int inGroupCount(int group)
	{
		int cellsCount = _dataSource->numberOfCellsInGirdView(this);
		if(cellsCount < 1) return 0;
		
    	int idx = getIndexFromGroupAndInGroup(group, 0);
		return _cellsInGroup < (cellsCount - idx) ? _cellsInGroup : (cellsCount - idx);
	}
	
	long getIndexFromPoint(cocos2d::Point point);
	cocos2d::Point getPositionFromIndex(ssize_t index)
	{
		assert( index >= 0 && index < _dataSource->numberOfCellsInGirdView(this) );
		return _vCellsPositions[index];
	}
	
	void viewSizeSelfAdaption(bool value)
	{
		_selfAdaption = value;
	}

    // Overrides
    virtual void scrollViewDidScroll(YScrollView *view) override;
    virtual void scrollViewDidZoom(YScrollView *view) override {}
	virtual void scrollViewDidStopped(YScrollView *view) override
	{
		if(_girdViewDelegate) _girdViewDelegate->scrollViewDidStopped(this);
	}

    virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) override;
    virtual void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) override;
    virtual void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) override;
    virtual void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) override;

    /**
     * Updates the content of the cell at a given index.
     *
     * @param idx index to find a cell
     */
    void updateCellAtIndex(ssize_t idx);

    /**
     * Inserts a new cell at a given index
     *
     * @param idx location to insert
     */
    void insertCellAtIndex(ssize_t idx);
    /**
     * Removes a cell at a given index
     *
     * @param idx index to find a cell
     */
    void removeCellAtIndex(ssize_t idx);

    /**
     * Returns an existing cell at a given index. Returns nil if a cell is nonexistent at the moment of query.
     *
     * @param idx index
     * @return a cell at a given index
     */
    YGirdViewCell *cellAtIndex(ssize_t idx);

    /**
     * Dequeues a free cell if available. nil if not.
     *
     * @return free cell
     */
    YGirdViewCell *dequeueCell();

    /**
     * reloads data from data source.  the view will be refreshed.
     */
    void reloadData();

protected:
	void updateTouch(float dt); // 长按定时器
	
	inline int groupCount()
	{
		long cellsCount = _dataSource->numberOfCellsInGirdView(this);
		return (cellsCount + _cellsInGroup - 1) / _cellsInGroup;
	}
	
	inline cocos2d::Size girdCellSizeForIndex(YGirdView *gird, ssize_t idx)
	{
		if(_cellSizeIdentical) return _cellSize;
		else return _dataSource->girdCellSizeForIndex(gird, idx);
	}

	void _updateCellPositions();
	void _updateContentSize();

    long _indexFromOffset(cocos2d::Point offset);
    long __indexFromOffset(cocos2d::Point offset);
    long _indexFromOffsetInGroup(cocos2d::Point offset, int group);

    void _moveCellOutOfSight(YGirdViewCell *cell);
    void _setIndexForCell(ssize_t index, YGirdViewCell *cell);
    void _addCellIfNecessary(YGirdViewCell * cell);

protected:
	YGirdViewDataSource *_dataSource;

	YGirdViewDelegate *_girdViewDelegate;

	YGirdViewCell *_touchedCell;

	/**
     * index set to query the indexes of the cells used.
     */
    std::set<ssize_t> *_indices;

    /**
     * vector with all cell positions
     */
    std::vector<cocos2d::Point> _vCellsPositions;

    /**
     * cells that are currently in the gird
     */
    cocos2d::Vector<YGirdViewCell *> _cellsUsed;

    /**
     * free list of cells
     */
    cocos2d::Vector<YGirdViewCell *> _cellsFreed;

    /**
     * number of cells in a group.
     */
    ssize_t _cellsInGroup;
	
	bool _cellSizeIdentical;
	cocos2d::Size _cellSize;
	
	bool _selfAdaption;

    bool _isUsedCellsDirty;
	
	HandlerMap _handlers;

};

class LUA_YGirdViewDelegate : public cocos2d::Ref, public YGirdViewDelegate
{
public:
    LUA_YGirdViewDelegate() {}
    
    virtual ~LUA_YGirdViewDelegate() {}
    
    
    virtual void scrollViewDidScroll(YScrollView* gird) override
    {
        this->aux( (YGirdView *)gird, YGirdView::HandlerType::VIEW_SCROLL );
    }
    
    virtual void scrollViewDidZoom(YScrollView* gird) override
    {
        //
    }
	
	virtual void scrollViewDidStopped(YScrollView *gird) override
	{
		this->aux( (YGirdView *)gird, YGirdView::HandlerType::VIEW_STOPPED );
	}
	
	virtual void girdCellLongTouched(YGirdView* gird, YGirdViewCell* cell) override
    {
        this->aux(gird, YGirdView::HandlerType::CELL_LONG_TOUCHED, cell);
    }
    
    virtual void girdCellTouched(YGirdView* gird, YGirdViewCell* cell) override
    {
        this->aux(gird, YGirdView::HandlerType::CELL_TOUCHED, cell);
    }
    
    virtual void girdCellHighlight(YGirdView* gird, YGirdViewCell* cell) override
    {
        this->aux(gird, YGirdView::HandlerType::CELL_HIGHLIGHT, cell);
    }
    
    virtual void girdCellUnhighlight(YGirdView* gird, YGirdViewCell* cell) override
    {
        this->aux(gird, YGirdView::HandlerType::CELL_UNHIGHLIGHT, cell);
    }
    
    virtual void girdCellWillRecycle(YGirdView* gird, YGirdViewCell* cell) override
    {
        this->aux(gird, YGirdView::HandlerType::CELL_WILL_RECYCLE, cell);
    }
private:
	void aux(YGirdView* gird, YGirdView::HandlerType handlerType, YGirdViewCell* cell = nullptr)
    {
		if (nullptr != gird)
        {
            int handler = gird->getHandler(handlerType);
            if (0 != handler)
            {
                cocos2d::LuaStack *pStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				if(nullptr != cell)
					toluafix_pushusertype_ccobject(L, cell->_ID, &(cell->_luaID), (void*)(cell), "YGirdViewCell");
				
				pStack->executeFunctionByHandler(handler, cell ? 2 : 1);
				
				pStack->clean();
            }
        }
    }
};

class LUA_YGirdViewDataSource : public cocos2d::Ref, public YGirdViewDataSource
{
public:
    LUA_YGirdViewDataSource() {}
    virtual ~LUA_YGirdViewDataSource() {}
    
	virtual cocos2d::Size girdCellSizeForIndex(YGirdView *gird, ssize_t idx) override
	{
		if (nullptr != gird)
		{
			int handler = gird->getHandler(YGirdView::HandlerType::SIZE_FOR_CELL);
			if (0 != handler)
			{
				float width = 0.0;
                float height = 0.0;
				cocos2d::LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				lua_pushnumber(L, idx);
				int ret = pStack->executeFunction(handler, 2, 2, [&](lua_State* L, int numReturn)
				{
                    CCASSERT(numReturn == 2, "cellSizeForGird return count error");
                    height  = (float)tolua_tonumber(L, -1, 0);
                    lua_pop(L, 1);
                    width = (float)tolua_tonumber(L, -1, 0);
                    lua_pop(L, 1);
                });
				pStack->clean();
				
				return cocos2d::Size(width, height);
			}
		}
		
		return Size::ZERO;
	}
	
	virtual bool cellSizeIdentical(YGirdView *gird) override
	{
		if (nullptr != gird)
		{
			int handler = gird->getHandler(YGirdView::HandlerType::IS_CELLSIZE_IDENTICAL);
			if (0 != handler)
			{
				bool identical = false;
				cocos2d::LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				int ret = pStack->executeFunction(handler, 1, 1, [&](lua_State* L, int numReturn)
				{
                    CCASSERT(numReturn == 1, "cellSizeForGird return count error");
                    identical  = (lua_toboolean(L, -1)) >0?true:false;
                    lua_pop(L, 1);
                });
				pStack->clean();
				
				return identical;
			}
		}
		
		return false;
	}
    
    virtual YGirdViewCell* girdCellAtIndex(YGirdView *gird, ssize_t idx) override
    {
        if (nullptr != gird)
        {
            int handler = gird->getHandler(YGirdView::HandlerType::CELL_AT_INDEX);
            if (0 != handler)
            {
                YGirdViewCell* viewCell = nullptr;
				cocos2d::LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				lua_pushnumber(L, idx);
				int ret = pStack->executeFunction(handler, 2, 1, [&](lua_State* L, int numReturn)
				{
                    CCASSERT(numReturn == 1, "girdCellAtIndex return count error");
                    viewCell = static_cast<YGirdViewCell*>(tolua_tousertype(L, -1, nullptr));
                    lua_pop(L, 1);
                });
				pStack->clean();

                return viewCell;
            }
        }
        
        return NULL;
    }
    
    virtual ssize_t numberOfCellsInGirdView(YGirdView *gird) override
    {
        if (nullptr != gird)
        {
            int handler = gird->getHandler(YGirdView::HandlerType::NUMS_IN_GIRD);
            if (0 != handler)
            {
                ssize_t counts = 0;
				
				cocos2d::LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				int ret = pStack->executeFunction(handler, 1, 1, [&](lua_State* L, int numReturn)
				{
                    CCASSERT(numReturn == 1, "numberOfCellsInGirdView return count error");
                    counts = (ssize_t)tolua_tonumber(L, -1, 0);
                    lua_pop(L, 1);
                });
				pStack->clean();
				
                return counts;
            }
        }
		
        return 0;
    }
	
	virtual ssize_t numberOfCellsInGroup(YGirdView *gird) override
    {
        if (nullptr != gird)
        {
            int handler = gird->getHandler(YGirdView::HandlerType::NUMS_IN_GROUP);
            if (0 != handler)
            {
                ssize_t counts = 1;
				
				cocos2d::LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
				lua_State *L = pStack->getLuaState();
				
				toluafix_pushusertype_ccobject(L, gird->_ID, &(gird->_luaID), (void*)(gird), "YGirdView");
				int ret = pStack->executeFunction(handler, 1, 1, [&](lua_State* L, int numReturn)
				{
                    CCASSERT(numReturn == 1, "numberOfCellsInGroup return count error");
                    counts = (ssize_t)tolua_tonumber(L, -1, 0);
                    lua_pop(L, 1);
                });
				pStack->clean();
				
                return counts;
            }
        }
		
        return 1;
    }
};


NS_YOUNG_END


#endif // __YGirdView_H__