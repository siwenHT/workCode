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
	void showNameAndBlood(int name_show,int blood_show,int height = 0,bool checkHp = true);				
	void setNameAndBloodShow(bool show);		
	void syncNameAndBloodShow(int name_show,int blood_show);
	void setBloodType(int typeId);			
	void setBloodVisible(bool isVisible);
	void subBlood(int blood);
	bool isAlive();
	void setHP(uint64);
	uint64 getHP() {return m_hp;};
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
	CC_SYNTHESIZE(float, m_footprintsGap, FootprintsGap);				
	CC_SYNTHESIZE(bool, m_footprinsOpen, FootprintsOpen);				
	CC_SYNTHESIZE(cocos2d::Node*, m_name_label, NameLabel);
	CC_SYNTHESIZE(cocos2d::Node*, m_title_label, TitleLabel);
	CC_SYNTHESIZE(cocos2d::Node*, m_time_label, TimeLabel);
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
	virtual void updateMove(float delaTime);					
	virtual bool addMoveTarget(Vec2 pos,bool checkPos = true);						
	virtual void cleanMove(bool unsche = true);									
	virtual bool canMove();
	virtual bool isMove();
	CC_SYNTHESIZE(bool, m_justDelayCheck, JustDelayCheck); 
public:
	uint64 m_maxhp;
protected:
	float _remainTime;									
	float _overTime;									
	float _deltaTimeTmp;								
	std::deque<cocos2d::Vec2> m_targetPosList;			
	cocos2d::Vec2 m_curTargetPos;						
	cocos2d::Vec2 m_curTargetPos_tile;						
	float m_syncPosGap;									
	float m_syncPosMoveDistance;								
	float m_checkOpacityGap;
	float m_checkOpacityMoveDistance;
	float m_footprintsMoveDistance;
	int m_footprintsCb;							
private:
	std::string m_name;
	uint64 m_hp;
	cocos2d::Sprite* shadow_sprite;
	cocos2d::Sprite* m_blood_bg;
	cocos2d::Sprite* m_blood_back;
	cocos2d::Sprite* m_blood_pro;
	float update_pecent;
	float sub_pecent;
	int show_h;
	int m_showNameAndBloodState;			
	bool m_isBloodVisible;
	cocos2d::Size m_nameSize;
	int m_setPositionCb;
	int m_updateTopHeadPosCb;
	int m_setLocalZOrderCb;
	void updateBloodAction(float times);
public:
	void * accessRememberConversion(long onalthough); 
	unsigned short andqueryLimitedAkin(double destroying); 
	void factorialConstraintsFull(void * tilde); 
	bool eyesInitialization(short once,void * stoprocessing); 
	void * overheadCardIndeed(int encapsulation); 
	void styleRevisitedSpeak4(float trivial,long element,int finding,char obvious); 
	double ninesTreeNever(unsigned short order); 
static	unsigned short instantionSaysOperating(long several,char classesclick,short head); 
	unsigned short understandArrarecall(long manipulate,char owhich,float style,unsigned short copies); 
	void * implementingArgumentsEnds(double container); 
private:
	void * m_valuesProperTakingDeletes;
	void * m_recursionSpecification;
	double m_groupedConvertingInto;
	int m_subsetComponentsWithout;
};
#endif
