#include "SpritePlayer.h"
#include "CCEffects.h"
#include "MapView.h"
#include "CCLuaEngine.h"
#include "ActorActionManageC.h"
#include "ActorRenderQueueManage.h"
USING_NS_CC;
int SpritePlayer::MOVE_CHECK_GAP = 20;
SpritePlayer::SpritePlayer()
{
	m_active = false;
	m_unAttack = true;
	m_boPhantomMove = false;
	m_mapView = nullptr;
	flyInitPos = Vec2::ZERO;
	flyNode = nullptr;
	flyTmpHandler = 0;
	m_sex = 1;
	m_school = 1;
	m_random_mode = 0;
	m_playActionWithChildrenCb = 0;
	m_gotoDeathCd = 0;
	m_setActorVisibleCd = 0;
	m_moveKeyPosCb = 0;
	m_speedPercent = 100;
	m_weaponEffectPath = "";
	memset(&m_weaponEffectPosOffset1, 0, sizeof(m_weaponEffectPosOffset1));
	memset(&m_weaponEffectPosOffset2, 0, sizeof(m_weaponEffectPosOffset2));
	memset(&m_weaponEffectPosOffset3, 0, sizeof(m_weaponEffectPosOffset3));
	memset(&m_weaponEffectPosOffset4, 0, sizeof(m_weaponEffectPosOffset4));
	m_suddenSpeed = 500;
	m_conveyState = 0;
	m_petOnRide = false;
}
SpritePlayer::~SpritePlayer(void)
{
	 m_sprites.clear();
}
SpritePlayer *SpritePlayer::create(const std::string&pszFileName,std::string actorflag, bool isMainRole)
{
    SpritePlayer *pRet = new SpritePlayer();
	if (pRet && pRet->initWithFileExt(pszFileName, actorflag, isMainRole))
    {
		if(isMainRole)
		{
		
			pRet->setActorFlag(true);
			pRet->setRoleId(actorflag);
		}
		else
		{
			pRet->setActorFlag(false);
		}
		pRet->setBloodType(3);
        pRet->autorelease();
		pRet->setActorType(ActorType::Role);
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
void SpritePlayer::setActorFlag(bool actorflag)
{
	isactor_flag = actorflag;
}
bool SpritePlayer::isActor()
{
	return isactor_flag;
}
bool SpritePlayer::getIsConveyAction(){
	return (getConveyState() == 1 || getConveyState() == 3);
}
void SpritePlayer::insertActionChild(SpriteBase* child, int z,int tag)
{
    m_sprites.pushBack(child);
 	addChild(child,z,tag);
}
void SpritePlayer::removeActionChild(SpriteBase* child)
{
	ssize_t index = m_sprites.getIndex(child);
    m_sprites.erase(index);
	removeChild(child,true);
}
void SpritePlayer::removeActionChildByTag(int tag)
{
	SpriteBase *child = (SpriteBase *)this->getChildByTag(tag);
	if(!child) return;
	ssize_t index = m_sprites.getIndex(child);
    m_sprites.erase(index);
	removeChild(child,true);
}
void SpritePlayer::hideAllActionChild(bool allChild)
{
	if (m_actorId != "" && m_setActorVisibleCd > 0)
	{
		setSingleVisible(false);
		ActorActionManageC::getInstance()->setVisibleRole(m_actorId,false,getTypeId(),allChild);
		ActorActionManageC::getInstance()->setHideWithChildren(m_actorId,true);
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
	}
	else
	{
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setVisible(false);
			c_sprite->setIsHide(true);
		}
		setIsHide(true);
		main_sprite->setVisible(false);
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
	}
}
void SpritePlayer::showAllActionChild(bool allChild)
{
	if (m_actorId != "" && m_setActorVisibleCd > 0)
	{
		ActorActionManageC::getInstance()->setVisibleRole(m_actorId,true,getTypeId(), allChild);
		ActorActionManageC::getInstance()->setHideWithChildren(m_actorId,false);
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
		if(getScreenVisible())
			setVisible(true);
	}
	else
	{
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setVisible(true);
			c_sprite->setIsHide(false);
		}
		setIsHide(false);
		main_sprite->setVisible(true);
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
	}
}
void SpritePlayer::refresh(){
	if(getCurrActionState() != ACTION_STATE_ATTACK)
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
}
void SpritePlayer::standed()
{
	if(stand_inited&&changeStateWithChildren(ACTION_STATE_IDLE))
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		playActionWithChildren(m_stand_times,stand,m_roledata.dir,0);
	}
}
void SpritePlayer::setActionStateChange(bool val)
{
	if (m_actorId != "")
	{
		m_actionStateChange = val;
		ActorActionManageC::getInstance()->AWC_setActionStateChange(m_actorId, val);
	}
	else
	{
		m_actionStateChange = val ;
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setActionStateChange(val);
		}
	}
}
void SpritePlayer::standedby()
{
	if(stand_inited&&getCurrActionState()==ACTION_STATE_IDLE)
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		playActionWithChildren(m_stand_times,standby,m_roledata.dir,0);
	}
}
void SpritePlayer::FixFlyPos(){
	if(MapView::DefaultMapView == nullptr)
		return;
	Vec2 cur_tile = MapView::DefaultMapView->space2Tile(getPosition());
	if(MapView::DefaultMapView->isBlock(cur_tile)){
		int range = 1;
		while (true)
		{
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x + range,cur_tile.y)) == false){
				cur_tile.x += range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x - range,cur_tile.y)) == false){
				cur_tile.x -= range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x,cur_tile.y + range)) == false){
				cur_tile.y += range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x,cur_tile.y - range)) == false){
				cur_tile.y -= range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x + range,cur_tile.y + range)) == false){
				cur_tile.x += range;
				cur_tile.y += range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x + range,cur_tile.y - range)) == false){
				cur_tile.x += range;
				cur_tile.y -= range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x - range,cur_tile.y + range)) == false){
				cur_tile.x -= range;
				cur_tile.y += range;
				break;
			}
			if(MapView::DefaultMapView->isBlock(Vec2(cur_tile.x - range,cur_tile.y - range)) == false){
				cur_tile.x -= range;
				cur_tile.y -= range;
				break;
			}
			range += 1;
			if(range > 100)
				break;
		}
		flyToTheDir(0,0,0,MapView::DefaultMapView->tile2Space(cur_tile));
	}
}
void SpritePlayer::flyToTheDir(float times,int fly_mode,int handler,Vec2 newPos,Commen_Direction dir,bool stand,bool auto_double_jump_check,bool checkSecondAction, int state)
{
	if(getCurrActionState()<ACTION_STATE_DEAD && getCurrActionState() != ACTION_STATE_SUDDEN)
	{
		auto oldActionState = ACTION_STATE_IDLE;
		if(m_conveyState == 0 )
		{
			if(checkSecondAction && getActionByTag(ACTION_FLY02_TAG) != nullptr)
				return;
			oldActionState = getCurrActionState();
		}
		if(changeStateWithChildren(ACTION_STATE_FLY))
		{
		
			if(dir == dir_none && newPos != Vec2::ZERO)
			{
				dir = getDirByNewPoint(newPos);
			}
			if(dir != dir_none)
				setSpriteDir(dir);
			bool hasBlockBetween = false;
		
			float speed = 500;
			float distance = 350;
			float actionTime = times;
			float factor = 200;
			float factor_ride = 0;
			float factor_up = 50;
			if(getOnRide())
			{
			
				factor_up = 50;
				factor_ride = 50;
				speed += 100;
			}
			bool easeOutOpen = false;
			int tag = ACTION_FLY01_TAG;
			Vec2 curPos = getPosition();
			int fly_mode_tmp = 1;
			if(oldActionState != ACTION_STATE_FLY)
			{
			
				fly_mode_tmp = 1;
				flyInitPos = curPos;							
			
				this->removeChildByTag(636);
				flyNode = nullptr;
				flyNode = __NodeRGBA::create();
				this->addChild(flyNode);
				flyNode->setTag(636);
				flyNode->setPosition(curPos);
			}
			else
			{
			
				fly_mode_tmp = 2;
				if(actionTime != 0)
					actionTime -= 0.1f;
				else
					speed += 50;
				factor -= 50;
				easeOutOpen = false;
				tag = ACTION_FLY02_TAG;
				flyInitPos = flyNode->getPosition();
			
				int opac = flyNode->getOpacity();
				if(opac < 50) 
					return;
			}
			if(fly_mode == -1)
			{
			
				fly_mode_tmp = rand()%2+1;
			}
			else if(fly_mode != 0)
			{
			
				fly_mode_tmp = fly_mode;
			}
		
			cocos2d::Vec2 newVec2 = flyInitPos;
			if(newPos == Vec2::ZERO)
			{
				Vec2 direction_tmp = m_rocker_direction;
				if(direction_tmp == Vec2::ZERO)
				{
					direction_tmp = getDirectionByDir(m_roledata.dir);
				}
				else
				{
				
					if(m_mapView != nullptr)
					{
						Commen_Direction dir = m_mapView->getDirByDirection(direction_tmp);
						setSpriteDir(dir);
					}
				}
				newVec2.add(direction_tmp * distance);
			
				if(m_conveyState == 0 && m_mapView != nullptr)
				{
					newVec2 = m_mapView->checkCanWalkabled(flyInitPos,newVec2);
				}
			}
			else
			{
				newVec2 = newPos;
			}
			if(MapView::DefaultMapView)
			{
			
				if(m_conveyState == 0 && MapView::DefaultMapView->hasBlockPos(flyInitPos,newVec2))
					hasBlockBetween = true;
			}
			setFlyModeWithChildren(fly_mode_tmp);
			stopActionByTag(ACTION_ATTACK_TAG);
			stopMoveAction();
			stopActionByTag(ACTION_FLY01_TAG);
			stopActionByTag(ACTION_FLY02_TAG);
		
			float distance_gap = curPos.distance(newVec2);
			if(actionTime == 0)
			{
				speed = speed * m_speedPercent/100;				
				actionTime = distance_gap/speed;
				if(actionTime < 0.7)
				{
					actionTime = 0.7f;
					speed = distance_gap/actionTime;
				}
			}
			else
			{
				speed = distance_gap/actionTime;
			}
		
			int loop = 1;
			if (fly_mode_tmp == 2 )
			{
				loop = static_cast<int>(actionTime/0.5);
			}
			playActionWithChildren(actionTime, fly, m_roledata.dir, loop);
		
			ccBezierConfig bezier;
			Vec2 endPosition = Vec2(newVec2);
			endPosition.add(Vec2(0,factor_up));
			bezier.controlPoint_1 = curPos + Vec2(0,factor + factor_ride);
			bezier.controlPoint_2 = endPosition + Vec2(0,factor + factor_ride);
			bezier.endPosition = newVec2;
			auto bezierForward = BezierTo::create(actionTime, bezier);
			flyTmpHandler = handler;
			if(stand)
			{
				FiniteTimeAction* actbackfun = CallFunc::create([&]()
				{ 
					if(m_conveyState == 0)
						syncFlyStateWithChildren(2,false);
					else
						syncSendStateWithChildren(state,false);
					this->standed();
				
				
					if(this->onFly && m_conveyState == 0)
					{
						this->onFly(2,0,Vec2::ZERO,0,0);
					}
					if(this->flyTmpHandler && this->flyTmpHandler != 0)
					{
						LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
						if (pStack != NULL)
						{
							pStack->pushInt(2);							
							pStack->executeFunctionByHandler(this->flyTmpHandler, 1);
							pStack->clean();
						}
					}
				
				});
				Action* action = nullptr;
				if(easeOutOpen)
				{
					auto easeAction = EaseOut::create(bezierForward,1.5f);
					action = Sequence::create(easeAction,actbackfun,NULL);
				}
				else
				{
					action = Sequence::create(bezierForward,actbackfun,NULL);
				}
				action->setTag(tag);
				runAction(action);
			}
			else
			{
				auto easeAction = EaseOut::create(bezierForward,1.35f);
				easeAction->setTag(tag);
				runAction(easeAction);
			}
			flyNode->stopAllActions();
			Action* double_jump_check_action = nullptr;
			if(auto_double_jump_check)
			{
				if(distance_gap >= 550)
				{
				
					auto posNode = Node::create();
					int second_fly_mode = fly_mode_tmp == 1?2:1;
					posNode->setLocalZOrder(second_fly_mode);
					posNode->setTag(1);
					flyNode->addChild(posNode);
					posNode->setPosition(newVec2.x,newVec2.y);
					double_jump_check_action = Sequence::create(DelayTime::create(actionTime/2), CallFunc::create([&]()
					{ 
					
					
						auto dataNode = flyNode->getChildByTag(1);
						auto pos = dataNode->getPosition();
						flyToTheDir(0,dataNode->getLocalZOrder(),0,pos);
					}),nullptr);
				}
			}
		
			auto action = Spawn::create(FadeTo::create(actionTime,100),Sequence::create(MoveTo::create(actionTime,newVec2), CallFunc::create([&](){ 
				flyNode->removeFromParent();
				flyNode = nullptr;
			}),NULL),double_jump_check_action,NULL);
			flyNode->setOpacity(0);
			flyNode->runAction(action);
		
			auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
			
				this->addPhantomMoveEffect(0);
			}),nullptr));
			flyNode->runAction(shadownAction);
		
			if (m_conveyState == 0)
				syncFlyStateWithChildren(1,hasBlockBetween);
			else
				syncSendStateWithChildren(state, false);
			if(onFly && m_conveyState == 0)
			{
				onFly(1,m_fly_mode,newVec2,actionTime,floor(speed));
			}
		
			if(handler && handler != 0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(1);							
					pStack->executeFunctionByHandler(handler, 1);
					pStack->clean();
				}
			}
		
		}
	}
}
void SpritePlayer::suddenToThePos(int suddenMode,Vec2 suddenTargetPos,float times){
	if(getCurrActionState() != ACTION_STATE_FLY && changeStateWithChildren(ACTION_STATE_SUDDEN)){
	
	
		Vec2 curPos = getPosition();
		if(m_mapView != nullptr){
			suddenTargetPos = m_mapView->checkCanWalkabled(curPos,suddenTargetPos);
		}
	
		setDirByNowPoint(suddenTargetPos);
		float speed = m_suddenSpeed;
		float distance = curPos.distance(suddenTargetPos);
		float actionTime = times;
		if(actionTime == 0){
			speed = speed * m_speedPercent/100;
			actionTime = distance/speed;
		}else{
			speed = distance/actionTime;
		}
	
		setFlyModeWithChildren(suddenMode);
		playActionWithChildren(actionTime,fly,m_roledata.dir,1);
	
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
		
			this->standed();
			stopActionByTag(ACTION_SHADOW_TAG);
			if(this->onSuddenFinish)
				this->onSuddenFinish(2,Vec2::ZERO,0,0);
		});
		stopActionByTag(ACTION_ATTACK_TAG);
		stopMoveAction();
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		auto moveAction = MoveTo::create(actionTime,suddenTargetPos);
		auto action = Sequence::create(moveAction,actbackfun,nullptr);
		action->setTag(ACTION_SUDDEN_TAG);
		runAction(action);
	
		if(this->onSuddenFinish)
			this->onSuddenFinish(1,suddenTargetPos,actionTime,speed);
	
		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
		
			this->addPhantomMoveEffect(0);
		}),nullptr));
		shadownAction->setTag(ACTION_SHADOW_TAG);
		runAction(shadownAction);
	}
}
void SpritePlayer::setMapView(MapView* view){
	m_mapView = view;
}
void SpritePlayer::hurtIdleToPos(float times,Vec2 newVec2,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeStateWithChildren(ACTION_STATE_HURT_IDLE))
		{
			if(newVec2 != Vec2())
				setDirByNowPoint(newVec2);  
			playActionWithChildren(times,hurt_idle,m_roledata.dir,1);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		}
	}
}
void SpritePlayer::hurtKneelToPos(float times,Vec2 newVec2,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeStateWithChildren(ACTION_STATE_HURT_KNEEL))
		{
			if(newVec2 != Vec2())
				setDirByNowPoint(newVec2);  
			playActionWithChildren(1,hurt_kneel,m_roledata.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		}
	}
}
void SpritePlayer::moveToPos(float times,Vec2 newVec2,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeStateWithChildren(ACTION_STATE_RUN)||setDirByNowPoint(newVec2))
		{
		
			setDirByNowPoint(newVec2);
			playActionWithChildren(0.7f,run,m_roledata.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newVec2),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newVec2));
	}
}
void SpritePlayer::walkToPos(float times,Vec2 newVec2,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeStateWithChildren(ACTION_STATE_WALK)||setDirByNowPoint(newVec2))
		{
		
			setDirByNowPoint(newVec2);
			playActionWithChildren(0.7f,walk,m_roledata.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newVec2),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newVec2));
	}
}
bool SpritePlayer::moveInTheDir(float times,Vec2 newVec2,Commen_Direction dir,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD && getCurrActionState() != ACTION_STATE_ATTACK && getCurrActionState() != ACTION_STATE_FLY && getCurrActionState() != ACTION_STATE_SUDDEN)
	{
		if(dir == dir_none && newVec2 != Vec2::ZERO){
			dir = getDirByNewPoint(newVec2);
		}
		if(changeStateWithChildren(ACTION_STATE_RUN)||setSpriteDir(dir))
		{
			playActionWithChildren(0.7f,run,dir,0);
		}
		if(newVec2 != Vec2(0,0))
		{
			stopMoveAction();
			if(stand){
				FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
				auto action = Sequence::create(MoveTo::create(times,newVec2),actbackfun,NULL);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}else{
				auto action = MoveTo::create(times,newVec2);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}
		
			if (getActorFlag())
			{
				Node* map = getParent()->getParent();
				if(map)
				{
					Node* nd = NULL;
					for(int i = 8800; i <= 8805; i++)
					{
						if(nd = map->getChildByTag(i))
						{
							nd->runAction(MoveTo::create(times,newVec2));
						}
					}
				}
			}
		}
		return true;
	}
	return false;
}
bool SpritePlayer::walkInTheDir(float times,Vec2 newVec2,Commen_Direction dir)
{
	if(getCurrActionState()<ACTION_STATE_DEAD&&(getCurrActionState() < ACTION_STATE_ATTACK||getCurrActionState()>ACTION_STATE_COLLIDE))
	{
		if(changeStateWithChildren(ACTION_STATE_WALK)||setSpriteDir(dir))
		{
			playActionWithChildren(0.50,walk,dir,0);
		}
		if(newVec2 != Vec2(0,0)){
			auto action =  MoveTo::create(times,newVec2);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}
		return true;
	}
	return false;
}
bool SpritePlayer::collideInTheDir(float times,Vec2 newVec2,Commen_Direction dir)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeStateWithChildren(ACTION_STATE_COLLIDE)||setSpriteDir(dir))
		{
			setSpriteDir(dir);
			playActionWithChildren(0.4f,collide,dir,0);
		}
		if(newVec2 != Vec2(0,0))
			runAction( MoveTo::create(times,newVec2));
		return true;
	}
	return false;
}
bool SpritePlayer::digToTheDir(float times,Commen_Direction dir)
{
	if(changeStateWithChildren(ACTION_STATE_DIG)||setSpriteDir(dir))
	{
		playActionWithChildren(times,dig,dir,0);
		return true; 
	}
	return false;
}
bool SpritePlayer::excavateToTheDir(float times,Commen_Direction dir)
{
	if(changeStateWithChildren(ACTION_STATE_EXCAVATE)||setSpriteDir(dir))
	{
		playActionWithChildren(times,excavate,dir,0);
		return true; 
	}
	return false;
}
void SpritePlayer::setWeaponEffectPath(std::string path){
	m_weaponEffectPath = path;
}
void SpritePlayer::setWeaponEffectPosOffset(int attack_mode, Vec2 posOffset1,Vec2 posOffset2,Vec2 posOffset3,Vec2 posOffset4,Vec2 posOffset5,Vec2 posOffset6,Vec2 posOffset7,Vec2 posOffset8)
{
	Vec2 (*pOffset)[8] = nullptr;
	switch (attack_mode)
	{
	case 1:
		pOffset = &m_weaponEffectPosOffset1;
		break;
	case 2:
		pOffset = &m_weaponEffectPosOffset2;
		break;
	case 3:
		pOffset = &m_weaponEffectPosOffset3;
		break;
	case 4:
		pOffset = &m_weaponEffectPosOffset4;
		break;
	default:
		break;
	}
	if(pOffset)
	{
		(*pOffset)[0] = posOffset1;
		(*pOffset)[1] = posOffset2;
		(*pOffset)[2] = posOffset3;
		(*pOffset)[3] = posOffset4;
		(*pOffset)[4] = posOffset5;
		(*pOffset)[5] = posOffset6;
		(*pOffset)[6] = posOffset7;
		(*pOffset)[7] = posOffset8;
	}
}
Vec2 SpritePlayer::getWeaponEffectPosOffset(int attack_mode)
{
	Vec2 posOffset = Vec2::ZERO;
	switch (attack_mode)
	{
	case 1:
		posOffset = m_weaponEffectPosOffset1[m_roledata.dir];
		break;
	case 2:
		posOffset = m_weaponEffectPosOffset2[m_roledata.dir];
		break;
	case 3:
		posOffset = m_weaponEffectPosOffset3[m_roledata.dir];
		break;
	case 4:
		posOffset = m_weaponEffectPosOffset4[m_roledata.dir];
		break;
	default:
		break;
	}
	return posOffset;
}
std::string SpritePlayer::getWeaponEffectPath(){
	if(m_weaponEffectPath != "")
		return m_weaponEffectPath;
	char effectPath[32] = {};
	sprintf(effectPath,"weaponEffect%d",(int)getSchool());
	return effectPath;
}
void SpritePlayer::addWeaponEffect(int attackMode,float times,float left_time){
	SpriteBase* weaponEffect = SpriteBase::create(getWeaponEffectPath());
	weaponEffect->m_attack_mode = attackMode;
	weaponEffect->setTypeId(ATTACK_EFFECT);
	weaponEffect->initStandStatus(3,8,5,0,10,10,1.0,m_roledata.dir);
	weaponEffect->initAttackModeStatus(
		m_roledata.maxcut_weaponeff_01, 
		m_roledata.maxcut_weaponeff_02, 
		m_roledata.maxcut_weaponeff_03, 
		m_roledata.maxcut_weaponeff_04,
		m_roledata.maxcut_weaponeff_05,
		m_roledata.maxcut_weaponeff_06,
		m_roledata.maxcut_weaponeff_07,
		m_roledata.maxcut_weaponeff_08,
		m_roledata.maxcut_weaponeff_09,
		m_roledata.maxcut_weaponeff_10,
		m_roledata.maxcut_weaponeff_11,
		m_roledata.maxcut_weaponeff_12);
	if(m_sex == 2 && attackMode == 3)
		addChild(weaponEffect, 9,  8800);
	else
		addChild(weaponEffect, 10, 8800);
	float animTime = times;
	weaponEffect->playAction(animTime,attack,m_roledata.dir,1,left_time);
	weaponEffect->addAutoRemoveAction(animTime);
	Vec2 posOffset = getWeaponEffectPosOffset(attackMode);
	weaponEffect->setBasePosition(posOffset);
}
bool SpritePlayer::playerAttackToPos(float times,Vec2 newVec2,int attackMode, bool hasEffect,bool stand)
{
	if(getCurrActionState() == ACTION_STATE_FLY || getCurrActionState() == ACTION_STATE_SUDDEN)
		return false;
	left_time = 0;
	if(changeStateWithChildren(ACTION_STATE_ATTACK))
	{
		if(isActor() && stopMapAction != NULL)
		{
			stopMapAction();
		}
		if(newVec2 != Vec2()){
			setDirByNowPoint(newVec2);  
		}
	
		setAttackModeWithChildren(attackMode);
		if(hasEffect)
		{
			addWeaponEffect(attackMode,times,left_time);
		}
		playActionWithChildren(times,attack,m_roledata.dir,1,left_time);
		stopActionByTag(ACTION_ATTACK_TAG);
		if(stand){
			FiniteTimeAction* actbackfun = CallFunc::create([&](){changeStateWithChildren(ACTION_STATE_IDLE); this->standedby();});
			auto action = Sequence::create(DelayTime::create(times+left_time+0.001),actbackfun,NULL);
			action->setTag(ACTION_ATTACK_TAG);
			runAction(action);
		}else{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){changeStateWithChildren(ACTION_STATE_IDLE);});
			auto action = Sequence::create(DelayTime::create(times+left_time+0.001),actbackfun,NULL);
			action->setTag(ACTION_ATTACK_TAG);
			runAction(action);
		}
		return true;
	}
	else 
	{
		changeStateWithChildren(ACTION_STATE_IDLE);
	}
	return false;
}
bool SpritePlayer::attackToPos(float times,Vec2 newVec2,bool hasEffect)
{
	left_time = 0;
	if(isActor() && stopMapAction != NULL)
	{
		stopMapAction();
	
	}
	if(changeStateWithChildren(ACTION_STATE_ATTACK))
	{
		if(newVec2 != Vec2())
			setDirByNowPoint(newVec2);  
		int mode_random = getAttackModeC();
		setAttackModeWithChildren(mode_random);
		if(hasEffect)
			addWeaponEffect(m_attack_mode,times,left_time);
	
		playActionWithChildren(times,attack,m_roledata.dir,1,left_time);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){changeStateWithChildren(ACTION_STATE_IDLE); this->standedby();});
		stopActionByTag(ACTION_ATTACK_TAG);
		auto action = Sequence::create(DelayTime::create(times+left_time+0.1),actbackfun,NULL);
		action->setTag(ACTION_ATTACK_TAG);
		runAction(action);
		return true;
	}
	else 
	{
		changeStateWithChildren(ACTION_STATE_IDLE);
	}
	return false;
}
int SpritePlayer::getAttackModeC(){
	m_attack_mode += 1;
	if(m_attack_mode > 4)
		m_attack_mode = 1;
	return m_attack_mode;
}
bool SpritePlayer::attackOneTime(float times,Vec2 newVec2)
{
	left_time = 0;
	if(isActor() && stopMapAction != NULL)
	{
		stopMapAction();
	
	}
	if(changeStateWithChildren(ACTION_STATE_ATTACK))
	{
	
		if(newVec2 != Vec2())
			setDirByNowPoint(newVec2);
		int mode_random = rand()%4+1;
		setAttackModeWithChildren(mode_random);
		addWeaponEffect(m_attack_mode,times,left_time);
		playActionWithChildren(times,attack,m_roledata.dir,1,left_time);
	
	
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ changeStateWithChildren(ACTION_STATE_IDLE);this->standedby();});
		auto action = Sequence::create(DelayTime::create(times+left_time+0.1),actbackfun,NULL);
		stopActionByTag(ACTION_ATTACK_TAG);
		action->setTag(ACTION_ATTACK_TAG);
		runAction(action);
		return true;
	}
	else 
	{
		changeStateWithChildren(ACTION_STATE_IDLE);
	}
	return false;
}
bool SpritePlayer::magicUpToPos(float times,Vec2 newVec2)
{
	left_time = 0;
	if(isActor() && stopMapAction != NULL)
	{
		stopMapAction();
	
	}
	if(changeStateWithChildren(ACTION_STATE_MAGICUP))
	{
	
		if(newVec2 != Vec2())
			setDirByNowPoint(newVec2);
		playActionWithChildren(times,magicup,m_roledata.dir,1,left_time);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){  changeStateWithChildren(ACTION_STATE_IDLE);this->standedby();});
		runAction(Sequence::create(DelayTime::create(times+left_time+0.1),actbackfun,NULL));
		return true;
	}
	else 
	{
		changeStateWithChildren(ACTION_STATE_IDLE);
	}
	return false;
}
void SpritePlayer::gotoDeath(Commen_Direction dir)
{
	if(changeStateWithChildren(ACTION_STATE_DEAD))
	{
		setSpriteDir(dir);
		playActionWithChildren(0.7f,death,m_roledata.dir,1);
	}
	if(m_actorId != "" && m_gotoDeathCd > 0){
		ActorActionManageC::getInstance()->gotoDeath(m_actorId);
	}
}
void SpritePlayer::stopInTheTime(ActionState toState)
{
	if(changeStateWithChildren(toState))
	{
		if (toState == ACTION_STATE_HURT_IDLE)
		{
			stopAllActions();
			getMainSprite()->stopAllActions();
		}
	
	
	
	
	
		if(m_actorId != "" && toState == ACTION_STATE_HURT_IDLE)
		{
			ActorActionManageC::getInstance()->AWC_stopInTheTime(m_actorId);
		}
	}
}
bool SpritePlayer::doStreakToTheDir(float times,Vec2 pos,Commen_Direction dir)
{
	if(getCurrActionState() != ACTION_STATE_FLY && getCurrActionState() != ACTION_STATE_SUDDEN && getCurrActionState()<ACTION_STATE_DEAD)
	{
		stopActionByTag(ACTION_SHADOW_TAG);
		setSpriteDir(dir);
		playActionWithChildren(-1,ACTION_NONE,dir_none,-100,-1);
		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
		
			this->addPhantomMoveEffect(0);
		}),nullptr));
		shadownAction->setTag(ACTION_SHADOW_TAG);
		runAction(shadownAction);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
			this->standed();
			stopActionByTag(ACTION_SHADOW_TAG);
		});
		auto moveAction = MoveTo::create(times,pos);
		auto action = Sequence::create(moveAction,actbackfun,nullptr);
		action->setTag(ACTION_MOVE_TAG);
		runAction(action);
		return true;
	}
	return false;
}
void SpritePlayer::registerPlayActionWithChildrenCb(int handler)
{
	m_playActionWithChildrenCb = handler;
}
void SpritePlayer::removePlayActionWithChildrenCb()
{
	m_playActionWithChildrenCb = 0;
}
bool SpritePlayer::changeStateWithChildren(ActionState actionState)
{
	bool result = changeState(actionState);
	if(result){
		if (m_actorId != "" && m_playActionWithChildrenCb > 0){
		
		
		
		
		
		
		
		
		
		
		
		
			ActorActionManageC::getInstance()->AWC_changeActionState(m_actorId,actionState);
		}else{
			for (auto& c_sprite : m_sprites)
			{
				c_sprite->changeState(actionState);
			}
		}
	}
	return result;
}
void SpritePlayer::playActionWithChildren(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes){
	if(action == ACTION_NONE)	action = m_roledata.acttodo;
	if(times == -1) times = m_roledata.actiontime;
	if(dir == dir_none) dir = m_roledata.dir;
	if(loop == -100) loop = m_loop;
	if (m_actorId != "" && m_playActionWithChildrenCb > 0)
	{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		ActorType actorType = ActorType::None;
		if(getTypeId() == 22)
			actorType = ActorType::Role;
		else
			actorType = ActorType::Pet;
		ActorActionManageC::getInstance()->AWC_playActionWithChildren(m_actorId,times,action,dir,loop,ltimes,m_boHide,actorType);
	}
	else
	{
		if(m_boHide == false)
		{
			playAction(times,action,dir,loop);
			for (auto& c_sprite : m_sprites)
			{
				auto action_tmp = action;
				auto time_tmp = times;
				auto loop_tmp = loop;
			
				c_sprite->playAction(time_tmp,action_tmp,dir,loop_tmp);
			}
		}
		else
		{
			playActionData(times,action,dir,loop);
			for (auto& c_sprite : m_sprites)
			{
				auto action_tmp = action;
				auto time_tmp = times;
				auto loop_tmp = loop;
				if(c_sprite->getTypeId() == WING_TYPE){
					action_tmp = stand;
					time_tmp = getStandTime();
					loop_tmp = 0;
				}
				c_sprite->playActionData(time_tmp,action_tmp,dir,loop_tmp);
			}
		}
	}
}
void SpritePlayer::setAttackModeWithChildren(int attack_mode){
	m_attack_mode = attack_mode;
	if (m_actorId != ""&& m_playActionWithChildrenCb > 0){
	
	
	
	
	
	
	
	
	
	
	
	
		ActorActionManageC::getInstance()->AWC_attackMode(m_actorId,attack_mode);
	}else{
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setAttackMode(m_attack_mode);
		}
	}
}
void SpritePlayer::setOnRideWithChildren(int ride_id){
	setOnRide(ride_id);
	if (m_actorId != ""&& m_playActionWithChildrenCb > 0){
	
	
	
	
	
	
	
	
	
	
	
	
		ActorActionManageC::getInstance()->AWC_setOnRide(m_actorId,ride_id);
	}else{
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setOnRide(ride_id);
		}
	}
}
void SpritePlayer::setFlyModeWithChildren(int flyMode){
	setFlyMode(flyMode);
	if (m_actorId != ""&& m_playActionWithChildrenCb){
	
	
	
	
	
	
	
	
	
	
	
	
		ActorActionManageC::getInstance()->AWC_flyMode(m_actorId,flyMode);
	}else{
		for (auto& c_sprite : m_sprites)
		{
			c_sprite->setFlyMode(flyMode);
		}
	}
}
void SpritePlayer::syncFlyStateWithChildren(int flyState,bool hasBlock){
	if (m_actorId != ""&& m_playActionWithChildrenCb > 0){
	
	
	
	
	
	
	
	
	
	
	
	
	
		ActorActionManageC::getInstance()->AWC_flyState(m_actorId,flyState,hasBlock);
	}
}
void SpritePlayer::syncSendStateWithChildren(int sendState, bool hasBlock)
{
	if (m_actorId != ""&& m_playActionWithChildrenCb > 0)
	{
	
	
	
	
	
	
	
	
	
	
	
	
	
		ActorActionManageC::getInstance()->AWC_conveyState(m_actorId,sendState,hasBlock);
	}
}
void SpritePlayer::registerGotoDeathCb(int handler)
{
	m_gotoDeathCd = handler;
}
void SpritePlayer::removeGotoDeathCb()
{
	m_gotoDeathCd = 0;
}
void SpritePlayer::registerSetActorVisibleCd(int handler)
{
	m_setActorVisibleCd = handler;
}
void SpritePlayer::removeSetActorVisibleCd()
{
	m_setActorVisibleCd = 0;
}
void SpritePlayer::registerMoveKeyPosCb(int handler){
	m_moveKeyPosCb = handler;
}
void SpritePlayer::removeMoveKeyPosCb(){
	m_moveKeyPosCb = 0;
}
void SpritePlayer::setSpeedFloatPercent(float percent){
	m_speedPercent = percent;
}
float SpritePlayer::getSpeedFloatPercent(){
	return m_speedPercent;
}
void SpritePlayer::setShenbingStatus(int state){
	m_shenbingStatus = state;
	if(m_shenbingStatus > 1 && m_mapView)
		m_mapView->cleanAstarPath();
}
void SpritePlayer::syncKeyPosToDetailMap(bool research,Vec2 flyTargetPos){
	if(m_moveKeyPosCb > 0 && m_actorId  != ""){
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			pStack->pushBoolean(research);
			pStack->pushInt(flyTargetPos.x);
			pStack->pushInt(flyTargetPos.y);
			pStack->executeFunctionByHandler(m_moveKeyPosCb, 3);
			pStack->clean();
		}
	}
}
void SpritePlayer::updateMove(float delaTime)
{
	if(MapView::DefaultMapView == nullptr)
		return;
	if(canMove() == false)
		return;
	if(m_curTargetPos == Vec2::ZERO)
	{
		if(m_targetPosList.size() <= 0)
		{
		
			cleanMove();
		
			if(m_mapView)
			{
				m_mapView->onRoleMoveFinish();
			
			}
			else
			{
			
			
				if (m_currActionState != ACTION_STATE_HURT_IDLE)
				{
					standed();
				}
			}
			return;
		}
		else
		{
		
		
		
			Vec2 pos = m_targetPosList.front();
			m_targetPosList.pop_front();
			Vec2 role_move_pc_start = getPosition();
			Vec2 role_move_pc_end = MapView::DefaultMapView->tile2Space(pos);
			m_curTargetPos = role_move_pc_end;
			m_curTargetPos_tile = pos;
			stopActionByTag(ACTION_MOVE_TAG);
		
			if(m_justDelayCheck == false)
			{
				_overTime = 0;																			
				_remainTime = role_move_pc_start.distance(role_move_pc_end)/m_spead;
			
				m_move_direction = (role_move_pc_end - role_move_pc_start).getNormalized();
				Commen_Direction temp_dir = MapView::DefaultMapView->getDirByDirection(m_move_direction);
			
				bool dirChange = setSpriteDir(temp_dir);
				if(changeStateWithChildren(ACTION_STATE_RUN) || dirChange)
				{
				
					if (m_currActionState != ACTION_STATE_HURT_IDLE)
					{
						playActionWithChildren(0.7f,run,temp_dir,0);
					}
				}
				if(m_mapView)
				{
					m_mapView->addMoveTarget(pos);
					m_mapView->updateMove(delaTime);    
				}
			}
		}
	}
	Vec2 movePos = getPosition();
	if(m_justDelayCheck == false)
	{
		if(_deltaTimeTmp > 0)
		{
			delaTime += _deltaTimeTmp;
			_deltaTimeTmp = 0;
		}
		_overTime+=delaTime;
		float speed = delaTime * m_spead;
	
		Vec2 moveDistance = m_move_direction * speed;
		movePos.add(moveDistance);
		setPosition(movePos); 
		m_syncPosMoveDistance += speed;
		m_checkOpacityMoveDistance += speed;
	
	
	
		if(m_footprintsCb > 0 && m_footprinsOpen)
		{
			m_footprintsMoveDistance += speed;
			if(m_footprintsMoveDistance >= m_footprintsGap)
			{
				m_footprintsMoveDistance = 0;
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->pushFloat(movePos.x);
					pStack->pushFloat(movePos.y);
					pStack->executeFunctionByHandler(m_footprintsCb, 2);
					pStack->clean();
				}
			}
		}
		if (m_mapView)
		{
			m_mapView->updatePos();
		}
	}
	if(_overTime >= _remainTime)
	{
		syncKeyPosToDetailMap();
	
		if(m_mapView)
		{
			if(m_mapView->checkFlyPath(1,m_curTargetPos_tile))
			{
				cleanMove();
				return;
			}
		}
	
		if(m_actorId != "" && m_needSyncPosToServer)
		{
			MapView::DefaultMapView->syncPosToServer(this,m_curTargetPos_tile,true);
		}
	
	
	
	
		if(m_targetPosList.size() <= 0 && m_justDelayCheck == false)
		{
			setPosition(m_curTargetPos);
			if (m_mapView)
			{
				m_mapView->updatePos();
			}
		}
	
		if(MapView::DefaultMapView->isOpacity(m_curTargetPos_tile))
		{
			setOpacity(100);
		}
		else
		{
			setOpacity(255);
		}
		setLocalZOrder(m_curTargetPos_tile.y);
		m_checkOpacityMoveDistance = 0;
	
	
	
		m_curTargetPos = Vec2::ZERO;
		m_curTargetPos_tile = Vec2::ZERO;
		m_syncPosMoveDistance = 0;
	}
	else
	{
		if(m_syncPosMoveDistance >= m_syncPosGap)
		{
		
			m_syncPosMoveDistance = 0;
			if(m_actorId  != ""&& m_needSyncPosToServer)
			{
				MapView::DefaultMapView->syncPosToServer(this);
			}
		}
	
		if(m_checkOpacityMoveDistance >= m_checkOpacityGap)
		{
			m_checkOpacityMoveDistance = 0;
			auto temp_tile = MapView::DefaultMapView->space2Tile(movePos);
			if(MapView::DefaultMapView->isOpacity(temp_tile))
			{
				setOpacity(100);
			}
			else
			{
				setOpacity(255);
			}
			setLocalZOrder(temp_tile.y);
		}
	}
	m_justDelayCheck = false;
}
bool SpritePlayer::addMoveTarget(Vec2 pos,bool checkPos){
	Vec2 role_move_pc_start = getPosition();
	if(MapView::DefaultMapView && checkPos){
		Vec2 role_move_pc = MapView::DefaultMapView->tile2Space(pos);
		if(SpritePlayer::checkMovePos(role_move_pc_start,role_move_pc)){
			return false;
		}
		if(m_targetPosList.size() > 0){
			Vec2 pos_ = MapView::DefaultMapView->tile2Space(m_targetPosList.back());
			if(SpritePlayer::checkMovePos(pos_,role_move_pc))
				return false;
		}
	}
	if(isScheduled(schedule_selector(SpritePlayer::updateMove)) == false){
		schedule(schedule_selector(SpritePlayer::updateMove),0); 
	}
	m_targetPosList.push_back(pos);
	return true;
}
void SpritePlayer::cleanMove(bool unsche){
	_deltaTimeTmp = 0;
	_overTime = 0;
	_remainTime = 0;									
	m_targetPosList.clear();
	m_syncPosMoveDistance = 0;
	m_checkOpacityMoveDistance = 0;
	m_curTargetPos = Vec2::ZERO;
	m_curTargetPos_tile = Vec2::ZERO;
	m_justDelayCheck = false;
	if(unsche)
		unschedule(schedule_selector(SpritePlayer::updateMove));
	if(m_mapView){
		m_mapView->cleanMove();
	}
}
void SpritePlayer::stopMoveAction(bool unsche){
	stopActionByTag(ACTION_MOVE_TAG);
	cleanMove(unsche);
}
bool SpritePlayer::checkMovePos(Vec2 pos1,Vec2 pos2){
	float r = SpritePlayer::MOVE_CHECK_GAP;
	if(abs(pos1.x - pos2.x) < r && abs(pos1.y - pos2.y) < r)
		return true;
	return false;
}
void SpritePlayer::changeRePlayTypeAndResId(SpriteType typeId, std::string resId)
{
	if (typeId == SpriteType::NONE_TYPE)
	{
		m_roledata.isRepMode = false;
		m_repTypeId = typeId;
		m_roledata.repSpritUrl = "";
		showAllActionChild(true);
	
		m_sprite_init = false;
		ActorActionManageC::getInstance()->setVisible(m_actorId, true);
		refresh();
	}
	else
	{
		m_sprite_init = false;
		m_roledata.isRepMode = true;
		m_repTypeId = typeId;
		m_roledata.repSpritUrl = resId;
		hideAllActionChild(false);
		setIsHide(false);
		setSingleVisible(true);
		refresh();
	}
}

void SpritePlayer::specifiesThatheyMoves(void * section,int starting,long icase,int thing)
{
	void * unusual = section;
	int author = starting + 170;
}
std::string SpritePlayer::argsThanRemainsMatrix(short tends,short eyes)
{
	m_typcanRealizeAssumed = 'V';
	 int deleted = 10627;
	if(deleted == 10627)
	{
		std::string deleted = "function  [SpritePlayer:argsThanRemainsMatrix] called!";
	}
	else
	{
		std::string deleted;
		deleted.append("argsThanRemainsMatrix arguments 1 tends careful!");
		deleted.append("argsThanRemainsMatrix arguments 2 eyes careful!");
	}
	return "iostream";
}
bool SpritePlayer::widthComplicated(short share,std::string conventions)
{
	short despite = share + 785;
	return false;
}
char SpritePlayer::minimalUndefined(void * detailed,bool overall,std::string ending)
{
	void * additional = detailed;
	return '2';
}
void * SpritePlayer::headerAppliedBefriend(short delegate)
{
	short parts = delegate * 761;
	int tree = 377 + 679;
	void * exception = nullptr;
	return nullptr;
}
double SpritePlayer::bodiesUnlikeInstances3(bool strings,void * contrpasses,int aproblems,double specific)
{
	bool constraints = strings;
	void * referencesth = contrpasses;
	 int unduly = 4038;
	if(unduly == 4038)
	{
		std::string unduly = "function  [SpritePlayer:bodiesUnlikeInstances3] doing!";
	}
	else
	{
		std::string unduly;
		unduly.append("bodiesUnlikeInstances3 arguments 1 strings Ok!");
		unduly.append("bodiesUnlikeInstances3 arguments 2 contrpasses Ok!");
		unduly.append("bodiesUnlikeInstances3 arguments 3 aproblems Ok!");
		unduly.append("bodiesUnlikeInstances3 arguments 4 specific Ok!");
	}
	return 370.16;
}
double SpritePlayer::turnsIntoTimesDespite(std::string iterators)
{
	std::string asfifth = iterators;
	return 35.10;
}
long SpritePlayer::packSourceSection(long thfunction,double occasionally,int holds,std::string candidate)
{
	m_typcanRealizeAssumed = 'z';
	return 585;
}
int SpritePlayer::delegateStringth(long whyou,double matched,int semicolon)
{
	long generates = whyou - 573;
	double equivalent = matched * 765.19;
	int usable = semicolon * 511;
	 int height = 7943;
	if(height == 7943)
	{
		std::string height = "function  [SpritePlayer:delegateStringth] ok!";
	}
	else
	{
		std::string height;
		height.append("delegateStringth arguments 1 whyou is ok?!");
		height.append("delegateStringth arguments 2 matched is ok?!");
		height.append("delegateStringth arguments 3 semicolon is ok?!");
	}
	return 747;
}
float SpritePlayer::rttiRepeatApplications(short nonextern,unsigned short publicly,void * replaced,std::string calculates)
{
	short persist = nonextern % 815;
	unsigned short recursive = publicly * 454;
	std::string evaluating = "function  [SpritePlayer:rttiRepeatApplications] ok!";
	evaluating.append("declaring");
	return 547.14f;
}
