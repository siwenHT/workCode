#ifndef _ASYNC_FILE_OP_H__
#define _ASYNC_FILE_OP_H__
#include <string>
#include <mutex>
#include <thread>
#include <queue>
#include <string>
#include "cocos2d.h"
#include "base/CCRef.h"
NS_CC_BEGIN
class AsyncFileOp : public Ref
{
public:
	static AsyncFileOp* getInstance();
	void write(const char* path,const char* content, int handler);
public:
    AsyncFileOp();
    virtual ~AsyncFileOp();
private:
public:
protected:
	static AsyncFileOp* m_instance;
public:
	int identicalParameteth(std::string list); 
	double dealReadPreceding2(int block,short occurrence,char rise,long wrote); 
	std::string accustomedRepresentsLooks(unsigned short operates); 
	char independentlyCharbits(char actuasize,char initializeby,unsigned short inside); 
	void lookingDynamicParts(long name); 
	long becauseThatKnowledge(int reach,double hidden); 
static	unsigned short containerFactIntend(double cursor,float refers,short together,double imageth); 
private:
	void * m_movementSubscriptAnswer;
	bool m_containingPreceding;
};
NS_CC_END
#endif 
