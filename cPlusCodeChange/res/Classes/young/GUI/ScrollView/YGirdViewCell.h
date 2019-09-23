#ifndef __YGirdViewCell_H__
#define __YGirdViewCell_H__

#include "common/Ycommon.h"
#include "cocos2d.h"

NS_YOUNG_BEGIN

/**
 * Abstract class for SWTableView cell node
 */
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

    /**
     * The index used internally by SWTableView and its subclasses
     */
    ssize_t getIdx() const
    {
    	return _idx;
    }

    /**
     * Cleans up any resources linked to this cell and resets <code>idx</code> property.
     */
    void reset()
    {
    	_idx = cocos2d::CC_INVALID_INDEX;
    }

private:
    ssize_t _idx;
};



NS_YOUNG_END


#endif // __YGirdViewCell_H__