#include "AppDelegate.h"
#include "confusionSwapThrough.h"
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
		glview = GLViewImpl::createWithRect("magic", Rect(0, 0, atoi(lauchingArgs["w"].c_str()), atoi(lauchingArgs["h"].c_str())));
#else
		glview = GLViewImpl::createWithRect("dialog", resolutionList[3], 1);
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
	std::vector<std::string> searchPaths;
	std::string pathToSave = FileUtils::getInstance()->getWritablePath();
	pathToSave += "files";
	searchPaths.push_back(pathToSave);
	searchPaths.push_back("files");
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	FileUtils::getInstance()->setPopupNotify(false);
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
	
	
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		
			const char kkk1[] = {0x34, 0x66, 0x64, 0x36, 0x63, 0x30, 0x32, 0x38, 0x63, 0x64, 0x00};
            CrashReport::initCrashReport(kkk1, false);
        #else
            const char kkk1[] = {0x35, 0x34, 0x66, 0x65, 0x30, 0x64, 0x62, 0x64, 0x66, 0x61, 0x00};
            CrashReport::initCrashReport(kkk1, false);
		#endif
	
	
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
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
    
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();
    
	if (engine->executeScriptFile("src/main.lua"))
	{
	
		return false;
	}
#endif
    return true;
}
void AppDelegate::applicationDidEnterBackground()
{
	confusionSwapThrough confusionswapthrough_e;
	confusionswapthrough_e.enclosingOverhead(17);

    Director::getInstance()->stopAnimation();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer buff = luaEventMgr->getLuaEventEx(11001);
	LuaSocket::getInstance()->sendSocket(buff);
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("ENTER_BACKGROUND");
}
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("BACK_FOREGROUND");
}
void AppDelegate::applicationOnExit()
{
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
	std::string file1 = "cocos/initFile_ex.lua";
	std::string file2 = "cocos/cocos2d/DeprecatedExtend_ex.lua";
	CPLUSLog("AppDelegate::initFiles");
	FileUtils* ins = FileUtils::getInstance();
	ins->initResInfoByFile(file1, 1);
	ins->initResInfoByFile(file2, 2);
	CPLUSLog("AppDelegate::initFiles end");
}
