#ifndef _SPIRIT_GRAY_H_
#define _SPIRIT_GRAY_H_
#include "cocos2d.h"
#define USER_NEW_PLAY_ACTION 1
class GraySprite : public cocos2d::Sprite
{
public: 
	GraySprite();
	virtual ~GraySprite(void);
	static GraySprite* create();
	static GraySprite* create(const std::string&pszFileName);
	void addColorGray();
	void removeColorGray();
	void setColorGray(bool);
	void setColorWrite(bool);
	bool m_isGray;
	bool m_isWhite;
public:
	float protectionVectorsReally5(float real,double ignored); 
	void * freeInteresting(bool emplace,double redeclare); 
	double seesManipulateOfferEach(long inadvertently); 
	int ostringstreamPrevent(unsigned short would,bool finding); 
	unsigned short conventionsSwappedPush(void * faced,void * initializes); 
	float unrelatedCountsPromotes(unsigned short isbn,float person,float terms,int knowledge); 
	void reversesContentsMutually(void * jumping,short technique,double propagates,short enumeration); 
	int seeminglyInvalid(short specializes,unsigned short open); 
	void connectionBecomesTogether(float code,double framework,double certain,float convention); 
	double purposeFailsUnderstand(int coverage,float cout); 
	short againInitializes(float destructor); 
private:
	int m_reasonsCopiesConceptually;
	float m_preventSaysOught;
};
#endif