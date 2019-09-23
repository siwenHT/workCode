#pragma once

#include "cocos2d.h"
USING_NS_CC;

/**
* 幻影移动特效
* @author xiehaibin
*
*/
class SkillPhantomMoveEffect : public Sprite
{
public :
	SkillPhantomMoveEffect();
	~SkillPhantomMoveEffect();
	virtual bool init(SpriteFrame* frame); 
	static SkillPhantomMoveEffect* create(SpriteFrame* frame);

protected :
	void endMove();

	CC_SYNTHESIZE_READONLY(bool, m_isFinished, IsFinished);

};