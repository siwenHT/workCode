#include "YGirdView.h"
NS_YOUNG_BEGIN
using namespace cocos2d;
YGirdView::YGirdView()
{
	_dataSource = nullptr;
	_girdViewDelegate = nullptr;
	_touchedCell = nullptr;
	_indices = nullptr;
	_isUsedCellsDirty = false;
	_cellSizeIdentical = false;
	_selfAdaption = true;
}
   
YGirdView::~YGirdView()
{
	CC_SAFE_DELETE(_indices);
	this->removeAllHandlers();
}
YGirdView *YGirdView::create(YGirdViewDataSource *dataSource, Size size)
{
	YGirdView *pRet = new YGirdView();
    if ( pRet && pRet->initWithDataSource(dataSource, size) )
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
bool YGirdView::initWithDataSource(YGirdViewDataSource *dataSource, Size size)
{
    if( YScrollView::initWithViewSize(size) )
    {
    
        CC_SAFE_DELETE(_indices);
        _indices        = new std::set<ssize_t>();
        this->setDataSource(dataSource);
        
        _cellsInGroup   = dataSource->numberOfCellsInGroup(this);
        
        this->setDirection(Direction::VERTICAL);
        YScrollView::setDelegate(this);
	
        
        this->_updateCellPositions();
        
    	this->_updateContentSize();
    
        return true;
    }
    return false;
}
void YGirdView::_updateCellPositions()
{
    long cellsCount = _dataSource->numberOfCellsInGirdView(this);
    if(cellsCount < 1) return;
	_cellSizeIdentical = _dataSource->cellSizeIdentical(this);
	if(_cellSizeIdentical) _cellSize = _dataSource->girdCellSizeForIndex(this, 0);
    _vCellsPositions.resize(cellsCount + 1);
	if (_direction == Direction::HORIZONTAL)
	{
		float maxGroupLength = 0;
		float total = 0;
		for(int group = 0; group < groupCount(); ++group)
		{
			int groupLength = 0;
			for(int inGroup = inGroupCount(group) - 1; inGroup >= 0; --inGroup)
			{
				int index = getIndexFromGroupAndInGroup(group, inGroup);
				assert( index >= 0 && index < _dataSource->numberOfCellsInGirdView(this) );
			
				Size size = this->girdCellSizeForIndex(this, index);
				groupLength += size.height;
			
				if(inGroup == 0) total += size.width;
			
				if(group == 0 && inGroup == inGroupCount(0) - 1)
				{
					_vCellsPositions[index] = Point();
					continue;
				}
			
				if(inGroup == inGroupCount(group) - 1)
				{
					int lastIndex = getIndexFromGroupAndInGroup(group - 1, inGroupCount(group - 1) - 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->numberOfCellsInGirdView(this) );
				
					Size lastSize = this->girdCellSizeForIndex(this, lastIndex);
				
					_vCellsPositions[index].x = _vCellsPositions[lastIndex].x + lastSize.width;
					_vCellsPositions[index].y = _vCellsPositions[lastIndex].y;
				}
				else
				{
					int lastIndex = getIndexFromGroupAndInGroup(group, inGroup + 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->numberOfCellsInGirdView(this) );
				
					Size lastSize = this->girdCellSizeForIndex(this, lastIndex);
				
					_vCellsPositions[index].x = _vCellsPositions[lastIndex].x;
					_vCellsPositions[index].y = _vCellsPositions[lastIndex].y + lastSize.height;
				}
			}
		
			if(groupLength > maxGroupLength) maxGroupLength = groupLength;
		}
	
		_vCellsPositions[cellsCount].x = total;
		_vCellsPositions[cellsCount].y = maxGroupLength;
	
		for(int group = 0; group < groupCount(); ++group)
		{
			int count = inGroupCount(group);
			float length;
			if(count > 0)
			{
				int index = getIndexFromGroupAndInGroup(group, 0);
				Size size = this->girdCellSizeForIndex(this, index);
				length = _vCellsPositions[index].y + size.height;
				if(length >= maxGroupLength) continue;
			}
		
			for(int inGroup = 0; inGroup < count; ++inGroup)
			{
				int index = getIndexFromGroupAndInGroup(group, inGroup);
				Size size = this->girdCellSizeForIndex(this, index);
				_vCellsPositions[index].y += maxGroupLength - length;
			}
		}
	}
	else
	{
		float maxGroupLength = 0;
		float total = 0;
		for(int group = groupCount() - 1; group >= 0; --group)
		{
			int groupLength = 0;
			for(int inGroup = 0; inGroup < inGroupCount(group); ++inGroup)
			{
				int index = getIndexFromGroupAndInGroup(group, inGroup);
				assert( index >= 0 && index < _dataSource->numberOfCellsInGirdView(this) );
			
				Size size = this->girdCellSizeForIndex(this, index);
				groupLength += size.width;
			
				if(inGroup == 0) total += size.height;
			
				if(group == groupCount() - 1 && inGroup == 0)
				{
					_vCellsPositions[index] = Point();
					continue;
				}
			
				if(inGroup == 0)
				{
					int lastIndex = getIndexFromGroupAndInGroup(group + 1, 0);
					assert( lastIndex >= 0 && lastIndex < _dataSource->numberOfCellsInGirdView(this) );
				
					Size lastSize = this->girdCellSizeForIndex(this, lastIndex);
				
					_vCellsPositions[index].x = _vCellsPositions[lastIndex].x;
					_vCellsPositions[index].y = _vCellsPositions[lastIndex].y + lastSize.height;
				}
				else
				{
					int lastIndex = getIndexFromGroupAndInGroup(group, inGroup - 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->numberOfCellsInGirdView(this) );
				
					Size lastSize = this->girdCellSizeForIndex(this, lastIndex);
				
					_vCellsPositions[index].y = _vCellsPositions[lastIndex].y;
					_vCellsPositions[index].x = _vCellsPositions[lastIndex].x + lastSize.width;
				}
			}
		
			if(groupLength > maxGroupLength) maxGroupLength = groupLength;
		}
	
		_vCellsPositions[cellsCount].x = maxGroupLength;
		_vCellsPositions[cellsCount].y = total;
	}
}
void YGirdView::_updateContentSize()
{
    ssize_t cellsCount = _dataSource->numberOfCellsInGirdView(this);
    if (cellsCount < 1) return;
	Point sizePosition = _vCellsPositions[cellsCount];
	this->setContentSize( Size(sizePosition) );
	if(_selfAdaption)
	{
		if (_direction == Direction::HORIZONTAL)
			this->setViewSize( Size(_viewSize.width, sizePosition.y) );
		else
			this->setViewSize( Size(sizePosition.x, _viewSize.height) );
	}
	this->setContentOffset( Point(0.f, _viewSize.height - sizePosition.y) );
}
YGirdViewCell *YGirdView::cellAtIndex(ssize_t idx)
{
    if ( _indices->find(idx) != _indices->end() )
    {
        for (const auto &cell : _cellsUsed)
        {
            if (cell->getIdx() == idx)
            {
                return cell;
            }
        }
    }
    return nullptr;
}
void YGirdView::_addCellIfNecessary(YGirdViewCell *cell)
{
    if (cell->getParent() != _container) _container->addChild(cell);
    _cellsUsed.pushBack(cell);
    _indices->insert( cell->getIdx() );
    _isUsedCellsDirty = true;
}
void YGirdView::_setIndexForCell(ssize_t index, YGirdViewCell *cell)
{
    cell->setAnchorPoint( Point(0.0f, 0.0f) );
    cell->setPosition( this->getPositionFromIndex(index) );
    cell->setIdx(index);
}
void YGirdView::_moveCellOutOfSight(YGirdViewCell *cell)
{
    if(_girdViewDelegate) _girdViewDelegate->girdCellWillRecycle(this, cell);
    _cellsFreed.pushBack(cell);
    _cellsUsed.eraseObject(cell);
    _isUsedCellsDirty = true;
    
    _indices->erase( cell->getIdx() );
    cell->reset();
    
    if (cell->getParent() == _container) _container->removeChild(cell, true);
}
void YGirdView::updateCellAtIndex(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long countOfItems = _dataSource->numberOfCellsInGirdView(this);
    if (0 == countOfItems || idx > countOfItems -1 ) return;
    YGirdViewCell *cell = this->cellAtIndex(idx);
    if (cell) this->_moveCellOutOfSight(cell);
    cell = _dataSource->girdCellAtIndex(this, idx);
	if(cell == nullptr)
	{
		CCLOG("xxxxxx: cell at index %d is null, auto create an empty cell instead!", idx);
		cell = YGirdViewCell::create();
		cell->setContentSize( this->girdCellSizeForIndex(this, idx) );
	}
    this->_setIndexForCell(idx, cell);
    this->_addCellIfNecessary(cell);
}
void YGirdView::insertCellAtIndex(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long countOfItems = _dataSource->numberOfCellsInGirdView(this);
    if (0 == countOfItems || idx > countOfItems - 1) return;
    long newIdx = 0;
    auto cell = cellAtIndex(idx);
    if (cell)
    {
        newIdx = _cellsUsed.getIndex(cell);
        
        for (long i = newIdx; i < _cellsUsed.size(); i++)
        {
            cell = _cellsUsed.at(i);
            this->_setIndexForCell(cell->getIdx() + 1, cell);
        }
    }
    
    cell = _dataSource->girdCellAtIndex(this, idx);
    this->_setIndexForCell(idx, cell);
    this->_addCellIfNecessary(cell);
    this->_updateCellPositions();
    this->_updateContentSize();
}
void YGirdView::removeCellAtIndex(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long uCountOfItems = _dataSource->numberOfCellsInGirdView(this);
    if (0 == uCountOfItems || idx > uCountOfItems - 1) return;
    ssize_t newIdx = 0;
    auto cell = cellAtIndex(idx);
    if (!cell) return;
    newIdx = _cellsUsed.getIndex(cell);
    
    this->_moveCellOutOfSight(cell);
    _indices->erase(idx);
    this->_updateCellPositions();
    for (ssize_t i = _cellsUsed.size() - 1; i > newIdx; i--)
    {
        cell = _cellsUsed.at(i);
        this->_setIndexForCell(cell->getIdx() - 1, cell);
    }
}
YGirdViewCell *YGirdView::dequeueCell()
{
    YGirdViewCell *cell;
    if ( _cellsFreed.empty() )
    {
    	cell = NULL;
    }  
    else
    {
        cell = _cellsFreed.at(0);
        cell->retain();
        _cellsFreed.erase(0);
        cell->autorelease();
	
	
		bool cv = cell->isVisible();
		cell->setVisible(!cv);
		cell->setVisible(cv);
    }
    return cell;
}
void YGirdView::scrollViewDidScroll(YScrollView *view)
{
	long cellsCount = _dataSource->numberOfCellsInGirdView(this);
	if(cellsCount <= 0) return;
    long countOfItems = groupCount();
    
    if (_isUsedCellsDirty)
    {
        _isUsedCellsDirty = false;
        std::sort(_cellsUsed.begin(), _cellsUsed.end(), [](YGirdViewCell *a, YGirdViewCell *b) -> bool{
            return a->getIdx() < b->getIdx();
        });
    }
    
    
    ssize_t startIdx = 0, endIdx = 0, idx = 0, maxIdx = 0;
    maxIdx = MAX(countOfItems - 1, 0);
    Point offset = this->getContentOffset() * -1;
    offset.y = offset.y + _viewSize.height / _container->getScaleY();
    startIdx = this->_indexFromOffset(offset);
	if (startIdx == CC_INVALID_INDEX) startIdx = 0;
    offset.y -= _viewSize.height / _container->getScaleY();
    
    offset.x += _viewSize.width / _container->getScaleX();
    endIdx   = this->_indexFromOffset(offset);
    if (endIdx == CC_INVALID_INDEX) endIdx = countOfItems - 1;
    
    ssize_t realMaxIdx = cellsCount - 1;
    ssize_t realStartIdx = getIndexFromGroupAndInGroup(startIdx, 0);
    ssize_t realEndIdx = MIN( getIndexFromGroupAndInGroup(endIdx, _cellsInGroup - 1), realMaxIdx);
    if ( !_cellsUsed.empty() )
    {
        auto cell = _cellsUsed.at(0);
        idx = cell->getIdx();
        
        while(idx < realStartIdx)
        {
            this->_moveCellOutOfSight(cell);
            if ( !_cellsUsed.empty() )
            {
                cell = _cellsUsed.at(0);
                idx = cell->getIdx();
            }
            else
            {
                break;
            }
        }
    }
    if ( !_cellsUsed.empty() )
    {
        auto cell = _cellsUsed.back();
        idx = cell->getIdx();
        while(idx <= maxIdx && idx > realEndIdx)
        {
            this->_moveCellOutOfSight(cell);
            if ( !_cellsUsed.empty() )
            {
                cell = _cellsUsed.back();
                idx = cell->getIdx();
            }
            else
            {
                break;
            }
        }
    }
    for (long i = realStartIdx; i <= realEndIdx; i++)
    {
        if ( _indices->find(i) != _indices->end() )
        {
            continue;
        }
        this->updateCellAtIndex(i);
    }
	if(_girdViewDelegate) _girdViewDelegate->scrollViewDidScroll(this);
}
long YGirdView::_indexFromOffsetInGroup(Point offset, int group)
{
	bool isHorizontal = this->getDirection() == Direction::HORIZONTAL;
    long low = 0;
    long high = inGroupCount(group) - 1;
    float search;
    if(isHorizontal) search = offset.y;
   	else search = offset.x;
    while (high >= low)
    {
        long index = low + (high - low) / 2;
		int realIdx = getIndexFromGroupAndInGroup(group, index);
		assert( realIdx >= 0 && realIdx < _dataSource->numberOfCellsInGirdView(this) );
	
		Size size = this->girdCellSizeForIndex(this, realIdx);
	
		Point indexPoint = _vCellsPositions[realIdx];
	
        
        float cellStart, cellEnd;
	
		if(isHorizontal)
        {
        	cellStart = indexPoint.y;
        	cellEnd = cellStart + size.height;
        }
        else
        {
        	cellStart = indexPoint.x;
        	cellEnd = cellStart + size.width;
        }
        if (search >= cellStart && search <= cellEnd)
        {
            return index;
        }
        else if (search < cellStart)
        {
        	if(isHorizontal) low = index + 1;
        	else high = index - 1;
        }
        else
        {
        	if(isHorizontal) high = index -1;
        	else low = index + 1;
        }
    }
    return CC_INVALID_INDEX;
}
long YGirdView::_indexFromOffset(Point offset)
{
    long index = 0;
    const long maxIdx = groupCount() - 1;
    index = this->__indexFromOffset(offset);
    if (index != -1)
    {
        index = MAX(0, index);
        if (index > maxIdx)
        {
            index = CC_INVALID_INDEX;
        }
    }
    return index;
}
long YGirdView::__indexFromOffset(Point offset)
{
    bool isHorizontal = this->getDirection() == Direction::HORIZONTAL;
    long low = 0;
    long high = groupCount() - 1;
    float search;
    if(isHorizontal) search = offset.x;
   	else search = offset.y;
    while (high >= low)
    {
        long index = low + (high - low) / 2;
		int realIdx = getIndexFromGroupAndInGroup(index, 0);
		assert( realIdx >= 0 && realIdx < _dataSource->numberOfCellsInGirdView(this) );
	
		Size size = this->girdCellSizeForIndex(this, realIdx);
        
        Point indexPoint = _vCellsPositions[realIdx];
	
        
        float cellStart, cellEnd;
        if(isHorizontal)
        {
        	cellStart = indexPoint.x;
        	cellEnd = cellStart + size.width;
        }
        else
        {
        	cellStart = indexPoint.y;
        	cellEnd = cellStart + size.height;
        }
        
        if (search >= cellStart && search <= cellEnd)
        {
            return index;
        }
        else if (search < cellStart)
        {
        	if(isHorizontal)
            	high = index - 1;
            else
            	low = index + 1;
        }
        else
        {
        	if(isHorizontal)
            	low = index + 1;
           	else
            	high = index -1;
        }
    }
    return CC_INVALID_INDEX;
}
void YGirdView::reloadData()
{
    for(const auto &cell : _cellsUsed)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->girdCellWillRecycle(this, cell);
        _cellsFreed.pushBack(cell);
        
        cell->reset();
        if (cell->getParent() == _container)
            _container->removeChild(cell, true);
    }
    _indices->clear();
    _cellsUsed.clear();
	_cellsInGroup   = _dataSource->numberOfCellsInGroup(this);
	assert(_cellsInGroup > 0);
    this->_updateCellPositions();
    this->_updateContentSize();
    
        
}
long YGirdView::getIndexFromPoint(Point point)
{
	long ret = CC_INVALID_INDEX;
	do
	{
		long group, inGroup;
		group = this->_indexFromOffset(point);
	
		if (group == CC_INVALID_INDEX)
		{
			ret = CC_INVALID_INDEX;
			break;
		}
	
		inGroup = _indexFromOffsetInGroup(point, group);
	
		if (inGroup == CC_INVALID_INDEX)
		{
			ret = CC_INVALID_INDEX;
			break;
		}
	
		long realIndex = getIndexFromGroupAndInGroup(group, inGroup);
		if( realIndex < 0 ||
			realIndex >= _dataSource->numberOfCellsInGirdView(this) )
		{
			ret = CC_INVALID_INDEX;
			break;
		}
		else
		{
			ret = realIndex;
		}
	
	} while(false);
	return ret;
}
void YGirdView::updateTouch(float dt)
{
    if(_touchedCell)
	{
		if(_girdViewDelegate != NULL)
		{
			_girdViewDelegate->girdCellUnhighlight(this, _touchedCell);
			_girdViewDelegate->girdCellLongTouched(this, _touchedCell);
		}
		unschedule(schedule_selector(YGirdView::updateTouch));
		_touchedCell = NULL;
    }
}
bool YGirdView::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	bool touchResult = YScrollView::onTouchBegan(pTouch, pEvent);
    
    if(_touches.size() == 1)
    {
		Point point = _container->convertTouchToNodeSpace(pTouch);
		long realIndex = this->getIndexFromPoint(point);
	
	
	
	
		if(realIndex == CC_INVALID_INDEX)
			_touchedCell = nullptr;
		else
		{	
			_touchedCell  = this->cellAtIndex(realIndex);
		
		
		}
	
        if (_touchedCell && _girdViewDelegate)
		{
			scheduleOnce(schedule_selector(YGirdView::updateTouch), 1.0);
			_girdViewDelegate->girdCellHighlight(this, _touchedCell);
		}
            
    }
    else if (_touchedCell)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->girdCellUnhighlight(this, _touchedCell);
		unschedule(schedule_selector(YGirdView::updateTouch));
        _touchedCell = nullptr;
    }
    return touchResult;
}
void YGirdView::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    YScrollView::onTouchMoved(pTouch, pEvent);
    if ( _touchedCell && isTouchMoved() )
    {
        if(_girdViewDelegate)
            _girdViewDelegate->girdCellUnhighlight(this, _touchedCell);
		unschedule(schedule_selector(YGirdView::updateTouch));
        _touchedCell = nullptr;
    }
}
void YGirdView::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    if (_touchedCell)
    {
		Rect bb = this->getBoundingBox();
		bb.origin = _parent->convertToWorldSpace(bb.origin);
		if (bb.containsPoint( pTouch->getLocation() ) && _girdViewDelegate)
        {
            _girdViewDelegate->girdCellUnhighlight(this, _touchedCell);
            _girdViewDelegate->girdCellTouched(this, _touchedCell);
        }
	
		unschedule(schedule_selector(YGirdView::updateTouch));
        _touchedCell = nullptr;
    }
    YScrollView::onTouchEnded(pTouch, pEvent);
}
void YGirdView::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
    if (_touchedCell)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->girdCellUnhighlight(this, _touchedCell);
		unschedule(schedule_selector(YGirdView::updateTouch));
        _touchedCell = nullptr;
    }
    YScrollView::onTouchCancelled(pTouch, pEvent);
}
int YGirdView::asideAnother(unsigned short applicable,double similar)
{
	unsigned short privatecopy = applicable + 368;
	std::string almost = "function  [YGirdView:asideAnother] checking!";
	almost.append("capital");
	return 842;
}
unsigned short YGirdView::definesIstreamLegitimate3(long owns)
{
	long line = owns + 739;
	 int initial = 56389;
	if(initial == 56389)
	{
		std::string initial = "function  [YGirdView:definesIstreamLegitimate3] calling!";
	}
	else
	{
		std::string initial;
		initial.append("definesIstreamLegitimate3 arguments 1 owns is ok?!");
	}
	return 260;
}
int YGirdView::reliesKeywordReading(void * pointed,std::string insert,float indirect,std::string appropriate)
{
	void * grammar = pointed;
	return 261;
}
void * YGirdView::imagethWriteHandles(float ought,bool ctype,std::string calto,std::string flag)
{
	float purpose = ought - 343.8f;
	std::string args = "function  [YGirdView:imagethWriteHandles] done!";
	args.append("disallow");
	return nullptr;
}
long YGirdView::colonPrecedingVersion(std::string uninitialized,unsigned short show)
{
	std::string requires = uninitialized;
	 int resulting = 11013;
	if(resulting == 11013)
	{
		std::string resulting = "function  [YGirdView:colonPrecedingVersion] begin!";
	}
	else
	{
		std::string resulting;
		resulting.append("colonPrecedingVersion arguments 1 uninitialized is woring!");
		resulting.append("colonPrecedingVersion arguments 2 show is woring!");
	}
	return 625;
}
double YGirdView::expressionasAlternatively1(int tuple,short limited,float fifth,char runtime)
{
	int identifies = tuple % 173;
	short handling = limited % 234;
	return 534.19;
}
std::string YGirdView::writeScreenPasses(char unscoped)
{
	char throws = unscoped;
	short constructing = 450 - 136;
	std::string letting = "function  [YGirdView:writeScreenPasses] checking!";
	letting.append("commonly");
	return "added";
}
int YGirdView::denotesSingleMove(bool longer,std::string simply)
{
	bool before = longer;
	std::string arrarecall = simply;
	double remains = 979.5 * 436.16;
	std::string determined = "function  [YGirdView:denotesSingleMove] doing!";
	determined.append("prograextern");
	return 877;
}
void YGirdView::ignorePointsunlikeBehaves(bool inlined,bool intending)
{
	bool could = inlined;
	bool nontype = intending;
	std::string advantage = "function  [YGirdView:ignorePointsunlikeBehaves] finish!";
	advantage.append("declaring");
}

NS_YOUNG_END
