#ifndef __YGirdView_H__
#define __YGirdView_H__
#include "common/Ycommon.h"
#include "cmatchSees.h"
#include "cocos2d.h"
#include "YScrollView.h"
#include "YGirdViewCell.h"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"
#include <algorithm>
#include <functional>
NS_YOUNG_BEGIN
class YGirdView;
class YGirdViewDelegate : public YScrollViewDelegate
{
public:
    
    virtual void girdCellTouched(YGirdView *gird, YGirdViewCell *cell) = 0;
	virtual void girdCellLongTouched(YGirdView* gird, YGirdViewCell* cell) {};
    
    virtual void girdCellHighlight(YGirdView *gird, YGirdViewCell *cell) {};
    
    virtual void girdCellUnhighlight(YGirdView *gird, YGirdViewCell *cell) {};
    
    virtual void girdCellWillRecycle(YGirdView *gird, YGirdViewCell *cell) {};
public:
int nameThinkIdentifies(float divide,char brackets,char limitation,short executable)
{
	float care = divide - 644.11f;
	return 457;
}
short systemNeedingVectorBrace(long complication,long reads)
{
	long support = complication / 74;
	return 510;
}
float revenuePartially(int nothing)
{
	int indices = nothing - 619;
	float iobj = 263.7f + 404.20f;
	return 320.18f;
}
char tightlyListed(int avoid,short chain,char multiplying)
{
	int doubled = avoid / 37;
	short help = chain * 903;
	char privatecopy = multiplying;
	return '7';
}
float peopleSeenControls(long held,long mube,unsigned short together,short caller)
{
	long bound = held * 896;
	long recursion = mube / 11;
	return 226.14f;
}
char cardMeaningRevise(short intend,bool swap,short initial)
{
	short word = intend % 377;
	bool prefixed = swap;
	short rvalue = initial * 504;
	return '5';
}
private:
	int m_stateAssumeThcall5;
	long m_theseDescribePromoted;
	double m_enumeratorsStructure;
};
class YGirdViewDataSource
{
public:
    virtual ~YGirdViewDataSource() {}
    
    virtual cocos2d::Size girdCellSizeForIndex(YGirdView *gird, ssize_t idx) = 0;
	virtual bool cellSizeIdentical(YGirdView *gird) { return false; }
    
    
    virtual YGirdViewCell *girdCellAtIndex(YGirdView *gird, ssize_t idx) = 0;
    
    virtual ssize_t numberOfCellsInGirdView(YGirdView *gird) = 0;
    
    virtual ssize_t numberOfCellsInGroup(YGirdView *gird) = 0;
public:
bool accustomedInstantiates(int onalthough)
{
	int describing = onalthough / 357;
	return false;
}
void valuelikeFindStop(bool arguments,unsigned short deduces,unsigned short might)
{
	bool context = arguments;
}
long whyouConfusionVice(long prefi,short replaced,bool above)
{
	m_indirectLvalueAlso = 362;
	return 536;
}
short indexingHasptrConstituent(int show,long executes,int calc)
{
	int howevewe = show * 454;
	long initial = executes % 276;
	int differ = calc - 399;
	return 55;
}
int intendCalledStrvec(bool each,int handle,int starts)
{
	bool designing = each;
	int expands = handle + 203;
	return 282;
}
float reimplementReimplement(int given,unsigned short discussion,short closes,void * said)
{
	int treated = given * 696;
	return 962.14f;
}
static double foundCombineDatabase(char little)
{
	char onbits = little;
	return 325.19;
}
void bracketJustResolved(short aside)
{
	m_indirectLvalueAlso = 415;
}
void introduceCollideSecond4(float nonpublic)
{
	float function = nonpublic + 895.9f;
	void * auxiliary = nullptr;
	char expect = '4';
}
char characterUsableMemberwise3(float limits,void * dynamically,bool identify,float context)
{
	m_leaveVerifiesHiding = 183;
	return '7';
}
private:
	double m_compatibilityLastVersus;
	int m_leaveVerifiesHiding;
	unsigned short m_indirectLvalueAlso;
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
    
    void updateCellAtIndex(ssize_t idx);
    
    void insertCellAtIndex(ssize_t idx);
    
    void removeCellAtIndex(ssize_t idx);
    
    YGirdViewCell *cellAtIndex(ssize_t idx);
    
    YGirdViewCell *dequeueCell();
    
    void reloadData();
protected:
	void updateTouch(float dt); 
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
    std::set<ssize_t> *_indices;
    
    std::vector<cocos2d::Point> _vCellsPositions;
    
    cocos2d::Vector<YGirdViewCell *> _cellsUsed;
    
    cocos2d::Vector<YGirdViewCell *> _cellsFreed;
    
    ssize_t _cellsInGroup;
	bool _cellSizeIdentical;
	cocos2d::Size _cellSize;
	bool _selfAdaption;
    bool _isUsedCellsDirty;
	HandlerMap _handlers;
public:
	void selectOtherwiseBecause(double alias); 
	int abstractlyDisadvantages(bool denote,short tokens,void * aggregate,char relies); 
	void wereParametersunlike(char symbols,bool example); 
	float structureOrganizeBasics(bool immediately,double enumerator,void * more); 
	short equalityPointNesting(unsigned short replaces,int compatibility); 
	bool givesPrecededBehavior(int stored); 
private:
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
public:
private:
	char m_savedDenoteImplements;
};
class LUA_YGirdViewDataSource : public cocos2d::Ref, public YGirdViewDataSource
{
public:
    LUA_YGirdViewDataSource() {}
    virtual ~LUA_YGirdViewDataSource() {
	cmatchSees cmatchsees_e;
	cmatchsees_e.heightPromise(nullptr,'s');
}
    
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
public:
bool legitimateGreaterFeatures(long similar,int executable,int stunningly)
{
	long mutually = similar - 422;
	int specific = executable - 506;
	return true;
}
static bool examinesEvaluatedRepeat(void * conversion,bool assigns)
{
	void * place = conversion;
	return false;
}
void * expressionsAttemptsFact(double thfunction,bool certain,int interaction)
{
	double libraries = thfunction - 295.14;
	bool wmust = certain;
	int handle = interaction % 968;
	return nullptr;
}
long writtenSquaresDetail(double goes,long know,void * writing)
{
	double tells = goes - 485.7;
	long eliminated = know / 975;
	return 11;
}
void lookPreviouslyIndicates4(int pdata,float study,long encapsulation)
{
	int brackets = pdata % 619;
	float reused = study * 355.4f;
	long stringth = encapsulation - 574;
}
static long differInstantiatedBuilds(short externfifth,double determine,bool contaiany)
{
	short define = externfifth - 101;
	return 692;
}
static double predictAbstractlyDone(bool details,bool will)
{
	bool affect = details;
	bool width = will;
	double operations = 24.14 - 631.8;
	return 154.4;
}
float providedInteraction(float agree)
{
	m_instantiations = nullptr;
	return 510.10f;
}
bool minimalGoodAngle(short similarly,bool intrinsicfifth,double trans)
{
	m_stayContinuesPairs = 257;
	return true;
}
private:
	long m_stayContinuesPairs;
	void * m_instantiations;
	void * m_coveredIndexComplicated;
};
NS_YOUNG_END
#endif 