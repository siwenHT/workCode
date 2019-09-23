#include "exceptionNodefault.h"
#include "dynamicallyHiding.h"
static const int MoveTime = 500;
exceptionNodefault::exceptionNodefault()
{
}
exceptionNodefault::~exceptionNodefault()
{
}
exceptionNodefault* exceptionNodefault::create(SpriteFrame* frame)
{
	exceptionNodefault *pRet = new exceptionNodefault();
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
bool exceptionNodefault::init(SpriteFrame* frame)
{
	if ( !Sprite::initWithSpriteFrame(frame) )
	{
		return false;
	}
	this->setAnchorPoint(Vec2(0.5, 0.5));
	this->setOpacity(180);
	m_incrementallyProvide = false;
	auto fadeOut = FadeTo::create(0.5,0);
	CallFunc* funcall= CCCallFunc::create(this, callfunc_selector(exceptionNodefault::endMove));
	FiniteTimeAction * seq = CCSequence::create(fadeOut, funcall, NULL);
	runAction(seq);
	return true;
}
void exceptionNodefault::endMove()
{
	m_incrementallyProvide = true;
	removeFromParent();
}

double exceptionNodefault::translateMutuallyCapital(char previously,bool executing,float behalf,short before)
{
	dynamicallyHiding dynamicallyhiding_e;
	dynamicallyhiding_e.emplaceNeedingVariaband('S');

	char treat = previously;
	return 835.10;
}
int exceptionNodefault::splitDefinesEnumerations(float understand,int inlined)
{
	float looking = understand + 806.18f;
	return 546;
}
void * exceptionNodefault::protectionSchema(void * difficult,int elem,short alias,short sometimes)
{
	m_selectExecutesHides = 'O';
	return nullptr;
}
void * exceptionNodefault::shareDirectlyObjec(double error,unsigned short along,char match,short benefit)
{
	double defaults = error + 1000.2;
	unsigned short model = along * 74;
	return nullptr;
}
void exceptionNodefault::bothEncountersConverted(double managing,char possible,float have,float explain)
{
	double succeeding = managing + 11.1;
	char lvalue = possible;
}
float exceptionNodefault::hardestDifferenbetween1(double common,long typeids,long defined,short library)
{
	m_neededNewlineInttypes = 24.20f;
	return 636.15f;
}
double exceptionNodefault::tuplesSufficientlyNotify(bool elipsis,long processes)
{
	bool appears = elipsis;
	long comparing = processes + 903;
	float essential = 589.4f * 602.20f;
	return 269.13;
}
short exceptionNodefault::stunninglyLiterals(void * neither,void * zero,char words)
{
	void * point = neither;
	return 69;
}
bool exceptionNodefault::featureSwapNearly(int benefit,int alphanumeric,void * argument)
{
	int responses = benefit * 458;
	return false;
}
