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


// 导入头文件 CrashReport.h 和 BuglyLuaAgent.h
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "bugly/CrashReport.h"
#include "bugly/lua/BuglyLuaAgent.h"       
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CrashReport.h"
#include "BuglyLuaAgent.h"
#endif

//#include <vld.h> 

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

const int strCfgList[] = {};

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
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    RuntimeEngine::getInstance()->end();
#endif

}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// const char* arch = "arm";

// #if defined(__i386__) || defined(_M_IX86)
	// arch = "x86";
// #elif defined(__x86_64__) || defined(_M_X64)
	// arch = "x86_64";
// #endif

	// cocos2d::log("app start %s %d bits", arch, sizeof(size_t) * 8);

	// 市面上主流手机屏幕大小，方便屏幕适配
	// 关键在于宽高比, 大小不重要           // 编号  宽高比  机型
	Rect resolutionList[] = 
	{
		Rect(0, 0, 1024, 768),              // 0.   1.33    iPad,
		Rect(0, 0, 960,  640),              // 1.   1.5     iPhone 4
		Rect(0, 0, 1136, 640),              // 2.   1.77    iPhone 5
		Rect(0, 0, 1334, 750),              // 3.   1.78    iPhone 6
		Rect(0, 0, 1920, 1080),             // 4.   1.78    iPhone 6P
		Rect(0, 0, 1280, 720),              // 5.   1.78    中低端Android机  30%
		Rect(0, 0, 1920, 1080),             // 6.   1.78    中高端Android机  15%
		Rect(0, 0, 800,  480),              // 7.   1.67    低端Android机-A  12%
		Rect(0, 0, 854,  480),              // 8.   1.78    低端Android机-B  10%
		Rect(0, 0, 960,  540),              // 9.   1.78    低端Android机-C  9% 
		Rect(0, 0, 1080, 720),              // 10.  1.5     
	};

	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
		glview = GLViewImpl::createWithRect("Dialog", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));//GLView::createWithRect("DiRenJie", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));
#else

		glview = GLViewImpl::createWithRect("view", resolutionList[3], 1);
#endif
		director->setOpenGLView(glview);
	}

	Size siz = director->getWinSizeInPixels();
	MapView::setMapScale(1.05);
	Size base_size = Size(1334, 750);					//基本当前不能修改 因为地图是比例是按照这个比例来设计的

	//注释这断代码，没必要了
//#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
//	if (siz.height > 640)//ipad
//		base_size = Size(1280, 854);
//#endif
	if (siz.width / siz.height > base_size.width / base_size.height)
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_HEIGHT);
	else
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_WIDTH);
    // set default FPS
	director->setDisplayStats(false);

    Director::getInstance()->setAnimationInterval((float)1.0 / 30);
	director->_onExitCallback = CC_CALLBACK_0(AppDelegate::applicationOnExit, this);

    // register lua module
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);

    register_all_packages();

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
//#endif
	ZipUtils::setCCZSpaceNum(4);

    LuaStack* stack = engine->getLuaStack();
    //stack->setXXTEAKeyAndSign("1452313126231", strlen("1452313126231"), "Signal", strlen("Signal"));
	//ZipUtils::setPvrEncryptionKey(0xa9dfc6ed, 0xbe2dc95e, 0x08add5c7, 0x34146af3);

    //register custom function
    //LuaStack* stack = engine->getLuaStack();
    //register_custom_function(stack->getLuaState());
	lua_LuaProxy(L);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ||CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	register_assetsmanager_test_sample(L);
#endif

	int tmpSymbolKeyA[] = {}; //"files"
	std::string folderName = HandleString(tmpSymbolKeyA, STRNUMSIG);
	std::vector<std::string> searchPaths;
	//添加可写路径为搜索路径
	std::string pathToSave = FileUtils::getInstance()->getWritablePath();
	pathToSave += folderName;
	searchPaths.push_back(pathToSave);
	//添加本地路径为搜索路径
	searchPaths.push_back(folderName);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	FileUtils::getInstance()->setPopupNotify(false);

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			int tmpSymbolKey100[] = {}; //"215f4f1d20"
			std::string kkk1 = HandleString(tmpSymbolKey100, STRNUMSIG);
            CrashReport::initCrashReport(kkk1.c_str(), false);
        #else
            int tmpSymbolKey99[] = {}; //"54fe0dbdfa"
            std::string kkk1 = HandleString(tmpSymbolKey99, STRNUMSIG);
            CrashReport::initCrashReport(kkk1.c_str(), false);
		#endif
		
		// register lua exception handler with lua engine
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
	
	int tmpSymbolKey1[] = {};//"ZYA14ageb8642F58"
	std::string key = HandleString(tmpSymbolKey1, STRNUMSIG);
	int tmpSymbolKey2[] = {}; //"Signal"
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey2, STRNUMSIG).c_str());
	int tmpSymbolKey3[] = {}; //"JIOGEK"
	CCFileUtils::getInstance()->setDataKeyVal(1, key.c_str(), HandleString(tmpSymbolKey3, STRNUMSIG).c_str());

	int tmpSymbolKey10[] = {}; //"f23rdfaef32wfew5"
	std::string key10 = HandleString(tmpSymbolKey10, STRNUMSIG);
	int tmpSymbolKey11[] = {}; //"IPLS"
	CCFileUtils::getInstance()->setDataKeyVal(3, key10.c_str(), HandleString(tmpSymbolKey11, STRNUMSIG).c_str());

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();

    //CCLOG("call main");
	int tmpSymbolKeyMain[] = {}; //"src/main.lua"
	if (engine->executeScriptFile(HandleString(tmpSymbolKeyMain, STRNUMSIG).c_str()))
	{
		//CCLOG("main.lua run error!");
		return false;
	}
	//CCLOG("main.lua run ok!");
#endif
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer buff = luaEventMgr->getLuaEventEx(11001);
	LuaSocket::getInstance()->sendSocket(buff);

	int tmpSymbolKey[] = {}; //"ENTER_BACKGROUND"
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, STRNUMSIG));
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    int tmpSymbolKey[] = {}; //"BACK_FOREGROUND"
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(HandleString(tmpSymbolKey, STRNUMSIG));
}

void AppDelegate::applicationOnExit()
{
	//app退出给服务器发退出登录的消息
	//LuaEventManager *luaEventMgr = LuaEventManager::instance();
	//LuaMsgBuffer buff = luaEventMgr->getLuaEventEx(2012);
	//LuaSocket::getInstance()->sendSocket(buff);
}

void AppDelegate::initFiles()
{
	// 路径
	int tmpSymbolKey[] = {}; //"overloaded/specializationDeclaration4.zip"
	std::string file1 = HandleString(tmpSymbolKey, STRNUMSIG);

	// zipFile
	int tmpSymbolKey1[] = {}; //"precedes/Extend_ex.lua"
	std::string file2 = HandleString(tmpSymbolKey1, STRNUMSIG);

		// zipFile
	int tmpSymbolKey3[] = {}; //"sets/splitHex.lua"
	std::string file3 = HandleString(tmpSymbolKey3, STRNUMSIG);

//	CPLUSLog("AppDelegate::initFiles");
	FileUtils* ins = FileUtils::getInstance();
	ins->initResInfoByFile(file1, 1);
	ins->initResInfoByFile(file2, 2);
	ins->initResInfoByFile(file3, 3);
//	CPLUSLog("AppDelegate::initFiles end");
}
