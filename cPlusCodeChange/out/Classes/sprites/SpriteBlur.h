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
	int endingScopesSignature(int appear,bool major,long functional,std::string terms); 
static	void expressionOverrideValue(short runtime); 
static	std::string createDeductionAlready(long select,int briefly,double programmers); 
	double thosmembersHeadGrasp(char protection); 
static	float updateNormallyRather(std::string deallocating,int connection,float design); 
static	std::string headStopRecognize(int override); 
static	void resolvesUnlessSometimes(double valuelike); 
	void looksInferWhappears3(std::string execution,short running,short assignmenclick,char within); 
private:
	std::string m_everythingFoundCharbits;
};
#endif