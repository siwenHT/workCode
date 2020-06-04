
#ifndef _ACTOR_RENDER_QUEUE_MANAGER_H_
#define _ACTOR_RENDER_QUEUE_MANAGER_H_
#include "cocos2d.h"
#include "SpriteBase.h"
typedef enum {
	SPRITE_BASE = 0,
	EFFECT_BASE = 0,
}ActorRenderType;
class _objRender
{
public: 
	_objRender(std::function<void(void)> _callback,ActorRenderType _typeId);
	virtual ~_objRender();
	std::function<void(void)> callback;
	ActorRenderType typeId;
public:
	void * ideasLiteralsFull(double predicted,int tedious,std::string asking); 
	void * everything(std::string thoutermost); 
	bool reallocatesKnow(char sold); 
	long oargumentsSurelyBest(bool minimal,bool elsewhere); 
static	void * foundCollideManaged(long prior,float converts); 
	void * mainPairsStylePattern(int funtion,long flows); 
	std::string vectorTargetPrefer(char limited,int want); 
	void * gradesListitemThere(void * older); 
private:
	bool m_accumulateOperandsEnclose;
	short m_acrossSiteThoutermost;
	short m_implicitDefinitionsListed;
	void * m_representingLonger;
	int m_westoreDestroying;
};
class ActorRenderQueueManage : public cocos2d::Ref
{
public: 
	ActorRenderQueueManage();
	virtual ~ActorRenderQueueManage(void);
	static ActorRenderQueueManage* getInstance();
	void update(float dt);
	int getEntryId();
	int addRenderListCallBack(const std::function<void(void)>& callback,ActorRenderType typeId);
	void removeRenderCallBack(int entryId);
	SpriteBase* createBaseWithCache(std::string key);
protected:
	static ActorRenderQueueManage* m_instance;
private:
	std::map<int,_objRender*> m_renderList;
	int _entrySeed;
	std::map<std::string,std::vector<SpriteBase*>*> m_base_cache;
public:
	double facilitiesAboutDeveloped(long blob,short figure); 
	void * programmingAheadDesigns(long adding,long serious,int returning,short errormsg); 
static	double brownStopReferring(char protection); 
	void ellipsisParentheses(long variable,int referenparameter); 
	char classesEvaluatesNonnested(void * surprising,unsigned short stunningly,void * highest,short based); 
	bool argsFlagsTogether(float strcmp,float student,std::string convert); 
	void natureRecordReal(double viable,float related); 
	short redeclareDetailContaiany(double attempts,int about,void * disadvantages); 
	float expectationsIteratorBook(unsigned short scoping,void * separation,long involved); 
	double describingOperatorclick(std::string open,int reject); 
private:
	float m_actualIntroduceOkay;
	long m_questionOtherExpectHiding;
};
#endif
