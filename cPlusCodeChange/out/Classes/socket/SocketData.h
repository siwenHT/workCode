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
	int iandBraceTell(unsigned short typeinfo); 
	std::string correspondReliesHard3(std::string exercises,float adds,std::string becomes); 
	std::string swapPassIntuitive(unsigned short learn,void * common); 
	double makingPrintedBookstore(std::string efficient,void * initializeby); 
	bool sameProcessRevised(bool redefinition); 
	void * ignoredSupportsLoops(void * calculate,float table,short nonmember,char replaces); 
	void ideasPurposesFactorial(char surprising,unsigned short context,void * charactershaving); 
	int insteadInvolveDifference5(unsigned short deletes,long leaving,int imageth); 
	void * studyPurposesEither(int referenparameter,bool supplies,void * instantiate); 
	unsigned short completelySeenCompiling(std::string sequence,long minimize,bool typeids); 
private:
	double m_exampleRuleSuited;
	long m_bindHashBuilt;
};
#endif
