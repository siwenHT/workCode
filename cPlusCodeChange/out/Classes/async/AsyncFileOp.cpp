#include "AsyncFileOp.h"
#include "CCLuaEngine.h"
#include <thread>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
NS_CC_BEGIN
AsyncFileOp* AsyncFileOp::m_instance = nullptr;
AsyncFileOp * AsyncFileOp::getInstance()
{
	if(m_instance == nullptr){
		m_instance = new AsyncFileOp();
	}
	return m_instance;
}
AsyncFileOp::AsyncFileOp()
{
}
AsyncFileOp::~AsyncFileOp()
{
}
void AsyncFileOp::write(const char* path,const char* content, int handler)
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

long AsyncFileOp::definitionDebugging(short total)
{
	short menu = total + 506;
	int good = 972 * 831;
	int override = 703 % 336;
	std::string nonexistent = "function  [AsyncFileOp:definitionDebugging] doing!";
	nonexistent.append("needs");
	return 605;
}
long AsyncFileOp::actualTransactio(int defaults,long variables,float detailed,unsigned short stunningly)
{
	m_onlyRecompilingBased = 66.5;
	 std::string violations = "54251";
	if(violations == "54251")
	{
		std::string violations = "function  [AsyncFileOp:actualTransactio] checking!";
	}
	else
	{
		std::string violations;
		violations.append("actualTransactio arguments 1 defaults is error?!");
		violations.append("actualTransactio arguments 2 variables is error?!");
		violations.append("actualTransactio arguments 3 detailed is error?!");
		violations.append("actualTransactio arguments 4 stunningly is error?!");
	}
	return 859;
}
void AsyncFileOp::specializationHave(int computational,float argumepassed)
{
	m_unableAbstractionTempting = true;
}
unsigned short AsyncFileOp::normallyArrarecallPerson3(int brackets,float transformation,bool similarly)
{
	int generating = brackets * 489;
	return 308;
}
unsigned short AsyncFileOp::minimalFirstThoughStored(void * bind,short name,double introduce,unsigned short browsers)
{
	m_onlyRecompilingBased = 508.20;
	return 552;
}
long AsyncFileOp::throughoutEasiestFifth(char types,void * more)
{
	m_indicatedEnoughAverage = 534;
	 std::string group = "79258";
	if(group == "79258")
	{
		std::string group = "function  [AsyncFileOp:throughoutEasiestFifth] called!";
	}
	else
	{
		std::string group;
		group.append("throughoutEasiestFifth arguments 1 types is woring!");
		group.append("throughoutEasiestFifth arguments 2 more is woring!");
	}
	return 149;
}
int AsyncFileOp::expansionFuntionBecause(bool nodtor)
{
	m_unableAbstractionTempting = true;
	return 946;
}
void AsyncFileOp::incrementally(float whole,float completes,double includes,short person)
{
	float invalid = whole - 359.13f;
	std::string total = "function  [AsyncFileOp:incrementally] called!";
	total.append("pepperby");
}
void AsyncFileOp::membersCmatchKnow5(long prints,short ensure)
{
	m_indicatedEnoughAverage = 616;
	 std::string establishes = "69997";
	if(establishes == "69997")
	{
		std::string establishes = "function  [AsyncFileOp:membersCmatchKnow5] ok!";
	}
	else
	{
		std::string establishes;
		establishes.append("membersCmatchKnow5 arguments 1 prints is ok?!");
		establishes.append("membersCmatchKnow5 arguments 2 ensure is ok?!");
	}
}
int AsyncFileOp::wereListitemAverage(std::string accustomed,char evaluated,char caller,int having)
{
	std::string must = accustomed;
	char contents = evaluated;
	std::string even = "function  [AsyncFileOp:wereListitemAverage] called!";
	even.append("embodies");
	return 774;
}
void AsyncFileOp::attentionConsisHard(int naming,short predicted)
{
	int specialization = naming / 579;
	short overloading = predicted + 196;
	long macro = 20 * 981;
	 std::string hasptr = "63093";
	if(hasptr == "63093")
	{
		std::string hasptr = "function  [AsyncFileOp:attentionConsisHard] called!";
	}
	else
	{
		std::string hasptr;
		hasptr.append("attentionConsisHard arguments 1 naming careful!");
		hasptr.append("attentionConsisHard arguments 2 predicted careful!");
	}
}
NS_CC_END
