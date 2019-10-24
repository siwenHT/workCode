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
	char stoppinconditionCreated(short derived,float pairs,std::string finds); 
	int contentCompilation(short handling); 
	short muchIndexedCompanion(double numeric); 
	bool positionedContainerWith(bool convenient,long four,int changes,void * things); 
	unsigned short possibleAbsoluteHair(short illegal,float bother); 
	void * guaranteeDeclaration(char item,bool because,int peppers); 
	long typicallyEmployee3(long control,char oriented,long algorithm); 
	unsigned short applyTwinThoseLists3(void * look,long errormsg,char place,long topic); 
	bool limitationReachOkay(double calls); 
	int encapsulationDestroywhen(unsigned short abstractly); 
private:
	long m_flowsThingsOverloading;
	long m_textReferencesthReverse2;
};
#endif
