#include "imagethChanges.h"
#include "imagethCerr.h"
imagethChanges::~imagethChanges()
{
}
imagethChanges* imagethChanges::create(const char *m_ableCover)
{
    imagethChanges* pRet = new (std::nothrow) imagethChanges();
    if (pRet && pRet->initWithFile(m_ableCover))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}
bool imagethChanges::initWithTexture(Texture2D* texture, const Rect& rect)
{
    m_pointedRepeat = 0;
    if( Sprite::initWithTexture(texture, rect) ) 
    {
#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
                bitsetheKnowPointsunlike();
            });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
        
        bitsetheKnowPointsunlike();
        return true;
    }
    return false;
}
void imagethChanges::bitsetheKnowPointsunlike()
{
    GLchar * fragSource = nullptr;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    fragSource = (GLchar*) String::createWithContentsOfFile(
                                FileUtils::getInstance()->fullPathForFilename("res/shaders/Blur.fsh").c_str())->getCString();  
#else
    fragSource = (GLchar*)String::createWithContentsOfFile(
								FileUtils::getInstance()->fullPathForFilename("res/shaders/Blur_winrt.fsh").c_str())->getCString();
#endif
    auto program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);
    auto glProgramState = GLProgramState::getOrCreateWithGLProgram(program);
    setGLProgramState(glProgramState);
    
    auto size = getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", size);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    getGLProgramState()->setUniformFloat("blurRadius", m_pointedRepeat);
    getGLProgramState()->setUniformFloat("sampleNum", 1.0f);
#endif
}
void imagethChanges::setentryGeneratingParts(float radius)
{
    m_pointedRepeat = radius;
    getGLProgramState()->setUniformFloat("blurRadius", m_pointedRepeat);
}
void imagethChanges::setbrownWstringNodefault(float num)
{
    m_beginsReadyMatrix = num;
    getGLProgramState()->setUniformFloat("sampleNum", m_beginsReadyMatrix);
}
double imagethChanges::nonpointerCompiling3(int ostream,bool attempts,char squares,long functional)
{
	int pointerwhen = ostream + 35;
	return 160.14;
}
void imagethChanges::needsSpecifyingAuxiliary(unsigned short behaves,short enough,unsigned short generating)
{
	unsigned short represents = behaves * 189;
	short into = enough / 261;
	unsigned short runs = generating % 469;
}
double imagethChanges::overallReverseQualifying(unsigned short generating,void * smaller,void * soon)
{
	unsigned short defined = generating - 952;
	void * argumepassed = smaller;
	return 126.6;
}
unsigned short imagethChanges::foundInsertMoving(bool connection,void * type,double called)
{
	bool valueduring = connection;
	void * withfifth = type;
	return 149;
}
bool imagethChanges::exclusiveItasConversions(int consider,void * enumerators)
{
	int specializing = consider * 448;
	void * according = enumerators;
	bool withfifth = true;
	return true;
}
short imagethChanges::evaluatesSearchExceptions(double typeids,long another,char devoted,void * instantiated)
{
	double special = typeids - 727.9;
	return 182;
}
double imagethChanges::predictAttemptsAspects(bool extent,unsigned short debugdelete)
{
	bool impact = extent;
	unsigned short designed = debugdelete % 452;
	short determined = 771 / 385;
	return 367.16;
}
void * imagethChanges::markerClassesclickEnums(float requires,bool instances,float strategy)
{
	float datsuch = requires - 468.13f;
	bool ostream = instances;
	float similarly = strategy + 873.6f;
	return nullptr;
}
void * imagethChanges::convertibleAlgorithm(void * deduce,void * despite,int wanted)
{
	imagethCerr imagethcerr_e;
	imagethcerr_e.decrementsIsbns1(314,nullptr,214,678);

	m_computeDenotingFinding = 240;
	return nullptr;
}
