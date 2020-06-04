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

//设置血条和名字状态  TRUE表示常驻显示  FALSE表示不显示
void SpriteMonster::setNameAndBloodShow(bool show){
	//m_name_label->setVisible(show);
	//m_blood_bg->setVisible(show);
	int show_state = show == true?1:0;
	syncNameAndBloodShow(show_state,show_state);
	if(show == true){
		m_showNameAndBloodState = 1;

		//int content_h = main_sprite->getContentSize().height;
		//show_h =  main_sprite->getTextureRect().size.height;

		//m_blood_bg->setPosition(0,show_h);
		//m_name_label->setPosition(Point(0,show_h+15) );
	}
	else
		m_showNameAndBloodState = 2;
}

void SpriteMonster::syncNameAndBloodShow(int name_show,int blood_show){
	//if (m_syncActionCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		if(name_show != -1){
	//			pStack->pushInt(1);
	//			pStack->pushInt(m_actorId);
	//			pStack->pushInt(static_cast<int>(ActorComponentType::Name));
	//			pStack->pushBoolean(name_show == 1?true:false);
	//			pStack->executeFunctionByHandler(m_syncActionCb, 4);
	//			pStack->clean();
	//		}

	//		if(blood_show != -1){
	//			pStack->pushInt(1);
	//			pStack->pushInt(m_actorId);
	//			pStack->pushInt(static_cast<int>(ActorComponentType::BloodPro));
	//			pStack->pushBoolean(blood_show == 1?true:false);
	//			pStack->executeFunctionByHandler(m_syncActionCb, 4);
	//			pStack->clean();
	//		}
	//	}
	//}else{
	//	m_name_label->setVisible(name_show == 1?true:false);
	//	m_blood_bg->setVisible(blood_show == 1?true:false);
	//}
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
				//pStack->pushInt(1);
				//pStack->pushInt(m_actorId);
				//pStack->pushInt(static_cast<int>(ActorComponentType::Name));
				//pStack->pushBoolean(name_show == 1?true:false);
				//pStack->executeFunctionByHandler(m_syncActionCb, 4);
				//pStack->clean();
				ActorActionManageC::getInstance()->setVisibleCustom(Name,m_actorId,name_show == 1?true:false,false,m_name_label->getParent());
			}

			if(blood_show != -1){
				//pStack->pushInt(1);
				//pStack->pushInt(m_actorId);
				//pStack->pushInt(static_cast<int>(ActorComponentType::BloodPro));
				//pStack->pushBoolean(blood_show == 1?true:false);
				//pStack->executeFunctionByHandler(m_syncActionCb, 4);
				//pStack->clean();

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
		//m_name_label->setVisible(show);
		//m_blood_bg->setVisible(show);
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

	/*
	m_blood_bg->setPosition(0, show_h);
	m_name_label->setPosition(Point(0, show_h+15));
	*/
	//if (m_updateTopHeadPosCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorId);
	//		pStack->pushInt(x);
	//		pStack->pushInt(y);
	//		pStack->pushInt(show_h);
	//		pStack->pushBoolean(name_show);
	//		pStack->executeFunctionByHandler(m_updateTopHeadPosCb, 5);
	//		pStack->clean();
	//	}
	//}
}

void SpriteMonster::subBlood(int64 blood)
{
	m_hp -= blood;
	/*sub_pecent = ((float)blood * 5)/m_maxhp;*/
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

	if (update_pecent < 0 )
	{
		update_pecent = 0;
	}
	else if (update_pecent > 1)
	{
		update_pecent = 1;
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
	int tmpSymbolKey1[] = {}; //"blood/sbloodbk.png"
	std::string str1 = HandleString(tmpSymbolKey1, STRNUMSIG);
	const char* key1 = str1.c_str();

	int tmpSymbolKey2[] = {}; //"blood/sblood.png"
	std::string str2 = HandleString(tmpSymbolKey2, STRNUMSIG);
	const char* key2 = str2.c_str();

	int tmpSymbolKey3[] = {}; //"blood/sblood_yellow.png"
	std::string str3 = HandleString(tmpSymbolKey3, STRNUMSIG);
	const char* key3 = str3.c_str();

	int tmpSymbolKey4[] = {}; //"blood/pblood_green.png"
	std::string str4 = HandleString(tmpSymbolKey4, STRNUMSIG);
	const char* key4 = str4.c_str();

	int tmpSymbolKey5[] = {}; //"blood/pblood_red.png"
	std::string str5 = HandleString(tmpSymbolKey5, STRNUMSIG);
	const char* key5 = str5.c_str();

	int tmpSymbolKey6[] = {}; //"blood/bblood_bg.png"
	std::string str6 = HandleString(tmpSymbolKey6, STRNUMSIG);
	const char* key6 = str6.c_str();

	int tmpSymbolKey7[] = {}; //"blood/pblood_blue.png"
	std::string str7 = HandleString(tmpSymbolKey7, STRNUMSIG);
	const char* key7 = str7.c_str();

	int tmpSymbolKey8[] = {}; //"res/blood/blood.plist"
	std::string str8 = HandleString(tmpSymbolKey8, STRNUMSIG);
	const char* key8 = str8.c_str();

	int tmpSymbolKey9[] = {}; //"blood/pblood_bg.png"
	std::string str9 = HandleString(tmpSymbolKey9, STRNUMSIG);
	const char* key9 = str9.c_str();

	int tmpSymbolKey11[] = {}; //"blood/pblood_yellow.png"
	std::string str11 = HandleString(tmpSymbolKey11, STRNUMSIG);
	const char* key11 = str11.c_str();

	int tmpSymbolKey12[] = {}; //"blood/bblood_red.png"
	std::string str12 = HandleString(tmpSymbolKey12, STRNUMSIG);
	const char* key12 = str12.c_str();

	int tmpSymbolKey13[] = {}; //"blood/bblood_yellow.png"
	std::string str13 = HandleString(tmpSymbolKey13, STRNUMSIG);
	const char* key13 = str13.c_str();

	std::string bloodBg = key1;//"blood/sbloodbk.png";
	std::string bloodBar = key2;//"blood/sblood.png";
	std::string bloodBack = key3;//"blood/sblood_yellow.png";
	Vec2 barPosOffset = Vec2::ZERO;
	switch (typeId)
	{
	case 1:
		//怪物血条
		bloodBg = key1;//"blood/sbloodbk.png";
		bloodBar = key2;//"blood/sblood.png";
		bloodBack = key3;//"blood/sblood_yellow.png";
		break;
	case 2:
		//玩家血条 绿色
		bloodBg = key9;//"blood/pblood_bg.png";
		bloodBar = key4;//"blood/pblood_green.png";
		bloodBack = key11;// "blood/pblood_yellow.png";
		break;
	case 3:
		//玩家血条 红色
		bloodBg = key9;//"blood/pblood_bg.png";
		bloodBar = key5;//"blood/pblood_red.png";
		bloodBack = key11;//"blood/pblood_yellow.png";
		break;
	case 4:
		//玩家血条 蓝色 （行会战期间 行会其它玩家）
		bloodBg = key9;//"blood/pblood_bg.png";
		bloodBar = key7;//"blood/pblood_blue.png";
		bloodBack = key11;//"blood/pblood_yellow.png";
		break;
	case 5:
		//boss血条
		bloodBg = key6;//"blood/bblood_bg.png";
		bloodBar = key12;//"blood/bblood_red.png";
		bloodBack = key13;//"blood/bblood_yellow.png";
		barPosOffset.x = 5;
		break;
	default:
		break;
	}

	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(key1);//"blood/sbloodbk.png"
	if (!frame)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(key8);//"res/blood/blood.plist"
	}

	SpriteFrame* frame_bg = SpriteFrameCache::getInstance()->getSpriteFrameByName(bloodBg);
	m_blood_bg->setSpriteFrame(frame_bg);
	//m_blood_bg->initWithSpriteFrameName(bloodBg);
	//Sprite* blood = Sprite::createWithSpriteFrameName(bloodBar);
	//m_blood_pro->setSprite(blood);
	//m_blood_pro->setSpriteFrame()
	SpriteFrame* frame_pro = SpriteFrameCache::getInstance()->getSpriteFrameByName(bloodBar);
	m_blood_pro->setSpriteFrame(frame_pro);
	m_blood_pro->setPositionX(m_blood_pro->getPositionX() + barPosOffset.x);

	//Sprite* blood2 = Sprite::createWithSpriteFrameName(bloodBack);
	//m_blood_back->setSprite(blood2);
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

	//	if (MapView::DefaultMapView == nullptr)
	//	{
	//		return true;
	//	}

	//if (!isMainRole)
	//{
	auto shadow_node = Node::create();
	shadow_node->setCascadeOpacityEnabled(true);

	int tmpSymbolKey10[] = {}; //"res/shadow.png"
	std::string strM = HandleString(tmpSymbolKey10, STRNUMSIG);	
	shadow_sprite = Sprite::create(strM.c_str());
	shadow_sprite->setScale(1.2f);
	shadow_sprite->setTag(1);
	shadow_node->addChild(shadow_sprite);
	// 角色id大于0 表示由服务器创建 启用优化（角色所有部件分别放在单度层）
	// 小于等于0 表示由本地创建 不启用优化（角色所有部件还是放角色身上）
	if (m_actorId != "") 
	{
		//MapView::DefaultMapView->addTopHeadNodeToMap(static_cast<int>(ActorComponentType::Shadow), shadow_sprite, m_actorId, 0);
		ActorActionManageC::getInstance()->addComponent(Shadow,shadow_node,m_actorId,0);
	}
	else 
	{
		addChild(shadow_node, 1, 117);
	}
	//}

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
		//MapView::DefaultMapView->addTopHeadNodeToMap(static_cast<int>(ActorComponentType::Name), m_name_label, m_actorId, 0);
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

	int tmpSymbolKey3[] = {}; //"blood/sbloodbk.png"
	std::string strA = HandleString(tmpSymbolKey3, STRNUMSIG);	
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(strA.c_str());
	if (!frame)
	{
		int tmpSymbolKey4[] = {}; //"res/blood/blood.plist"
		std::string strB = HandleString(tmpSymbolKey4, STRNUMSIG);	
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(strB.c_str());
	}

	auto m_blood_node = Node::create();
	m_blood_node->setCascadeOpacityEnabled(true);	
	m_blood_bg = Sprite::createWithSpriteFrameName(strA.c_str());
	m_blood_bg->setAnchorPoint(Vec2(0.5, 0.5));
	m_blood_bg->setCascadeOpacityEnabled(true);
	m_blood_bg->setTag(1);
	m_blood_node->addChild(m_blood_bg);
	if (m_actorId != "") 
	{
		//MapView::DefaultMapView->addTopHeadNodeToMap(static_cast<int>(ActorComponentType::BloodPro), m_blood_bg, m_actorId, 0);
		ActorActionManageC::getInstance()->addComponent(BloodPro,m_blood_node,m_actorId,0);
	}
	else
	{
		addChild(m_blood_node,122);
	}

	//创建血条缓动背景
	//m_blood_back = ProgressTimer::create(Sprite::createWithSpriteFrameName("blood/sblood_yellow.png")) ;
	//m_blood_back->setPosition(1, 0);
	//m_blood_back->setType(ProgressTimer::Type::BAR);
	//m_blood_back->setAnchorPoint(Point(0.0, 0.0));
	//m_blood_back->setBarChangeRate(Point(1, 0));
	//m_blood_back->setMidpoint(Point(0, 1));
	//m_blood_back->setPercentage(100);
	//m_blood_back->setTag(2);
	//m_blood_bg->addChild(m_blood_back);
	int tmpSymbolKey30[] = {}; //"blood/sblood_yellow.png"
	std::string key1 = HandleString(tmpSymbolKey30, STRNUMSIG);	
	m_blood_back = Sprite::createWithSpriteFrameName(key1.c_str());
	m_blood_back->setAnchorPoint(Vec2(0,0));
	m_blood_back->setTag(2);
	m_blood_bg->addChild(m_blood_back);

	//创建血条
	//m_blood_pro = ProgressTimer::create(Sprite::createWithSpriteFrameName("blood/sblood.png")) ;
	//m_blood_pro->setPosition(1, 0);
	//m_blood_pro->setType(ProgressTimer::Type::BAR);
	//m_blood_pro->setAnchorPoint(Point(0.0, 0.0));
	//m_blood_pro->setBarChangeRate(Point(1, 0));
	//m_blood_pro->setMidpoint(Point(0, 1));
	//m_blood_pro->setPercentage(100);
	//m_blood_pro->setTag(1);
	//m_blood_bg->addChild(m_blood_pro);
	int tmpSymbolKey31[] = {}; //"blood/sblood.png"
	std::string key2 = HandleString(tmpSymbolKey31, STRNUMSIG);
	m_blood_pro = Sprite::createWithSpriteFrameName(key2.c_str());
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

void SpriteMonster::setHP(int64 hp)
{
	m_hp = hp;
	if(m_hp<m_maxhp && m_hp>0){
		//showNameAndBlood(true,true,show_h);
	}
	else if(m_hp<=0)
	{
		showNameAndBlood(0,0,show_h);
	}

	//if(hp == 1) 
	//	hp = 0;
	//if(m_maxhp < hp)
	//	m_maxhp = hp;
    if (hp < 0)
    {
        hp = 0;
    }

	float update_pecent = (float)hp/m_maxhp;
	if (update_pecent < 0 )
	{
		update_pecent = 0;
	}
	else if (update_pecent > 1)
	{
		update_pecent = 1;
	}

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

	//if (m_setPositionCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorType);
	//		pStack->pushInt(m_actorId);
	//		pStack->pushFloat(position.x);
	//		pStack->pushFloat(position.y);
	//		pStack->executeFunctionByHandler(m_setPositionCb, 4);
	//		pStack->clean();
	//	}
	//}
	if(m_setPositionCb > 0 && m_actorId != ""){
		ActorActionManageC::getInstance()->setPosition(m_actorId,position.x,position.y);
	}
}
void SpriteMonster::setPosition(float x, float y)
{
	Node::setPosition(x, y);

	//if (m_setPositionCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorType);
	//		pStack->pushInt(m_actorId);
	//		pStack->pushFloat(x);
	//		pStack->pushFloat(y);
	//		pStack->executeFunctionByHandler(m_setPositionCb, 4);
	//		pStack->clean();
	//	}
	//}
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
	//int value = calculationArrival(PLAYER_FEMALE_TYPE, 4);
	setOrderOfArrival(arrival);
	// 角色id大于0 表示由服务器创建 启用优化（角色所有部件分别放在单独层）
	// 小于等于0 表示由本地创建 不启用优化（角色所有部件还是放角色身上）
	//if (m_setLocalZOrderCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorId);
	//		pStack->pushInt(localZOrder);
	//		pStack->pushInt(value);
	//		pStack->executeFunctionByHandler(m_setLocalZOrderCb, 3);
	//		pStack->clean();
	//	}
	//}
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
	if(getCurrActionState() >= ACTION_STATE_DEAD || getCurrActionState() == ACTION_STATE_FLY || getCurrActionState() == ACTION_STATE_SUDDEN)//|| getCurrActionState() == ACTION_STATE_ATTACK
		return false;
	return true;
}

//移动缓动循环
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
			//计算玩家移动方向单元值
			//计算移动的方向
			//播放移动动画
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

	//判断是否触发足迹
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

	//SpritePlayer::checkMovePos(movePos,m_curTargetPos
	if(_overTime >= _remainTime){
		//TODO 发送协议同步关键点位置
		if(m_actorId != "" && m_needSyncPosToServer){
			MapView::DefaultMapView->syncPosToServer(this,m_curTargetPos_tile);
		}
		//if(_overTime > _remainTime){
		//	_deltaTimeTmp = _overTime - _remainTime;
		//	setPosition(m_curTargetPos);
		//}
		if(m_targetPosList.size() <= 0)
			setPosition(m_curTargetPos);

		//TODO 检查半透明情况
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
			//TODO 发送协议给服务器同步位置
			m_syncPosMoveDistance = 0;

			if(m_actorId  != "" && m_needSyncPosToServer){
				auto temp_tile = MapView::DefaultMapView->space2Tile(movePos);
				MapView::DefaultMapView->syncPosToServer(this,temp_tile);
			}
		}

		//TODO 检查半透明情况
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
//添加移动目标点
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
	//CPLUSLog("[SpriteMonster::addMoveTarget]  pos =%f, %f", pos.x, pos.y);
	m_targetPosList.push_back(pos);
	return true;
}
//停止移动
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