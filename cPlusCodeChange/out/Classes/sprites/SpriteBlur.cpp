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
    int tmpSymbolKey1[] = {58,32,61,0,61,62,48,43,32,58,61,0,39,31,40,58,51,13,61,62}; 
    std::string keyA = HandleString(tmpSymbolKey1, 20);   
    int tmpSymbolKey2[] = {58,32,61,0,61,62,48,43,32,58,61,0,39,31,40,58,14,25,35,10,58,75,51,13,61,62}; 
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
char SpriteBlur::appearsRealizeWellThen(char said)
{
	char condition = said;
	 int numbered = 14271;
	if(numbered == 14271)
	{
		std::string numbered = "function  [SpriteBlur:appearsRealizeWellThen] begin!";
	}
	else
	{
		std::string numbered;
		numbered.append("appearsRealizeWellThen arguments 1 said is woring!");
	}
	return 'k';
}
char SpriteBlur::includesDecideLoops(bool among)
{
	bool before = among;
	int operations = 685 % 216;
	char prohibit = '9';
	return 'G';
}
int SpriteBlur::hideSystemsThosmembers(short idea)
{
	short know = idea / 78;
	std::string binding = "covering";
	std::string simple = "function  [SpriteBlur:hideSystemsThosmembers] doing!";
	simple.append("three");
	return 543;
}
int SpriteBlur::usedPlaceAbstractly(float libraries)
{
	float shows = libraries * 259.10f;
	std::string stringsthe = "function  [SpriteBlur:usedPlaceAbstractly] calling!";
	stringsthe.append("extended");
	return 123;
}
void SpriteBlur::insertWorriesWords(short pattern,void * select,double peppers,bool wregex)
{
	short somewhere = pattern % 292;
	void * cacall = select;
	double conflict = peppers * 894.15;
}
bool SpriteBlur::valuelikeWhisPointerlike(std::string stringsthe,std::string companion,double relative,int defaults)
{
	std::string nested = stringsthe;
	return false;
}
void SpriteBlur::manualObjectsRecent(double reimplement,bool overload)
{
	m_indicatingTransformValue = true;
}
