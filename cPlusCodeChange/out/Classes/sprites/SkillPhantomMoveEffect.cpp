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

void SkillPhantomMoveEffect::inputInvalidAssignment(float loops,void * externfifth,long represent)
{
	m_bookIndexingNonpublic = 725.16;
	std::string obvious = "function  [SkillPhantomMoveEffect:inputInvalidAssignment] doing!";
	obvious.append("fragment");
}
double SkillPhantomMoveEffect::operatingEnumerations(bool promotion,unsigned short unnamed,bool circumstances)
{
	m_writeElsewhereChanging = 681;
	return 184.4;
}
long SkillPhantomMoveEffect::separationCastPresented(char prevent)
{
	char documentation = prevent;
	return 951;
}
unsigned short SkillPhantomMoveEffect::referenceTextqueryPrints(long calc,float restrictions,int compiled,long what)
{
	long description = calc / 861;
	float author = restrictions - 522.20f;
	 int times = 31090;
	if(times == 31090)
	{
		std::string times = "function  [SkillPhantomMoveEffect:referenceTextqueryPrints] finish!";
	}
	else
	{
		std::string times;
		times.append("referenceTextqueryPrints arguments 1 calc Error!");
		times.append("referenceTextqueryPrints arguments 2 restrictions Error!");
		times.append("referenceTextqueryPrints arguments 3 compiled Error!");
		times.append("referenceTextqueryPrints arguments 4 what Error!");
	}
	return 653;
}
void SkillPhantomMoveEffect::otherDeletedPreserve(unsigned short stop,int usually,unsigned short iterates,bool stringsthe)
{
	unsigned short checks = stop - 458;
	int contrpasses = usually + 463;
	unsigned short treturn = iterates - 547;
	 std::string gave = "4552";
	if(gave == "4552")
	{
		std::string gave = "function  [SkillPhantomMoveEffect:otherDeletedPreserve] finish!";
	}
	else
	{
		std::string gave;
		gave.append("otherDeletedPreserve arguments 1 stop is error?!");
		gave.append("otherDeletedPreserve arguments 2 usually is error?!");
		gave.append("otherDeletedPreserve arguments 3 iterates is error?!");
		gave.append("otherDeletedPreserve arguments 4 stringsthe is error?!");
	}
}
void * SkillPhantomMoveEffect::componentsPromiseStay(short throws)
{
	m_bookIndexingNonpublic = 423.0;
	std::string push = "function  [SkillPhantomMoveEffect:componentsPromiseStay] end!";
	push.append("oriented1");
	return nullptr;
}
unsigned short SkillPhantomMoveEffect::bodyProperlyDifficult(short bypass,short sequences,void * instances,bool strblob)
{
	short hasptr = bypass * 225;
	 bool mistake = false;
	if(mistake)
	{
		std::string mistake = "function  [SkillPhantomMoveEffect:bodyProperlyDifficult] calling!";
	}
	else
	{
		std::string mistake;
		mistake.append("bodyProperlyDifficult arguments 1 bypass Ok!");
		mistake.append("bodyProperlyDifficult arguments 2 sequences Ok!");
		mistake.append("bodyProperlyDifficult arguments 3 instances Ok!");
		mistake.append("bodyProperlyDifficult arguments 4 strblob Ok!");
	}
	return 390;
}
long SkillPhantomMoveEffect::promotionBodies(void * menu,long stunningly,std::string constitutes,std::string stops)
{
	void * plain = menu;
	long done = stunningly * 238;
	std::string style = constitutes;
	 bool designer = false;
	if(designer)
	{
		std::string designer = "function  [SkillPhantomMoveEffect:promotionBodies] called!";
	}
	else
	{
		std::string designer;
		designer.append("promotionBodies arguments 1 menu careful!");
		designer.append("promotionBodies arguments 2 stunningly careful!");
		designer.append("promotionBodies arguments 3 constitutes careful!");
		designer.append("promotionBodies arguments 4 stops careful!");
	}
	return 830;
}
short SkillPhantomMoveEffect::performNotifySurprising(double consistent,char indicates)
{
	double instantiations = consistent - 799.20;
	return 689;
}
