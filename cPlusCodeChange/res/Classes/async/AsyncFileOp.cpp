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
				//调用LUA回调
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


NS_CC_END

