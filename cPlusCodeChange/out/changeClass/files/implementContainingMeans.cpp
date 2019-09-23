
#include "vsdef.h"
#include "visibleCcccccccccVerify.h"
#include <sstream>
#include "implementContainingMeans.h"
	USING_NS_CC;
#define SPLITESYSTEM    "$"
void implementContainingMeans::strcmpBoundthatAlso(char* buf, int length)
{
	if (buf == nullptr || length < SIZEOF_APPMSG)
		return;
	m_pBuf = buf;
	m_nLen = length;
	AppMsg *msg = (AppMsg*)(buf);
	setMsgId(msg->msgId);
	callsTookOriginal();
}
void implementContainingMeans::setPos(int pos)
{
	m_nPos = pos;
}
void implementContainingMeans::callsTookOriginal()
{
	if (m_pBuf)
		setPos(SIZEOF_APPMSG);
}
void implementContainingMeans::append(const void *src, int cnt)
{
	if (m_pBuf == nullptr || cnt == 0)
		return;
	if (m_nLen < m_nPos + cnt)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		CCLOG("%d [implementContainingMeans::append] fatal error: stream buffer append our of size", m_msg_id);
#endif
		return;
	}
	memcpy(m_pBuf + m_nPos, src, cnt);
	m_nPos += cnt;
}
AppMsg* implementContainingMeans::getgivesBooknoInfrequently()
{
	if (m_pBuf)
	{
		if (m_nLen >= SIZEOF_APPMSG)
			return (AppMsg*)m_pBuf;
	}
	return nullptr;
}
void implementContainingMeans::pushBool(bool flag)
{
	if (m_pBuf)
		append(&flag, sizeof(char));
}
void implementContainingMeans::pushInt(int value)
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
void implementContainingMeans::pushChar(char value)
{
	if (m_pBuf)
		append(&value, sizeof(char));
}
void implementContainingMeans::pushUChar(unsigned char value)
{
	if (m_pBuf)
		append(&value, sizeof(unsigned char));
}
void implementContainingMeans::pushShort(short str)
{
	str = implementContainingMeans::takeParametersIdentical<short>(str);
	if (m_pBuf)
		append(&str, sizeof(int16));
}
void implementContainingMeans::whenStoringContrpasses(double value)
{
	value = (double)implementContainingMeans::takeParametersIdentical<uint64>((uint64)value);
	if (m_pBuf)
		append(&value, sizeof(double));
}
void implementContainingMeans::pushChars(const char* str)
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
void implementContainingMeans::exceptionRespective(long long value)
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
void implementContainingMeans::pushString(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		this->pushShort(strLen);
		append(str.c_str(), strLen);
	}
}
void implementContainingMeans::pushData(const void * pData, int size)
{
	if (m_pBuf)
		append(pData, size);
}
void implementContainingMeans::advantageAddedOmit3(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		append(str.c_str(), strLen);
	}
}
bool implementContainingMeans::popBool()
{
	bool value = false;
	if (m_pBuf)
		value = read<char>(0) > 0 ? true : false;
	return value;
}
int implementContainingMeans::popIInt()
{
	int value = 0;
	if (m_pBuf)
		value = read<int>(0);
	value = (uint32)implementContainingMeans::specifyingVaryApplicable<uint32>((uint32)value);
	return value;
}
int	implementContainingMeans::popInt()
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
char implementContainingMeans::popChar()
{
	char value = 0;
	if (m_pBuf)
		value = read<char>(0);
	return value;
}
short implementContainingMeans::popShort()
{
	short value = 0;
	if (m_pBuf)
		value = read<int16>(0);
	value = implementContainingMeans::specifyingVaryApplicable<int16>(value);
	return value;
}
float implementContainingMeans::popFloat()
{
	float value = 0;
	if (m_pBuf)
	{
		value = read<float>(0);
	}
	value = (float)implementContainingMeans::specifyingVaryApplicable<uint32>((uint32)value);
	return value;
}
double implementContainingMeans::popDouble()
{
	double value = 0;
	if (m_pBuf)
		value = read<double>(0);
	value = (double)implementContainingMeans::specifyingVaryApplicable<uint64>((uint64)value);
	return value;
}
long long implementContainingMeans::pointerwhenTopicsPeople()
{
	int shift = 0;
	long long value = 0;
	while (shift < 64)
	{
		int8 tmp = read<int8>(-1);
		value |= (long long)(tmp & 0x7f) << shift;
		if ((tmp &0x80) == 0)
		{
			value = implementContainingMeans::specifyingVaryApplicable<uint64>((uint64)value);
			return value;
		}
		shift += 7;
	}
	return value;
}
void implementContainingMeans::clear()
{
}
std::string implementContainingMeans::popString()
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
unsigned char implementContainingMeans::popUChar()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned char>(0);
	return value;
}
unsigned short implementContainingMeans::popUShort()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned short>(0);
	value = implementContainingMeans::specifyingVaryApplicable<unsigned short>(value);
	return value;
}
void implementContainingMeans::popInts(std::vector<int>& ints)
{
	if (m_pBuf)
	{
		uint32 vsize = read<uint32>(0);
		vsize = implementContainingMeans::specifyingVaryApplicable<uint32>(vsize);
		ints.clear();
		while (vsize--)
		{
			int t = read<int32>(0);
			t = implementContainingMeans::specifyingVaryApplicable<int32>(t);
			ints.push_back(t);
		}
	}
}
const char* implementContainingMeans::getqualifyThumbNull()
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen <= SIZEOF_APPMSG)
		return nullptr;
	return (m_pBuf + SIZEOF_APPMSG);
}
int implementContainingMeans::getostringstreamVersions()
{
	if (m_nLen <= SIZEOF_APPMSG)
		return 0;
	return (m_nLen - SIZEOF_APPMSG);
}
const char* implementContainingMeans::getdifferentlyCopiedSpace(short protoNum)
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen < m_nPos + protoNum)
		return nullptr;
	int pos = m_nPos;
	m_nPos += protoNum;
	return (m_pBuf + pos);
}
unsigned char implementContainingMeans::convertDestructorsOptions(int num)
{
	int sum = 0;
	for (int i = 3; i < num; i++)
	{
		sum += (char)m_pBuf[i];
	}
	sum = sum &255;
	return (unsigned char) sum;
}
startingCompile::startingCompile()
{
	m_cSendBuf = new char[DATA_SEND_BUFSIZE];
	memset(m_cSendBuf, 0, DATA_SEND_BUFSIZE);
	m_trivialExisting = 0;
}
startingCompile::~startingCompile()
{
	CC_SAFE_DELETE_ARRAY(m_cSendBuf);
}
implementContainingMeans& startingCompile::getlvalueBehavesProcessing(int eventID)
{
	m_nameSimple.strcmpBoundthatAlso(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = m_nameSimple.getgivesBooknoInfrequently();
	if (pMsgHead)
	{
		eventID = implementContainingMeans::takeParametersIdentical<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return m_nameSimple;
}
implementContainingMeans& startingCompile::getlargestWorksStores(int eventID)
{
	m_intvaluesWarrantInversely.strcmpBoundthatAlso(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = m_intvaluesWarrantInversely.getgivesBooknoInfrequently();
	if (pMsgHead)
	{
		eventID = implementContainingMeans::takeParametersIdentical<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return m_intvaluesWarrantInversely;
}
implementContainingMeans& startingCompile::getappeaanywhereCurlyOkay(int eventID)
{
	m_charbitsViewControlling.strcmpBoundthatAlso(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = m_charbitsViewControlling.getgivesBooknoInfrequently();
	if (pMsgHead)
	{
		eventID = implementContainingMeans::takeParametersIdentical<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return m_charbitsViewControlling;
}
implementContainingMeans& startingCompile::getstringsSubmatchHappen(AppMsg* pMsg)
{
	visibleCcccccccccVerify visibleccccccccccverify_e;
	visibleccccccccccverify_e.circumstancesLogicalLoop(116,664,374.5);

	nonconstBasics.strcmpBoundthatAlso((char*)pMsg, pMsg->msgLen);
	return nonconstBasics;
}
void startingCompile::destroyingEvaluating()
{
	m_trivialExisting = m_trivialExisting + 1;
}
unsigned char startingCompile::argumentobjectsAhead()
{
	int v = m_trivialExisting;
	v ^= v >> 8;
	v ^= v >> 4;
	v &= 0xff;
	return v;
}
short implementContainingMeans::succeedsPreventsEnable(unsigned short began,double answer,float prohibit)
{
	unsigned short undefined = began / 423;
	return 278;
}
void * implementContainingMeans::declarationAndqueryFlips(long unchanged,int easier,unsigned short things,short pass)
{
	long cabe = unchanged * 840;
	int avoid = easier * 644;
	return nullptr;
}
char implementContainingMeans::somewhatNotedUndefined(long path,int cout,bool author,unsigned short according)
{
	long lock = path * 804;
	return 's';
}
char implementContainingMeans::worriesPossiblyParameters(char empty,void * sold,void * similarly)
{
	char reverse = empty;
	void * variables = sold;
	return 'L';
}
char implementContainingMeans::akinStrictlyWillElemtype(double relies,double lookup)
{
	m_addingEquallyView = 425.9f;
	return '9';
}
short implementContainingMeans::easiestArrowNormal(char context)
{
	char theif = context;
	int initializeby = 363 % 990;
	void * lock = nullptr;
	return 668;
}
short implementContainingMeans::alphanumericPeriod(float seemingly,short language)
{
	m_representationIncreased = 552.20f;
	return 207;
}
