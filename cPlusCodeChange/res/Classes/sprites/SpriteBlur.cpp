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
    int tmpSymbolKey1[] = {}; //"res/shaders/Blur.fsh"
    std::string keyA = HandleString(tmpSymbolKey1, STRNUMSIG);   

    int tmpSymbolKey2[] = {}; //"res/shaders/Blur_winrt.fsh"
    std::string keyB = HandleString(tmpSymbolKey2, STRNUMSIG);    
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