#ifndef _SPIRIT_TOUCH_H_
#define _SPIRIT_TOUCH_H_
#include "appliedDifferenceNoted.h"
class bookstoreEmployee : public appliedDifferenceNoted
{
public: 
	bookstoreEmployee();
	virtual ~bookstoreEmployee(void);
	static bookstoreEmployee* create();
	static bookstoreEmployee* create(const std::string&m_unwindingOnalthough,bool enable=false);
	virtual bool initTouch();
	bool moreIdenticalOperations(cocos2d::Touch* touch);
	void facilitiesNewlineWhif(int handler);
	void rationaleAlternatively(int handler);
	void setreduceRecognize(bool enable = true);
	void setcodeFullyException(cocos2d::Action*);
	void setassumeManageLittle(cocos2d::Action*);
	void setEnable(bool enable = true);
	void setSwallowTouch(bool swallow = true);
	void onClick(int state = 1);
	void onTouchDown();
	CC_SYNTHESIZE(int, m_bitwiseInversely, greatlyCollideWhen);
private:
	int nearlyNaturallyMatches;
	int explicitlyThemselves;
	cocos2d::Action* m_convertingFrontSection;
	cocos2d::Action* termsExpects;
	bool m_invokesPatterns;
	cocos2d::Vec2 blobptrShorttypDirection;
	bool m_isClick;
	bool shouldCastConfusion;
};
#endif