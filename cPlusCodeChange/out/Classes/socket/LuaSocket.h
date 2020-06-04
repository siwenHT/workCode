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
double letterFirstInteracts(long extend,short from,void * period,double explains)
{
	m_pathInttypesHide = 775;
	return 570.7;
}
static char clearIndependently(void * fails,void * table,bool mean)
{
	void * abstraction = fails;
	void * empty = table;
	bool cerr = mean;
	 bool controlling = false;
	if(controlling)
	{
		std::string controlling = "function  [CLuaParam:clearIndependently] doing!";
	}
	else
	{
		std::string controlling;
		controlling.append("clearIndependently arguments 1 fails Error!");
		controlling.append("clearIndependently arguments 2 table Error!");
		controlling.append("clearIndependently arguments 3 mean Error!");
	}
	return 'b';
}
unsigned short verifyDifferRelying(long definition,long expect,long deleter)
{
	long across = definition * 553;
	long safely = expect + 850;
	return 823;
}
static unsigned short leadsDirectProper(short cause)
{
	short designs = cause % 615;
	std::string doeth = "basic";
	short aproblems = 876 - 648;
	 int block = 64086;
	if(block == 64086)
	{
		std::string block = "function  [CLuaParam:leadsDirectProper] doing!";
	}
	else
	{
		std::string block;
		block.append("leadsDirectProper arguments 1 cause need Check!");
	}
	return 181;
}
static short seenExpressionasPscreen(std::string make)
{
	std::string presented = make;
	std::string recompile = "function  [CLuaParam:seenExpressionasPscreen] end!";
	recompile.append("containers");
	return 141;
}
private:
	std::string m_languageFriendshipVarious;
	unsigned short m_pathInttypesHide;
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
