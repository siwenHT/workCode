/*
 * define file about portable socket class. 
 * description:this sock is suit both windows and linux
 * design:odison
 * e-mail:odison@126.com>
 * 
 */

#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_

#ifdef WIN32
	//#include <winsock.h>
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

	//#pragma region define win32 const variable in linux
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
	//#pragma endregion
#endif

#include "cocos2d.h"
USING_NS_CC;

#ifndef ENABLE_NETLOG
#define ENABLE_NETLOG 0
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

class ODSocket : public  Ref{

public:
	bool is_getData;
	ODSocket(SOCKET sock = INVALID_SOCKET);
	~ODSocket();

	// Create socket object for snd/recv data
	bool Create(int af, int type, int protocol = 0);

	// Connect socket
	bool Connect(const char* ip, unsigned short port);
	bool ConnectNormal(const char* ip, unsigned short port);
	int ConnectIpv6(const char* ip, unsigned short port);
	//#region server
	// Bind socket
	// bool Bind(unsigned short port);

	// Listen socket
	// bool Listen(int backlog = 5); 

	// Accept socket
	// bool Accept(ODSocket& s, char* fromip = NULL);
	//#endregion
	
	// Send socket
	int Send(const char* buf, int len, int flags = 0);

	// Recv socket
	int Recv(char* buf , int len, int flags = 0);
	
	// Close socket
	int Close();

	// Get errno
	int GetError();
	
	//#pragma region just for win32
	// Init winsock DLL 
	static int Init();	
	// Clean winsock DLL
	static int Clean();
	//#pragma endregion

	// Domain parse
	// static bool DnsParse(const char* domain, char* ip);

	ODSocket& operator = (SOCKET s);

	operator SOCKET ();
	//char* G2U(const char* gb2312);
protected:
	SOCKET m_sock;

};

#endif
