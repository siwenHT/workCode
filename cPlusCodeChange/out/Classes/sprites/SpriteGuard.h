#ifndef _SPIRIT_GUARD_
#define _SPIRIT_GUARD_
#include "SpriteBase.h"
typedef enum{
	beginAutoAction = 1,     
	resertAction = 2,        
	autoAction = 3,          
}TagType;
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
	bool    m_isAutoMove;         
	float   m_autoTime;           
	cocos2d::Vec2 m_moverPoint;   
	float   m_stepTime;           
	float   m_farLength;          
	float   m_restTime;           
};
#endif
