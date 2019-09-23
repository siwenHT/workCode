#include "leftBeganAppear.h"
static const int MoveTime = 500;
leftBeganAppear::leftBeganAppear()
{
}
leftBeganAppear::~leftBeganAppear()
{
}
leftBeganAppear* leftBeganAppear::create(SpriteFrame* frame)
{
	leftBeganAppear *pRet = new leftBeganAppear();
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
bool leftBeganAppear::init(SpriteFrame* frame)
{
	if ( !Sprite::initWithSpriteFrame(frame) )
	{
		return false;
	}
	this->setAnchorPoint(Vec2(0.5, 0.5));
	this->setOpacity(180);
	bindRelational = false;
	auto fadeOut = FadeTo::create(0.5,0);
	CallFunc* funcall= CCCallFunc::create(this, callfunc_selector(leftBeganAppear::endMove));
	FiniteTimeAction * seq = CCSequence::create(fadeOut, funcall, NULL);
	runAction(seq);
	return true;
}
void leftBeganAppear::endMove()
{
	bindRelational = true;
	removeFromParent();
}

double leftBeganAppear::comeStringProperties(short functiopresented,double always,char nothing)
{
	long elemeis;
	elemeis = 576;
	long exhasuting;
	exhasuting = 716;
	int muensure;
	muensure = 684;
	short storing;
	storing = 609;
	return 496.11;
}
short leftBeganAppear::writeSignalsPrograms(int section,char analogously,bool brown)
{
	long separately;
	separately = 478;
	short mutually;
	mutually = 736;
	return 837;
}
double leftBeganAppear::lookFixedInitializer(float store,void * strcmp)
{
	short definitions;
	definitions = 980;
	char throughout;
	throughout = '1';
	long skip;
	skip = 587;
	float serious;
	serious = 962.14f;
	return 872.11;
}
double leftBeganAppear::actionsTransfersNeed(void * decrement,void * onbits,long backslash,short current)
{
	double saved;
	saved = 639.2;
	float stunningly;
	stunningly = 254.9f;
	short exclusive;
	exclusive = 610;
	float assigned;
	assigned = 442.11f;
	int means;
	means = 680;
	return 603.12;
}
bool leftBeganAppear::ignoredProblemsContains(unsigned short modern,bool counts,short bookstore)
{
	short denote;
	denote = 943;
	return true;
}
void leftBeganAppear::elementsLeadsBuilds(short card)
{
	bool mimic;
	mimic = false;
	unsigned short distinctive;
	distinctive = 139;
	int realize;
	realize = 421;
	long qualify;
	qualify = 14;
}
int leftBeganAppear::simplyHoweveweUpdate(int starts,short held,double westore)
{
	int integral;
	integral = 706;
	double exactly;
	exactly = 803.20;
	double defined;
	defined = 525.19;
	char space;
	space = 'm';
	long dereferences;
	dereferences = 821;
	return 104;
}
bool leftBeganAppear::resolvedRemainder(char doeth,double series,void * designer)
{
	char prints;
	prints = 'Q';
	short affects;
	affects = 931;
	long lookup;
	lookup = 372;
	int wcannot;
	wcannot = 274;
	bool temporaries;
	temporaries = false;
	return false;
}
void leftBeganAppear::revenuePresenceVersus(double eyes,int fact)
{
	long value;
	value = 547;
	float nontemplate;
	nontemplate = 582.6f;
	short does;
	does = 16;
	float third;
	third = 121.18f;
	long letting;
	letting = 799;
}
void leftBeganAppear::collectionsApplication(char wita,char limited,short curly)
{
	double each;
	each = 347.1;
	double problems;
	problems = 882.0;
	int cannot;
	cannot = 413;
}
