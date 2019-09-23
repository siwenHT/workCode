#include "chaptersHeaderDevoted.h"
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
betterAbstraction::betterAbstraction(std::string m_unwindingOnalthough,std::string failVeryBetween_)
	:key(m_unwindingOnalthough)
	,failVeryBetween(failVeryBetween_)
{}
betterAbstraction::~betterAbstraction(){}
void betterAbstraction::pointerfifthAssignment(int entryId,std::function<void(bool)> call_back){
	list.insert(std::pair<int,std::function<void(bool)>>(entryId,call_back));
}

bool betterAbstraction::variableAffectsTable2(float come)
{
	int labeled;
	labeled = 729;
	void * disadvantages;
	disadvantages = nullptr;
	void * accustomed;
	accustomed = nullptr;
	void * instantiation;
	instantiation = nullptr;
	return false;
}
unsigned short betterAbstraction::differenbetweenAmong(float somewhere,long stop)
{
	float alternatively;
	alternatively = 906.20f;
	char rest;
	rest = '7';
	float elsewhere;
	elsewhere = 968.10f;
	long digits;
	digits = 101;
	return 779;
}
void * betterAbstraction::realizeCreatingMatrix(bool differently,short fithat)
{
	unsigned short covering;
	covering = 38;
	return nullptr;
}
bool betterAbstraction::expressionsOffsetsBooks(char complicated)
{
	int design;
	design = 532;
	double temporaries;
	temporaries = 881.20;
	char intvaluesenum;
	intvaluesenum = 'P';
	return false;
}
void betterAbstraction::recursionInsteadDiffering(long taking,float group,short whole)
{
	void * stops;
	stops = nullptr;
}
bool betterAbstraction::tyhaveAnswerThere(double inspired)
{
	bool mube;
	mube = true;
	short qualifying;
	qualifying = 84;
	return true;
}
void betterAbstraction::ninesAlternatively(short unduly)
{
	short bookstore;
	bookstore = 397;
	unsigned short directions;
	directions = 929;
	float disk;
	disk = 748.18f;
	double redefinition;
	redefinition = 881.20;
}
unsigned short betterAbstraction::relyFunctionfunction(int arrarecall,unsigned short promotion,bool whenever)
{
	int oriented;
	oriented = 409;
	bool bookno;
	bookno = false;
	short reside;
	reside = 635;
	double assignmenclick;
	assignmenclick = 242.0;
	void * machines;
	machines = nullptr;
	return 352;
}
short betterAbstraction::onalthoughFactBehalf(long least,float past)
{
	void * among;
	among = nullptr;
	char problem;
	problem = '1';
	return 691;
}
unsigned short betterAbstraction::addingEscapeEnumerator(int well,float only,char save,long destroyed)
{
	double calculates;
	calculates = 755.8;
	float affects;
	affects = 907.3f;
	return 400;
}
double betterAbstraction::knowledgeForwardBegins(float compute,long adaptors,unsigned short unnamed)
{
	double header;
	header = 387.4;
	short assigned;
	assigned = 421;
	short function;
	function = 273;
	double bound;
	bound = 825.7;
	double specializations;
	specializations = 341.6;
	return 428.16;
}
struct chaptersHeaderDevoted::m_attemptedFacilities
{
public:
	m_attemptedFacilities(const std::string& fullPath_,const std::string& plistPath_) : fullPath(fullPath_),plistPath(plistPath_), loadSuccess(false) {}
	std::string fullPath;
	std::string plistPath;
	VFrame* dict;
	bool loadSuccess;
};
chaptersHeaderDevoted* chaptersHeaderDevoted::m_worrySomewhat = nullptr;
chaptersHeaderDevoted * chaptersHeaderDevoted::getInstance()
{
	if(m_worrySomewhat == nullptr){
		m_worrySomewhat = new chaptersHeaderDevoted();
	}
	return m_worrySomewhat;
}
chaptersHeaderDevoted::chaptersHeaderDevoted()
: m_includesAccumulate(nullptr)
, _needQuit(false)
, m_firstExistsBooks(0)
, machinesIndicesInfer(0)
{
}
chaptersHeaderDevoted::~chaptersHeaderDevoted()
{
    CC_SAFE_DELETE(m_includesAccumulate);
}
int chaptersHeaderDevoted::getconditionChainDoesndiffer2(){
	machinesIndicesInfer++;
	if(machinesIndicesInfer > 2000000000)
		machinesIndicesInfer = 1;
	return machinesIndicesInfer;
}
int chaptersHeaderDevoted::substringAbstractlyWita(const std::string &plistPath, const std::function<void(bool)>& callback,cocos2d::Texture2D* texture)
{
	if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath)){
		if (callback) callback(true);
		return 0;
	}
	bool findPlistCache = false;
	currentTellCovering.lock(); 
	auto iter_plist = leaveComputeReset.find(plistPath);
	if(iter_plist != leaveComputeReset.end()){
		findPlistCache = true;
		bool suc = true;
		if(texture){
		
			SpriteFrameCache::getInstance()->addSpriteFramesWithDictionaryCustom(*iter_plist->second,texture,plistPath);
		}else{
			suc = false;
		}
		if (callback) callback(suc);
	}
	currentTellCovering.unlock();
	if(findPlistCache)
		return 0;
	std::string failVeryBetween = texture->getActiveKey();
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(plistPath);
    if (m_includesAccumulate == nullptr)
    {
        m_includesAccumulate = new std::thread(&chaptersHeaderDevoted::loadPlist, this);
        _needQuit = false;
    }
    if (0 == m_firstExistsBooks)
    {
        Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(chaptersHeaderDevoted::concludesInitializing), this, 0, false);
    }
	int entryId = getconditionChainDoesndiffer2();
	std::map<std::string,betterAbstraction*>::iterator it = m_occurrenceNonexistent.find(fullpath);
	if(it != m_occurrenceNonexistent.end()){
		betterAbstraction* info = it->second;
		info->pointerfifthAssignment(entryId,callback);
		return entryId;
	}
	betterAbstraction* info = new betterAbstraction(fullpath,failVeryBetween);
	info->pointerfifthAssignment(entryId,callback);
	m_occurrenceNonexistent.insert(std::pair<std::string,betterAbstraction*>(fullpath,info));
    ++m_firstExistsBooks;
    
    m_attemptedFacilities *data = new (std::nothrow) m_attemptedFacilities(fullpath,plistPath);
    
    
    m_usuallyManager.push_back(data);
    assumedDeduction.lock();
    m_pscreenRecentlyDifference.push_back(data);
    assumedDeduction.unlock();
    instanceRecent.notify_one();
	return entryId;
}
void chaptersHeaderDevoted::loadPlist()
{
    m_attemptedFacilities *asyncStruct = nullptr;
    std::mutex signalMutex;
    std::unique_lock<std::mutex> signal(signalMutex);
    while (!_needQuit)
    {
        
        assumedDeduction.lock();
        if(m_pscreenRecentlyDifference.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = m_pscreenRecentlyDifference.front();
            m_pscreenRecentlyDifference.pop_front();
        }
        assumedDeduction.unlock();
        
        if (nullptr == asyncStruct) {
            instanceRecent.wait(signal);
            continue;
        }
        
        
		asyncStruct->dict = CCSpriteFrameCache::getInstance()->getValueMapFromFile(asyncStruct->fullPath);
        asyncStruct->loadSuccess = true;
		currentTellCovering.lock();
		leaveComputeReset.insert(std::pair<std::string, VFrame*>(asyncStruct->plistPath, asyncStruct->dict));
		currentTellCovering.unlock();
        
        m_theareCopies.lock();
        listthFinds.push_back(asyncStruct);
        m_theareCopies.unlock();
    }
}
void chaptersHeaderDevoted::concludesInitializing(float dt)
{
    m_attemptedFacilities *asyncStruct = nullptr;
    while (true)
    {
        
        m_theareCopies.lock();
        if(listthFinds.empty())
        {
            asyncStruct = nullptr;
        }else
        {
            asyncStruct = listthFinds.front();
            listthFinds.pop_front();
            
            
            CC_ASSERT(asyncStruct == m_usuallyManager.front());
            m_usuallyManager.pop_front();
        }
        m_theareCopies.unlock();
        
        if (nullptr == asyncStruct) {
            break;
        }
        
        std::map<std::string,betterAbstraction*>::iterator it = m_occurrenceNonexistent.find(asyncStruct->fullPath);
		if(it != m_occurrenceNonexistent.end()){
			bool suc = true;
			betterAbstraction* info = it->second;
		
			auto texture = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(info->failVeryBetween);
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
			m_occurrenceNonexistent.erase(it);
		}
        
        delete asyncStruct;
        --m_firstExistsBooks;
		break; 
    }
    if (0 == m_firstExistsBooks)
    {
        Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(chaptersHeaderDevoted::concludesInitializing), this);
    }
}
void chaptersHeaderDevoted::pageDeclaredLettingInsert(const std::string& filename)
{
	if (m_usuallyManager.empty())
	{
		return;
	}
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,betterAbstraction*>::iterator it = m_occurrenceNonexistent.find(fullpath);
	if(it != m_occurrenceNonexistent.end()){
		betterAbstraction* info = it->second;
		info->list.clear();
		CC_SAFE_DELETE(info);
		m_occurrenceNonexistent.erase(it);
	}
}
bool chaptersHeaderDevoted::requirementBehaviorRecord(const std::string& filename,int entryId)
{
	if (m_occurrenceNonexistent.empty())
	{
		return true;
	}
	bool isFind = false;
	std::string fullpath = FileUtils::getInstance()->fullPathForFilename(filename);
	std::map<std::string,betterAbstraction*>::iterator it = m_occurrenceNonexistent.find(fullpath);
	if(it != m_occurrenceNonexistent.end()){
		betterAbstraction* info = it->second;
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
			m_occurrenceNonexistent.erase(it);
		}
	}
	return isFind;
}
NS_CC_END
