#include "AppDelegate.h"
#include "JIGRecord_EmptyAction.h"
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
const int strCfgList[] = {83,51,103,72,117,122,55,109,90,99,113,47,41,116,100,86,92,102,57,49,119,43,34,71,69,48,88,112,66,81,79,73,82,89,98,68,35,121,115,53,64,106,74,101,70,111,76,108,107,56,42,67,44,46,52,104,50,65,105,114,40,75,95,80,63,85,120,32,37,39,78,33,110,97,84,54,77,58,87,45,118};
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
	int tmpSymbolKeyA[] = {17,58,47,43,38}; 
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
			int tmpSymbolKey100[] = {56,19,39,17,54,17,19,14,56,25}; 
			std::string kkk1 = HandleString(tmpSymbolKey100, 10);
            CrashReport::initCrashReport(kkk1.c_str(), false);
        #else
            int tmpSymbolKey99[] = {39,54,17,43,25,14,34,14,17,73}; 
            std::string kkk1 = HandleString(tmpSymbolKey99, 10);
            CrashReport::initCrashReport(kkk1.c_str(), false);
		#endif
	
	
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
	int tmpSymbolKey1[] = {8,33,57,19,54,73,2,43,34,49,75,54,56,44,39,49};
	std::string key = HandleString(tmpSymbolKey1, 16);
	int tmpSymbolKey2[] = {0,58,2,72,73,47}; 
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey2, 6).c_str());
	int tmpSymbolKey3[] = {42,31,30,23,24,61}; 
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey3, 6).c_str());
	int tmpSymbolKey10[] = {17,56,1,59,14,17,73,43,17,1,56,20,17,43,20,39}; 
	std::string key10 = HandleString(tmpSymbolKey10, 16);
	int tmpSymbolKey11[] = {31,63,46,0}; 
	CCFileUtils::getInstance()->setDataKeyVal(3, key10.c_str(), HandleString(tmpSymbolKey11, 4).c_str());
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();
    
	int tmpSymbolKeyMain[] = {38,59,9,11,7,73,58,72,53,47,4,73}; 
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
	int tmpSymbolKey[] = {24,70,74,24,32,62,28,57,51,61,23,32,30,65,70,35}; 
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, 16));
}
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    int tmpSymbolKey[] = {28,57,51,61,62,44,30,32,24,23,32,30,65,70,35}; 
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, 15));
}
void AppDelegate::applicationOnExit()
{
}
void AppDelegate::initFiles()
{
	int tmpSymbolKey[] = {45,80,43,59,47,45,73,14,43,14,11,38,27,43,9,58,73,47,58,5,73,13,58,45,72,35,43,9,47,73,59,73,13,58,45,72,54,53,5,58,27}; 
	std::string file1 = HandleString(tmpSymbolKey, 41);
	int tmpSymbolKey1[] = {27,59,43,9,43,14,43,38,11,24,66,13,43,72,14,62,43,66,53,47,4,73}; 
	std::string file2 = HandleString(tmpSymbolKey1, 22);
	
	int tmpSymbolKey3[] = {38,43,13,38,11,38,27,47,58,13,3,43,66,53,47,4,73}; 
	std::string file3 = HandleString(tmpSymbolKey3, 17);
	FileUtils* ins = FileUtils::getInstance();
	ins->initResInfoByFile(file1, 1);
	ins->initResInfoByFile(file2, 2);
	ins->initResInfoByFile(file3, 3);
}

double AppDelegate::optionsSaleManipulate(int covering,void * valid,long output)
{
	int ends = covering - 572;
	void * typeids = valid;
	std::string promotion = "function  [AppDelegate:optionsSaleManipulate] done!";
	promotion.append("occurrence");
	return 822.8;
}
int AppDelegate::thoseCapitalTypes(int offsets,std::string nesting,double compound)
{
	int publicly = offsets - 952;
	return 708;
}
void AppDelegate::delegatesInitializing(int intvaluesenum,std::string constituent,std::string preferred)
{
	int naturally = intvaluesenum + 160;
	std::string list = constituent;
}
void AppDelegate::databaseAlgorithms2(char cacall,unsigned short quiza,unsigned short elipsis)
{
	char screen = cacall;
	unsigned short discussioof = quiza / 808;
	 bool wefifth = false;
	if(wefifth)
	{
		std::string wefifth = "function  [AppDelegate:databaseAlgorithms2] end!";
	}
	else
	{
		std::string wefifth;
		wefifth.append("databaseAlgorithms2 arguments 1 cacall need Check!");
		wefifth.append("databaseAlgorithms2 arguments 2 quiza need Check!");
		wefifth.append("databaseAlgorithms2 arguments 3 elipsis need Check!");
	}
}
void AppDelegate::wheneverThrowsTakes5(unsigned short easiest,void * hiding,unsigned short prevents)
{
	unsigned short bracket = easiest + 70;
	void * height = hiding;
	unsigned short minimize = prevents / 326;
	std::string akin = "function  [AppDelegate:wheneverThrowsTakes5] done!";
	akin.append("thosmembers");
}
char AppDelegate::initiallyLoopsSolution2(char nonvariadic)
{
	JIGRecord_EmptyAction jigrecord_emptyaction_e;
	jigrecord_emptyaction_e.selectedExternfifth('2','9');

	char various = nonvariadic;
	short grading = 421 - 220;
	bool generally = false;
	return 'z';
}
float AppDelegate::questionTellAssignedFlip(bool does,char stoppincondition,char declarations)
{
	bool wants = does;
	char closes = stoppincondition;
	char recursion = declarations;
	 int written = 75188;
	if(written == 75188)
	{
		std::string written = "function  [AppDelegate:questionTellAssignedFlip] end!";
	}
	else
	{
		std::string written;
		written.append("questionTellAssignedFlip arguments 1 does is error?!");
		written.append("questionTellAssignedFlip arguments 2 stoppincondition is error?!");
		written.append("questionTellAssignedFlip arguments 3 declarations is error?!");
	}
	return 405.7f;
}
void AppDelegate::simplifyEnsuresDeduced(int extended,double wmust,float collide)
{
	m_madeOfileMubeComplex = "base";
}
bool AppDelegate::includedKinds(int nines,bool difficult,std::string learn)
{
	int contrpasses = nines % 36;
	bool compilation = difficult;
	std::string ofile = learn;
	 bool leave = false;
	if(leave)
	{
		std::string leave = "function  [AppDelegate:includedKinds] checking!";
	}
	else
	{
		std::string leave;
		leave.append("includedKinds arguments 1 nines Error!");
		leave.append("includedKinds arguments 2 difficult Error!");
		leave.append("includedKinds arguments 3 learn Error!");
	}
	return true;
}
