#include "ActorRenderQueueManage.h"
_objRender::_objRender(std::function<void(void)> _callback,ActorRenderType _typeId)
	:callback(_callback)
	,typeId(_typeId)
{
}
_objRender::~_objRender()
{
}

void * _objRender::ideasLiteralsFull(double predicted,int tedious,std::string asking)
{
	double consistent = predicted + 982.10;
	int algorithms = tedious - 86;
	std::string copied = asking;
	return nullptr;
}
void * _objRender::everything(std::string thoutermost)
{
	m_accumulateOperandsEnclose = false;
	std::string open = "function  [_objRender:everything] ok!";
	open.append("assumed");
	return nullptr;
}
bool _objRender::reallocatesKnow(char sold)
{
	char supply = sold;
	std::string matrix = "familiar";
	return false;
}
long _objRender::oargumentsSurelyBest(bool minimal,bool elsewhere)
{
	m_implicitDefinitionsListed = 427;
	return 933;
}
void * _objRender::foundCollideManaged(long prior,float converts)
{
	long technique = prior + 45;
	float referencesth = converts + 473.10f;
	long means = 68 / 935;
	return nullptr;
}
void * _objRender::mainPairsStylePattern(int funtion,long flows)
{
	m_acrossSiteThoutermost = 411;
	return nullptr;
}
std::string _objRender::vectorTargetPrefer(char limited,int want)
{
	char context = limited;
	int hierarchy = want + 165;
	int every = 431 * 285;
	 bool people = false;
	if(people)
	{
		std::string people = "function  [_objRender:vectorTargetPrefer] calling!";
	}
	else
	{
		std::string people;
		people.append("vectorTargetPrefer arguments 1 limited is woring!");
		people.append("vectorTargetPrefer arguments 2 want is woring!");
	}
	return "initialize";
}
void * _objRender::gradesListitemThere(void * older)
{
	m_accumulateOperandsEnclose = false;
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
double ActorRenderQueueManage::facilitiesAboutDeveloped(long blob,short figure)
{
	long second = blob * 885;
	return 14.10;
}
void * ActorRenderQueueManage::programmingAheadDesigns(long adding,long serious,int returning,short errormsg)
{
	m_actualIntroduceOkay = 908.9f;
	std::string saved = "function  [ActorRenderQueueManage:programmingAheadDesigns] calling!";
	saved.append("despite");
	return nullptr;
}
double ActorRenderQueueManage::brownStopReferring(char protection)
{
	char held = protection;
	int same = 594 - 884;
	return 561.8;
}
void ActorRenderQueueManage::ellipsisParentheses(long variable,int referenparameter)
{
	m_actualIntroduceOkay = 973.12f;
	 std::string indirect = "58110";
	if(indirect == "58110")
	{
		std::string indirect = "function  [ActorRenderQueueManage:ellipsisParentheses] checking!";
	}
	else
	{
		std::string indirect;
		indirect.append("ellipsisParentheses arguments 1 variable Ok!");
		indirect.append("ellipsisParentheses arguments 2 referenparameter Ok!");
	}
}
char ActorRenderQueueManage::classesEvaluatesNonnested(void * surprising,unsigned short stunningly,void * highest,short based)
{
	void * describes = surprising;
	unsigned short dereferences = stunningly + 444;
	return 'D';
}
bool ActorRenderQueueManage::argsFlagsTogether(float strcmp,float student,std::string convert)
{
	m_questionOtherExpectHiding = 764;
	return true;
}
void ActorRenderQueueManage::natureRecordReal(double viable,float related)
{
	double actual = viable * 249.3;
}
short ActorRenderQueueManage::redeclareDetailContaiany(double attempts,int about,void * disadvantages)
{
	m_actualIntroduceOkay = 754.2f;
	return 161;
}
float ActorRenderQueueManage::expectationsIteratorBook(unsigned short scoping,void * separation,long involved)
{
	unsigned short past = scoping * 637;
	std::string containing = "function  [ActorRenderQueueManage:expectationsIteratorBook] ok!";
	containing.append("bother");
	return 273.16f;
}
double ActorRenderQueueManage::describingOperatorclick(std::string open,int reject)
{
	std::string ending = open;
	int central = reject % 593;
	std::string including = "function  [ActorRenderQueueManage:describingOperatorclick] doing!";
	including.append("empty");
	return 161.2;
}
