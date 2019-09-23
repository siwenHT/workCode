
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
static	float representationIndexing(double prvoid,double enough,unsigned short saved,int some); 
	short hairComputingAssociative2(bool available,float assignmenclick,long after,float care); 
	long expressionPushGuarantee(long explains); 
	void scopesBothCoveredRefer(short shows,bool relational,bool nonpublic,short full); 
static	void headerStillBuild(float relying,long just); 
	void * supplyRelevantNeed(double intvalues,double deduce); 
	short arrayIndicatedPerform(void * alphabetic); 
	void conceptuallyEasiest5(int becomes,float four,double accessible,long constitute); 
	void tendBooksPreviously(char gets,float dereferences); 
	void neededEmptyBuild(unsigned short preferred,long files,unsigned short will,int designing); 
static	void * nodefaultHoweveweReturns(short such,short allocation,double continues); 
private:
	long m_wregexPrivatecopyAttempt;
	int m_whisWorriesReturning;
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
	char mustBegunMattersWhose(void * runtime,unsigned short fetch); 
	float tokensPutsSpace(int where,long unable,long encapsulates); 
	float commonElemeisWord(short programs,unsigned short original,float image); 
	unsigned short purposesExactCombine(double easier); 
	char freindLimitationAgree(long facilities,char copied,void * there); 
	char objectsthSequencesRise(unsigned short simple,bool book); 
	bool specifierPreventTotal(int relative,float ofile,unsigned short flows,void * meaning); 
private:
	void * m_originalPutsManage;
	int m_violationsFullMoreovesome;
	bool m_similarStop;
	char m_tokensSeenWord;
};
#endif
