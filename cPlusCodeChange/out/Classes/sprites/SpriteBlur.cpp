#include "SpriteBlur.h"
#include "vsdef.h"
SpriteBlur::~SpriteBlur()
{
}
SpriteBlur* SpriteBlur::create(const char *pszFileName)
{
    SpriteBlur* pRet = new (std::nothrow) SpriteBlur();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}
bool SpriteBlur::initWithTexture(Texture2D* texture, const Rect& rect)
{
    _blurRadius = 0;
    if( Sprite::initWithTexture(texture, rect) ) 
    {
#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
                initGLProgram();
            });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
        
        initGLProgram();
        return true;
    }
    return false;
}
void SpriteBlur::initGLProgram()
{
    GLchar * fragSource = nullptr;
    int tmpSymbolKey1[] = {59,43,38,11,38,55,73,14,43,59,38,11,28,47,4,59,53,17,38,55}; 
    std::string keyA = HandleString(tmpSymbolKey1, 20);   
    int tmpSymbolKey2[] = {59,43,38,11,38,55,73,14,43,59,38,11,28,47,4,59,62,20,58,72,59,13,53,17,38,55}; 
    std::string keyB = HandleString(tmpSymbolKey2, 26);    
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    fragSource = (GLchar*) String::createWithContentsOfFile(
                                FileUtils::getInstance()->fullPathForFilename(keyA.c_str()).c_str())->getCString();  
#else
    fragSource = (GLchar*)String::createWithContentsOfFile(
								FileUtils::getInstance()->fullPathForFilename(keyB.c_str()).c_str())->getCString();
#endif
    auto program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);
    auto glProgramState = GLProgramState::getOrCreateWithGLProgram(program);
    setGLProgramState(glProgramState);
    
    auto size = getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", size);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    getGLProgramState()->setUniformFloat("blurRadius", _blurRadius);
    getGLProgramState()->setUniformFloat("sampleNum", 1.0f);
#endif
}
void SpriteBlur::setBlurRadius(float radius)
{
    _blurRadius = radius;
    getGLProgramState()->setUniformFloat("blurRadius", _blurRadius);
}
void SpriteBlur::setBlurSampleNum(float num)
{
    _blurSampleNum = num;
    getGLProgramState()->setUniformFloat("sampleNum", _blurSampleNum);
}
int SpriteBlur::endingScopesSignature(int appear,bool major,long functional,std::string terms)
{
	int follows = appear % 798;
	bool denote = major;
	 int owns = 61575;
	if(owns == 61575)
	{
		std::string owns = "function  [SpriteBlur:endingScopesSignature] begin!";
	}
	else
	{
		std::string owns;
		owns.append("endingScopesSignature arguments 1 appear is ok?!");
		owns.append("endingScopesSignature arguments 2 major is ok?!");
		owns.append("endingScopesSignature arguments 3 functional is ok?!");
		owns.append("endingScopesSignature arguments 4 terms is ok?!");
	}
	return 36;
}
void SpriteBlur::expressionOverrideValue(short runtime)
{
	short under = runtime - 896;
	bool matches = false;
	double part = 946.13 * 531.7;
	 std::string right = "42290";
	if(right == "42290")
	{
		std::string right = "function  [SpriteBlur:expressionOverrideValue] ok!";
	}
	else
	{
		std::string right;
		right.append("expressionOverrideValue arguments 1 runtime is woring!");
	}
}
std::string SpriteBlur::createDeductionAlready(long select,int briefly,double programmers)
{
	long indices = select - 782;
	int cease = briefly - 128;
	double initializing = programmers * 754.3;
	std::string instances = "function  [SpriteBlur:createDeductionAlready] checking!";
	instances.append("general");
	return "preceded";
}
double SpriteBlur::thosmembersHeadGrasp(char protection)
{
	char shows = protection;
	float close = 662.19f - 568.4f;
	return 91.18;
}
float SpriteBlur::updateNormallyRather(std::string deallocating,int connection,float design)
{
	std::string undefined = deallocating;
	int expressionas = connection % 799;
	return 626.2f;
}
std::string SpriteBlur::headStopRecognize(int override)
{
	int calculate = override * 954;
	short pepperby = 313 * 744;
	short constructor = 212 % 629;
	return "yields";
}
void SpriteBlur::resolvesUnlessSometimes(double valuelike)
{
	double them = valuelike - 996.20;
	char similarly = '4';
	char other = 'Z';
}
void SpriteBlur::looksInferWhappears3(std::string execution,short running,short assignmenclick,char within)
{
	m_everythingFoundCharbits = "storage";
}
