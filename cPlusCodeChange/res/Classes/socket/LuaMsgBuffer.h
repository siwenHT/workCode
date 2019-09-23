/************************************************************************/
/* filename：LuaMsgBuffer.h                                             */
/*																		*/
/* desc：和lua交互的缓冲区，主要是table协议的支持						*/
/************************************************************************/

#ifndef __LUA_MSG_BUFFER_H__
#define __LUA_MSG_BUFFER_H__
#include <vector>
#include "ByteBuffer.h"

extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#ifdef WIN32
 #ifdef LUAENGINE_EXPORTS
  #define LUAENGINE_API __declspec(dllexport)
 #else
  #define LUAENGINE_API //__declspec(dllimport)
 #endif
#else
 #define LUAENGINE_API
#endif

#define LUA_V_UINT		1
#define LUA_V_LONG		2
#define LUA_V_FLOAT		3
#define LUA_V_STRING	4

//----------------------------------------------------------
//发送C-RPC事件的缓冲区
//----------------------------------------------------------
class LuaMsgBuffer
{
public:
	LuaMsgBuffer()
		: m_pBuf(nullptr)
		, m_nLen(0)
		, m_nPos(0)
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		, m_readNum(0)
#endif
		//, m_msg_remType(-1)
	{}

	~LuaMsgBuffer()
	{}

	void             InitMsgBuff(char* buf, int length);
	void             setPos(int pos);
	void             resetPosByHead();
	char*            getBuf()	{ return m_pBuf; }
	int              getBufLen()	{ return m_nLen; }
	int              getSendBufLen()	{ return m_nPos; }
	const char*      getMsgBody();
	int              getMsgBodyLen();
	const char*      getProtoBody(short protoNum);
	AppMsg*          getAppMsgHead();
	void             setMsgId(unsigned int id){ m_msg_id = id;};
	unsigned int     getMsgId(){ return m_msg_id;};
	void             clear();
	bool             eof()	{ return (m_nPos >= m_nLen); }
	void             pushBool(bool flag);
	void             pushInt(int value);
	void             pushChar(char value);
	void             pushUChar(unsigned char value);
	void             pushShort(short value);
	void             pushDouble(double value);
	void             pushChars(const char* str);
	void             pushLongLong(long long value);
	void             pushString(std::string& str);
	void             pushData(const void * pData, int lengh);
	void             pushDataByString(std::string& str);
	bool		     popBool();
	int			     popInt();
	int              popIInt();
	char		     popChar();
	short		     popShort();
	float		     popFloat();
	double		     popDouble();
	long long	     popLongLong();
	std::string	     popString();
	void		     popInts(std::vector<int>& ints);
	unsigned char    popUChar();
	unsigned short   popUShort();

	unsigned char    initCheckFlg(int num);

public:
	template <typename T> static T HostValue2Big(T value)
	{
		//int sizeNum = sizeof(T);
		//
		//switch (sizeNum)
		//{
		//	case 1:
		//		break;
		//	case 2:
		//		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP16((uint16)value);
		//		break;
		//	case 4:
		//		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP32((uint32)value);
		//		break;
		//	case 8:
		//		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP64((uint64)value);
		//		break;
		//	default:
		//		break;
		//}
		
		return value;
	}
	template <typename T> static T BigValue2Host(T value)
	{
		//服务器发过来小端数据
		return value;
		//return HostValue2Big<T>(value);
		/*int sizeNum = sizeof(T);

		switch (sizeNum)
		{
		case 1:
		break;
		case 2:
		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP16(value);
		break;
		case 4:
		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP32(value);
		break;
		case 8:
		value = (CC_HOST_IS_BIG_ENDIAN == true)? (value):CC_SWAP64(value);
		break;
		default:
		break;
		}

		return value;*/
	}
protected:	
	void append(const void *src, int cnt);

	template <typename T> T read(T def, bool needRecode = true)
	{
		if (m_pBuf == nullptr || m_nLen == 0)
			return def;

		int nTsize = sizeof(T);
		if (m_nPos + nTsize > m_nLen)
		{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
			CCLOG("%d [LuaMsgBuffer::read] fatal error: stream buffer our of size,readSize=%d,msgLen=%d,hasReadNum=%d", m_msg_id,m_nPos + nTsize,m_nLen,m_readNum);
#endif
			return def;
		}

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		if (needRecode)
			m_readNum += 1;
#endif
		int pos = m_nPos;
		m_nPos += nTsize;
		return *((T*)(m_pBuf + pos));
	}
	unsigned int m_msg_id;

	char*	     m_pBuf;
	int		     m_nLen;
	int		     m_nPos;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	int          m_readNum;
#endif
};


#define DATA_SEND_BUFSIZE	(64*1024)

//----------------------------------------------------------
//发送C-RPC事件的管理器
//----------------------------------------------------------
class LuaEventManager
{
public:	
	~LuaEventManager();
	static LuaEventManager* instance()
	{
		static LuaEventManager evtmgr;
		return &evtmgr;
	}

	LuaMsgBuffer& getLuaEvent(int eventID);
	LuaMsgBuffer& getLuaEventEx(int eventID);
	LuaMsgBuffer& getLuaEventExEx(int eventID);
	LuaMsgBuffer& getLuaBuffer(AppMsg* pMsg);

	void addSendMsgCount();
	unsigned char calculateOffset();
	CC_SYNTHESIZE(int, m_sendMsgCount, SendMsgCount);

private:
	LuaEventManager();

private:
	char*		m_cSendBuf;

	LuaMsgBuffer s_sendMsgBuff;
	LuaMsgBuffer s_sendMsgBuffEx;
	LuaMsgBuffer s_sendMsgBuffExEx;
	LuaMsgBuffer s_recvMsgBuff;
};
#endif


