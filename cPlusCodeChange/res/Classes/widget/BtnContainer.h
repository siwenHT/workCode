#ifndef _BOTTOM_CONTAINER_H_
#define _BOTTOM_CONTAINER_H_

#include <cocos2d.h>
#include "widget/MenuButton.h"

typedef enum {
	MODE_FULL = 0,
	MODE_SHORT,
	COMPLETE_SHORT_MODE,
}ModeState;

class BtnContainer : public cocos2d::Sprite
{
public:
	BtnContainer();
	virtual ~BtnContainer();

	bool initial(float pading);

	static BtnContainer *create(const std::string&pszFileName,float pading);
	static BtnContainer *create(float pading);

	static BtnContainer *createTopContainer(const std::string&pszFileName,float pading);
	static BtnContainer *createTopContainer(float pading);

	void addItem(MenuButton *);

	void setFullMode();
	void setShortMode(); 
	void onHide(int tag) ;

	void changeFullShortMode();

	CC_SYNTHESIZE(int, m_tag, TopTag);
private:
	bool changeMode(ModeState modeState);

	ModeState m_currMode;
	cocos2d::Menu *m_menu;
	float m_pading;
	int m_count;
};

#endif