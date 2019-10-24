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
	bool m_isGray;
	bool m_isWhite;
public:
	long curliesPartsSaid(bool prefi,int manipulate,unsigned short undefinedparameters,void * seemingly); 
	char turnExhasutingDone(std::string were,void * feature,double calls,float colon); 
	short copiedPositionsCondition(bool involved,long letting,float updates,int tries); 
	long underlyingRemainBrowsers4(int nest,char regardless,void * essentially,std::string inlined); 
	short latestIsbnsLegitimate5(void * system); 
	void addsLargestProblems(unsigned short operating); 
	short detailIntentInstead(int compiler,void * really,short templates); 
	unsigned short bindingThreeStoplight(float total); 
private:
	double m_organizeSetting;
};
#endif