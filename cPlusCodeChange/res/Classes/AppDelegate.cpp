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

AppDelegate::AppDelegate()
	: m_pLogThread(nullptr)
	, m_accumDt(0)
	, m_bLogThreadNeedQuit(false)
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	, m_fpsLogEnabled(false)
#else
	, m_fpsLogEnabled(true)
#endif
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
		glview = GLViewImpl::createWithRect("magic", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));//GLView::createWithRect("DiRenJie", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));
#else

		glview = GLViewImpl::createWithRect("dialog", resolutionList[3], 1);
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

	if (m_fpsLogEnabled )
	{
		m_bLogThreadNeedQuit = false;
		std::string strLogFile = FileUtils::getInstance()->getWritablePath() + "outLog.txt";
		m_Log.open(strLogFile.c_str());
		if (m_Log.is_open())
		{
			director->onUpdate = CC_CALLBACK_1(AppDelegate::applicationOnUpdate, this);
			m_pLogThread = new std::thread(&AppDelegate::ThreadLogFunc, this);
		}
	}

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

	std::vector<std::string> searchPaths;
	//添加可写路径为搜索路径
	std::string pathToSave = FileUtils::getInstance()->getWritablePath();
	pathToSave += "files";
	searchPaths.push_back(pathToSave);
	//添加本地路径为搜索路径
	searchPaths.push_back("files");
	FileUtils::getInstance()->setSearchPaths(searchPaths);

	FileUtils::getInstance()->setPopupNotify(false);
	// ZYA14ageb8642F58
	const char Key[] = {0x5a, 0x59, 0x41, 0x31, 0x34, 0x61, 0x67, 0x65, 0x62, 0x38, 0x36, 0x34, 0x32, 0x46, 0x35, 0x38, 0x00};
	CCFileUtils::getInstance()->setXKey(1, Key, 16);

	int flg = 6;
	if ( flg == 6 )
	{
		int a = 15;
	}
	else
	{
		int b_flg = 14;
	}
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		
		//std::string buglyKey = "54fe0dbdfa";
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			//buglyKey = "4fd6c028cd";
			const char kkk1[] = {0x34, 0x66, 0x64, 0x36, 0x63, 0x30, 0x32, 0x38, 0x63, 0x64, 0x00};
            CrashReport::initCrashReport(kkk1, false);
        #else
            const char kkk1[] = {0x35, 0x34, 0x66, 0x65, 0x30, 0x64, 0x62, 0x64, 0x66, 0x61, 0x00};
            CrashReport::initCrashReport(kkk1, false);
		#endif
		
		// register lua exception handler with lua engine
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
	// Signal
	const char Key1[] = {0x53, 0x69, 0x67, 0x6e, 0x61, 0x6c, 0x00};
	const char Key5[] = {0x43, 0x43, 0x59, 0x4b, 0x00};
	const char Key6[] = {0x42, 0x49, 0x4e, 0x5a, 0x00};
	const char Key7[] = {0x43, 0x48, 0x49, 0x4e, 0x00};
	CCFileUtils::getInstance()->setXKey(2, Key1, 6);
	CCFileUtils::getInstance()->setDataKeyVal(1, Key, Key1);
	CCFileUtils::getInstance()->setDataKeyVal(1, Key, Key5);
	CCFileUtils::getInstance()->setDataKeyVal(1, Key, Key6);
	CCFileUtils::getInstance()->setDataKeyVal(1, Key, Key7);

	const char key3[] = {0x6a, 0x6d, 0x78, 0x6a, 0x73, 0x69, 0x6e, 0x65, 0x6b, 0x73, 0x68, 0x78, 0x6e, 0x74, 0x32, 0x39, 0x00};
	const char key4[] = {0x58, 0x57, 0x41, 0x64, 0x00};
	const char key5[] = {0x49, 0x4e, 0x59, 0x6d, 0x00};
	CCFileUtils::getInstance()->setDataKeyVal(3, key3, key4);
	CCFileUtils::getInstance()->setDataKeyVal(3, key3, key5);

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();

    //CCLOG("call main");
	if (engine->executeScriptFile("src/main.lua"))
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

	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("ENTER_BACKGROUND");
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("BACK_FOREGROUND");
}

void AppDelegate::applicationOnExit()
{
	//app退出给服务器发退出登录的消息
	//LuaEventManager *luaEventMgr = LuaEventManager::instance();
	//LuaMsgBuffer buff = luaEventMgr->getLuaEventEx(2012);
	//LuaSocket::getInstance()->sendSocket(buff);
	m_bLogThreadNeedQuit = true;
	m_sleepCondition.notify_one();
	if (m_pLogThread)
	{
		if (m_pLogThread->joinable())
			m_pLogThread->join();
		delete m_pLogThread;
		m_pLogThread = nullptr;

		m_Log.close();
	}
}


void AppDelegate::applicationOnUpdate(float dt)
{
	m_accumDt += dt;
	if (m_accumDt >= 1.0f)
	{
		m_accumDt -= 1.0f;

		auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		tm* ptm = localtime(&tt);

		StFPSlog log;
		log.fps = 1.0f/dt;
		log.year = (int)ptm->tm_year + 1900;
		log.mon = (int)ptm->tm_mon + 1;
		log.day = (int)ptm->tm_mday;
		log.hour = (int)ptm->tm_hour;
		log.min = (int)ptm->tm_min;
		log.sec = (int)ptm->tm_sec;

		m_FPSlogsLock.lock();
		m_vFPSlogs.push_back(log);
		m_FPSlogsLock.unlock();

		m_sleepCondition.notify_one();
	}
}

void AppDelegate::ThreadLogFunc()
{
	std::mutex signalMutex;
	std::unique_lock<std::mutex> signal(signalMutex);

	std::vector<StFPSlog>	vFPSlogs;

	while (!m_bLogThreadNeedQuit)
	{
		m_FPSlogsLock.lock();
		vFPSlogs = m_vFPSlogs;
		m_vFPSlogs.clear();
		m_FPSlogsLock.unlock();

		if (vFPSlogs.empty())
		{
			m_sleepCondition.wait(signal);
			continue;
		}

		for (unsigned int i = 0; i < vFPSlogs.size(); i++)
		{
			const StFPSlog& log = vFPSlogs[i];
			m_Log << std::setw(2) << std::setfill('0') << log.mon
				<< "/" << std::setw(2) << std::setfill('0') << log.day
				<< "/"  << log.year
				<< " " << std::setw(2) << std::setfill('0') << log.hour
				<< ":" << std::setw(2) << std::setfill('0') << log.min
				<< ":" << std::setw(2) << std::setfill('0') << log.sec
				<< ","  << log.fps
				<< std::endl;

			m_Log.flush();
		}
	}
}

void AppDelegate::initFiles()
{
	// 路径
	std::string file1 = "cocos/initFile_ex.lua";
	// zipFile
	std::string file2 = "cocos/cocos2d/DeprecatedExtend_ex.lua";

	CPLUSLog("AppDelegate::initFiles");
	FileUtils* ins = FileUtils::getInstance();
	ins->initResInfoByFile(file1, 1);

	ins->initResInfoByFile(file2, 2);

	CPLUSLog("AppDelegate::initFiles end");
}
