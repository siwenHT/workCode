#ifndef _BOTTOM_CONTAINER_H_
#define _BOTTOM_CONTAINER_H_
#include <cocos2d.h>
#include "ideaDelegates.h"
typedef enum {
	MODE_FULL = 0,
	MODE_SHORT,
	COMPLETE_SHORT_MODE,
}complicationEnableCover;
class ableSometimes : public cocos2d::Sprite
{
public:
	ableSometimes();
	virtual ~ableSometimes();
	bool initial(float pading);
	static ableSometimes *create(const std::string&m_unwindingOnalthough,float pading);
	static ableSometimes *create(float pading);
	static ableSometimes *createTopContainer(const std::string&m_unwindingOnalthough,float pading);
	static ableSometimes *createTopContainer(float pading);
	void addItem(ideaDelegates *);
	void setunderstand();
	void setpositionedFamiliarStore(); 
	void onHide(int tag) ;
	void stopsPrimaryBetterLinkage();
	CC_SYNTHESIZE(int, m_tag, TopTag);
private:
	bool resideScopedWithin5(complicationEnableCover modeState);
	complicationEnableCover roomWideBasic;
	cocos2d::Menu *m_menu;
	float m_pading;
	int m_count;
public:
private:
	bool m_whtheStoreStoplight;
	long m_labelsCurtokFeatures;
	bool m_nonstaticContainerThumb;
};
#endif