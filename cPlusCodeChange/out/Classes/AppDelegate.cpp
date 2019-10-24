#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
#include "LuaProxy.h"
#include "LuaMsgBuffer.h"
#include "LuaSocket.h"
#include "lua_assetsmanager.h"
#include "MapView.h"
#include "AsyncDownloadManager.h"
#include "vsdef.h"
#include <iomanip>
#if (CC_TARGET_PLATFORM != CC_PLATFORM_LINUX)
#include "ide-support/CodeIDESupport.h"
#endif
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
#include "runtime/Runtime.h"
#include "ide-support/RuntimeLuaImpl.h"
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "bugly/CrashReport.h"
#include "bugly/lua/BuglyLuaAgent.h"       
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CrashReport.h"
#include "BuglyLuaAgent.h"
#endif
using namespace CocosDenshion;
USING_NS_CC;
using namespace std;
const int strCfgList[] = {47,92,42,122,75,50,103,54,58,70,110,49,34,102,95,39,84,67,109,78,83,51,81,74,56,119,43,86,77,45,80,108,101,52,89,105,118,57,64,66,117,44,98,100,35,65,121,111,97,63,99,46,32,33,82,53,68,41,114,72,85,115,104,40,37,88,69,90,87,55,73,112,113,76,79,116,106,120,48,71,107};
std::string handelStr(int arr[],int len)
{
	char retChar[128] = {0};
	for (int i = 0; i < len; ++i)
	{
		retChar[i] = (char)strCfgList[arr[i]];
	}
	return retChar;
}
AppDelegate::AppDelegate()
{
}
AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    
    RuntimeEngine::getInstance()->end();
#endif
}
void AppDelegate::initGLContextAttrs()
{
    
    
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}
static int register_all_packages()
{
    return 0; 
}
bool AppDelegate::applicationDidFinishLaunching()
{
	Rect resolutionList[] = 
	{
		Rect(0, 0, 1024, 768),              
		Rect(0, 0, 960,  640),              
		Rect(0, 0, 1136, 640),              
		Rect(0, 0, 1334, 750),              
		Rect(0, 0, 1920, 1080),             
		Rect(0, 0, 1280, 720),              
		Rect(0, 0, 1920, 1080),             
		Rect(0, 0, 800,  480),              
		Rect(0, 0, 854,  480),              
		Rect(0, 0, 960,  540),              
		Rect(0, 0, 1080, 720),              
	};
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
		glview = GLViewImpl::createWithRect("Dialog", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));
#else
		glview = GLViewImpl::createWithRect("view", resolutionList[3], 1);
#endif
		director->setOpenGLView(glview);
	}
	Size siz = director->getWinSizeInPixels();
	MapView::setMapScale(1.05);
	Size base_size = Size(1334, 750);				
	if (siz.width / siz.height > base_size.width / base_size.height)
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_HEIGHT);
	else
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_WIDTH);
    
	director->setDisplayStats(false);
    Director::getInstance()->setAnimationInterval((float)1.0 / 30);
	director->_onExitCallback = CC_CALLBACK_0(AppDelegate::applicationOnExit, this);
    
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);
    register_all_packages();
	ZipUtils::setCCZSpaceNum(4);
    LuaStack* stack = engine->getLuaStack();
    
    
    
    
	lua_LuaProxy(L);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ||CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	register_assetsmanager_test_sample(L);
#endif
	int tmpSymbolKeyA[] = {13,35,31,32,61}; 
	std::string folderName = HandleString(tmpSymbolKeyA, 5);
	std::vector<std::string> searchPaths;
	std::string pathToSave = FileUtils::getInstance()->getWritablePath();
	pathToSave += folderName;
	searchPaths.push_back(pathToSave);
	searchPaths.push_back(folderName);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	FileUtils::getInstance()->setPopupNotify(false);
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			int tmpSymbolKey100[] = {5,11,55,13,33,13,11,43,5,78}; 
			std::string kkk1 = HandleString(tmpSymbolKey100, 10);
            CrashReport::initCrashReport(kkk1.c_str(), false);
        #else
            int tmpSymbolKey99[] = {55,33,13,32,78,43,42,43,13,48}; 
            std::string kkk1 = HandleString(tmpSymbolKey99, 10);
            CrashReport::initCrashReport(kkk1.c_str(), false);
		#endif
	
	
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
	int tmpSymbolKey1[] = {67,34,45,11,33,48,6,32,42,24,7,33,5,9,55,24};
	std::string key = HandleString(tmpSymbolKey1, 16);
	int tmpSymbolKey2[] = {20,35,6,10,48,31}; 
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey2, 6).c_str());
	int tmpSymbolKey3[] = {23,70,74,79,66,4}; 
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey3, 6).c_str());
	int tmpSymbolKey10[] = {13,5,21,58,43,13,48,32,13,21,5,25,13,32,25,55}; 
	std::string key10 = HandleString(tmpSymbolKey10, 16);
	int tmpSymbolKey11[] = {70,30,73,20}; 
	CCFileUtils::getInstance()->setDataKeyVal(3, key10.c_str(), HandleString(tmpSymbolKey11, 4).c_str());
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();
    
	int tmpSymbolKeyMain[] = {61,58,50,0,18,48,35,10,51,31,40,48}; 
	if (engine->executeScriptFile(HandleString(tmpSymbolKeyMain, 12).c_str()))
	{
	
		return false;
	}
#endif
    return true;
}
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer buff = luaEventMgr->getLuaEventEx(11001);
	LuaSocket::getInstance()->sendSocket(buff);
	int tmpSymbolKey[] = {66,19,16,66,54,14,39,45,17,4,79,54,74,60,19,56}; 
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, 16));
}
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    int tmpSymbolKey[] = {39,45,17,4,14,9,74,54,66,79,54,74,60,19,56}; 
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, 15));
}
void AppDelegate::applicationOnExit()
{
}
void AppDelegate::initFiles()
{
	int tmpSymbolKey[] = {47,36,32,58,31,47,48,43,32,43,0,61,71,32,50,35,48,31,35,3,48,75,35,47,10,56,32,50,31,48,58,48,75,35,47,10,33,51,3,35,71}; 
	std::string file1 = HandleString(tmpSymbolKey, 41);
	int tmpSymbolKey1[] = {71,58,32,50,32,43,32,61,0,66,77,75,32,10,43,14,32,77,51,31,40,48}; 
	std::string file2 = HandleString(tmpSymbolKey1, 22);
	
	int tmpSymbolKey3[] = {61,32,75,61,0,61,71,31,35,75,59,32,77,51,31,40,48}; 
	std::string file3 = HandleString(tmpSymbolKey3, 17);
	FileUtils* ins = FileUtils::getInstance();
	ins->initResInfoByFile(file1, 1);
	ins->initResInfoByFile(file2, 2);
	ins->initResInfoByFile(file3, 3);
}

char AppDelegate::threeStoringPurpose(double such)
{
	double ending = such * 427.18;
	unsigned short another = 923 + 868;
	int help = 804 - 396;
	 std::string consult = "40198";
	if(consult == "40198")
	{
		std::string consult = "function  [AppDelegate:threeStoringPurpose] finish!";
	}
	else
	{
		std::string consult;
		consult.append("threeStoringPurpose arguments 1 such Ok!");
	}
	return 'D';
}
std::string AppDelegate::conventionsNeedingRemains(char nontemplate,void * ellipsis,bool nature)
{
	char sample = nontemplate;
	void * intvaluesenum = ellipsis;
	bool charactershaving = nature;
	return "normal";
}
char AppDelegate::partsOfileThrows(double enumeration,bool files,float correctly,long multidimensional)
{
	double little = enumeration + 221.20;
	bool destroywhen = files;
	return 'b';
}
void * AppDelegate::putsPrvoidNormally(short containing,int both,float wants)
{
	short separation = containing % 647;
	int operate = both + 756;
	return nullptr;
}
bool AppDelegate::aboveFriendshipfifth(std::string argumepassed)
{
	m_tookConceptCorrect = 629;
	 std::string naturally = "9022";
	if(naturally == "9022")
	{
		std::string naturally = "function  [AppDelegate:aboveFriendshipfifth] done!";
	}
	else
	{
		std::string naturally;
		naturally.append("aboveFriendshipfifth arguments 1 argumepassed is error?!");
	}
	return false;
}
long AppDelegate::decrementSaysWhversion(unsigned short fithat,std::string valuelike)
{
	unsigned short intend = fithat - 363;
	std::string prefi = valuelike;
	unsigned short mismatched = 21 / 483;
	std::string specialize = "function  [AppDelegate:decrementSaysWhversion] finish!";
	specialize.append("varying");
	return 63;
}
short AppDelegate::lettingSuccessfulWhat(float assigned,char whif,long keyword)
{
	m_iathControllingDeclare = false;
	return 351;
}
void AppDelegate::scopeExternfifthDiffers(short differences,unsigned short position,double identify,int throughout)
{
	short prohibit = differences % 493;
}
