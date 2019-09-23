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
	PARAM_DATATYPE_NONE = -1,			/// LUA_TNONE
	PARAM_DATATYPE_NIL = 0,				/// LUA_TNIL
	PARAM_DATATYPE_BOOLEAN = 1,			/// LUA_TBOOLEAN
	PARAM_DATATYPE_LIGHTUSERDATA = 2,	/// LUA_TLIGHTUSERDATA
	PARAM_DATATYPE_NUMBER = 3,			/// LUA_TNUMBER
	PARAM_DATATYPE_STRING =	4,			/// LUA_TSTRING
	PARAM_DATATYPE_TABLE = 5,			/// LUA_TTABLE
	PARAM_DATATYPE_FUNCTION = 6,		/// LUA_TFUNCTION
	PARAM_DATATYPE_USERDATA	= 7,		/// LUA_TUSERDATA
	PARAM_DATATYPE_THREAD = 8,			/// LUA_TTHREAD
};

class WsThreadHelper;

/// Lua参数
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
	/// 数据类型
	int	m_nDataType;
	char m_szValue[8];	
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
	int openSocket(const char *ip,int poush);//打开socket服务器
	void sendSocket(LuaMsgBuffer& luaBuff);//
	void closeSocket();//关闭服务器
	//void update(float delta);
	//void sendThread();
	void readThread();
	void waitCloseReadThread();
	//void connectThread();
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
	LuaSocketState m_SocketState;	// LuaSocketState
	ProtocolPacker *m_protocolInst;
	
    friend class WsThreadHelper;
    WsThreadHelper* _wsHelper;
};

