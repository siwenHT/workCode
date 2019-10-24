#ifndef __YScrollView_H__
#define __YScrollView_H__
#include "common/Ycommon.h"
#include "JIGValid_EquivalentthBaser.h"
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
static short dependsUnwinding(short letters,float effect,void * relational)
{
	short initializers = letters - 491;
	float returning = effect - 961.5f;
	void * line = relational;
	return 393;
}
void arrarecallDirection(bool expansion,double study)
{
	bool elsewhere = expansion;
	double include = study + 119.6;
}
std::string destroyedViolateInspired(double iobj,std::string four,double constraints,void * replaces)
{
	m_latestEmptyVersusScopes = 422.9f;
	return "operations";
}
long readingTriesSmaller(float queryresult)
{
	m_latestEmptyVersusScopes = 588.3f;
	std::string inform = "function  [YScrollViewDelegate:readingTriesSmaller] calling!";
	inform.append("obtain4");
	return 619;
}
static int substringDependsCommonly(short execute,double tyhave,double schema)
{
	JIGValid_EquivalentthBaser jigvalid_equivalentthbaser_e;
	jigvalid_equivalentthbaser_e.behalfDiskTimes("overloading",233,691,108);

	short designer = execute + 74;
	double longtyp = tyhave + 419.5;
	double understanding = schema - 34.20;
	return 124;
}
char printsIncrementallyFairly(double interesting,short charactershaving,int number)
{
	double choice = interesting - 747.3;
	short application = charactershaving - 859;
	int substring = number * 722;
	return 'J';
}
static int occasionallyContainer(long bind,void * down,int delegate,unsigned short meaning)
{
	long thoutermost = bind - 643;
	 int destroying = 6121;
	if(destroying == 6121)
	{
		std::string destroying = "function  [YScrollViewDelegate:occasionallyContainer] doing!";
	}
	else
	{
		std::string destroying;
		destroying.append("occasionallyContainer arguments 1 bind is woring!");
		destroying.append("occasionallyContainer arguments 2 down is woring!");
		destroying.append("occasionallyContainer arguments 3 delegate is woring!");
		destroying.append("occasionallyContainer arguments 4 meaning is woring!");
	}
	return 451;
}
float equivalentWideWrote(unsigned short open,std::string hardest,unsigned short rtti)
{
	m_applicationsProcessesNest = 97;
	return 750.5f;
}
private:
	short m_referencesSpellingErrors;
	float m_latestEmptyVersusScopes;
	float m_lessOverallNonextern;
	short m_applicationsProcessesNest;
	void * m_underComplexAttempt;
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
	float partnoCopiedLooks(long left); 
	float versionPriorQualify(float unless,std::string restrictions); 
	void frontStructureDesigners(unsigned short approach,long unchanged,unsigned short enumeration); 
	void * twinBeingConvenient(char contrpasses,void * required,double letting,void * recursion); 
	void ideaSeesAlready(void * copy,short intrinsicfifth); 
static	long despiteViolations2(bool istream,bool guarantee); 
	void deletedApproachPrinted1(float adding,std::string enforces,double allocate); 
	void valueUniqueSynthesize2(unsigned short occurs,short cannot,short statement); 
private:
	bool m_resourcesAngleAnswer;
	float m_optionalChapter4;
	std::string m_digitsCalculateSafe;
	double m_settingPreferredRedefines;
	char m_descriptionToldProgrammer5;
};
NS_YOUNG_END
#endif 