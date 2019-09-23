#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__
#include "cocos2d.h"
class ideaDelegates : public cocos2d::MenuItemImage
{
public:
	ideaDelegates();
	virtual ~ideaDelegates();
	static ideaDelegates* create(const std::string& normalImage);
	static ideaDelegates* create(const std::string& normalImage,const cocos2d::ccMenuCallback& callback);
	void setImages(const std::string& normalImage);
	virtual void selected();
	virtual void unselected();
	CC_SYNTHESIZE(bool, m_objectsEntireThexercises, passedDeclaringPurposes);
	void setcodeFullyException(cocos2d::Action*);
	void setassumeManageLittle(cocos2d::Action*);
private:
	cocos2d::Action* m_convertingFrontSection;
	cocos2d::Action* termsExpects;
	float m_scale;
public:
private:
	int m_eliminatedCareRepeatedly;
	int m_pushedSimplifyEllipsis;
	unsigned short m_nullMutuallyKnownLiteral;
};
#endif