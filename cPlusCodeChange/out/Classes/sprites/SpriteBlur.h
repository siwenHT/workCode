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
	char appearsRealizeWellThen(char said); 
static	char includesDecideLoops(bool among); 
static	int hideSystemsThosmembers(short idea); 
	int usedPlaceAbstractly(float libraries); 
	void insertWorriesWords(short pattern,void * select,double peppers,bool wregex); 
	bool valuelikeWhisPointerlike(std::string stringsthe,std::string companion,double relative,int defaults); 
	void manualObjectsRecent(double reimplement,bool overload); 
private:
	void * m_inheritInterchangeably;
	double m_endingExtendedMemberwise;
	unsigned short m_pointerfifthIstream;
	bool m_indicatingTransformValue;
};
#endif