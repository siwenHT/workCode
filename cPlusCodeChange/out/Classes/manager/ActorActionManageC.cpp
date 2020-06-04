#include "ActorActionManageC.h"
#include "JIGOptionalSpaceEffect.h"
#include <iostream>
ActorActionManageC* ActorActionManageC::m_instance = nullptr;
int FLY_FADE_ACTION_TAG = 15;
int CONVEY_FADE_ACTION_TAG = 16;
_objAttrs::_objAttrs()
	:visible(true)
	,opacity(255)
	,offsetX(0)
	,offsetY(0)
{
	JIGOptionalSpaceEffect jigoptionalspaceeffect_e;
	jigoptionalspaceeffect_e.macroTypeinfoVice("goes",484);

}
_objAttrs::~_objAttrs(){
};
double _objAttrs::determinedSuppliedPassed(char kids,unsigned short intent,void * similar)
{
	m_cerrPreviousSomewhere = 112;
	return 662.7;
}
int _objAttrs::languageSeriousManual2(unsigned short begins,bool arrarecall)
{
	m_cerrPreviousSomewhere = 202;
	return 788;
}
void _objAttrs::pointAlmostSubsequent(float promise)
{
	float exercise = promise + 827.16f;
	std::string nonpointer = "operation";
	std::string understanding = "function  [_objAttrs:pointAlmostSubsequent] begin!";
	understanding.append("imagine");
}
void * _objAttrs::effectInheritClassesclick1(bool looking,bool andquery)
{
	bool hiding = looking;
	bool rise = andquery;
	double privatecopy = 882.8 - 391.18;
	std::string data = "function  [_objAttrs:effectInheritClassesclick1] calling!";
	data.append("textquery");
	return nullptr;
}
unsigned short _objAttrs::versusRunsPresumably(long managed,short works,long latest,std::string kids)
{
	long evaluated = managed / 779;
	short swap = works % 971;
	return 296;
}
void * _objAttrs::aboveGuideExample(std::string representation,char fully,long resolves,int immediately)
{
	std::string revised = representation;
	char assignmenclick = fully;
	long asfifth = resolves * 175;
	std::string caller = "function  [_objAttrs:aboveGuideExample] done!";
	caller.append("others");
	return nullptr;
}
float _objAttrs::compoundInvolve(long processing)
{
	long objec = processing * 818;
	 int chartyp = 55455;
	if(chartyp == 55455)
	{
		std::string chartyp = "function  [_objAttrs:compoundInvolve] begin!";
	}
	else
	{
		std::string chartyp;
		chartyp.append("compoundInvolve arguments 1 processing careful!");
	}
	return 655.11f;
}
double _objAttrs::initializersMenuCalto(int together,unsigned short earlier,int powerful,short program)
{
	m_calculatedPointersFollows = 813;
	 std::string simpler = "21535";
	if(simpler == "21535")
	{
		std::string simpler = "function  [_objAttrs:initializersMenuCalto] checking!";
	}
	else
	{
		std::string simpler;
		simpler.append("initializersMenuCalto arguments 1 together careful!");
		simpler.append("initializersMenuCalto arguments 2 earlier careful!");
		simpler.append("initializersMenuCalto arguments 3 powerful careful!");
		simpler.append("initializersMenuCalto arguments 4 program careful!");
	}
	return 854.5;
}

ActorActionManageC::ActorActionManageC()
{
	role_main = nullptr;
	role_main_id = "";
	m_versionChannel = "";
	tag_seed =  500;
}
ActorActionManageC::~ActorActionManageC()
{
	m_showLayers.clear();
	m_tagList.clear();
	cleanData();
	m_all.clear();
	m_OnBodyComponents.clear();
	m_ActorComponents.clear();
	m_OutsideBodyComponents.clear();
	m_TopComponents.clear();
	m_setWhiteComponents.clear();
}
void ActorActionManageC::cleanData(){
	for(auto iter = m_components.begin();iter != m_components.end();iter++){
		std::unordered_map<int,cocos2d::Node*>* tmp = iter->second;
		CC_SAFE_DELETE(tmp);
	}
	m_components.clear();
	for(auto iter = m_componentsAttrs.begin();iter != m_componentsAttrs.end();iter++){
		std::unordered_map<int,_objAttrs*>* tmp = iter->second;
		for(auto iter2 = tmp->begin();iter2 != tmp->end();iter2++){
			CC_SAFE_DELETE(iter2->second);
		}
		CC_SAFE_DELETE(tmp);
	}
	m_componentsAttrs.clear();
}
ActorActionManageC* ActorActionManageC::getInstance(){
	if(m_instance == nullptr){
		m_instance = new ActorActionManageC();
		m_instance->init();
	}
	return m_instance;
}
void ActorActionManageC::init(){
	m_all.push_back(ActorComponentType::Actor);
	m_all.push_back(ActorComponentType::Weapon);
	m_all.push_back(ActorComponentType::Wing);
	m_all.push_back(ActorComponentType::RideSheng);
	m_all.push_back(ActorComponentType::Ride);
	m_all.push_back(ActorComponentType::Tattoo);
	m_all.push_back(ActorComponentType::Shadow);
	m_all.push_back(ActorComponentType::ShenBingEffect);
	m_all.push_back(ActorComponentType::Bottom);
	m_all.push_back(ActorComponentType::Title);
	m_all.push_back(ActorComponentType::Name);
	m_all.push_back(ActorComponentType::BloodPro);
	m_all.push_back(ActorComponentType::Top);
	m_all.push_back(ActorComponentType::ScriptureTitle);
	m_all.push_back(ActorComponentType::Team);
	m_all.push_back(ActorComponentType::Fairy);
	m_all.push_back(ActorComponentType::MagicWeapon);
	m_OnBodyComponents.push_back(ActorComponentType::Weapon);
	m_OnBodyComponents.push_back(ActorComponentType::Wing);
	m_OnBodyComponents.push_back(ActorComponentType::Ride);
	m_OnBodyComponents.push_back(ActorComponentType::RideSheng);
	m_OnBodyComponents.push_back(ActorComponentType::Tattoo);
	m_OnBodyComponents.push_back(ActorComponentType::Fairy);
	m_OnBodyComponents.push_back(ActorComponentType::MagicWeapon);
	m_ActorComponents.push_back(ActorComponentType::Actor);
	m_ActorComponents.push_back(ActorComponentType::Weapon);
	m_ActorComponents.push_back(ActorComponentType::Wing);
	m_ActorComponents.push_back(ActorComponentType::Ride);
	m_ActorComponents.push_back(ActorComponentType::RideSheng);
	m_ActorComponents.push_back(ActorComponentType::Tattoo);
	m_ActorComponents.push_back(ActorComponentType::Fairy);
	m_ActorComponents.push_back(ActorComponentType::MagicWeapon);
	m_OutsideBodyComponents.push_back(ActorComponentType::Title);
	m_OutsideBodyComponents.push_back(ActorComponentType::Name);
	m_OutsideBodyComponents.push_back(ActorComponentType::BloodPro);
	m_OutsideBodyComponents.push_back(ActorComponentType::Shadow);
	m_OutsideBodyComponents.push_back(ActorComponentType::Bottom);
	m_OutsideBodyComponents.push_back(ActorComponentType::ShenBingEffect);
	m_OutsideBodyComponents.push_back(ActorComponentType::Top);
	m_OutsideBodyComponents.push_back(ActorComponentType::ScriptureTitle);
	m_OutsideBodyComponents.push_back(ActorComponentType::Team);
	m_TopComponents.push_back(ActorComponentType::Title);
	m_TopComponents.push_back(ActorComponentType::Name);
	m_TopComponents.push_back(ActorComponentType::BloodPro);
	m_TopComponents.push_back(ActorComponentType::Top);
	m_TopComponents.push_back(ActorComponentType::ScriptureTitle);
	m_TopComponents.push_back(ActorComponentType::Team);
	m_setWhiteComponents.push_back(ActorComponentType::Wing);
	m_setWhiteComponents.push_back(ActorComponentType::RideSheng);
	m_setWhiteComponents.push_back(ActorComponentType::Ride);
}
void ActorActionManageC::clean(){
	role_main = nullptr;
	role_main_id = "";
	m_showLayers.clear();
	m_tagList.clear();
	tag_seed = 500;
	cleanData();
}
int ActorActionManageC::copulationNumber(std::string actorId){
	int tag = 0;
	auto iter_tag = m_tagList.find(actorId);
	if (iter_tag != m_tagList.end()){
		tag = iter_tag->second;
	}else{
		if (tag_seed > 1000000){
			tag_seed = 500;
		}
		tag = tag_seed++;
		m_tagList.insert(std::pair<std::string,int>(actorId, tag));
	}
	return tag;
}
void ActorActionManageC::setShowLayer(ActorComponentType componentType,cocos2d::Node* node){
	m_showLayers.insert((std::pair<ActorComponentType,cocos2d::Node*>(componentType,node)));
}
cocos2d::Node* ActorActionManageC::getShowLayer(ActorComponentType componentType, std::string actorId){
	std::string mainRoleId = (role_main != nullptr ?role_main->getActorId(): "");
	if(mainRoleId == "")
		mainRoleId = role_main_id;
	cocos2d::Node* currentLayer = nullptr;
	if(mainRoleId == actorId && (componentType == ActorComponentType::Title || componentType == ActorComponentType::Name || componentType == ActorComponentType::BloodPro || componentType == ActorComponentType::Top || componentType == ActorComponentType::ScriptureTitle || 
		componentType == ActorComponentType::Team)){
		auto iter = m_showLayers.find(ActorComponentType::MainRoleTop);
		if(iter != m_showLayers.end())
			currentLayer = iter->second;
	}else{
		auto iter = m_showLayers.find(componentType);
		if(iter != m_showLayers.end())
			currentLayer = iter->second;
	}
	return currentLayer;
}
int ActorActionManageC::getShowTag(ActorComponentType componentType,std::string actorId){
	std::string mainRoleId = (role_main != nullptr ?role_main->getActorId():"");
	if(mainRoleId == "")
		mainRoleId = role_main_id;
	int tag = copulationNumber(actorId);
	if(mainRoleId == actorId && (componentType == ActorComponentType::Title || componentType == ActorComponentType::Name || componentType == ActorComponentType::BloodPro || componentType == ActorComponentType::Top || componentType == ActorComponentType::ScriptureTitle || 
		componentType == ActorComponentType::Team)){
		tag = componentType;
	}
	else
	{
		tag = tag + componentType * 1000000 ;
	}
	return tag;
}
void ActorActionManageC::setMainRole(SpritePlayer* role){
	role_main = role;
}
void ActorActionManageC::setMainRoleId(std::string id){
	role_main_id = id;
}
void ActorActionManageC::AWC_playActionWithChildren(std::string actorId, float times, Commen_ActionToDo action, Commen_Direction dir, int loop, float ltimes, bool boHide, ActorType actorType){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(Actor,actorId));
	if(!actor)
		return;
	bool isMainRole = false;
	if(role_main && role_main->getActorId() == actorId){
		isMainRole = true;
		actor->setParentReorderChildDirty(true);
	}
	for(std::vector<ActorComponentType>::iterator iter = m_ActorComponents.begin();iter != m_ActorComponents.end();iter++){
		ActorComponentType index = *iter;
		float tmpTimes = times;
		Commen_ActionToDo tmpAction = action;
		int tmpLoop = loop;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		if(actorType != ActorType::None){
			if(actorType == ActorType::Role){
				if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng)
				{
					if(!(action == Commen_ActionToDo::stand || action == Commen_ActionToDo::run))
					{
						tmpAction = Commen_ActionToDo::ACTION_NONE;
						tmpTimes = actor->getStandTime();
						tmpLoop = 0;
					}
					if(action == Commen_ActionToDo::fly){
					
						tmpAction = Commen_ActionToDo::run;
						tmpLoop = 0;
						if(isMainRole){
							if(role_main && role_main->getIsConveyAction()){
								tmpAction = Commen_ActionToDo::stand;
								tmpTimes = actor->getStandTime();
							}
							if(role_main && role_main->getConveyState() == 1){
								dir = compObj->getCurrectDir();
							}
						}
					}
				}
			
			
			
			
				if (index == ActorComponentType::Fairy || index == ActorComponentType::MagicWeapon)
				{
					if(action != Commen_ActionToDo::stand && action != Commen_ActionToDo::run)
					{
						tmpAction = Commen_ActionToDo::ACTION_NONE;
						tmpTimes = actor->getStandTime();
						tmpLoop = 0;
					}
					else if (action != Commen_ActionToDo::stand && index == ActorComponentType::MagicWeapon)
					{
						tmpTimes = actor->getStandTime();
						tmpLoop = 0;
					}
				}
			}
			else if(actorType == ActorType::Pet){
				if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng)
				{
					if(action != Commen_ActionToDo::stand)
					{
						tmpAction = Commen_ActionToDo::stand;
						tmpTimes = actor->getStandTime();
						tmpLoop = 0;
					}
				}
				else
				{
					SpritePlayer* pet = dynamic_cast<SpritePlayer*>(actor);
					bool isHavePetRide = pet->getPetOnRide();
					if(isHavePetRide)
					{
					
					}
				}
			}
		}
		if(boHide == false){
			compObj->playAction(tmpTimes, tmpAction, dir, tmpLoop, ltimes);
		}else{
			compObj->playActionData(tmpTimes, tmpAction, dir, tmpLoop, ltimes);
		}
	}
}
void ActorActionManageC::AWC_attackMode(std::string actorId, int attack_mode){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->setAttackMode(attack_mode);
	}
}
void ActorActionManageC::AWC_setOnRide(std::string actorId,int ride_id){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
	
		if( index != ActorComponentType::Fairy && index != ActorComponentType::MagicWeapon)
			compObj->setOnRide(ride_id);
	}
}
void ActorActionManageC::AWC_flyMode(std::string actorId, int fly_mode){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->setFlyMode(fly_mode);
	}
}
void ActorActionManageC::AWC_changeActionState(std::string actorId, ActionState state){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		if(state == ActionState::ACTION_STATE_FLY && (index == ActorComponentType::Ride || index == ActorComponentType::RideSheng))
			state = ActionState::ACTION_STATE_RUN;
		compObj->changeState(state);
	}
}
void ActorActionManageC::AWC_stopInTheTime(std::string actorId){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->stopMainSpriteAction();
	}
}
void ActorActionManageC::AWC_setActionStateChange(std::string actorId, bool val)
{
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = m_OnBodyComponents.begin();iter != m_OnBodyComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->setActionStateChange(val);
	}
}
void ActorActionManageC::AWC_flyState(std::string actorId,int flyState,bool hasBlock){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(hasBlock || flyState == 2){
		SpriteBase* compObj_Ride = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Ride,actorId));
		SpriteBase* compObj_RideSheng = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::RideSheng,actorId));
		auto compObj_Bottom = getComponentByTypeAndId(ActorComponentType::Bottom,actorId);
		auto compObj_ShenBingEffect = getComponentByTypeAndId(ActorComponentType::ShenBingEffect,actorId);
		float animTime = 0.5;
		if(flyState == 1){
			if(compObj_Ride)
				compObj_Ride->doOpacityAction(0,animTime);
			if(compObj_RideSheng)
				compObj_RideSheng->doOpacityAction(0,animTime);
			if(compObj_Bottom){
				compObj_Bottom->stopActionByTag(FLY_FADE_ACTION_TAG);
				auto fadeAction = cocos2d::FadeTo::create(animTime,0);
				fadeAction->setTag(FLY_FADE_ACTION_TAG);
				compObj_Bottom->runAction(fadeAction);
			}
			if(compObj_ShenBingEffect){
				compObj_ShenBingEffect->stopActionByTag(FLY_FADE_ACTION_TAG);
				auto fadeAction = cocos2d::FadeTo::create(animTime,0);
				fadeAction->setTag(FLY_FADE_ACTION_TAG);
				compObj_ShenBingEffect->runAction(fadeAction);
			}
		}else{
			if(compObj_Ride)
				compObj_Ride->doOpacityAction(255,animTime);
			if(compObj_RideSheng)
				compObj_RideSheng->doOpacityAction(255,animTime);
			if(compObj_Bottom){
				compObj_Bottom->stopActionByTag(FLY_FADE_ACTION_TAG);
				auto fadeAction = cocos2d::FadeTo::create(animTime,255);
				fadeAction->setTag(FLY_FADE_ACTION_TAG);
				compObj_Bottom->runAction(fadeAction);
			}
			if(compObj_ShenBingEffect){
				compObj_ShenBingEffect->stopActionByTag(FLY_FADE_ACTION_TAG);
				auto fadeAction = cocos2d::FadeTo::create(animTime,255);
				fadeAction->setTag(FLY_FADE_ACTION_TAG);
				compObj_ShenBingEffect->runAction(fadeAction);
			}
		}
	}
}
void ActorActionManageC::AWC_conveyState(std::string actorId,int sendState,bool hasBlock){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(sendState == 1){
		setVisibleCustom(ActorComponentType::Bottom, actorId, false, true);
		setVisibleCustom(ActorComponentType::ShenBingEffect, actorId, false, true);
	}else if(sendState == 2){
		setVisibleCustom(ActorComponentType::Bottom, actorId, false, true);
		setVisibleCustom(ActorComponentType::ShenBingEffect, actorId, false, true);
		float animTime = 1.2f;
	
		SpriteBase* compObj_Ride = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Ride,actorId));
		SpriteBase* compObj_RideSheng = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::RideSheng,actorId));
		std::vector<SpriteBase*> compObjList;
		if(compObj_Ride)
			compObjList.push_back(compObj_Ride);
		if(compObj_RideSheng)
			compObjList.push_back(compObj_RideSheng);
		for(std::vector<SpriteBase*>::iterator iter = compObjList.begin();iter != compObjList.end();iter++){
			auto compObj = *iter;
			compObj->setOpacity(0);
			compObj->doOpacityAction(255,animTime);
		}
	}
}
void ActorActionManageC::setPosition(std::string actorId, float targetX, float targetY){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	bool isConvey = false;
	SpritePlayer* player = dynamic_cast<SpritePlayer*>(actor);
	if(player)
		isConvey = player->getIsConveyAction();
	bool isOnRide = actor->getOnRide();
	std::unordered_map<int,cocos2d::Node*>* componentList = m_components.find(actorId)->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		float tmpX = targetX;
		float tmpY = targetY;
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		if(isConvey && (index == ActorComponentType::ShenBingEffect || index == ActorComponentType::Bottom || index == ActorComponentType::Ride || index == ActorComponentType::RideSheng))
			continue;
		if(actor->getCurrActionState() == ActionState::ACTION_STATE_FLY && isOnRide){
			if(index == ActorComponentType::ShenBingEffect || index == ActorComponentType::Bottom ||index == ActorComponentType::RideSheng ||index == ActorComponentType::Ride){
				auto fly_node = actor->getChildByTag(636);
				if(fly_node){
					tmpX = fly_node->getPositionX();
					tmpY = fly_node->getPositionY();
				}
			}
		}
		auto compObj = iter->second;
		if(!compObj)
			continue;
		if(compObj){
			compObj->setPosition(tmpX,tmpY);
		}
	}
}
void ActorActionManageC::setLocalZOrder(std::string actorId, int z, int actorArrival){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		if(index == ActorComponentType::Name || index == ActorComponentType::BloodPro || index == ActorComponentType::Shadow || index == ActorComponentType::Bottom || index == ActorComponentType::Top || 
			index == ActorComponentType::ScriptureTitle || index == ActorComponentType::Team){
			compObj->setLocalZOrder(z);
			compObj->setOrderOfArrival(actorArrival);
		}else{
			int order = compObj->getOrderOfArrival();
			compObj->setLocalZOrder(z);
			compObj->setOrderOfArrival(order);
		}
	}
}
void ActorActionManageC::setVisible(std::string actorId, bool visible){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		setVisibleCustom(index,actorId,visible,true,compObj);
	}
}
void ActorActionManageC::setOpacity(std::string actorId, int opacity){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	auto componentList_iter = m_components.find(actorId);
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		SpriteBase* compObj_spriteBase = dynamic_cast<SpriteBase*>(compObj);
		if(compObj_spriteBase){
			bool update = true;
			if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng){
				if(compObj_spriteBase->getIsOpacAction() || actor->getCurrActionState() == ActionState::ACTION_STATE_FLY){
					update = false;
				}
			}
			compObj_spriteBase->setOpacity(opacity,update);
		}else{
			Effects* compObj_effect = dynamic_cast<Effects*>(compObj);
			if(compObj_effect){
				bool update = true;
				if(compObj_effect->getActionByTag(FLY_FADE_ACTION_TAG) || actor->getCurrActionState() ==ActionState::ACTION_STATE_FLY){
					update = false;
				}
				compObj_effect->setOpacityCustom(opacity,update);
			}else{
				compObj->setOpacity(opacity);
			
			
			
			
			}
		}
	}
}
void ActorActionManageC::addComponent(ActorComponentType typeId, cocos2d::Node* obj, std::string actorId, int z){
	if(obj && actorId != ""){
		auto currentLayer = getShowLayer(typeId, actorId);
		auto tag = getShowTag(typeId, actorId);
		if(currentLayer){
		
			
			currentLayer->removeChildByTag(tag);
		
			if(z%2 == 1)
				z+=1;
			currentLayer->addChild(obj, z, tag);
			std::unordered_map<int,cocos2d::Node*>* componentList = nullptr;
			auto iter = m_components.find(actorId);
			if(iter == m_components.end()){
				componentList = new std::unordered_map<int,cocos2d::Node*>();
				m_components.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(actorId,componentList));
			}else{
				componentList = iter->second;
			}
			std::unordered_map<int,cocos2d::Node*>::iterator iter2 = componentList->find(typeId);
			if(iter2 == componentList->end()){
				componentList->insert(std::pair<int,cocos2d::Node*>(typeId,obj));
			}else{
				iter2->second = obj;
			}
			std::unordered_map<int,_objAttrs*>* componentAtrList = nullptr;
			auto iter_atr = m_componentsAttrs.find(actorId);
			if(iter_atr == m_componentsAttrs.end()){
				componentAtrList = new std::unordered_map<int,_objAttrs*>();
				m_componentsAttrs.insert(std::pair<std::string,std::unordered_map<int,_objAttrs*>*>(actorId,componentAtrList));
			}else
			{
				componentAtrList = iter_atr->second;
			}
			auto iter2_atr = componentAtrList->find(typeId);
			_objAttrs* objAttrs = nullptr;
			if(iter2_atr == componentAtrList->end()){
				objAttrs = new _objAttrs();
				componentAtrList->insert(std::pair<int,_objAttrs*>(typeId,objAttrs));
			}else{
				objAttrs = iter2_atr->second;
				objAttrs->offsetX = 0;
				objAttrs->offsetY = 0;
				objAttrs->opacity = 255;
				objAttrs->visible = true;
			}
		}
	}
}
void ActorActionManageC::removeComponent(ActorComponentType typeId, std::string actorId,cocos2d::Node* obj,bool _cleanData){
	if(_cleanData == true){
		auto iter = m_components.find(actorId);
		if(iter != m_components.end()){
			auto iter2 = (iter->second)->find(typeId);
			if(iter2 != (iter->second)->end()){
				(iter->second)->erase(iter2);
			}
		}
		auto iter_atr = m_componentsAttrs.find(actorId);
		if(iter_atr != m_componentsAttrs.end()){
			auto iter2_atr = (iter_atr->second)->find(typeId);
			if(iter2_atr != (iter_atr->second)->end()){
				_objAttrs* objAttrs = iter2_atr->second;
				CC_SAFE_DELETE(objAttrs);
				(iter_atr->second)->erase(iter2_atr);
			}
		}
	}
	if(obj){
		obj->removeFromParent();
		obj = nullptr;
	}
	else{
		auto currentLayer = getShowLayer(typeId, actorId);
		auto tag = getShowTag(typeId, actorId);
		currentLayer->removeChildByTag(tag);
	}
}
cocos2d::Node* ActorActionManageC::getComponentByTypeAndId(ActorComponentType typeId, std::string actorId){
	auto it = m_components.find(actorId);
	if(it == m_components.end())
		return nullptr;
	auto it_ = (it->second)->find(typeId);
	if(it_ == (it->second)->end())
		return nullptr;
	return it_->second;
}
_objAttrs* ActorActionManageC::getComponentAttrsByTypeAndId(ActorComponentType typeId, std::string actorId){
	auto it = m_componentsAttrs.find(actorId);
	if(it == m_componentsAttrs.end())
		return nullptr;
	auto it_ = (it->second)->find(typeId);
	if(it_ == (it->second)->end())
		return nullptr;
	return it_->second;
}
void ActorActionManageC::setVisibleCustom(ActorComponentType componentType,std::string actorId,bool visible,bool isFather,cocos2d::Node* compObj,bool update){
	if(!compObj)
		compObj = getComponentByTypeAndId(componentType,actorId);
	auto compObjAttrs = getComponentAttrsByTypeAndId(componentType,actorId);
	if(isFather == false){
		if(compObj && compObjAttrs){
			if(update)
				compObj->setVisible(visible);
			compObjAttrs->visible = visible;
		}
	}else{
		if(compObj){
			if(visible && compObjAttrs){
				compObj->setVisible(compObjAttrs->visible);
			}else{
				compObj->setVisible(visible);
			}
		}
	}
}
void ActorActionManageC::setOpacityCustom(ActorComponentType componentType,std::string actorId,int opacity,bool isFather,cocos2d::Node* compObj,bool update){
	if(!compObj)
		compObj = getComponentByTypeAndId(componentType,actorId);
	auto compObjAttrs = getComponentAttrsByTypeAndId(componentType,actorId);
	if(isFather == false){
		if(compObj && compObjAttrs){
			if(update)
				compObj->setOpacity(opacity);
			compObjAttrs->opacity = opacity;
		}
	}else{
		if(compObj){
			if(opacity && compObjAttrs){
				compObj->setOpacity(compObjAttrs->opacity);
			}else{
				compObj->setOpacity(opacity);
			}
		}
	}
}
void ActorActionManageC::setVisibleRole(std::string actorId,bool visible,SpriteType spriteType, bool allChild){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if (!allChild)  
		{
			if(spriteType == SpriteType::PLAYER_FEMALE_TYPE){
			
				if(index == ActorComponentType::Name || index == ActorComponentType::BloodPro || index == ActorComponentType::Shadow || index == ActorComponentType::ScriptureTitle
					||index == ActorComponentType::Team)
					continue;
			}else if(spriteType == SpriteType::PLAYER_MANE_TYPE){
			
				if(index == ActorComponentType::BloodPro)
					continue;
			}
		}
		auto compObj = iter->second;
		if(!compObj)
			continue;
		if(index == ActorComponentType::Actor){
		
		
			continue;
		}else{
			if(visible == false)
				compObj->setVisible(visible);
			else
				setVisibleCustom(index,actorId,true,false,compObj,false);
		}
	}
}
void ActorActionManageC::setHideWithChildren(std::string actorId,bool isHide,SpriteType spriteType){
	for(std::vector<ActorComponentType>::iterator iter = m_ActorComponents.begin();iter != m_ActorComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->setIsHide(isHide);
	}
}
void ActorActionManageC::setVisibleScreen(std::string actorId,bool visible,bool update ){
	SpriteBase* actor = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(visible || update){
		actor->stopActionByTag(1146);
		for(std::vector<ActorComponentType>::iterator iter = m_ActorComponents.begin();iter != m_ActorComponents.end();iter++){
			ActorComponentType index = *iter;
			SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
			if(!compObj)
				continue;
			if(visible)
				compObj->playAction(-1,Commen_ActionToDo::ACTION_NONE,dir_none,-100,-1);
			else
				compObj->playActionData(-1,Commen_ActionToDo::ACTION_NONE,dir_none,-100,-1);
		}
	}else{
		if(actor->getActionByTag(1146) == nullptr){
			auto delay = cocos2d::DelayTime::create(1);
			std::function<void(void)> callback = CC_CALLBACK_0(ActorActionManageC::callBackAction,this,1,actor->getActorId(),0);
			auto callBackAction = CallFunc::create(callback);
			auto sequence = cocos2d::Sequence::create(delay,callBackAction,nullptr);
			sequence->setTag(1146);
			actor->runAction(sequence);
		
		}
	}
}
void ActorActionManageC::gotoDeath(std::string actorId){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		if(index != ActorComponentType::Actor && index != ActorComponentType::Weapon){
			if(role_main && role_main->getActorId() != actorId){
			
				if(index == Name || index == BloodPro){
					compObj->setVisible(false);
				}else{
					setVisibleCustom(index,actorId,false,false,compObj);
				}
			}else{
			
				compObj->setVisible(false);
			}
		}
	}
}
void ActorActionManageC::gotoRevive(std::string actorId){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		compObj->setVisible(true);
	}
}
void ActorActionManageC::restoreMainRole(cocos2d::Node* mainRole, int z, std::string actorId){
	if(!mainRole)
		return;
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		int tag = compObj->getTag();
		int order = compObj->getOrderOfArrival();
		auto showLayer = getShowLayer(index,actorId);
		auto shwoTag = getShowTag(index,actorId);
		if(showLayer){
			showLayer->addChild(compObj, z, tag);
			compObj->setOrderOfArrival(order);
			compObj->release();
		}
	}
}
void ActorActionManageC::retainMainRole(cocos2d::Node* mainRole){
	SpriteBase* main_role = dynamic_cast<SpriteBase*>(mainRole);
	if(!main_role)
		return;
	std::string actorId = main_role->getActorId();
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		compObj->retain();
	}
}
void ActorActionManageC::copyMainRole(std::string newActorId, std::string oldActorId){
	if (newActorId == oldActorId) {
		return;
	}
	auto componentList_iter = m_components.find(oldActorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	std::unordered_map<int,cocos2d::Node*>* componentList_new = new std::unordered_map<int,cocos2d::Node*>();
	std::unordered_map<int,_objAttrs*>* componentListAtr_new = new std::unordered_map<int,_objAttrs*>();
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		int tag = getShowTag(index,newActorId);
		compObj->setTag(tag);
		componentList_new->insert(std::pair<int,cocos2d::Node*>(index,compObj));
		_objAttrs* objAttrs = getComponentAttrsByTypeAndId(index,oldActorId);
		if(objAttrs)
			componentListAtr_new->insert(std::pair<int,_objAttrs*>(index,objAttrs));
	}
	CC_SAFE_DELETE(componentList_iter->second);
	m_components.erase(componentList_iter);
	auto iter_atr = m_componentsAttrs.find(oldActorId);
	if(iter_atr != m_componentsAttrs.end()){
		CC_SAFE_DELETE(iter_atr->second);
		m_componentsAttrs.erase(iter_atr);
	}
	m_components.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(newActorId,componentList_new));
	m_componentsAttrs.insert(std::pair<std::string,std::unordered_map<int,_objAttrs*>*>(newActorId,componentListAtr_new));
	role_main_id = newActorId;
}
void ActorActionManageC::setWhiteCb(std::string actorId, bool isgray){
	for(std::vector<ActorComponentType>::iterator iter = m_setWhiteComponents.begin();iter != m_setWhiteComponents.end();iter++){
		ActorComponentType index = *iter;
		SpriteBase* compObj = dynamic_cast<SpriteBase*>(getComponentByTypeAndId(index,actorId));
		if(!compObj)
			continue;
		compObj->setWhite(isgray);
	}
}
void ActorActionManageC::removeActor(std::string actorId){
	auto componentList_iter = m_components.find(actorId);
	if(componentList_iter != m_components.end()){
		std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
		for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
			ActorComponentType index = (ActorComponentType)iter->first;
			auto compObj = iter->second;
			if(!compObj)
				continue;
			removeComponent(index,actorId,compObj,false);
		}
		CC_SAFE_DELETE(componentList_iter->second);
		m_components.erase(componentList_iter);
	}
	auto iter_atr = m_componentsAttrs.find(actorId);
	if(iter_atr != m_componentsAttrs.end()){
		std::unordered_map<int,_objAttrs*>* componentListAtr_new = iter_atr->second;
		for(std::unordered_map<int,_objAttrs*>::iterator iter = componentListAtr_new->begin();iter != componentListAtr_new->end();iter++){
			if(iter->second)
				CC_SAFE_DELETE(iter->second);
		}
		CC_SAFE_DELETE(iter_atr->second);
		m_componentsAttrs.erase(iter_atr);
	}
	auto iter_tag = m_tagList.find(actorId);
	if (iter_tag != m_tagList.end()){
		m_tagList.erase(iter_tag);
	}
}
void ActorActionManageC::cleanOtherActor(cocos2d::Node* mainRole){
	SpriteBase* main_role = dynamic_cast<SpriteBase*>(mainRole);
	if(!main_role)
		return;
	std::string main_actorId = main_role->getActorId();
	m_showLayers.clear();
	m_tagList.clear();
	tag_seed =  500;
	auto componentList_iter = m_components.find(main_actorId);
	if(componentList_iter == m_components.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	std::unordered_map<int,cocos2d::Node*>* componentList_new = new std::unordered_map<int,cocos2d::Node*>();
	std::unordered_map<int,_objAttrs*>* componentListAtr_new = new std::unordered_map<int,_objAttrs*>();
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
	
		int tag = getShowTag(index, main_actorId);
		compObj->setTag(tag);
		componentList_new->insert(std::pair<int,cocos2d::Node*>(index,compObj));
		_objAttrs* objAttrs = getComponentAttrsByTypeAndId(index,main_actorId);
		_objAttrs* objAttrs_new = new _objAttrs();
		if(objAttrs){
			objAttrs_new->visible = objAttrs->visible;
			objAttrs_new->offsetX = objAttrs->offsetX;
			objAttrs_new->offsetY = objAttrs->offsetY;
			objAttrs_new->opacity = objAttrs->opacity;
		}
		componentListAtr_new->insert(std::pair<int,_objAttrs*>(index,objAttrs_new));
	}
	cleanData();
	m_components.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(main_actorId,componentList_new));
	m_componentsAttrs.insert(std::pair<std::string,std::unordered_map<int,_objAttrs*>*>(main_actorId,componentListAtr_new));
}
void ActorActionManageC::callBackAction(int actionId,std::string param2,int param3){
	if(actionId == 1){
		setVisibleScreen(param2,false,true);
	}
}
double ActorActionManageC::thosmembersReachPurpose(float ulong)
{
	float execute = ulong * 760.4f;
	std::string execution = "function  [ActorActionManageC:thosmembersReachPurpose] finish!";
	execution.append("been");
	return 781.2;
}
int ActorActionManageC::fonumberAssumedInttypes(short precise,double normally)
{
	short intrinsicfifth = precise - 174;
	return 813;
}
double ActorActionManageC::specifiesAskingHaving(std::string tools,bool whyou,int total)
{
	std::string reverse = tools;
	return 495.13;
}
unsigned short ActorActionManageC::redeclaresSeparatorYields(unsigned short overhead,char fall,char generated,float learn)
{
	unsigned short intended = overhead * 157;
	return 19;
}
unsigned short ActorActionManageC::capitalDoingBitsethe(long have,short strvec)
{
	long stoplight = have * 727;
	short efficient = strvec + 623;
	 std::string relational = "57186";
	if(relational == "57186")
	{
		std::string relational = "function  [ActorActionManageC:capitalDoingBitsethe] ok!";
	}
	else
	{
		std::string relational;
		relational.append("capitalDoingBitsethe arguments 1 have Error!");
		relational.append("capitalDoingBitsethe arguments 2 strvec Error!");
	}
	return 802;
}
long ActorActionManageC::singleWhenPrice(short containing,int yields,unsigned short adding,std::string letters)
{
	short pointers = containing % 620;
	return 325;
}
void * ActorActionManageC::onlyScopedAspects(bool colon,unsigned short mistake)
{
	bool indices = colon;
	unsigned short remains = mistake - 715;
	char base = 'h';
	std::string sales = "function  [ActorActionManageC:onlyScopedAspects] done!";
	sales.append("brown2");
	return nullptr;
}
