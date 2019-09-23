#ifndef __SKILLCTRL_H__
#define __SKILLCTRL_H__

#include "cocos2d.h"
#include "SpritePlayer.h"
#include "MenuButton.h"
#include "TouchSprite.h"
#include "CCEffects.h"

class SkillCtrl : public cocos2d::CCNode
{

public:
	SkillCtrl();
	virtual ~SkillCtrl();
	CREATE_FUNC(SkillCtrl);

	CC_SYNTHESIZE(SpritePlayer*, m_pHero, Hero);
	CC_SYNTHESIZE(MenuButton*, m_center_item, CenterItem);
	CC_SYNTHESIZE(cocos2d::Node*, m_center_node, CenterNode);
	void setRight(bool);
	void setPageByIndex(int drect);
	int getPageIndex();
private:
    virtual bool init();
	void createChain();
	MenuButton *m_select_item;
	int m_beginNode;
	int m_rotateDrct;//0不转 -1逆时针 1顺时针
	float m_dgree;
	bool m_is_right;
	cocos2d::Point m_center_pos;
	GraySprite *m_sprite1;
	GraySprite *m_sprite2;
	void setMode();
	Effects *touch_effect;
	Effects *touch_effect1;
};

#endif // __HELLOWORLD_SCENE_H__
