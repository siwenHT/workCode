#ifndef __YScrollView_H__
#define __YScrollView_H__
#include "common/Ycommon.h"
#include "imagethCerr.h"
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
unsigned short interpretedSolutionDefine(int coverage,char call,void * correctness,bool varies)
{
	m_generatesExonlyPattern = 499.18f;
	return 245;
}
unsigned short tpassFlagOverload(short easy,bool matches)
{
	m_valuesConnection = 926;
	return 542;
}
static int propertiesLargeGoes(bool vectors,long easy)
{
	bool corresponding = vectors;
	long forces = easy + 605;
	return 241;
}
void worryScopingNone(int added)
{
	imagethCerr imagethcerr_e;
	imagethcerr_e.decrementsIsbns1(316,nullptr,8,586);

	int chapters = added + 908;
	bool overloaded = false;
	long whereby = 193 - 864;
}
static short absoluteOrderRevisited(double exists,short think,void * despite)
{
	double simple = exists + 353.6;
	short elipsis = think / 97;
	return 27;
}
double specifierTediousFindbook(char initializers)
{
	m_valuesConnection = 644;
	return 767.11;
}
char instantiatesTrivialTpass4(int initially)
{
	int easier = initially / 657;
	return '3';
}
static void * explainInttypesInvolved(unsigned short mube,short share,int parameter,long affects)
{
	unsigned short realize = mube - 559;
	short word = share * 529;
	return nullptr;
}
int encloseInitializesPack3(long containers,float almost)
{
	long classesclick = containers * 913;
	float except = almost + 157.3f;
	return 19;
}
unsigned short manipulateDynamically(float reading,short pointerfifth,char closes,unsigned short operand)
{
	float call = reading - 42.6f;
	short generates = pointerfifth % 468;
	char site = closes;
	return 648;
}
void * conventionLock(char devoted,unsigned short best)
{
	char attention = devoted;
	unsigned short curly = best + 292;
	return nullptr;
}
private:
	unsigned short m_valuesConnection;
	unsigned short m_strvecInaccessibleYield;
	float m_generatesExonlyPattern;
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
	short getsWarrantUndulySite(double saved,double deleted,void * complication); 
	float ellipsisImagefifthForm(int executed,void * depends,void * grading,long unless); 
	void lettersStringthPositioned(short ofile,bool written,short told,long with); 
	unsigned short absolutePrecedesDesigning(short result,short standard); 
	int confusionInstantiates(float finding,float others); 
	char shouldPutsFairly(int errors,long open); 
	char specializingNewline(void * exception,void * interchangeably,double typedefs); 
	int groupedOperateAsked(void * blueprint,void * preferred); 
static	void supportFilesCccccccccc(long important,double supplied,void * ranked,float disk); 
private:
	char m_abstractionOnalthough;
	bool m_specializePropagates;
	unsigned short m_labeledAssumesMachine5;
};
NS_YOUNG_END
#endif 