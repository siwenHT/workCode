#ifndef _ASYNC_SPRITE_H_
#define _ASYNC_SPRITE_H_
#include "cocos2d.h"
typedef enum {
	NORMAL = 0,								
	WAITDOWNLOAD = 1,						
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
public:
	bool stackRelationshipSuppress(float database,short solve,double occur,unsigned short managing); 
	bool arraytheUnnamedRepeatedly(char change,unsigned short aend); 
static	float zeroAvailableIndeed(char introduced,char reading,float compile,int along); 
	long executionAdvantageAssumed4(unsigned short briefly,char position); 
	double fileSelectedHave(void * wstring,float derived); 
private:
	char m_holdsActuallyEnough;
	void * m_persistVariabandCompare;
	int m_fourFormStoreRanked;
	char m_intrinsicfifthSynthesizes;
};
#endif
