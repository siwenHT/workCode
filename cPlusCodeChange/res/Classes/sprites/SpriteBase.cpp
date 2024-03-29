﻿#include "SpriteBase.h"
#include "../common/FontChina.h"
#include "AsyncDownloadManager.h"
#include "CCLuaEngine.h"

#include "AsyncLoadPlist.h"
#include "ActorActionManageC.h"
#include "ActorRenderQueueManage.h"

//#include "TextureManager.h"

USING_NS_CC;

static const int ActionResNameSize = 19;
static const char* ActionResName[ActionResNameSize] = 
{
	"",          //ACTION_NONE=0,
	"normal",    //run=1,
	"normal",    //stand=2,
	"attack",    //attack=3,
	"",          //hurt = 4,
	"normal",    //death=5,
	"",          //funny=6,
	"",          //magicup=7,
	"normal",    //walk = 8,
	"",          //collide = 9,
	"",          //dig = 10,
	"",          //excavate = 11,
	"",          //create_ = 12,
	"normal",    //standby = 13,
	"fly",       //fly = 14,
	"",          //hurt_idle = 15,
	"",          //hurt_kneel = 16,
	"attack",    //attack_03 = 17,					//17及18统一为突进技能
	"attack"     //attack_04 = 18,
};


/**
   5110701 //角色资源名
 za5110701 //z表示原本zorder z = z*OrderOfArrivalZBase  a表示动作类型 a = a*OrderOfArrivalRBase
 100000000 //OrderOfArrival = z*OrderOfArrivalZBase + a*OrderOfArrivalRBase + 资源id
2147483647 //int 最大值
*/
const int OrderOfArrivalZBase = 100000000;  //setOrderOfArrival zorder基数
const int OrderOfArrivalRBase = 10000000;   //setOrderOfArrival res基数

static const int ActionShowType[ActionResNameSize] = 
{
	// 最大类型只能义到7， 8，9乘骑占用
	0,    //"",          //ACTION_NONE=0,
	1,    //"normal",    //run=1,
	1,    //"normal",    //stand=2,
	2,    //"attack",    //attack=3,
	0,    //"",          //hurt = 4,
	1,    //"normal",    //death=5,
	0,    //"",          //funny=6,
	0,    //"",          //magicup=7,
	1,    //"",          //walk = 8,
	0,    //"",          //collide = 9,
	0,    //"",          //dig = 10,
	0,    //"",          //excavate = 11,
	0,    //"",          //create_ = 12,
	0,    //"",          //standby = 13,
	3,    //"fly",       //fly = 14,
	0,    //"",          //hurt_idle = 15,
	0,    //"",          //hurt_kneel = 16,

	2,    //"attack",    //attack_03 = 17,					//17及18统一为突进技能
	2,    //"attack"     //attack_04 = 18,
};
static const int ActionShowTypeSize = sizeof(ActionShowType)/sizeof(int);

static const int ActionShowType_RideStand = 6; //坐骑站立 单独定义
static const int ActionShowType_RideRun   = 7; //坐骑跑   单独定义

static const int ActionShowType_OnRide = 8; // 乘骑 乘骑不属于动作ActionShowType没有 单独定义

//模型默认帧数，主要是给替换显示使用. 所有种类有限
static int getDefActionNum(SpriteType typeId, Commen_ActionToDo toDo)
{
	switch (toDo)
	{
	case walk:
	case run:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 8;
		else if (typeId == NPC_TYPE)
			return 0;
		else if (typeId == PET_MONSTER)
			return 8;
		break;
	case stand:
	case standby:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 6;
		else if (typeId == NPC_TYPE)
			return 7;
		else if (typeId == PET_MONSTER) 
			return 6;
		break;
	case attack:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 8;
		else if (typeId == PET_MONSTER) 
			return 12;
		break;
	case death:
			return 2;
		break;
	default:
		break;
	}
	return -1;
}

//static	std::mutex _cacheMutex;

SpriteBase::SpriteBase()
{
	stand_inited = false;
	walk_inited = false;
	run_inited = false;
	attack_inited = false;
	hurt_inited = false;
	magic_inited = false;
	death_inited = false;
	fly_inited = false;
	hurt_inited_idle = false;
	hurt_kneel_inited = false;
	attack_rush_inited = false;
	ride_inited = false;
	m_isWhite = false;
	m_touchEnabled = true;
	m_isAddRenderList = false;
	m_openActionCheck = false;
	m_onRide_id = 0;
	main_sprite = NULL;
	m_plist_num = 1;
	m_plist_loadnum = 0;

	m_roledata.dir=  dir_right_up;
	m_roledata.maxcut = 6;
	m_roledata.acttodo = ACTION_NONE;
	m_roledata.actiontime = 1.0f;
	m_roledata.animKey = "";
	m_loop = 0;

	m_rocker_direction = Vec2::ZERO;
	m_move_direction = Vec2::ZERO;
	m_type = BASE_TYPE;
	isactor_flag = true;
	base_url_backUp.clear();
	m_attack_mode = 0;
	m_fly_mode = 1;
	m_shenbingStatus = 0;
	m_showState = SHOW_STATE_EMPTY;
	m_FatherType = SpriteType::BASE_TYPE;

	m_ischeck = true;
	m_isLoadTexture = false;
	m_isLoadPlist = false;

	m_ischecking = false;
	m_isLoadTexturing = false;
	m_isLoadPlisting = false;
	m_isInRenderList = false;

	m_loadPlistEntryId = 0;
	m_loadTextureEntryId = 0;
	m_renderListEntryId = 0;
	updateShowState();
	m_syncReplace = nullptr;
	m_currActionState = ACTION_STATE_NONE;
	m_visibleState = isVisible(); 
	m_resSuffix = "png";	//pvr.ccz png
	m_checkResType = false;
	m_show_plist_path = "";
	m_show_texture_path = "";
	m_async_pvr_path = "";

	m_isOpacAction = false;
	m_actionOpac = 255;
	m_actionOpacGap = 255;
	m_actionOpac_c = 255;
	m_actionOpa_state = 1;   //1表示升 2表示降
	m_resId = 0;
	m_actorId = "";
	m_actorType = 0;
	m_offsetPos.x = 0;
	m_offsetPos.y = 0;

	m_spriteInitCb = 0;
	m_setOpacityCb = 0;
	m_setVisibleCb = 0;
	m_setVisibleScreenCb = 0;
	m_father = nullptr;
	m_opact = 255;
	m_setWhiteCb = 0;
	m_syncActionCb = 0;
	m_boHide = false;
	m_screenVisible = true;
	m_zOrderFlag = 0;
	m_isFixAnimDir = true;
	m_sprite_init = false;
	m_roledata.isRepMode = false;

	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	memset(m_defaultActionPath, 0, sizeof(m_defaultActionPath));
	m_load_all = false;	
}

SpriteBase::~SpriteBase(void)
{
	base_url_backUp.clear();
	m_needLoadTextureList.clear();
	for(std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter = m_downloadListenerList.begin();iter != m_downloadListenerList.end();iter++){
		if(iter->second){
			_eventDispatcher->removeEventListener(iter->second);
		}
	}
	m_downloadListenerList.clear();

	//只有确定被释放才调用这个方法，而不是在cleanup里面调用
	//例如主角不释放，但它移出舞台时，还是会触发cleanup事件
	cleanDenpendFrames();
	cleanAsync();
}

void SpriteBase::cleanup(){
	Node::cleanup();
	cleanAsync();
}

void SpriteBase::cleanAsync(){
	if(m_loadTextureEntryId != 0 && !m_show_texture_path.empty()){
		bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(m_show_texture_path,m_loadTextureEntryId);
		// CCASSERT(isFind == true, "SpriteBase m_loadTextureEntryId remove Fail");
		m_loadTextureEntryId = 0;
	}
	m_needLoadTextureList.clear();
	if(m_loadPlistEntryId != 0 && !m_show_plist_path.empty()){
		bool isFind = AsyncLoadPlist::getInstance()->unbindPlistAsyncWithEntryId(m_show_plist_path,m_loadPlistEntryId);
		// CCASSERT(isFind == true, "SpriteBase m_loadPlistEntryId remove Fail");
		m_loadPlistEntryId = 0;
	}
	if(m_renderListEntryId != 0){
		ActorRenderQueueManage::getInstance()->removeRenderCallBack(m_renderListEntryId);
		m_renderListEntryId = 0;
	}
	m_async_pvr_path = "";
}


bool SpriteBase::initWithFile(const std::string&pszFileName, std::string actorId)
{
	main_node = Node::create();
	addChild(main_node,4,110);

	main_sprite = GraySprite::create();
	//Texture2D* texture = Director::getInstance()->getTextureCache()->getTextureForKey("/cc_2x2_white_image");
	//main_sprite->initWithFile("res/empty_frame.png");
	//main_sprite->initWithTexture(texture);
	m_roledata.spiritUrl = pszFileName;
	m_actorId = actorId;
	
	if(main_sprite == NULL)
	{
		return false;
	}
	main_node->addChild(main_sprite,4,110);

	return true;
}

void SpriteBase::setTypeId(SpriteType typeId,bool initDepend){
	m_type = typeId;
	if(initDepend)
		initDependTexturePathList();
}

void SpriteBase::setIsHide(bool hide){
	m_boHide = hide;
	main_sprite->stopAllActions();
	m_roledata.animKey = "";
}

void SpriteBase::updateShowState(){
	if(!m_ischeck) 
		//无资源
		m_showState = SHOW_STATE_EMPTY;
	else{
		//有资源
		m_showState = SHOW_STATE_ASSET;
		if(m_isLoadTexture){
			//资源已下载
			m_showState = SHOW_STATE_LOADED;
			if(m_isLoadPlist)
				m_showState = SHOW_STATE_ALL;
		}
	}
}

bool SpriteBase::canShowNormal(){
	return m_showState == SHOW_STATE_ALL;
}

void SpriteBase::reset(){
	cleanAsync();
	m_isLoadTexture = false;
	m_isLoadTexturing = false;
	m_isLoadPlist = false;
	m_isLoadPlisting = false;
	m_isInRenderList = false;
	updateShowState();
	m_sprite_init = false;
}

void SpriteBase::cleanDenpendFrames(){
	for(auto iter = m_needReleaseFrameList.begin();iter != m_needReleaseFrameList.end();iter++){
		(*iter)->release();
	}
	m_needReleaseFrameList.clear();
}

void SpriteBase::initDependTexturePathList(){
	cleanDenpendFrames();

	if (true)
	{
		return;
	}

	m_load_all = false;
	m_needLoadTexturePathList.clear();
	char strurl[128] = "";
	char strurl_action[128] = "";
	auto i =  m_roledata.spiritUrl.find("/");
	auto sub_str = m_roledata.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  m_roledata.spiritUrl.substr(0,i);
		else
			sub_str =  m_roledata.spiritUrl.substr(i+1);
	}

	int tmpSymbolKey1[] = {}; //"res/roleplist/r_%s"
	std::string keyA = HandleString(tmpSymbolKey1, STRNUMSIG);
	const char* key1 = keyA.c_str();

	int tmpSymbolKey2[] = {}; //"res/roleplist/r_%s"
	std::string keyB = HandleString(tmpSymbolKey2, STRNUMSIG);
	const char* key2 = keyB.c_str();

	int tmpSymbolKey3[] = {}; //"res/wuqiplist/w_%s"
	std::string keyC = HandleString(tmpSymbolKey3, STRNUMSIG);
	const char* key3 = keyC.c_str();

	int tmpSymbolKey4[] = {}; //"res/wingplist/wing_%s"
	std::string keyE = HandleString(tmpSymbolKey4, STRNUMSIG);
	const char* key4 = keyE.c_str();

	int tmpSymbolKey5[] = {}; //"res/rideplist/ride_%s_%s"
	std::string keyF = HandleString(tmpSymbolKey5, STRNUMSIG);
	const char* key5 = keyF.c_str();

	int tmpSymbolKey6[] = {}; //"attack"
	std::string keyAttack = HandleString(tmpSymbolKey6, STRNUMSIG);
	const char* chrAttack = keyAttack.c_str();

	int tmpSymbolKey7[] = {}; //"normal"
	std::string keyNormal = HandleString(tmpSymbolKey7, STRNUMSIG);
	const char* chrNormal = keyNormal.c_str();

	int tmpSymbolKey8[] = {}; //"ride"
	std::string keyRide = HandleString(tmpSymbolKey8, STRNUMSIG);
	const char* chrRide = keyRide.c_str();

	int tmpSymbolKey9[] = {}; //"run"
	std::string keyRun = HandleString(tmpSymbolKey9, STRNUMSIG);
	const char* chrRun = keyRun.c_str();

	int tmpSymbolKey10[] = {}; //"stand"
	std::string keyStand = HandleString(tmpSymbolKey10, STRNUMSIG);
	const char* chrStand = keyStand.c_str();	

	char actionName[128] = "";
	switch (m_type)
	{
	case PLAYER_MANE_TYPE: 
		//美人
		sprintf(strurl, key1, sub_str.c_str());//"res/roleplist/r_%s"

		sprintf(strurl_action,"%s_%s",strurl,chrAttack);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrNormal);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case PLAYER_FEMALE_TYPE:
		//角色
		sprintf(strurl,key2, sub_str.c_str());//"res/roleplist/r_%s"

		sprintf(strurl_action,"%s_%s",strurl,chrAttack);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrNormal);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		//memset( strurl_action, 0, sizeof(strurl_action) );
		//sprintf(strurl_action,"%s_%s",strurl,"fly");
		//m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrRide);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case WUQI_TYPE:
		sprintf(strurl, key3, sub_str.c_str());

		if(m_FatherType != SpriteType::BASE_TYPE && m_FatherType == SpriteType::PLAYER_MANE_TYPE){
			//美人武器
			sprintf(strurl_action,"%s_%s",strurl,chrAttack);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,chrNormal);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
			//角色武器
			sprintf(strurl_action,"%s_%s",strurl,chrAttack);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,chrNormal);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

			//memset( strurl_action, 0, sizeof(strurl_action) );
			//sprintf(strurl_action,"%s_%s",strurl,"fly");
			//m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,chrRide);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}
		break;
	case HEAD_TYPE:
		break;
	case WING_TYPE:
		sprintf(strurl, key4, sub_str.c_str());

		sprintf(strurl_action,"%s_%s",strurl,chrAttack);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrNormal);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		//memset( strurl_action, 0, sizeof(strurl_action) );
		//sprintf(strurl_action,"%s_%s",strurl,"fly");
		//m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrRide);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if(m_FatherType != SpriteType::BASE_TYPE && m_FatherType == SpriteType::PLAYER_MANE_TYPE){
			//美人坐骑
			sprintf(strurl_action, key5,sub_str.c_str(), chrStand); 
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
			//角色坐骑
			sprintf(strurl_action, key5, sub_str.c_str(), chrStand);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));

			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action, key5,sub_str.c_str(), chrRun);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}
		break;
	case SHOW_TYPE:
		break;
	case NORMAL_MONSTER:
	case ELIT_MONSTER:
	case BOSS_MONSTER:
	case JUQING_MONSTER:
		break;
	case NPC_TYPE:
		break;
	case ATTACK_EFFECT:
		break;
	case TATTO_TYPE:
		break;
	default:
		break;
	}
}

//针对换装
void SpriteBase::setBaseUrl(const std::string&pszFileName)
{
	//攻击状态下不重置精灵显示
	//if(getCurrActionState() == ACTION_STATE_ATTACK){
	//	base_url_backUp = pszFileName;
	//	return;
	//}
	if(m_roledata.spiritUrl.compare(pszFileName) != 0){
		cleanAsync();
		//m_isLoadTexture = false;
		//m_isLoadTexturing = false;
		//m_isLoadPlist = false;
		//m_isLoadPlisting = false;
		//m_isInRenderList = false;
		updateShowState();
		m_sprite_init = false;
		m_roledata.spiritUrl = pszFileName; 
		initDependTexturePathList();
	}
	m_roledata.spiritUrl = pszFileName; 

	if (m_type == SpriteType::RIDE_TYPE_UP || m_type == SpriteType::RIDE_TYPE_DOWN)
	{
		setDefaultActionPlistPath();
	}
}

void SpriteBase::setBaseAnchorPoint(cocos2d::Point anchorPoint){
	main_sprite->setAnchorPoint(anchorPoint);
}

void SpriteBase::setBasePosition(cocos2d::Point pos){
	main_sprite->setPosition(pos);
}


SpriteBase *SpriteBase::create(const std::string&pszFileName)
{
    SpriteBase *pRet = new SpriteBase();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

SpriteBase* SpriteBase::create(const std::string&pszFileName, std::string actorId)
{
	SpriteBase *pRet = new SpriteBase();
	if (pRet && pRet->initWithFile(pszFileName, actorId))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

SpriteBase *SpriteBase::create(const std::string&pszFileName,Size touch_size)
{
    SpriteBase *pRet = new SpriteBase();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}



void SpriteBase::initStandStatus(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,Commen_Direction dir)
{
	m_roledata.maxcut_stand = standcut;
	m_stand_times = times;
	if((int)dir != -1)
		m_roledata.dir=  dir;
	stand_inited = true;
	initRunStatus("",runcut);
	initAttackStatus("",attackcut);
	initHurtStatus("",maxcut2);
	initMagicStatus("",maxcut2);
	initDeathStatus("",deathcut);
}

void SpriteBase::initDeathStatus(const std::string&pszFileName,int maxcut)
{
	if(maxcut != -1){
		m_roledata.maxcut_death = maxcut;
		death_inited = true;
	}
}

void SpriteBase::initRunStatus(const std::string&pszFileName,int maxcut)
{
	if(maxcut != -1){
		m_roledata.maxcut_run = maxcut;
		run_inited = true;	
	}
}

void SpriteBase::initAttackStatus(const std::string&pszFileName,int maxcut)
{
	if(maxcut != -1){
		m_roledata.maxcut_attack = maxcut;
		attack_inited = true;
	}
}

void SpriteBase::initHurtStatus(const std::string&pszFileName,int maxcut)
{ 
	if(maxcut != -1){
		m_roledata.maxcut_hurt = maxcut;
		hurt_inited = true;
	}
}

void SpriteBase::initMagicStatus(const std::string&pszFileName,int maxcut)
{
	if(maxcut != -1){
		m_roledata.maxcut_magic = maxcut;
		magic_inited = true;
	}
}

void SpriteBase::initFlyStatus(int maxcut_fly01,int maxcut_fly02,int maxcut_fly03)
{
	m_roledata.maxcut_fly01 = maxcut_fly01;
	m_roledata.maxcut_fly02 = maxcut_fly02;
	m_roledata.maxcut_fly03 = maxcut_fly03;
	fly_inited = true;
}

void SpriteBase::initHurtIdleStatus(const std::string&pszFileName,int maxcut)
{
	m_roledata.maxcut_hurt_idle = maxcut;
	hurt_inited_idle = true;
}

void SpriteBase::initHurtKneelStatus(const std::string&pszFileName,int maxcut)
{
	m_roledata.maxcut_hurt_kneel = maxcut;
	hurt_kneel_inited = true;
}

void SpriteBase::initAttackRushStatus(const std::string&pszFileName,int maxcut_03,int maxcut_04){
	m_roledata.maxcut_attack_03 = maxcut_03;
	m_roledata.maxcut_attack_04 = maxcut_04;
	attack_rush_inited = true;
}

void SpriteBase::initRideStatus(int maxcut_stand,int max_run){
	m_roledata.maxcut_ride_stand = maxcut_stand;
	m_roledata.maxcut_ride_run = max_run;
	ride_inited = true;
}

void SpriteBase::initAttackModeStatus(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,
									  int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12)
{
	m_roledata.maxcut_attackmode_01 = maxcut_mode1;
	m_roledata.maxcut_attackmode_02 = maxcut_mode2;
	m_roledata.maxcut_attackmode_03 = maxcut_mode3;
	m_roledata.maxcut_attackmode_04 = maxcut_mode4;

	m_roledata.maxcut_attackmode_05 = maxcut_mode5;
	m_roledata.maxcut_attackmode_06 = maxcut_mode6;
	m_roledata.maxcut_attackmode_07 = maxcut_mode7;
	m_roledata.maxcut_attackmode_08 = maxcut_mode8;

	m_roledata.maxcut_attackmode_09 = maxcut_mode9;
	m_roledata.maxcut_attackmode_10 = maxcut_mode10;
	m_roledata.maxcut_attackmode_11 = maxcut_mode11;
	m_roledata.maxcut_attackmode_12 = maxcut_mode12;

	attack_inited = true;
}

void SpriteBase::initWeaponEffFrames(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12)
{
	m_roledata.maxcut_weaponeff_01 = maxcut1;
	m_roledata.maxcut_weaponeff_02 = maxcut2;
	m_roledata.maxcut_weaponeff_03 = maxcut3;
	m_roledata.maxcut_weaponeff_04 = maxcut4;

	m_roledata.maxcut_weaponeff_05 = maxcut5;
	m_roledata.maxcut_weaponeff_06 = maxcut6;
	m_roledata.maxcut_weaponeff_07 = maxcut7;
	m_roledata.maxcut_weaponeff_08 = maxcut8;

	m_roledata.maxcut_weaponeff_09 = maxcut9;
	m_roledata.maxcut_weaponeff_10 = maxcut10;
	m_roledata.maxcut_weaponeff_11 = maxcut11;
	m_roledata.maxcut_weaponeff_12 = maxcut12;
}


/************************************************************************/
/* 检测是否本地有资源，没有则下载                                       */
/* 检测资源是否加载过，没有则进行异步加载								*/
/************************************************************************/

bool SpriteBase::checkShow(){
	//return false;
	if(m_ischecking == true || m_isLoadTexturing == true || m_isLoadPlisting == true)
		return false;
	if(m_ischeck && m_isLoadTexture && m_isLoadPlist) return m_showState == SHOW_STATE_ALL;
	if(m_showState == SHOW_STATE_ALL) return true;
	//TODO 检查本地资源文件是否存在
	bool canShow = false;
	if(m_ischeck == false)
	{
		m_ischeck = true;
		std::map<std::string,bool> needDownFileNameList;
		char strurl[128] = "";
		for(int i=1;i<=m_plist_num;i++)
		{
		
			if(i <= 1)
			{
				//getPlistPath(strurl);
				memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			}
			else
			{
				//getPlistPath(strurl,i);
				getPlistPath2(strurl, m_actionPvrPath, i);
			}
			

			char plistPath[128];
			char pvrPath[128];
			sprintf(plistPath,"%s.plist",strurl);
			sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
				//文件不存在
				m_ischecking = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(plistPath)){
				//文件存在，但是在下载列表中 
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
				//文件不存在
				m_ischecking = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(pvrPath)){
				//文件存在，但是在下载列表中 
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
		}
		if(needDownFileNameList.size()>0){
			//TODO 缺少资源需要下载
			//TODO 创建替代资源 未做  根据类型决定是否需要创建替代资源
			//TODO 添加下载任务到下载管理器
			//TODO 自身状态修改
			if(m_type==NPC_TYPE||m_type==NORMAL_MONSTER||m_type == ELIT_MONSTER || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER|| m_type == PET_MONSTER||m_type == PLAYER_MANE_TYPE||m_type == PLAYER_FEMALE_TYPE){
				int tmpSymbolKey[] = {}; //"res/syncReplace/1.png"
				std::string keyA = HandleString(tmpSymbolKey, STRNUMSIG);
				m_syncReplace = Sprite::create(keyA.c_str());
				m_syncReplace->setPositionY(40);
				m_syncReplace->setTag(554);
				addChild(m_syncReplace);
			}
			for(std::map<std::string,bool>::iterator iter = needDownFileNameList.begin();iter != needDownFileNameList.end();iter++){
				std::string pszFileName = iter->first;
				bool addjob = iter->second;
				//CCLOG("need down key:%s",pszFileName.c_str());
				cocos2d::EventListenerCustom* customlistener = _eventDispatcher->addCustomEventListener(pszFileName.c_str(), [this](EventCustom* event){
					//TODO 移除监听
					//TODO 检测是否全部下载完毕
					//TODO 全部下载完毕，加载资源
					//CCLOG("download finish key:%s",event->getEventName().c_str());
					std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter_map = m_downloadListenerList.find(event->getEventName());
					if(iter_map != m_downloadListenerList.end()){
						_eventDispatcher->removeEventListener(iter_map->second);
						m_downloadListenerList.erase(iter_map);
					}
					//CCLOG("m_downloadListenerList size:%d",m_downloadListenerList.size());
					if(m_downloadListenerList.size() <= 0){
						m_showState = SHOW_STATE_ASSET;
						removeChildByTag(554);
						m_isLoadTexture = false;
						//按需加载的的资源，一率异步加载显示
						m_ischecking = false;
						checkShow();
					}
				});
				m_downloadListenerList.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(pszFileName,customlistener));
				if(addjob)	AsyncDownloadManager::getInstance()->addJob(pszFileName,nullptr);
				//CCLOG("need down key size:%d",m_downloadListenerList.size());
			}
			m_showState = SHOW_STATE_EMPTY;
		}else{
			m_showState = SHOW_STATE_ASSET;
		}
	}
	Texture2D* tex = nullptr;
	//检查是在有资源的情况下，是否异步加载资源
	if(m_showState == SHOW_STATE_ASSET && m_isLoadTexture == false){
		m_isLoadTexture = true;
		char strurl[128] = "";

		memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
		char pvrPath[128];
		sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
		tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		if(tex == nullptr){
			addSpriteFrameListAsync(strurl);
		}else{
			m_showState = SHOW_STATE_LOADED;
		}
	}
	if(m_showState == SHOW_STATE_LOADED && m_isLoadPlist == false){
		if(tex == nullptr){
			char strurl[128] = "";

			memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			char pvrPath[128];
			sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
			tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		}
		m_isLoadPlist = true;
		char plistPath[128] = "";
		sprintf(plistPath,"%s.plist", m_actionPvrPath);
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false){
			addSpriteFrameListCallBack(tex,m_actionPvrPath);
		}else{
			canShow = true;
			m_showState = SHOW_STATE_ALL;
		}
	}
	return canShow;
}

void SpriteBase::addSpriteFrameListAsync(char* strurl){
	if(m_loadTextureEntryId != 0)
		return;
	char pvrPath[128];
	sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
	std::string s(strurl);
	if(m_checkResType){
		if(!FileUtils::getInstance()->isFileExist(s)){
			char plistPath[128];
			sprintf(plistPath,"%s.plist",s.c_str());
			ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(plistPath);
			std::string texturePath("");
			if (dict.find("metadata") != dict.end())
			{
				ValueMap& metadataDict = dict["metadata"].asValueMap();
				// try to read  texture file name from meta data
				texturePath = metadataDict["textureFileName"].asString();

				size_t pos = texturePath.find_first_of('.');
				if (pos != std::string::npos)
				{
					m_resSuffix = texturePath.substr(pos+1);
					memset( pvrPath, 0, sizeof(pvrPath) ); 
					sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
				}
			}
		}
	}
	m_isLoadTexturing = true;
	m_async_pvr_path = m_actionPvrPath;
	setShowTexturePath(pvrPath);
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(SpriteBase::addSpriteFrameListCallBack,this,s);

	//暂时只支持一件texture文件
	m_loadTextureEntryId = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}

void SpriteBase::addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string strurl){
	m_loadTextureEntryId = 0;
	m_isLoadTexturing = false;
	if(a == nullptr){
		// CCLOG("SpriteBase_load file fail:%s",strurl.c_str());
		return;
	}
	if(m_loadPlistEntryId != 0)
		return;
	m_async_pvr_path = m_actionPvrPath;
	m_showState = SHOW_STATE_LOADED;
	char plistPath[128];
	sprintf(plistPath,"%s.plist",strurl.c_str());
	setShowPlistPath(plistPath);
	m_isLoadPlisting = true;
	m_isLoadPlist = true;
	std::function<void(bool)> addPlist = CC_CALLBACK_1(SpriteBase::addSpriteFramePlistCallBack,this);
	
	//暂时只支持一件plist文件
	m_loadPlistEntryId = AsyncLoadPlist::getInstance()->loadPlistAsync(plistPath,addPlist,a);
}

void SpriteBase::addSpriteFramePlistCallBack(bool suc){
	m_loadPlistEntryId = 0;
	m_isLoadPlisting = false;
	m_async_pvr_path = "";
	if(suc){
		m_showState = SHOW_STATE_ALL;
		playAction(-1,ACTION_NONE,dir_none,-100,-1);
	}else{
		m_isLoadTexture = false;
		m_isLoadTexturing = false;
		m_isLoadPlist = false;
		m_isLoadPlisting = false;
		m_isInRenderList = false;
		updateShowState();
		m_sprite_init = false;
	}
}

void SpriteBase::addRenderListCallback(){
	m_renderListEntryId = 0;
	m_isInRenderList = false;
	playAction(-1,ACTION_NONE,dir_none,-100,-1);
}

int SpriteBase::calculationArrival(SpriteType type, int z)
{
	bool isOnRide = getOnRide();
	int iActtodo = static_cast<int>(m_roledata.acttodo);

	if (iActtodo > -1 && iActtodo <= ActionShowTypeSize)
	{
		if (type == RIDE_TYPE_UP || type == RIDE_TYPE_DOWN)
		{
			if (m_roledata.acttodo == Commen_ActionToDo::stand)
			{
				iActtodo = ActionShowType_RideStand;
			}
			else if (m_roledata.acttodo == Commen_ActionToDo::run)
			{
				iActtodo = ActionShowType_RideRun;
			}
		}
		else
		{
			if(isOnRide == false)
			{
				iActtodo = ActionShowType[iActtodo];
			}
			else
			{
				// 身体和武器都有乘骑状态，但它们不属于动作，所以用8 ActionShowType_RideStand
				if (type == PLAYER_FEMALE_TYPE || type == WUQI_TYPE)
				{
					if (m_roledata.acttodo == Commen_ActionToDo::stand)
					{
						iActtodo = ActionShowType_OnRide;
					}
					else if (m_roledata.acttodo == Commen_ActionToDo::run)
					{
						iActtodo = ActionShowType_OnRide;
					}
				}
			}
		}
	}

	int arrival = z*OrderOfArrivalZBase + iActtodo*OrderOfArrivalRBase + m_resId;
	// 如果orderOfArrival超出int范围
	assert(arrival>0);
	return arrival;
}

void SpriteBase::updateZOrder(const Commen_Direction dir)
{
	//根据类型设置渲染层级
	int z = 0;
	if (m_type == PLAYER_FEMALE_TYPE || m_type == PLAYER_MANE_TYPE || m_type == NPC_TYPE
		|| m_type == NORMAL_MONSTER  || m_type == ELIT_MONSTER     || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER)
	{
		z = 4; // 10
	}
	else if(m_type == TATTO_TYPE)
	{
		if(dir>0 && dir<4 )
		{ 
			z = 5; //11; 
		}
		else
		{ 
			z = 7; //13;
		}
	}
	else if(m_type == WUQI_TYPE)
	{
		if(dir>4 && dir<8)
		{
			z = 7; //13;
		}
		else
		{
			z = 5; //11;
		}
	}
	else if(m_type == RIDE_TYPE_DOWN)
	{
		if(dir < 5)
		{
			z = 8; //14;
			if (m_zOrderFlag == 0)
			{
				z = 6; //12;
			}
		}
		else
		{
			z = 8; //14;
		}
	}
	else if(m_type == RIDE_TYPE_UP)
	{
		z = 2; //8;
	}
	else if(m_type == WING_TYPE)
	{
		if(dir < 5)
		{
			z = 7; //13;
		}
		else
		{
			z = 3; //9;
		}
	}

	if (z > 0)
	{
		//if (m_type == WING_TYPE||m_type == PLAYER_FEMALE_TYPE || m_type == PLAYER_MANE_TYPE)
		//{
		//	CCLOG("SpriteBase::updateZOrder Before %d,%d ,%s ,%d", z, m_type, m_actorId.c_str(),m_resId);
		//}

		if (m_resId > 0)
		{
			z = calculationArrival(m_type, z);
		}

		//if (m_type == WING_TYPE || m_type == PLAYER_FEMALE_TYPE || m_type == PLAYER_MANE_TYPE )
		//{
		//	CCLOG("SpriteBase::updateZOrder end %d,%d ,%s", z, m_type, m_actorId.c_str());
		//}
		setOrderOfArrival(z);
	}
}

void SpriteBase::playActionData(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes,bool stopAnim)
{
	if(action != ACTION_NONE)	m_roledata.acttodo = action;
	if(times != -1) m_roledata.actiontime = times;
	Commen_Direction dir_temp = m_roledata.dir;
	if(dir != dir_none) dir_temp = dir;
	dir = dir_temp;
	setSpriteDir(dir);
	int loop_temp = m_loop;
	if(loop != -100) loop_temp = loop;
	m_loop = loop_temp;


	if(m_boHide == false){
		updateZOrder(dir);
		if(stopAnim){
			main_sprite->stopAllActions();
			m_roledata.animKey = "";
		}
		if (m_isWhite)
		{
			setWhite(true);
		}
	}
}
/**
* 播放角色默认动作
*/
bool SpriteBase::checkPlayDefaultAction(void)
{
	bool isRunAction = false;
	if (strcmp(m_defaultActionPath, "") != 0){
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(m_defaultActionPath))
		{
			Commen_ActionToDo tmp_acttodo = m_roledata.acttodo;
			float tmp_actionTime = m_roledata.actiontime;
			int tmp_loop = m_loop;

			m_roledata.acttodo = Commen_ActionToDo::stand;
			m_roledata.actiontime = m_stand_times;
			m_loop = 0;

			Animate* anim = updateNowAnt(m_loop);
			if(anim)
			{
				main_sprite->stopAllActions();
				main_sprite->runAction(anim);
				isRunAction = true;
			}
			m_roledata.acttodo = tmp_acttodo;
			m_roledata.actiontime = tmp_actionTime;
			m_loop = tmp_loop;
		}
	}

	return isRunAction;
}


#if (USER_NEW_PLAY_ACTION == 1)
void SpriteBase::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	//CPLUSLog("[SpriteBase::playAction] BEGIN!!!")
	bool isSameAction = false;
	if(action == Commen_ActionToDo::ACTION_NONE && m_roledata.acttodo == Commen_ActionToDo::ACTION_NONE)
		action = Commen_ActionToDo::stand;
	if(action == m_roledata.acttodo)
		isSameAction = true;
	
	playActionData(times,action,dir,loop,ltimes,false);
	if(base_url_backUp.size() > 0 && getCurrActionState() != ACTION_STATE_ATTACK)
	{
		setBaseUrl(base_url_backUp);
		base_url_backUp.clear();
	}
	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	getPlistPath(m_actionPvrPath);

	//if(m_isInRenderList)
	//	return;
	//if(m_isAddRenderList)
	//{
	//	main_sprite->stopAllActions();
	//	m_isAddRenderList = false;     //此字段只生效一次

	//	m_isInRenderList = true;
	//	std::function<void(void)> addRenderList = CC_CALLBACK_0(SpriteBase::addRenderListCallback,this);
	//	m_renderListEntryId = ActorRenderQueueManage::getInstance()->addRenderListCallBack(addRenderList,ActorRenderType::SPRITE_BASE);
	//}
	//else
	//{
		if(m_actionStateChange == false && isSameAction && (action == Commen_ActionToDo::stand || action == Commen_ActionToDo::run))
		{
			m_openActionCheck = true;
			m_actionStateChange = false;
		}
		else
		{
			m_openActionCheck = false;
			m_actionStateChange = true;
		}

		Animate* anim = updateNowAnt(m_loop);
		if(anim && m_actionStateChange)
		{
			main_sprite->stopAllActions();
			m_actionStateChange = false;
			main_sprite->runAction(anim);
			//if (action == Commen_ActionToDo::run &&  this->m_type == PLAYER_FEMALE_TYPE)
			std::string val = m_actionPvrPath;
		}

		if (anim == nullptr)
		{
			CPLUSLog("[SpriteBase::playAction] get anim Fail, file = %s", m_actionPvrPath);
		}
	//}
	//CPLUSLog("[SpriteBase::playAction] END!!!")
}
#else
void SpriteBase::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	/************************************************************************/
	/* 
	--[[
	TODO 针对翅膀 动作特殊处理
	1，男女角色调用同一套光翼资源，即全都调用原男角色资源；

	2，攻击时，光翼调用待机动作；
	3，轻功时，光翼调用移动动作(当前也调用待机)；

	4，死亡时，不需要调用光翼动作；

	5，骑乘时，光翼调用常规待机动作资源，需要根据角色位置做调整修正。
	6，移动，调用移动动作
	]]
	*/
	bool isPlayDefaultAction = false;
	bool isSameAction = false;
	if(action == Commen_ActionToDo::ACTION_NONE && m_roledata.acttodo == Commen_ActionToDo::ACTION_NONE)
		action = Commen_ActionToDo::stand;
	if(action == m_roledata.acttodo)
		isSameAction = true;

	playActionData(times,action,dir,loop,ltimes,false);
	if(m_boHide){
		return;
	}

	if(base_url_backUp.size() > 0 && getCurrActionState() != ACTION_STATE_ATTACK)
	{
		setBaseUrl(base_url_backUp);
		base_url_backUp.clear();

		getPlistPath(m_actionPvrPath);
	}
	else
	{
		if(m_load_all == false){
			//所依赖的资源没有合部加载完，则进行检查
			getPlistPath(m_actionPvrPath);
			//检测正在加载且异步加载配置的 名称是否相同，相同则不操作
			if(m_async_pvr_path.compare(m_actionPvrPath) == 0)
				return;
			//检测是否在依赖所需的加载列表中，如果不在，表示已加载，不用再次进行检查
			if(m_needLoadTexturePathList.find(m_actionPvrPath) != m_needLoadTexturePathList.end()){
				char texPath[128] = "";
				sprintf(texPath,"%s.%s", m_actionPvrPath, m_resSuffix.c_str());
				Texture2D* tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(texPath);
				if (tex == nullptr)
				{
					// 坐骑跑和站立动作不在同一张plist 切换动作会有加载过程，在动作加载完之前用默认动作代替显示
					if ((m_type == SpriteType::RIDE_TYPE_UP || m_type == SpriteType::RIDE_TYPE_DOWN) && (action == Commen_ActionToDo::run || action == Commen_ActionToDo::walk))
					{
						isPlayDefaultAction = checkPlayDefaultAction();
					}

					cleanAsync();
					m_isLoadTexture = false;
					m_isLoadTexturing = false;
					m_isLoadPlist = false;
					m_isLoadPlisting = false;
					m_isInRenderList = false;
					updateShowState();
					m_async_pvr_path = m_actionPvrPath;

					//没有纹理不用return继续走checkShow流程
				}
				else
				{
					//因为会出现纹理加载完 plist没有解析的情况
					char plistPath[128] = "";
					sprintf(plistPath,"%s.plist", m_actionPvrPath);
					if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false)
					{
						// 坐骑跑和站立动作不在同一张plist 切换动作会有加载过程，在动作加载完之前用默认动作代替显示
						if ((m_type == SpriteType::RIDE_TYPE_UP || m_type == SpriteType::RIDE_TYPE_DOWN) && (action == Commen_ActionToDo::run || action == Commen_ActionToDo::walk))
						{
							isPlayDefaultAction = checkPlayDefaultAction();
						}

						cleanAsync();
						m_isLoadTexture = true;
						m_isLoadTexturing = false;
						m_isLoadPlist = false;
						m_isLoadPlisting = false;
						m_isInRenderList = false;
						updateShowState();

						//addSpriteFrameListCallBack(tex,m_actionPvrPath);
						if(!isPlayDefaultAction){
							main_sprite->stopAllActions();
							m_roledata.animKey = "";
						}
						addSpriteFrameListCallBack(tex,m_actionPvrPath);
						//没有plist则，异步加载plist即可，直接return
						return;
					}
				}
			}
		}
	}

	if(checkShow()){
		if(m_isInRenderList)
			return;
		if(m_isAddRenderList){
			main_sprite->stopAllActions();
			m_isAddRenderList = false;     //此字段只生效一次

			m_isInRenderList = true;
			std::function<void(void)> addRenderList = CC_CALLBACK_0(SpriteBase::addRenderListCallback,this);
			m_renderListEntryId = ActorRenderQueueManage::getInstance()->addRenderListCallBack(addRenderList,ActorRenderType::SPRITE_BASE);
		}else{
			if(m_actionStateChange == false && isSameAction && (action == Commen_ActionToDo::stand || action == Commen_ActionToDo::run)){
				m_openActionCheck = true;
				m_actionStateChange = false;
			}else{
				m_openActionCheck = false;
				m_actionStateChange = true;
			}
			Animate* anim = updateNowAnt(m_loop);
			if(anim && m_actionStateChange){
				main_sprite->stopAllActions();
				m_actionStateChange = false;
				main_sprite->runAction(anim);
				//if (action == Commen_ActionToDo::run &&  this->m_type == PLAYER_FEMALE_TYPE)
					//CPLUSLog("begin show Run!.......................")
			}
		}
	}else{
		if (isPlayDefaultAction == false)
			main_sprite->stopAllActions();
	}
}
#endif

void SpriteBase::standed()
{
	if(stand_inited&&changeState(ACTION_STATE_IDLE))
	{
		//stopAllActions();
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		playAction(m_stand_times,stand,m_roledata.dir,0);
	}
}

float SpriteBase::getStandTime(){
	return m_stand_times;
}

void SpriteBase::flyToTheDir(float times,int fly_mode,int handler,Vec2 newPos,Commen_Direction dir,bool stand,bool auto_double_jump_check,bool checkSecondAction, int state){
}
void SpriteBase::hurtIdleToPos(float times,Point newpoint,bool stand){
}
void SpriteBase::hurtKneelToPos(float times,Point newpoint,bool stand){
}

void SpriteBase::moveToPos(float times,Point newpoint,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_RUN)||setDirByNowPoint(newpoint))
		{
			setDirByNowPoint(newpoint);
			playAction(0.7f,run,m_roledata.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newpoint));
	}
}

void SpriteBase::walkToPos(float times,Point newpoint,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_WALK)||setDirByNowPoint(newpoint))
		{
			setDirByNowPoint(newpoint);
			playAction(0.7f,walk,m_roledata.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newpoint));
	}
}

bool SpriteBase::moveInTheDir(float times,Point newpoint,Commen_Direction dir,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(dir == dir_none && newpoint != Vec2::ZERO){
			dir = getDirByNewPoint(newpoint);
		}
		if(changeState(ACTION_STATE_RUN)||setSpriteDir(dir))
		{
			playAction(0.7f,run,dir,0);
		}
		if(newpoint != Point(0,0)){
			stopActionByTag(ACTION_MOVE_TAG);
			if(stand){
				FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
				auto action = Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}else{
				auto action = MoveTo::create(times,newpoint);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}
		}
		return true;
	}
	return false;
}


bool SpriteBase::walkInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_WALK)||setSpriteDir(dir))
		{
			playAction(0.7f,walk,dir,0);
		}
		if(newpoint != Point(0,0)){
			auto action =  MoveTo::create(times,newpoint);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}
		return true;
	}
	return false;
}

bool SpriteBase::collideInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	return false;
}

bool SpriteBase::createToTheDir(float times,Commen_Direction dir)
{

	if(changeState(ACTION_STATE_CREATE)||setSpriteDir(dir))
	{
		playAction(0.45f,create_,dir,0);
		return true; 
	}	
	return false;
}

bool SpriteBase::attackToPos(float times,Point newpoint,bool hasEffect)
{
	if(changeState(ACTION_STATE_ATTACK))
	{
		
		if(newpoint != Point())
			setDirByNowPoint(newpoint);
		playAction(times,attack,m_roledata.dir,1);

		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;  
	}
	return false;
}
//突进技能的前半段
//bool SpriteBase::attack03ToPos(float times,cocos2d::Point newpoint,bool stand)
//{
//	if(changeState(ACTION_STATE_ATTACK))
//	{
//
//		if(newpoint != Point())
//			setDirByNowPoint(newpoint);
//		playAction(times,attack_03,m_roledata.dir,1);
//
//		//FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->attack04ToPos(time04,Point());});
//		if(stand){
//			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
//			runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
//		}
//		return true;  
//	}
//	return false;
//}
////突进技能的后半段
//bool SpriteBase::attack04ToPos(float times,cocos2d::Point newpoint,bool stand)
//{
//	if(changeState(ACTION_STATE_ATTACK))
//	{
//
//		if(newpoint != Point())
//			setDirByNowPoint(newpoint);
//		playAction(times,attack_04,m_roledata.dir,1);
//
//		if(stand){
//			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
//			runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
//		}
//		return true;  
//	}
//	return false;
//}


bool SpriteBase::attackOneTime(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{	
		if(newpoint != Point(0,0))
			setDirByNowPoint(newpoint);
		playAction(times,attack,m_roledata.dir,1);
		return true;
	}
	return false;
}

bool SpriteBase::magicUpToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		
		if(newpoint != Point())
			setDirByNowPoint(newpoint);
		playAction(times,magicup,m_roledata.dir,1);

		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;
	}
	return false;
}

void SpriteBase::gotoDeath(Commen_Direction dir)
{
	if(changeState(ACTION_STATE_DEAD))
	{
		setSpriteDir(dir);
		float time = 1.5f;
		if (getTypeId() < 20)
			time = 0.3f;
		playAction(time,death,m_roledata.dir,1);
		//FiniteTimeAction* actbackfun = CallFunc::create([&](){ changeState(ACTION_STATE_REMOVE);});
		//runAction(Sequence::create(DelayTime::create(1.0),actbackfun,NULL));
	}
}

void SpriteBase::hasHurted(float delay,float times)
{
	//if(getCurrActionState()!=ACTION_STATE_RUN&&changeState(ACTION_STATE_HURT))
	//{
	//	//changeState(ACTION_STATE_HURT);
	//	FiniteTimeAction* actfun = CallFunc::create([&](){
	//		playAction(times,hurt,m_roledata.dir,1);
	//	});
	//	FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
	//	runAction(Sequence::create(DelayTime::create(delay),actfun,DelayTime::create(times),actbackfun,NULL));
	//}
	//runAction(Sequence::create(DelayTime::create(delay),Blink::create(times,1),NULL));
	if(changeState(ACTION_STATE_HURT))
	{
		FiniteTimeAction* start = CallFunc::create([&](){ setWhite(true);});
		FiniteTimeAction* ended = CallFunc::create([&](){ setWhite(false);});
		runAction(Sequence::create(DelayTime::create(delay),start,DelayTime::create(times),ended,NULL));
	}
}

void SpriteBase::doOpacityAction(int opac,float animTime){
	m_actionOpac = opac;
	int actionTimes = animTime/0.05f;
	m_actionOpac_c = getOpacity();
	if(m_actionOpac == m_actionOpac_c)
		return;
	if(m_actionOpac > m_actionOpac_c)
		m_actionOpa_state = 1;
	else
		m_actionOpa_state = 2;
	m_actionOpacGap = (m_actionOpac - getOpacity())/actionTimes;
	unschedule(schedule_selector(SpriteBase::updateOpacityAction));
	schedule(schedule_selector(SpriteBase::updateOpacityAction), 0.05f); 
	m_isOpacAction = true;
}

void SpriteBase::updateOpacityAction(float times){
	m_actionOpac_c += m_actionOpacGap;
	
	bool unAction = false;
	if(m_actionOpac_c <= 0)
	{
		unAction = true;
		m_actionOpac_c = 0;
	}
	else if(m_actionOpac_c >= 255)
	{
		unAction = true;
		m_actionOpac_c = 255;
	}else{
		if(m_actionOpa_state == 1){
			if(m_actionOpac_c >= m_actionOpac){
				unAction = true;
				m_actionOpac_c = m_actionOpac;
			}
		}else{
			if(m_actionOpac_c <= m_actionOpac){
				unAction = true;
				m_actionOpac_c = m_actionOpac;
			}
		}
	}
	setOpacity(m_actionOpac_c);
	if(unAction){
		m_isOpacAction = false;
		unschedule(schedule_selector(SpriteBase::updateOpacityAction));
	}
}

int SpriteBase::setOpacity(int opact,bool update)
{
	if(update){
		for (auto& child : getChildren())
		{
			if(child->getTag()>=40 && child->getTag() < 70)
			{
				SpriteBase* children = dynamic_cast<SpriteBase*>(child);
				children->setOpacity(opact);
			}
			else if(child->getTag() == 110){
				child->getChildByTag(110)->setOpacity(opact);
			}
			else
			{
				child->setOpacity(opact);
			}
		}
	}

	//if (m_setOpacityCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorId);
	//		pStack->pushInt(static_cast<int>(opact));
	//		pStack->executeFunctionByHandler(m_setOpacityCb, 2);
	//		pStack->clean();
	//	}
	//}
	if(m_setOpacityCb > 0 && m_actorId != ""){
		ActorActionManageC::getInstance()->setOpacity(m_actorId,opact);
	}

	m_opact = opact;

	return 1;
}

int SpriteBase::getOpacity()
{
	return m_opact;
}

bool SpriteBase::isTouchInside(Touch* touch)
{
	if(m_touchEnabled == true){
		Point local = main_sprite->convertTouchToNodeSpace(touch);
		//Rect t_rect = main_sprite->getTextureRect();
		Rect t_rect = Rect(0, 0, 120, 160);
		Size c_size =  main_sprite->getContentSize();
		//Rect r = Rect(c_size.width/2-t_rect.size.width/2,c_size.height/2-t_rect.size.height/2,t_rect.size.width,t_rect.size.height);
		Rect r = Rect(c_size.width/2-t_rect.size.width/2,c_size.height/2 - 40,t_rect.size.width,t_rect.size.height);
		//Rect r = Rect(c_size.width/2-t_rect.size.width/2, 0, t_rect.size.width, t_rect.size.height);
		return r.containsPoint(local); 
	}
	return false;
}

 void SpriteBase::setTouchEnable(bool enabled){
	 m_touchEnabled = enabled;
 }

Commen_Direction SpriteBase::getDirByNewPoint(cocos2d::Point newpoint)
{
	Commen_Direction dir = dir_right_down; //默认为右下
	Point my_pos = getPosition();
	float dista = newpoint.getDistance(my_pos);
	Point direct = (newpoint - my_pos);
	if(dista<5 || dista>3000) return dir_right_down;
	if(((direct.x >= -0.000001) &&(direct.x <= 0.000001) && (direct.y >= -0.000001)&& (direct.y <= 0.000001)) )
	return dir_right_down;
	//if((direct.x >= -0.000001) &&(direct.x <= 0.000001) )
	//{
	// if(direct.y > 0)
	//	 dir = dir_up;
	// else if(direct.y < 1)
	//	 dir = dir_down;
	//}
	//else
	{
		double angel = atan2(std::abs(direct.y),std::abs(direct.x));
		//CCLOG("angel----------------:%4f",angel * 180 / PI);
		//if(tanAngel < tan(PI/8))
		if(angel < PI / 8)
		{
			if(direct.x < 0)
				if (direct.y >= 0.000001)
					dir = dir_left;
				else
					dir = dir_left_down;
			else
				if (direct.y >= 0.00001)
					dir = dir_right;
				else
					dir = dir_right_down;
		}
		else if(angel > PI * 3 / 8)
		{
			if(direct.y > 0)
				dir = dir_up;
			else
				dir = dir_down;
		}
		else
		{
			if(direct.x < 0 && direct.y < 0)
				dir = dir_left_down;
			else if(direct.x < 0 && direct.y > 0)
				dir = dir_left_up;
			else if(direct.x > 0 && direct.y > 0)
				dir = dir_right_up;
			else
				dir = dir_right_down;
		}
	}
	return dir;
}

/*************
* 根据点击坐标获得人物的朝向
*************/
bool SpriteBase::setDirByNowPoint(Point newpoint)
{
	Commen_Direction dir = getDirByNewPoint(newpoint);
	
	return setSpriteDir(dir);
}

bool SpriteBase::setSpriteDir(Commen_Direction dir)
{
	if(m_roledata.dir == dir)
		return false;
	else
	{
		m_roledata.dir = dir;
	}
	return true;
}

void SpriteBase::setColor(const Color3B& color)
{
	for (auto& child : getChildren())
    {
		
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			SpriteBase* children = dynamic_cast<SpriteBase*>(child);
			if(children)
				children->setColor(color);
		}
		else if(child->getTag() == 110){
			child->getChildByTag(110)->setColor(color);
		}
	}
}


void SpriteBase::setWhite(bool isgray)
{
	m_isWhite = isgray;
	for (auto& child : getChildren())
	{
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			SpriteBase* children = dynamic_cast<SpriteBase*>(child);
			if(children)
				children->setWhite(isgray);
		}
		else if(child->getTag() == 110){
			GraySprite* children = dynamic_cast<GraySprite*>(child->getChildByTag(110));
			if(children)
				children->setColorWrite(isgray);
		}
	}

	//if (m_setWhiteCb && m_actorId>0)
	//{
	//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//	if (pStack != nullptr)
	//	{
	//		pStack->pushInt(m_actorId);
	//		pStack->pushBoolean(isgray);
	//		pStack->executeFunctionByHandler(m_setWhiteCb, 2);
	//		pStack->clean();
	//	}
	//}
	if(m_setWhiteCb > 0 && m_actorId != ""){
		ActorActionManageC::getInstance()->setWhiteCb(m_actorId,isgray);
	}
}
void SpriteBase::setGray(bool isgray)
{
	for (auto& child : getChildren())
    {
		
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			SpriteBase* children = dynamic_cast<SpriteBase*>(child);
			if(children)
				children->setGray(isgray);
		}
		else if(child->getTag() == 110){
			GraySprite* children = dynamic_cast<GraySprite*>(child->getChildByTag(110));
			if(children)
				children->setColorGray(isgray);
		}
	}
	if(isgray)
	{
		stopAllActions();
		main_sprite->stopAllActions();
	}
	else 
		standed();
}

Animate* SpriteBase::updateNowAnt(int RepeatNum)
{
	Animation* donghua = getNowActByDir();
	if(donghua == nullptr) return nullptr;
	if (m_roledata.isRepMode && m_repTypeId != m_type)
	{
		int currMaxCut = getDefActionNum(m_repTypeId, Commen_ActionToDo::stand);
		int tmpCut = getDefActionNum(m_repTypeId, m_roledata.acttodo);
		if (tmpCut != -1)
		{
			currMaxCut = tmpCut;
		}

		if(m_openActionCheck && currMaxCut != m_roledata.maxcut)
			m_actionStateChange = true;
		m_roledata.maxcut = currMaxCut;
		donghua->setDelayPerUnit(m_roledata.actiontime / m_roledata.maxcut);
	}
	else if(m_roledata.actiontime > 0 )
	{
		int currMaxCut = m_roledata.maxcut_stand;
		int cut = m_roledata.maxcut_attack;
		switch(m_roledata.acttodo)
		{
		case attack:
			switch (m_attack_mode)
			{
			case 1:
				cut = m_roledata.maxcut_attackmode_01;
				break;
			case 2:
				cut = m_roledata.maxcut_attackmode_02;
				break;
			case 3:
				cut = m_roledata.maxcut_attackmode_03;
				break;
			case 4:
				cut = m_roledata.maxcut_attackmode_04;
				break;
			case 5:
				cut = m_roledata.maxcut_attackmode_05;
				break;
			case 6:
				cut = m_roledata.maxcut_attackmode_06;
				break;
			case 7:
				cut = m_roledata.maxcut_attackmode_07;
				break;
			case 8:
				cut = m_roledata.maxcut_attackmode_08;
				break;
			case 9:
				cut = m_roledata.maxcut_attackmode_09;
				break;
			case 10:
				cut = m_roledata.maxcut_attackmode_10;
				break;
			case 11:
				cut = m_roledata.maxcut_attackmode_11;
				break;
			case 12:
				cut = m_roledata.maxcut_attackmode_12;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case run:
		case walk:
			if(getOnRide() == false)
				currMaxCut = m_roledata.maxcut_run;
			else
				currMaxCut = m_roledata.maxcut_ride_run;
			break;
		case stand:
		case standby:
			if(getOnRide() == false)
				currMaxCut = m_roledata.maxcut_stand;
			else
				currMaxCut = m_roledata.maxcut_ride_stand;
			break;
		case hurt:
			currMaxCut = m_roledata.maxcut_hurt;
			break;
		case magicup:
			currMaxCut = m_roledata.maxcut_magic;
			break;
		case death:
			currMaxCut = m_roledata.maxcut_death;
			break;
		case fly:
			switch (m_fly_mode)
			{
			case 1:
				cut = m_roledata.maxcut_fly01;
				break;
			case 2:
				cut = m_roledata.maxcut_fly02;
				break;
			case 3:
				cut = m_roledata.maxcut_fly03;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case hurt_idle:
			currMaxCut = m_roledata.maxcut_hurt_idle;
			break;
		case hurt_kneel:
			currMaxCut = m_roledata.maxcut_hurt_kneel;
			break;
		case attack_03:
			currMaxCut = m_roledata.maxcut_attack_03;
			break;
		case attack_04:
			currMaxCut = m_roledata.maxcut_attack_04;
			break;
		default:
			currMaxCut = m_roledata.maxcut_stand;
			break;
		}

		if(m_openActionCheck && currMaxCut != m_roledata.maxcut)
			m_actionStateChange = true;
		m_roledata.maxcut = currMaxCut;
		donghua->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut);
	}
	else  
	{
		donghua->setDelayPerUnit(2.0f/15.0f);//执行默认时间
	}

	if(RepeatNum>0)
	{
		donghua->setLoops(RepeatNum);
		donghua->setRestoreOriginalFrame(false);
	}
	else
	{
		donghua->setLoops(-1);
		donghua->setRestoreOriginalFrame(true);
	}

	Animate* playdonghua = Animate::create(donghua);

	return playdonghua;
}

void SpriteBase::stopInTheTime(ActionState toState)
{
	if(changeState(toState))
	{
		stopAllActions();
		getMainSprite()->stopAllActions();
	}
}

void SpriteBase::stopMainSpriteAction()
{
	stopAllActions();
	getMainSprite()->stopAllActions();
}

void SpriteBase::getActionName(char* d)
{
	char actionName[128];
	int acttodo = static_cast<int>(m_roledata.acttodo);
	if (acttodo > -1 && acttodo <= ActionResNameSize)
	{
		switch (m_roledata.acttodo)
		{
		case run:
		case walk:
		case stand:
		case standby:
			if(getOnRide() == false)
			{
				//actionName = ActionResName[acttodo];
				sprintf(actionName,"%s", ActionResName[acttodo]);
			}
			else
			{
				//actionName = "ride";
				sprintf(actionName,"%s", "ride");
			}
			break;
		default:
			sprintf(actionName,"%s", ActionResName[acttodo]);
			break;
		}
		//if(getOnRide() == false || m_roledata.acttodo == Commen_ActionToDo::fly)
		//{
		//	actionName = ActionResName[acttodo];
		//}
		//else
		//{
		//	actionName = "ride";
		//}
	}
	memcpy(d, actionName, strlen(actionName));
}

//并没有对num处理，意味着没有对可能出现的多纹理情况处理
void SpriteBase::getPlistPath(char *strpath)
{
	auto tmpStrUrl = m_roledata.spiritUrl;
	auto typeId = m_type;
	if (m_roledata.isRepMode)
	{
		tmpStrUrl = m_roledata.repSpritUrl;
		typeId = m_repTypeId;
	}

	auto i =  tmpStrUrl.find("/");
	auto sub_str = tmpStrUrl;
	if(std::string::npos != i)
	{
		if( typeId == RIDE_TYPE_UP || typeId == RIDE_TYPE_DOWN)
			sub_str =  sub_str.substr(0,i);
		else
			sub_str =  sub_str.substr(i+1);
	}

	int tmpSymbolKey1[] = {}; //"res/roleplist/r_%s_%s"
	std::string str1 = HandleString(tmpSymbolKey1, STRNUMSIG);
	const char* key1 = str1.c_str();

	int tmpSymbolKey2[] = {}; //"res/wuqiplist/w_%s_%s"
	std::string str2 = HandleString(tmpSymbolKey2, STRNUMSIG);
	const char* key2 = str2.c_str();

	int tmpSymbolKey3[] = {}; //"res/headplist/head"
	std::string str3 = HandleString(tmpSymbolKey3, STRNUMSIG);
	const char* key3 = str3.c_str();

	int tmpSymbolKey4[] = {}; //"res/wingplist/wing_%s_%s"
	std::string str4 = HandleString(tmpSymbolKey4, STRNUMSIG);
	const char* key4 = str4.c_str();

	int tmpSymbolKey5[] = {}; //"res/rideplist/ride_%s_%s"
	std::string str5 = HandleString(tmpSymbolKey5, STRNUMSIG);
	const char* key5 = str5.c_str();

	int tmpSymbolKey6[] = {}; //"res/showplist/s_%s"
	std::string str6 = HandleString(tmpSymbolKey6, STRNUMSIG);
	const char* key6 = str6.c_str();

	int tmpSymbolKey7[] = {}; //"res/monster/m_%s"
	std::string str7 = HandleString(tmpSymbolKey7, STRNUMSIG);
	const char* key7 = str7.c_str();

	int tmpSymbolKey8[] = {}; //"res/npcplist/n_%s"
	std::string str8 = HandleString(tmpSymbolKey8, STRNUMSIG);
	const char* key8 = str8.c_str();

	int tmpSymbolKey9[] = {}; //"res/skilleffcets/%s"
	std::string str9 = HandleString(tmpSymbolKey9, STRNUMSIG);
	const char* key9 = str9.c_str();

	int tmpSymbolKey10[] = {}; //"res/longwenplist/l_%s"
	std::string str10 = HandleString(tmpSymbolKey10, STRNUMSIG);
	const char* key10 = str10.c_str();

	int tmpSymbolKey11[] = {}; //"res/fabaoplist/m_%s"
	std::string str11 = HandleString(tmpSymbolKey11, STRNUMSIG);
	const char* key11 = str11.c_str();

	int tmpSymbolKey12[] = {}; //"res/fabaoplist/sw_%s"
	std::string str12 = HandleString(tmpSymbolKey12, STRNUMSIG);
	const char* key12 = str12.c_str();

	int tmpSymbolKey13[] = {}; //"res/baseplist/b_%s"
	std::string str13 = HandleString(tmpSymbolKey13, STRNUMSIG);
	const char* key13 = str13.c_str();

	char actionName[128] = "";
	switch (typeId)
	{
	case PLAYER_MANE_TYPE: 
	case PLAYER_FEMALE_TYPE:
		getActionName(actionName);
		sprintf(strpath,key1, sub_str.c_str(), actionName);
		break;
	case WUQI_TYPE:
		getActionName(actionName);
		sprintf(strpath,key2, sub_str.c_str(), actionName);
		break;
	case HEAD_TYPE:
		sprintf(strpath, key3);
		break;
	case WING_TYPE:
		getActionName(actionName);
		sprintf(strpath, key4, sub_str.c_str(), actionName);
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if (m_roledata.acttodo == Commen_ActionToDo::stand)
		{
			sprintf(strpath,key5,sub_str.c_str(), "stand"); 
		}
		else if (m_roledata.acttodo == Commen_ActionToDo::run)
		{
			sprintf(strpath,key5,sub_str.c_str(), "run");
		}
		break;
	case SHOW_TYPE:
		sprintf(strpath,key6,sub_str.c_str());
		break;
	case NORMAL_MONSTER:
	case ELIT_MONSTER:
	case BOSS_MONSTER:
	case JUQING_MONSTER:
		sprintf(strpath,key7,sub_str.c_str());
		break;
	case NPC_TYPE:
		sprintf(strpath, key8,sub_str.c_str());
		break;
	case ATTACK_EFFECT:
		sprintf(strpath,key9,sub_str.c_str());
		break;
	case TATTO_TYPE:
		sprintf(strpath, key10,sub_str.c_str()); 
		break;
	case FAIRY_TYPE:
		sprintf(strpath,key11,sub_str.c_str());
		break;
	case MAGIC_WEAPON_TYPE:
		sprintf(strpath,key12,sub_str.c_str());
		break;
	default:
		sprintf(strpath, key13,sub_str.c_str());
		break;
	}
	//if(num > 1)
	//{
	//	sprintf(strpath, "%s%c", strpath, temp_str.at(num - 2) );
	//}
}
void SpriteBase::getPlistPath2(char *d, char *s, int num, bool old)
{
	if (strcmp(s, "") == 0)
	{
		getPlistPath(m_actionPvrPath);
		s = m_actionPvrPath;
	}

	if (old)
		sprintf(d, "%s\0", s);
	else
		sprintf(d, "%s@%d\0", s, num - 1);
}

//针对坐骑
void SpriteBase::setDefaultActionPlistPath(void)
{
	auto i =  m_roledata.spiritUrl.find("/");
	auto sub_str = m_roledata.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  m_roledata.spiritUrl.substr(0,i);
		else
			sub_str =  m_roledata.spiritUrl.substr(i+1);
	}

	int tmpSymbolKey[] = {}; //"res/rideplist/ride_%s_stand.plist"
	std::string keyA = HandleString(tmpSymbolKey, STRNUMSIG);

	switch (m_type)
	{
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		sprintf(m_defaultActionPath, keyA.c_str(), sub_str.c_str());
		break;
	default:
		break;
	}
}


/************************************************************************/
/*           
	减面 面数修正
	怪物，只用1，3双面，0、2、4三面不用，0、2用1，4用3
*/
/************************************************************************/
int SpriteBase::fixAnimDir(int dir_id)
{
	//if(m_type >= NORMAL_MONSTER && m_type <= JUQING_MONSTER){
		
		if (dir_id == 0)
			dir_id = 1;
		else if (dir_id == 2)
			dir_id = 1;
		else if(dir_id == 4)
			dir_id = 3;
			
	//}
	return dir_id;
}


void SpriteBase::loadPlist()
{
	//CPLUSLog("[SpriteBase::loadPlist] called %s", m_roledata.spiritUrl.c_str());
	if (m_roledata.spiritUrl.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		FileUtils* utils = FileUtils::getInstance();

		static const int s_max_plist_num = 20;
		bool plistExist;
		bool hasFindNewPlistFile = false;
		char newStrUrl[256] = { 0 };

		for (int i = 1; i <= s_max_plist_num; i++)
		{
			getPlistPath2(newStrUrl, m_actionPvrPath, i);
			sprintf(newStrUrl, "%s.plist", newStrUrl);

			plistExist = utils->isFileExist(newStrUrl);

			if (!plistExist)
			{
				break;
			}

			hasFindNewPlistFile = true;
			cache->addSpriteFramesWithFileAsync(newStrUrl);
			//std::string tmpVal(m_actionPvrPath);
			//if (tmpVal.find("m_1901") != -1)
			//	CPLUSLog("[SpriteBase::loadPlist] ___ Plist@ preLoad: %s", newStrUrl);
		}

		if (!hasFindNewPlistFile)
		{
			getPlistPath2(newStrUrl, m_actionPvrPath, 0, true);
			sprintf(newStrUrl, "%s.plist", newStrUrl);
			plistExist = utils->isFileExist(newStrUrl);
			if (plistExist)
			{
				//std::string tmpVal(m_actionPvrPath);
				//if (tmpVal.find("m_1901") != -1)
				//	CPLUSLog("[SpriteBase::loadPlist] ___ Plist preLoad: %s", newStrUrl);

				cache->addSpriteFramesWithFileAsync(newStrUrl);
			}
			else
			{
				// CPLUSLog("[SpriteBase::loadPlist] ... Plist Not Find: %s", newStrUrl);
			}
		}
	}
	//CPLUSLog("[SpriteBase::loadPlist] called  end.......");
}

#if (USER_NEW_PLAY_ACTION == 1)
Animation* SpriteBase::setNowAct(const char *sprite_url, int count, int dir_id)
{	
	Animation* act = nullptr;
	if (m_isFixAnimDir)
	{
		dir_id = fixAnimDir(dir_id);
	}
	std::string tmpUrl = m_roledata.spiritUrl;
	if (m_roledata.isRepMode)
	{
		tmpUrl = m_roledata.repSpritUrl;
	}
	char animKey[128] = {0};
	int tmpSymbolKey1[] = {}; //"%s%s%d"
	std::string key1 = HandleString(tmpSymbolKey1, STRNUMSIG);	
	sprintf(animKey, key1.c_str(), tmpUrl.c_str(), sprite_url, dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_openActionCheck && m_roledata.animKey.compare(animKey) != 0)
	{
		m_actionStateChange = true;
	}
	m_roledata.animKey = animKey;
	if(cacheAnim)
	{
		//if (m_type == PLAYER_FEMALE_TYPE)
		//	CCLOG("GET ANIM KEY:%s", animKey);
		act = cacheAnim;
		if(m_roledata.acttodo == death)
		{
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			main_sprite->setSpriteFrame(backFrame);
		}
	}

	if(act == nullptr)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		act = Animation::create();
		char strurl[128] = "";
		bool bLoadPlist = false;
		bool bOutError = false;
		bool has_load_res = false;

		for(int i = 0; i < count ; i++)
		{
			std::string ss = tmpUrl;	
			memset(strurl,0,128);
			int tmpSymbolKey[] = {}; //"%s%d%04d.png"
			std::string keyA = HandleString(tmpSymbolKey, STRNUMSIG);
			sprintf(strurl, keyA.c_str(), sprite_url, dir_id, i);
			ss.append(strurl);

			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if ((!bLoadPlist) && frame == nullptr)
			{
				bLoadPlist = true;
				loadPlist();
			}

			// 目前的逻辑存在有一些怪物的攻击动作没有按规定帧数的补齐
			frame = cache->getSpriteFrameByName(ss);
			if (frame)
			{
				//if (frame->getTextureReal() == nullptr)
				//	has_load_res = false;
				
				has_load_res = true;
				act->addSpriteFrame(frame);

				if (m_type > BASE_TYPE)
				{
					if ( (m_roledata.acttodo ==  death) && i == (count - 1))
					{
						main_sprite->setSpriteFrame(frame);
					}
					else if ( (m_roledata.acttodo == attack ) && i==0)
					{
						if ((m_type < NORMAL_MONSTER)||(m_type > PET_MONSTER))
						{
							main_sprite->setSpriteFrame(frame);
						}
					}
				}

				//if (ss.find("m_1901") != -1)
				//	CPLUSLog("%s find spriteFrame", animKey, ss)
			}
			else
			{
				if (!bOutError)
				{
					bOutError = true;
					if (i == 0)
					{
						int a = 1;
						// CPLUSLog("[SpriteBase::setNowAct] error: %s", ss.c_str());
					}
				}
			}
		}

		if (has_load_res)
		{
			AnimationCache::getInstance()->addAnimation(act, animKey);
		}
	}

	if(m_sprite_init == false && m_spriteInitCb > 0)
	{
		Vector<AnimationFrame*> frams = act->getFrames();
		if (frams.size() > 0)
		{
			m_sprite_init = true;
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			if(m_spriteInitCb > 0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				pStack->pushString(m_actorId.c_str());
				pStack->pushFloat(firstFrame->getRect().size.height);
				pStack->executeFunctionByHandler(m_spriteInitCb, 2);
				pStack->clean();
			}
		}
	}

	return act;
}
#else
/*********************
* 八方向人物动作合成器
*********************/
Animation* SpriteBase::setNowAct(const char *sprite_url,int count,int dir_id)
{	
	//if (m_type == PLAYER_FEMALE_TYPE && m_roledata.acttodo == run)
	//	main_sprite->isShowLog = true;
	//else
	//	main_sprite->isShowLog = false;

	Animation* act = nullptr;
	if (m_isFixAnimDir)
	{
		dir_id = fixAnimDir(dir_id);
	}
	char animKey[128];
	int tmpSymbolKey1[] = {}; //"%s%s%d"
	std::string key1 = HandleString(tmpSymbolKey1, STRNUMSIG);	
	sprintf(animKey,key1.c_str(),m_roledata.spiritUrl.c_str(),sprite_url,dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_openActionCheck && m_roledata.animKey.compare(animKey) != 0){
		m_actionStateChange = true;
	}
	m_roledata.animKey = animKey;
	bool has_load_res = false;
	if(cacheAnim){
		//if (m_type == PLAYER_FEMALE_TYPE)
			//CCLOG("GET ANIM KEY:%s",animKey);

		has_load_res = true;
		act = cacheAnim;
		if(m_roledata.acttodo ==  death){
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			main_sprite->setSpriteFrame(backFrame);
		}
	}
	if(act == nullptr){
		bool tryLoadRes = false;   //是否尝试加载资源
		act = Animation::create();
		char strurl[128] = "";
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		for(int i = 0; i < count ; i++)
		{
			std::string ss = m_roledata.spiritUrl;	
			memset(strurl,0,128);
			int tmpSymbolKey[] = {}; //"%s%d%04d.png"
			std::string keyA = HandleString(tmpSymbolKey, STRNUMSIG);
			sprintf(strurl,keyA.c_str(),sprite_url,dir_id,i);
			ss.append(strurl);
			
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if(frame)
			{
				has_load_res = true;
				act->addSpriteFrame(frame);
				if(m_roledata.acttodo ==  death && i==(count-1))
				{
					main_sprite->setSpriteFrame(frame);
				}
			}
			else if(i == 0 && tryLoadRes == false)
			{
				//头一帧为空，进行加载Plist及资源
				//加载完成，将i倒退一，重新开始创建动画
				tryLoadRes = true;
				memset(strurl,0,128);
				if(m_roledata.spiritUrl.length()>1)
				{
					if(m_plist_num > 1)
					{
						for(int i=1;i<=m_plist_num;i++)
						{
							//getPlistPath(strurl,i);
							getPlistPath2(strurl, m_actionPvrPath, i);
							sprintf(strurl,"%s.plist",strurl);
							cache->addSpriteFramesWithFile(strurl);
						}
					}
					else
					{
						//getPlistPath(strurl);
						memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
						sprintf(strurl,"%s.plist",strurl);
						cache->addSpriteFramesWithFile(strurl);
					}
				}
				i -= 1;
			}
		}
		if(act && has_load_res == true){
			//CCLOG("NEW ANIM KEY:%s",animKey);
			AnimationCache::getInstance()->addAnimation(act,animKey);
		}
	}
	if(has_load_res && m_load_all == false){
		//检查是否所有资源已加载
		if(m_needLoadTexturePathList.size() > 0){
			bool find = false;
			for(auto it = m_needLoadTexturePathList.begin();it != m_needLoadTexturePathList.end();){
				std::string info = (*it).first;
				if(info.compare(m_actionPvrPath) == 0){
					find = true;
					m_needLoadTexturePathList.erase(it++);
					break;
				}else{
					it++;
				}
			}
			if(find){
				Vector<AnimationFrame*> frams = act->getFrames();
				SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
				firstFrame->retain();
				m_needReleaseFrameList.push_back(firstFrame);
			}
			if(m_needLoadTexturePathList.size() <= 0)
				m_load_all = true;
		}else{
			m_load_all = true;
			Vector<AnimationFrame*> frams = act->getFrames();
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			firstFrame->retain();
			m_needReleaseFrameList.push_back(firstFrame);
		}
	}
	if(has_load_res && m_sprite_init == false){
		Vector<AnimationFrame*> frams = act->getFrames();
		m_sprite_init = true;
		SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
		//main_sprite->setTextureCustom(firstFrame->getTexture());
		//main_sprite->setTextureRect(firstFrame->getRect());
		main_sprite->setSpriteFrame(firstFrame);
		if(m_roledata.acttodo ==  death){
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			main_sprite->setSpriteFrame(backFrame);
		}
		if(m_spriteInitCb > 0){
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			pStack->pushString(m_actorId.c_str());
			pStack->pushFloat(firstFrame->getRect().size.height);
			pStack->executeFunctionByHandler(m_spriteInitCb, 2);
			pStack->clean();
		}
	}
	return act;
}
#endif

bool SpriteBase::getActorFlag()
{
	return isactor_flag;
}
//void SpriteBase::addTextureSprite(Texture2D *a)
//{
//	if(m_plist_num<0 || m_plist_num > 4 || m_plist_loadnum <0 || m_plist_loadnum > 4 || m_roledata.spiritUrl.length()<2)
//	{
//		return;
//	}
//	SpriteFrameCache* cache = SpriteFrameCache::getInstance();  
//	char strurl[128] = {0};
//	memset(strurl,0,128);
//	if(m_plist_num <= 1)
//	{
//		getPlistPath(strurl);
//		if(strlen(strurl)>1)
//		{
//			sprintf(strurl,"%s.plist",strurl);
//			cache->addSpriteFramesWithFile(strurl);
//			playAction(m_stand_times,m_roledata.acttodo,m_roledata.dir,0);
//		}
//	}
//	else
//	{
//		m_plist_loadnum++;
//		if(m_plist_loadnum>=m_plist_num)
//		{
//			for(int i=1;i<=m_plist_num;i++)
//			{
//				memset(strurl,0,128);
//				getPlistPath(strurl,i);
//				if(strlen(strurl)<=1)
//				{
//					return;
//				}
//				sprintf(strurl,"%s.plist",strurl);
//				cache->addSpriteFramesWithFile(strurl);
//			}
//			playAction(m_stand_times,m_roledata.acttodo,m_roledata.dir,0);
//			m_plist_loadnum = 0;
//		}
//		
//	}
//}
//
//void SpriteBase::addSpriteFramesWithFile()
//{	
//	char strurl[128] = {0};
//	m_plist_loadnum = 0;
//	if(m_plist_num > 1)
//	{
//		for(int i=1;i<=m_plist_num;i++)
//		{
//			memset(strurl,0,128);
//			getPlistPath(strurl,i);
//			sprintf(strurl,"%s.%s",strurl,m_resSuffix.c_str());
//			std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(SpriteBase::addTextureSprite,this);
//			Director::getInstance()->getTextureCache()->addImageAsync(strurl,addTexture);
//		}
//	}
//	else
//	{
//		memset(strurl,0,128);
//		getPlistPath(strurl);
//		sprintf(strurl,"%s.%s",strurl,m_resSuffix.c_str());
//		std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(SpriteBase::addTextureSprite,this);
//		Director::getInstance()->getTextureCache()->addImageAsync(strurl,addTexture);
//	}
//}

bool SpriteBase::getResLoadStatus()
{
	return m_sprite_init;
}
Animation* SpriteBase::getNowActByDir()
{
	/**
	* 方向对应资源名
	* 上   = 0
	* 右上 = 1
	* 右   = 2
	* 右下 = 3
	* 下   = 4
	*/
	Animation* act = nullptr;
	//main_sprite->setFlippedX(false);

	// 主精灵旋转了, 不能把整个节点反转
	Node* node = nullptr;
	if (m_type == FAIRY_TYPE)
	{
		node = main_sprite;
	}
	else if (m_type == MAGIC_WEAPON_TYPE)
	{
		node = Node::create();
	}
	else
	{
		node = main_node;
	}
	node->setScaleX(1);

	int dir_id = 0;
	switch (m_roledata.dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		node->setScaleX(-1);
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		node->setScaleX(-1);
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		node->setScaleX(-1);
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}

	int tmpSymbolKey1[] = {}; //"/run/"
	std::string key1 = HandleString(tmpSymbolKey1, STRNUMSIG);

	int tmpSymbolKey2[] = {}; //"/ride_run/"
	std::string key2 = HandleString(tmpSymbolKey2, STRNUMSIG);	

	int tmpSymbolKey3[] = {}; //"/stand/"
	std::string key3 = HandleString(tmpSymbolKey3, STRNUMSIG);	

	int tmpSymbolKey4[] = {}; //"/ride_stand/"
	std::string key4 = HandleString(tmpSymbolKey4, STRNUMSIG);			

	int tmpSymbolKey5[] = {}; //"/attack_%02d/"
	std::string key5 = HandleString(tmpSymbolKey5, STRNUMSIG);	

	int tmpSymbolKey6[] = {}; //"/attack/"
	std::string key6 = HandleString(tmpSymbolKey6, STRNUMSIG);	

	int tmpSymbolKey7[] = {}; //"/injured/"
	std::string key7 = HandleString(tmpSymbolKey7, STRNUMSIG);	

	int tmpSymbolKey8[] = {}; //"/death/"
	std::string key8 = HandleString(tmpSymbolKey8, STRNUMSIG);	

	int tmpSymbolKey9[] = {}; //"/attack_%02d/"
	std::string key9 = HandleString(tmpSymbolKey9, STRNUMSIG);	

	int tmpSymbolKey10[] = {}; //"/attack/%s"
	std::string key10 = HandleString(tmpSymbolKey10, STRNUMSIG);	

	int tmpSymbolKey11[] = {}; //"/fly_%02d/"
	std::string key11 = HandleString(tmpSymbolKey11, STRNUMSIG);	

	int tmpSymbolKey12[] = {}; //"/hurt_idle/"
	std::string key12 = HandleString(tmpSymbolKey12, STRNUMSIG);	

	int tmpSymbolKey13[] = {}; //"/hurt_kneel/"
	std::string key13 = HandleString(tmpSymbolKey13, STRNUMSIG);	

	int tmpSymbolKey14[] = {}; //"/attack_03/"
	std::string key14 = HandleString(tmpSymbolKey14, STRNUMSIG);	

	int tmpSymbolKey15[] = {}; //"/attack_04/"
	std::string key15 = HandleString(tmpSymbolKey15, STRNUMSIG);	

	int tmpSymbolKey16[] = {}; //"/collide/"
	std::string key16 = HandleString(tmpSymbolKey16, STRNUMSIG);	

	int tmpSymbolKey17[] = {}; //"/dig/"
	std::string key17 = HandleString(tmpSymbolKey17, STRNUMSIG);	

	int tmpSymbolKey18[] = {}; //"/excavate/"
	std::string key18 = HandleString(tmpSymbolKey18, STRNUMSIG);	

	int tmpSymbolKey19[] = {}; //"/create/"
	std::string key19 = HandleString(tmpSymbolKey19, STRNUMSIG);	
	 
	switch (m_roledata.acttodo)
	{
	case walk:
	case run:
		if(getOnRide() == false){
			if(run_inited)
				act = setNowAct(key1.c_str(),m_roledata.maxcut_run,dir_id);
		}else{
			if(ride_inited)
				act = setNowAct(key2.c_str(),m_roledata.maxcut_ride_run,dir_id);
		}
		break;
	case stand:
	case standby:
		if(getOnRide() == false){
			if(stand_inited)
				act = setNowAct(key3.c_str(),m_roledata.maxcut_stand,dir_id);
		}else{
			if(ride_inited)
				act = setNowAct(key4.c_str(),m_roledata.maxcut_ride_stand,dir_id);
		}
		break;
	case attack:
		if(attack_inited)
		{
			char temp[32] = {0};
			if (m_attack_mode > 0 && m_attack_mode < 13)
			{
				sprintf(temp,key5.c_str(),m_attack_mode);
			}
			else
			{
				sprintf(temp, key6.c_str(), "");
			}
			int cut = m_roledata.maxcut_attack;
			switch (m_attack_mode)
			{
			case 1:
				cut = m_roledata.maxcut_attackmode_01;
				break;
			case 2:
				cut = m_roledata.maxcut_attackmode_02;
				break;
			case 3:
				cut = m_roledata.maxcut_attackmode_03;
				break;
			case 4:
				cut = m_roledata.maxcut_attackmode_04;
				break;
			case 5:
				cut = m_roledata.maxcut_attackmode_05;
				break;
			case 6:
				cut = m_roledata.maxcut_attackmode_06;
				break;
			case 7:
				cut = m_roledata.maxcut_attackmode_07;
				break;
			case 8:
				cut = m_roledata.maxcut_attackmode_08;
				break;
			case 9:
				cut = m_roledata.maxcut_attackmode_09;
				break;
			case 10:
				cut = m_roledata.maxcut_attackmode_10;
				break;
			case 11:
				cut = m_roledata.maxcut_attackmode_11;
				break;
			case 12:
				cut = m_roledata.maxcut_attackmode_12;
				break;
			default:
				break;
			}
			/*act = setNowAct(temp,m_roledata.maxcut_attack,dir_id);*/
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt:
		if(hurt_inited)
			act = setNowAct(key7.c_str(),m_roledata.maxcut_hurt,dir_id);
		break;
	case death:
		if(death_inited)
			act = setNowAct(key8.c_str(),m_roledata.maxcut_death,dir_id);
		break;
	case magicup:
		//现在废弃 不用了
		if(magic_inited)
		{
			char temp[32] = {0};
			if (m_attack_mode > 0 && m_attack_mode < 3)
			{
				sprintf(temp,key9.c_str(),m_attack_mode);
			}
			else
			{
				sprintf(temp,key10.c_str(),"");
			}
			act = setNowAct(temp,m_roledata.maxcut_magic,dir_id);
		}
		break;
	case fly:
		if(fly_inited){
			char temp[32] = {0};
			sprintf(temp,key11.c_str(),m_fly_mode);
			int cut = m_roledata.maxcut_fly01;
			switch (m_fly_mode){
			case 1:
				cut = m_roledata.maxcut_fly01;
				break;
			case 2:
				cut = m_roledata.maxcut_fly02;
				break;
			case 3:
				cut = m_roledata.maxcut_fly03;
				break;
			default:
				break;
			}
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt_idle:
		if(hurt_inited_idle)
			act = setNowAct(key12.c_str(),m_roledata.maxcut_hurt_idle,dir_id);
		break;
	case hurt_kneel:
		if(hurt_kneel_inited)
			act = setNowAct(key13.c_str(),m_roledata.maxcut_hurt_kneel,dir_id);
		break;
	case attack_03:
		if(attack_rush_inited)
			act = setNowAct(key14.c_str(),m_roledata.maxcut_attack_03,dir_id);
		break;
	case attack_04:
		if(attack_rush_inited)
			act = setNowAct(key15.c_str(),m_roledata.maxcut_attack_04,dir_id);
		break;
	case collide:
		if(magic_inited)
			act = setNowAct(key16.c_str(),m_roledata.maxcut_magic,dir_id);
		break;
	case dig:
		act = setNowAct(key17.c_str(),1,dir_id);
		break;
	case excavate:
		act = setNowAct(key18.c_str(),3,dir_id);
		break;
	case create_:
		act = setNowAct(key19.c_str(),4,dir_id);
		break;
	default:
		break;
	}
	return act;
}

void SpriteBase::refresh(){
	playAction(-1,ACTION_NONE,dir_none,-100,-1);
}

bool SpriteBase::changeState(ActionState actionState)
{
	if( m_currActionState == actionState && actionState!=ACTION_STATE_IDLE)
	{
		if(m_currActionState == ACTION_STATE_WALK||m_currActionState ==ACTION_STATE_RUN)
			return false;
	}
	if((m_currActionState == ACTION_STATE_DEAD && actionState != ACTION_STATE_REMOVE ))
	{
		this->stopAllActions();
		return false;
	}
	// 如果被控制状态, 除非死亡不能切换状态
	if( beControl() && actionState != ACTION_STATE_DEAD && actionState != ACTION_STATE_IDLE)
	{
		return false;
	}
	if(actionState == ACTION_STATE_DEAD){
		this->stopAllActions();
	}

	m_currActionState = actionState;
	return true;
}

bool SpriteBase::beControl()
{
	if ( m_currActionState >= ACTION_STATE_CHENMO && m_currActionState <= ACTION_STATE_CHAOS)
	{
		return true;
	}
	return false;
}
//bool SpriteBase::streakToTheDir(float times,Vec2 pos,Commen_Direction dir)
//{
//	if(getCurrActionState() != ACTION_STATE_FLY && getCurrActionState() != ACTION_STATE_SUDDEN){
//		setSpriteDir(dir);
//		playAction(-1,ACTION_NONE,dir_none,-100,-1);
//		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1),CallFunc::create([&](){ 
//			//TODO 每隔0.2表创建一个当前动画的影子
//			this->addPhantomMoveEffect(0);
//		}),nullptr));
//		shadownAction->setTag(ACTION_SHADOW_TAG);
//		runAction(shadownAction);
//	}
//	//char strurl[128] = {0};
//	//std::string ss = m_roledata.spiritUrl;	
//	//memset(strurl,0,128);
//	//int dir_temp = getDirIDByDir(NULL,dir);
//	//bool flipX = false;
//	//if(dir_temp < 0){
//	//	dir_temp = -dir_temp;
//	//	flipX = true;
//	//}
//	//char* action_url = "/run/%d0004.png";
//	//int temp_dir = (int)dir;
//	//switch (action)
//	//{
//	//case run:
//	//	action_url = "/run/%d0004.png";
//	//	break;
//	//case stand:
//	//	action_url = "/stand/%d0001.png";
//	//	if(temp_dir >= 4)
//	//		temp_dir = temp_dir - 4; 
//	//	else
//	//		temp_dir = temp_dir + 4;
//	//	break;
//	//case fly:
//	//	action_url = "/fly/%d0003.png";
//	//	break;
//	//case attack:
//	//	break;
//	//case hurt:
//	//	break;
//	//case death:
//	//	break;
//	//case funny:
//	//	break;
//	//case magicup:
//	//	break;
//	//case walk:
//	//	break;
//	//case collide:
//	//	break;
//	//case dig:
//	//	break;
//	//case excavate:
//	//	break;
//	//case create_:
//	//	break;
//	//case standby:
//	//	break;
//	//default:
//	//	break;
//	//}
//	//sprintf(strurl,action_url,dir_temp);
//	//ss.append(strurl);
//	////log(ss.c_str());
//	//SpriteFrame *frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(ss);
//	//if(frame)
//	//{
//	//	Point base = getTileByDir((Commen_Direction)temp_dir);
//	//	for(int i = 1;i<5;i++)
//	//	{
//	//		Sprite *sub_sprite = Sprite::createWithSpriteFrame(frame);
//	//		if(sub_sprite)
//	//		{
//	//			this->removeChildByTag(1000 + i);
//	//			sub_sprite->setFlippedX(flipX);
//	//			sub_sprite->setPosition(base*i);
//	//			sub_sprite->setOpacity(255*(1-0.1*i));
//	//			//if(dir == dir_left_down || dir == dir_left_up ||dir == dir_left)
//	//			//	sub_sprite->setFlippedX(true);
//	//			addChild(sub_sprite,0,1000+i);
//	//			FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
//	//				for(int i = 1;i<5;i++){
//	//					int tag = 1000 + i;
//	//					auto obj = this->getChildByTag(tag);
//	//					if(obj)
//	//						obj->removeFromParent();
//	//				}
//	//				//sub_sprite->removeFromParent();
//	//			});
//	//			sub_sprite->runAction(Sequence::create(FadeTo::create(times,200/i),actbackfun,NULL));
//	//		}
//	//	}
//	//}
//	//return false;
//}
Vec2 SpriteBase::getTileByDir(Commen_Direction dir) 
{
	switch (dir)
	{
	case dir_up:
		return  Vec2(0,-16);
	case dir_down:
		return  Vec2(0,16);
	case dir_left:
		return  Vec2(24,0);
	case dir_right:
		return  Vec2(-24,0);
	case dir_left_up:
		return  Vec2(24,-16);
	case dir_right_up:
		return  Vec2(-24,-16);
	case dir_left_down:
		return  Vec2(24,16);
	case dir_right_down:
		return  Vec2(-24,16);
	default:
		return  Vec2(0,-16);
	}
	return Vec2::ZERO;
}

Vec2 SpriteBase::getDirectionByDir(Commen_Direction dir){
	return (getTileByDir(dir)*-1).getNormalized();
}

int SpriteBase::getDirIDByDir(Sprite* sp,Commen_Direction dir)
{
	int dir_id = 0;
	switch (dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		dir_id = -2;
		break;
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		dir_id = -1;
		break;
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		dir_id = -3;
		break;
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
	if(m_type == WING_TYPE&&(m_roledata.acttodo==attack||m_roledata.acttodo==excavate||m_roledata.acttodo==collide||m_roledata.acttodo==magicup))
	{
		bool unneed_flip = false;
		switch (dir)
		{
			case dir_left:
				dir_id = 6;
				unneed_flip = true;
				break;
			case dir_left_up:
				dir_id = 7;
				unneed_flip = true;
				break;
			case dir_left_down:
				dir_id = 5;
				unneed_flip = true;
				break;
			default:
				break;
		}
		if(unneed_flip&&sp)
			sp->setFlippedX(false);
	}
	return dir_id;
}

bool SpriteBase::doStreakToTheDir(float times,Vec2 pos,Commen_Direction dir)
{
	if(getCurrActionState() != ACTION_STATE_FLY && getCurrActionState() != ACTION_STATE_SUDDEN && getCurrActionState()<ACTION_STATE_DEAD)
	{
		stopActionByTag(ACTION_SHADOW_TAG);

		setSpriteDir(dir);
		playAction(-1,ACTION_NONE,dir_none,-100,-1);
		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
			//TODO 每隔0.2表创建一个当前动画的影子
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

void SpriteBase::setOnRide(int ride_id){
	m_onRide_id = ride_id;
}
bool SpriteBase::getOnRide(){
	return !(m_onRide_id == 0);
}
int SpriteBase::getOnRideId(){
	return m_onRide_id;
}


int SpriteBase::getLocalZOrder()
{
	return this->_localZOrder;
}

void SpriteBase::setAttackMode(int attackMode)
{
	m_attack_mode = attackMode;
}
int SpriteBase::getAttackMode()
{
	return m_attack_mode;
}

void SpriteBase::setFlyMode(int flyMode){
	m_fly_mode = flyMode;
}

void SpriteBase::setResId(int resId)
{
	m_resId = resId;
}
int SpriteBase::getResId(void)
{
	return m_resId;
}

void SpriteBase::setParentReorderChildDirty(const bool isReorder) 
{ 
	Node* parent = getParent();
	if (parent != nullptr) 
	{ 
		parent->setReorderChildDirty(isReorder);
	} 
};

void SpriteBase::setVisible(bool visible)
{ 
	if(m_boHide)
		visible = false;
	bool old_visible = isVisible();
	if(m_father == nullptr)
	{
		Node::setVisible(visible);
	}
	else
	{
		if(m_father->isVisible()){
			Node::setVisible(visible);
		}
	}
	//记录自己的独立于父亲的可见状态
	m_visibleState = visible;

	//值不同时进行对应逻辑
	if(visible != old_visible)
	{
		//if (m_setVisibleCb && m_actorId>0)
		//{
		//	LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		//	if (pStack != nullptr)
		//	{
		//		pStack->pushInt(m_actorId);
		//		pStack->pushBoolean(visible);
		//		pStack->executeFunctionByHandler(m_setVisibleCb, 2);
		//		pStack->clean();
		//	}
		//}
		if(m_setVisibleCb > 0 && m_actorId != "")
		{
			ActorActionManageC::getInstance()->setVisible(m_actorId,visible);
		}
	}
}
void SpriteBase::setVisibleScreen(bool visible)
{ 
	//if(m_screenVisible != visible){
	//	if (m_setVisibleScreenCb && m_actorId>0)
	//	{
	//		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
	//		if (pStack != nullptr)
	//		{
	//			pStack->pushInt(m_actorId);
	//			pStack->pushBoolean(visible);
	//			pStack->executeFunctionByHandler(m_setVisibleScreenCb, 2);
	//			pStack->clean();
	//		}
	//	}
	//}
	if(m_screenVisible != visible){
		if(m_setVisibleScreenCb > 0 && m_actorId != ""){
			ActorActionManageC::getInstance()->setVisibleScreen(m_actorId,visible);
		}
	}

	m_screenVisible = visible;
}

void SpriteBase::setSingleVisible(bool visible)
{
	Node::setVisible(visible);
}

void SpriteBase::registerSetOpacityCb(int handler)
{
	m_setOpacityCb = handler;
}
void SpriteBase::removeSetOpacityCb()
{
	m_setOpacityCb = 0;
}

void SpriteBase::registerSetVisibleCb(int handler)
{
	m_setVisibleCb = handler;
}
void SpriteBase::removeSetVisibleCb()
{
	m_setVisibleCb = 0;
}

void SpriteBase::registerSetVisibleScreenCb(int handler)
{
	 m_setVisibleScreenCb = handler;
}
void SpriteBase::removeSetVisibleScreenCb()
{
	m_setVisibleScreenCb = 0;
}

void SpriteBase::registerSetWhiteCb(int handler)
{
	m_setWhiteCb = handler;
}
void SpriteBase::removeSetWhiteCb()
{
	m_setWhiteCb = 0;
}

void SpriteBase::registerSyncChildActionCb(int handler){
	m_syncActionCb = handler;
}
void SpriteBase::removeSyncChildActionCb()
{
	m_syncActionCb = 0;
}

void SpriteBase::registerSpriteInitCb(int handler){
	m_spriteInitCb = handler;
}

void SpriteBase::removeSpriteInitCb(){
	m_spriteInitCb = 0;
}


void SpriteBase::addAutoRemoveAction(float time){
	auto delayAction = DelayTime::create(time);
	auto callBackAction = CallFunc::create([&](){
		stopAllActions();
		this->removeFromParent();
	});
	runAction(Sequence::create(delayAction,callBackAction,nullptr));
}

/* 
添加幻影移动特效 
*/
void SpriteBase::addPhantomMoveEffect(float dt)
{
	if(m_boHide)
		return;
	SpriteFrame* spriteFrame = main_sprite->getSpriteFrame();
	SkillPhantomMoveEffect* effect = SkillPhantomMoveEffect::create(spriteFrame);
	Vec2 main_sprite_pos = main_sprite->getPosition();
	main_sprite_pos.add(this->getPosition());
	effect->setAnchorPoint(main_sprite->getAnchorPoint());
	effect->setPosition(main_sprite_pos);
	effect->setLocalZOrder(getLocalZOrder());
	effect->setOrderOfArrival(getOrderOfArrival());

	this->getParent()->addChild(effect);

	int dir_id = 0;
	switch (m_roledata.dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		effect->setFlippedX(true);
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		effect->setFlippedX(true);
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		effect->setFlippedX(true);
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
}

void SpriteBase::setRenderMode(int val)
{
	if (main_sprite)
	{
		main_sprite->setRenderMode(val);
	}
}