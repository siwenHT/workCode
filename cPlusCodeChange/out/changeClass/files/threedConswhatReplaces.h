
#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_
#ifdef WIN32
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include "errno.h"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	typedef int				SOCKET;
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
#endif
#include "cocos2d.h"
USING_NS_CC;
#ifndef ENABLE_NETLOG
#define ENABLE_NETLOG 1
#endif
#if (ENABLE_NETLOG == 1) 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define NETLog(format, ...)      	{SYSTEMTIME st = {0};\
	GetLocalTime(&st);\
	char str[50] = {};\
	std::string fmt = "%s ";\
	fmt += format;\
	sprintf_s(str, "%d-%02d-%02d %02d:%02d:%02d:%03d",  st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond,st.wMilliseconds);\
	cocos2d::log(fmt.c_str(), str, ##__VA_ARGS__);}
#else 
#define NETLog(format, ...)				 cocos2d::log(format, ##__VA_ARGS__)
#endif 
#else
#define NETLog(...)				 do {} while (0)
#endif
class threedConswhatReplaces : public  Ref{
public:
	bool m_calcMistake;
	threedConswhatReplaces(SOCKET sock = INVALID_SOCKET);
	~threedConswhatReplaces();
	bool Create(int af, int type, int protocol = 0);
	bool Connect(const char* ip, unsigned short port);
	bool sometimesPeoplePredict(const char* ip, unsigned short port);
	int existAlmostRecent(const char* ip, unsigned short port);
	int Send(const char* buf, int len, int flags = 0);
	int Recv(char* buf , int len, int flags = 0);
	int Close();
	int GetError();
	static int Init();
	static int Clean();
	threedConswhatReplaces& operator = (SOCKET s);
	operator SOCKET ();
protected:
	SOCKET m_sock;
public:
private:
	unsigned short m_thingFollowsImportant;
	void * m_partsExplaining;
	int m_packTransactionEllipsis;
};
#endif
