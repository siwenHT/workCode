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

	ACTION_STATE_CHENMO,           // 被沉默
	ACTION_STATE_XUANYUN,          // 眩晕
	ACTION_STATE_HURT_IDLE,        // 定身
	ACTION_STATE_HURT_KNEEL,      
	ACTION_STATE_CHAOS,            // 混乱

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
	ACTION_SHADOW_TAG = 26,						//残影动作TAG
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
	PLAYER_MANE_TYPE = 21,       //现表示美人
	PLAYER_FEMALE_TYPE = 22,     //表示角色
	ACTOR_TYPE = 30,
	SHOW_TYPE,                  //展示模型
	MAGIC_WEAPON_TYPE = 36,     //法宝
	FAIRY_TYPE = 37,            //小鬼怪
	ATTACK_EFFECT = 38,
	ANOTHER_TYPE=40,
}SpriteType;

typedef enum {
	SHOW_STATE_EMPTY = 0,			 //0表示没有检查资源没有加载资源    
	SHOW_STATE_ASSET = 1,			 //1表示本地有资源没有加载
	SHOW_STATE_LOADED = 2,			     //2表示有资源且加载过 但是没有加载plist
	SHOW_STATE_ALL = 3,			     //2表示有资源且加载过且加载过plist，可正常显示
}SHOW_STATE;

///*
//角色部件类型 
//同步Lua ActorComponentType
//*/
//enum class ActorComponentType
//{
//	Actor    = 1,  // 角色
//	Weapon   = 2,  // 武器
//	Wing     = 3,  // 翅膀
//	RideSheng= 4,  // 坐骑绳
//	Ride     = 5,  // 坐骑
//	Tattoo   = 6,  // 龙纹
//	Shadow   = 7,  // 影子
//
//	Title    = 10, // 头衔
//	Vip      = 11, // vip
//	Name     = 12, // 名字
//	BloodPro = 13, // 血条
//};

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
	//virtual bool init(MainRoledata roledata);  

	void reset();
	void setBaseUrl(const std::string&pszFileName);
	void setBaseAnchorPoint(cocos2d::Point anchorPoint);
	virtual void setBasePosition(cocos2d::Point pos);

	void initDependTexturePathList();					//初始化依赖的纹理路径列表
	void cleanDenpendFrames();

	/* 添加幻影移动特效 */
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
	bool getIsHide() {return m_boHide;};          //玩家是否隐藏
	void setIsHide(bool hide);          //玩家是否隐藏

	void addAutoRemoveAction(float time);

	virtual void standed();
	virtual void standedby(){};
	virtual void hurtKneelToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual void hurtIdleToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual void flyToTheDir(float times,int fly_mode,int handler,cocos2d::Vec2 newPos = cocos2d::Vec2::ZERO,Commen_Direction dir = dir_none,bool stand = true,bool auto_double_jump_check = false,bool checkSecondAction = false, int state = 0);
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false);
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool attackToPos(float times,cocos2d::Point newpoint,bool hasEffect = false);
	//virtual bool attack03ToPos(float times,cocos2d::Point newpoint,bool stand = false);
	//virtual bool attack04ToPos(float times,cocos2d::Point newpoint,bool stand = false);
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
	//根据点击坐标获得人物的朝向
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
	/*cocos2d::Animation* createAnimation(const char* formatStr, int frameCount, int fps);*/
	CC_SYNTHESIZE(ActionState, m_currActionState, CurrActionState);
	CC_SYNTHESIZE(GraySprite*, main_sprite, MainSprite);
	CC_SYNTHESIZE(Node*, main_node, MainNode);
	CC_SYNTHESIZE(cocos2d::Vec2, m_rocker_direction, RockerDirection);//摇杆的方向
	CC_SYNTHESIZE(cocos2d::Vec2, m_move_direction, MoveDirectionUpdate);		//移动方向
	void setTypeId(SpriteType typeId,bool initDepend = true);
	SpriteType getTypeId(){ return m_type; };

	CC_SYNTHESIZE(bool, m_load_all, LoadALL);		//移动方向

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
	bool canShowNormal();			//是否能正常显示，当资源不齐时，此值返回false
	virtual bool checkShow();		//检测资源是否齐全 
	virtual void updateShowState();

	void addSpriteFrameListAsync(char* fileName);		//异步加载plist文件
	void addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string fileName);
	void addSpriteFramePlistCallBack(bool suc);
	void addRenderListCallback();
	void cleanAsync();

	CC_SYNTHESIZE(std::string, m_async_pvr_path, AsyncPvrPath);
	CC_SYNTHESIZE(std::string, m_show_plist_path, ShowPlistPath);
	CC_SYNTHESIZE(std::string, m_show_texture_path, ShowTexturePath);

	bool changeState(ActionState actionState);
	bool beControl();

	CC_SYNTHESIZE(std::string, m_actorId, ActorId);      // 角色id
	CC_SYNTHESIZE(int, m_actorType, ActorType);  // 角色类型 
	int getLocalZOrder();                        // 深度值
	void setAttackMode(int attackMode);   
	int getAttackMode();
	void setFlyMode(int flyMode);
	void setResId(int resId);                    // 资源Id
	int getResId(void);                          // 资源Id

	virtual void setVisible(bool visible) override;
	void setVisibleScreen(bool visible);
	void setSingleVisible(bool visible);

	int fixAnimDir(int dir_id);

	CC_SYNTHESIZE(bool, m_visibleState, VisibleState);				//在父亲可见时，其所保持的 是否可见状态(父亲不可见，isVisible为false,当父亲可见时，根据此字段来决定是否可见)
	CC_SYNTHESIZE(SpriteType, m_FatherType, FatherType);  // 角色类型 
	CC_SYNTHESIZE(SpriteBase*, m_father, Father);					//父亲节点
	CC_SYNTHESIZE(cocos2d::Vec2, m_offsetPos, OffsetPos);           //偏移量
	CC_SYNTHESIZE(bool, m_screenVisible, ScreenVisible);
	CC_SYNTHESIZE(unsigned short, m_zOrderFlag, ZOrderFlag);        // 为1时角色朝上翅膀层在坐骑上层之下 
	CC_SYNTHESIZE(bool, m_isFixAnimDir, IsFixAnimDir);              // 是否减面
	CC_SYNTHESIZE(bool, m_isAddRenderList, IsAddRenderList);		//是否需要添加到队列显示

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

	//注册同步子结点方法回调
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
		//角色基本数据
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

	//替换模型类型
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
	bool attack_rush_inited;				//突进技能03、04比初始帧数
	bool ride_inited;
	int m_plist_num;
	int m_plist_loadnum;
	int m_opact;
	cocos2d::Rect m_touch_rect;
	std::string base_url_backUp;					//当处于攻击状态时，玩家显示精灵备份，待跳出攻击状态时，进行播放
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
	//void addSpriteFramesWithFile();
	//void addTextureSprite(cocos2d::Texture2D *a);
	//void addTextureSpritePre(cocos2d::Texture2D *a);
protected:
	//std::vector<std::string> m_needDownFileNameList;								//需要下载的文件列表
	std::map<std::string,cocos2d::EventListenerCustom*> m_downloadListenerList;				//下载事件监听列表 键值对
	std::vector<std::string> m_needLoadTextureList;										//需要加载的资源列表
	SHOW_STATE m_showState;														    //显示状态 0表示没有检查资源没有加载资源  1表示本地有资源没有加载  2表示有资源且加载过，可正常显示
	bool m_ischeck;																	//是否检查过显示（本地是否有资源文件，是否需要下载）
	bool m_ischecking;																//是否正在下载

	bool m_isLoadTexture;															//是否加载过资源
	bool m_isLoadTexturing;															//是否正在加载

	bool m_isLoadPlist;
	bool m_isLoadPlisting;

	bool m_isInRenderList;															//是否在渲染列表里面

	int m_loadPlistEntryId;
	int m_loadTextureEntryId;
	int m_renderListEntryId;

	int m_actionOpac;
	int m_actionOpac_c;
	int m_actionOpacGap;
	int m_actionOpa_state;

	cocos2d::Sprite* m_syncReplace;													//替代资源

	int m_resId;
	int m_setOpacityCb;
	int m_setVisibleCb;
	int m_setVisibleScreenCb;
	int m_setWhiteCb;
	int m_syncActionCb;
	int m_spriteInitCb;

	std::string m_resSuffix;						//资源类型
	bool m_checkResType;
	/* 是否隐藏 */
	bool m_boHide;
	bool m_sprite_init;


	std::unordered_map<std::string,int> m_needLoadTexturePathList;								//需要依赖加载的所有纹理路径列表
	std::vector<cocos2d::SpriteFrame*> m_needReleaseFrameList;						//需要主动释放的精灵帧列表
};
#endif//_SPIRIT_BASE_
