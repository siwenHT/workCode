#ifndef _SPIRIT_GUARD_
#define _SPIRIT_GUARD_

#include "SpriteBase.h"

typedef enum{
	beginAutoAction = 1,     //自转开启动作
	resertAction = 2,        //回到原位置动作
	autoAction = 3,          //自转动作
}TagType;


// 守护、法宝（前期准备只用来做守护,后面发现也可以实现法宝的逻辑,就一起了）
class SpriteGuard : public SpriteBase 
{
public: 
	SpriteGuard();
	virtual ~SpriteGuard(void);
	static SpriteGuard* create(const std::string&pszFileName,std::string actorflag);
	void beginAutoAct();
	void autoMoveShow();
	void autoMoveShow_ex();
	void resetSpriteAct();
	virtual void playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);
	void playAction_ex(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);
	void setAutoInfo(cocos2d::Vec2 pos, float autoTime = 8, float stepTime = 3,float restTime = 10, float farL = 100);
	virtual void standed();
	virtual void setPosition(float x, float y);
	virtual void setBasePosition(cocos2d::Point pos);
private:
	bool    m_isAutoMove;         // 是否是自动转动中
	float   m_autoTime;           // 自转开启时间
	cocos2d::Vec2 m_moverPoint;   // 移动范围
	float   m_stepTime;           // 一次移动消耗时间（一次自转分四次移动）
	float   m_farLength;          // 法宝最远跟随距离
	float   m_restTime;           // 法宝重置位置时间
};
#endif//_SPIRIT_GUARD_
