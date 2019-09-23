#ifndef __YScrollView_H__
#define __YScrollView_H__

#include "common/Ycommon.h"
#include "cocos2d.h"

NS_YOUNG_BEGIN

class YScrollView;

class YScrollViewDelegate
{
public:
    
    virtual ~YScrollViewDelegate() {}
    
    virtual void scrollViewDidScroll(YScrollView *view) = 0;
    
    virtual void scrollViewDidZoom(YScrollView *view) = 0;
	
	virtual void scrollViewDidStopped(YScrollView *view) = 0;
};

class YScrollView : public cocos2d::Layer, public cocos2d::ActionTweenDelegate
{
public:
    enum class Direction
    {
        NONE = -1,
        HORIZONTAL = 0,
        VERTICAL,
        BOTH
    };

    YScrollView();
    
    virtual ~YScrollView();

    /**
     * Returns an autoreleased scroll view object.
     *
     * @param size view size
     * @param container parent object
     * @return autoreleased scroll view object
     */
    static YScrollView *create(cocos2d::Size size, cocos2d::Node *container = NULL);

    
    /**
     * Returns a scroll view object
     *
     * @param size view size
     * @param container parent object
     * @return scroll view object
     */
    bool initWithViewSize(cocos2d::Size size, cocos2d::Node *container = NULL);


    void setDelegate(YScrollViewDelegate *pDelegate) { _delegate = pDelegate; }
    YScrollViewDelegate *getDelegate() { return _delegate; }

    /**
     * direction allowed to scroll. ScrollViewDirectionBoth by default.
     */
    Direction getDirection() const { return _direction; }
    virtual void setDirection(Direction eDirection) { _direction = eDirection; }

    /**
     * size to clip. Node boundingBox uses contentSize directly.
     * It's semantically different what it actually means to common scroll views.
     * Hence, this scroll view will use a separate size property.
     */
    cocos2d::Size getViewSize() const { return _viewSize; }
    void setViewSize(cocos2d::Size size);

    cocos2d::Node * getContainer()
	{
	    return this->_container;
	}

    // Overrides
    virtual void setContentSize(const cocos2d::Size &size) override;
    virtual const cocos2d::Size &getContentSize() const override;

    /**
     * Sets a new content offset.
     *
     * @param offset    The new offset.
     * @param animated  If true, the view will scroll to the new offset.
     */
    void setContentOffset(cocos2d::Point offset, bool animated = false);
    cocos2d::Point getContentOffset();

    /**
     * Sets a new content offset.
     * You can override the animation duration with this method.
     *
     * @param offset    The new offset.
     * @param dt        The animation duration.
     */
    void setContentOffsetInDuration(cocos2d::Point offset, float dt);


    void setTouchEnabled(bool enabled);
    bool isTouchEnabled() const;

    bool isDragging() const { return _dragging; }
    bool isTouchMoved() const { return _touchMoved; }

    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);

    using cocos2d::Node::addChild;
    virtual void addChild(cocos2d::Node *child, int zOrder, int tag) override;
	virtual void addChild(cocos2d::Node *child, int zOrder) override;
	virtual void addChild(cocos2d::Node *child) override;


    virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)override;
    /*
     * CCActionTweenDelegate
     */
    void updateTweenAction(float value, const std::string &key);

	bool hasVisibleParents() const;

protected:

	cocos2d::Rect getViewRect();

	/**
     * clip this view so that outside of the visible bounds can be hidden.
     */
    void beforeDraw();
    void onBeforeDraw();
    /**
     * retract what's done in beforeDraw so that there's no side effect to
     * other nodes.
     */
    void afterDraw();
    void onAfterDraw();

    /**
     * This method makes sure auto scrolling causes delegate to invoke its method
     */
    void performedAnimatedScroll(float dt);
public:
    /**
     * Expire animated scroll delegate calls
     */
    void stoppedAnimatedScroll(cocos2d::Node *node);


protected:
    /**
     * implements auto-scrolling behavior. change SCROLL_DEACCEL_RATE as needed to choose
     * deacceleration speed. it must be less than 1.0f.
     *
     * @param dt delta
     */
    void deaccelerateScrolling(float dt);

    /**
     * Relocates the container at the proper offset, in bounds of max/min offsets.
     *
     * @param animated If true, relocation is animated
     */
    void relocateContainer(bool animated, cocos2d::Point restore);

    /**
     * Provided to make scroll view compatible with SWLayer's pause method
     */
    void pause(cocos2d::Ref *sender);
    /**
     * Provided to make scroll view compatible with SWLayer's resume method
     */
    void resume(cocos2d::Ref *sender);

    
protected:
	/**
     * Container holds scroll view contents, Sets the scrollable container object of the scroll view
     */
    cocos2d::Node* _container;

    /**
     * size to clip. Node boundingBox uses contentSize directly.
     * It's semantically different what it actually means to common scroll views.
     * Hence, this scroll view will use a separate size property.
     */
    cocos2d::Size _viewSize;

    Direction _direction;

    /**
     * If YES, the view is being dragged.
     */
    bool _dragging;
	
	bool _needRelocateContainer;

    /**
     * Determiens whether user touch is moved after begin phase.
     */
    bool _touchMoved;

    /**
     * length between two fingers
     */
    float _touchLength;

    /**
     * Touch point
     */
    cocos2d::Point _touchPoint;

    /**
     * scroll speed
     */
    cocos2d::Point _scrollDistance;

    /**
     * Touch objects to detect multitouch
     */
    std::vector<cocos2d::Touch *> _touches;

    /** Touch listener */
    cocos2d::EventListenerTouchOneByOne *_touchListener;

    /**
     * max and min scale
     */
    float _minScale, _maxScale;

    /**
     * scroll view delegate
     */
    YScrollViewDelegate* _delegate;

    /**
     * scissor rect for parent, just for restoring GL_SCISSOR_BOX
     */
    cocos2d::Rect _parentScissorRect;
    bool _scissorRestored;

    cocos2d::CustomCommand _beforeDrawCommand;
    cocos2d::CustomCommand _afterDrawCommand;
};

NS_YOUNG_END

#endif // __YScrollView_H__