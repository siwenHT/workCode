#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__
#include "cocos2d.h"
class MenuButton : public cocos2d::MenuItemImage
{
public:
	MenuButton();
	virtual ~MenuButton();
	static MenuButton* create(const std::string& normalImage);
	static MenuButton* create(const std::string& normalImage,const cocos2d::ccMenuCallback& callback);
	void setImages(const std::string& normalImage);
	virtual void selected();
	virtual void unselected();
	CC_SYNTHESIZE(bool, m_smalltobig, SmallToBigMode);
	void setSelectAction(cocos2d::Action*);
	void setUnSelectAction(cocos2d::Action*);
private:
	cocos2d::Action* m_select_action;
	cocos2d::Action* m_unselect_action;
	float m_scale;
public:
private:
	short m_efficientConverts;
};
#endif