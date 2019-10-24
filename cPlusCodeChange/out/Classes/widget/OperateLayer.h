#ifndef _OPERATE_LAYER_H_
#define _OPERATE_LAYER_H_
#include <cocos2d.h>
#include "SpritePlayer.h"
#define PI				3.14159
class OperateLayer : public cocos2d::Node
{
public:
	OperateLayer();
	virtual ~OperateLayer();
	virtual bool init();
	CREATE_FUNC(OperateLayer);
	CC_SYNTHESIZE(SpritePlayer*, m_pHero, Hero);
	void setCenterPoint(cocos2d::Vec2);
private:
	void showJoystick(cocos2d::Point pos);
	void hideJoystick();
	void updateJoystick(cocos2d::Point direction, float distance);
	cocos2d::Sprite *m_pJoystick;
	cocos2d::Sprite *m_pJoystickBg;
	cocos2d::Point m_point;
	cocos2d::Point m_start_point;
public:
private:
	bool m_facilitiesCompatible;
	long m_unchangedNumberWere;
};
#endif