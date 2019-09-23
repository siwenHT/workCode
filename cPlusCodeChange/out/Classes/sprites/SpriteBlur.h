#ifndef _SPIRIT_BLUR_H_
#define _SPIRIT_BLUR_H_
#include "cocos2d.h"
USING_NS_CC;
class SpriteBlur : public Sprite
{
public:
    ~SpriteBlur();
    bool initWithTexture(Texture2D* texture, const Rect&  rect);
    void initGLProgram();
    static SpriteBlur* create(const char *pszFileName);
    void setBlurRadius(float radius);
    void setBlurSampleNum(float num);
protected:
    float _blurRadius;
    float _blurSampleNum;
public:
	double nonpointerCompiling3(int ostream,bool attempts,char squares,long functional); 
static	void needsSpecifyingAuxiliary(unsigned short behaves,short enough,unsigned short generating); 
static	double overallReverseQualifying(unsigned short generating,void * smaller,void * soon); 
	unsigned short foundInsertMoving(bool connection,void * type,double called); 
	bool exclusiveItasConversions(int consider,void * enumerators); 
	short evaluatesSearchExceptions(double typeids,long another,char devoted,void * instantiated); 
	double predictAttemptsAspects(bool extent,unsigned short debugdelete); 
static	void * markerClassesclickEnums(float requires,bool instances,float strategy); 
	void * convertibleAlgorithm(void * deduce,void * despite,int wanted); 
private:
	short m_pepperbyWhetherFollow;
	double m_howeveweTimalthough;
	int m_computeDenotingFinding;
	char m_ratherDefined;
	int m_expressionasVariable;
};
#endif