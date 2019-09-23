#include "mubeReplacement.h"
#include <iostream>
mubeReplacement* mubeReplacement::m_worrySomewhat = nullptr;
int FLY_FADE_ACTION_TAG = 15;
int CONVEY_FADE_ACTION_TAG = 16;
completelyInfrequently::completelyInfrequently()
	:visible(true)
	,opacity(255)
	,offsetX(0)
	,offsetY(0)
{
}
completelyInfrequently::~completelyInfrequently(){
};
short completelyInfrequently::equalsReferencesOften(void * templates,int rather,unsigned short three)
{
	float recompiling;
	recompiling = 187.11f;
	return 716;
}
bool completelyInfrequently::convenientMovesEqual(double changed)
{
	void * chain;
	chain = nullptr;
	char responses;
	responses = '7';
	short becomes;
	becomes = 873;
	return true;
}
char completelyInfrequently::referenparameterWithout(int sections,void * types)
{
	int another;
	another = 992;
	return 'Z';
}
bool completelyInfrequently::makingSurprisingSometimes(unsigned short come,short friends)
{
	char remaining;
	remaining = 'P';
	bool vector;
	vector = true;
	char insert;
	insert = '8';
	float prefix;
	prefix = 686.13f;
	double nontype;
	nontype = 759.0;
	return true;
}
long completelyInfrequently::patternsInfrequently(short resolved)
{
	char needs;
	needs = '5';
	return 287;
}
void * completelyInfrequently::pairsAddedLoop5(short literals,short search,char classclick)
{
	float assumed;
	assumed = 384.18f;
	int blobptr;
	blobptr = 355;
	bool usually;
	usually = true;
	long useful;
	useful = 677;
	return nullptr;
}
double completelyInfrequently::modelSometimesSuccessful(float following,int looking,bool evaluated)
{
	char stored;
	stored = 'K';
	double resulting;
	resulting = 975.0;
	long delegates;
	delegates = 507;
	short selects;
	selects = 112;
	return 43.13;
}

mubeReplacement::mubeReplacement()
{
	role_main = nullptr;
	m_visibleThgenerates = "";
	destroysLeadsFamiliar = "";
	tag_seed =  500;
}
mubeReplacement::~mubeReplacement()
{
	occasionallyErrormsg.clear();
	m_tagList.clear();
	cleanData();
	m_all.clear();
	reflectNontemplate.clear();
	elemeisLabeledSafely.clear();
	involveHidesDetermined.clear();
	m_worryNonstatic.clear();
	m_synthesizedLimited.clear();
}
void mubeReplacement::cleanData(){
	for(auto iter = timeReferenparameter.begin();iter != timeReferenparameter.end();iter++){
		std::unordered_map<int,cocos2d::Node*>* tmp = iter->second;
		CC_SAFE_DELETE(tmp);
	}
	timeReferenparameter.clear();
	for(auto iter = m_instantiationsNothing.begin();iter != m_instantiationsNothing.end();iter++){
		std::unordered_map<int,completelyInfrequently*>* tmp = iter->second;
		for(auto iter2 = tmp->begin();iter2 != tmp->end();iter2++){
			CC_SAFE_DELETE(iter2->second);
		}
		CC_SAFE_DELETE(tmp);
	}
	m_instantiationsNothing.clear();
}
mubeReplacement* mubeReplacement::getInstance(){
	if(m_worrySomewhat == nullptr){
		m_worrySomewhat = new mubeReplacement();
		m_worrySomewhat->init();
	}
	return m_worrySomewhat;
}
void mubeReplacement::init(){
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
	reflectNontemplate.push_back(ActorComponentType::Weapon);
	reflectNontemplate.push_back(ActorComponentType::Wing);
	reflectNontemplate.push_back(ActorComponentType::Ride);
	reflectNontemplate.push_back(ActorComponentType::RideSheng);
	reflectNontemplate.push_back(ActorComponentType::Tattoo);
	reflectNontemplate.push_back(ActorComponentType::Fairy);
	reflectNontemplate.push_back(ActorComponentType::MagicWeapon);
	elemeisLabeledSafely.push_back(ActorComponentType::Actor);
	elemeisLabeledSafely.push_back(ActorComponentType::Weapon);
	elemeisLabeledSafely.push_back(ActorComponentType::Wing);
	elemeisLabeledSafely.push_back(ActorComponentType::Ride);
	elemeisLabeledSafely.push_back(ActorComponentType::RideSheng);
	elemeisLabeledSafely.push_back(ActorComponentType::Tattoo);
	elemeisLabeledSafely.push_back(ActorComponentType::Fairy);
	elemeisLabeledSafely.push_back(ActorComponentType::MagicWeapon);
	involveHidesDetermined.push_back(ActorComponentType::Title);
	involveHidesDetermined.push_back(ActorComponentType::Name);
	involveHidesDetermined.push_back(ActorComponentType::BloodPro);
	involveHidesDetermined.push_back(ActorComponentType::Shadow);
	involveHidesDetermined.push_back(ActorComponentType::Bottom);
	involveHidesDetermined.push_back(ActorComponentType::ShenBingEffect);
	involveHidesDetermined.push_back(ActorComponentType::Top);
	involveHidesDetermined.push_back(ActorComponentType::ScriptureTitle);
	involveHidesDetermined.push_back(ActorComponentType::Team);
	m_worryNonstatic.push_back(ActorComponentType::Title);
	m_worryNonstatic.push_back(ActorComponentType::Name);
	m_worryNonstatic.push_back(ActorComponentType::BloodPro);
	m_worryNonstatic.push_back(ActorComponentType::Top);
	m_worryNonstatic.push_back(ActorComponentType::ScriptureTitle);
	m_worryNonstatic.push_back(ActorComponentType::Team);
	m_synthesizedLimited.push_back(ActorComponentType::Wing);
	m_synthesizedLimited.push_back(ActorComponentType::RideSheng);
	m_synthesizedLimited.push_back(ActorComponentType::Ride);
}
void mubeReplacement::clean(){
	role_main = nullptr;
	m_visibleThgenerates = "";
	occasionallyErrormsg.clear();
	m_tagList.clear();
	tag_seed = 500;
	cleanData();
}
int mubeReplacement::freindLooksDisadvantages2(std::string actorId){
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
void mubeReplacement::setdesignerRvalueAbility4(ActorComponentType componentType,cocos2d::Node* node){
	occasionallyErrormsg.insert((std::pair<ActorComponentType,cocos2d::Node*>(componentType,node)));
}
cocos2d::Node* mubeReplacement::getdesignerRvalueAbility4(ActorComponentType componentType, std::string actorId){
	std::string mainRoleId = (role_main != nullptr ?role_main->getrankedClauseHowevewe(): "");
	if(mainRoleId == "")
		mainRoleId = m_visibleThgenerates;
	cocos2d::Node* currentLayer = nullptr;
	if(mainRoleId == actorId && (componentType == ActorComponentType::Title || componentType == ActorComponentType::Name || componentType == ActorComponentType::BloodPro || componentType == ActorComponentType::Top || componentType == ActorComponentType::ScriptureTitle || 
		componentType == ActorComponentType::Team)){
		auto iter = occasionallyErrormsg.find(ActorComponentType::updatesPersistSpecifying3Top);
		if(iter != occasionallyErrormsg.end())
			currentLayer = iter->second;
	}else{
		auto iter = occasionallyErrormsg.find(componentType);
		if(iter != occasionallyErrormsg.end())
			currentLayer = iter->second;
	}
	return currentLayer;
}
int mubeReplacement::getmismatchedCharbits(ActorComponentType componentType,std::string actorId){
	std::string mainRoleId = (role_main != nullptr ?role_main->getrankedClauseHowevewe():"");
	if(mainRoleId == "")
		mainRoleId = m_visibleThgenerates;
	int tag = freindLooksDisadvantages2(actorId);
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
void mubeReplacement::setupdatesPersistSpecifying3(assumeApproachEmbodies* role){
	role_main = role;
}
void mubeReplacement::setfragmentSynthesized(std::string id){
	m_visibleThgenerates = id;
}
void mubeReplacement::lookProvidedDestroys(std::string actorId, float times, soonAlongMemberwise action, accessedIntroductory dir, int loop, float ltimes, bool boHide, templatesStartTuples actorType){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(Actor,actorId));
	if(!actor)
		return;
	bool isupdatesPersistSpecifying3 = false;
	if(role_main && role_main->getrankedClauseHowevewe() == actorId){
		isupdatesPersistSpecifying3 = true;
		actor->setprvoidExtensioindicating(true);
	}
	for(std::vector<ActorComponentType>::iterator iter = elemeisLabeledSafely.begin();iter != elemeisLabeledSafely.end();iter++){
		ActorComponentType index = *iter;
		float tmpTimes = times;
		soonAlongMemberwise tmpAction = action;
		int tmpLoop = loop;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		if(actorType != templatesStartTuples::None){
			if(actorType == templatesStartTuples::Role){
				if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng)
				{
					if(!(action == soonAlongMemberwise::stand || action == soonAlongMemberwise::run))
					{
						tmpAction = soonAlongMemberwise::ACTION_NONE;
						tmpTimes = actor->getthreeLoopsOperatingMatter();
						tmpLoop = 0;
					}
					if(action == soonAlongMemberwise::fly){
					
						tmpAction = soonAlongMemberwise::run;
						tmpLoop = 0;
						if(isupdatesPersistSpecifying3){
							if(role_main && role_main->getoperatesTriesConstitute()){
								tmpAction = soonAlongMemberwise::stand;
								tmpTimes = actor->getthreeLoopsOperatingMatter();
							}
							if(role_main && role_main->getexpressionasInvolveCode() == 1){
								dir = compObj->getinstantiatingBindRegular();
							}
						}
					}
				}
			
			
			
			
				if (index == ActorComponentType::Fairy || index == ActorComponentType::MagicWeapon)
				{
					if(action != soonAlongMemberwise::stand && action != soonAlongMemberwise::run)
					{
						tmpAction = soonAlongMemberwise::ACTION_NONE;
						tmpTimes = actor->getthreeLoopsOperatingMatter();
						tmpLoop = 0;
					}
					else if (action != soonAlongMemberwise::stand && index == ActorComponentType::MagicWeapon)
					{
						tmpTimes = actor->getthreeLoopsOperatingMatter();
						tmpLoop = 0;
					}
				}
			}
			else if(actorType == templatesStartTuples::Pet){
				if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng)
				{
					if(action != soonAlongMemberwise::stand)
					{
						tmpAction = soonAlongMemberwise::stand;
						tmpTimes = actor->getthreeLoopsOperatingMatter();
						tmpLoop = 0;
					}
				}
				else
				{
					assumeApproachEmbodies* pet = dynamic_cast<assumeApproachEmbodies*>(actor);
					bool isHavePetRide = pet->getsalesWereTree2();
					if(isHavePetRide)
					{
					
					}
				}
			}
		}
		if(boHide == false){
			compObj->bitsManyUnlike(tmpTimes, tmpAction, dir, tmpLoop, ltimes);
		}else{
			compObj->imageRevisedCaltoFront(tmpTimes, tmpAction, dir, tmpLoop, ltimes);
		}
	}
}
void mubeReplacement::programmersRangeFocusMost(std::string actorId, int attack_mode){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->setpatternResultNodefault(attack_mode);
	}
}
void mubeReplacement::worthNodefault(std::string actorId,int ride_id){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
	
		if( index != ActorComponentType::Fairy && index != ActorComponentType::MagicWeapon)
			compObj->setOnRide(ride_id);
	}
}
void mubeReplacement::earlierCreateFrom(std::string actorId, int fly_mode){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->setprogrammingQualifying(fly_mode);
	}
}
void mubeReplacement::algorithmWorksBraceAend4(std::string actorId, pushBoundthat state){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		if(state == pushBoundthat::ACTION_STATE_FLY && (index == ActorComponentType::Ride || index == ActorComponentType::RideSheng))
			state = pushBoundthat::ACTION_STATE_RUN;
		compObj->cerrResultsThroughCeases(state);
	}
}
void mubeReplacement::descriptionKnowsShow5(std::string actorId){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->removedDetailsKids();
	}
}
void mubeReplacement::drivenSimplyPreserving(std::string actorId, bool val)
{
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	for(std::vector<ActorComponentType>::iterator iter = reflectNontemplate.begin();iter != reflectNontemplate.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->setembodiesSolveReplaces(val);
	}
}
void mubeReplacement::shownRestrictedThroughout(std::string actorId,int flyState,bool hasBlock){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(hasBlock || flyState == 2){
		addingRelies* compObj_Ride = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Ride,actorId));
		addingRelies* compObj_RideSheng = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::RideSheng,actorId));
		auto compObj_Bottom = getvaluesTellsProgramming(ActorComponentType::Bottom,actorId);
		auto compObj_ShenBingEffect = getvaluesTellsProgramming(ActorComponentType::ShenBingEffect,actorId);
		float animTime = 0.5;
		if(flyState == 1){
			if(compObj_Ride)
				compObj_Ride->failsQuizaMistake(0,animTime);
			if(compObj_RideSheng)
				compObj_RideSheng->failsQuizaMistake(0,animTime);
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
				compObj_Ride->failsQuizaMistake(255,animTime);
			if(compObj_RideSheng)
				compObj_RideSheng->failsQuizaMistake(255,animTime);
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
void mubeReplacement::mostWorthIndicating(std::string actorId,int sendState,bool hasBlock){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(sendState == 1){
		settechniqueGenerates(ActorComponentType::Bottom, actorId, false, true);
		settechniqueGenerates(ActorComponentType::ShenBingEffect, actorId, false, true);
	}else if(sendState == 2){
		settechniqueGenerates(ActorComponentType::Bottom, actorId, false, true);
		settechniqueGenerates(ActorComponentType::ShenBingEffect, actorId, false, true);
		float animTime = 1.2f;
	
		addingRelies* compObj_Ride = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Ride,actorId));
		addingRelies* compObj_RideSheng = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::RideSheng,actorId));
		std::vector<addingRelies*> compObjList;
		if(compObj_Ride)
			compObjList.push_back(compObj_Ride);
		if(compObj_RideSheng)
			compObjList.push_back(compObj_RideSheng);
		for(std::vector<addingRelies*>::iterator iter = compObjList.begin();iter != compObjList.end();iter++){
			auto compObj = *iter;
			compObj->setOpacity(0);
			compObj->failsQuizaMistake(255,animTime);
		}
	}
}
void mubeReplacement::setPosition(std::string actorId, float targetX, float targetY){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	bool isConvey = false;
	assumeApproachEmbodies* player = dynamic_cast<assumeApproachEmbodies*>(actor);
	if(player)
		isConvey = player->getoperatesTriesConstitute();
	bool isOnRide = actor->getOnRide();
	std::unordered_map<int,cocos2d::Node*>* componentList = timeReferenparameter.find(actorId)->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		float tmpX = targetX;
		float tmpY = targetY;
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		if(isConvey && (index == ActorComponentType::ShenBingEffect || index == ActorComponentType::Bottom || index == ActorComponentType::Ride || index == ActorComponentType::RideSheng))
			continue;
		if(actor->getspecializedComplication() == pushBoundthat::ACTION_STATE_FLY && isOnRide){
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
void mubeReplacement::setLocalZOrder(std::string actorId, int z, int actorArrival){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
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
void mubeReplacement::setVisible(std::string actorId, bool visible){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		settechniqueGenerates(index,actorId,visible,true,compObj);
	}
}
void mubeReplacement::setOpacity(std::string actorId, int opacity){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	auto componentList_iter = timeReferenparameter.find(actorId);
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if(index == ActorComponentType::Actor)
			continue;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		addingRelies* compObj_spriteBase = dynamic_cast<addingRelies*>(compObj);
		if(compObj_spriteBase){
			bool update = true;
			if(index == ActorComponentType::Ride || index == ActorComponentType::RideSheng){
				if(compObj_spriteBase->getdefininsideWideThink() || actor->getspecializedComplication() == pushBoundthat::ACTION_STATE_FLY){
					update = false;
				}
			}
			compObj_spriteBase->setOpacity(opacity,update);
		}else{
			knewOverheadSupplied* compObj_effect = dynamic_cast<knewOverheadSupplied*>(compObj);
			if(compObj_effect){
				bool update = true;
				if(compObj_effect->getActionByTag(FLY_FADE_ACTION_TAG) || actor->getspecializedComplication() ==pushBoundthat::ACTION_STATE_FLY){
					update = false;
				}
				compObj_effect->setsupportedComputingRemoved(opacity,update);
			}else{
				compObj->setOpacity(opacity);
			
			
			
			
			}
		}
	}
}
void mubeReplacement::nonexistentAccessible(ActorComponentType typeId, cocos2d::Node* obj, std::string actorId, int z){
	if(obj && actorId != ""){
		auto currentLayer = getdesignerRvalueAbility4(typeId, actorId);
		auto tag = getmismatchedCharbits(typeId, actorId);
		if(currentLayer){
		
			
			currentLayer->removeChildByTag(tag);
		
			if(z%2 == 1)
				z+=1;
			currentLayer->addChild(obj, z, tag);
			std::unordered_map<int,cocos2d::Node*>* componentList = nullptr;
			auto iter = timeReferenparameter.find(actorId);
			if(iter == timeReferenparameter.end()){
				componentList = new std::unordered_map<int,cocos2d::Node*>();
				timeReferenparameter.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(actorId,componentList));
			}else{
				componentList = iter->second;
			}
			std::unordered_map<int,cocos2d::Node*>::iterator iter2 = componentList->find(typeId);
			if(iter2 == componentList->end()){
				componentList->insert(std::pair<int,cocos2d::Node*>(typeId,obj));
			}else{
				iter2->second = obj;
			}
			std::unordered_map<int,completelyInfrequently*>* componentAtrList = nullptr;
			auto iter_atr = m_instantiationsNothing.find(actorId);
			if(iter_atr == m_instantiationsNothing.end()){
				componentAtrList = new std::unordered_map<int,completelyInfrequently*>();
				m_instantiationsNothing.insert(std::pair<std::string,std::unordered_map<int,completelyInfrequently*>*>(actorId,componentAtrList));
			}else
			{
				componentAtrList = iter_atr->second;
			}
			auto iter2_atr = componentAtrList->find(typeId);
			completelyInfrequently* objAttrs = nullptr;
			if(iter2_atr == componentAtrList->end()){
				objAttrs = new completelyInfrequently();
				componentAtrList->insert(std::pair<int,completelyInfrequently*>(typeId,objAttrs));
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
void mubeReplacement::leadsDoesndifferRest2(ActorComponentType typeId, std::string actorId,cocos2d::Node* obj,bool _cleanData){
	if(_cleanData == true){
		auto iter = timeReferenparameter.find(actorId);
		if(iter != timeReferenparameter.end()){
			auto iter2 = (iter->second)->find(typeId);
			if(iter2 != (iter->second)->end()){
				(iter->second)->erase(iter2);
			}
		}
		auto iter_atr = m_instantiationsNothing.find(actorId);
		if(iter_atr != m_instantiationsNothing.end()){
			auto iter2_atr = (iter_atr->second)->find(typeId);
			if(iter2_atr != (iter_atr->second)->end()){
				completelyInfrequently* objAttrs = iter2_atr->second;
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
		auto currentLayer = getdesignerRvalueAbility4(typeId, actorId);
		auto tag = getmismatchedCharbits(typeId, actorId);
		currentLayer->removeChildByTag(tag);
	}
}
cocos2d::Node* mubeReplacement::getvaluesTellsProgramming(ActorComponentType typeId, std::string actorId){
	auto it = timeReferenparameter.find(actorId);
	if(it == timeReferenparameter.end())
		return nullptr;
	auto it_ = (it->second)->find(typeId);
	if(it_ == (it->second)->end())
		return nullptr;
	return it_->second;
}
completelyInfrequently* mubeReplacement::getseparatelyJustPeople(ActorComponentType typeId, std::string actorId){
	auto it = m_instantiationsNothing.find(actorId);
	if(it == m_instantiationsNothing.end())
		return nullptr;
	auto it_ = (it->second)->find(typeId);
	if(it_ == (it->second)->end())
		return nullptr;
	return it_->second;
}
void mubeReplacement::settechniqueGenerates(ActorComponentType componentType,std::string actorId,bool visible,bool isFather,cocos2d::Node* compObj,bool update){
	if(!compObj)
		compObj = getvaluesTellsProgramming(componentType,actorId);
	auto compObjAttrs = getseparatelyJustPeople(componentType,actorId);
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
void mubeReplacement::setsupportedComputingRemoved(ActorComponentType componentType,std::string actorId,int opacity,bool isFather,cocos2d::Node* compObj,bool update){
	if(!compObj)
		compObj = getvaluesTellsProgramming(componentType,actorId);
	auto compObjAttrs = getseparatelyJustPeople(componentType,actorId);
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
void mubeReplacement::setrealizeFollowedPointed4(std::string actorId,bool visible,wantedConvertibleGroup spriteType, bool allChild){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		if (!allChild)  
		{
			if(spriteType == wantedConvertibleGroup::PLAYER_FEMALE_TYPE){
			
				if(index == ActorComponentType::Name || index == ActorComponentType::BloodPro || index == ActorComponentType::Shadow || index == ActorComponentType::ScriptureTitle
					||index == ActorComponentType::Team)
					continue;
			}else if(spriteType == wantedConvertibleGroup::PLAYER_MANE_TYPE){
			
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
				settechniqueGenerates(index,actorId,true,false,compObj,false);
		}
	}
}
void mubeReplacement::setstoringRuleOtherwise(std::string actorId,bool isHide,wantedConvertibleGroup spriteType){
	for(std::vector<ActorComponentType>::iterator iter = elemeisLabeledSafely.begin();iter != elemeisLabeledSafely.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->setIsHide(isHide);
	}
}
void mubeReplacement::setshownRatherInitially(std::string actorId,bool visible,bool update ){
	addingRelies* actor = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(ActorComponentType::Actor,actorId));
	if(!actor)
		return;
	if(visible || update){
		actor->stopActionByTag(1146);
		for(std::vector<ActorComponentType>::iterator iter = elemeisLabeledSafely.begin();iter != elemeisLabeledSafely.end();iter++){
			ActorComponentType index = *iter;
			addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
			if(!compObj)
				continue;
			if(visible)
				compObj->bitsManyUnlike(-1,soonAlongMemberwise::ACTION_NONE,dir_none,-100,-1);
			else
				compObj->imageRevisedCaltoFront(-1,soonAlongMemberwise::ACTION_NONE,dir_none,-100,-1);
		}
	}else{
		if(actor->getActionByTag(1146) == nullptr){
			auto delay = cocos2d::DelayTime::create(1);
			std::function<void(void)> callback = CC_CALLBACK_0(mubeReplacement::westoreWidthTypes,this,1,actor->getrankedClauseHowevewe(),0);
			auto westoreWidthTypes = CallFunc::create(callback);
			auto sequence = cocos2d::Sequence::create(delay,westoreWidthTypes,nullptr);
			sequence->setTag(1146);
			actor->runAction(sequence);
		
		}
	}
}
void mubeReplacement::gotoDeath(std::string actorId){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		if(index != ActorComponentType::Actor && index != ActorComponentType::Weapon){
			if(role_main && role_main->getrankedClauseHowevewe() != actorId){
			
				if(index == Name || index == BloodPro){
					compObj->setVisible(false);
				}else{
					settechniqueGenerates(index,actorId,false,false,compObj);
				}
			}else{
			
				compObj->setVisible(false);
			}
		}
	}
}
void mubeReplacement::errorsMimicScope(std::string actorId){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
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
void mubeReplacement::curlyAmongEvaluating(cocos2d::Node* mainRole, int z, std::string actorId){
	if(!mainRole)
		return;
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		int tag = compObj->getTag();
		int order = compObj->getOrderOfArrival();
		auto showLayer = getdesignerRvalueAbility4(index,actorId);
		auto shwoTag = getmismatchedCharbits(index,actorId);
		if(showLayer){
			showLayer->addChild(compObj, z, tag);
			compObj->setOrderOfArrival(order);
			compObj->release();
		}
	}
}
void mubeReplacement::begunWilreferRevisited(cocos2d::Node* mainRole){
	addingRelies* main_role = dynamic_cast<addingRelies*>(mainRole);
	if(!main_role)
		return;
	std::string actorId = main_role->getrankedClauseHowevewe();
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter == timeReferenparameter.end())
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
void mubeReplacement::possibleSurprisinglyOlder(std::string newrankedClauseHowevewe, std::string oldrankedClauseHowevewe){
	if (newrankedClauseHowevewe == oldrankedClauseHowevewe) {
		return;
	}
	auto componentList_iter = timeReferenparameter.find(oldrankedClauseHowevewe);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	std::unordered_map<int,cocos2d::Node*>* componentList_new = new std::unordered_map<int,cocos2d::Node*>();
	std::unordered_map<int,completelyInfrequently*>* componentListAtr_new = new std::unordered_map<int,completelyInfrequently*>();
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
		int tag = getmismatchedCharbits(index,newrankedClauseHowevewe);
		compObj->setTag(tag);
		componentList_new->insert(std::pair<int,cocos2d::Node*>(index,compObj));
		completelyInfrequently* objAttrs = getseparatelyJustPeople(index,oldrankedClauseHowevewe);
		if(objAttrs)
			componentListAtr_new->insert(std::pair<int,completelyInfrequently*>(index,objAttrs));
	}
	CC_SAFE_DELETE(componentList_iter->second);
	timeReferenparameter.erase(componentList_iter);
	auto iter_atr = m_instantiationsNothing.find(oldrankedClauseHowevewe);
	if(iter_atr != m_instantiationsNothing.end()){
		CC_SAFE_DELETE(iter_atr->second);
		m_instantiationsNothing.erase(iter_atr);
	}
	timeReferenparameter.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(newrankedClauseHowevewe,componentList_new));
	m_instantiationsNothing.insert(std::pair<std::string,std::unordered_map<int,completelyInfrequently*>*>(newrankedClauseHowevewe,componentListAtr_new));
	m_visibleThgenerates = newrankedClauseHowevewe;
}
void mubeReplacement::setinsteadCollideConsult(std::string actorId, bool isgray){
	for(std::vector<ActorComponentType>::iterator iter = m_synthesizedLimited.begin();iter != m_synthesizedLimited.end();iter++){
		ActorComponentType index = *iter;
		addingRelies* compObj = dynamic_cast<addingRelies*>(getvaluesTellsProgramming(index,actorId));
		if(!compObj)
			continue;
		compObj->setWhite(isgray);
	}
}
void mubeReplacement::totalImportanceRest(std::string actorId){
	auto componentList_iter = timeReferenparameter.find(actorId);
	if(componentList_iter != timeReferenparameter.end()){
		std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
		for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
			ActorComponentType index = (ActorComponentType)iter->first;
			auto compObj = iter->second;
			if(!compObj)
				continue;
			leadsDoesndifferRest2(index,actorId,compObj,false);
		}
		CC_SAFE_DELETE(componentList_iter->second);
		timeReferenparameter.erase(componentList_iter);
	}
	auto iter_atr = m_instantiationsNothing.find(actorId);
	if(iter_atr != m_instantiationsNothing.end()){
		std::unordered_map<int,completelyInfrequently*>* componentListAtr_new = iter_atr->second;
		for(std::unordered_map<int,completelyInfrequently*>::iterator iter = componentListAtr_new->begin();iter != componentListAtr_new->end();iter++){
			if(iter->second)
				CC_SAFE_DELETE(iter->second);
		}
		CC_SAFE_DELETE(iter_atr->second);
		m_instantiationsNothing.erase(iter_atr);
	}
	auto iter_tag = m_tagList.find(actorId);
	if (iter_tag != m_tagList.end()){
		m_tagList.erase(iter_tag);
	}
}
void mubeReplacement::identifiesRepresents(cocos2d::Node* mainRole){
	addingRelies* main_role = dynamic_cast<addingRelies*>(mainRole);
	if(!main_role)
		return;
	std::string main_actorId = main_role->getrankedClauseHowevewe();
	occasionallyErrormsg.clear();
	m_tagList.clear();
	tag_seed =  500;
	auto componentList_iter = timeReferenparameter.find(main_actorId);
	if(componentList_iter == timeReferenparameter.end())
		return;
	std::unordered_map<int,cocos2d::Node*>* componentList = componentList_iter->second;
	std::unordered_map<int,cocos2d::Node*>* componentList_new = new std::unordered_map<int,cocos2d::Node*>();
	std::unordered_map<int,completelyInfrequently*>* componentListAtr_new = new std::unordered_map<int,completelyInfrequently*>();
	for(std::unordered_map<int,cocos2d::Node*>::iterator iter = componentList->begin();iter != componentList->end();iter++){
		ActorComponentType index = (ActorComponentType)iter->first;
		auto compObj = iter->second;
		if(!compObj)
			continue;
	
		int tag = getmismatchedCharbits(index, main_actorId);
		compObj->setTag(tag);
		componentList_new->insert(std::pair<int,cocos2d::Node*>(index,compObj));
		completelyInfrequently* objAttrs = getseparatelyJustPeople(index,main_actorId);
		completelyInfrequently* objAttrs_new = new completelyInfrequently();
		if(objAttrs){
			objAttrs_new->visible = objAttrs->visible;
			objAttrs_new->offsetX = objAttrs->offsetX;
			objAttrs_new->offsetY = objAttrs->offsetY;
			objAttrs_new->opacity = objAttrs->opacity;
		}
		componentListAtr_new->insert(std::pair<int,completelyInfrequently*>(index,objAttrs_new));
	}
	cleanData();
	timeReferenparameter.insert(std::pair<std::string,std::unordered_map<int,cocos2d::Node*>*>(main_actorId,componentList_new));
	m_instantiationsNothing.insert(std::pair<std::string,std::unordered_map<int,completelyInfrequently*>*>(main_actorId,componentListAtr_new));
}
void mubeReplacement::westoreWidthTypes(int actionId,std::string param2,int param3){
	if(actionId == 1){
		setshownRatherInitially(param2,false,true);
	}
}
void * mubeReplacement::expressionSharedOptional(char ability,void * contract)
{
	void * doing;
	doing = nullptr;
	return nullptr;
}
void mubeReplacement::filesKnownDestruction(short space,double base,int wants,char techniques)
{
	bool regular;
	regular = true;
}
unsigned short mubeReplacement::targetInsteadAlong(short application,long refer,char capital)
{
	void * deduces;
	deduces = nullptr;
	short says;
	says = 257;
	void * qualifying;
	qualifying = nullptr;
	return 466;
}
char mubeReplacement::destroysDeclarationHeader(char isbn)
{
	int connection;
	connection = 527;
	double statement;
	statement = 534.10;
	return 'j';
}
int mubeReplacement::evenCleansPromotion(float syntactic,int incidental,bool impact)
{
	unsigned short backslash;
	backslash = 744;
	unsigned short lets;
	lets = 915;
	int manager;
	manager = 308;
	int results;
	results = 485;
	int similarly;
	similarly = 408;
	return 754;
}
short mubeReplacement::presentedExactly(void * imageth)
{
	float accessed;
	accessed = 393.18f;
	short period;
	period = 557;
	void * relative;
	relative = nullptr;
	long options;
	options = 235;
	unsigned short chparameter;
	chparameter = 573;
	return 542;
}
