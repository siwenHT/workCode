#include "ODSocket.h"
#include <stdio.h>
#include <vector>
#include <string>
#if defined(_MSC_VER) || defined(__MINGW32__)
#include <io.h>
#include <WS2tcpip.h>
#include <Winsock2.h>
#if defined(__MINGW32__)
#include "platform/win32/inet_pton_mingw.h"
#include <netinet/tcp.h>
#endif
#define bzero(a, b) memset(a, 0, b);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#include "inet_ntop_winrt.h"
#include "inet_pton_winrt.h"
#include "CCWinRTUtils.h"
#endif
#else
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <netinet/tcp.h>
#endif
#include "cocos2d.h"
using namespace std;
#ifdef WIN32
	#pragma comment(lib , "wsock32")
	#pragma comment(lib , "libcurl_imp.lib")
#endif
#ifdef WIN32
	#define MY_ERRNO WSAGetLastError()
	#define MY_EINTR WSAEINTR
#else
	#define MY_ERRNO errno
	#define MY_EINTR EINTR
#endif
ODSocket::ODSocket(SOCKET sock)
{
	m_sock = sock;
}
ODSocket::~ODSocket()
{
}
int ODSocket::Init()
{
#ifdef WIN32
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);	
	if ( ret ) {
		return -1;
	}
#endif
	return 0;
}
int ODSocket::Clean()
{
#ifdef WIN32
	return (WSACleanup());
#endif
	return 0;
}
ODSocket& ODSocket::operator = (SOCKET s)
{
	m_sock = s;
	return (*this);
}
ODSocket::operator SOCKET ()
{
	return m_sock;
}
bool ODSocket::Create(int af, int type, int protocol)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    return true;
#else
	m_sock = socket(af , type , protocol);
	if ( m_sock == INVALID_SOCKET ) {
		return false;
	}
#endif
	return true;
}
static struct sockaddr *get_sock_addr(const char *addr, unsigned short port, int *size)
{
	static struct sockaddr_in6	servaddr_v6;
	static struct sockaddr_in svraddr_v4;
	struct hostent	*hptr;
	char **pptr;
#ifdef WIN32   
	hptr = gethostbyname(addr);
	pptr = hptr->h_addr_list;
	memset(&svraddr_v4,0,sizeof(svraddr_v4));
	svraddr_v4.sin_family = AF_INET;
	svraddr_v4.sin_port = htons(port);
	memcpy(&svraddr_v4.sin_addr, *pptr, sizeof(svraddr_v4.sin_addr));	
	*size = sizeof(svraddr_v4);
	return (struct sockaddr *)&svraddr_v4;
#else
	if ( (hptr = gethostbyname2(addr, AF_INET6)) == NULL || *(hptr->h_addr_list) == NULL)
	{
		hptr = gethostbyname2(addr, AF_INET);
	    pptr = hptr->h_addr_list;
		memset(&svraddr_v4,0,sizeof(svraddr_v4));
		svraddr_v4.sin_family = AF_INET;
		svraddr_v4.sin_port = htons(port);
		memcpy(&svraddr_v4.sin_addr, *pptr, sizeof(svraddr_v4.sin_addr));	
		*size = sizeof(svraddr_v4);
		return (struct sockaddr *)&svraddr_v4;
	}
	pptr = hptr->h_addr_list;
	bzero(&servaddr_v6, sizeof(servaddr_v6));
	servaddr_v6.sin6_family = AF_INET6;
	servaddr_v6.sin6_port   = htons(port);
	memcpy(&servaddr_v6.sin6_addr, *pptr, sizeof(servaddr_v6.sin6_addr));
	*size = sizeof(servaddr_v6);
	return (struct sockaddr *)&servaddr_v6;
#endif
}
bool isIPAddress(const char *s)  
{  
	const char *pChar;  
	bool rv = true;  
	int tmp1, tmp2, tmp3, tmp4, i;  
	while( 1 )  
	{  
		i = sscanf(s, "%d.%d.%d.%d", &tmp1, &tmp2, &tmp3, &tmp4);  
		if( i != 4 )  
		{  
			rv = false;  
			break;  
		}  
		if( (tmp1 > 255) || (tmp2 > 255) || (tmp3 > 255) || (tmp4 > 255) )  
		{  
			rv = false;  
			break;  
		}  
		for( pChar = s; *pChar != 0; pChar++ )  
		{  
			if( (*pChar != '.')  
				&& ((*pChar < '0') || (*pChar > '9')) )  
			{  
				rv = false;  
				break;  
			}  
		}  
		break;  
	}  
	return rv;  
}  
bool ODSocket::Connect(const char* ip, unsigned short port)
{
	int ret = ConnectIpv6(ip,port);
	if(ret != 0)
	{
		return false;
	}
	return true;
}
bool ODSocket::ConnectNormal(const char* ip, unsigned short port)
{
	bool useIpConnect = true;
	if(cocos2d::Application::getInstance()->getTargetPlatform() == ApplicationProtocol::Platform::OS_IPHONE || cocos2d::Application::getInstance()->getTargetPlatform() == ApplicationProtocol::Platform::OS_IPAD){
	
		useIpConnect = false;
	}
	
		if(isIPAddress(ip) == false){
			useIpConnect = false;
		}
	if(useIpConnect == false){
	
		int size;
		CCLOG("connecting:.....%s...%d", ip, port);
		struct sockaddr *svraddr = get_sock_addr(ip, port, &size);
		if (size == sizeof(struct	sockaddr_in))
		{
			Create(AF_INET, SOCK_STREAM, 0);
		}
		else
		{
			Create(AF_INET6, SOCK_STREAM, 0);
		}
		CCLOG("connect:.....%d:%d:%d:%d...%d",(unsigned char)svraddr->sa_data[1], (unsigned char)svraddr->sa_data[2], (unsigned char)svraddr->sa_data[3], (unsigned char)svraddr->sa_data[4], port);
		int ret = connect(m_sock, svraddr, size);  
		if ( ret == SOCKET_ERROR ) {
			return false;
		}
	}else{
	
		Create(AF_INET , SOCK_STREAM , 0);
		struct sockaddr_in svraddr;
		svraddr.sin_family = AF_INET;
		svraddr.sin_addr.s_addr = inet_addr(ip);
		svraddr.sin_port = htons(port);
		int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
		if ( ret == SOCKET_ERROR ) {
			return false;
		}
	}
	return true;
}
int ODSocket::ConnectIpv6(const char* host, unsigned short port){
	NETLog("--------------------------------------------------------------");
	NETLog("[ODSocket::ConnectIpv6] connect start %s : %d", host, port);
	struct addrinfo hints, *res, *ressave;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	int n;
	if ((n = getaddrinfo(host, nullptr, &hints, &res)) != 0)
	{
		NETLog("[ODSocket::ConnectIpv6] getaddrinfo error for %s: %s", host, gai_strerror(n));
		return 2;
	}
	if (res == nullptr)
	{
		NETLog("[ODSocket::ConnectIpv6] getaddrinfo error 2 for %s", host);
		return 2;
	}
	ressave = res;
	do 
	{
		m_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (m_sock < 0)
		{
			NETLog("[ODSocket::ConnectIpv6] socket error: %d, %d, %d", res->ai_family, res->ai_socktype, res->ai_protocol);
			continue;
		}
		NETLog("[ODSocket::ConnectIpv6] socket ok: %d, %d, %d", res->ai_family, res->ai_socktype, res->ai_protocol);
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
		int set = 1;
		setsockopt(m_sock, SOL_SOCKET, SO_NOSIGPIPE, (void*)&set, sizeof(int));
#endif
		if (res->ai_family == AF_INET)
		{
			struct sockaddr_in *sin = (struct sockaddr_in*) res->ai_addr;
			sin->sin_port = htons(port);
#if ENABLE_NETLOG == 1
			char buf[INET_ADDRSTRLEN] = "";
			if (inet_ntop(res->ai_family, &sin->sin_addr, buf, sizeof(buf)) != nullptr)
				NETLog("[ODSocket::ConnectIpv6] connect start %s : %d", buf, ntohs(sin->sin_port));
#endif
		}
		else if (res->ai_family == AF_INET6)
		{
			struct sockaddr_in6 *sin = (struct sockaddr_in6*) res->ai_addr;
			sin->sin6_port = htons(port);
#if ENABLE_NETLOG == 1
			char buf[INET6_ADDRSTRLEN] = "";
			if (inet_ntop(res->ai_family, &sin->sin6_addr, buf, sizeof(buf)) != nullptr)
				NETLog("[ODSocket::ConnectIpv6] connect start %s : %d", buf, ntohs(sin->sin6_port));
#endif
		}
		else
		{
			Close();
			m_sock = INVALID_SOCKET;
			continue;
		}
		if (connect(m_sock, res->ai_addr, res->ai_addrlen) == SOCKET_ERROR)
		{
			if (errno != EINPROGRESS)
			{
				m_sock = INVALID_SOCKET;
				continue;
			} 
			else 
			{
				break;
			}
		}
		else
		{
			break;
		}
		return 0;
	} while (0);
	if (res == nullptr)
	{
		freeaddrinfo(ressave);
		m_sock = INVALID_SOCKET;
		NETLog("[ODSocket::ConnectIpv6] socket connect error : addr");
		NETLog("--------------------------------------------------------------");
		return 3;
	}
	freeaddrinfo(ressave);
	if (m_sock < 0 || m_sock == INVALID_SOCKET)
	{
		NETLog("[ODSocket::ConnectIpv6] socket connect error");
		NETLog("--------------------------------------------------------------");
		return 3;
	}
	NETLog("--------------------------------------------------------------");
	return 0;
}
int ODSocket::Send(const char* buf, int len, int flags)
{
	int bytes;
	int count = 0;
	while ( count < len ) {
		bytes = send(m_sock, buf + count, len - count, flags);
		if ( bytes == -1 || bytes == 0 )
			return -1;
		count += bytes;
	} 
	is_getData = true;
	return count;
}
static int BlockRecv(SOCKET sock, char *buf, int max)
{
	int rLen = 0;
	int ret = 0;
    while (true)
    {
        if (rLen >= max) break;
        ret = recv(sock, buf+rLen, max-rLen, 0);
        if (ret == 0) return -1; 
        if (ret == SOCKET_ERROR)
        {
            if (MY_ERRNO == MY_EINTR) continue;
            return -2; 
        }
        
        rLen += ret;
    }
	return 0;
}
int ODSocket::Recv(char* buf , int len , int flags)
{
	if(buf == NULL) return -3;
	signed char streamlen[2];
	int ret = BlockRecv(m_sock, (char *)streamlen, 2);
	if (ret != 0) return ret;
	unsigned short bLen = 0;
	memcpy(&bLen, streamlen, 2);
	bLen = bLen + 2;
	if (bLen <= 0) return -4; 
	if (len < bLen) return -5; 
	memcpy(buf, &bLen, 2);
	memcpy(buf + 2, &bLen, 2);  
	ret = BlockRecv(m_sock, &buf[4], bLen - 4);
	if (ret != 0) return ret;
	return bLen ;
}
int ODSocket::Close()
{
#ifdef WIN32
	return (closesocket(m_sock));
#else
	return (shutdown(m_sock, SHUT_RDWR));
#endif
}
int ODSocket::GetError()
{
#ifdef WIN32
	return (WSAGetLastError());
#else
	return (errno);
#endif
}
