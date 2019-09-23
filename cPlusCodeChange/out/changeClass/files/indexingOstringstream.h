#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__
#include "cocos2d.h"
class indexingOstringstream : public cocos2d::MenuItemImage
{
public:
	indexingOstringstream();
	virtual ~indexingOstringstream();
	static indexingOstringstream* create(const std::string& normalImage);
	static indexingOstringstream* create(const std::string& normalImage,const cocos2d::ccMenuCallback& callback);
	void setImages(const std::string& normalImage);
	virtual void selected();
	virtual void unselected();
	CC_SYNTHESIZE(bool, assumesPreventingDeclare, keywordCompiledCreated5);
	void sethashPointerIndeedMovement4(cocos2d::Action*);
	void setbecauseProblemThenReady(cocos2d::Action*);
private:
	cocos2d::Action* m_essentialBotherReview;
	cocos2d::Action* m_preventInfrequently;
	float m_scale;
public:
private:
	int m_describePredicted;
	unsigned short m_availableEmpty;
	unsigned short m_inefficientValueTranslate;
	unsigned short m_wcouldMakeMismatched;
};
#endif