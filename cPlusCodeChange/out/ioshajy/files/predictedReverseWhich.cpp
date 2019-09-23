#include "predictedReverseWhich.h"
predictedReverseWhich::~predictedReverseWhich()
{
}
predictedReverseWhich* predictedReverseWhich::create(const char *m_unwindingOnalthough)
{
    predictedReverseWhich* pRet = new (std::nothrow) predictedReverseWhich();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}
bool predictedReverseWhich::initWithTexture(Texture2D* texture, const Rect& rect)
{
    m_plainEnumeratorsCare = 0;
    if( Sprite::initWithTexture(texture, rect) ) 
    {
#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
                destructionOwhichDeletes();
            });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
        
        destructionOwhichDeletes();
        return true;
    }
    return false;
}
void predictedReverseWhich::destructionOwhichDeletes()
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
    getGLProgramState()->setUniformFloat("blurRadius", m_plainEnumeratorsCare);
    getGLProgramState()->setUniformFloat("sampleNum", 1.0f);
#endif
}
void predictedReverseWhich::setdesignersIndicateExcept(float radius)
{
    m_plainEnumeratorsCare = radius;
    getGLProgramState()->setUniformFloat("blurRadius", m_plainEnumeratorsCare);
}
void predictedReverseWhich::setliteralSpecifiesIostream(float num)
{
    handledChosen = num;
    getGLProgramState()->setUniformFloat("sampleNum", handledChosen);
}
unsigned short predictedReverseWhich::writingBothUnnamed(short wrote)
{
	bool stunningly;
	stunningly = true;
	unsigned short becomes;
	becomes = 649;
	short generally;
	generally = 238;
	long striparameter;
	striparameter = 992;
	bool iterator;
	iterator = true;
	return 3;
}
void predictedReverseWhich::savedMuchFewer(short stoplight,short language,void * objec)
{
	short bookstore;
	bookstore = 677;
	bool during;
	during = true;
	long interpreted;
	interpreted = 884;
}
char predictedReverseWhich::supplyCompilationOnbits(double correctly,short denote,int properly)
{
	char more;
	more = 'z';
	double strcmp;
	strcmp = 522.10;
	return '7';
}
float predictedReverseWhich::placedOutputIntroductory(void * their)
{
	char destroy;
	destroy = 'T';
	short first;
	first = 206;
	short took;
	took = 510;
	double mean;
	mean = 590.15;
	char author;
	author = '5';
	return 493.13f;
}
long predictedReverseWhich::failsElipsisInfer(float alphabetic,long classes)
{
	long interesting;
	interesting = 949;
	unsigned short copied;
	copied = 375;
	int colon;
	colon = 763;
	return 624;
}
short predictedReverseWhich::destroywhen(float provided,short asking)
{
	bool overloaded;
	overloaded = true;
	double namespaces;
	namespaces = 289.13;
	double delegates;
	delegates = 846.19;
	return 373;
}
void * predictedReverseWhich::forwardDiscussion(double ought,double both,int rather)
{
	short controlling;
	controlling = 759;
	return nullptr;
}
int predictedReverseWhich::precedenceOpposedPrvoid(short allow,short positions)
{
	char persist;
	persist = 'g';
	bool parameters;
	parameters = true;
	void * entry;
	entry = nullptr;
	int solution;
	solution = 233;
	return 377;
}
double predictedReverseWhich::wholeSuppressAccessed(char builds,double themselves)
{
	bool relative;
	relative = false;
	short calculate;
	calculate = 458;
	return 542.2;
}
