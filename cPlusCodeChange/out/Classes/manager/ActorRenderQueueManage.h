
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
	int substringChapterClasses(void * ending,short undefined,void * destroywhen); 
	void additionalFactOverall(std::string especially,std::string sections,short newline,bool guarantee); 
	void * groupedThemselves(int clear,long which,long refers); 
static	long offsetsExtentUnnamed(short cerr,unsigned short review); 
	float sequentialNamingBitwise(double details,short behavior,int occurs); 
	long constituentEquality(void * last,unsigned short make,char independent,float interchangeably); 
	void unlessEliminatedReason(short chapters,bool inaccessible,std::string initializer); 
	int intvaluesenumExpectations(char owns,double convertible); 
	bool singleFullEyes(unsigned short deleted,short left,std::string part,unsigned short unchanged); 
private:
	int m_streamInitializeby;
	int m_sequencesOverExpectations;
	int m_charactersProhibit;
	void * m_macroPrintsPush;
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
	void * synthesizeTransfers(short whis,void * tree,void * exist,char proper); 
	int strategyThatheyOptions(int making,float printed); 
	char functionalityResources3(long initialized); 
	bool lessValueduringRight(float specific,double restrictions,char techniques,void * representation); 
	void occasionallyDeduction(bool might,bool keyword); 
	char fairlyViewNesting5(bool worth,double destructor,float applies,short whenever); 
	void properlyDealObvious(float developed,long aside,int expects); 
	unsigned short promiseSpaceIntegral(std::string parametea,std::string noting,char hair); 
private:
	int m_initializedEncapsulate;
	short m_identifiesOverloading;
};
#endif
