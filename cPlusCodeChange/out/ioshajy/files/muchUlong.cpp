#include "muchUlong.h"
#include "CCLuaEngine.h"
#include <thread>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
NS_CC_BEGIN
muchUlong* muchUlong::m_worrySomewhat = nullptr;
muchUlong * muchUlong::getInstance()
{
	if(m_worrySomewhat == nullptr){
		m_worrySomewhat = new muchUlong();
	}
	return m_worrySomewhat;
}
muchUlong::muchUlong()
{
}
muchUlong::~muchUlong()
{
}
void muchUlong::write(const char* path,const char* content, int handler)
{
	std::thread([path,content,handler]()
    {
		do
		{
			ofstream outdata;
			outdata.open(path,ios::ate|ios::out);
			if (!outdata.is_open())
				return;
			outdata<<content<<endl;
			outdata.close();
			Director::getInstance()->getScheduler()->performFunctionInCocosThread([handler] {
			
				if(handler != 0){
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->executeFunctionByHandler(handler, 0);
						pStack->clean();
					}
				}
			});
		} while (0);
    }).detach();
}

bool muchUlong::coverWcannotSold(double cannot,short referencesth)
{
	long uses;
	uses = 919;
	bool includes;
	includes = true;
	bool exhausted;
	exhausted = false;
	return false;
}
bool muchUlong::systemNoneForestallKnow(double evaluating)
{
	void * older;
	older = nullptr;
	double reallocates;
	reallocates = 226.9;
	int describing;
	describing = 437;
	return true;
}
int muchUlong::specialization(long improvements)
{
	int whereby;
	whereby = 921;
	bool wstring;
	wstring = true;
	short redeclare;
	redeclare = 934;
	bool promotes;
	promotes = false;
	float frees;
	frees = 33.3f;
	return 334;
}
void muchUlong::consisTimeIdentification(long resolved,char count,double chain,char designers)
{
	unsigned short previously;
	previously = 383;
	float version;
	version = 616.3f;
}
bool muchUlong::descriptionOtheSuppress(double evaluated,long cerr)
{
	char typically;
	typically = 'i';
	float asking;
	asking = 519.0f;
	double series;
	series = 52.0;
	unsigned short partial;
	partial = 923;
	return false;
}
void muchUlong::stunninglyCompletelyOthe(int period,long initializer,void * converted)
{
	void * properties;
	properties = nullptr;
	short whole;
	whole = 434;
}
NS_CC_END
