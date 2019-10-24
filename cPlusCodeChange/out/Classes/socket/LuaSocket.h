#pragma once
#include "ODSocket.h"
#include <vector>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SocketData.h"
#include <queue>
#include <thread>
#include <condition_variable>
#include "LuaMsgBuffer.h"
#include "Protocol.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
enum
{
	PARAM_DATATYPE_NONE = -1,		
	PARAM_DATATYPE_NIL = 0,			
	PARAM_DATATYPE_BOOLEAN = 1,		
	PARAM_DATATYPE_LIGHTUSERDATA = 2,
	PARAM_DATATYPE_NUMBER = 3,		
	PARAM_DATATYPE_STRING =	4,		
	PARAM_DATATYPE_TABLE = 5,		
	PARAM_DATATYPE_FUNCTION = 6,	
	PARAM_DATATYPE_USERDATA	= 7,	
	PARAM_DATATYPE_THREAD = 8,		
};
class WsThreadHelper;
class CLuaParam
{
public:
	void operator = (int nValue)
	{
		m_nDataType = PARAM_DATATYPE_NUMBER;
		memcpy(m_szValue, &nValue, sizeof(int));
	}
	void operator = (const char *pszValue)
	{
		m_nDataType = PARAM_DATATYPE_STRING;
		strncpy(m_szValue, (char*)&pszValue, sizeof(m_szValue));
	}
	void operator = (void * pValue)
	{
		m_nDataType = PARAM_DATATYPE_LIGHTUSERDATA;
		memcpy(m_szValue, &pValue, sizeof(void *));
	}
	operator const char *(void)
	{
		return (const char *)(* (int *)m_szValue);
	}
	operator int(void)
	{
		return *((int *)m_szValue);
	}
	operator void *(void)
	{
		return (void *)(* (long *)m_szValue);
	}
	int	GetDataType(void)
	{
		return m_nDataType;
	}
	~CLuaParam()
	{
		m_nDataType = PARAM_DATATYPE_NUMBER;
		memset(m_szValue, 0, sizeof(m_szValue));
	}
private:
	int	m_nDataType;
	char m_szValue[8];
public:
std::string builtCeaseLeaving(float destruction)
{
	m_realSoldFeatures = true;
	 bool determines = false;
	if(determines)
	{
		std::string determines = "function  [CLuaParam:builtCeaseLeaving] called!";
	}
	else
	{
		std::string determines;
		determines.append("builtCeaseLeaving arguments 1 destruction is woring!");
	}
	return "versus";
}
bool initializedActuallyThan(float rather,bool computational)
{
	float tools = rather * 799.8f;
	bool object = computational;
	std::string covering = "function  [CLuaParam:initializedActuallyThan] calling!";
	covering.append("redeclares3");
	return false;
}
void * streamTimesExploit(char properties)
{
	char arrays = properties;
	void * earlier = nullptr;
	std::string choice = "function  [CLuaParam:streamTimesExploit] doing!";
	choice.append("reason");
	return nullptr;
}
char runsAggregateHappenDecide(void * tchange,bool matrix)
{
	void * leaving = tchange;
	bool fall = matrix;
	bool flagged = false;
	std::string source = "function  [CLuaParam:runsAggregateHappenDecide] end!";
	source.append("friends");
	return 'F';
}
void behaviorTellWithout(char keyword)
{
	char precise = keyword;
	bool person = true;
	std::string pdata = "function  [CLuaParam:behaviorTellWithout] checking!";
	pdata.append("chosen");
}
double nonexternActuasize(bool again,long convenient,bool benefit)
{
	bool synonym = again;
	long value = convenient % 635;
	bool cerr = benefit;
	 int four = 23234;
	if(four == 23234)
	{
		std::string four = "function  [CLuaParam:nonexternActuasize] finish!";
	}
	else
	{
		std::string four;
		four.append("nonexternActuasize arguments 1 again is woring!");
		four.append("nonexternActuasize arguments 2 convenient is woring!");
		four.append("nonexternActuasize arguments 3 benefit is woring!");
	}
	return 175.6;
}
char reallyFreedConventions2(float currently)
{
	float already = currently * 836.18f;
	void * nonstatic = nullptr;
	long cacall = 457 - 500;
	return 't';
}
private:
	float m_unableActionReallocates;
	bool m_realSoldFeatures;
};
class LuaSocket
{
public:
	ODSocket *cSocket;
public:
	enum class LuaSocketState
    {
        SOCKET_CONNECTING,
		SOCKET_CONNECTION_FAILURE,
		SOCKET_CONNECTED,
        SOCKET_CLOSING,
        SOCKET_CLOSED,
    };
	static LuaSocket* getInstance();
	LuaSocket(void);
	~LuaSocket(void);
	virtual bool onSubThreadStarted();
    virtual int onSubThreadLoop(std::vector<SocketData*>& messages);
    virtual void onSubThreadEnded();
	virtual void onUIThreadReceiveMessage(SocketData* msg);
	int openSocket(const char *ip,int poush);
	void sendSocket(LuaMsgBuffer& luaBuff);
	void closeSocket();
	void readThread();
	void waitCloseReadThread();
	bool runLuaFunc(const char* szFunName, CLuaParam * pInParam, int nInNum);
	void setMaxReadCount(int);
	void setCplusShowMsgID(bool);
private:
	bool ThreadSendMsg(SocketData* msg);
	lua_State *m_pLuaState;
	char m_ip[32];
	int m_port;
	int m_max_num;
	bool m_showMsgID;
	LuaSocketState m_SocketState;
	ProtocolPacker *m_protocolInst;
    friend class WsThreadHelper;
    WsThreadHelper* _wsHelper;
};
