#ifndef _SPIRIT_BASE_H_
#define _SPIRIT_BASE_H_
#include "cocos2d.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"
#include "MainRoledata.h"
#include "GraySprite.h"
#include "SkillPhantomMoveEffect.h"
#include "vsdef.h"
#define PI				3.14159
typedef enum {
	ACTION_STATE_NONE = 0,
	ACTION_STATE_IDLE,
	ACTION_STATE_WALK,
	ACTION_STATE_RUN,
	ACTION_STATE_ATTACK,
	ACTION_STATE_MAGICUP,
	ACTION_STATE_COLLIDE,
	ACTION_STATE_HURT,
	ACTION_STATE_DIG,
	ACTION_STATE_EXCAVATE,
	ACTION_STATE_CREATE,
	ACTION_STATE_FLY,
	ACTION_STATE_SUDDEN,
	ACTION_STATE_CHENMO,           
	ACTION_STATE_XUANYUN,          
	ACTION_STATE_HURT_IDLE,        
	ACTION_STATE_HURT_KNEEL,      
	ACTION_STATE_CHAOS,            
	ACTION_STATE_DEAD,
	ACTION_STATE_REMOVE,
}ActionState;
typedef enum {
	ACTION_MOVE_TAG = 20,
	ACTION_FLY01_TAG = 21,
	ACTION_FLY02_TAG = 22,
	ACTION_SET_TILE_TAG = 23,
	ACTION_ATTACK_TAG = 24,
	ACTION_SUDDEN_TAG = 25,
	ACTION_SHADOW_TAG = 26,					
}ActionTag;
typedef enum {
	NONE_TYPE = -1,
	BASE_TYPE = 0,
	NPC_TYPE = 1,
	WUQI_TYPE = 2,
	HEAD_TYPE = 4,
	WING_TYPE = 6,
	RIDE_TYPE_UP = 7,
	RIDE_TYPE_DOWN = 8,
	TATTO_TYPE = 9,
	NORMAL_MONSTER = 10,
	ELIT_MONSTER,
	BOSS_MONSTER,
	JUQING_MONSTER,
	PET_MONSTER = 15,
	PLAYER_MANE_TYPE = 21,       
	PLAYER_FEMALE_TYPE = 22,     
	ACTOR_TYPE = 30,
	SHOW_TYPE,                  
	MAGIC_WEAPON_TYPE = 36,     
	FAIRY_TYPE = 37,            
	ATTACK_EFFECT = 38,
	ANOTHER_TYPE=40,
}SpriteType;
typedef enum {
	SHOW_STATE_EMPTY = 0,			 
	SHOW_STATE_ASSET = 1,			 
	SHOW_STATE_LOADED = 2,			     
	SHOW_STATE_ALL = 3,			     
}SHOW_STATE;
class SpriteBase : public cocos2d::Node
{
public: 
	SpriteBase();
	virtual ~SpriteBase(void);
	virtual bool isTouchInside(cocos2d::Touch* thisPos);
	virtual void setTouchEnable(bool enabled);
	virtual bool initWithFile(const std::string&pszFileName, std::string actorId = "");
	static SpriteBase* create(const std::string&pszFileName);
	static SpriteBase* create(const std::string&pszFileName, std::string actorId);
	static SpriteBase* create(const std::string&pszFileName,cocos2d::Size touch_size);
	void reset();
	void setBaseUrl(const std::string&pszFileName);
	void setBaseAnchorPoint(cocos2d::Point anchorPoint);
	virtual void setBasePosition(cocos2d::Point pos);
	void initDependTexturePathList();				
	void cleanDenpendFrames();
	void addPhantomMoveEffect(float dt);
	int calculationArrival(SpriteType type, int z);
	void updateZOrder(const Commen_Direction dir);
	void playActionData(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f,bool stopAnim = true);
	virtual void playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);
	void initStandStatus(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,Commen_Direction dir);
	void initRunStatus(const std::string&pszFileName,int maxcut);
	void initAttackStatus(const std::string&pszFileName,int maxcut);
	void initHurtStatus(const std::string&pszFileName,int maxcut);
	void initMagicStatus(const std::string&pszFileName,int maxcut);
	void initDeathStatus(const std::string&pszFileName,int maxcut);
	void initFlyStatus(int maxcut_fly01,int maxcut_fly02,int maxcut_fly03);
	void initHurtIdleStatus(const std::string&pszFileName,int maxcut);
	void initHurtKneelStatus(const std::string&pszFileName,int maxcut);
	void initAttackRushStatus(const std::string&pszFileName,int maxcut_03,int maxcut_04);
	void initRideStatus(int maxcut_stand,int max_run);
	void initAttackModeStatus(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12);
	void initWeaponEffFrames(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12);
	cocos2d::Vec2 getTileByDir(Commen_Direction dir);
	cocos2d::Vec2 getDirectionByDir(Commen_Direction dir);
	int getDirIDByDir(cocos2d::Sprite* sp,Commen_Direction dir);
	virtual bool doStreakToTheDir(float times,Vec2 pos,Commen_Direction dir);
	bool getIsHide() {return m_boHide;};          
	void setIsHide(bool hide);          
	void addAutoRemoveAction(float time);
	virtual void standed();
	virtual void standedby(){};
	virtual void hurtKneelToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual void hurtIdleToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual void flyToTheDir(float times,int fly_mode,int handler,cocos2d::Vec2 newPos = cocos2d::Vec2::ZERO,Commen_Direction dir = dir_none,bool stand = true,bool auto_double_jump_check = false,bool checkSecondAction = false, int state = 0);
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false);
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool attackToPos(float times,cocos2d::Point newpoint,bool hasEffect = false);
	virtual bool attackOneTime(float times,cocos2d::Point newpoint);
	virtual bool magicUpToPos(float times,cocos2d::Point newpoint);
	virtual void hasHurted(float delay,float times);
	virtual bool walkInTheDir(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual bool moveInTheDir(float times,cocos2d::Point pos,Commen_Direction dir = dir_none,bool stand = false);
	virtual bool collideInTheDir(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual void gotoDeath(Commen_Direction dir);
	virtual bool digToTheDir(float times,Commen_Direction dir){return false;};
	virtual bool excavateToTheDir(float times,Commen_Direction dir){return false;};
	virtual bool createToTheDir(float times,Commen_Direction dir);
	virtual void refresh();
	virtual void FixFlyPos(){};
	bool setDirByNowPoint(cocos2d::Point newpoint);
	Commen_Direction getDirByNewPoint(cocos2d::Point newpoint);
	virtual void stopInTheTime(ActionState toState);
	void stopMainSpriteAction();
	bool setSpriteDir(Commen_Direction dir);
	int setOpacity(int opac,bool update = true);
	int getOpacity();
	void doOpacityAction(int opac,float animTime);
	void updateOpacityAction(float times);
	void setColor(const cocos2d::Color3B& color) override;
	void setGray(bool isgray);
	void setWhite(bool isgray);
	bool getResLoadStatus();
	CC_SYNTHESIZE(ActionState, m_currActionState, CurrActionState);
	CC_SYNTHESIZE(GraySprite*, main_sprite, MainSprite);
	CC_SYNTHESIZE(Node*, main_node, MainNode);
	CC_SYNTHESIZE(cocos2d::Vec2, m_rocker_direction, RockerDirection);
	CC_SYNTHESIZE(cocos2d::Vec2, m_move_direction, MoveDirectionUpdate);	
	void setTypeId(SpriteType typeId,bool initDepend = true);
	SpriteType getTypeId(){ return m_type; };
	CC_SYNTHESIZE(bool, m_load_all, LoadALL);	
	int getShenbingStatus(){ return m_shenbingStatus;};
	virtual void setShenbingStatus(int state){
		m_shenbingStatus = state;
	}
	void setOnRide(int ride_id);
	bool getOnRide();
	int getOnRideId();
	bool getActorFlag();
	Commen_Direction getCurrectDir(){ return m_roledata.dir; }
	Commen_ActionToDo getCurrentActionState(){ return m_roledata.acttodo; }
	bool isactor_flag;
	void setPlistsNum(int num){ m_plist_num = num; }
	bool canShowNormal();		
	virtual bool checkShow();	
	virtual void updateShowState();
	void addSpriteFrameListAsync(char* fileName);	
	void addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string fileName);
	void addSpriteFramePlistCallBack(bool suc);
	void addRenderListCallback();
	void cleanAsync();
	CC_SYNTHESIZE(std::string, m_async_pvr_path, AsyncPvrPath);
	CC_SYNTHESIZE(std::string, m_show_plist_path, ShowPlistPath);
	CC_SYNTHESIZE(std::string, m_show_texture_path, ShowTexturePath);
	bool changeState(ActionState actionState);
	bool beControl();
	CC_SYNTHESIZE(std::string, m_actorId, ActorId);      
	CC_SYNTHESIZE(int, m_actorType, ActorType);  
	int getLocalZOrder();                        
	void setAttackMode(int attackMode);   
	int getAttackMode();
	void setFlyMode(int flyMode);
	void setResId(int resId);                    
	int getResId(void);                          
	virtual void setVisible(bool visible) override;
	void setVisibleScreen(bool visible);
	void setSingleVisible(bool visible);
	int fixAnimDir(int dir_id);
	CC_SYNTHESIZE(bool, m_visibleState, VisibleState);			
	CC_SYNTHESIZE(SpriteType, m_FatherType, FatherType);  
	CC_SYNTHESIZE(SpriteBase*, m_father, Father);				
	CC_SYNTHESIZE(cocos2d::Vec2, m_offsetPos, OffsetPos);           
	CC_SYNTHESIZE(bool, m_screenVisible, ScreenVisible);
	CC_SYNTHESIZE(unsigned short, m_zOrderFlag, ZOrderFlag);        
	CC_SYNTHESIZE(bool, m_isFixAnimDir, IsFixAnimDir);              
	CC_SYNTHESIZE(bool, m_isAddRenderList, IsAddRenderList);	
	CC_SYNTHESIZE(bool, m_isOpacAction, IsOpacAction);
	CC_SYNTHESIZE(bool, m_actionStateChange, ActionStateChange);
	CC_SYNTHESIZE(bool, m_openActionCheck, OpenActionCheck);
	void setParentReorderChildDirty(const bool isReorder);
	void registerSetOpacityCb(int handler);
	void removeSetOpacityCb();
	void registerSetVisibleCb(int handler);
	void removeSetVisibleCb();
	void registerSetVisibleScreenCb(int handler);
	void removeSetVisibleScreenCb();
	void registerSetWhiteCb(int handler);
	void removeSetWhiteCb();
	void registerSyncChildActionCb(int handler);
	void removeSyncChildActionCb();
	void registerSpriteInitCb(int handler);
	void removeSpriteInitCb();
	void setRenderMode(int val);
	float getStandTime();
	virtual void cleanup() override;
	virtual bool getIsRepMode() {return m_roledata.isRepMode ; }
private :
	bool checkPlayDefaultAction(void);
	void setDefaultActionPlistPath(void);
public: 
	
	MainRoledata m_roledata;
	bool stand_inited;
	float m_stand_times;
	int m_loop;
	int m_attack_mode;
	int m_fly_mode;
	int m_onRide_id;
	int m_auto_clean_cache;
	int m_shenbingStatus;
	SpriteType m_type;
	SpriteType m_repTypeId;
private:
	bool walk_inited;
	bool run_inited;
	bool attack_inited;
	bool hurt_inited;
	bool magic_inited;
	bool death_inited;
	bool fly_inited;
	bool hurt_inited_idle;
	bool hurt_kneel_inited;
	bool attack_rush_inited;			
	bool ride_inited;
	int m_plist_num;
	int m_plist_loadnum;
	int m_opact;
	cocos2d::Rect m_touch_rect;
	std::string base_url_backUp;				
	char m_actionPvrPath[128];
	char m_defaultActionPath[128];
	bool m_isWhite;
	bool m_touchEnabled;
private:
	void loadPlist();
    cocos2d::Animation* setNowAct(const char *sprite_url,int count,int dir_id);
	cocos2d::Animation* getNowActByDir();
	cocos2d::Animate* updateNowAnt(int RepeatNum);
	void getActionName(char* d);
	void getPlistPath(char *a);
	void getPlistPath2(char *d, char *s, int num, bool old = false);
protected:
	std::map<std::string,cocos2d::EventListenerCustom*> m_downloadListenerList;			
	std::vector<std::string> m_needLoadTextureList;									
	SHOW_STATE m_showState;														    
	bool m_ischeck;																
	bool m_ischecking;															
	bool m_isLoadTexture;														
	bool m_isLoadTexturing;														
	bool m_isLoadPlist;
	bool m_isLoadPlisting;
	bool m_isInRenderList;														
	int m_loadPlistEntryId;
	int m_loadTextureEntryId;
	int m_renderListEntryId;
	int m_actionOpac;
	int m_actionOpac_c;
	int m_actionOpacGap;
	int m_actionOpa_state;
	cocos2d::Sprite* m_syncReplace;												
	int m_resId;
	int m_setOpacityCb;
	int m_setVisibleCb;
	int m_setVisibleScreenCb;
	int m_setWhiteCb;
	int m_syncActionCb;
	int m_spriteInitCb;
	std::string m_resSuffix;					
	bool m_checkResType;
	bool m_boHide;
	bool m_sprite_init;
	std::unordered_map<std::string,int> m_needLoadTexturePathList;							
	std::vector<cocos2d::SpriteFrame*> m_needReleaseFrameList;					
public:
	long thereExecutedArray(bool functiopresented,int realizing,bool classes); 
static	float mismatchedIterators(unsigned short returns,short isbns); 
	float possibleContainers(int right,long harder,float infer,bool asfifth); 
	long stringSpecifyPrimary5(void * approach,char checks,int permitted); 
	short rationaleResolvedUnscoped(void * used,bool nonconst,double handles); 
	std::string suppliesRefersSolution(int primary,int literals,short designs); 
	unsigned short betweenErrorsNesting(void * describe); 
	long automaticSynthesizeNote(bool typedefs,void * would,char whereby,char expressions); 
	void * andqueryGrantsSmatch(float replaces,short restrictions,unsigned short wcould); 
private:
	char m_managedFollowedMatters3;
	std::string m_ensureExceptionFails3;
	int m_movementThingsBuild;
};
#endif
