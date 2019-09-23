#include "andqueryApplies.h"
#include "imagineUnlikeNeed.h"
#include "vsdef.h"
#include "EventUtil.h"
#include "CCLuaEngine.h"
#include "curlyEffect.h"
static andqueryApplies *s_pGameHttp = NULL;
static std::thread *s_stillIndependentlyArgs = NULL;
class employeeConstructAcross : public Ref
{
public:
    employeeConstructAcross();
    ~employeeConstructAcross();
        
    
    bool createThread(const andqueryApplies& ws);
    
    void quitSubThread();
    
    
    virtual void update(float dt);
    
    
    void sendMessageToUIThread(recentlyViewRelative *msg);
    
    
    void sendMessageToSubThread(recentlyViewRelative *msg);
    
    
    void joinSubThread();
	void deleteSubThread();
	void waitCloseThread();
    
    
protected:
    void wsThreadEntryFunc();
    
private:
    std::deque<recentlyViewRelative*>* _UIWsMessageQueue;
    std::vector<recentlyViewRelative*>* _subThreadWsMessageQueue;
    std::mutex   _UIWsMessageQueueMutex;
    std::mutex   _subThreadWsMessageQueueMutex;
    std::thread* _subThreadInstance;
    andqueryApplies*	 _ws;
    bool		 _needQuit;
    friend class andqueryApplies;
};
employeeConstructAcross::employeeConstructAcross()
: _subThreadInstance(nullptr)
, _ws(nullptr)
, _needQuit(false)
{
    _UIWsMessageQueue = new std::deque<recentlyViewRelative*>();
    _subThreadWsMessageQueue = new std::vector<recentlyViewRelative*>();
    
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}
employeeConstructAcross::~employeeConstructAcross()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    waitCloseThread();
    delete _UIWsMessageQueue;
    delete _subThreadWsMessageQueue;
}
bool employeeConstructAcross::createThread(const andqueryApplies& ws)
{
    _ws = const_cast<andqueryApplies*>(&ws);
    
	waitCloseThread();
    _subThreadInstance = new std::thread(&employeeConstructAcross::wsThreadEntryFunc, this);
    return true;
}
void employeeConstructAcross::quitSubThread()
{
    _needQuit = true;
}
void employeeConstructAcross::wsThreadEntryFunc()
{
    bool ret = _ws->bracketsTokensSeparates5();
	if (ret)
	{
		std::vector<recentlyViewRelative*> messages;
		while (!_needQuit)
		{
			if (_ws->objectHighestFront(messages))
			{
				break;
			}
		}
	}
}
void employeeConstructAcross::sendMessageToUIThread(recentlyViewRelative *msg)
{
    std::lock_guard<std::mutex> lk(_UIWsMessageQueueMutex);
    _UIWsMessageQueue->push_back(msg);
}
void employeeConstructAcross::sendMessageToSubThread(recentlyViewRelative *msg)
{
    std::lock_guard<std::mutex> lk(_subThreadWsMessageQueueMutex);
    _subThreadWsMessageQueue->push_back(msg);
}
void employeeConstructAcross::joinSubThread()
{
    if (_subThreadInstance && _subThreadInstance->joinable())
    {
        _subThreadInstance->join();
    }
}
void employeeConstructAcross::deleteSubThread()
{
	 CC_SAFE_DELETE(_subThreadInstance);
	 _subThreadWsMessageQueueMutex.lock();
	 _subThreadWsMessageQueue->clear();
	 _subThreadWsMessageQueueMutex.unlock();
}
void employeeConstructAcross::waitCloseThread()
{
	joinSubThread();
	deleteSubThread();
}
void employeeConstructAcross::update(float dt)
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
		recentlyViewRelative* msg = _UIWsMessageQueue->front();
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		_ws->collectionSensible(msg);
		CC_SAFE_DELETE(msg);
	}
	else
	{
	
	
	
		static std::deque<recentlyViewRelative*> messages;
		messages = *_UIWsMessageQueue;
		_UIWsMessageQueue->clear();
		_UIWsMessageQueueMutex.unlock();
		for (auto msg : messages) {
			if (_ws)
			{
				_ws->collectionSensible(msg);
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
andqueryApplies::andqueryApplies(void)
	: _wsHelper(nullptr)
	, cSocket(nullptr)
	, m_protocolInst(nullptr)
{
	m_operatorclickThdefines = recentRelies::SOCKET_CLOSED;
	m_max_num = 50;
	unlikeCentral = true;
	_wsHelper = new (std::nothrow) employeeConstructAcross();
	m_protocolInst = new comeRevise();
}
andqueryApplies::~andqueryApplies(void)
{
	aspectsTreeRequired();
	CC_SAFE_RELEASE_NULL(_wsHelper);
	CC_SAFE_DELETE(m_protocolInst);
}
bool andqueryApplies::moreovesomeStrategy(recentlyViewRelative* msg)
{
	if (recentRelies::SOCKET_CONNECTED != m_operatorclickThdefines &&
		recentRelies::SOCKET_CLOSING != m_operatorclickThdefines)
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
		_wsHelper->sendMessageToUIThread( new recentlyViewRelative(-101 ,-1, "",READ_DATA));
	}
	CC_SAFE_DELETE(msg);
	return true;
}
int andqueryApplies::objectHighestFront(std::vector<recentlyViewRelative*>& messages)
{
	if (cSocket == nullptr)
		return 1;
	if (recentRelies::SOCKET_CONNECTED != m_operatorclickThdefines &&
		recentRelies::SOCKET_CLOSING != m_operatorclickThdefines)
		return 1;
	if ((recentRelies::SOCKET_CONNECTED == m_operatorclickThdefines) && (0 == _wsHelper->_subThreadWsMessageQueue->size()))
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
		if (recentRelies::SOCKET_CONNECTED == m_operatorclickThdefines)
			return 0;
		else
			return 1;
	}
	if (nSubThreadWsMessageQueueSize == 1)
	{
		recentlyViewRelative* msg = _wsHelper->_subThreadWsMessageQueue->front();
		_wsHelper->_subThreadWsMessageQueue->clear();
		_wsHelper->_subThreadWsMessageQueueMutex.unlock();
		moreovesomeStrategy(msg);
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
				if (!moreovesomeStrategy(msg))
					continue;
			}
		}
		messages.clear();
	}
	return 0;
}
bool andqueryApplies::bracketsTokensSeparates5()
{
	if(!cSocket)
		return false;
	m_operatorclickThdefines = recentRelies::SOCKET_CONNECTING;
	bool ret = true;
	int ret_num = 1;
	ret = cSocket->Connect(m_ip,m_port);
	if (ret == false)
	{
		m_operatorclickThdefines = recentRelies::SOCKET_CONNECTION_FAILURE;
		CCLOG("Socket connect fail");
	}
	else
	{
		m_operatorclickThdefines = recentRelies::SOCKET_CONNECTED;
		CCLOG("Socket connect ok");
	}
	if(ret == false)
		ret_num = 0;
	_wsHelper->sendMessageToUIThread( new recentlyViewRelative(-102 ,4, (char*)&ret_num,CONNECT_RET));
	return (recentRelies::SOCKET_CONNECTED == m_operatorclickThdefines);
}
void andqueryApplies::specializesThumb2()
{
}
void andqueryApplies::collectionSensible(recentlyViewRelative* data)
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
			senseGrades::instance()->setsafePropagatesItemFocus(0);
			andqueryApplies::getInstance()->consistentExclusiveKnow("NetError",NULL,0);	
			return;
		}
		if(data->m_flag == CONNECT_RET)
		{
			likelyDescribeField luaParams[1];
			luaParams[0] = (int)(*data->m_buf);
		
			if (luaParams[0] == 1)
			{
				senseGrades::instance()->setsafePropagatesItemFocus(0);
			}
			andqueryApplies::getInstance()->consistentExclusiveKnow("connectCallback", luaParams, 1);
			return;
		}
		if(data->m_flag == READ_DATA)
		{
			AppMsg *msg = (AppMsg*)data->m_buf;
			yieldsAnswerAlways& pBuff = senseGrades::instance()->getareaArgumentobjects(msg);
			likelyDescribeField luaParams[2];
			luaParams[0] = msg->msgId;
			if (msg->msgId != 4002 && unlikeCentral)
			{
				NETLog("andqueryApplies::RecvSocket .....msgid:%d,msgLen:%d", msg->msgId, msg->msgLen);
			}
			luaParams[1] = static_cast<void*>(&pBuff);
			andqueryApplies::getInstance()->consistentExclusiveKnow("NetMsgDispacher", luaParams, 2);
		}
	}
}
void andqueryApplies::stillIndependentlyArgs()
{
	int return_code = 200;
	while (true)
	{
		if(!cSocket || recentRelies::SOCKET_CONNECTING == m_operatorclickThdefines)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
			continue;
		}
		if (recentRelies::SOCKET_CONNECTION_FAILURE == m_operatorclickThdefines)
			break;
		char recvBuf[0x5000] = "\0";
		int length = 0;
		length = cSocket->Recv(recvBuf, 0x4900, 0);
		return_code = 200;
	
	
	
	
	
	
	
	
	
	
	
		 _wsHelper->sendMessageToUIThread(new recentlyViewRelative(return_code, length, recvBuf, READ_DATA));
		if(length < 0)
		{
			m_operatorclickThdefines = recentRelies::SOCKET_CLOSED;
			break;
		}
	}
}
void andqueryApplies::setfunctionalityJustAlready(int num)
{
	m_max_num = num;
}
void andqueryApplies::setbracketsBodyResulting(bool show)
{
	unlikeCentral = show;
}
 
andqueryApplies* andqueryApplies::getInstance()
{
	if (s_pGameHttp == NULL) {
		s_pGameHttp = new andqueryApplies();
	}
	return s_pGameHttp;
}
int andqueryApplies::destructorDoesSplit(const char *ip , int poush) {
	aspectsTreeRequired();
	memset(m_ip,0,32);
	memcpy(m_ip,ip,strlen(ip));
	m_port = poush;
	CCLOG("...............destructorDoesSplit.ip:%s,port:%d", ip, m_port);
	m_protocolInst->Reset();
	m_operatorclickThdefines = recentRelies::SOCKET_CONNECTING;
	cSocket = new difficultDoeth();
	cSocket->Init();
	_wsHelper->createThread(*this);
	s_stillIndependentlyArgs = new std::thread(&andqueryApplies::stillIndependentlyArgs,this);
	return 0;
}
void andqueryApplies::designsInstance()
{
	if (s_stillIndependentlyArgs)
	{
		if ( s_stillIndependentlyArgs->joinable())
		{
			s_stillIndependentlyArgs->join();
		}
		delete s_stillIndependentlyArgs;
		s_stillIndependentlyArgs = NULL;
	}
}
void andqueryApplies::updateSelectsButton(yieldsAnswerAlways& luaBuff)
{
	if(!cSocket)
		return;
	AppMsg* pMsg = luaBuff.getreadsIsbnsPattern1();
	if (pMsg == nullptr)
		return;
	pMsg->msgLen = luaBuff.getiostreamArgumepassed1();
	if (pMsg->msgLen <= 0)
		return;
	int sendNum = (int)pMsg->msgLen;
	pMsg->msgLen = yieldsAnswerAlways::correspondsAdvantage<short>(pMsg->msgLen);
	pMsg->offset = senseGrades::instance()->importanceDealBound();
	pMsg->msgCheck = luaBuff.asfifthSignatureSetting(sendNum);
	if (unlikeCentral)
	{
		NETLog("andqueryApplies::updateSelectsButton .....msgid:%d", yieldsAnswerAlways::correspondsAdvantage(pMsg->msgId));
	}
	senseGrades::instance()->comparesReadsPlaced();
	_wsHelper->sendMessageToSubThread(new recentlyViewRelative(200, sendNum, (char*)pMsg ,WRITE_DATA));
}
void andqueryApplies::aspectsTreeRequired()
{
    if(cSocket != NULL) 
	{
		m_operatorclickThdefines = recentRelies::SOCKET_CLOSING;
		_wsHelper->waitCloseThread();
	
		cSocket->Close();
	
		designsInstance();
		m_operatorclickThdefines = recentRelies::SOCKET_CLOSED;
		cSocket->Clean();
		delete cSocket;
		cSocket = NULL;
	
	}
}
bool andqueryApplies::consistentExclusiveKnow(const char* szFunName, likelyDescribeField * pInParam, int nInNum)
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
