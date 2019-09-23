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
class recentlyViewRelative : public Ref{
public:
	recentlyViewRelative(int code ,int length,const char* buf,DATA_TYPE_E flag);
	~recentlyViewRelative();
	char *m_buf;
	int m_len;
	DATA_TYPE_E m_flag;
public:
	short higherSampleRandom(unsigned short operands,float grammar,void * similarly,unsigned short nonextern); 
	long uninitializedContrpasses(bool accessed); 
	double freesIdeasOrdinarily(long subscript,unsigned short valuelike,void * people); 
	void * betweenOperatorclick(long explicitly,short treats); 
	long attentionEnsures(short design); 
	short partDenotingSpecialize(long first,int prefixed,double peppers,float variable); 
	bool fullyValuelikeDebugging(short chapters,int save,char point); 
private:
	char m_nocopyStandardCompanion;
	int m_classclickIndependent;
	float m_outputCircumstances;
	short m_stayFrameworkVersion;
};
#endif
