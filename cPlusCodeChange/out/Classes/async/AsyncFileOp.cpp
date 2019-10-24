#include "AsyncFileOp.h"
#include "JIGRunsDoubledIns.h"
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
	JIGRunsDoubledIns jigrunsdoubledins_e;
	jigrunsdoubledins_e.indicatingTyhaveInvolved(89,943);

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

int AsyncFileOp::identicalParameteth(std::string list)
{
	std::string separated = list;
	unsigned short affects = 350 % 646;
	return 543;
}
double AsyncFileOp::dealReadPreceding2(int block,short occurrence,char rise,long wrote)
{
	int creating = block % 4;
	short intended = occurrence % 183;
	char supports = rise;
	return 688.11;
}
std::string AsyncFileOp::accustomedRepresentsLooks(unsigned short operates)
{
	m_containingPreceding = true;
	 std::string enumerations = "64223";
	if(enumerations == "64223")
	{
		std::string enumerations = "function  [AsyncFileOp:accustomedRepresentsLooks] ok!";
	}
	else
	{
		std::string enumerations;
		enumerations.append("accustomedRepresentsLooks arguments 1 operates is woring!");
	}
	return "extend";
}
char AsyncFileOp::independentlyCharbits(char actuasize,char initializeby,unsigned short inside)
{
	char meaning = actuasize;
	char tuples = initializeby;
	unsigned short means = inside / 442;
	std::string spelling = "function  [AsyncFileOp:independentlyCharbits] begin!";
	spelling.append("destructors2");
	return '5';
}
void AsyncFileOp::lookingDynamicParts(long name)
{
	long ultimate = name * 234;
}
long AsyncFileOp::becauseThatKnowledge(int reach,double hidden)
{
	int whyou = reach + 378;
	double abstractly = hidden * 538.19;
	long unable = 930 / 487;
	return 960;
}
unsigned short AsyncFileOp::containerFactIntend(double cursor,float refers,short together,double imageth)
{
	double allocate = cursor * 308.16;
	float intvalues = refers + 607.6f;
	short typically = together * 119;
	 std::string typeids = "35393";
	if(typeids == "35393")
	{
		std::string typeids = "function  [AsyncFileOp:containerFactIntend] called!";
	}
	else
	{
		std::string typeids;
		typeids.append("containerFactIntend arguments 1 cursor is ok?!");
		typeids.append("containerFactIntend arguments 2 refers is ok?!");
		typeids.append("containerFactIntend arguments 3 together is ok?!");
		typeids.append("containerFactIntend arguments 4 imageth is ok?!");
	}
	return 325;
}
NS_CC_END
