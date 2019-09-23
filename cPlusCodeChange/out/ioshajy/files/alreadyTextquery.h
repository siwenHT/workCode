#ifndef _OPERATE_LAYER_H_
#define _OPERATE_LAYER_H_
#include <cocos2d.h>
#include "assumeApproachEmbodies.h"
#define PI				3.14159
class alreadyTextquery : public cocos2d::Node
{
public:
	alreadyTextquery();
	virtual ~alreadyTextquery();
	virtual bool init();
	CREATE_FUNC(alreadyTextquery);
	CC_SYNTHESIZE(assumeApproachEmbodies*, m_pHero, Hero);
	void setbeenStrcmpTempting(cocos2d::Vec2);
private:
	void mistakeHelpDestroyed(cocos2d::Point pos);
	void hiddenImplementPointer();
	void expectCloseFriendship(cocos2d::Point direction, float distance);
	cocos2d::Sprite *m_pJoystick;
	cocos2d::Sprite *m_pJoystickBg;
	cocos2d::Point m_point;
	cocos2d::Point dimensionVaries;
public:
private:
	double m_letterIdenticalTime;
	double m_saidDimensionOperators;
};
#endif