#include "SkillPhantomMoveEffect.h"

//#include "GameLogic/Sync/SyncTime.h"

static const int MoveTime = 500;

SkillPhantomMoveEffect::SkillPhantomMoveEffect()
{
}

SkillPhantomMoveEffect::~SkillPhantomMoveEffect()
{
}

SkillPhantomMoveEffect* SkillPhantomMoveEffect::create(SpriteFrame* frame)
{
	SkillPhantomMoveEffect *pRet = new SkillPhantomMoveEffect();
	if (pRet && pRet->init(frame))
	{ 
		pRet->autorelease(); 

		return pRet; 
	} 
	else 
	{ 
		delete pRet; 
		pRet = nullptr; 
	}

	return nullptr; 
}
bool SkillPhantomMoveEffect::init(SpriteFrame* frame)
{
	if ( !Sprite::initWithSpriteFrame(frame) )
	{
		return false;
	}
	this->setAnchorPoint(Vec2(0.5, 0.5));
	this->setOpacity(180);
	m_isFinished = false;

	auto fadeOut = FadeTo::create(0.5,0);
	CallFunc* funcall= CCCallFunc::create(this, callfunc_selector(SkillPhantomMoveEffect::endMove));
	FiniteTimeAction * seq = CCSequence::create(fadeOut, funcall, NULL);
	runAction(seq);


	//setColor(Color3B(0, 0, 0));
	return true;
}

void SkillPhantomMoveEffect::endMove()
{
	m_isFinished = true;
	removeFromParent();
}

