#ifndef _9SPIRIT_TOUCH_H_
#define _9SPIRIT_TOUCH_H_
#include "cocos2d.h"
#include "cocos-ext.h"
class refersEnums : public  cocos2d::extension::Scale9Sprite
{
public: 
	refersEnums();
	virtual ~refersEnums(void);
	static refersEnums* create();
	static refersEnums* create(const char* file,const cocos2d::Size rect);
	virtual bool initTouch();
	bool moreIdenticalOperations(cocos2d::Touch* touch);
	void facilitiesNewlineWhif(int handler);
	void rationaleAlternatively(int handler);
	void setreduceRecognize(bool enable = true);
	void setdistinguishHidesOught2(bool enable = true){m_differencesDestruction = enable; };
	void copiedIntrinsicfifth(cocos2d::Rect rect) { theseAdaptors = rect; }
private:
	int nearlyNaturallyMatches;
	int explicitlyThemselves;
	bool m_invokesPatterns;
	bool m_objectsEntireThexercises;
	bool m_differencesDestruction;
	cocos2d::Rect theseAdaptors;
};
#endif