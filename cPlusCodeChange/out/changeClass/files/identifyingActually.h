#ifndef _BOTTOM_CONTAINER_H_
#define _BOTTOM_CONTAINER_H_
#include <cocos2d.h>
#include "indexingOstringstream.h"
typedef enum {
	MODE_FULL = 0,
	MODE_SHORT,
	COMPLETE_SHORT_MODE,
}loopStoredModel;
class identifyingActually : public cocos2d::Sprite
{
public:
	identifyingActually();
	virtual ~identifyingActually();
	bool initial(float pading);
	static identifyingActually *create(const std::string&m_ableCover,float pading);
	static identifyingActually *create(float pading);
	static identifyingActually *createTopContainer(const std::string&m_ableCover,float pading);
	static identifyingActually *createTopContainer(float pading);
	void addItem(indexingOstringstream *);
	void setuniqueCoutPositioned();
	void setdetailsReferLetting(); 
	void onHide(int tag) ;
	void performanceGuideCalls();
	CC_SYNTHESIZE(int, m_tag, TopTag);
private:
	bool startsModelTypeinfoHeld(loopStoredModel modeState);
	loopStoredModel m_despiteApplicationsLonger;
	cocos2d::Menu *m_menu;
	float m_pading;
	int m_count;
public:
private:
	double m_compoundCheckStrblob;
	long m_currentlyHoweveweEnding;
	short m_fonumberBeforeCount;
	float m_employeeIntroduceRules;
	char m_ensureOtherwisePrograms;
};
#endif