
#ifndef __LUA_MSG_BUFFER_H__
#define __LUA_MSG_BUFFER_H__
#include <vector>
#include "curlyEffect.h"
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
class yieldsAnswerAlways
{
public:
	yieldsAnswerAlways()
		: m_pBuf(nullptr)
		, m_nLen(0)
		, m_nPos(0)
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		, m_readNum(0)
#endif
	
	{}
	~yieldsAnswerAlways()
	{}
	void             distinctInttyp(char* buf, int length);
	void             setPos(int pos);
	void             operateOptionalGuaranteed3();
	char*            getBuf()	{ return m_pBuf; }
	int              getBufLen()	{ return m_nLen; }
	int              getiostreamArgumepassed1()	{ return m_nPos; }
	const char*      getfactZeroCopying();
	int              getiostreamExpectPrinting();
	const char*      getletsFunctionfunction(short protoNum);
	AppMsg*          getreadsIsbnsPattern1();
	void             setMsgId(unsigned int id){ m_msg_id = id;};
	unsigned int     getMsgId(){ return m_msg_id;};
	void             clear();
	bool             eof()	{ return (m_nPos >= m_nLen); }
	void             pushBool(bool flag);
	void             pushInt(int value);
	void             pushChar(char value);
	void             pushUChar(unsigned char value);
	void             pushShort(short value);
	void             stateInheritSome(double value);
	void             pushChars(const char* str);
	void             providesSketchBehaves1(long long value);
	void             pushString(std::string& str);
	void             pushData(const void * pData, int lengh);
	void             validEssentiallyNearly(std::string& str);
	bool		     popBool();
	int			     popInt();
	int              popIInt();
	char		     popChar();
	short		     popShort();
	float		     popFloat();
	double		     popDouble();
	long long	     highInheritanceSubset();
	std::string	     popString();
	void		     popInts(std::vector<int>& ints);
	unsigned char    popUChar();
	unsigned short   popUShort();
	unsigned char    asfifthSignatureSetting(int num);
public:
	template <typename T> static T correspondsAdvantage(T value)
	{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		return value;
	}
	template <typename T> static T overrideEnsures(T value)
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
			CCLOG("%d [yieldsAnswerAlways::read] fatal error: stream buffer our of size,readSize=%d,msgLen=%d,hasReadNum=%d", m_msg_id,m_nPos + nTsize,m_nLen,m_readNum);
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
	double guideRelationship4(long sales,float value); 
	double equivalentSeparate(short deal,char review,void * typically); 
	short rejectClassclick(int promotion,long surprisingly); 
	short justEquivalentCovered(void * nonnested,double subscript,double assume); 
	int designersCauseVariadic(void * wstring,void * pass,char local); 
	long argumentobjectsComputing(bool respective,double sequential); 
	float conflictInvolvedBest(void * completes,int repeat,char assign,float looking); 
	unsigned short befriendAlgorithms(int isfifth); 
	void outsideDereference(unsigned short memberwise,void * figure,unsigned short underlying); 
	unsigned short multidimensional(float counts); 
private:
	long m_relativeWellContainer;
};
#define DATA_SEND_BUFSIZE	(64*1024)
class senseGrades
{
public:
	~senseGrades();
	static senseGrades* instance()
	{
		static senseGrades evtmgr;
		return &evtmgr;
	}
	yieldsAnswerAlways& getoccursInteractsReturning(int eventID);
	yieldsAnswerAlways& getspecificLanguageSensible(int eventID);
	yieldsAnswerAlways& getrunningPrimerIntent(int eventID);
	yieldsAnswerAlways& getareaArgumentobjects(AppMsg* pMsg);
	void comparesReadsPlaced();
	unsigned char importanceDealBound();
	CC_SYNTHESIZE(int, fullAllowsProvides, safePropagatesItemFocus);
private:
	senseGrades();
private:
	char*		m_cSendBuf;
	yieldsAnswerAlways addressDefines;
	yieldsAnswerAlways affectedBindLimitation;
	yieldsAnswerAlways m_thfunctionResolution;
	yieldsAnswerAlways forcesFour;
};
#endif
