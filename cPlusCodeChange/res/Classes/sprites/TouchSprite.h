#ifndef _SPIRIT_TOUCH_H_
#define _SPIRIT_TOUCH_H_

#include "GraySprite.h"

class TouchSprite : public GraySprite
{
public: 
	TouchSprite();
	virtual ~TouchSprite(void);
	static TouchSprite* create();
	static TouchSprite* create(const std::string&pszFileName,bool enable=false);
	virtual bool initTouch();
	bool isTouchInside(cocos2d::Touch* touch);
	void registerTouchDownHandler(int handler);
	void registerTouchUpHandler(int handler);
	void setTouchEnable(bool enable = true);
	void setSelectAction(cocos2d::Action*);
	void setUnSelectAction(cocos2d::Action*);
	void setEnable(bool enable = true);
	void setSwallowTouch(bool swallow = true);
	//state 1表示点击正常  0表示失败
	void onClick(int state = 1);
	void onTouchDown();

	CC_SYNTHESIZE(int, m_touchType, TouchType);
private:
	int m_scriptSelectedHandler;
	int m_scriptUnselectedHandler;
	cocos2d::Action* m_select_action;
	cocos2d::Action* m_unselect_action;
	bool m_touch_enable;
	cocos2d::Vec2 m_beginPoint;
	bool m_isClick;
	bool m_swallowTouch;
};
#endif