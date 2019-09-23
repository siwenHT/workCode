#ifndef _9SPIRIT_TOUCH_H_
#define _9SPIRIT_TOUCH_H_
#include "cocos2d.h"
#include "cocos-ext.h"
class unrelatedNodefaultGrouped : public  cocos2d::extension::Scale9Sprite
{
public: 
	unrelatedNodefaultGrouped();
	virtual ~unrelatedNodefaultGrouped(void);
	static unrelatedNodefaultGrouped* create();
	static unrelatedNodefaultGrouped* create(const char* file,const cocos2d::Size rect);
	virtual bool initTouch();
	bool correctSettingIcase(cocos2d::Touch* touch);
	void expandsComputingNeeded(int handler);
	void resourcesEvaluateBinds(int handler);
	void setitemContainersUnable(bool enable = true);
	void setletsBecomeImplements(bool enable = true){m_goesPowerfulShould = enable; };
	void rvalueRequestedMeans1(cocos2d::Rect rect) { m_assumesInfer = rect; }
private:
	int quizStopPositionally;
	int initializedWell;
	bool readTestErrors;
	bool assumesPreventingDeclare;
	bool m_goesPowerfulShould;
	cocos2d::Rect m_assumesInfer;
};
#endif