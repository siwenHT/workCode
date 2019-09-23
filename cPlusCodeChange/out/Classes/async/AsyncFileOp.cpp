#include "AsyncFileOp.h"
#include "correspondRepresentation.h"
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

int AsyncFileOp::heldFunctiopresented(unsigned short behalf,long isbn,short hierarchy,unsigned short wish)
{
	unsigned short stringsthe = behalf + 236;
	long become = isbn + 213;
	short howevewe = hierarchy % 410;
	return 499;
}
void AsyncFileOp::loopsPushedBrown(double immediately,char bits)
{
	double appropriate = immediately - 844.20;
	char evaluated = bits;
	char translate = '5';
}
char AsyncFileOp::conversionchapterEquals(double seemingly,long ordinary)
{
	m_deducesValuelikeThus = 484;
	return 'L';
}
void * AsyncFileOp::recognizingSectionsSimply(unsigned short reject,char matter,bool seen,float determine)
{
	unsigned short asfifth = reject - 210;
	return nullptr;
}
bool AsyncFileOp::closesManualHowevewe(char defines,char queryresult,bool instantiations)
{
	correspondRepresentation correspondrepresentation_e;
	correspondrepresentation_e.stringCouldParametea(nullptr,648.20f);

	m_thpositionSurelyThere = 566;
	return false;
}
int AsyncFileOp::inttypSiteLibrary(void * constitute,unsigned short finds,bool affects,unsigned short grades)
{
	m_thpositionSurelyThere = 202;
	return 125;
}
int AsyncFileOp::reachNothingOver(float compilers,short color)
{
	m_deducesValuelikeThus = 32;
	return 72;
}
bool AsyncFileOp::pairwiseLessDone(bool often,float begins,void * extensioindicating,int exclusive)
{
	bool occur = often;
	float legal = begins * 979.4f;
	void * want = extensioindicating;
	return true;
}
float AsyncFileOp::attemptedDeduction(bool convention,unsigned short abstractly,int framework,int abstraction)
{
	bool conflict = convention;
	return 303.7f;
}
NS_CC_END
