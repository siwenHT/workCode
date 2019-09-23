/************************************************************************/
/* 
	角色管理器
*/
/************************************************************************/
#ifndef _ACTOR_ACTION_MANAGER_C_H_
#define _ACTOR_ACTION_MANAGER_C_H_

#include "cocos2d.h"

#include <unordered_map>

#include "vsdef.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"
#include "MapView.h"
#include "SpriteBase.h"
#include "SpriteMonster.h"
#include "SpritePlayer.h"


typedef enum
{
	//NoneCom     = 0,
	Actor    = 1,  // 角色
	Weapon   = 2,  // 武器
	Wing     = 3,  // 翅膀
	RideSheng= 4,  // 坐骑绳
	Ride     = 5,  // 坐骑
	Tattoo   = 6,  // 龙纹

	Shadow   = 7,  // 影子
	ShenBingEffect = 8,  // 神兵脚底特效           --无
	Bottom         = 9,  // 底部其他一些特效（选中,指引等）

	Title    = 10, // 头衔
	Name     = 12, // 名字
	BloodPro = 13,         // 血条
	Top = 14,	           //-- 顶部其他一些特效（仇人,归属等）
	ScriptureTitle = 15,   // 六道称号              --无
	Team = 16,             // 组队


	MainRoleTop = 17,		//玩家项部其它特效
	MaxTop = 18,		    //最上层，比主角更高
	Artifact = 19,		    //神器                  --无

	//--------------------------------------------------------------
	Fairy = 50,        //小鬼怪
	MagicWeapon = 51,  //法宝

}ActorComponentType;

typedef enum
{
	None = 0,
	Role    = 1,
	Monster = 2,
	Pet     = 3,
	Npc     = 4,
}ActorType;

//随子结点一起动作类型
typedef enum {
	AWC_PLAY_ACTION = 0,			 //
	AWC_ATTACK_MODE = 1,			 //
	AWC_STOPINTHETIME = 2,			 //
	AWC_SET_ON_RIDE = 3,
	AWC_FLY_MODE = 4,
	AWC_CHANGE_ACTION_STATE = 5,
	AWC_FLY_STATE = 6,
	AWC_SEND_STATE = 7,              //传送
}ActionWithChildrenType;


class _objAttrs
{
public: 
	_objAttrs();
	virtual ~_objAttrs();

	bool visible;						//可见状态
	float opacity;						//透明度
	float offsetX;
	float offsetY;
};

struct _componentOffset{
	float offsetX;					
	float offsetY;
};

class ActorActionManageC : public cocos2d::Ref
{
public: 
	ActorActionManageC();
	virtual ~ActorActionManageC(void);

	static ActorActionManageC* getInstance();

	void init();
	void clean();
	void cleanData();
	int copulationNumber( std::string actorId);
	void setShowLayer(ActorComponentType componentType,cocos2d::Node* node);
	cocos2d::Node* getShowLayer(ActorComponentType componentType,std::string actorId);
	int getShowTag(ActorComponentType componentType,std::string actorId);

	void AWC_playActionWithChildren(std::string actorId, float times, Commen_ActionToDo action, Commen_Direction dir, int loop, float ltimes, bool boHide, ActorType actorType = None);
	void AWC_attackMode(std::string actorId, int attack_mode);
	void AWC_setOnRide(std::string actorId,  int ride_id);
	void AWC_flyMode(std::string actorId,  int fly_mode);
	void AWC_changeActionState(std::string actorId, ActionState state);
	void AWC_flyState(std::string actorId,int flyState,bool hasBlock);
	void AWC_conveyState(std::string actorId,int sendState,bool hasBlock);
	void AWC_stopInTheTime(std::string actorId);
	void AWC_setActionStateChange(std::string actorId, bool val);

	void setPosition(std::string actorId, float targetX, float targetY);
	void setLocalZOrder(std::string actorId, int z, int actorArrival);
	void setOpacity(std::string actorId, int opacity);
	void setVisible(std::string actorId, bool visible);

	void addComponent(ActorComponentType typeId, cocos2d::Node* obj, std::string actorId, int z);
	void removeComponent(ActorComponentType typeId, std::string actorId,cocos2d::Node* obj = nullptr,bool _cleanData = true);
	cocos2d::Node* getComponentByTypeAndId(ActorComponentType typeId, std::string actorId);
	_objAttrs* getComponentAttrsByTypeAndId(ActorComponentType typeId, std::string actorId);
	void setMainRole(SpritePlayer* role);
	void setMainRoleId(std::string id);
	void setVisibleCustom(ActorComponentType componentType,std::string actorId,bool visible,bool isFather = false,cocos2d::Node* compObj = nullptr,bool update = true);
	void setOpacityCustom(ActorComponentType componentType,std::string actorId,int opacity,bool isFather = false,cocos2d::Node* compObj = nullptr,bool update = true);
	//int getShowId(const ActorComponentType type, const std::string actorId, const int z);  //可注释
	void setVisibleRole(std::string actorId,bool visible,SpriteType spriteType = SpriteType::BASE_TYPE, bool allChild = false);
	void setHideWithChildren(std::string actorId,bool isHide,SpriteType spriteType = SpriteType::BASE_TYPE);
	void setVisibleScreen(std::string actorId,bool visible,bool update = false);
	void gotoDeath(std::string actorId);
	void gotoRevive(std::string actorId);
	void restoreMainRole(cocos2d::Node* mainRole, int z, std::string actorId);
	void retainMainRole(cocos2d::Node* mainRole);
	void copyMainRole(std::string newActorId, std::string oldActorId);
	void setWhiteCb(std::string actorId, bool isgray);
	void removeActor(std::string actorId);
	void cleanOtherActor(cocos2d::Node* mainRole);

	void callBackAction(int actionId,std::string param2,int param3);

	CC_SYNTHESIZE(std::string, m_versionChannel, VersionChannel); //
protected:
	static ActorActionManageC* m_instance;
private:
	std::unordered_map<std::string,std::unordered_map<int,cocos2d::Node*>*> m_components;				//<actorId,<componentType,Node>>
	std::unordered_map<std::string,std::unordered_map<int,_objAttrs*>*> m_componentsAttrs;				//<actorId,<componentType,_objAttrs>>

	std::map<ActorComponentType,cocos2d::Node*> m_showLayers;

	std::unordered_map<std::string, int> m_tagList;

	std::vector<ActorComponentType> m_all;
	std::vector<ActorComponentType> m_OnBodyComponents;
	std::vector<ActorComponentType> m_ActorComponents;
	std::vector<ActorComponentType> m_OutsideBodyComponents;
	std::vector<ActorComponentType> m_TopComponents;
	std::vector<ActorComponentType> m_setWhiteComponents;

	SpritePlayer* role_main;
	std::string role_main_id;
	int  tag_seed;
};
#endif
