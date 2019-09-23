#ifndef _ASYNC_SPRITE_H_
#define _ASYNC_SPRITE_H_

#include "cocos2d.h"

typedef enum {
	NORMAL = 0,									//正常
	WAITDOWNLOAD = 1,							//等待下载
}AsyncSpriteState;

class AsyncSprite : public cocos2d::Sprite
{
public: 
	AsyncSprite();
	virtual ~AsyncSprite(void);

	static AsyncSprite* create(const std::string pszFileName,const std::string defaultFileName = "");
	bool initAsync(const std::string filename,const std::string defaultFileName);
	void addCacheSprites();
	void addTextureSprite(cocos2d::Texture2D *a);
private:
	std::string m_pszFileName;
	std::string m_defaultFileName;
	AsyncSpriteState m_state;
	cocos2d::EventListenerCustom* m_customlistener;
};
#endif
