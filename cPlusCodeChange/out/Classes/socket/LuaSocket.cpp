#include "LuaSocket.h"
#include "mapview/MapView.h"
#include "vsdef.h"
#include "EventUtil.h"
#include "CCLuaEngine.h"
#include "ByteBuffer.h"
static LuaSocket *s_pGameHttp = NULL;
static std::thread *s_readThread = NULL;
class WsThreadHelper : public Ref
{
public:
    WsThreadHelper();
    ~WsThreadHelper();
        
    
    bool createThread(const LuaSocket& ws);
    
    void quitSubThread();
    
    
    virtual void update(float dt);
    
    
    void sendMessageToUIThread(SocketData *msg);
    
    
    void sendMessageToSubThread(SocketData *msg);
    
    
    void joinSubThread();
	void deleteSubThread();
	void waitCloseThread();
    
    
protected:
    void wsThreadEntryFunc();
    
private:
    std::deque<SocketData*>* _UIWsMessageQueue;
    std::vector<SocketData*>* _subThreadWsMessageQueue;
    std::mutex   _UIWsMessageQueueMutex;
    std::mutex   _subThreadWsMessageQueueMutex;
    std::thread* _subThreadInstance;
    LuaSocket*	 _ws;
    bool		 _needQuit;
    friend class LuaSocket;
};
WsThreadHelper::WsThreadHelper()
: _subThreadInstance(nullptr)
, _ws(nullptr)
, _needQuit(false)
{
    _UIWsMessageQueue = new std::deque<SocketData*>();
    _subThreadWsMessageQueue = new std::vector<SocketData*>();
    
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}
WsThreadHelper::~WsThreadHelper()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    waitCloseThread();
    delete _UIWsMessageQueue;
    delete _subThreadWsMessageQueue;
}
bool WsThreadHelper::createThread(const LuaSocket& ws)
{
    _ws = const_cast<LuaSocket*>(&ws);
    
	waitCloseThread();
    _subThreadInstance = new std::thread(&WsThreadHelper::wsThreadEntryFunc, this);
    return true;
}
void WsThreadHelper::quitSubThread()
{
    _needQuit = true;
}
void WsThreadHelper::wsThreadEntryFunc()
{
    bool ret = _ws->onSubThreadStarted();
	if (ret)
	{
		std::vector<SocketData*> messages;
		while (!_needQuit)
		{
			if (_ws->onSubThreadLoop(messages))
			{
				break;
			}
		}
	}
}
void WsThreadHelper::sendMessageToUIThread(SocketData *msg)
{
    std::lock_guard<std::mutex> lk(_UIWsMessageQueueMutex);
    _UIWsMessageQueue->push_back(msg);
}
void WsThreadHelper::sendMessageToSubThread(SocketData *msg)
{
    std::lock_guard<std::mutex> lk(_subThreadWsMessageQueueMutex);
    _subThreadWsMessageQueue->push_back(msg);
}
void WsThreadHelper::joinSubThread()
{
    if (_subThreadInstance && _subThreadInstance->joinable())
    {
        _subThreadInstance->join();
    }
}
void WsThreadHelper::deleteSubThread()
{
	 CC_SAFE_DELETE(_subThreadInstance);
	 _subThreadWsMessageQueueMutex.lock();
	 _subThreadWsMessageQueue->clear();
	 _subThreadWsMessageQueueMutex.unlock();
}
void WsThreadHelper::waitCloseThread()
{
	joinSubThread();
	deleteSubThread();
}
void WsThreadHelper::update(float dt)
{
    
    if (0 == _UIWsMessageQueue->size()) 
        return;
    
    _UIWsMessageQueueMutex.lock();
	std::string::size_type nUIWsMessageQueueSize = _UIWsMessageQueue->size();
    if (0 == nUIWsMessageQueueSize)
    {
        _UIWsMessageQueueMutex.unlock();
        return;
    }
	if (nUIWsMessageQueueSize == 1)
	{
		SocketData* msg = _UIWsMessageQueue->front();
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		_ws->onUIThreadReceiveMessage(msg);
		CC_SAFE_DELETE(msg);
	}
	else
	{
	
	
	
		static std::deque<SocketData*> messages;
		messages = *_UIWsMessageQueue;
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		for (auto msg : messages) {
			if (_ws)
			{
				_ws->onUIThreadReceiveMessage(msg);
			}
			CC_SAFE_DELETE(msg);
		}
		messages.clear();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
}
enum WS_MSG {
    WS_MSG_TO_SUBTRHEAD_SENDING_STRING = 0,
    WS_MSG_TO_SUBTRHEAD_SENDING_BINARY,
    WS_MSG_TO_UITHREAD_OPEN,
    WS_MSG_TO_UITHREAD_MESSAGE,
    WS_MSG_TO_UITHREAD_ERROR,
    WS_MSG_TO_UITHREAD_CLOSE
};
LuaSocket::LuaSocket(void)
	: _wsHelper(nullptr)
	, cSocket(nullptr)
	, m_protocolInst(nullptr)
{
	m_SocketState = LuaSocketState::SOCKET_CLOSED;
	m_max_num = 50;
	m_showMsgID = true;
	_wsHelper = new (std::nothrow) WsThreadHelper();
	m_protocolInst = new ProtocolPacker();
}
LuaSocket::~LuaSocket(void)
{
	closeSocket();
	CC_SAFE_RELEASE_NULL(_wsHelper);
	CC_SAFE_DELETE(m_protocolInst);
}
bool LuaSocket::ThreadSendMsg(SocketData* msg)
{
	if (LuaSocketState::SOCKET_CONNECTED != m_SocketState &&
		LuaSocketState::SOCKET_CLOSING != m_SocketState)
		return false;
	int ret = 0;
	AppMsg * pMsg = (AppMsg*)msg->m_buf;
	if(pMsg == NULL)
	{
		CC_SAFE_DELETE(msg);
		return false;
	}
	ret = cSocket->Send((char*)pMsg, msg->m_len, 0);
	if(ret < 0) 
	{
		_wsHelper->sendMessageToUIThread( new SocketData(-101 ,-1, "",READ_DATA));
	}
	CC_SAFE_DELETE(msg);
	return true;
}
int LuaSocket::onSubThreadLoop(std::vector<SocketData*>& messages)
{
	if (cSocket == nullptr)
		return 1;
	if (LuaSocketState::SOCKET_CONNECTED != m_SocketState &&
		LuaSocketState::SOCKET_CLOSING != m_SocketState)
		return 1;
	if ((LuaSocketState::SOCKET_CONNECTED == m_SocketState) && (0 == _wsHelper->_subThreadWsMessageQueue->size()))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		return 0;
	}
	_wsHelper->_subThreadWsMessageQueueMutex.lock();
	std::string::size_type nSubThreadWsMessageQueueSize = _wsHelper->_subThreadWsMessageQueue->size();
	if (0 ==  nSubThreadWsMessageQueueSize)
	{
		_wsHelper->_subThreadWsMessageQueueMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		if (LuaSocketState::SOCKET_CONNECTED == m_SocketState)
			return 0;
		else
			return 1;
	}
	if (nSubThreadWsMessageQueueSize == 1)
	{
		SocketData* msg = _wsHelper->_subThreadWsMessageQueue->front();
		_wsHelper->_subThreadWsMessageQueue->clear();
		_wsHelper->_subThreadWsMessageQueueMutex.unlock();
		ThreadSendMsg(msg);
	}
	else
	{
	
	
		messages = *(_wsHelper->_subThreadWsMessageQueue);
		_wsHelper->_subThreadWsMessageQueue->clear();
		_wsHelper->_subThreadWsMessageQueueMutex.unlock();
		for (auto msg : messages)
		{
			if(msg)
			{
				if (!ThreadSendMsg(msg))
					continue;
			}
		}
		messages.clear();
	}
	return 0;
}
bool LuaSocket::onSubThreadStarted()
{
	if(!cSocket)
		return false;
	m_SocketState = LuaSocketState::SOCKET_CONNECTING;
	bool ret = true;
	int ret_num = 1;
	ret = cSocket->Connect(m_ip,m_port);
	if (ret == false)
	{
		m_SocketState = LuaSocketState::SOCKET_CONNECTION_FAILURE;
	
	}
	else
	{
		m_SocketState = LuaSocketState::SOCKET_CONNECTED;
	
	}
	if(ret == false)
		ret_num = 0;
	_wsHelper->sendMessageToUIThread( new SocketData(-102 ,4, (char*)&ret_num,CONNECT_RET));
	return (LuaSocketState::SOCKET_CONNECTED == m_SocketState);
}
void LuaSocket::onSubThreadEnded()
{
}
void LuaSocket::onUIThreadReceiveMessage(SocketData* data)
{
	if(data)
	{
		if(data->m_len == 0)
		{
			return;
		}
#if (ENABLE_NETLOG == 1 )
		if (data->m_len < 0)
		{
			if (data->m_len == -1)
			{
				NETLog("!!!!!when recv find socket close!");
			}
			else if(data->m_len == -2)
			{
				NETLog("!!!!!when recv find socket error!");
			}
			else if (data->m_len == -3)
			{
				NETLog("!!!!!when recv find recvbuf is nil!");
			}
			else if (data->m_len == -4)
			{
				NETLog("!!!!!when recv find msglen < 0 !");
			}
			else if (data->m_len == -5)
			{
				NETLog("!!!!!when recv find recvBuflen < msgLen !");
			}
		}
#endif
		if(data->m_len < 0)
		{
			LuaEventManager::instance()->setSendMsgCount(0);
			int tmpSymbolKey[] = {19,32,75,66,58,58,47,58}; 
			std::string keyA = HandleString(tmpSymbolKey, 8);		
			LuaSocket::getInstance()->runLuaFunc(keyA.c_str(), NULL, 0);
			return;
		}
		if(data->m_flag == CONNECT_RET)
		{
			CLuaParam luaParams[1];
			luaParams[0] = (int)(*data->m_buf);
		
			if (luaParams[0] == 1)
			{
				LuaEventManager::instance()->setSendMsgCount(0);
			}
			int tmpSymbolKey[] = {50,47,10,10,32,50,75,17,48,31,31,42,48,50,80}; 
			std::string keyB = HandleString(tmpSymbolKey, 15);
			LuaSocket::getInstance()->runLuaFunc(keyB.c_str(), luaParams, 1);
			return;
		}
		if(data->m_flag == READ_DATA)
		{
			AppMsg *msg = (AppMsg*)data->m_buf;
			LuaMsgBuffer& pBuff = LuaEventManager::instance()->getLuaBuffer(msg);
			CLuaParam luaParams[2];
			luaParams[0] = msg->msgId;
		
		
		
		
			luaParams[1] = static_cast<void*>(&pBuff);
			int tmpSymbolKey[] = {19,32,75,28,61,6,56,35,61,71,48,50,62,32,58}; 
			std::string keyC = HandleString(tmpSymbolKey, 15);
			LuaSocket::getInstance()->runLuaFunc(keyC.c_str(), luaParams, 2);
		}
	}
}
void LuaSocket::readThread()
{
	int return_code = 200;
	while (true)
	{
		if(!cSocket || LuaSocketState::SOCKET_CONNECTING == m_SocketState)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
			continue;
		}
		if (LuaSocketState::SOCKET_CONNECTION_FAILURE == m_SocketState)
			break;
		char recvBuf[0x10000] = "\0";
		int length = 0;
		length = cSocket->Recv(recvBuf, 0xfff1, 0);
		return_code = 200;
	
	
	
	
	
	
	
	
	
	
	
		 _wsHelper->sendMessageToUIThread(new SocketData(return_code, length, recvBuf, READ_DATA));
		if(length < 0)
		{
			m_SocketState = LuaSocketState::SOCKET_CLOSED;
			break;
		}
	}
}
void LuaSocket::setMaxReadCount(int num)
{
	m_max_num = num;
}
void LuaSocket::setCplusShowMsgID(bool show)
{
	m_showMsgID = show;
}
 
LuaSocket* LuaSocket::getInstance()
{
	if (s_pGameHttp == NULL) {
		s_pGameHttp = new LuaSocket();
	}
	return s_pGameHttp;
}
int LuaSocket::openSocket(const char *ip , int poush) {
	closeSocket();
	memset(m_ip,0,32);
	memcpy(m_ip,ip,strlen(ip));
	m_port = poush;
	m_protocolInst->Reset();
	m_SocketState = LuaSocketState::SOCKET_CONNECTING;
	cSocket = new ODSocket();
	cSocket->Init();
	_wsHelper->createThread(*this);
	s_readThread = new std::thread(&LuaSocket::readThread,this);
	return 0;
}
void LuaSocket::waitCloseReadThread()
{
	if (s_readThread)
	{
		if ( s_readThread->joinable())
		{
			s_readThread->join();
		}
		delete s_readThread;
		s_readThread = NULL;
	}
}
void LuaSocket::sendSocket(LuaMsgBuffer& luaBuff)
{
	if(!cSocket)
		return;
	AppMsg* pMsg = luaBuff.getAppMsgHead();
	if (pMsg == nullptr)
		return;
	pMsg->msgLen = luaBuff.getSendBufLen();
	if (pMsg->msgLen <= 0)
		return;
	int sendNum = (int)pMsg->msgLen;
	pMsg->msgLen = LuaMsgBuffer::HostValue2Big<short>(pMsg->msgLen);
	pMsg->offset = LuaEventManager::instance()->calculateOffset();
	pMsg->msgCheck = luaBuff.initCheckFlg(sendNum);
	LuaEventManager::instance()->addSendMsgCount();
	_wsHelper->sendMessageToSubThread(new SocketData(200, sendNum, (char*)pMsg ,WRITE_DATA));
}
void LuaSocket::closeSocket()
{
    if(cSocket != NULL) 
	{
		m_SocketState = LuaSocketState::SOCKET_CLOSING;
		_wsHelper->waitCloseThread();
	
		cSocket->Close();
	
		waitCloseReadThread();
		m_SocketState = LuaSocketState::SOCKET_CLOSED;
		cSocket->Clean();
		delete cSocket;
		cSocket = NULL;
	
	}
}
bool LuaSocket::runLuaFunc(const char* szFunName, CLuaParam * pInParam, int nInNum)
{
	if(!szFunName) return false;
	m_pLuaState = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	int top = lua_gettop(m_pLuaState);
	int nResult = 0;
	try
	{
		lua_getglobal(m_pLuaState, szFunName);
	
		if(!lua_isfunction(m_pLuaState, -1))
		{
			log("invalid function\n");
			goto RFEXIT;
		}
		for(int i = 0; i < nInNum; i++)
		{
			switch(pInParam[i].GetDataType())
			{
			case PARAM_DATATYPE_NUMBER:
				{
					lua_pushnumber(m_pLuaState, (int)pInParam[i]);
				}		
				break;		
			case PARAM_DATATYPE_STRING:
				{
					lua_pushstring(m_pLuaState, (const char *)pInParam[i]);
				}		
				break;
			case PARAM_DATATYPE_LIGHTUSERDATA:
				{
					lua_pushlightuserdata(m_pLuaState, (void *)pInParam[i]);
				}
				break;
			default:
				{
					goto RFEXIT;
				}
			}
		}
	
		nResult = lua_pcall(m_pLuaState, nInNum, 0, 0);
		if(nResult == 0)
		{
		}
		else
		{
			log("[LUA ERROR] %s", lua_tostring(m_pLuaState, - 1));
		}
	}
	catch (...) {
		log("[LUA ERROR]");
	}
RFEXIT:
	lua_settop(m_pLuaState, top);
	if(nResult != 0)
		log("[LuaEngine] call function %s(...) failed\n", szFunName);        
	return (nResult == 0);
}
