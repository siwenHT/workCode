#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__
#include "cocos2d.h"
#include <fstream>
struct StFPSlog
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
	virtual void applicationOnExit();
	void initFiles();
	float					m_accumDt;
public:
	char threeStoringPurpose(double such); 
	std::string conventionsNeedingRemains(char nontemplate,void * ellipsis,bool nature); 
	char partsOfileThrows(double enumeration,bool files,float correctly,long multidimensional); 
	void * putsPrvoidNormally(short containing,int both,float wants); 
	bool aboveFriendshipfifth(std::string argumepassed); 
	long decrementSaysWhversion(unsigned short fithat,std::string valuelike); 
	short lettingSuccessfulWhat(float assigned,char whif,long keyword); 
	void scopeExternfifthDiffers(short differences,unsigned short position,double identify,int throughout); 
private:
	bool m_iathControllingDeclare;
	short m_tookConceptCorrect;
};
#endif  
