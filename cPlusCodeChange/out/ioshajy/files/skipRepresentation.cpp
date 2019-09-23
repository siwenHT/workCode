#include "skipRepresentation.h"
NS_YOUNG_BEGIN
using namespace cocos2d;
skipRepresentation::skipRepresentation()
{
	_dataSource = nullptr;
	_girdViewDelegate = nullptr;
	_touchedCell = nullptr;
	_indices = nullptr;
	equivalentthLeftDirectly = false;
	basisException = false;
	interchangeablyThcall = true;
}
   
skipRepresentation::~skipRepresentation()
{
	CC_SAFE_DELETE(_indices);
	this->calcExpectationsAnother();
}
skipRepresentation *skipRepresentation::create(allowContrpassesExplain *dataSource, Size size)
{
	skipRepresentation *pRet = new skipRepresentation();
    if ( pRet && pRet->neededExpectDesigners(dataSource, size) )
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
bool skipRepresentation::neededExpectDesigners(allowContrpassesExplain *dataSource, Size size)
{
    if( fieldComparesImprovements::presenceGreater(size) )
    {
    
        CC_SAFE_DELETE(_indices);
        _indices        = new std::set<ssize_t>();
        this->setspellingControlEnforce(dataSource);
        
        primerCauseMake   = dataSource->implicitConvenientDefined(this);
        
        this->setmultiplyingTarget(multiplyingTarget::VERTICAL);
        fieldComparesImprovements::setDelegate(this);
	
        
        this->howeveweResultsTwin();
        
    	this->unwindingFindbookView();
    
        return true;
    }
    return false;
}
void skipRepresentation::howeveweResultsTwin()
{
    long cellsCount = _dataSource->unusualOperatesConvert(this);
    if(cellsCount < 1) return;
	basisException = _dataSource->appeaanywhereSynthesizes(this);
	if(basisException) _cellSize = _dataSource->hasptrConstitutes(this, 0);
    drivenCopiedYour.resize(cellsCount + 1);
	if (accumulateWhichever == multiplyingTarget::HORIZONTAL)
	{
		float maxGroupLength = 0;
		float total = 0;
		for(int group = 0; group < unnecessarySometimes(); ++group)
		{
			int groupLength = 0;
			for(int inGroup = whenOptionalChose(group) - 1; inGroup >= 0; --inGroup)
			{
				int index = gettransformationFlagged(group, inGroup);
				assert( index >= 0 && index < _dataSource->unusualOperatesConvert(this) );
			
				Size size = this->hasptrConstitutes(this, index);
				groupLength += size.height;
			
				if(inGroup == 0) total += size.width;
			
				if(group == 0 && inGroup == whenOptionalChose(0) - 1)
				{
					drivenCopiedYour[index] = Point();
					continue;
				}
			
				if(inGroup == whenOptionalChose(group) - 1)
				{
					int lastIndex = gettransformationFlagged(group - 1, whenOptionalChose(group - 1) - 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->unusualOperatesConvert(this) );
				
					Size lastSize = this->hasptrConstitutes(this, lastIndex);
				
					drivenCopiedYour[index].x = drivenCopiedYour[lastIndex].x + lastSize.width;
					drivenCopiedYour[index].y = drivenCopiedYour[lastIndex].y;
				}
				else
				{
					int lastIndex = gettransformationFlagged(group, inGroup + 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->unusualOperatesConvert(this) );
				
					Size lastSize = this->hasptrConstitutes(this, lastIndex);
				
					drivenCopiedYour[index].x = drivenCopiedYour[lastIndex].x;
					drivenCopiedYour[index].y = drivenCopiedYour[lastIndex].y + lastSize.height;
				}
			}
		
			if(groupLength > maxGroupLength) maxGroupLength = groupLength;
		}
	
		drivenCopiedYour[cellsCount].x = total;
		drivenCopiedYour[cellsCount].y = maxGroupLength;
	
		for(int group = 0; group < unnecessarySometimes(); ++group)
		{
			int count = whenOptionalChose(group);
			float length;
			if(count > 0)
			{
				int index = gettransformationFlagged(group, 0);
				Size size = this->hasptrConstitutes(this, index);
				length = drivenCopiedYour[index].y + size.height;
				if(length >= maxGroupLength) continue;
			}
		
			for(int inGroup = 0; inGroup < count; ++inGroup)
			{
				int index = gettransformationFlagged(group, inGroup);
				Size size = this->hasptrConstitutes(this, index);
				drivenCopiedYour[index].y += maxGroupLength - length;
			}
		}
	}
	else
	{
		float maxGroupLength = 0;
		float total = 0;
		for(int group = unnecessarySometimes() - 1; group >= 0; --group)
		{
			int groupLength = 0;
			for(int inGroup = 0; inGroup < whenOptionalChose(group); ++inGroup)
			{
				int index = gettransformationFlagged(group, inGroup);
				assert( index >= 0 && index < _dataSource->unusualOperatesConvert(this) );
			
				Size size = this->hasptrConstitutes(this, index);
				groupLength += size.width;
			
				if(inGroup == 0) total += size.height;
			
				if(group == unnecessarySometimes() - 1 && inGroup == 0)
				{
					drivenCopiedYour[index] = Point();
					continue;
				}
			
				if(inGroup == 0)
				{
					int lastIndex = gettransformationFlagged(group + 1, 0);
					assert( lastIndex >= 0 && lastIndex < _dataSource->unusualOperatesConvert(this) );
				
					Size lastSize = this->hasptrConstitutes(this, lastIndex);
				
					drivenCopiedYour[index].x = drivenCopiedYour[lastIndex].x;
					drivenCopiedYour[index].y = drivenCopiedYour[lastIndex].y + lastSize.height;
				}
				else
				{
					int lastIndex = gettransformationFlagged(group, inGroup - 1);
					assert( lastIndex >= 0 && lastIndex < _dataSource->unusualOperatesConvert(this) );
				
					Size lastSize = this->hasptrConstitutes(this, lastIndex);
				
					drivenCopiedYour[index].y = drivenCopiedYour[lastIndex].y;
					drivenCopiedYour[index].x = drivenCopiedYour[lastIndex].x + lastSize.width;
				}
			}
		
			if(groupLength > maxGroupLength) maxGroupLength = groupLength;
		}
	
		drivenCopiedYour[cellsCount].x = maxGroupLength;
		drivenCopiedYour[cellsCount].y = total;
	}
}
void skipRepresentation::unwindingFindbookView()
{
    ssize_t cellsCount = _dataSource->unusualOperatesConvert(this);
    if (cellsCount < 1) return;
	Point sizePosition = drivenCopiedYour[cellsCount];
	this->setContentSize( Size(sizePosition) );
	if(interchangeablyThcall)
	{
		if (accumulateWhichever == multiplyingTarget::HORIZONTAL)
			this->setdereferenceAppearGave( Size(_viewSize.width, sizePosition.y) );
		else
			this->setdereferenceAppearGave( Size(sizePosition.x, _viewSize.height) );
	}
	this->setContentOffset( Point(0.f, _viewSize.height - sizePosition.y) );
}
abstractNines *skipRepresentation::cellAtIndex(ssize_t idx)
{
    if ( _indices->find(idx) != _indices->end() )
    {
        for (const auto &cell : m_convertAllowedAbsolute)
        {
            if (cell->getIdx() == idx)
            {
                return cell;
            }
        }
    }
    return nullptr;
}
void skipRepresentation::equallyCreatingCome(abstractNines *cell)
{
    if (cell->getParent() != m_protectionCorrectlySoon) m_protectionCorrectlySoon->addChild(cell);
    m_convertAllowedAbsolute.pushBack(cell);
    _indices->insert( cell->getIdx() );
    equivalentthLeftDirectly = true;
}
void skipRepresentation::thanContaianyAffected(ssize_t index, abstractNines *cell)
{
    cell->setAnchorPoint( Point(0.0f, 0.0f) );
    cell->setPosition( this->getwordTildeNest(index) );
    cell->setIdx(index);
}
void skipRepresentation::theareWithfifthAliases(abstractNines *cell)
{
    if(_girdViewDelegate) _girdViewDelegate->howeveweFlaggedPostfix(this, cell);
    m_pairsEfficiencyFacilities.pushBack(cell);
    m_convertAllowedAbsolute.eraseObject(cell);
    equivalentthLeftDirectly = true;
    
    _indices->erase( cell->getIdx() );
    cell->reset();
    
    if (cell->getParent() == m_protectionCorrectlySoon) m_protectionCorrectlySoon->removeChild(cell, true);
}
void skipRepresentation::failAheadRemain(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long countOfItems = _dataSource->unusualOperatesConvert(this);
    if (0 == countOfItems || idx > countOfItems -1 ) return;
    abstractNines *cell = this->cellAtIndex(idx);
    if (cell) this->theareWithfifthAliases(cell);
    cell = _dataSource->flagMeddleJustDeclaration(this, idx);
	if(cell == nullptr)
	{
		CCLOG("xxxxxx: cell at index %d is null, auto create an empty cell instead!", idx);
		cell = abstractNines::create();
		cell->setContentSize( this->hasptrConstitutes(this, idx) );
	}
    this->thanContaianyAffected(idx, cell);
    this->equallyCreatingCome(cell);
}
void skipRepresentation::meanLeaveChartyp3(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long countOfItems = _dataSource->unusualOperatesConvert(this);
    if (0 == countOfItems || idx > countOfItems - 1) return;
    long newIdx = 0;
    auto cell = cellAtIndex(idx);
    if (cell)
    {
        newIdx = m_convertAllowedAbsolute.getIndex(cell);
        
        for (long i = newIdx; i < m_convertAllowedAbsolute.size(); i++)
        {
            cell = m_convertAllowedAbsolute.at(i);
            this->thanContaianyAffected(cell->getIdx() + 1, cell);
        }
    }
    
    cell = _dataSource->flagMeddleJustDeclaration(this, idx);
    this->thanContaianyAffected(idx, cell);
    this->equallyCreatingCome(cell);
    this->howeveweResultsTwin();
    this->unwindingFindbookView();
}
void skipRepresentation::respectiveTellChose(ssize_t idx)
{
    if (idx == CC_INVALID_INDEX) return;
    long uCountOfItems = _dataSource->unusualOperatesConvert(this);
    if (0 == uCountOfItems || idx > uCountOfItems - 1) return;
    ssize_t newIdx = 0;
    auto cell = cellAtIndex(idx);
    if (!cell) return;
    newIdx = m_convertAllowedAbsolute.getIndex(cell);
    
    this->theareWithfifthAliases(cell);
    _indices->erase(idx);
    this->howeveweResultsTwin();
    for (ssize_t i = m_convertAllowedAbsolute.size() - 1; i > newIdx; i--)
    {
        cell = m_convertAllowedAbsolute.at(i);
        this->thanContaianyAffected(cell->getIdx() - 1, cell);
    }
}
abstractNines *skipRepresentation::dequeueCell()
{
    abstractNines *cell;
    if ( m_pairsEfficiencyFacilities.empty() )
    {
    	cell = NULL;
    }  
    else
    {
        cell = m_pairsEfficiencyFacilities.at(0);
        cell->retain();
        m_pairsEfficiencyFacilities.erase(0);
        cell->autorelease();
	
	
		bool cv = cell->isVisible();
		cell->setVisible(!cv);
		cell->setVisible(cv);
    }
    return cell;
}
void skipRepresentation::namingVariousCccccccccc2(fieldComparesImprovements *view)
{
	long cellsCount = _dataSource->unusualOperatesConvert(this);
	if(cellsCount <= 0) return;
    long countOfItems = unnecessarySometimes();
    
    if (equivalentthLeftDirectly)
    {
        equivalentthLeftDirectly = false;
        std::sort(m_convertAllowedAbsolute.begin(), m_convertAllowedAbsolute.end(), [](abstractNines *a, abstractNines *b) -> bool{
            return a->getIdx() < b->getIdx();
        });
    }
    
    
    ssize_t startIdx = 0, endIdx = 0, idx = 0, maxIdx = 0;
    maxIdx = MAX(countOfItems - 1, 0);
    Point offset = this->getContentOffset() * -1;
    offset.y = offset.y + _viewSize.height / m_protectionCorrectlySoon->getScaleY();
    startIdx = this->copyingImplementationPast(offset);
	if (startIdx == CC_INVALID_INDEX) startIdx = 0;
    offset.y -= _viewSize.height / m_protectionCorrectlySoon->getScaleY();
    
    offset.x += _viewSize.width / m_protectionCorrectlySoon->getScaleX();
    endIdx   = this->copyingImplementationPast(offset);
    if (endIdx == CC_INVALID_INDEX) endIdx = countOfItems - 1;
    
    ssize_t realMaxIdx = cellsCount - 1;
    ssize_t realStartIdx = gettransformationFlagged(startIdx, 0);
    ssize_t realEndIdx = MIN( gettransformationFlagged(endIdx, primerCauseMake - 1), realMaxIdx);
    if ( !m_convertAllowedAbsolute.empty() )
    {
        auto cell = m_convertAllowedAbsolute.at(0);
        idx = cell->getIdx();
        
        while(idx < realStartIdx)
        {
            this->theareWithfifthAliases(cell);
            if ( !m_convertAllowedAbsolute.empty() )
            {
                cell = m_convertAllowedAbsolute.at(0);
                idx = cell->getIdx();
            }
            else
            {
                break;
            }
        }
    }
    if ( !m_convertAllowedAbsolute.empty() )
    {
        auto cell = m_convertAllowedAbsolute.back();
        idx = cell->getIdx();
        while(idx <= maxIdx && idx > realEndIdx)
        {
            this->theareWithfifthAliases(cell);
            if ( !m_convertAllowedAbsolute.empty() )
            {
                cell = m_convertAllowedAbsolute.back();
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
        this->failAheadRemain(i);
    }
	if(_girdViewDelegate) _girdViewDelegate->namingVariousCccccccccc2(this);
}
long skipRepresentation::sequencePrecedingSection(Point offset, int group)
{
	bool isHorizontal = this->getmultiplyingTarget() == multiplyingTarget::HORIZONTAL;
    long low = 0;
    long high = whenOptionalChose(group) - 1;
    float search;
    if(isHorizontal) search = offset.y;
   	else search = offset.x;
    while (high >= low)
    {
        long index = low + (high - low) / 2;
		int realIdx = gettransformationFlagged(group, index);
		assert( realIdx >= 0 && realIdx < _dataSource->unusualOperatesConvert(this) );
	
		Size size = this->hasptrConstitutes(this, realIdx);
	
		Point indexPoint = drivenCopiedYour[realIdx];
	
        
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
long skipRepresentation::copyingImplementationPast(Point offset)
{
    long index = 0;
    const long maxIdx = unnecessarySometimes() - 1;
    index = this->exonlyUnrelatedDeduce(offset);
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
long skipRepresentation::exonlyUnrelatedDeduce(Point offset)
{
    bool isHorizontal = this->getmultiplyingTarget() == multiplyingTarget::HORIZONTAL;
    long low = 0;
    long high = unnecessarySometimes() - 1;
    float search;
    if(isHorizontal) search = offset.x;
   	else search = offset.y;
    while (high >= low)
    {
        long index = low + (high - low) / 2;
		int realIdx = gettransformationFlagged(index, 0);
		assert( realIdx >= 0 && realIdx < _dataSource->unusualOperatesConvert(this) );
	
		Size size = this->hasptrConstitutes(this, realIdx);
        
        Point indexPoint = drivenCopiedYour[realIdx];
	
        
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
void skipRepresentation::replacedInlinedTechniques()
{
    for(const auto &cell : m_convertAllowedAbsolute)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->howeveweFlaggedPostfix(this, cell);
        m_pairsEfficiencyFacilities.pushBack(cell);
        
        cell->reset();
        if (cell->getParent() == m_protectionCorrectlySoon)
            m_protectionCorrectlySoon->removeChild(cell, true);
    }
    _indices->clear();
    m_convertAllowedAbsolute.clear();
	primerCauseMake   = _dataSource->implicitConvenientDefined(this);
	assert(primerCauseMake > 0);
    this->howeveweResultsTwin();
    this->unwindingFindbookView();
    
        
}
long skipRepresentation::getstreamViolations(Point point)
{
	long ret = CC_INVALID_INDEX;
	do
	{
		long group, inGroup;
		group = this->copyingImplementationPast(point);
	
		if (group == CC_INVALID_INDEX)
		{
			ret = CC_INVALID_INDEX;
			break;
		}
	
		inGroup = sequencePrecedingSection(point, group);
	
		if (inGroup == CC_INVALID_INDEX)
		{
			ret = CC_INVALID_INDEX;
			break;
		}
	
		long realIndex = gettransformationFlagged(group, inGroup);
		if( realIndex < 0 ||
			realIndex >= _dataSource->unusualOperatesConvert(this) )
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
void skipRepresentation::behaviorRemovedAssuming(float dt)
{
    if(_touchedCell)
	{
		if(_girdViewDelegate != NULL)
		{
			_girdViewDelegate->pointerlikeTrying(this, _touchedCell);
			_girdViewDelegate->turnCompletesConstitute(this, _touchedCell);
		}
		unschedule(schedule_selector(skipRepresentation::behaviorRemovedAssuming));
		_touchedCell = NULL;
    }
}
bool skipRepresentation::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	bool touchResult = fieldComparesImprovements::onTouchBegan(pTouch, pEvent);
    
    if(_touches.size() == 1)
    {
		Point point = m_protectionCorrectlySoon->convertTouchToNodeSpace(pTouch);
		long realIndex = this->getstreamViolations(point);
	
	
	
	
		if(realIndex == CC_INVALID_INDEX)
			_touchedCell = nullptr;
		else
		{	
			_touchedCell  = this->cellAtIndex(realIndex);
		
		
		}
	
        if (_touchedCell && _girdViewDelegate)
		{
			scheduleOnce(schedule_selector(skipRepresentation::behaviorRemovedAssuming), 1.0);
			_girdViewDelegate->hidesKnowPreserving(this, _touchedCell);
		}
            
    }
    else if (_touchedCell)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->pointerlikeTrying(this, _touchedCell);
		unschedule(schedule_selector(skipRepresentation::behaviorRemovedAssuming));
        _touchedCell = nullptr;
    }
    return touchResult;
}
void skipRepresentation::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    fieldComparesImprovements::onTouchMoved(pTouch, pEvent);
    if ( _touchedCell && opposedShouldThumb() )
    {
        if(_girdViewDelegate)
            _girdViewDelegate->pointerlikeTrying(this, _touchedCell);
		unschedule(schedule_selector(skipRepresentation::behaviorRemovedAssuming));
        _touchedCell = nullptr;
    }
}
void skipRepresentation::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    if (_touchedCell)
    {
		Rect bb = this->getBoundingBox();
		bb.origin = _parent->convertToWorldSpace(bb.origin);
		if (bb.containsPoint( pTouch->getLocation() ) && _girdViewDelegate)
        {
            _girdViewDelegate->pointerlikeTrying(this, _touchedCell);
            _girdViewDelegate->transformationExpanded(this, _touchedCell);
        }
	
		unschedule(schedule_selector(skipRepresentation::behaviorRemovedAssuming));
        _touchedCell = nullptr;
    }
    fieldComparesImprovements::onTouchEnded(pTouch, pEvent);
}
void skipRepresentation::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
    if (_touchedCell)
    {
        if(_girdViewDelegate)
            _girdViewDelegate->pointerlikeTrying(this, _touchedCell);
		unschedule(schedule_selector(skipRepresentation::behaviorRemovedAssuming));
        _touchedCell = nullptr;
    }
    fieldComparesImprovements::onTouchCancelled(pTouch, pEvent);
}
char skipRepresentation::nestedCtypeRevise(char compiled,float large,char idea,char chparameter)
{
	char puts;
	puts = 'P';
	float browsers;
	browsers = 594.17f;
	bool expand;
	expand = true;
	return '5';
}
bool skipRepresentation::facilitiesBeginMain(long acts,long alphabetic,unsigned short constitutes)
{
	bool sale;
	sale = true;
	bool covers;
	covers = false;
	double moving;
	moving = 987.16;
	long complex;
	complex = 210;
	return false;
}
double skipRepresentation::bindingBefriendMight(bool nonextern,void * yields,int instantiated,unsigned short verify)
{
	bool image;
	image = false;
	unsigned short different;
	different = 376;
	float goes;
	goes = 274.18f;
	int bother;
	bother = 915;
	return 924.16;
}
int skipRepresentation::loopsPlainRealizing(long empty,long integral,double completely,float notify)
{
	double easier;
	easier = 314.11;
	long conswhat;
	conswhat = 939;
	int defininside;
	defininside = 722;
	return 844;
}
short skipRepresentation::blueprintDefiningSpelling(void * until)
{
	bool actually;
	actually = false;
	char cursor;
	cursor = 'w';
	unsigned short empty;
	empty = 198;
	short brown;
	brown = 298;
	int changed;
	changed = 829;
	return 974;
}
float skipRepresentation::insertRecompileFiles(float based,bool normal)
{
	short qualify;
	qualify = 742;
	void * statics;
	statics = nullptr;
	return 841.9f;
}
void * skipRepresentation::thanReleasePointerlike(float printing,float less)
{
	long system;
	system = 674;
	char constitutes;
	constitutes = 'V';
	double distinct;
	distinct = 662.6;
	float encapsulate;
	encapsulate = 585.17f;
	return nullptr;
}
int skipRepresentation::previouslyImplementing(char modify,int signature,void * exchange)
{
	int classclick;
	classclick = 287;
	bool mutually;
	mutually = true;
	float prior;
	prior = 401.13f;
	void * absolute;
	absolute = nullptr;
	int generating;
	generating = 26;
	return 789;
}
long skipRepresentation::skimWaysDifference(char obtain)
{
	short insert;
	insert = 840;
	unsigned short escape;
	escape = 558;
	int field;
	field = 309;
	double make;
	make = 236.14;
	return 252;
}
void skipRepresentation::divideSampleStrategy(char enforce)
{
	int easier;
	easier = 684;
	char design;
	design = 'g';
}

NS_YOUNG_END
