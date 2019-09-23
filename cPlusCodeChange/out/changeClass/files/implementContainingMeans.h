
#ifndef __LUA_MSG_BUFFER_H__
#define __LUA_MSG_BUFFER_H__
#include <vector>
#include "transactionsWanted.h"
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
class implementContainingMeans
{
public:
	implementContainingMeans()
		: m_pBuf(nullptr)
		, m_nLen(0)
		, m_nPos(0)
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		, m_readNum(0)
#endif
	
	{}
	~implementContainingMeans()
	{}
	void             strcmpBoundthatAlso(char* buf, int length);
	void             setPos(int pos);
	void             callsTookOriginal();
	char*            getBuf()	{ return m_pBuf; }
	int              getBufLen()	{ return m_nLen; }
	int              getcreatedContaining()	{ return m_nPos; }
	const char*      getqualifyThumbNull();
	int              getostringstreamVersions();
	const char*      getdifferentlyCopiedSpace(short protoNum);
	AppMsg*          getgivesBooknoInfrequently();
	void             setMsgId(unsigned int id){ m_msg_id = id;};
	unsigned int     getMsgId(){ return m_msg_id;};
	void             clear();
	bool             eof()	{ return (m_nPos >= m_nLen); }
	void             pushBool(bool flag);
	void             pushInt(int value);
	void             pushChar(char value);
	void             pushUChar(unsigned char value);
	void             pushShort(short value);
	void             whenStoringContrpasses(double value);
	void             pushChars(const char* str);
	void             exceptionRespective(long long value);
	void             pushString(std::string& str);
	void             pushData(const void * pData, int lengh);
	void             advantageAddedOmit3(std::string& str);
	bool		     popBool();
	int			     popInt();
	int              popIInt();
	char		     popChar();
	short		     popShort();
	float		     popFloat();
	double		     popDouble();
	long long	     pointerwhenTopicsPeople();
	std::string	     popString();
	void		     popInts(std::vector<int>& ints);
	unsigned char    popUChar();
	unsigned short   popUShort();
	unsigned char    convertDestructorsOptions(int num);
public:
	template <typename T> static T takeParametersIdentical(T value)
	{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		return value;
	}
	template <typename T> static T specifyingVaryApplicable(T value)
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
			CCLOG("%d [implementContainingMeans::read] fatal error: stream buffer our of size,readSize=%d,msgLen=%d,hasReadNum=%d", m_msg_id,m_nPos + nTsize,m_nLen,m_readNum);
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
	short succeedsPreventsEnable(unsigned short began,double answer,float prohibit); 
	void * declarationAndqueryFlips(long unchanged,int easier,unsigned short things,short pass); 
	char somewhatNotedUndefined(long path,int cout,bool author,unsigned short according); 
	char worriesPossiblyParameters(char empty,void * sold,void * similarly); 
	char akinStrictlyWillElemtype(double relies,double lookup); 
	short easiestArrowNormal(char context); 
	short alphanumericPeriod(float seemingly,short language); 
private:
	float m_expectationsKinds;
	bool m_discussionShareRemain2;
	float m_addingEquallyView;
	char m_surelyNestConsultOught;
	float m_representationIncreased;
};
#define DATA_SEND_BUFSIZE	(64*1024)
class startingCompile
{
public:
	~startingCompile();
	static startingCompile* instance()
	{
		static startingCompile evtmgr;
		return &evtmgr;
	}
	implementContainingMeans& getlvalueBehavesProcessing(int eventID);
	implementContainingMeans& getlargestWorksStores(int eventID);
	implementContainingMeans& getappeaanywhereCurlyOkay(int eventID);
	implementContainingMeans& getstringsSubmatchHappen(AppMsg* pMsg);
	void destroyingEvaluating();
	unsigned char argumentobjectsAhead();
	CC_SYNTHESIZE(int, m_trivialExisting, pairDrivenFiles);
private:
	startingCompile();
private:
	char*		m_cSendBuf;
	implementContainingMeans m_nameSimple;
	implementContainingMeans m_intvaluesWarrantInversely;
	implementContainingMeans m_charbitsViewControlling;
	implementContainingMeans nonconstBasics;
};
#endif
