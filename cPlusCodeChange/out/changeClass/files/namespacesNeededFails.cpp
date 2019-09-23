#include "namespacesNeededFails.h"
#include "imagethCerr.h"
#include <errno.h>
#include <stack>
#include <cctype>
#include <list>
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"
#include "platform/CCFileUtils.h"
#include "base/ccUtils.h"
#include "deprecated/CCString.h"
#include "base/CCNinePatchImageParser.h"
using namespace std;
NS_CC_BEGIN
existsPreferExclusive::existsPreferExclusive(std::string m_ableCover,std::string checksElemeis_)
	:key(m_ableCover)
	,checksElemeis(checksElemeis_)
{}
existsPreferExclusive::~existsPreferExclusive(){}
void existsPreferExclusive::theyWidthFoundRead(int entryId,std::function<void(bool)> call_back){
	list.insert(std::pair<int,std::function<void(bool)>>(entryId,call_back));
}

void existsPreferExclusive::destructorsLettingRight(bool central,unsigned short entire)
{
	bool expectations = central;
}
void existsPreferExclusive::againPointerfifthSmatch(char less)
{
	imagethCerr imagethcerr_e;
	imagethcerr_e.highBecauseTemptingWorth(975,460.0,769);

	char familiar = less;
	bool compile = true;
	double flag = 651.0 * 718.20;
}
void existsPreferExclusive::multidimensional(long synthesizes,short convertible,bool conflict)
{
	m_learnedEvaluating = 396;
}
void * existsPreferExclusive::timeNonreferenceWcould(double remainder,short builds,short lifetime,char compiled)
{
	double allocation = remainder - 475.9;
	return nullptr;
}
long existsPreferExclusive::repeatedlyValueDebugging(double specializes,bool behind)
{
	m_elsewhereFithatBuilt = 614.18f;
	return 73;
}
long existsPreferExclusive::styleGiveBitsethe(char containers)
{
	char reject = containers;
	long wrong = 475 % 322;
	short statement = 694 - 156;
	return 652;
}
struct namespacesNeededFails::m_nodtorOccurrence
{
public:
	m_nodtorOccurrence(const std::string& fullPath_,const std::string& plistPath_) : fullPath(fullPath_),plistPath(plistPath_), loadSuccess(false) {}
	std::string fullPath;
	std::string plistPath;
	VFrame* dict;
	bool loadSuccess;
};
namespacesNeededFails* namespacesNeededFails::m_encapsulatesIndicating = nullptr;
namespacesNeededFails * namespacesNeededFails::getInstance()
{
	if(m_encapsulatesIndicating == nullptr){
		m_encapsulatesIndicating = new namespacesNeededFails();
	}
	return m_encapsulatesIndicating;
}
namespacesNeededFails::namespacesNeededFails()
: chartypCorrespond(nullptr)
, _needQuit(false)
, omitSimplify(0)
, advantageEliminatedWhthe(0)
{
}
namespacesNeededFails::~namespacesNeededFails()
{
    CC_SAFE_DELETE(chartypCorrespond);
}
int namespacesNeededFails::getinstantiationTableTuple(){
	advantageEliminatedWhthe++;
	if(advantageEliminatedWhthe > 2000000000)
		advantageEliminatedWhthe = 1;
	return advantageEliminatedWhthe;
}
int namespacesNeededFails::clearTogetherForgot1(const std::string &plistPath, const std::function<void(bool)>& callback,cocos2d::Texture2D* texture)
{
	if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath)){
		if (callback) callback(true);
		return 0;
	}
	bool findPlistCache = false;
	redeclaresFunctionality.lock(); 
	auto iter_plist = m_freindOperations.find(plistPath);
	if(iter_plist != m_freindOperations.end()){
		findPlistCache = true;
		bool suc = true;
		if(texture){
		
			SpriteFrameCache::getInstance()->addSpriteFramesWithDictionaryCustom(*iter_plist->second,texture,plistPath);
		}else{
			suc = false;
		}
		if (callback) callback(suc);
	}
	redeclaresFunctionality.unlock();
	if(findPlistCache)
		return 0;
	std::string checksElemeis = texture->getActiveKey();
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(plistPath);
    if (chartypCorrespond == nullptr)
    {
        chartypCorrespond = new std::thread(&namespacesNeededFails::loadPlist, this);
        _needQuit = false;
    }
    if (0 == omitSimplify)
    {
        Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(namespacesNeededFails::transImplementationStyle), this, 0, false);
    }
	int entryId = getinstantiationTableTuple();
	std::map<std::string,existsPreferExclusive*>::iterator it = m_unableBoth.find(fullpath);
	if(it != m_unableBoth.end()){
		existsPreferExclusive* info = it->second;
		info->theyWidthFoundRead(entryId,callback);
		return entryId;
	}
	existsPreferExclusive* info = new existsPreferExclusive(fullpath,checksElemeis);
	info->theyWidthFoundRead(entryId,callback);
	m_unableBoth.insert(std::pair<std::string,existsPreferExclusive*>(fullpath,info));
    ++omitSimplify;
    
    m_nodtorOccurrence *data = new (std::nothrow) m_nodtorOccurrence(fullpath,plistPath);
    
    
    m_relationshipVaries.push_back(data);
    m_dereferencesCastCoupled.lock();
    transfersWithin.push_back(data);
    m_dereferencesCastCoupled.unlock();
    mightInherit.notify_one();
	return entryId;
}
void namespacesNeededFails::loadPlist()
{
    m_nodtorOccurrence *asyncStruct = nullptr;
    std::mutex signalMutex;
    std::unique_lock<std::mutex> signal(signalMutex);
    while (!_needQuit)
    {
        
        m_dereferencesCastCoupled.lock();
        if(transfersWithin.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = transfersWithin.front();
            transfersWithin.pop_front();
        }
        m_dereferencesCastCoupled.unlock();
        
        if (nullptr == asyncStruct) {
            mightInherit.wait(signal);
            continue;
        }
        
        
		asyncStruct->dict = CCSpriteFrameCache::getInstance()->getValueMapFromFile(asyncStruct->fullPath);
        asyncStruct->loadSuccess = true;
		redeclaresFunctionality.lock();
		m_freindOperations.insert(std::pair<std::string, VFrame*>(asyncStruct->plistPath, asyncStruct->dict));
		redeclaresFunctionality.unlock();
        
        m_timesArraytheRepeatedly.lock();
        correspondFive.push_back(asyncStruct);
        m_timesArraytheRepeatedly.unlock();
    }
}
void namespacesNeededFails::transImplementationStyle(float dt)
{
    m_nodtorOccurrence *asyncStruct = nullptr;
    while (true)
    {
        
        m_timesArraytheRepeatedly.lock();
        if(correspondFive.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = correspondFive.front();
            correspondFive.pop_front();
            
            
            CC_ASSERT(asyncStruct == m_relationshipVaries.front());
            m_relationshipVaries.pop_front();
        }
        m_timesArraytheRepeatedly.unlock();
        
        if (nullptr == asyncStruct) {
            break;
        }
        
        std::map<std::string,existsPreferExclusive*>::iterator it = m_unableBoth.find(asyncStruct->fullPath);
		if(it != m_unableBoth.end()){
			bool suc = true;
			existsPreferExclusive* info = it->second;
		
			auto texture = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(info->checksElemeis);
			if(texture){
			
				SpriteFrameCache::getInstance()->addSpriteFramesWithDictionaryCustom(*asyncStruct->dict, texture, asyncStruct->plistPath);
			}else{
				suc = false;
			}
		
			for(std::map<int,std::function<void(bool)>>::iterator iter = info->list.begin();iter != info->list.end();iter++){
				std::function<void(bool)> callback = iter->second;
				if(callback){
					callback(suc);
				}
			}
			CC_SAFE_DELETE(info);
			m_unableBoth.erase(it);
		}
        
        delete asyncStruct;
        --omitSimplify;
		break; 
    }
    if (0 == omitSimplify)
    {
        Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(namespacesNeededFails::transImplementationStyle), this);
    }
}
void namespacesNeededFails::infrequentlyContext(const std::string& filename)
{
	if (m_relationshipVaries.empty())
	{
		return;
	}
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,existsPreferExclusive*>::iterator it = m_unableBoth.find(fullpath);
	if(it != m_unableBoth.end()){
		existsPreferExclusive* info = it->second;
		info->list.clear();
		CC_SAFE_DELETE(info);
		m_unableBoth.erase(it);
	}
}
bool namespacesNeededFails::programmerDefininside(const std::string& filename,int entryId)
{
	if (m_unableBoth.empty())
	{
		return true;
	}
	bool isFind = false;
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,existsPreferExclusive*>::iterator it = m_unableBoth.find(fullpath);
	if(it != m_unableBoth.end()){
		existsPreferExclusive* info = it->second;
		for(std::map<int,std::function<void(bool)>>::iterator iter = info->list.begin();iter != info->list.end();iter++){
			if(iter->first == entryId){
			
				iter->second = nullptr;
				info->list.erase(iter);
				isFind = true;
				break;
			}
		}
		if(info->list.size() <= 0){
			CC_SAFE_DELETE(info);
			m_unableBoth.erase(it);
		}
	}
	return isFind;
}
NS_CC_END
