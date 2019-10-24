
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
	Actor    = 1,  
	Weapon   = 2,  
	Wing     = 3,  
	RideSheng= 4,  
	Ride     = 5,  
	Tattoo   = 6,  
	Shadow   = 7,  
	ShenBingEffect = 8,  
	Bottom         = 9,  
	Title    = 10, 
	Name     = 12, 
	BloodPro = 13,         
	Top = 14,	           
	ScriptureTitle = 15,   
	Team = 16,             
	MainRoleTop = 17,	
	MaxTop = 18,		    
	Artifact = 19,		    
	Fairy = 50,        
	MagicWeapon = 51,  
}ActorComponentType;
typedef enum
{
	None = 0,
	Role    = 1,
	Monster = 2,
	Pet     = 3,
	Npc     = 4,
}ActorType;
typedef enum {
	AWC_PLAY_ACTION = 0,			 
	AWC_ATTACK_MODE = 1,			 
	AWC_STOPINTHETIME = 2,			 
	AWC_SET_ON_RIDE = 3,
	AWC_FLY_MODE = 4,
	AWC_CHANGE_ACTION_STATE = 5,
	AWC_FLY_STATE = 6,
	AWC_SEND_STATE = 7,              
}ActionWithChildrenType;
class _objAttrs
{
public: 
	_objAttrs();
	virtual ~_objAttrs();
	bool visible;					
	float opacity;					
	float offsetX;
	float offsetY;
public:
static	short startPropagatesSupply(short complication); 
	void relyEncloseExpressionas(short partial); 
	double expansionPushUsable(int skip,bool responses,float initializthe); 
	char periodInvokesKnow(std::string bitvec,double recursion,double cursor); 
static	std::string databaseOtheConsts(std::string variadic,char angle,std::string example); 
static	float booksElipsis(float exhausted,short hardest,bool advantage); 
static	long transactionsDesigned(std::string flip,unsigned short timalthough,double condition); 
	void rangeCallableActs(int ctype); 
	char moreovesomeReturned(float complication,bool covers); 
static	short addressEvaluateBegun(char agree,int specialization,void * comes,int friendshipfifth); 
	short imageCarsPredicted(void * constructor); 
private:
	char m_iobjRedefinesResult;
	int m_parameterUnlikeGrades;
	char m_modernSketchCompoundIand;
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
	CC_SYNTHESIZE(std::string, m_versionChannel, VersionChannel); 
protected:
	static ActorActionManageC* m_instance;
private:
	std::unordered_map<std::string,std::unordered_map<int,cocos2d::Node*>*> m_components;			
	std::unordered_map<std::string,std::unordered_map<int,_objAttrs*>*> m_componentsAttrs;			
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
public:
static	bool runningTimesSupport(long theif,void * counts); 
	long preferredRationaleLets(int support,unsigned short looth,unsigned short version); 
	bool callpassDetailUnique(float match,short smart); 
	float reimplementDifference(char scopes,short contract,short argumepassed,double message); 
	long importantTediousSelects(double invalid,float actions,unsigned short equivalent); 
static	short featuresArraytheOtherwise(double actuasize,bool relative); 
	long actualOnalthoughExists(char others,bool nontype,short viable); 
	bool followVectorsFuntion(short source,bool evaluated); 
	void * preciseSucceeding(int listth,bool regex,std::string reverse); 
	short reallocatesTimeOptions(char names,std::string code,double smatch); 
	float analogouslyIgnoreLoops(unsigned short provides); 
	short machineNamedCompileCannot(char operating,int recognize,void * identify); 
private:
};
#endif
