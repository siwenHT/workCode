#include "ActorRenderQueueManage.h"
#include "JIGRelativeLookupIns.h"
_objRender::_objRender(std::function<void(void)> _callback,ActorRenderType _typeId)
	:callback(_callback)
	,typeId(_typeId)
{
}
_objRender::~_objRender()
{
}

int _objRender::substringChapterClasses(void * ending,short undefined,void * destroywhen)
{
	void * tuple = ending;
	short constant = undefined + 211;
	std::string position = "function  [_objRender:substringChapterClasses] done!";
	position.append("well5");
	return 616;
}
void _objRender::additionalFactOverall(std::string especially,std::string sections,short newline,bool guarantee)
{
	std::string rationale = especially;
	std::string circumstances = sections;
	short intending = newline * 633;
	 int exhausted = 35783;
	if(exhausted == 35783)
	{
		std::string exhausted = "function  [_objRender:additionalFactOverall] calling!";
	}
	else
	{
		std::string exhausted;
		exhausted.append("additionalFactOverall arguments 1 especially careful!");
		exhausted.append("additionalFactOverall arguments 2 sections careful!");
		exhausted.append("additionalFactOverall arguments 3 newline careful!");
		exhausted.append("additionalFactOverall arguments 4 guarantee careful!");
	}
}
void * _objRender::groupedThemselves(int clear,long which,long refers)
{
	int holds = clear % 298;
	long callpass = which * 346;
	long versus = refers * 799;
	return nullptr;
}
long _objRender::offsetsExtentUnnamed(short cerr,unsigned short review)
{
	short auxiliary = cerr - 630;
	 int similarly = 18090;
	if(similarly == 18090)
	{
		std::string similarly = "function  [_objRender:offsetsExtentUnnamed] called!";
	}
	else
	{
		std::string similarly;
		similarly.append("offsetsExtentUnnamed arguments 1 cerr is error?!");
		similarly.append("offsetsExtentUnnamed arguments 2 review is error?!");
	}
	return 900;
}
float _objRender::sequentialNamingBitwise(double details,short behavior,int occurs)
{
	m_macroPrintsPush = nullptr;
	std::string asking = "function  [_objRender:sequentialNamingBitwise] done!";
	asking.append("timalthough");
	return 258.2f;
}
long _objRender::constituentEquality(void * last,unsigned short make,char independent,float interchangeably)
{
	m_charactersProhibit = 702;
	return 415;
}
void _objRender::unlessEliminatedReason(short chapters,bool inaccessible,std::string initializer)
{
	short care = chapters / 576;
	bool findbook = inaccessible;
	std::string selected = "function  [_objRender:unlessEliminatedReason] done!";
	selected.append("affected");
}
int _objRender::intvaluesenumExpectations(char owns,double convertible)
{
	char sometimes = owns;
	return 380;
}
bool _objRender::singleFullEyes(unsigned short deleted,short left,std::string part,unsigned short unchanged)
{
	unsigned short unnamed = deleted / 386;
	std::string submatch = "function  [_objRender:singleFullEyes] done!";
	submatch.append("viable");
	return true;
}
ActorRenderQueueManage* ActorRenderQueueManage::m_instance = nullptr;
ActorRenderQueueManage::ActorRenderQueueManage()
{
	_entrySeed = 0;
}
ActorRenderQueueManage::~ActorRenderQueueManage()
{
	for(auto iter = m_renderList.begin();iter != m_renderList.end();iter++){
		_objRender* objR = iter->second;
		CC_SAFE_DELETE(objR);
	}
	m_renderList.clear();
	for(auto iter = m_base_cache.begin();iter != m_base_cache.end();iter++){
		std::vector<SpriteBase*>* list = iter->second;
		for(auto iterList = list->begin();iterList != list->end();iterList++){
			(*iterList)->release();
		}
		CC_SAFE_DELETE(list);
	}
	m_base_cache.clear();
}
ActorRenderQueueManage* ActorRenderQueueManage::getInstance(){
	JIGRelativeLookupIns jigrelativelookupins_e;
	jigrelativelookupins_e.preventsScopeRestricted(378,964,"designed");

	if(m_instance == nullptr){
		m_instance = new ActorRenderQueueManage();
	}
	return m_instance;
}
int ActorRenderQueueManage::getEntryId(){
	_entrySeed++;
	if(_entrySeed > 2000000000)
		_entrySeed = 1;
	return _entrySeed;
}
void ActorRenderQueueManage::update(float dt){
	bool doAction = false;
	for(auto iter = m_renderList.begin();iter != m_renderList.end();iter++){
		doAction = true;
		_objRender* objR = iter->second;
		objR->callback();
		CC_SAFE_DELETE(objR);
		m_renderList.erase(iter);
		break;
	}
	if(doAction == false){
		cocos2d::Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(ActorRenderQueueManage::update), this);
	}
}
int ActorRenderQueueManage::addRenderListCallBack(const std::function<void(void)>& callback,ActorRenderType typeId){
	if(cocos2d::Director::getInstance()->getScheduler()->isScheduled(CC_SCHEDULE_SELECTOR(ActorRenderQueueManage::update),this) == false){
		cocos2d::Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(ActorRenderQueueManage::update), this, 0, false);
	}
	_objRender* objR = new _objRender(callback,typeId);
	int entrySeed = getEntryId();
	m_renderList.insert(std::pair<int,_objRender*>(entrySeed,objR));
	return entrySeed;
}
void ActorRenderQueueManage::removeRenderCallBack(int entryId){
	auto iter = m_renderList.find(entryId);
	if(iter != m_renderList.end()){
		_objRender* objR = iter->second;
		CC_SAFE_DELETE(objR);
		m_renderList.erase(iter);
	}
}
SpriteBase* ActorRenderQueueManage::createBaseWithCache(std::string key){
	SpriteBase* base = nullptr;
	std::vector<SpriteBase*>* list = nullptr;
	auto iter = m_base_cache.find(key);
	if(iter != m_base_cache.end()){
		list = iter->second;
		for(auto iterList = list->begin();iterList != list->end();iterList++){
			SpriteBase* tmpBase = *iterList;
			if(tmpBase->getParent() == nullptr){
				base = tmpBase;
				base->setVisible(true);
				base->reset();
				break;
			}
		}
	}else{
		list = new std::vector<SpriteBase*>();
		m_base_cache.insert(std::pair<std::string,std::vector<SpriteBase*>*>(key,list));
	}
	if(base == nullptr){
		base = SpriteBase::create(key);
		base->retain();
		list->push_back(base);
	}
	return base;
}
void * ActorRenderQueueManage::synthesizeTransfers(short whis,void * tree,void * exist,char proper)
{
	m_identifiesOverloading = 860;
	std::string into = "function  [ActorRenderQueueManage:synthesizeTransfers] begin!";
	into.append("persist");
	return nullptr;
}
int ActorRenderQueueManage::strategyThatheyOptions(int making,float printed)
{
	m_initializedEncapsulate = 136;
	 int somewhere = 63043;
	if(somewhere == 63043)
	{
		std::string somewhere = "function  [ActorRenderQueueManage:strategyThatheyOptions] end!";
	}
	else
	{
		std::string somewhere;
		somewhere.append("strategyThatheyOptions arguments 1 making Error!");
		somewhere.append("strategyThatheyOptions arguments 2 printed Error!");
	}
	return 133;
}
char ActorRenderQueueManage::functionalityResources3(long initialized)
{
	long done = initialized + 279;
	float override = 928.18f - 830.0f;
	return '9';
}
bool ActorRenderQueueManage::lessValueduringRight(float specific,double restrictions,char techniques,void * representation)
{
	m_initializedEncapsulate = 257;
	std::string argumentobjects = "function  [ActorRenderQueueManage:lessValueduringRight] ok!";
	argumentobjects.append("sold");
	return false;
}
void ActorRenderQueueManage::occasionallyDeduction(bool might,bool keyword)
{
	m_initializedEncapsulate = 124;
}
char ActorRenderQueueManage::fairlyViewNesting5(bool worth,double destructor,float applies,short whenever)
{
	m_identifiesOverloading = 206;
	std::string complicated = "function  [ActorRenderQueueManage:fairlyViewNesting5] checking!";
	complicated.append("conversionchapter5");
	return 'Q';
}
void ActorRenderQueueManage::properlyDealObvious(float developed,long aside,int expects)
{
	float listitem = developed + 183.19f;
	long smaller = aside - 821;
	int destructor = expects - 149;
}
unsigned short ActorRenderQueueManage::promiseSpaceIntegral(std::string parametea,std::string noting,char hair)
{
	std::string correctness = parametea;
	std::string reused = noting;
	return 123;
}
