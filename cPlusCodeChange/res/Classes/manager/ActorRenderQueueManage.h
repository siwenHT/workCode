/************************************************************************/
/* 
	角色渲染队列

	一帧会渲染一个（播放一个）
*/
/************************************************************************/
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
};
#endif
