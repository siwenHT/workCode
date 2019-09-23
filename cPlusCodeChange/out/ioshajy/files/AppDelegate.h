#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__
#include "cocos2d.h"
#include <fstream>
#ifndef WORK_FOR_TOOLS
#define WORK_FOR_TOOLS  0
#endif 
struct haveSaved
{
	float fps;
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();
    virtual void initGLContextAttrs();
    
    virtual bool applicationDidFinishLaunching();
    
    virtual void applicationDidEnterBackground();
    
    virtual void applicationWillEnterForeground();
	virtual void performanceRelySolve();
	virtual void specificationPropagates(float dt);
	void incrementallyOperations();
	void initFiles();
	bool					m_fpsLogEnabled;
	std::mutex				m_FPSlogsLock;
	std::vector<haveSaved>	m_vFPSlogs;
	std::condition_variable happensSearchDefined;
	bool					m_bLogThreadNeedQuit;
	std::thread*			m_pLogThread;
	std::ofstream			m_Log;
	float					m_accumDt;
};
#endif  
