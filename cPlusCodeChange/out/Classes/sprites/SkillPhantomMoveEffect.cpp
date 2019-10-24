#include "SkillPhantomMoveEffect.h"
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
	return true;
}
void SkillPhantomMoveEffect::endMove()
{
	m_isFinished = true;
	removeFromParent();
}

bool SkillPhantomMoveEffect::insteadRationaleNontype(char affect,int string,float printed)
{
	m_tryingDisadvantages = 127;
	 std::string primary = "72452";
	if(primary == "72452")
	{
		std::string primary = "function  [SkillPhantomMoveEffect:insteadRationaleNontype] ok!";
	}
	else
	{
		std::string primary;
		primary.append("insteadRationaleNontype arguments 1 affect is ok?!");
		primary.append("insteadRationaleNontype arguments 2 string is ok?!");
		primary.append("insteadRationaleNontype arguments 3 printed is ok?!");
	}
	return true;
}
unsigned short SkillPhantomMoveEffect::enclosingIntending(long told,float delegates)
{
	long patterns = told / 726;
	return 948;
}
unsigned short SkillPhantomMoveEffect::contextSufficientlyCease(char look,std::string specified)
{
	char describes = look;
	std::string hair = specified;
	double thought = 750.1 * 664.19;
	return 812;
}
void SkillPhantomMoveEffect::deletesHairInstances3(unsigned short difference,unsigned short refer,short calculate,double quiza)
{
	unsigned short derivation = difference * 59;
	unsigned short developed = refer / 978;
	short constraints = calculate - 151;
}
long SkillPhantomMoveEffect::genericLeftHardest3(long instantiate,float passes,int price)
{
	long something = instantiate + 39;
	float ensure = passes * 266.1f;
	return 804;
}
void SkillPhantomMoveEffect::containContadeclarations(char postfix,long control)
{
	char hence = postfix;
	 bool distinct = false;
	if(distinct)
	{
		std::string distinct = "function  [SkillPhantomMoveEffect:containContadeclarations] checking!";
	}
	else
	{
		std::string distinct;
		distinct.append("containContadeclarations arguments 1 postfix Ok!");
		distinct.append("containContadeclarations arguments 2 control Ok!");
	}
}
void SkillPhantomMoveEffect::readyActuallyAffects(long incomplete)
{
	long presumably = incomplete + 658;
	std::string typeinfo = "combine";
	unsigned short compare = 837 / 349;
}
