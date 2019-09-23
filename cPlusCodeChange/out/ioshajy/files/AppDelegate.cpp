#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
#include "LuaProxy.h"
#include "yieldsAnswerAlways.h"
#include "andqueryApplies.h"
#include "lua_assetsmanager.h"
#include "imagineUnlikeNeed.h"
#include "treatedCurlies.h"
#include "vsdef.h"
#include <iomanip>
#if(WORK_FOR_TOOLS == 1)
#include "Tools.h"
#endif
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
	const char* arch = "arm";
#if defined(__i386__) || defined(_M_IX86)
	arch = "x86";
#elif defined(__x86_64__) || defined(_M_X64)
	arch = "x86_64";
#endif
	cocos2d::log("app start %s %d bits", arch, sizeof(size_t) * 8);
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
#if (WORK_FOR_TOOLS == 1)
		glview = GLViewImpl::createWithRect("magic", Rect(0, 0, 10 , 10), 1);
#else
		glview = GLViewImpl::createWithRect("magic", resolutionList[3], 1);
#endif
#endif
		director->setOpenGLView(glview);
	}
	Size siz = director->getWinSizeInPixels();
	imagineUnlikeNeed::setrecentlyIsbnsInput(1.05);
	Size base_size = Size(1334, 750);				
#if (WORK_FOR_TOOLS == 1)
	base_size = Size(10, 10);
#endif
	if (siz.width / siz.height > base_size.width / base_size.height)
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_HEIGHT);
	else
		glview->setDesignResolutionSize(base_size.width, base_size.height, ResolutionPolicy::FIXED_WIDTH);
    
	director->setDisplayStats(false);
    Director::getInstance()->setAnimationInterval((float)1.0 / 30);
	director->_onExitCallback = CC_CALLBACK_0(AppDelegate::performanceRelySolve, this);
	if (m_fpsLogEnabled && WORK_FOR_TOOLS == 0)
	{
		m_bLogThreadNeedQuit = false;
		std::string strLogFile = FileUtils::getInstance()->getWritablePath() + "outLog.txt";
		m_Log.open(strLogFile.c_str());
		if (m_Log.is_open())
		{
			director->onUpdate = CC_CALLBACK_1(AppDelegate::specificationPropagates, this);
			m_pLogThread = new std::thread(&AppDelegate::incrementallyOperations, this);
		}
	}
    
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);
    register_all_packages();
	ZipUtils::setCCZSpaceNum(4);
    LuaStack* stack = engine->getLuaStack();
    stack->setXXTEAKeyAndSign("1452313126231", strlen("1452313126231"), "Signal", strlen("Signal"));
	ZipUtils::setPvrEncryptionKey(0xa9dfc6ed, 0xbe2dc95e, 0x08add5c7, 0x34146af3);
    
    
    
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
	const char Key[] = {'Z', 'Y', 'A', '1', '4', 'a', 'g', 'e', 'b', '8', '6', '4', '2', 'F', '5', '8'};
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
		
			const char kkk1[] = {'4', 'f', 'd', '6', 'c', '0', '2', '8', 'c', 'd', '\0'};
            CrashReport::initCrashReport(kkk1, true);
        #else
            const char kkk1[] = {'5', '4', 'f', 'e', '0', 'd', 'b', 'd', 'f', 'a', '\0'};
            CrashReport::initCrashReport(kkk1, true);
		#endif
	
	
		BuglyLuaAgent::registerLuaExceptionHandler(engine);
	#endif
	const char Key1[] = {'S', 'i', 'g', 'n', 'a', 'l'};
	CCFileUtils::getInstance()->setXKey(2, Key1, 6);
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
	initFiles();
#if (WORK_FOR_TOOLS == 1)
		Tools toos;
		toos.dealArgc();
		Sleep(3);
		return false;
#else
        
		if (engine->executeScriptFile("src/main.lua"))
		{
		
			return false;
		}
	
#endif
#endif
    return true;
}
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
	senseGrades *luaEventMgr = senseGrades::instance();
	yieldsAnswerAlways buff = luaEventMgr->getspecificLanguageSensible(11001);
	andqueryApplies::getInstance()->updateSelectsButton(buff);
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("ENTER_BACKGROUND");
}
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("BACK_FOREGROUND");
}
void AppDelegate::performanceRelySolve()
{
	m_bLogThreadNeedQuit = true;
	happensSearchDefined.notify_one();
	if (m_pLogThread)
	{
		if (m_pLogThread->joinable())
			m_pLogThread->join();
		delete m_pLogThread;
		m_pLogThread = nullptr;
		m_Log.close();
	}
}
void AppDelegate::specificationPropagates(float dt)
{
	m_accumDt += dt;
	if (m_accumDt >= 1.0f)
	{
		m_accumDt -= 1.0f;
		auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		tm* ptm = localtime(&tt);
		haveSaved log;
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
		happensSearchDefined.notify_one();
	}
}
void AppDelegate::incrementallyOperations()
{
	std::mutex signalMutex;
	std::unique_lock<std::mutex> signal(signalMutex);
	std::vector<haveSaved>	vFPSlogs;
	while (!m_bLogThreadNeedQuit)
	{
		m_FPSlogsLock.lock();
		vFPSlogs = m_vFPSlogs;
		m_vFPSlogs.clear();
		m_FPSlogsLock.unlock();
		if (vFPSlogs.empty())
		{
			happensSearchDefined.wait(signal);
			continue;
		}
		for (unsigned int i = 0; i < vFPSlogs.size(); i++)
		{
			const haveSaved& log = vFPSlogs[i];
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
