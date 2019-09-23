#include "GraySprite.h"
//#include "CustomShaders.h"
//#include "CustomShaderNames.h"

USING_NS_CC;

GraySprite::GraySprite()
{
	m_isGray = false;
	m_isWhite = false;
	//isShowLog = false;
}
GraySprite::~GraySprite(void)
{
}


GraySprite *GraySprite::create(const std::string&pszFileName)
{
    GraySprite *pRet = new GraySprite();
	
	//先去cache里面去找有没有对应的精灵帧 ，没有按照正常的方式生成精灵
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pszFileName);
	
	if(frame!=nullptr){
		bool bret = pRet->initWithSpriteFrameName(pszFileName);
		if(bret){
			pRet->autorelease();
			return pRet;
		}
	}

//	pRet->createWithSpriteFrameName();

    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        //CC_SAFE_DELETE(pRet);
        //return NULL;
		CCLOG("!!!!!!!!!!!!!!!!create GraySprite failure, filename %s",pszFileName.c_str());
		pRet->initWithFile("res/empty_frame.png");
		return pRet;
    }
}

GraySprite *GraySprite::create()
{
    GraySprite *pRet = new GraySprite();
    if (pRet&& pRet->init()) 
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

void GraySprite::addColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
}

void GraySprite::removeColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
}

void GraySprite::setColorGray(bool isgray)
{
	if(m_isGray == isgray)
		return;
	m_isGray = isgray;
	if(isgray)
		addColorGray();
	else
		removeColorGray();
}

void GraySprite::setColorWrite(bool isgray)
{
	return;
	/*
	if(m_isWhite == isgray)
		return;
	m_isWhite = isgray;
	if(isgray){
		GLProgram * p = ShaderCache::getInstance()->getGLProgram(CUSTOM_SHADER_NAME_POSITION_TEXTURECOLOR_WHITE);
		if(p == nullptr){
			p = new GLProgram();
			p->initWithByteArrays(ccPositionTextureColor_noMVP_vert, customShader_positionTextureColor_white);
			p->link();
			p->updateUniforms();

			ShaderCache::getInstance()->addGLProgram(p,CUSTOM_SHADER_NAME_POSITION_TEXTURECOLOR_WHITE);
		}
		setGLProgram(p);
		//setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
	}
	else
		removeColorGray();
	*/
}


//void GraySprite::setSpriteFrame(SpriteFrame *spriteFrame)
//{
//	cocos2d::Sprite::setSpriteFrame(spriteFrame);
//	if (isShowLog)
//	{
//		CCLOG("isChange setSpriteFrame called!!1 %s", spriteFrame->getTextureFilename().c_str());
//	}
//}