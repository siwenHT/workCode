#include "SpriteBase.h"
#include "../common/FontChina.h"
#include "AsyncDownloadManager.h"
#include "CCLuaEngine.h"
#include "AsyncLoadPlist.h"
#include "ActorActionManageC.h"
#include "ActorRenderQueueManage.h"
USING_NS_CC;
static const int ActionResNameSize = 19;
static const char* ActionResName[ActionResNameSize] = 
{
	"",          
	"normal",    
	"normal",    
	"attack",    
	"",          
	"normal",    
	"",          
	"",          
	"normal",    
	"",          
	"",          
	"",          
	"",          
	"normal",    
	"fly",       
	"",          
	"",          
	"attack",    
	"attack"     
};
const int OrderOfArrivalZBase = 100000000;  
const int OrderOfArrivalRBase = 10000000;   
static const int ActionShowType[ActionResNameSize] = 
{
	0,    
	1,    
	1,    
	2,    
	0,    
	1,    
	0,    
	0,    
	1,    
	0,    
	0,    
	0,    
	0,    
	0,    
	3,    
	0,    
	0,    
	2,    
	2,    
};
static const int ActionShowTypeSize = sizeof(ActionShowType)/sizeof(int);
static const int ActionShowType_RideStand = 6; 
static const int ActionShowType_RideRun   = 7; 
static const int ActionShowType_OnRide = 8; 
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
	m_resSuffix = "png";
	m_checkResType = false;
	m_show_plist_path = "";
	m_show_texture_path = "";
	m_async_pvr_path = "";
	m_isOpacAction = false;
	m_actionOpac = 255;
	m_actionOpacGap = 255;
	m_actionOpac_c = 255;
	m_actionOpa_state = 1;   
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
	
		m_loadTextureEntryId = 0;
	}
	m_needLoadTextureList.clear();
	if(m_loadPlistEntryId != 0 && !m_show_plist_path.empty()){
		bool isFind = AsyncLoadPlist::getInstance()->unbindPlistAsyncWithEntryId(m_show_plist_path,m_loadPlistEntryId);
	
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
	
		m_showState = SHOW_STATE_EMPTY;
	else{
	
		m_showState = SHOW_STATE_ASSET;
		if(m_isLoadTexture){
		
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
	int tmpSymbolKey1[] = {58,32,61,0,58,47,31,32,71,31,35,61,75,0,58,14,64,61}; 
	std::string keyA = HandleString(tmpSymbolKey1, 18);
	const char* key1 = keyA.c_str();
	int tmpSymbolKey2[] = {58,32,61,0,58,47,31,32,71,31,35,61,75,0,58,14,64,61}; 
	std::string keyB = HandleString(tmpSymbolKey2, 18);
	const char* key2 = keyB.c_str();
	int tmpSymbolKey3[] = {58,32,61,0,25,40,72,35,71,31,35,61,75,0,25,14,64,61}; 
	std::string keyC = HandleString(tmpSymbolKey3, 18);
	const char* key3 = keyC.c_str();
	int tmpSymbolKey4[] = {58,32,61,0,25,35,10,6,71,31,35,61,75,0,25,35,10,6,14,64,61}; 
	std::string keyE = HandleString(tmpSymbolKey4, 21);
	const char* key4 = keyE.c_str();
	int tmpSymbolKey5[] = {58,32,61,0,58,35,43,32,71,31,35,61,75,0,58,35,43,32,14,64,61,14,64,61}; 
	std::string keyF = HandleString(tmpSymbolKey5, 24);
	const char* key5 = keyF.c_str();
	int tmpSymbolKey6[] = {48,75,75,48,50,80}; 
	std::string keyAttack = HandleString(tmpSymbolKey6, 6);
	const char* chrAttack = keyAttack.c_str();
	int tmpSymbolKey7[] = {10,47,58,18,48,31}; 
	std::string keyNormal = HandleString(tmpSymbolKey7, 6);
	const char* chrNormal = keyNormal.c_str();
	int tmpSymbolKey8[] = {58,35,43,32}; 
	std::string keyRide = HandleString(tmpSymbolKey8, 4);
	const char* chrRide = keyRide.c_str();
	int tmpSymbolKey9[] = {58,40,10}; 
	std::string keyRun = HandleString(tmpSymbolKey9, 3);
	const char* chrRun = keyRun.c_str();
	int tmpSymbolKey10[] = {61,75,48,10,43}; 
	std::string keyStand = HandleString(tmpSymbolKey10, 5);
	const char* chrStand = keyStand.c_str();
	char actionName[128] = "";
	switch (m_type)
	{
	case PLAYER_MANE_TYPE: 
	
		sprintf(strurl, key1, sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,chrAttack);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrNormal);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case PLAYER_FEMALE_TYPE:
	
		sprintf(strurl,key2, sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,chrAttack);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrNormal);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrRide);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case WUQI_TYPE:
		sprintf(strurl, key3, sub_str.c_str());
		if(m_FatherType != SpriteType::BASE_TYPE && m_FatherType == SpriteType::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action,"%s_%s",strurl,chrAttack);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,chrNormal);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
			sprintf(strurl_action,"%s_%s",strurl,chrAttack);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,chrNormal);
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		
		
		
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
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,chrRide);
		m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if(m_FatherType != SpriteType::BASE_TYPE && m_FatherType == SpriteType::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action, key5,sub_str.c_str(), chrStand); 
			m_needLoadTexturePathList.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
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
void SpriteBase::setBaseUrl(const std::string&pszFileName)
{
	if(getCurrActionState() == ACTION_STATE_ATTACK){
		base_url_backUp = pszFileName;
		return;
	}
	if(m_roledata.spiritUrl.compare(pszFileName) != 0){
		cleanAsync();
	
	
	
	
	
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
bool SpriteBase::checkShow(){
	if(m_ischecking == true || m_isLoadTexturing == true || m_isLoadPlisting == true)
		return false;
	if(m_ischeck && m_isLoadTexture && m_isLoadPlist) return m_showState == SHOW_STATE_ALL;
	if(m_showState == SHOW_STATE_ALL) return true;
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
			
				memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			}
			else
			{
			
				getPlistPath2(strurl, m_actionPvrPath, i);
			}
		
			char plistPath[128];
			char pvrPath[128];
			sprintf(plistPath,"%s.plist",strurl);
			sprintf(pvrPath,"%s.%s",strurl,m_resSuffix.c_str());
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
			
				m_ischecking = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(plistPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
			
				m_ischecking = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(pvrPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
		}
		if(needDownFileNameList.size()>0){
		
		
		
		
			if(m_type==NPC_TYPE||m_type==NORMAL_MONSTER||m_type == ELIT_MONSTER || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER|| m_type == PET_MONSTER||m_type == PLAYER_MANE_TYPE||m_type == PLAYER_FEMALE_TYPE){
				int tmpSymbolKey[] = {58,32,61,0,61,46,10,50,54,32,71,31,48,50,32,0,11,51,71,10,6}; 
				std::string keyA = HandleString(tmpSymbolKey, 21);
				m_syncReplace = Sprite::create(keyA.c_str());
				m_syncReplace->setPositionY(40);
				m_syncReplace->setTag(554);
				addChild(m_syncReplace);
			}
			for(std::map<std::string,bool>::iterator iter = needDownFileNameList.begin();iter != needDownFileNameList.end();iter++){
				std::string pszFileName = iter->first;
				bool addjob = iter->second;
			
				cocos2d::EventListenerCustom* customlistener = _eventDispatcher->addCustomEventListener(pszFileName.c_str(), [this](EventCustom* event){
				
				
				
				
					std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter_map = m_downloadListenerList.find(event->getEventName());
					if(iter_map != m_downloadListenerList.end()){
						_eventDispatcher->removeEventListener(iter_map->second);
						m_downloadListenerList.erase(iter_map);
					}
				
					if(m_downloadListenerList.size() <= 0){
						m_showState = SHOW_STATE_ASSET;
						removeChildByTag(554);
						m_isLoadTexture = false;
					
						m_ischecking = false;
						checkShow();
					}
				});
				m_downloadListenerList.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(pszFileName,customlistener));
				if(addjob)	AsyncDownloadManager::getInstance()->addJob(pszFileName,nullptr);
			
			}
			m_showState = SHOW_STATE_EMPTY;
		}else{
			m_showState = SHOW_STATE_ASSET;
		}
	}
	Texture2D* tex = nullptr;
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
	m_loadTextureEntryId = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}
void SpriteBase::addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string strurl){
	m_loadTextureEntryId = 0;
	m_isLoadTexturing = false;
	if(a == nullptr){
	
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
	assert(arrival>0);
	return arrival;
}
void SpriteBase::updateZOrder(const Commen_Direction dir)
{
	int z = 0;
	if (m_type == PLAYER_FEMALE_TYPE || m_type == PLAYER_MANE_TYPE || m_type == NPC_TYPE
		|| m_type == NORMAL_MONSTER  || m_type == ELIT_MONSTER     || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER)
	{
		z = 4; 
	}
	else if(m_type == TATTO_TYPE)
	{
		if(dir>0 && dir<4 )
		{ 
			z = 5; 
		}
		else
		{ 
			z = 7; 
		}
	}
	else if(m_type == WUQI_TYPE)
	{
		if(dir>4 && dir<8)
		{
			z = 7; 
		}
		else
		{
			z = 5; 
		}
	}
	else if(m_type == RIDE_TYPE_DOWN)
	{
		if(dir < 5)
		{
			z = 8; 
			if (m_zOrderFlag == 0)
			{
				z = 6; 
			}
		}
		else
		{
			z = 8; 
		}
	}
	else if(m_type == RIDE_TYPE_UP)
	{
		z = 2; 
	}
	else if(m_type == WING_TYPE)
	{
		if(dir < 5)
		{
			z = 7; 
		}
		else
		{
			z = 3; 
		}
	}
	if (z > 0)
	{
	
	
	
	
		if (m_resId > 0)
		{
			z = calculationArrival(m_type, z);
		}
	
	
	
	
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
		
			std::string val = m_actionPvrPath;
		}
		if (anim == nullptr)
		{
			CPLUSLog("[SpriteBase::playAction] get anim Fail, file = %s", m_actionPvrPath);
		}
}
#else
void SpriteBase::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
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
		
			getPlistPath(m_actionPvrPath);
		
			if(m_async_pvr_path.compare(m_actionPvrPath) == 0)
				return;
		
			if(m_needLoadTexturePathList.find(m_actionPvrPath) != m_needLoadTexturePathList.end()){
				char texPath[128] = "";
				sprintf(texPath,"%s.%s", m_actionPvrPath, m_resSuffix.c_str());
				Texture2D* tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(texPath);
				if (tex == nullptr)
				{
				
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
				
				}
				else
				{
				
					char plistPath[128] = "";
					sprintf(plistPath,"%s.plist", m_actionPvrPath);
					if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false)
					{
					
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
					
						if(!isPlayDefaultAction){
							main_sprite->stopAllActions();
							m_roledata.animKey = "";
						}
						addSpriteFrameListCallBack(tex,m_actionPvrPath);
					
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
			m_isAddRenderList = false;     
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
	
	
	}
}
void SpriteBase::hasHurted(float delay,float times)
{
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
	
		Rect t_rect = Rect(0, 0, 120, 160);
		Size c_size =  main_sprite->getContentSize();
	
		Rect r = Rect(c_size.width/2-t_rect.size.width/2,c_size.height/2 - 40,t_rect.size.width,t_rect.size.height);
	
		return r.containsPoint(local); 
	}
	return false;
}
 void SpriteBase::setTouchEnable(bool enabled){
	 m_touchEnabled = enabled;
 }
Commen_Direction SpriteBase::getDirByNewPoint(cocos2d::Point newpoint)
{
	Commen_Direction dir = dir_right_down; 
	Point my_pos = getPosition();
	float dista = newpoint.getDistance(my_pos);
	Point direct = (newpoint - my_pos);
	if(dista<5 || dista>3000) return dir_right_down;
	if(((direct.x >= -0.000001) &&(direct.x <= 0.000001) && (direct.y >= -0.000001)&& (direct.y <= 0.000001)) )
	return dir_right_down;
	{
		double angel = atan2(std::abs(direct.y),std::abs(direct.x));
	
	
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
		donghua->setDelayPerUnit(2.0f/15.0f);
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
			
				sprintf(actionName,"%s", ActionResName[acttodo]);
			}
			else
			{
			
				sprintf(actionName,"%s", "ride");
			}
			break;
		default:
			sprintf(actionName,"%s", ActionResName[acttodo]);
			break;
		}
	
	
	
	
	
	
	
	
	}
	memcpy(d, actionName, strlen(actionName));
}
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
	int tmpSymbolKey1[] = {58,32,61,0,58,47,31,32,71,31,35,61,75,0,58,14,64,61,14,64,61}; 
	std::string str1 = HandleString(tmpSymbolKey1, 21);
	const char* key1 = str1.c_str();
	int tmpSymbolKey2[] = {58,32,61,0,25,40,72,35,71,31,35,61,75,0,25,14,64,61,14,64,61}; 
	std::string str2 = HandleString(tmpSymbolKey2, 21);
	const char* key2 = str2.c_str();
	int tmpSymbolKey3[] = {58,32,61,0,62,32,48,43,71,31,35,61,75,0,62,32,48,43}; 
	std::string str3 = HandleString(tmpSymbolKey3, 18);
	const char* key3 = str3.c_str();
	int tmpSymbolKey4[] = {58,32,61,0,25,35,10,6,71,31,35,61,75,0,25,35,10,6,14,64,61,14,64,61}; 
	std::string str4 = HandleString(tmpSymbolKey4, 24);
	const char* key4 = str4.c_str();
	int tmpSymbolKey5[] = {58,32,61,0,58,35,43,32,71,31,35,61,75,0,58,35,43,32,14,64,61,14,64,61}; 
	std::string str5 = HandleString(tmpSymbolKey5, 24);
	const char* key5 = str5.c_str();
	int tmpSymbolKey6[] = {58,32,61,0,61,62,47,25,71,31,35,61,75,0,61,14,64,61}; 
	std::string str6 = HandleString(tmpSymbolKey6, 18);
	const char* key6 = str6.c_str();
	int tmpSymbolKey7[] = {58,32,61,0,18,47,10,61,75,32,58,0,18,14,64,61}; 
	std::string str7 = HandleString(tmpSymbolKey7, 16);
	const char* key7 = str7.c_str();
	int tmpSymbolKey8[] = {58,32,61,0,10,71,50,71,31,35,61,75,0,10,14,64,61}; 
	std::string str8 = HandleString(tmpSymbolKey8, 17);
	const char* key8 = str8.c_str();
	int tmpSymbolKey9[] = {58,32,61,0,61,80,35,31,31,32,13,13,50,32,75,61,0,64,61}; 
	std::string str9 = HandleString(tmpSymbolKey9, 19);
	const char* key9 = str9.c_str();
	int tmpSymbolKey10[] = {58,32,61,0,31,47,10,6,25,32,10,71,31,35,61,75,0,31,14,64,61}; 
	std::string str10 = HandleString(tmpSymbolKey10, 21);
	const char* key10 = str10.c_str();
	int tmpSymbolKey11[] = {58,32,61,0,13,48,42,48,47,71,31,35,61,75,0,18,14,64,61}; 
	std::string str11 = HandleString(tmpSymbolKey11, 19);
	const char* key11 = str11.c_str();
	int tmpSymbolKey12[] = {58,32,61,0,13,48,42,48,47,71,31,35,61,75,0,61,25,14,64,61}; 
	std::string str12 = HandleString(tmpSymbolKey12, 20);
	const char* key12 = str12.c_str();
	int tmpSymbolKey13[] = {58,32,61,0,42,48,61,32,71,31,35,61,75,0,42,14,64,61}; 
	std::string str13 = HandleString(tmpSymbolKey13, 18);
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
	int tmpSymbolKey[] = {58,32,61,0,58,35,43,32,71,31,35,61,75,0,58,35,43,32,14,64,61,14,61,75,48,10,43,51,71,31,35,61,75}; 
	std::string keyA = HandleString(tmpSymbolKey, 33);
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
int SpriteBase::fixAnimDir(int dir_id)
{
	
		if (dir_id == 0)
			dir_id = 1;
		else if (dir_id == 2)
			dir_id = 1;
		else if(dir_id == 4)
			dir_id = 3;
		
	return dir_id;
}
void SpriteBase::loadPlist()
{
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
		
		
		
		}
		if (!hasFindNewPlistFile)
		{
			getPlistPath2(newStrUrl, m_actionPvrPath, 0, true);
			sprintf(newStrUrl, "%s.plist", newStrUrl);
			plistExist = utils->isFileExist(newStrUrl);
			if (plistExist)
			{
			
			
			
				cache->addSpriteFramesWithFileAsync(newStrUrl);
			}
			else
			{
			
			}
		}
	}
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
	int tmpSymbolKey1[] = {64,61,64,61,64,43}; 
	std::string key1 = HandleString(tmpSymbolKey1, 6);
	sprintf(animKey, key1.c_str(), tmpUrl.c_str(), sprite_url, dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_openActionCheck && m_roledata.animKey.compare(animKey) != 0)
	{
		m_actionStateChange = true;
	}
	m_roledata.animKey = animKey;
	if(cacheAnim)
	{
	
	
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
			int tmpSymbolKey[] = {64,61,64,43,64,78,33,43,51,71,10,6}; 
			std::string keyA = HandleString(tmpSymbolKey, 12);
			sprintf(strurl, keyA.c_str(), sprite_url, dir_id, i);
			ss.append(strurl);
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if ((!bLoadPlist) && frame == nullptr)
			{
				bLoadPlist = true;
				loadPlist();
			}
		
			frame = cache->getSpriteFrameByName(ss);
			if (frame)
			{
			
			
			
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
			
			
			}
			else
			{
				if (!bOutError)
				{
					bOutError = true;
					if (i == 0)
					{
						int a = 1;
					
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
Animation* SpriteBase::setNowAct(const char *sprite_url,int count,int dir_id)
{
	Animation* act = nullptr;
	if (m_isFixAnimDir)
	{
		dir_id = fixAnimDir(dir_id);
	}
	char animKey[128];
	int tmpSymbolKey1[] = {64,61,64,61,64,43}; 
	std::string key1 = HandleString(tmpSymbolKey1, 6);
	sprintf(animKey,key1.c_str(),m_roledata.spiritUrl.c_str(),sprite_url,dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_openActionCheck && m_roledata.animKey.compare(animKey) != 0){
		m_actionStateChange = true;
	}
	m_roledata.animKey = animKey;
	bool has_load_res = false;
	if(cacheAnim){
	
		
		has_load_res = true;
		act = cacheAnim;
		if(m_roledata.acttodo ==  death){
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			main_sprite->setSpriteFrame(backFrame);
		}
	}
	if(act == nullptr){
		bool tryLoadRes = false;   
		act = Animation::create();
		char strurl[128] = "";
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		for(int i = 0; i < count ; i++)
		{
			std::string ss = m_roledata.spiritUrl;
			memset(strurl,0,128);
			int tmpSymbolKey[] = {64,61,64,43,64,78,33,43,51,71,10,6}; 
			std::string keyA = HandleString(tmpSymbolKey, 12);
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
			
			
				tryLoadRes = true;
				memset(strurl,0,128);
				if(m_roledata.spiritUrl.length()>1)
				{
					if(m_plist_num > 1)
					{
						for(int i=1;i<=m_plist_num;i++)
						{
						
							getPlistPath2(strurl, m_actionPvrPath, i);
							sprintf(strurl,"%s.plist",strurl);
							cache->addSpriteFramesWithFile(strurl);
						}
					}
					else
					{
					
						memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
						sprintf(strurl,"%s.plist",strurl);
						cache->addSpriteFramesWithFile(strurl);
					}
				}
				i -= 1;
			}
		}
		if(act && has_load_res == true){
		
			AnimationCache::getInstance()->addAnimation(act,animKey);
		}
	}
	if(has_load_res && m_load_all == false){
	
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
bool SpriteBase::getResLoadStatus()
{
	return m_sprite_init;
}
Animation* SpriteBase::getNowActByDir()
{
	Animation* act = nullptr;
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
	int tmpSymbolKey1[] = {0,58,40,10,0}; 
	std::string key1 = HandleString(tmpSymbolKey1, 5);
	int tmpSymbolKey2[] = {0,58,35,43,32,14,58,40,10,0}; 
	std::string key2 = HandleString(tmpSymbolKey2, 10);
	int tmpSymbolKey3[] = {0,61,75,48,10,43,0}; 
	std::string key3 = HandleString(tmpSymbolKey3, 7);
	int tmpSymbolKey4[] = {0,58,35,43,32,14,61,75,48,10,43,0}; 
	std::string key4 = HandleString(tmpSymbolKey4, 12);		
	int tmpSymbolKey5[] = {0,48,75,75,48,50,80,14,64,78,5,43,0}; 
	std::string key5 = HandleString(tmpSymbolKey5, 13);
	int tmpSymbolKey6[] = {0,48,75,75,48,50,80,0}; 
	std::string key6 = HandleString(tmpSymbolKey6, 8);
	int tmpSymbolKey7[] = {0,35,10,76,40,58,32,43,0}; 
	std::string key7 = HandleString(tmpSymbolKey7, 9);
	int tmpSymbolKey8[] = {0,43,32,48,75,62,0}; 
	std::string key8 = HandleString(tmpSymbolKey8, 7);
	int tmpSymbolKey9[] = {0,48,75,75,48,50,80,14,64,78,5,43,0}; 
	std::string key9 = HandleString(tmpSymbolKey9, 13);
	int tmpSymbolKey10[] = {0,48,75,75,48,50,80,0,64,61}; 
	std::string key10 = HandleString(tmpSymbolKey10, 10);
	int tmpSymbolKey11[] = {0,13,31,46,14,64,78,5,43,0}; 
	std::string key11 = HandleString(tmpSymbolKey11, 10);
	int tmpSymbolKey12[] = {0,62,40,58,75,14,35,43,31,32,0}; 
	std::string key12 = HandleString(tmpSymbolKey12, 11);
	int tmpSymbolKey13[] = {0,62,40,58,75,14,80,10,32,32,31,0}; 
	std::string key13 = HandleString(tmpSymbolKey13, 12);
	int tmpSymbolKey14[] = {0,48,75,75,48,50,80,14,78,21,0}; 
	std::string key14 = HandleString(tmpSymbolKey14, 11);
	int tmpSymbolKey15[] = {0,48,75,75,48,50,80,14,78,33,0}; 
	std::string key15 = HandleString(tmpSymbolKey15, 11);
	int tmpSymbolKey16[] = {0,50,47,31,31,35,43,32,0}; 
	std::string key16 = HandleString(tmpSymbolKey16, 9);
	int tmpSymbolKey17[] = {0,43,35,6,0}; 
	std::string key17 = HandleString(tmpSymbolKey17, 5);
	int tmpSymbolKey18[] = {0,32,77,50,48,36,48,75,32,0}; 
	std::string key18 = HandleString(tmpSymbolKey18, 10);
	int tmpSymbolKey19[] = {0,50,58,32,48,75,32,0}; 
	std::string key19 = HandleString(tmpSymbolKey19, 8);
	 
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
	m_visibleState = visible;
	if(visible != old_visible)
	{
	
	
	
	
	
	
	
	
	
	
	
		if(m_setVisibleCb > 0 && m_actorId != "")
		{
			ActorActionManageC::getInstance()->setVisible(m_actorId,visible);
		}
	}
}
void SpriteBase::setVisibleScreen(bool visible)
{ 
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
double SpriteBase::conceptIteratesManaged(long literals,void * differenbetween,char parentheses)
{
	m_commonlyTotalInvolved = 947.20;
	return 402.5;
}
void SpriteBase::equivalentReplacesCalled1(int initialized,long attempts,long large,std::string destruction)
{
	int executed = initialized - 891;
	std::string changed = "function  [SpriteBase:equivalentReplacesCalled1] calling!";
	changed.append("compares5");
}
void SpriteBase::slowThdefinesBack(long enable,bool initial,std::string surprisingly)
{
	long past = enable + 899;
	 bool system = false;
	if(system)
	{
		std::string system = "function  [SpriteBase:slowThdefinesBack] ok!";
	}
	else
	{
		std::string system;
		system.append("slowThdefinesBack arguments 1 enable Ok!");
		system.append("slowThdefinesBack arguments 2 initial Ok!");
		system.append("slowThdefinesBack arguments 3 surprisingly Ok!");
	}
}
void * SpriteBase::considerInterpreted(char ostream,std::string somewhere,float rvalue)
{
	m_commonlyTotalInvolved = 292.10;
	return nullptr;
}
float SpriteBase::givenChosenClearRegex(unsigned short mismatched,std::string parameters)
{
	m_commonlyTotalInvolved = 949.19;
	 bool parametea = false;
	if(parametea)
	{
		std::string parametea = "function  [SpriteBase:givenChosenClearRegex] called!";
	}
	else
	{
		std::string parametea;
		parametea.append("givenChosenClearRegex arguments 1 mismatched need Check!");
		parametea.append("givenChosenClearRegex arguments 2 parameters need Check!");
	}
	return 752.8f;
}
void SpriteBase::lookupLittlePromoted(bool addition)
{
	m_stoplightUnableBuilt = 172;
}
