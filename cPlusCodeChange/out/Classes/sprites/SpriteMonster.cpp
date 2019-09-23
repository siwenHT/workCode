#include "SpriteMonster.h"
#include "CCLuaEngine.h"
#include "MapView.h"
#include "ActorActionManageC.h"
USING_NS_CC;
SpriteMonster::SpriteMonster()
{
	shadow_sprite = NULL;
	m_maxhp = 1;
	show_h = 0;
	m_hp = 0;
	m_showNameAndBloodState = 0;
	m_isBloodVisible = true;
	m_blood_back = nullptr;
	m_blood_pro = nullptr;
	m_setPositionCb = 0;
	m_updateTopHeadPosCb = 0;
	m_setLocalZOrderCb = 0;
	m_footprintsCb = 0;
	m_footprintsGap = 100;
	m_footprintsMoveDistance = 0;
	m_footprinsOpen = false;
	m_monster_id = 0;
	_deltaTimeTmp = 0;
	_overTime = 0;
	_remainTime = 0;									
	m_curTargetPos = Vec2::ZERO;
	m_curTargetPos_tile = Vec2::ZERO;
	m_targetPosList.clear();
	m_syncPosGap = 100;
	m_syncPosMoveDistance = 0;
	m_checkOpacityGap = 50;
	m_checkOpacityMoveDistance = 0;
	m_spead = 200;
	m_justDelayCheck = false;
	m_needSyncPosToServer = false;
	m_name_label = nullptr;
	m_showBloodAnim = true;
}
SpriteMonster::~SpriteMonster(void)
{
}
void SpriteMonster::setNameAndBloodShow(bool show){
	int show_state = show == true?1:0;
	syncNameAndBloodShow(show_state,show_state);
	if(show == true){
		m_showNameAndBloodState = 1;
	
	
	
	
	}
	else
		m_showNameAndBloodState = 2;
}
void SpriteMonster::syncNameAndBloodShow(int name_show,int blood_show){
	if(m_isBloodVisible)
	{
		blood_show == 1 ? true : false;
	}
	else
	{
		blood_show = false;
	}
	if (m_syncActionCb > 0 && m_actorId != "")
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			if(name_show != -1){
			
			
			
			
			
			
				ActorActionManageC::getInstance()->setVisibleCustom(Name,m_actorId,name_show == 1?true:false,false,m_name_label->getParent());
			}
			if(blood_show != -1){
			
			
			
			
			
			
				ActorActionManageC::getInstance()->setVisibleCustom(BloodPro,m_actorId,blood_show == 1?true:false,false,m_blood_bg->getParent());
			}
		}
	}else{
		m_name_label->getParent()->setVisible(name_show == 1?true:false);
		m_blood_bg->getParent()->setVisible(blood_show == 1?true:false);
	}
}
void SpriteMonster::setBloodVisible(bool isVisible)
{
	m_isBloodVisible = isVisible;
	if (m_syncActionCb > 0 && m_actorId != "")
	{
		ActorActionManageC::getInstance()->setVisibleCustom(BloodPro, m_actorId, isVisible, false, m_blood_bg->getParent());
	}
	else
	{
		m_blood_bg->getParent()->setVisible(isVisible);
	}
}
void SpriteMonster::showNameAndBlood(int name_show,int blood_show,int height,bool checkHp)
{
	if(checkHp && m_hp <= 0)
	{
		m_showNameAndBloodState = 0;
		name_show = false;
		blood_show = false;
	}
	if(m_showNameAndBloodState == 0)
	{
	
	
		syncNameAndBloodShow(name_show,blood_show);
	}
	if(height != 0)
	{
		show_h = height;
	}
	if(show_h == 0)
	{
		if(m_sprite_init){
			int content_h = main_sprite->getContentSize().height;
			show_h =  main_sprite->getTextureRect().size.height;
		}
	}
	if(!(m_actorId != "" && m_spriteInitCb > 0)){
		int x = this->getPositionX();
		int y = this->getPositionY();
		m_blood_bg->setPosition(0, show_h);
		m_name_label->setPosition(0, show_h+17);
	}
}
void SpriteMonster::subBlood(int blood)
{
	m_hp -= blood;
	if(m_hp<=0)
	{
		update_pecent = 0;
		m_hp = 0;
		showNameAndBlood(0,0,show_h);
	}
	else 
	{
		if(m_hp > m_maxhp)
			m_hp = m_maxhp;
		update_pecent = ((float)m_hp/m_maxhp);
		showNameAndBlood(-1,1,show_h);
		m_blood_pro->setScaleX(update_pecent);
	}
	if(m_blood_bg->isVisible())
	{
		if(m_showBloodAnim){
			float old_pecent = m_blood_back->getScaleX();
			sub_pecent = 0;
			if(old_pecent > update_pecent)
				sub_pecent = (old_pecent-update_pecent)/10;
			if(isScheduled(schedule_selector(SpriteMonster::updateBloodAction)) == false)
				schedule(schedule_selector(SpriteMonster::updateBloodAction), 0.02f); 
		}else{
			m_blood_back->setScaleX(update_pecent);
		}
	}
}
void SpriteMonster::updateBloodAction(float times)
{
	float old_pecent = m_blood_back->getScaleX();
	if(old_pecent>update_pecent)
	{
		m_blood_back->setScaleX(old_pecent-sub_pecent);
	}
	else
	{
		m_blood_back->setScaleX(update_pecent);
		unschedule(schedule_selector(SpriteMonster::updateBloodAction));
	}
}
bool SpriteMonster::isAlive()
{
	ActionState state = getCurrActionState();
	return state&&(state < ACTION_STATE_DEAD || getHP()>0);
}
void SpriteMonster::setBloodType(int typeId)
{
	std::string bloodBg = "blood/sbloodbk.png";
	std::string bloodBar = "blood/sblood.png";
	std::string bloodBack = "blood/sblood_yellow.png";
	Vec2 barPosOffset = Vec2::ZERO;
	switch (typeId)
	{
	case 1:
	
		bloodBg = "blood/sbloodbk.png";
		bloodBar = "blood/sblood.png";
		bloodBack = "blood/sblood_yellow.png";
		break;
	case 2:
	
		bloodBg = "blood/pblood_bg.png";
		bloodBar = "blood/pblood_green.png";
		bloodBack = "blood/pblood_yellow.png";
		break;
	case 3:
	
		bloodBg = "blood/pblood_bg.png";
		bloodBar = "blood/pblood_red.png";
		bloodBack = "blood/pblood_yellow.png";
		break;
	case 4:
	
		bloodBg = "blood/pblood_bg.png";
		bloodBar = "blood/pblood_blue.png";
		bloodBack = "blood/pblood_yellow.png";
		break;
	case 5:
	
		bloodBg = "blood/bblood_bg.png";
		bloodBar = "blood/bblood_red.png";
		bloodBack = "blood/bblood_yellow.png";
		barPosOffset.x = 5;
		break;
	default:
		break;
	}
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("blood/sbloodbk.png");
	if (!frame)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/blood/blood.plist");
	}
	SpriteFrame* frame_bg = SpriteFrameCache::getInstance()->getSpriteFrameByName(bloodBg);
	m_blood_bg->setSpriteFrame(frame_bg);
	SpriteFrame* frame_pro = SpriteFrameCache::getInstance()->getSpriteFrameByName(bloodBar);
	m_blood_pro->setSpriteFrame(frame_pro);
	m_blood_pro->setPositionX(m_blood_pro->getPositionX() + barPosOffset.x);
	SpriteFrame* frame_back = SpriteFrameCache::getInstance()->getSpriteFrameByName(bloodBack);
	m_blood_back->setSpriteFrame(frame_back);
	m_blood_back->setPositionX(m_blood_back->getPositionX() + barPosOffset.x);
}
bool SpriteMonster::initWithFileExt(const std::string&pszFileName, std::string actorId, bool isMainRole)
{
	if(!initWithFile(pszFileName, actorId))
	{
		return false;
	}
	auto shadow_node = Node::create();
	shadow_node->setCascadeOpacityEnabled(true);
	shadow_sprite = Sprite::create("res/shadow.png");
	shadow_sprite->setScale(1.2f);
	shadow_sprite->setTag(1);
	shadow_node->addChild(shadow_sprite);
	if (m_actorId != "") 
	{
	
		ActorActionManageC::getInstance()->addComponent(Shadow,shadow_node,m_actorId,0);
	}
	else 
	{
		addChild(shadow_node, 1, 117);
	}
	auto m_name_node = Node::create();
	m_name_node->setCascadeOpacityEnabled(true);
	m_name_label = Node::create();
	m_name_label->setCascadeOpacityEnabled(true);
	m_name_label->setScale(1.2f);
	m_name_label->setAnchorPoint(Point(0.5, 0) );
	m_name_label->setTag(1);
	m_name_node->addChild(m_name_label);
	if (m_actorId != "") 
	{
	
		ActorActionManageC::getInstance()->addComponent(Name,m_name_node,m_actorId,0);
	}
	else
	{
		addChild(m_name_node,122,123);
	}
	m_title_label = Node::create();
	m_title_label->setAnchorPoint(Point(0.5, 0.5) );
	addChild(m_title_label, 122, 150);
	m_time_label = Node::create();
	m_time_label->setAnchorPoint(Point(0.5, 0.5) );
	addChild(m_time_label,122,123);
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("blood/sbloodbk.png");
	if (!frame)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/blood/blood.plist");
	}
	auto m_blood_node = Node::create();
	m_blood_node->setCascadeOpacityEnabled(true);
	m_blood_bg = Sprite::createWithSpriteFrameName("blood/sbloodbk.png");
	m_blood_bg->setAnchorPoint(Vec2(0.5, 0.5));
	m_blood_bg->setCascadeOpacityEnabled(true);
	m_blood_bg->setTag(1);
	m_blood_node->addChild(m_blood_bg);
	if (m_actorId != "") 
	{
	
		ActorActionManageC::getInstance()->addComponent(BloodPro,m_blood_node,m_actorId,0);
	}
	else
	{
		addChild(m_blood_node,122);
	}
	m_blood_back = Sprite::createWithSpriteFrameName("blood/sblood_yellow.png");
	m_blood_back->setAnchorPoint(Vec2(0,0));
	m_blood_back->setTag(2);
	m_blood_bg->addChild(m_blood_back);
	m_blood_pro = Sprite::createWithSpriteFrameName("blood/sblood.png");
	m_blood_pro->setAnchorPoint(Vec2(0,0));
	m_blood_pro->setTag(1);
	m_blood_bg->addChild(m_blood_pro);
	showNameAndBlood(0,0,show_h);
	return true;
}
SpriteMonster *SpriteMonster::create(const std::string&pszFileName, std::string actorId)
{
	SpriteMonster *pRet = new SpriteMonster();
	if (pRet && pRet->initWithFileExt(pszFileName, actorId))
	{
		pRet->setActorType(ActorType::Monster);
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}
void SpriteMonster::setHP(uint64 hp)
{
	m_hp = hp;
	if(m_hp<m_maxhp && m_hp>0){
	
	}
	else if(m_hp<=0)
	{
		showNameAndBlood(0,0,show_h);
	}
	if(m_maxhp < hp)
		m_maxhp = hp;
	float update_pecent = (float)hp/m_maxhp;
	m_blood_pro->setScaleX(update_pecent);
	m_blood_back->setScaleX(update_pecent);
	unschedule(schedule_selector(SpriteMonster::updateBloodAction));
}
int SpriteMonster::getShowHeight()
{
	return (show_h == 0 ? 130 : show_h);
}
void SpriteMonster::setNameSize(cocos2d::Size& size)
{
	m_nameSize = size;
}
cocos2d::Size SpriteMonster::getNameSize(void)
{
	return m_nameSize;
}
void SpriteMonster::setPosition(const Vec2& position)
{
	Node::setPosition(position);
	if(m_setPositionCb > 0 && m_actorId != ""){
		ActorActionManageC::getInstance()->setPosition(m_actorId,position.x,position.y);
	}
}
void SpriteMonster::setPosition(float x, float y)
{
	Node::setPosition(x, y);
	if(m_setPositionCb > 0 && m_actorId!=""){
		ActorActionManageC::getInstance()->setPosition(m_actorId,x,y);
	}
}
void SpriteMonster::setLocalZOrder(int localZOrder)
{
	if ((localZOrder%2) == 1)
	{
		localZOrder = localZOrder + 1;
	}
	if (getLocalZOrder() == localZOrder)
	{
		return;
	}
	int arrival = getOrderOfArrival();
	Node::setLocalZOrder(localZOrder);
	setOrderOfArrival(arrival);
	if(m_setLocalZOrderCb > 0 && m_actorId != ""){
		ActorActionManageC::getInstance()->setLocalZOrder(m_actorId,localZOrder,arrival);
	}
}
void SpriteMonster::registerSetLocalZOrderCb(int handler)
{
	m_setLocalZOrderCb = handler;
}
void SpriteMonster::removeSetLocalZOrderCb()
{
	m_setLocalZOrderCb = 0;
}
void SpriteMonster::registerSetPositionCb(int handler)
{
	m_setPositionCb = handler;
}
void SpriteMonster::removeSetPositionCb()
{
	m_setPositionCb = 0;
}
void SpriteMonster::registerUpdateTopHeadPosCb(int handler)
{
	m_updateTopHeadPosCb = handler;
}
void SpriteMonster::removeUpdateTopHeadPosCb()
{
	m_updateTopHeadPosCb = 0;
}
void SpriteMonster::registerFootprintsCb(int handler){
	m_footprintsCb = handler;
}
void SpriteMonster::removeFootprintsCb(){
	m_footprintsCb = 0;
}
bool SpriteMonster::canMove(){
	if(getCurrActionState() >= ACTION_STATE_DEAD || getCurrActionState() == ACTION_STATE_ATTACK || getCurrActionState() == ACTION_STATE_FLY || getCurrActionState() == ACTION_STATE_SUDDEN)
		return false;
	return true;
}
void SpriteMonster::updateMove(float delaTime){
	if(MapView::DefaultMapView == nullptr)
		return;
	if(canMove() == false)
		return;
	if(m_curTargetPos == Vec2::ZERO){
		if(m_targetPosList.size() <= 0){
			cleanMove();
			standed();
			return;
		}else{
		
		
		
			Vec2 pos = m_targetPosList.front();
			m_targetPosList.pop_front();
			Vec2 role_move_pc_start = getPosition();
			Vec2 role_move_pc_end = MapView::DefaultMapView->tile2Space(pos);
			_overTime = 0;																			
			_remainTime = role_move_pc_start.distance(role_move_pc_end)/m_spead;
			m_curTargetPos = role_move_pc_end;
			m_curTargetPos_tile = pos;
			m_move_direction = (role_move_pc_end - role_move_pc_start).getNormalized();
			Commen_Direction temp_dir = MapView::DefaultMapView->getDirByDirection(m_move_direction);
			stopActionByTag(ACTION_MOVE_TAG);
			bool dirChange = setSpriteDir(temp_dir);
			if(changeState(ACTION_STATE_RUN) || dirChange)
			{
				playAction(0.7f,run,temp_dir,0);
			}
		}
	}
	if(_deltaTimeTmp > 0){
		delaTime += _deltaTimeTmp;
		_deltaTimeTmp = 0;
	}
	_overTime+=delaTime;
	float speed = delaTime * m_spead;
	Vec2 moveDistance = m_move_direction * speed;
	Vec2 movePos = getPosition();
	movePos.add(moveDistance);
	setPosition(movePos);
	bool visible_ = MapView::DefaultMapView->checkVisible(this, nullptr);
	setVisible(visible_);
	setVisibleScreen(visible_);
	m_syncPosMoveDistance += speed;
	m_checkOpacityMoveDistance += speed;
	if(m_footprintsCb > 0 && m_footprinsOpen){
		m_footprintsMoveDistance += speed;
		if(m_footprintsMoveDistance >= m_footprintsGap){
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
	if(_overTime >= _remainTime){
	
		if(m_actorId != "" && m_needSyncPosToServer){
			MapView::DefaultMapView->syncPosToServer(this,m_curTargetPos_tile);
		}
	
	
	
	
		if(m_targetPosList.size() <= 0)
			setPosition(m_curTargetPos);
	
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
	}else{
		if(m_syncPosMoveDistance >= m_syncPosGap){
		
			m_syncPosMoveDistance = 0;
			if(m_actorId  != "" && m_needSyncPosToServer){
				auto temp_tile = MapView::DefaultMapView->space2Tile(movePos);
				MapView::DefaultMapView->syncPosToServer(this,temp_tile);
			}
		}
	
		if(m_checkOpacityMoveDistance >= m_checkOpacityGap){
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
}
bool SpriteMonster::addMoveTarget(Vec2 pos,bool checkPos){
	Vec2 role_move_pc_start = getPosition();
	if(checkPos && MapView::DefaultMapView){
		Vec2 role_move_pc = MapView::DefaultMapView->tile2Space(pos);
		if(SpritePlayer::checkMovePos(role_move_pc_start,role_move_pc))
			return false;
	}
	if(isScheduled(schedule_selector(SpriteMonster::updateMove)) == false){
		schedule(schedule_selector(SpriteMonster::updateMove),0); 
	}
	m_targetPosList.push_back(pos);
	return true;
}
void SpriteMonster::cleanMove(bool unsche){
	_deltaTimeTmp = 0;
	_overTime = 0;
	_remainTime = 0;									
	m_targetPosList.clear();
	m_syncPosMoveDistance = 0;
	m_checkOpacityMoveDistance = 0;
	m_curTargetPos = Vec2::ZERO;
	m_curTargetPos_tile = Vec2::ZERO;
	if(unsche)
		unschedule(schedule_selector(SpriteMonster::updateMove));
}
void SpriteMonster::stopMoveAction(bool unsche){
	stopActionByTag(ACTION_MOVE_TAG);
	cleanMove(unsche);
}
bool SpriteMonster::isMove(){
	if(m_curTargetPos != Vec2::ZERO || m_targetPosList.size() > 0 || getActionByTag(ACTION_MOVE_TAG))
		return true;
	return false;
}
double SpriteMonster::positionedBookno(char user)
{
	char cannot = user;
	return 503.6;
}
long SpriteMonster::correspondsContentCover(short along,long sets,long generated)
{
	short syntactic = along % 385;
	return 506;
}
int SpriteMonster::compileUnderTrivial(short replaced)
{
	m_gradesConverted = 173;
	return 787;
}
double SpriteMonster::matterCorrespondingBook(float limited,short digits,unsigned short treats,float pairs)
{
	m_immediatelyUnderstand = 226;
	return 906.16;
}
bool SpriteMonster::extensionsThingsFigure(float themselves)
{
	float feature = themselves * 803.16f;
	return true;
}
bool SpriteMonster::heightThcallElemeis(float count,short importance,char inform,void * ceases)
{
	float above = count * 20.12f;
	return false;
}
char SpriteMonster::legalThenIathNeeded(void * designer)
{
	m_gradesConverted = 52;
	return 'c';
}
void * SpriteMonster::initializesImagethWhthe(double confusion,double never)
{
	m_gradesConverted = 256;
	return nullptr;
}
