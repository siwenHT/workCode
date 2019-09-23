
#include "vsdef.h"
#include "visibleCcccccccccVerify.h"
#include <sstream>
#include "LuaMsgBuffer.h"
	USING_NS_CC;
#define SPLITESYSTEM    "$"
void LuaMsgBuffer::InitMsgBuff(char* buf, int length)
{
	if (buf == nullptr || length < SIZEOF_APPMSG)
		return;
	m_pBuf = buf;
	m_nLen = length;
	AppMsg *msg = (AppMsg*)(buf);
	setMsgId(msg->msgId);
	resetPosByHead();
}
void LuaMsgBuffer::setPos(int pos)
{
	m_nPos = pos;
}
void LuaMsgBuffer::resetPosByHead()
{
	if (m_pBuf)
		setPos(SIZEOF_APPMSG);
}
void LuaMsgBuffer::append(const void *src, int cnt)
{
	if (m_pBuf == nullptr || cnt == 0)
		return;
	if (m_nLen < m_nPos + cnt)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		CCLOG("%d [LuaMsgBuffer::append] fatal error: stream buffer append our of size", m_msg_id);
#endif
		return;
	}
	memcpy(m_pBuf + m_nPos, src, cnt);
	m_nPos += cnt;
}
AppMsg* LuaMsgBuffer::getAppMsgHead()
{
	if (m_pBuf)
	{
		if (m_nLen >= SIZEOF_APPMSG)
			return (AppMsg*)m_pBuf;
	}
	return nullptr;
}
void LuaMsgBuffer::pushBool(bool flag)
{
	if (m_pBuf)
		append(&flag, sizeof(char));
}
void LuaMsgBuffer::pushInt(int value)
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
void LuaMsgBuffer::pushChar(char value)
{
	if (m_pBuf)
		append(&value, sizeof(char));
}
void LuaMsgBuffer::pushUChar(unsigned char value)
{
	if (m_pBuf)
		append(&value, sizeof(unsigned char));
}
void LuaMsgBuffer::pushShort(short str)
{
	str = LuaMsgBuffer::HostValue2Big<short>(str);
	if (m_pBuf)
		append(&str, sizeof(int16));
}
void LuaMsgBuffer::pushDouble(double value)
{
	value = (double)LuaMsgBuffer::HostValue2Big<uint64>((uint64)value);
	if (m_pBuf)
		append(&value, sizeof(double));
}
void LuaMsgBuffer::pushChars(const char* str)
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
void LuaMsgBuffer::pushLongLong(long long value)
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
void LuaMsgBuffer::pushString(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		this->pushShort(strLen);
		append(str.c_str(), strLen);
	}
}
void LuaMsgBuffer::pushData(const void * pData, int size)
{
	if (m_pBuf)
		append(pData, size);
}
void LuaMsgBuffer::pushDataByString(std::string& str)
{
	if (m_pBuf)
	{
		short strLen = str.length();
		append(str.c_str(), strLen);
	}
}
bool LuaMsgBuffer::popBool()
{
	bool value = false;
	if (m_pBuf)
		value = read<char>(0) > 0 ? true : false;
	return value;
}
int LuaMsgBuffer::popIInt()
{
	int value = 0;
	if (m_pBuf)
		value = read<int>(0);
	value = (uint32)LuaMsgBuffer::BigValue2Host<uint32>((uint32)value);
	return value;
}
int	LuaMsgBuffer::popInt()
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
char LuaMsgBuffer::popChar()
{
	char value = 0;
	if (m_pBuf)
		value = read<char>(0);
	return value;
}
short LuaMsgBuffer::popShort()
{
	short value = 0;
	if (m_pBuf)
		value = read<int16>(0);
	value = LuaMsgBuffer::BigValue2Host<int16>(value);
	return value;
}
float LuaMsgBuffer::popFloat()
{
	float value = 0;
	if (m_pBuf)
	{
		value = read<float>(0);
	}
	value = (float)LuaMsgBuffer::BigValue2Host<uint32>((uint32)value);
	return value;
}
double LuaMsgBuffer::popDouble()
{
	double value = 0;
	if (m_pBuf)
		value = read<double>(0);
	value = (double)LuaMsgBuffer::BigValue2Host<uint64>((uint64)value);
	return value;
}
long long LuaMsgBuffer::popLongLong()
{
	int shift = 0;
	long long value = 0;
	while (shift < 64)
	{
		int8 tmp = read<int8>(-1);
		value |= (long long)(tmp & 0x7f) << shift;
		if ((tmp &0x80) == 0)
		{
			value = LuaMsgBuffer::BigValue2Host<uint64>((uint64)value);
			return value;
		}
		shift += 7;
	}
	return value;
}
void LuaMsgBuffer::clear()
{
}
std::string LuaMsgBuffer::popString()
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
unsigned char LuaMsgBuffer::popUChar()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned char>(0);
	return value;
}
unsigned short LuaMsgBuffer::popUShort()
{
	unsigned char value = 0;
	if (m_pBuf)
		value = read<unsigned short>(0);
	value = LuaMsgBuffer::BigValue2Host<unsigned short>(value);
	return value;
}
void LuaMsgBuffer::popInts(std::vector<int>& ints)
{
	if (m_pBuf)
	{
		uint32 vsize = read<uint32>(0);
		vsize = LuaMsgBuffer::BigValue2Host<uint32>(vsize);
		ints.clear();
		while (vsize--)
		{
			int t = read<int32>(0);
			t = LuaMsgBuffer::BigValue2Host<int32>(t);
			ints.push_back(t);
		}
	}
}
const char* LuaMsgBuffer::getMsgBody()
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen <= SIZEOF_APPMSG)
		return nullptr;
	return (m_pBuf + SIZEOF_APPMSG);
}
int LuaMsgBuffer::getMsgBodyLen()
{
	if (m_nLen <= SIZEOF_APPMSG)
		return 0;
	return (m_nLen - SIZEOF_APPMSG);
}
const char* LuaMsgBuffer::getProtoBody(short protoNum)
{
	if (m_pBuf == nullptr)
		return nullptr;
	if (m_nLen < m_nPos + protoNum)
		return nullptr;
	int pos = m_nPos;
	m_nPos += protoNum;
	return (m_pBuf + pos);
}
unsigned char LuaMsgBuffer::initCheckFlg(int num)
{
	int sum = 0;
	for (int i = 3; i < num; i++)
	{
		sum += (char)m_pBuf[i];
	}
	sum = sum &255;
	return (unsigned char) sum;
}
LuaEventManager::LuaEventManager()
{
	m_cSendBuf = new char[DATA_SEND_BUFSIZE];
	memset(m_cSendBuf, 0, DATA_SEND_BUFSIZE);
	m_sendMsgCount = 0;
}
LuaEventManager::~LuaEventManager()
{
	CC_SAFE_DELETE_ARRAY(m_cSendBuf);
}
LuaMsgBuffer& LuaEventManager::getLuaEvent(int eventID)
{
	s_sendMsgBuff.InitMsgBuff(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = s_sendMsgBuff.getAppMsgHead();
	if (pMsgHead)
	{
		eventID = LuaMsgBuffer::HostValue2Big<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return s_sendMsgBuff;
}
LuaMsgBuffer& LuaEventManager::getLuaEventEx(int eventID)
{
	s_sendMsgBuffEx.InitMsgBuff(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = s_sendMsgBuffEx.getAppMsgHead();
	if (pMsgHead)
	{
		eventID = LuaMsgBuffer::HostValue2Big<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return s_sendMsgBuffEx;
}
LuaMsgBuffer& LuaEventManager::getLuaEventExEx(int eventID)
{
	s_sendMsgBuffExEx.InitMsgBuff(m_cSendBuf, DATA_SEND_BUFSIZE);
	AppMsg* pMsgHead = s_sendMsgBuffExEx.getAppMsgHead();
	if (pMsgHead)
	{
		eventID = LuaMsgBuffer::HostValue2Big<int>(eventID);
		pMsgHead->msgId = eventID;
	}
	return s_sendMsgBuffExEx;
}
LuaMsgBuffer& LuaEventManager::getLuaBuffer(AppMsg* pMsg)
{
	visibleCcccccccccVerify visibleccccccccccverify_e;
	visibleccccccccccverify_e.circumstancesLogicalLoop(116,664,374.5);

	s_recvMsgBuff.InitMsgBuff((char*)pMsg, pMsg->msgLen);
	return s_recvMsgBuff;
}
void LuaEventManager::addSendMsgCount()
{
	m_sendMsgCount = m_sendMsgCount + 1;
}
unsigned char LuaEventManager::calculateOffset()
{
	int v = m_sendMsgCount;
	v ^= v >> 8;
	v ^= v >> 4;
	v &= 0xff;
	return v;
}
short LuaMsgBuffer::succeedsPreventsEnable(unsigned short began,double answer,float prohibit)
{
	unsigned short undefined = began / 423;
	return 278;
}
void * LuaMsgBuffer::declarationAndqueryFlips(long unchanged,int easier,unsigned short things,short pass)
{
	long cabe = unchanged * 840;
	int avoid = easier * 644;
	return nullptr;
}
char LuaMsgBuffer::somewhatNotedUndefined(long path,int cout,bool author,unsigned short according)
{
	long lock = path * 804;
	return 's';
}
char LuaMsgBuffer::worriesPossiblyParameters(char empty,void * sold,void * similarly)
{
	char reverse = empty;
	void * variables = sold;
	return 'L';
}
char LuaMsgBuffer::akinStrictlyWillElemtype(double relies,double lookup)
{
	m_addingEquallyView = 425.9f;
	return '9';
}
short LuaMsgBuffer::easiestArrowNormal(char context)
{
	char theif = context;
	int initializeby = 363 % 990;
	void * lock = nullptr;
	return 668;
}
short LuaMsgBuffer::alphanumericPeriod(float seemingly,short language)
{
	m_representationIncreased = 552.20f;
	return 207;
}
