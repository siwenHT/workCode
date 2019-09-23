#ifndef _YVLISTERN_H_
#define _YVLISTERN_H_
#include <iostream>
#include <algorithm>
#include <list>
#include "YVTypeDef.h"
namespace YVSDK
{
#define InitListern(Name, ArgcType)  \
public:  \
	typedef YVListern::YV##Name##Listern Name##Lister;  \
	void add##Name##Listern(Name##Lister* lister)  \
	{ \
	m_##Name##listerList.push_back(lister); \
} \
	void del##Name##Listern(Name##Lister* lister)  \
	{  \
	std::list<Name##Lister* >::iterator iter = m_##Name##listerList.begin(); \
	for (;iter != m_##Name##listerList.end(); ++iter) {if ((*iter) == lister)break;} \
	if (iter != m_##Name##listerList.end()) \
	{ \
	m_##Name##listerList.erase(iter); \
} \
} \
	void call##Name##Listern(ArgcType* t) \
	{ \
	std::list<Name##Lister* >::iterator _listenerItr = m_##Name##listerList.begin(); \
	while (_listenerItr != m_##Name##listerList.end())  \
	{  \
	Name##Lister* lister = *_listenerItr; \
	++_listenerItr; \
	lister->on##Name##Listern(t); \
}  \
} \
private: \
	std::list<Name##Lister* > m_##Name##listerList;
	class YVListern
	{
	public:
	
		class YVLoginListern
		{
		public:
			virtual void onLoginListern(CPLoginResponce*) = 0;
		};
	
		class YVReConnectListern
		{
		public:
			virtual void onReConnectListern(ReconnectionNotify*) = 0;
		};
	
		class YVStopRecordListern
		{
		public:
			virtual void onStopRecordListern(RecordStopNotify*) = 0;
		};
	
		class YVFinishSpeechListern
		{
		public:
			virtual void onFinishSpeechListern(SpeechStopRespond*) = 0;
		};
	
		class YVFinishPlayListern
		{
		public:
			virtual void onFinishPlayListern(StartPlayVoiceRespond*) = 0;
		};
	
		class YVUpLoadFileListern
		{
		public:
			virtual void onUpLoadFileListern(UpLoadFileRespond*) = 0;
		};
	
		class YVDownLoadFileListern
		{
		public:
			virtual void onDownLoadFileListern(DownLoadFileRespond*) = 0;
		};
	
		class YVNetWorkSateListern
		{
		public:
			virtual void onNetWorkSateListern(NetWorkStateNotify*) = 0;
		};
	
		class YVDownloadVoiceListern
		{
		public: 
			virtual void onDownloadVoiceListern(DownloadVoiceRespond*) = 0;
		};
	
		class YVRecordVoiceListern
		{
		public:
			virtual void onRecordVoiceListern(RecordVoiceNotify*) = 0;
		};
	
		class YVCPUserInfoListern
		{
		public:
			virtual void onCPUserInfoListern(GetCPUserInfoRespond*) = 0;
		};
        
        
        class YVFlowListern
        {
        public:
            virtual void onFlowListern(YunvaflowRespond*) = 0;
        };
        
        
	};
};
#endif