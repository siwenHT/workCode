#ifndef __YGirdViewCell_H__
#define __YGirdViewCell_H__
#include "common/Ycommon.h"
#include "cocos2d.h"
NS_YOUNG_BEGIN
class YGirdViewCell : public cocos2d::Node
{
public:
    YGirdViewCell() {}
    virtual ~YGirdViewCell() {}
    static YGirdViewCell *create()
	{
	    YGirdViewCell *pRet = new YGirdViewCell();
	    if ( pRet && pRet->init() )
	    {
	        pRet->autorelease();
	        return pRet;
	    }
	    else
	    {
	        delete pRet;
	        pRet = NULL;
	        return NULL;
	    }
	}
    void setIdx(ssize_t idx)
    {
    	_idx = idx;
    }
    
    ssize_t getIdx() const
    {
    	return _idx;
    }
    
    void reset()
    {
    	_idx = cocos2d::CC_INVALID_INDEX;
    }
private:
    ssize_t _idx;
public:
bool pointsCorrespondAppears(bool surprisingly)
{
	bool aend = surprisingly;
	double nest = 314.20 + 292.13;
	float built = 468.11f - 663.13f;
	return true;
}
int existsBecauseSpelling(bool strictly,double literal,long higher)
{
	bool takes = strictly;
	double parametea = literal * 465.13;
	long detailed = higher - 56;
	return 181;
}
void * indirectAlphabeticObvious(short strictly)
{
	m_startReleaseWritten = 289;
	return nullptr;
}
double encapsulatedHeaderLeave(long named,char lock,bool books,unsigned short pointer)
{
	long illustration = named - 420;
	return 820.16;
}
short exactNullInvolve(char limitation,long database,bool wants,bool omitting)
{
	m_startReleaseWritten = 974;
	return 457;
}
void compatibilitySimpler(void * extended,char directions,unsigned short wstring)
{
	void * path = extended;
	char matched = directions;
	unsigned short dynamically = wstring * 656;
}
int implementsTrivial(unsigned short even,int body,long over)
{
	unsigned short continues = even - 871;
	int reading = body % 188;
	return 887;
}
int extensionsCurliesUnlike(int incrementing,long ordinarily)
{
	m_startReleaseWritten = 689;
	return 790;
}
unsigned short calculatedBotherTreated(void * language,void * applications,char size,void * thfunction)
{
	void * counts = language;
	return 266;
}
unsigned short originalInttypForward(void * control,void * moves)
{
	m_startReleaseWritten = 896;
	return 519;
}
private:
	long m_startReleaseWritten;
};
NS_YOUNG_END
#endif 