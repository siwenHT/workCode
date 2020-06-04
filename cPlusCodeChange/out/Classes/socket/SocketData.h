#ifndef _SOCKETDATA_H_
#define _SOCKETDATA_H_
#include "vsdef.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
typedef enum{
	READ_DATA,
	WRITE_DATA,
	CONNECT_RET
} DATA_TYPE_E;
class SocketData : public Ref{
public:
	SocketData(int code ,int length,const char* buf,DATA_TYPE_E flag);
	~SocketData();
	char *m_buf;
	int m_len;
	DATA_TYPE_E m_flag;
public:
	char appearsRepresenting(long stores); 
	short trivialOmitIncidental(char oarguments); 
	std::string attemptsCompatibleOutput(long free,std::string show,bool table); 
	bool mubeThingsWidthDeveloped(char obvious,void * introductory); 
	void greatlyInstantiating(float adds); 
static	void * theyIgnoredItem(char insert); 
	unsigned short majorNumbersTyhave(std::string assumed,char asked,long patterns); 
private:
	long m_letsRemainNull;
	int m_eitherLanguageThemselves;
	short m_ofileFamilySubstring;
	char m_includeOlderWays;
	std::string m_happenExercisePrimary;
};
#endif
