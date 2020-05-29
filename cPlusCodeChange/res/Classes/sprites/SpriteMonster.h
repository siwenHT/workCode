#ifndef _SPIRIT_MASTER_
#define _SPIRIT_MASTER_

#include "SpriteBase.h"



class SpriteMonster : public SpriteBase 
{
public: 

	SpriteMonster();
	virtual ~SpriteMonster(void);
	bool initWithFileExt(const std::string&pszFileName, std::string actorId, bool isMainRole = false);

	static SpriteMonster* create(const std::string&pszFileName, std::string actorId = "");
	//-1表示不变 0表示显示 1表示不显示
	void showNameAndBlood(int name_show,int blood_show,int height = 0,bool checkHp = true);					//设置血条显示与否，并且调节高度
	void setNameAndBloodShow(bool show);			//优先级大于showNameAndBlood，为真表示血条常驻，为否表示不显示，如果调用此函数，则showNameAndBlood的show字段将会失效
	void syncNameAndBloodShow(int name_show,int blood_show);
	void setBloodType(int typeId);				//设置血条类型 默认及1表示怪物血条  2表示玩家绿色血条  3表示玩家红色血条
	void setBloodVisible(bool isVisible);
	void subBlood(int64 blood);
	bool isAlive();
	void setHP(int64);
	int64 getHP() {return m_hp;};
	//CC_SYNTHESIZE(int, m_hp, HP);
	CC_SYNTHESIZE(unsigned int, m_monster_id, MonsterId);
	uint64 getMaxHP(){ return m_maxhp; };
	void setMaxHP(uint64 maxHp){
		if(maxHp > 0)
			m_maxhp = maxHp;
	};

	CC_SYNTHESIZE(bool, m_showBloodAnim, ShowBloodAnim);
	CC_SYNTHESIZE(bool, m_needSyncPosToServer, NeedSyncPosToServer);
	CC_SYNTHESIZE(double, m_spead, Speed);
	CC_SYNTHESIZE(unsigned int, m_attack, Attack);
	CC_SYNTHESIZE(float, m_footprintsGap, FootprintsGap);					//足迹回调移动间隔
	CC_SYNTHESIZE(bool, m_footprinsOpen, FootprintsOpen);					//足迹开关
	CC_SYNTHESIZE(cocos2d::Node*, m_name_label, NameLabel);//名字
	CC_SYNTHESIZE(cocos2d::Node*, m_title_label, TitleLabel);//名称
	CC_SYNTHESIZE(cocos2d::Node*, m_time_label, TimeLabel);//刷新时间

	//CC_SYNTHESIZE(std::string, m_name, Name);
	std::string getName() { return m_name; }
	void setName(std::string _name) { m_name = _name; }
	CC_SYNTHESIZE(int, m_level, Level);


	int getShowHeight();
	virtual void setPosition(const cocos2d::Vec2 &position) override;
    virtual void setPosition(float x, float y) override;
	virtual void setLocalZOrder(int localZOrder) override;

	void setNameSize(cocos2d::Size& size);
	cocos2d::Size getNameSize(void);


	void registerSetLocalZOrderCb(int handler);
	void removeSetLocalZOrderCb();

	void registerSetPositionCb(int handler);
	void removeSetPositionCb();

	void registerUpdateTopHeadPosCb(int handler);
	void removeUpdateTopHeadPosCb();

	void registerFootprintsCb(int handler);
	void removeFootprintsCb();

	virtual void stopMoveAction(bool unsche = true);
	virtual void updateMove(float delaTime);						//移动循环
	virtual bool addMoveTarget(Vec2 pos,bool checkPos = true);							//添加移动目标点
	virtual void cleanMove(bool unsche = true);										//停止移动
	virtual bool canMove();
	virtual bool isMove();
	CC_SYNTHESIZE(bool, m_justDelayCheck, JustDelayCheck); 
public:
	uint64 m_maxhp;
protected:
	float _remainTime;										//当前路径所需时间
	float _overTime;										//当前路径经历过的时间
	float _deltaTimeTmp;									//因为卡顿导致多出的时间
	std::deque<cocos2d::Vec2> m_targetPosList;				//要行径的关键点列表
	cocos2d::Vec2 m_curTargetPos;							//当前要行径的目标点  像素点
	cocos2d::Vec2 m_curTargetPos_tile;							//当前要行径的目标点  地图格子
	float m_syncPosGap;										//每隔多少像素与服务器同步位置		
	float m_syncPosMoveDistance;									//当前移动了多少像素，与上一字段合作调用
	float m_checkOpacityGap;
	float m_checkOpacityMoveDistance;

	float m_footprintsMoveDistance;
	int m_footprintsCb;								//足迹移动回调
private:
	//角色基本数据
	std::string m_name;
	int64 m_hp;
	//bool isactor_flag;
	cocos2d::Sprite* shadow_sprite;
	cocos2d::Sprite* m_blood_bg;//血条
	cocos2d::Sprite* m_blood_back;//血条缓动
	cocos2d::Sprite* m_blood_pro;//血条
	float update_pecent;
	float sub_pecent;
	int show_h;
	int m_showNameAndBloodState;				//m_showNameAndBloodState显示状态 0正常  1血条和名字常驻 2不显示
	bool m_isBloodVisible;

	cocos2d::Size m_nameSize;

	int m_setPositionCb;
	int m_updateTopHeadPosCb;
	int m_setLocalZOrderCb;
	void updateBloodAction(float times);
};
#endif//_SPIRIT_MASTER_
