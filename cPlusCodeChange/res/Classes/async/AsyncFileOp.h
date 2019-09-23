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
};


NS_CC_END

#endif 

