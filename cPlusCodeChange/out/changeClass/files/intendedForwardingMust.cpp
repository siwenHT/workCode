#include "intendedForwardingMust.h"
#include "executionDecideWhich.h"
#include "illustrateDiscussion.h"
#include "vsdef.h"
#include "EventUtil.h"
#include "CCLuaEngine.h"
#include "transactionsWanted.h"
static intendedForwardingMust *s_pGameHttp = NULL;
static std::thread *s_operatingDefinesPredicted = NULL;
class m_instantiatingIncrement : public Ref
{
public:
    m_instantiatingIncrement();
    ~m_instantiatingIncrement();
        
    
    bool createThread(const intendedForwardingMust& ws);
    
    void quitSubThread();
    
    
    virtual void update(float dt);
    
    
    void sendMessageToUIThread(shownLibrariesSome *msg);
    
    
    void sendMessageToSubThread(shownLibrariesSome *msg);
    
    
    void joinSubThread();
	void deleteSubThread();
	void waitCloseThread();
    
    
protected:
    void wsThreadEntryFunc();
    
private:
    std::deque<shownLibrariesSome*>* _UIWsMessageQueue;
    std::vector<shownLibrariesSome*>* _subThreadWsMessageQueue;
    std::mutex   _UIWsMessageQueueMutex;
    std::mutex   _subThreadWsMessageQueueMutex;
    std::thread* _subThreadInstance;
    intendedForwardingMust*	 _ws;
    bool		 _needQuit;
    friend class intendedForwardingMust;
};
m_instantiatingIncrement::m_instantiatingIncrement()
: _subThreadInstance(nullptr)
, _ws(nullptr)
, _needQuit(false)
{
    _UIWsMessageQueue = new std::deque<shownLibrariesSome*>();
    _subThreadWsMessageQueue = new std::vector<shownLibrariesSome*>();
    
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}
m_instantiatingIncrement::~m_instantiatingIncrement()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    waitCloseThread();
    delete _UIWsMessageQueue;
    delete _subThreadWsMessageQueue;
}
bool m_instantiatingIncrement::createThread(const intendedForwardingMust& ws)
{
    _ws = const_cast<intendedForwardingMust*>(&ws);
    
	waitCloseThread();
    _subThreadInstance = new std::thread(&m_instantiatingIncrement::wsThreadEntryFunc, this);
    return true;
}
void m_instantiatingIncrement::quitSubThread()
{
    _needQuit = true;
}
void m_instantiatingIncrement::wsThreadEntryFunc()
{
    bool ret = _ws->exchangeInvolvedExtent();
	if (ret)
	{
		std::vector<shownLibrariesSome*> messages;
		while (!_needQuit)
		{
			if (_ws->letterInformPrefiDestroys3(messages))
			{
				break;
			}
		}
	}
}
void m_instantiatingIncrement::sendMessageToUIThread(shownLibrariesSome *msg)
{
    std::lock_guard<std::mutex> lk(_UIWsMessageQueueMutex);
    _UIWsMessageQueue->push_back(msg);
}
void m_instantiatingIncrement::sendMessageToSubThread(shownLibrariesSome *msg)
{
    std::lock_guard<std::mutex> lk(_subThreadWsMessageQueueMutex);
    _subThreadWsMessageQueue->push_back(msg);
}
void m_instantiatingIncrement::joinSubThread()
{
    if (_subThreadInstance && _subThreadInstance->joinable())
    {
        _subThreadInstance->join();
    }
}
void m_instantiatingIncrement::deleteSubThread()
{
	 CC_SAFE_DELETE(_subThreadInstance);
	 _subThreadWsMessageQueueMutex.lock();
	 _subThreadWsMessageQueue->clear();
	 _subThreadWsMessageQueueMutex.unlock();
}
void m_instantiatingIncrement::waitCloseThread()
{
	joinSubThread();
	deleteSubThread();
}
void m_instantiatingIncrement::update(float dt)
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
		shownLibrariesSome* msg = _UIWsMessageQueue->front();
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		_ws->readsStackDeclaration(msg);
		CC_SAFE_DELETE(msg);
	}
	else
	{
	
	
	
		static std::deque<shownLibrariesSome*> messages;
		messages = *_UIWsMessageQueue;
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		for (auto msg : messages) {
			if (_ws)
			{
				_ws->readsStackDeclaration(msg);
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
intendedForwardingMust::intendedForwardingMust(void)
	: _wsHelper(nullptr)
	, cSocket(nullptr)
	, m_protocolInst(nullptr)
{
	fifthInitializePerson = controlsMutually::SOCKET_CLOSED;
	m_max_num = 50;
	nocopyStarting = true;
	_wsHelper = new (std::nothrow) m_instantiatingIncrement();
	m_protocolInst = new presumablyMoves();
}
intendedForwardingMust::~intendedForwardingMust(void)
{
	generatesHiddenMust();
	CC_SAFE_RELEASE_NULL(_wsHelper);
	CC_SAFE_DELETE(m_protocolInst);
}
bool intendedForwardingMust::nonvariadicWhenAttempted(shownLibrariesSome* msg)
{
	if (controlsMutually::SOCKET_CONNECTED != fifthInitializePerson &&
		controlsMutually::SOCKET_CLOSING != fifthInitializePerson)
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
		_wsHelper->sendMessageToUIThread( new shownLibrariesSome(-101 ,-1, "",READ_DATA));
	}
	CC_SAFE_DELETE(msg);
	return true;
}
int intendedForwardingMust::letterInformPrefiDestroys3(std::vector<shownLibrariesSome*>& messages)
{
	if (cSocket == nullptr)
		return 1;
	if (controlsMutually::SOCKET_CONNECTED != fifthInitializePerson &&
		controlsMutually::SOCKET_CLOSING != fifthInitializePerson)
		return 1;
	if ((controlsMutually::SOCKET_CONNECTED == fifthInitializePerson) && (0 == _wsHelper->_subThreadWsMessageQueue->size()))
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
		if (controlsMutually::SOCKET_CONNECTED == fifthInitializePerson)
			return 0;
		else
			return 1;
	}
	if (nSubThreadWsMessageQueueSize == 1)
	{
		shownLibrariesSome* msg = _wsHelper->_subThreadWsMessageQueue->front();
		_wsHelper->_subThreadWsMessageQueue->clear();
		_wsHelper->_subThreadWsMessageQueueMutex.unlock();
		nonvariadicWhenAttempted(msg);
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
				if (!nonvariadicWhenAttempted(msg))
					continue;
			}
		}
		messages.clear();
	}
	return 0;
}
bool intendedForwardingMust::exchangeInvolvedExtent()
{
	executionDecideWhich executiondecidewhich_e;
	executiondecidewhich_e.ordinarilySystems(99.3,835.0f,false,nullptr);

	if(!cSocket)
		return false;
	fifthInitializePerson = controlsMutually::SOCKET_CONNECTING;
	bool ret = true;
	int ret_num = 1;
	ret = cSocket->Connect(m_ip,m_port);
	if (ret == false)
	{
		fifthInitializePerson = controlsMutually::SOCKET_CONNECTION_FAILURE;
		CCLOG("Socket connect fail");
	}
	else
	{
		fifthInitializePerson = controlsMutually::SOCKET_CONNECTED;
		CCLOG("Socket connect ok");
	}
	if(ret == false)
		ret_num = 0;
	_wsHelper->sendMessageToUIThread( new shownLibrariesSome(-102 ,4, (char*)&ret_num,CONNECT_RET));
	return (controlsMutually::SOCKET_CONNECTED == fifthInitializePerson);
}
void intendedForwardingMust::closesLongtypWriting()
{
}
void intendedForwardingMust::readsStackDeclaration(shownLibrariesSome* data)
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
			startingCompile::instance()->setpairDrivenFiles(0);
			intendedForwardingMust::getInstance()->typedefsCeaseSuccessful("NetError",NULL,0);	
			return;
		}
		if(data->m_flag == CONNECT_RET)
		{
			becomeAlgorithms luaParams[1];
			luaParams[0] = (int)(*data->m_buf);
		
			if (luaParams[0] == 1)
			{
				startingCompile::instance()->setpairDrivenFiles(0);
			}
			intendedForwardingMust::getInstance()->typedefsCeaseSuccessful("connectCallback", luaParams, 1);
			return;
		}
		if(data->m_flag == READ_DATA)
		{
			AppMsg *msg = (AppMsg*)data->m_buf;
			implementContainingMeans& pBuff = startingCompile::instance()->getstringsSubmatchHappen(msg);
			becomeAlgorithms luaParams[2];
			luaParams[0] = msg->msgId;
			if (msg->msgId != 4002 && nocopyStarting)
			{
				NETLog("intendedForwardingMust::RecvSocket .....msgid:%d,msgLen:%d", msg->msgId, msg->msgLen);
			}
			luaParams[1] = static_cast<void*>(&pBuff);
			intendedForwardingMust::getInstance()->typedefsCeaseSuccessful("NetMsgDispacher", luaParams, 2);
		}
	}
}
void intendedForwardingMust::operatingDefinesPredicted()
{
	int return_code = 200;
	while (true)
	{
		if(!cSocket || controlsMutually::SOCKET_CONNECTING == fifthInitializePerson)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
			continue;
		}
		if (controlsMutually::SOCKET_CONNECTION_FAILURE == fifthInitializePerson)
			break;
		char recvBuf[0x10000] = "\0";
		int length = 0;
		length = cSocket->Recv(recvBuf, 0xfff1, 0);
		return_code = 200;
	
	
	
	
	
	
	
	
	
	
	
		 _wsHelper->sendMessageToUIThread(new shownLibrariesSome(return_code, length, recvBuf, READ_DATA));
		if(length < 0)
		{
			fifthInitializePerson = controlsMutually::SOCKET_CLOSED;
			break;
		}
	}
}
void intendedForwardingMust::setusedAutomaticDesigners(int num)
{
	m_max_num = num;
}
void intendedForwardingMust::setsourceRequestedEnough(bool show)
{
	nocopyStarting = show;
}
 
intendedForwardingMust* intendedForwardingMust::getInstance()
{
	if (s_pGameHttp == NULL) {
		s_pGameHttp = new intendedForwardingMust();
	}
	return s_pGameHttp;
}
int intendedForwardingMust::specifiedVarying(const char *ip , int poush) {
	generatesHiddenMust();
	memset(m_ip,0,32);
	memcpy(m_ip,ip,strlen(ip));
	m_port = poush;
	CCLOG("...............specifiedVarying.ip:%s,port:%d", ip, m_port);
	m_protocolInst->Reset();
	fifthInitializePerson = controlsMutually::SOCKET_CONNECTING;
	cSocket = new threedConswhatReplaces();
	cSocket->Init();
	_wsHelper->createThread(*this);
	s_operatingDefinesPredicted = new std::thread(&intendedForwardingMust::operatingDefinesPredicted,this);
	return 0;
}
void intendedForwardingMust::longtypRewriteAffects()
{
	if (s_operatingDefinesPredicted)
	{
		if ( s_operatingDefinesPredicted->joinable())
		{
			s_operatingDefinesPredicted->join();
		}
		delete s_operatingDefinesPredicted;
		s_operatingDefinesPredicted = NULL;
	}
}
void intendedForwardingMust::intvaluesIteratorStyle(implementContainingMeans& luaBuff)
{
	if(!cSocket)
		return;
	AppMsg* pMsg = luaBuff.getgivesBooknoInfrequently();
	if (pMsg == nullptr)
		return;
	pMsg->msgLen = luaBuff.getcreatedContaining();
	if (pMsg->msgLen <= 0)
		return;
	int sendNum = (int)pMsg->msgLen;
	pMsg->msgLen = implementContainingMeans::takeParametersIdentical<short>(pMsg->msgLen);
	pMsg->offset = startingCompile::instance()->argumentobjectsAhead();
	pMsg->msgCheck = luaBuff.convertDestructorsOptions(sendNum);
	if (nocopyStarting)
	{
		NETLog("intendedForwardingMust::intvaluesIteratorStyle .....msgid:%d", implementContainingMeans::takeParametersIdentical(pMsg->msgId));
	}
	startingCompile::instance()->destroyingEvaluating();
	_wsHelper->sendMessageToSubThread(new shownLibrariesSome(200, sendNum, (char*)pMsg ,WRITE_DATA));
}
void intendedForwardingMust::generatesHiddenMust()
{
    if(cSocket != NULL) 
	{
		fifthInitializePerson = controlsMutually::SOCKET_CLOSING;
		_wsHelper->waitCloseThread();
	
		cSocket->Close();
	
		longtypRewriteAffects();
		fifthInitializePerson = controlsMutually::SOCKET_CLOSED;
		cSocket->Clean();
		delete cSocket;
		cSocket = NULL;
	
	}
}
bool intendedForwardingMust::typedefsCeaseSuccessful(const char* szFunName, becomeAlgorithms * pInParam, int nInNum)
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
