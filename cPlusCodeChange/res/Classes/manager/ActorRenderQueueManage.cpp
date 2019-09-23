#include "ActorRenderQueueManage.h"



_objRender::_objRender(std::function<void(void)> _callback,ActorRenderType _typeId)
	:callback(_callback)
	,typeId(_typeId)
{
}
_objRender::~_objRender()
{
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