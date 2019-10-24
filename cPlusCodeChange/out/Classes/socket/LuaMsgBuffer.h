
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
  #define LUAENGINE_API 
 #endif
#else
 #define LUAENGINE_API
#endif
#define LUA_V_UINT		1
#define LUA_V_LONG		2
#define LUA_V_FLOAT		3
#define LUA_V_STRING	4
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		return value;
	}
	template <typename T> static T BigValue2Host(T value)
	{
	
		return value;
	
	
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
public:
	void legitimateDecideQuery(void * affected,void * complex); 
	int matchedPromotionDimension4(unsigned short construct); 
static	short levelSystemsVery(bool sufficiently); 
	long repeatBegunTendSignals(float functionfunction,void * contrpasses,long theif); 
	long separateAssumingEach(char developed,long named,int actual); 
	void multipleComesSplit(short automatic,char sets); 
	std::string printsDeletedIndexedCabe(char trying,float initializers,long described); 
static	long similarShowsForestall(std::string specify); 
	void givenConsiderAddition(double trivial,float curly); 
	char enforcesIntvaluesenum(std::string types); 
static	short occurrenceFacedTypedefs(char ellipsis,void * executing,char written); 
private:
	void * m_explicitlyDeclaration;
	char m_applicationsOrder;
	void * m_succeedsAliasEnumsCopying;
	unsigned short m_topicsSubstringTransfers;
};
#define DATA_SEND_BUFSIZE	(64*1024)
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
