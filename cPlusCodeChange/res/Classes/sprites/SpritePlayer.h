#ifndef _SPIRIT_PLAYER_
#define _SPIRIT_PLAYER_

#include "SpriteMonster.h"
//#include "SkillPhantomMoveEffect.h"


class MapView;


class SpritePlayer : public SpriteMonster 
{
public: 

	SpritePlayer();
	virtual ~SpritePlayer(void);
	//virtual bool initWithFile(const std::string&pszFileName);

	static SpritePlayer* create(const std::string&pszFileName,std::string actorflag, bool isMainRole = false);
	bool isActor();

	CC_SYNTHESIZE(std::string, m_role_id, RoleId); 
	CC_SYNTHESIZE(int, m_sex, Sex);
	CC_SYNTHESIZE(double, m_school, School);
	CC_SYNTHESIZE(bool, m_active, Active);
	CC_SYNTHESIZE(bool, m_unAttack, UnToAttack);
	CC_SYNTHESIZE(float, m_suddenSpeed, SuddenSpeed);
	CC_SYNTHESIZE(int, m_conveyState, ConveyState) //传送状态 默认为0， 1.传出地图， 2.地图切换中， 3.传入地图
	CC_SYNTHESIZE(bool, m_petOnRide, PetOnRide);    //美人是否在骑乘

	void setMapView(MapView* view);
	
	std::function<void(Commen_Direction, float,cocos2d::Vec2)> onWalk;
	std::function<void(int,int,cocos2d::Vec2,float,int)> onFly;
	std::function<void(void)> stop;
	std::function<void(int)> onAttack;
	std::function<void(double)> resetSpeed;
	std::function<float()> getTimeLeft;
	std::function<void(void)> stopMapAction;
	std::function<bool(int,cocos2d::Vec2,float,int)> onSuddenFinish;
	float getLeftTime(){return left_time;};
	void insertActionChild(SpriteBase* child, int z,int tag);
	void removeActionChild(SpriteBase* child);
	void removeActionChildByTag(int tag);
	void hideAllActionChild(bool allChild = false); //隐藏所有动作
	void showAllActionChild(bool allChild = false); //显示所有动作

	bool getIsConveyAction();

	void playActionWithChildren(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);
	void setAttackModeWithChildren(int attack_mode);
	void setOnRideWithChildren(int ride_id);
	void setFlyModeWithChildren(int flyMode);
	void syncFlyStateWithChildren(int flyState,bool hasBlock);
	void syncSendStateWithChildren(int sendState, bool hasBlock);

	void addWeaponEffect(int attack_mode,float times,float left_time);
	void setWeaponEffectPosOffset(int attack_mode, Vec2 posOffset1,Vec2 posOffset2,Vec2 posOffset3,Vec2 posOffset4,Vec2 posOffset5,Vec2 posOffset6,Vec2 posOffset7,Vec2 posOffset8);
	Vec2 getWeaponEffectPosOffset(int attack_mode);
	void setWeaponEffectPath(std::string path);
	std::string getWeaponEffectPath();
	int getAttackModeC();

	virtual void FixFlyPos() override;			//修复玩家飞行过程中被眩晕导致角色在阻档点

	//void initStandStatus(int standcut,int maxcut,float times,Commen_Direction dir);
	virtual void standed() override;
	virtual void standedby() override;
	virtual void setActionStateChange(bool val) override;

	virtual void flyToTheDir(float times,int fly_mode,int handler,Vec2 newPos = Vec2::ZERO,Commen_Direction dir = dir_none,bool stand = true,bool auto_double_jump_check = false,bool checkSecondAction = false, int state = 1) override;
	virtual void hurtIdleToPos(float times,cocos2d::Point pos,bool stand = true) override;
	virtual void hurtKneelToPos(float times,cocos2d::Point pos,bool stand = true) override;
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false) override;
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true) override;
	virtual bool attackToPos(float times,cocos2d::Point newpoint,bool hasEffect = false) override;
	//virtual bool attack03ToPos(float times,cocos2d::Point newpoint,bool stand = false) override;
	//virtual bool attack04ToPos(float times,cocos2d::Point newpoint,bool stand = false) override;

	void suddenToThePos(int suddenMode,Vec2 suddenTargetPos,float times = 0);

	bool playerAttackToPos(float times,cocos2d::Point newpoint,int attackMode, bool hasEffect,bool stand = true);
	virtual bool attackOneTime(float times,cocos2d::Point newpoint) override;
	virtual bool magicUpToPos(float times,cocos2d::Point newpoint) override;
	//virtual void hasHurted(float delay,float times);
	virtual bool walkInTheDir(float times,cocos2d::Point pos,Commen_Direction dir) override;
	virtual bool moveInTheDir(float times,cocos2d::Point pos,Commen_Direction dir = dir_none,bool stand = false) override;
	virtual bool collideInTheDir(float times,cocos2d::Point pos,Commen_Direction dir) override;
	virtual void gotoDeath(Commen_Direction dir) override;
	virtual bool digToTheDir(float times,Commen_Direction dir) override;
	virtual bool excavateToTheDir(float times,Commen_Direction dir) override;
	virtual void stopInTheTime(ActionState toState) override;
	virtual void refresh() override;
	virtual bool changeStateWithChildren(ActionState actionState);
	void setActorFlag(bool actorflag);											//是否玩家本身
	//add by univer 
	virtual bool doStreakToTheDir(float times,Vec2 pos,Commen_Direction dir) override;

	void registerPlayActionWithChildrenCb(int handler);
	void removePlayActionWithChildrenCb();

	void registerGotoDeathCb(int handler);
	void removeGotoDeathCb();

	void registerSetActorVisibleCd(int handler);
	void removeSetActorVisibleCd();

	void registerMoveKeyPosCb(int handler);
	void removeMoveKeyPosCb();

	void syncKeyPosToDetailMap(bool research = false,Vec2 flyTargetPos = Vec2::ZERO);

	void setSpeedFloatPercent(float percent);				//设置速度浮动值
	float getSpeedFloatPercent();

	virtual void setShenbingStatus(int state) override;
	//移动缓动机制
	virtual void stopMoveAction(bool unsche = true) override;
	virtual void updateMove(float delaTime) override;						//移动循环
	virtual bool addMoveTarget(Vec2 pos,bool checkPos = true) override;							//添加移动目标点
	virtual void cleanMove(bool unsche = true) override;										//停止移动
	static bool checkMovePos(Vec2 pos1,Vec2 pos);						//返回真，表示两者值一样大  针对像素点
	static int MOVE_CHECK_GAP;

	void changeRePlayTypeAndResId(SpriteType typeId, std::string resId);
private:
	//角色基本数据
	cocos2d::Vector<SpriteBase*> m_sprites;
	//cocos2d::Sprite* shadow_sprite;
	//cocos2d::Sprite* m_blood_bg;//血条
	//cocos2d::ProgressTimer* m_blood_pro;//血条
	//float update_pecent;
	float left_time;

	int m_random_mode;
	/* 幻影移动 */
	bool m_boPhantomMove;
	/* 幻影移动帧筛选 */
	int m_phantomMoveFrame;
	MapView* m_mapView;
	cocos2d::Vec2 flyInitPos;
	cocos2d::Node* flyNode;
	int flyTmpHandler;

	int m_playActionWithChildrenCb;
	int m_gotoDeathCd;
	int m_setActorVisibleCd;
	int m_moveKeyPosCb;
	
	float m_speedPercent;
	std::string m_weaponEffectPath;

	Vec2 m_weaponEffectPosOffset1[8];
	Vec2 m_weaponEffectPosOffset2[8];
	Vec2 m_weaponEffectPosOffset3[8];
	Vec2 m_weaponEffectPosOffset4[8];

	//Vec2 m_weaponEffectPosOffset1_2;
	//Vec2 m_weaponEffectPosOffset2_2;
	//Vec2 m_weaponEffectPosOffset3_2;
	//Vec2 m_weaponEffectPosOffset4_2;
};
#endif//_SPIRIT_PLAYER_
