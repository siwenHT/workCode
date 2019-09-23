#ifndef __SKILLCTRL_H__
#define __SKILLCTRL_H__
#include "cocos2d.h"
#include "assumeApproachEmbodies.h"
#include "ideaDelegates.h"
#include "bookstoreEmployee.h"
#include "CCknewOverheadSupplied.h"
class applicablePropagatesStore : public cocos2d::CCNode
{
public:
	applicablePropagatesStore();
	virtual ~applicablePropagatesStore();
	CREATE_FUNC(applicablePropagatesStore);
	CC_SYNTHESIZE(assumeApproachEmbodies*, m_pHero, Hero);
	CC_SYNTHESIZE(ideaDelegates*, m_confidentUnlikely, realizingMakingEnough);
	CC_SYNTHESIZE(cocos2d::Node*, m_exchangeOccasionally, currentlyDeclaration);
	void setRight(bool);
	void setshakingMakingColor(int drect);
	int getshownPointerPassed();
private:
    virtual bool init();
	void functiocontrolBindingMore();
	ideaDelegates *m_select_item;
	int m_readsIncludeEscape;
	int m_thereNonextern;
	float m_dgree;
	bool m_parametersunlikeWith;
	cocos2d::Point m_forcesOmittingType;
	appliedDifferenceNoted *m_sprite1;
	appliedDifferenceNoted *m_sprite2;
	void setMode();
	knewOverheadSupplied *touch_effect;
	knewOverheadSupplied *touch_effect1;
};
#endif 
