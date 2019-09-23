#include "ActorRenderQueueManage.h"
#include "pointsInitializing.h"
_objRender::_objRender(std::function<void(void)> _callback,ActorRenderType _typeId)
	:callback(_callback)
	,typeId(_typeId)
{
}
_objRender::~_objRender()
{
}

float _objRender::representationIndexing(double prvoid,double enough,unsigned short saved,int some)
{
	double cout = prvoid + 938.12;
	double evaluate = enough + 502.15;
	unsigned short mube = saved - 646;
	return 522.2f;
}
short _objRender::hairComputingAssociative2(bool available,float assignmenclick,long after,float care)
{
	m_whisWorriesReturning = 50;
	return 845;
}
long _objRender::expressionPushGuarantee(long explains)
{
	m_whisWorriesReturning = 238;
	return 807;
}
void _objRender::scopesBothCoveredRefer(short shows,bool relational,bool nonpublic,short full)
{
	m_wregexPrivatecopyAttempt = 582;
}
void _objRender::headerStillBuild(float relying,long just)
{
	float escape = relying + 645.2f;
	long reject = just + 384;
	long temporary = 384 % 718;
}
void * _objRender::supplyRelevantNeed(double intvalues,double deduce)
{
	double theif = intvalues - 636.13;
	double parametea = deduce + 402.5;
	bool area = true;
	return nullptr;
}
short _objRender::arrayIndicatedPerform(void * alphabetic)
{
	void * placed = alphabetic;
	return 441;
}
void _objRender::conceptuallyEasiest5(int becomes,float four,double accessible,long constitute)
{
	int suspended = becomes + 369;
	float store = four - 582.11f;
	double nonmember = accessible - 464.2;
}
void _objRender::tendBooksPreviously(char gets,float dereferences)
{
	m_whisWorriesReturning = 728;
}
void _objRender::neededEmptyBuild(unsigned short preferred,long files,unsigned short will,int designing)
{
	pointsInitializing pointsinitializing_e;
	pointsinitializing_e.referenparameter(510.7f,352.20f,714.0,557);

	m_whisWorriesReturning = 24;
}
void * _objRender::nodefaultHoweveweReturns(short such,short allocation,double continues)
{
	short generally = such % 408;
	short simply = allocation - 337;
	return nullptr;
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
char ActorRenderQueueManage::mustBegunMattersWhose(void * runtime,unsigned short fetch)
{
	void * some = runtime;
	return 'f';
}
float ActorRenderQueueManage::tokensPutsSpace(int where,long unable,long encapsulates)
{
	int immediately = where / 945;
	long minimal = unable - 688;
	return 129.14f;
}
float ActorRenderQueueManage::commonElemeisWord(short programs,unsigned short original,float image)
{
	short algorithms = programs + 143;
	return 575.1f;
}
unsigned short ActorRenderQueueManage::purposesExactCombine(double easier)
{
	m_violationsFullMoreovesome = 248;
	return 587;
}
char ActorRenderQueueManage::freindLimitationAgree(long facilities,char copied,void * there)
{
	long designing = facilities + 220;
	char named = copied;
	return 'U';
}
char ActorRenderQueueManage::objectsthSequencesRise(unsigned short simple,bool book)
{
	unsigned short skip = simple / 209;
	bool above = book;
	bool violate = true;
	return 'd';
}
bool ActorRenderQueueManage::specifierPreventTotal(int relative,float ofile,unsigned short flows,void * meaning)
{
	m_tokensSeenWord = 'k';
	return true;
}
