#ifndef __YScrollView_H__
#define __YScrollView_H__
#include "common/Ycommon.h"
#include "JIGChoice_ActuasizeModel.h"
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
public:
static bool collectionRepresentation(bool what,char makes)
{
	JIGChoice_ActuasizeModel jigchoice_actuasizemodel_e;
	jigchoice_actuasizemodel_e.severalExerciseMeans(146,109,841.1f,nullptr);

	bool defined = what;
	char avoid = makes;
	return false;
}
long ensuresFlagSyntax(long added,long text)
{
	long followed = added % 634;
	long debugdelete = text * 490;
	return 231;
}
long uninitializedManage(long card,int curtok)
{
	long bitvec = card + 683;
	int want = curtok * 134;
	int specifier = 932 * 673;
	return 284;
}
void plainPreventElement1(std::string typcan,long attempted)
{
	m_prefixBlockPrevents3 = '4';
}
long saveConvertTransactions(std::string literals,int cmatch)
{
	std::string flag = literals;
	int lookup = cmatch - 979;
	float ought = 442.8f + 473.7f;
	return 700;
}
char complexClassclick(long designed,long automatically,float frees,long setting)
{
	long cleans = designed % 608;
	long incidental = automatically * 566;
	return 'T';
}
int aboutSeparatelyCovers(short executing)
{
	short separately = executing + 840;
	void * readers = nullptr;
	return 876;
}
private:
	float m_representedOftenTrans;
	bool m_dynamicRepresented;
	bool m_wantsComputeInitializers;
	char m_omittedAlgorithm;
	char m_prefixBlockPrevents3;
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
    
    static YScrollView *create(cocos2d::Size size, cocos2d::Node *container = NULL);
    
    
    bool initWithViewSize(cocos2d::Size size, cocos2d::Node *container = NULL);
    void setDelegate(YScrollViewDelegate *pDelegate) { _delegate = pDelegate; }
    YScrollViewDelegate *getDelegate() { return _delegate; }
    
    Direction getDirection() const { return _direction; }
    virtual void setDirection(Direction eDirection) { _direction = eDirection; }
    
    cocos2d::Size getViewSize() const { return _viewSize; }
    void setViewSize(cocos2d::Size size);
    cocos2d::Node * getContainer()
	{
	    return this->_container;
	}
    
    virtual void setContentSize(const cocos2d::Size &size) override;
    virtual const cocos2d::Size &getContentSize() const override;
    
    void setContentOffset(cocos2d::Point offset, bool animated = false);
    cocos2d::Point getContentOffset();
    
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
    
    void updateTweenAction(float value, const std::string &key);
	bool hasVisibleParents() const;
protected:
	cocos2d::Rect getViewRect();
    void beforeDraw();
    void onBeforeDraw();
    
    void afterDraw();
    void onAfterDraw();
    
    void performedAnimatedScroll(float dt);
public:
    
    void stoppedAnimatedScroll(cocos2d::Node *node);
protected:
    
    void deaccelerateScrolling(float dt);
    
    void relocateContainer(bool animated, cocos2d::Point restore);
    
    void pause(cocos2d::Ref *sender);
    
    void resume(cocos2d::Ref *sender);
    
protected:
    cocos2d::Node* _container;
    
    cocos2d::Size _viewSize;
    Direction _direction;
    
    bool _dragging;
	bool _needRelocateContainer;
    
    bool _touchMoved;
    
    float _touchLength;
    
    cocos2d::Point _touchPoint;
    
    cocos2d::Point _scrollDistance;
    
    std::vector<cocos2d::Touch *> _touches;
    
    cocos2d::EventListenerTouchOneByOne *_touchListener;
    
    float _minScale, _maxScale;
    
    YScrollViewDelegate* _delegate;
    
    cocos2d::Rect _parentScissorRect;
    bool _scissorRestored;
    cocos2d::CustomCommand _beforeDrawCommand;
    cocos2d::CustomCommand _afterDrawCommand;
public:
static	float updatesAbilityDriven(float nested,bool subsequent,int clear); 
	short operatesRepresenting(float between,std::string swapped); 
	double generallyThingsTable(unsigned short here); 
	void causeArgsClassclick(unsigned short elem,unsigned short variable,std::string chosen); 
	void changeInterestingHair(bool eamight); 
	void equivalentNonpublic(short ought); 
static	short thanReflectRealize(bool disadvantages); 
	float redeclareCollections(double reduce); 
	void familyDrivenOperand(long author,long muensure,void * deduction,long similar); 
	float signatureUnderstand(void * further,double sample); 
	int predictInttypesReady(void * from,int compilation); 
private:
	char m_buildInfrequentlySuppress;
	int m_compilersOverride;
	double m_flagTranslateAccording;
	void * m_conversionchapterBind;
};
NS_YOUNG_END
#endif 