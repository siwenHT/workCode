#ifndef _SPIRIT_GRAY_H_
#define _SPIRIT_GRAY_H_

#include "cocos2d.h"
#define USER_NEW_PLAY_ACTION 1

class GraySprite : public cocos2d::Sprite
{
public: 
	GraySprite();
	virtual ~GraySprite(void);
	static GraySprite* create();
	static GraySprite* create(const std::string&pszFileName);
	void addColorGray();
	void removeColorGray();
	void setColorGray(bool);
	void setColorWrite(bool);
	//virtual void setSpriteFrame(cocos2d::SpriteFrame* newFrame);


	bool m_isGray;
	bool m_isWhite;
	//bool isShowLog;
};
#endif