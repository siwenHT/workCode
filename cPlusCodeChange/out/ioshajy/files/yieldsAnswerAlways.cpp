
#include "vsdef.h"
#include <sstream>
#include "yieldsAnswerAlways.h"
	USING_NS_CC;
#define SPLITESYSTEM    "$"
void yieldsAnswerAlways::distinctInttyp(char* buf, int length)
{
	if (buf == nullptr || length < SIZEOF_APPMSG)
		return;
	m_pBuf = buf;
	m_nLen = length;
	AppMsg *msg = (AppMsg*)(buf);
	setMsgId(msg->msgId);
	operateOptionalGuaranteed3();
}
void yieldsAnswerAlways::setPos(int pos)
{
	m_nPos = pos;
}
void yieldsAnswerAlways::operateOptionalGuaranteed3()
{
	if (m_pBuf)
		setPos(SIZEOF_APPMSG);
}
void yieldsAnswerAlways::append(const void *src, int cnt)
{
	if (m_pBuf == nullptr || cnt == 0)
		return;
	if (m_nLen < m_nPos + cnt)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		CCLOG("%d [yieldsAnswerAlways::append] fatal error: stream buffer append our of size", m_msg_id);
#endif
		return;
	}
	memcpy(m_pBuf + m_nPos, src, cnt);
	m_nPos += cnt;
}
AppMsg* yieldsAnswerAlways::getreadsIsbnsPattern1()
{
	if (m_pBuf)
	{
		if (m_nLen >= SIZEOF_APPMSG)
			return (AppMsg*)m_pBuf;
	}
	return nullptr;
}
void yieldsAnswerAlways::pushBool(bool flag)
{
	if (m_pBuf)
		append(&flag, sizeof(char));
}
void yieldsAnswerAlways::pushInt(int value)
{
	if (m_pBuf)
	{
	
		while (true)
		{
			if ((value & ~0x7f) == 0)
			{
				append(&value,sizeof(char));
				return;
			}
			else
			{
				char tmp = ((char) value &0x7f)|0x80;
				append(&tmp,sizeof(char));
				value =(0x0|value)>>7;
			}
		}
	}
}
void yieldsAnswerAlways::pushChar(char value)
{
	if (m_pBuf)
		append(&value, sizeof(char));
}
void yieldsAnswerAlways::pushUChar(unsigned char value)
{
	if (m_pBuf)
		append(&value, sizeof(unsigned char));
}
void yieldsAnswerAlways::pushShort(short str)
{
	str = yieldsAnswerAlways::correspondsAdvantage<short>(str);
	if (m_pBuf)
		append(&str, sizeof(int16));
}
void yieldsAnswerAlways::stateInheritSome(double value)
{
	value = (double)yieldsAnswerAlways::correspondsAdvantage<uint64>((uint64)value);
	if (m_pBuf)
		append(&value, sizeof(double));
}
void yieldsAnswerAlways::pushChars(const char* str)
{
	if (m_pBuf)
	{
		if (str)
		{
			append(str, str ? strlen(str) : 0);
		}
		uint8 end = 0;
		append(&end, sizeof(uint8));
	}
}
void yieldsAnswerAlways::providesSketchBehaves1(long long value)
{
	if (m_pBuf)
	{
		while (true)
		{
			if ((value & ~0x7f) == 0)
			{
				append(&value, sizeof(char));
				return;
			}
			else
			{
				char tmp = ((char) value &0x7f)|0x80;
				append(&tmp,sizeof(char));
				value =(0x0|value)>>7;
			}
		}
	}
}
void yieldsAnswerAlways::pushString(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		this->pushShort(strLen);
		append(str.c_str(), strLen);
	}
}
void yieldsAnswerAlways::pushData(const void * pData, int size)
{
	if (m_pBuf)
		append(pData, size);
}
void yieldsAnswerAlways::validEssentiallyNearly(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		append(str.c_str(), strLen);
	}
}
bool yieldsAnswerAlways::popBool()
{
	bool value = false;
	if (m_pBuf)
		value = read<char>(0) > 0 ? true : false;
	return value;
}
int yieldsAnswerAlways::popIInt()
{
	int value = 0;
	if (m_pBuf)
		value = read<int>(0);
	value = (uint32)yieldsAnswerAlways::overrideEnsures<uint32>((uint32)value);
	return value;
}
int	yieldsAnswerAlways::popInt()
{
	int value = 0;
	if (m_pBuf)
	{
		char tmp = read<int8>(0);
		if (tmp >= 0)
		{
			value = (int)tmp;
			return value;
		}
		value = tmp &0x7f;
		if ((tmp = read<int8>(0)) >=0)
		{
			value |= tmp << 7;
		}
		else 
		{
			value |= (tmp&0x7f) <<7;
			if ((tmp = read<int8>(-1))>=0)
			{
				value |= tmp<<14;
			}
			else
			{
				value |= (tmp&0x7f)<<14;
				if ((tmp = read<int8>(-1))>=0)
				{
					value |= tmp<<21;
				}
				else
				{
					value |= (tmp&0x7f)<<21;
					value |= (tmp = read<int8>(-1))<<28;
					if (tmp < 0)
					{
						for (int i = 0; i < 5 ; i++)
						{
							if (read<int>(-1) >= 0)
							{
								return value;
							}
						}
					}
				}
			}
		}
		return value;
	}
}
char yieldsAnswerAlways::popChar()
{
	char value = 0;
	if (m_pBuf)
		value = read<char>(0);
	return value;
}
short yieldsAnswerAlways::popShort()
{
	short value = 0;
	if (m_pBuf)
		value = read<int16>(0);
	value = yieldsAnswerAlways::overrideEnsures<int16>(value);
	return value;
}
float yieldsAnswerAlways::popFloat()
{
	float value = 0;
	if (m_pBuf)
	{
		value = read<float>(0);
	}
	value = (float)yieldsAnswerAlways::overrideEnsures<uint32>((uint32)value);
	return value;
}
double yieldsAnswerAlways::popDouble()
{
	double value = 0;
	if (m_pBuf)
		value = read<double>(0);
	value = (double)yieldsAnswerAlways::overrideEnsures<uint64>((uint64)value);
	return value;
}
long long yieldsAnswerAlways::highInheritanceSubset()
{
	int shift = 0;
	long long value = 0;
	while (shift < 64)
	{
		int8 tmp = read<int8>(-1);
		value |= (long long)(tmp & 0x7f) << shift;
		if ((tmp &0x80) == 0)
		{
			value = yieldsAnswerAlways::overrideEnsures<uint64>((uint64)value);
			return value;
		}
		shift += 7;
	}
	return value;
}
void yieldsAnswerAlways::clear()
{
}
std::string yieldsAnswerAlways::popString()
{
	std::string str;
	if (m_pBuf)
	{
		short len = read<short>(0, false);
	
		for (short i = 0; i < len; ++i)
		{
			char c = read<char>(0, false);
			str += c;
		}
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		m_readNum += 1;
#endif
	}
	return str;
}
unsigned char yieldsAnswerAlways::popUChar()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned char>(0);
	return value;
}
unsigned short yieldsAnswerAlways::popUShort()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned short>(0);
	value = yieldsAnswerAlways::overrideEnsures<unsigned short>(value);
	return value;
}
void yieldsAnswerAlways::popInts(std::vector<int>& ints)
{
	if (m_pBuf)
	{
		uint32 vsize = read<uint32>(0);
		vsize = yieldsAnswerAlways::overrideEnsures<uint32>(vsize);
		ints.clear();
		while (vsize--)
		{
			int t = read<int32>(0);
			t = yieldsAnswerAlways::overrideEnsures<int32>(t);
			ints.push_back(t);
		}
	}
}
const char* yieldsAnswerAlways::getfactZeroCopying()
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen <= SIZEOF_APPMSG)
		return nullptr;
	return (m_pBuf + SIZEOF_APPMSG);
}
int yieldsAnswerAlways::getiostreamExpectPrinting()
{
	if (m_nLen <= SIZEOF_APPMSG)
		return 0;
	return (m_nLen - SIZEOF_APPMSG);
}
const char* yieldsAnswerAlways::getletsFunctionfunction(short protoNum)
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen < m_nPos + protoNum)
		return nullptr;
	int pos = m_nPos;
	m_nPos += protoNum;
	return (m_pBuf + pos);
}
unsigned char yieldsAnswerAlways::asfifthSignatureSetting(int num)
{
	int sum = 0;
	for (int i = 3; i < num; i++)
	{
		sum += (char)m_pBuf[i];
	}
	sum = sum &255;
	return (unsigned char) sum;
}
senseGrades::senseGrades()
{
	m_cSendBuf = new char[DATA_SEND_BUFSIZE];
	memset(m_cSendBuf, 0, DATA_SEND_BUFSIZE);
	fullAllowsProvides = 0;
}
senseGrades::~senseGrades()
{
	CC_SAFE_DELETE_ARRAY(m_cSendBuf);
}
yieldsAnswerAlways& senseGrades::getoccursInteractsReturning(int eventID)
{
	addressDefines.distinctInttyp(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = addressDefines.getreadsIsbnsPattern1();
	if (pMsgHead)
	{
		eventID = yieldsAnswerAlways::correspondsAdvantage<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return addressDefines;
}
yieldsAnswerAlways& senseGrades::getspecificLanguageSensible(int eventID)
{
	affectedBindLimitation.distinctInttyp(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = affectedBindLimitation.getreadsIsbnsPattern1();
	if (pMsgHead)
	{
		eventID = yieldsAnswerAlways::correspondsAdvantage<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return affectedBindLimitation;
}
yieldsAnswerAlways& senseGrades::getrunningPrimerIntent(int eventID)
{
	m_thfunctionResolution.distinctInttyp(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = m_thfunctionResolution.getreadsIsbnsPattern1();
	if (pMsgHead)
	{
		eventID = yieldsAnswerAlways::correspondsAdvantage<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return m_thfunctionResolution;
}
yieldsAnswerAlways& senseGrades::getareaArgumentobjects(AppMsg* pMsg)
{
	forcesFour.distinctInttyp((char*)pMsg, pMsg->msgLen);
	return forcesFour;
}
void senseGrades::comparesReadsPlaced()
{
	fullAllowsProvides = fullAllowsProvides + 1;
}
unsigned char senseGrades::importanceDealBound()
{
	int v = fullAllowsProvides;
	v ^= v >> 8;
	v ^= v >> 4;
	v &= 0xff;
	return v;
}
double yieldsAnswerAlways::guideRelationship4(long sales,float value)
{
	float kids;
	kids = 746.11f;
	char complexities;
	complexities = '3';
	char bitvec;
	bitvec = 'E';
	return 967.0;
}
double yieldsAnswerAlways::equivalentSeparate(short deal,char review,void * typically)
{
	void * mismatched;
	mismatched = nullptr;
	return 193.7;
}
short yieldsAnswerAlways::rejectClassclick(int promotion,long surprisingly)
{
	double operations;
	operations = 496.14;
	unsigned short letters;
	letters = 148;
	double differs;
	differs = 361.14;
	unsigned short temporaries;
	temporaries = 823;
	return 188;
}
short yieldsAnswerAlways::justEquivalentCovered(void * nonnested,double subscript,double assume)
{
	char instantiations;
	instantiations = 'Z';
	return 562;
}
int yieldsAnswerAlways::designersCauseVariadic(void * wstring,void * pass,char local)
{
	void * redeclares;
	redeclares = nullptr;
	float precedence;
	precedence = 497.6f;
	return 775;
}
long yieldsAnswerAlways::argumentobjectsComputing(bool respective,double sequential)
{
	char swapped;
	swapped = 'C';
	long eyes;
	eyes = 931;
	long computing;
	computing = 75;
	double partial;
	partial = 709.16;
	return 999;
}
float yieldsAnswerAlways::conflictInvolvedBest(void * completes,int repeat,char assign,float looking)
{
	long mark;
	mark = 757;
	long synonym;
	synonym = 766;
	long threed;
	threed = 911;
	long operation;
	operation = 993;
	return 181.13f;
}
unsigned short yieldsAnswerAlways::befriendAlgorithms(int isfifth)
{
	float specifed;
	specifed = 345.9f;
	double require;
	require = 340.5;
	return 106;
}
void yieldsAnswerAlways::outsideDereference(unsigned short memberwise,void * figure,unsigned short underlying)
{
	unsigned short expect;
	expect = 669;
}
unsigned short yieldsAnswerAlways::multidimensional(float counts)
{
	void * covering;
	covering = nullptr;
	return 103;
}
