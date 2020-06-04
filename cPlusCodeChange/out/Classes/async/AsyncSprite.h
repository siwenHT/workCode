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
	int readersEqualsImplement(char supported); 
	char numbersLargerLooking(unsigned short rewrite,float articles,double larger); 
	int chaptersDestroysAkin(std::string intending); 
	void * thdefinesThree(void * call,int increments); 
static	void argumentsArgumentsDefine(unsigned short copy,unsigned short hierarchy,float doing); 
	double possiblyDifferUsuallyCode(char techniques); 
	void mistakeExceptionInsert(unsigned short general,void * memory,char content); 
	bool facilitiesActuallyConsts(short complication,unsigned short operates,float wita); 
	bool iobjWhenDeallocating(void * count,std::string sufficiently,long chapter,unsigned short range); 
	int succeedsResultsMeans1(char handle); 
	bool safeRejectPrefer(long right); 
private:
	long m_recentExpectImportant;
	std::string m_instantiateHeightSmatch;
	double m_abstractionArticles;
	short m_grantsRestrictions;
};
#endif
