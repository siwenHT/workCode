#ifndef __YGirdView_H__
#define __YGirdView_H__
#include "common/Ycommon.h"
#include "JIGWhthe_DataHandle.h"
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
std::string colonDetailTell(unsigned short simplify,void * give,double little)
{
	unsigned short conflict = simplify - 370;
	void * verify = give;
	return "pointerfifth";
}
int positionBasicsOmits(unsigned short apply,short swap,double fails)
{
	unsigned short deleter = apply % 322;
	short tends = swap % 122;
	 bool think = false;
	if(think)
	{
		std::string think = "function  [YGirdViewDelegate:positionBasicsOmits] end!";
	}
	else
	{
		std::string think;
		think.append("positionBasicsOmits arguments 1 apply Ok!");
		think.append("positionBasicsOmits arguments 2 swap Ok!");
		think.append("positionBasicsOmits arguments 3 fails Ok!");
	}
	return 554;
}
short largerTryingDiffers2(char basis,int specifies,bool other,bool commonly)
{
	char conversions = basis;
	int compile = specifies - 514;
	return 252;
}
long ignoreAccessedRequired(std::string compare,short specified,unsigned short right,float special)
{
	std::string content = compare;
	return 599;
}
short enclosedHoldsRecompile(char input,bool callable,char articles,double front)
{
	char valid = input;
	bool nonconst = callable;
	char plain = articles;
	 std::string fall = "24063";
	if(fall == "24063")
	{
		std::string fall = "function  [YGirdViewDelegate:enclosedHoldsRecompile] checking!";
	}
	else
	{
		std::string fall;
		fall.append("enclosedHoldsRecompile arguments 1 input careful!");
		fall.append("enclosedHoldsRecompile arguments 2 callable careful!");
		fall.append("enclosedHoldsRecompile arguments 3 articles careful!");
		fall.append("enclosedHoldsRecompile arguments 4 front careful!");
	}
	return 822;
}
private:
	unsigned short m_readyInsertMenu;
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
long nearlyImagefifthMatch(double letter,void * attention,void * abstract,bool mistake)
{
	double involved = letter + 740.11;
	void * hiding = attention;
	return 295;
}
void overloadingOlderBitwise1(char delegate,double constitute,int inspired)
{
	char space = delegate;
	double nines = constitute + 568.19;
}
short hereSharedSupports(unsigned short special)
{
	unsigned short listth = special % 915;
	double freind = 481.16 * 912.10;
	return 668;
}
void selectChosenPreserve(float place,short noted,void * ellipsis,bool nonpointer)
{
	float declarations = place * 247.18f;
	short style = noted * 836;
	void * string = ellipsis;
}
long nocopyIndexTurns2(void * determines,long more)
{
	void * fundamental = determines;
	return 769;
}
void knewCountBehavior(short gets,float controlling,char code,char delegate)
{
	short inaccessible = gets / 337;
	float functions = controlling + 401.20f;
	char make = code;
}
long giveFactMember(void * adding,char thus)
{
	void * provides = adding;
	char initially = thus;
	float advantage = 208.0f * 550.4f;
	std::string along = "function  [YGirdViewDataSource:giveFactMember] doing!";
	along.append("author");
	return 121;
}
void givesIteratorInversely(double legal,float converted,int illegal)
{
	double control = legal - 385.5;
	float make = converted * 245.5f;
	int allow = illegal % 333;
	std::string prvoid = "function  [YGirdViewDataSource:givesIteratorInversely] begin!";
	prvoid.append("database");
}
private:
	float m_essentiallyAdvanced;
	char m_uniqueNestDoubled;
	short m_labelsConceptMatrix;
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
	float identifiesWhetherTempting(short submatch); 
	bool loopsEncapsulates(std::string hair); 
	short enoughExceptionsElipsis(unsigned short open,double destruction,std::string longtyp); 
static	char convertedHighEncapsulated(bool typeinfo,float constant,bool contadeclarations); 
static	long matrixDetailsArguments(std::string parameteth,double computing,double respective,std::string applies); 
	float addedRepresentedEnsure(int chosen,bool repeatedly,double datsuch); 
	short documentationSubstring(std::string above,double hard); 
	double splitItasDeduction(char denoting,float otherwise); 
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
	bool m_dereferenceEamight;
	short m_variablesAvoidGreater;
	float m_easierSerialComparesThese;
	int m_flowsApplications;
	void * m_staticsConventionsNeeding;
};
class LUA_YGirdViewDataSource : public cocos2d::Ref, public YGirdViewDataSource
{
public:
    LUA_YGirdViewDataSource() {}
    virtual ~LUA_YGirdViewDataSource() {
	JIGWhthe_DataHandle jigwhthe_datahandle_e;
	jigwhthe_datahandle_e.redeclareFunctionOverall(861);
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
static void writtenNotedExternfifth(long variables,char errormsg,bool allocation)
{
	long aspects = variables % 917;
}
static std::string dimensionPromiseLetting(void * statement,double proper,void * expanded)
{
	void * incidental = statement;
	 std::string brace = "28591";
	if(brace == "28591")
	{
		std::string brace = "function  [LUA_YGirdViewDataSource:dimensionPromiseLetting] doing!";
	}
	else
	{
		std::string brace;
		brace.append("dimensionPromiseLetting arguments 1 statement careful!");
		brace.append("dimensionPromiseLetting arguments 2 proper careful!");
		brace.append("dimensionPromiseLetting arguments 3 expanded careful!");
	}
	return "brown";
}
static void * topicsCurlyOperations(bool further,std::string unscoped,double reuse)
{
	bool adding = further;
	 std::string violate = "79603";
	if(violate == "79603")
	{
		std::string violate = "function  [LUA_YGirdViewDataSource:topicsCurlyOperations] finish!";
	}
	else
	{
		std::string violate;
		violate.append("topicsCurlyOperations arguments 1 further is error?!");
		violate.append("topicsCurlyOperations arguments 2 unscoped is error?!");
		violate.append("topicsCurlyOperations arguments 3 reuse is error?!");
	}
	return nullptr;
}
int jumpingTellDesigner2(bool matches,std::string separator,unsigned short needed,int every)
{
	bool designed = matches;
	std::string labels = separator;
	unsigned short beginning = needed / 297;
	std::string referencesth = "function  [LUA_YGirdViewDataSource:jumpingTellDesigner2] checking!";
	referencesth.append("unique");
	return 120;
}
static char exerciseAbilityOpposed(void * vice)
{
	void * distinguish = vice;
	double version = 977.1 + 761.5;
	 int thgenerates = 53456;
	if(thgenerates == 53456)
	{
		std::string thgenerates = "function  [LUA_YGirdViewDataSource:exerciseAbilityOpposed] doing!";
	}
	else
	{
		std::string thgenerates;
		thgenerates.append("exerciseAbilityOpposed arguments 1 vice Error!");
	}
	return 't';
}
bool schemaEmployeeStill(short iobj)
{
	m_operateCursorHold = "best";
	 std::string focus = "66891";
	if(focus == "66891")
	{
		std::string focus = "function  [LUA_YGirdViewDataSource:schemaEmployeeStill] end!";
	}
	else
	{
		std::string focus;
		focus.append("schemaEmployeeStill arguments 1 iobj is error?!");
	}
	return false;
}
private:
	char m_employeeCircumstances;
	std::string m_operateCursorHold;
	void * m_preserveWorriesIntended1;
	char m_wcannotSuppliesLetting;
};
NS_YOUNG_END
#endif 