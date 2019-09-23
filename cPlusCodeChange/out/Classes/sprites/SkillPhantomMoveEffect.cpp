#include "SkillPhantomMoveEffect.h"
#include "dynamicallyHiding.h"
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

double SkillPhantomMoveEffect::translateMutuallyCapital(char previously,bool executing,float behalf,short before)
{
	dynamicallyHiding dynamicallyhiding_e;
	dynamicallyhiding_e.emplaceNeedingVariaband('S');

	char treat = previously;
	return 835.10;
}
int SkillPhantomMoveEffect::splitDefinesEnumerations(float understand,int inlined)
{
	float looking = understand + 806.18f;
	return 546;
}
void * SkillPhantomMoveEffect::protectionSchema(void * difficult,int elem,short alias,short sometimes)
{
	m_selectExecutesHides = 'O';
	return nullptr;
}
void * SkillPhantomMoveEffect::shareDirectlyObjec(double error,unsigned short along,char match,short benefit)
{
	double defaults = error + 1000.2;
	unsigned short model = along * 74;
	return nullptr;
}
void SkillPhantomMoveEffect::bothEncountersConverted(double managing,char possible,float have,float explain)
{
	double succeeding = managing + 11.1;
	char lvalue = possible;
}
float SkillPhantomMoveEffect::hardestDifferenbetween1(double common,long typeids,long defined,short library)
{
	m_neededNewlineInttypes = 24.20f;
	return 636.15f;
}
double SkillPhantomMoveEffect::tuplesSufficientlyNotify(bool elipsis,long processes)
{
	bool appears = elipsis;
	long comparing = processes + 903;
	float essential = 589.4f * 602.20f;
	return 269.13;
}
short SkillPhantomMoveEffect::stunninglyLiterals(void * neither,void * zero,char words)
{
	void * point = neither;
	return 69;
}
bool SkillPhantomMoveEffect::featureSwapNearly(int benefit,int alphanumeric,void * argument)
{
	int responses = benefit * 458;
	return false;
}
