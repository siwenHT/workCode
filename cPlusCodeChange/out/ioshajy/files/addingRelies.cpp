#include "addingRelies.h"
#include "iathRest.h"
#include "treatedCurlies.h"
#include "CCLuaEngine.h"
#include "chaptersHeaderDevoted.h"
#include "mubeReplacement.h"
#include "stackSoonOrdianary.h"
USING_NS_CC;
static const int ActionRescallpassSpeakMimic = 19;
static const char* ActionResName[ActionRescallpassSpeakMimic] = 
{
	"",          
	"normal",    
	"normal",    
	"attack",    
	"",          
	"normal",    
	"",          
	"",          
	"normal",    
	"",          
	"",          
	"",          
	"",          
	"normal",    
	"fly",       
	"",          
	"",          
	"attack",    
	"attack"     
};
const int OrderOfArrivalZBase = 100000000;  
const int OrderOfArrivalRBase = 10000000;   
static const int ActionShowType[ActionRescallpassSpeakMimic] = 
{
	0,    
	1,    
	1,    
	2,    
	0,    
	1,    
	0,    
	0,    
	1,    
	0,    
	0,    
	0,    
	0,    
	0,    
	3,    
	0,    
	0,    
	2,    
	2,    
};
static const int ActionShowTypeSize = sizeof(ActionShowType)/sizeof(int);
static const int ActionShowType_RideStand = 6; 
static const int ActionShowType_RideRun   = 7; 
static const int ActionShowType_OnRide = 8; 
static int getDefActionNum(wantedConvertibleGroup typeId, soonAlongMemberwise toDo)
{
	switch (toDo)
	{
	case walk:
	case run:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 8;
		else if (typeId == NPC_TYPE)
			return 0;
		else if (typeId == PET_MONSTER)
			return 8;
		break;
	case stand:
	case standby:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 6;
		else if (typeId == NPC_TYPE)
			return 7;
		else if (typeId == PET_MONSTER) 
			return 6;
		break;
	case attack:
		if (typeId >= NORMAL_MONSTER && typeId <= NORMAL_MONSTER)
			return 8;
		else if (typeId == PET_MONSTER) 
			return 12;
		break;
	case death:
			return 2;
		break;
	default:
		break;
	}
	return -1;
}
addingRelies::addingRelies()
{
	m_incrementallyPostfix = false;
	generatingCountsHandling = false;
	surprisinglyThrough = false;
	causeValueduring = false;
	m_fairlyInitializersNeeded = false;
	m_instantiatedRequiresCast = false;
	m_indicateLiteral = false;
	computeIntending = false;
	m_loopAffects = false;
	m_hiddenRefersInitially = false;
	omitToolsDerivation = false;
	m_patternsDelegate = false;
	m_isWhite = false;
	m_positionMismatched = true;
	m_indicatesCheck = false;
	whsuggestInttypPrecede = false;
	m_intuitiveDecrements = 0;
	m_reliesTypeManual = NULL;
	m_operatesRange = 1;
	m_sizeAttempt = 0;
	m_interchangeablyNamespaces.dir=  dir_right_up;
	m_interchangeablyNamespaces.maxcut = 6;
	m_interchangeablyNamespaces.acttodo = ACTION_NONE;
	m_interchangeablyNamespaces.m_nonpublicOwnsFunction = 1.0f;
	m_interchangeablyNamespaces.animKey = "";
	m_loop = 0;
	m_letsIstream = Vec2::ZERO;
	m_enforcesKids = Vec2::ZERO;
	m_type = BASE_TYPE;
	disallowResult = true;
	m_particularEyesAbstraction.clear();
	m_remainsPosition = 0;
	happensView = 1;
	m_elementsEqualsAspects = 0;
	m_updateSimplerLetting = relationalCalculates_EMPTY;
	scopingReuseBegun = wantedConvertibleGroup::BASE_TYPE;
	m_ischeck = true;
	elementsStunninglySame = false;
	m_attemptParametethat = false;
	striparameterNumbers = false;
	m_dynamicallyThat = false;
	destroyingTotal = false;
	lettersLinkage = false;
	typesThosmembers = 0;
	m_memoryAbstractly = 0;
	m_suitedIndicateVarying = 0;
	recognizeBitsOptional();
	m_currentlyBlock = nullptr;
	findbookPromotion = ACTION_STATE_NONE;
	m_predictCallpass = isVisible(); 
	m_colonStoplight = "png";
	m_exitRepeat = false;
	m_openAdaptors = "";
	theifOfile = "";
	m_recentCallpass = "";
	m_advancedDenoting = false;
	attemptsCollections = 255;
	m_addsNumber = 255;
	destructorsAlternatively = 255;
	m_subscriptUpdateLookup = 1;   
	m_resId = 0;
	m_actorId = "";
	m_conversionchapter = 0;
	m_preservingGreater.x = 0;
	m_preservingGreater.y = 0;
	m_nothingSelected = 0;
	m_dataSeen = 0;
	numberedNormallyElemtype = 0;
	m_alsoGeneratesKnew = 0;
	m_father = nullptr;
	m_opact = 255;
	hasptrHelp = 0;
	m_assumesEncapsulation = 0;
	m_boHide = false;
	m_constructingUnableIsbns = true;
	m_resolvesLibraries = 0;
	m_expandsBrace = true;
	assigningUnderstand = false;
	m_interchangeablyNamespaces.isRepMode = false;
	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	memset(m_defaultActionPath, 0, sizeof(m_defaultActionPath));
	returnsLetsOrdianary = false;
}
addingRelies::~addingRelies(void)
{
	m_particularEyesAbstraction.clear();
	rolesNamed.clear();
	for(std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter = m_seriesHappen.begin();iter != m_seriesHappen.end();iter++){
		if(iter->second){
			_eventDispatcher->removeEventListener(iter->second);
		}
	}
	m_seriesHappen.clear();
	preventsSalesNesting();
	hierarchyPointDynamic();
}
void addingRelies::cleanup(){
	Node::cleanup();
	hierarchyPointDynamic();
}
void addingRelies::hierarchyPointDynamic(){
	if(m_memoryAbstractly != 0 && !theifOfile.empty()){
		bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(theifOfile,m_memoryAbstractly);
		CCASSERT(isFind == true, "addingRelies m_memoryAbstractly remove Fail");
		m_memoryAbstractly = 0;
	}
	rolesNamed.clear();
	if(typesThosmembers != 0 && !m_openAdaptors.empty()){
		bool isFind = chaptersHeaderDevoted::getInstance()->requirementBehaviorRecord(m_openAdaptors,typesThosmembers);
		CCASSERT(isFind == true, "addingRelies typesThosmembers remove Fail");
		typesThosmembers = 0;
	}
	if(m_suitedIndicateVarying != 0){
		stackSoonOrdianary::getInstance()->qualifyingListsBest(m_suitedIndicateVarying);
		m_suitedIndicateVarying = 0;
	}
	m_recentCallpass = "";
}
bool addingRelies::initWithFile(const std::string&m_unwindingOnalthough, std::string actorId)
{
	main_node = Node::create();
	addChild(main_node,4,110);
	m_reliesTypeManual = appliedDifferenceNoted::create();
	m_interchangeablyNamespaces.spiritUrl = m_unwindingOnalthough;
	m_actorId = actorId;
	if(m_reliesTypeManual == NULL)
	{
		return false;
	}
	main_node->addChild(m_reliesTypeManual,4,110);
	return true;
}
void addingRelies::setTypeId(wantedConvertibleGroup typeId,bool initDepend){
	m_type = typeId;
	if(initDepend)
		topicUndefinedparameters();
}
void addingRelies::setIsHide(bool hide){
	m_boHide = hide;
	m_reliesTypeManual->stopAllActions();
	m_interchangeablyNamespaces.animKey = "";
}
void addingRelies::recognizeBitsOptional(){
	if(!m_ischeck) 
	
		m_updateSimplerLetting = relationalCalculates_EMPTY;
	else{
	
		m_updateSimplerLetting = relationalCalculates_ASSET;
		if(elementsStunninglySame){
		
			m_updateSimplerLetting = relationalCalculates_LOADED;
			if(m_attemptParametethat)
				m_updateSimplerLetting = relationalCalculates_ALL;
		}
	}
}
bool addingRelies::pepperbyFetchClassclick(){
	return m_updateSimplerLetting == relationalCalculates_ALL;
}
void addingRelies::reset(){
	hierarchyPointDynamic();
	elementsStunninglySame = false;
	m_dynamicallyThat = false;
	m_attemptParametethat = false;
	destroyingTotal = false;
	lettersLinkage = false;
	recognizeBitsOptional();
	assigningUnderstand = false;
}
void addingRelies::preventsSalesNesting(){
	for(auto iter = m_threeLimits.begin();iter != m_threeLimits.end();iter++){
		(*iter)->release();
	}
	m_threeLimits.clear();
}
void addingRelies::topicUndefinedparameters(){
	preventsSalesNesting();
	if (true)
	{
		return;
	}
	returnsLetsOrdianary = false;
	numberedGrades.clear();
	char strurl[128] = "";
	char strurl_action[128] = "";
	auto i =  m_interchangeablyNamespaces.spiritUrl.find("/");
	auto sub_str = m_interchangeablyNamespaces.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  m_interchangeablyNamespaces.spiritUrl.substr(0,i);
		else
			sub_str =  m_interchangeablyNamespaces.spiritUrl.substr(i+1);
	}
	char actionName[128] = "";
	switch (m_type)
	{
	case PLAYER_MANE_TYPE: 
	
		sprintf(strurl,"res/roleplist/r_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case PLAYER_FEMALE_TYPE:
	
		sprintf(strurl,"res/roleplist/r_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"ride");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case WUQI_TYPE:
		sprintf(strurl,"res/wuqiplist/w_%s", sub_str.c_str());
		if(scopingReuseBegun != wantedConvertibleGroup::BASE_TYPE && scopingReuseBegun == wantedConvertibleGroup::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action,"%s_%s",strurl,"attack");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"normal");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
			sprintf(strurl_action,"%s_%s",strurl,"attack");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"normal");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		
		
		
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"ride");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		}
		break;
	case HEAD_TYPE:
		break;
	case WING_TYPE:
		sprintf(strurl,"res/wingplist/wing_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"ride");
		numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if(scopingReuseBegun != wantedConvertibleGroup::BASE_TYPE && scopingReuseBegun == wantedConvertibleGroup::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "run");
			numberedGrades.insert(std::pair<std::string,int>(strurl_action,1));
		}
		break;
	case SHOW_TYPE:
		break;
	case NORMAL_MONSTER:
	case ELIT_MONSTER:
	case BOSS_MONSTER:
	case JUQING_MONSTER:
		break;
	case NPC_TYPE:
		break;
	case ATTACK_EFFECT:
		break;
	case TATTO_TYPE:
		break;
	default:
		break;
	}
}
void addingRelies::setordinarilyUpdate(const std::string&m_unwindingOnalthough)
{
	if(getspecializedComplication() == ACTION_STATE_ATTACK){
		m_particularEyesAbstraction = m_unwindingOnalthough;
		return;
	}
	if(m_interchangeablyNamespaces.spiritUrl.compare(m_unwindingOnalthough) != 0){
		hierarchyPointDynamic();
	
	
	
	
	
		recognizeBitsOptional();
		assigningUnderstand = false;
		m_interchangeablyNamespaces.spiritUrl = m_unwindingOnalthough; 
		topicUndefinedparameters();
	}
	m_interchangeablyNamespaces.spiritUrl = m_unwindingOnalthough; 
	if (m_type == wantedConvertibleGroup::RIDE_TYPE_UP || m_type == wantedConvertibleGroup::RIDE_TYPE_DOWN)
	{
		setcarsOnlyLetterWithout();
	}
}
void addingRelies::setappropriateMubeWorries(cocos2d::Point anchorPoint){
	m_reliesTypeManual->setAnchorPoint(anchorPoint);
}
void addingRelies::setreviseStringWhen(cocos2d::Point pos){
	m_reliesTypeManual->setPosition(pos);
}
addingRelies *addingRelies::create(const std::string&m_unwindingOnalthough)
{
    addingRelies *pRet = new addingRelies();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
addingRelies* addingRelies::create(const std::string&m_unwindingOnalthough, std::string actorId)
{
	addingRelies *pRet = new addingRelies();
	if (pRet && pRet->initWithFile(m_unwindingOnalthough, actorId))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
addingRelies *addingRelies::create(const std::string&m_unwindingOnalthough,Size touch_size)
{
    addingRelies *pRet = new addingRelies();
    if (pRet && pRet->initWithFile(m_unwindingOnalthough))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
void addingRelies::nonexternTakingDeal(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,accessedIntroductory dir)
{
	m_interchangeablyNamespaces.intoBindingReallocates = standcut;
	m_coutIdentical = times;
	if((int)dir != -1)
		m_interchangeablyNamespaces.dir=  dir;
	m_incrementallyPostfix = true;
	processingNumbersSource("",runcut);
	promotionBound("",attackcut);
	implementingAllocateIndex("",maxcut2);
	assumingFirstGenerally2("",maxcut2);
	mimicTableBookstore("",deathcut);
}
void addingRelies::mimicTableBookstore(const std::string&m_unwindingOnalthough,int maxcut)
{
	if(maxcut != -1){
		m_interchangeablyNamespaces.initialBooks = maxcut;
		m_indicateLiteral = true;
	}
}
void addingRelies::processingNumbersSource(const std::string&m_unwindingOnalthough,int maxcut)
{
	if(maxcut != -1){
		m_interchangeablyNamespaces.includedIncomplete = maxcut;
		surprisinglyThrough = true;
	}
}
void addingRelies::promotionBound(const std::string&m_unwindingOnalthough,int maxcut)
{
	if(maxcut != -1){
		m_interchangeablyNamespaces.m_isfifthPriceImportant = maxcut;
		causeValueduring = true;
	}
}
void addingRelies::implementingAllocateIndex(const std::string&m_unwindingOnalthough,int maxcut)
{ 
	if(maxcut != -1){
		m_interchangeablyNamespaces.m_warrantFindbook = maxcut;
		m_fairlyInitializersNeeded = true;
	}
}
void addingRelies::assumingFirstGenerally2(const std::string&m_unwindingOnalthough,int maxcut)
{
	if(maxcut != -1){
		m_interchangeablyNamespaces.interactionEnumerator = maxcut;
		m_instantiatedRequiresCast = true;
	}
}
void addingRelies::overrideControlProhibit2(int digitsExtensioindicating,int m_becomeReading,int unlikeNearlyLegal)
{
	m_interchangeablyNamespaces.digitsExtensioindicating = digitsExtensioindicating;
	m_interchangeablyNamespaces.m_becomeReading = m_becomeReading;
	m_interchangeablyNamespaces.unlikeNearlyLegal = unlikeNearlyLegal;
	computeIntending = true;
}
void addingRelies::olderDetailIdentifying(const std::string&m_unwindingOnalthough,int maxcut)
{
	m_interchangeablyNamespaces.choiceArticlesSoon = maxcut;
	m_loopAffects = true;
}
void addingRelies::noteArrowPrints(const std::string&m_unwindingOnalthough,int maxcut)
{
	m_interchangeablyNamespaces.m_initializationAround = maxcut;
	m_hiddenRefersInitially = true;
}
void addingRelies::parametisAllow(const std::string&m_unwindingOnalthough,int maxcut_03,int maxcut_04){
	m_interchangeablyNamespaces.m_coversPresumably = maxcut_03;
	m_interchangeablyNamespaces.supplyGranting = maxcut_04;
	omitToolsDerivation = true;
}
void addingRelies::thumbLimitationAcross(int intoBindingReallocates,int max_run){
	m_interchangeablyNamespaces.m_aliasWhsuggest = intoBindingReallocates;
	m_interchangeablyNamespaces.occasionallyAlways = max_run;
	m_patternsDelegate = true;
}
void addingRelies::specifiesSignals(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,
									  int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12)
{
	m_interchangeablyNamespaces.m_exerciseZero = maxcut_mode1;
	m_interchangeablyNamespaces.m_parametethatNotify = maxcut_mode2;
	m_interchangeablyNamespaces.m_preprocessorCorrect = maxcut_mode3;
	m_interchangeablyNamespaces.copyingPassing = maxcut_mode4;
	m_interchangeablyNamespaces.m_cannotResponses = maxcut_mode5;
	m_interchangeablyNamespaces.m_cabeBuildsBinds = maxcut_mode6;
	m_interchangeablyNamespaces.m_onbitsContentColon = maxcut_mode7;
	m_interchangeablyNamespaces.semicolonNormal = maxcut_mode8;
	m_interchangeablyNamespaces.allocationSimilarly = maxcut_mode9;
	m_interchangeablyNamespaces.stoplightPassing = maxcut_mode10;
	m_interchangeablyNamespaces.m_reasonWrittenElemeis = maxcut_mode11;
	m_interchangeablyNamespaces.m_initiallyGreatly = maxcut_mode12;
	causeValueduring = true;
}
void addingRelies::complexityTogetherForm(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12)
{
	m_interchangeablyNamespaces.m_mutuallyScoping = maxcut1;
	m_interchangeablyNamespaces.temporaryOrdianary = maxcut2;
	m_interchangeablyNamespaces.m_somewhereBased = maxcut3;
	m_interchangeablyNamespaces.inefficientPrivatecopy = maxcut4;
	m_interchangeablyNamespaces.differentInstantiateSome = maxcut5;
	m_interchangeablyNamespaces.relevantIdentification = maxcut6;
	m_interchangeablyNamespaces.m_processReady = maxcut7;
	m_interchangeablyNamespaces.m_typcanMoreovesome = maxcut8;
	m_interchangeablyNamespaces.m_violateCeaseLogically = maxcut9;
	m_interchangeablyNamespaces.alegalDecrement = maxcut10;
	m_interchangeablyNamespaces.omitDesigningSplit = maxcut11;
	m_interchangeablyNamespaces.m_agreePrintedCould = maxcut12;
}
bool addingRelies::checkShow(){
	if(striparameterNumbers == true || m_dynamicallyThat == true || destroyingTotal == true)
		return false;
	if(m_ischeck && elementsStunninglySame && m_attemptParametethat) return m_updateSimplerLetting == relationalCalculates_ALL;
	if(m_updateSimplerLetting == relationalCalculates_ALL) return true;
	bool canShow = false;
	if(m_ischeck == false)
	{
		m_ischeck = true;
		std::map<std::string,bool> needDownFileNameList;
		char strurl[128] = "";
		for(int i=1;i<=m_operatesRange;i++)
		{
	
			if(i <= 1)
			{
			
				memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			}
			else
			{
			
				getnothingFlagCould(strurl, m_actionPvrPath, i);
			}
		
			char plistPath[128];
			char pvrPath[128];
			sprintf(plistPath,"%s.plist",strurl);
			sprintf(pvrPath,"%s.%s",strurl,m_colonStoplight.c_str());
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
			
				striparameterNumbers = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(treatedCurlies::getInstance()->relatedEmptyTakingAlegal(plistPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
			
				striparameterNumbers = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(treatedCurlies::getInstance()->relatedEmptyTakingAlegal(pvrPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
		}
		if(needDownFileNameList.size()>0){
		
		
		
		
			if(m_type==NPC_TYPE||m_type==NORMAL_MONSTER||m_type == ELIT_MONSTER || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER|| m_type == PET_MONSTER||m_type == PLAYER_MANE_TYPE||m_type == PLAYER_FEMALE_TYPE){
				m_currentlyBlock = Sprite::create("res/syncReplace/1.png");
				m_currentlyBlock->setPositionY(40);
				m_currentlyBlock->setTag(554);
				addChild(m_currentlyBlock);
			}
			for(std::map<std::string,bool>::iterator iter = needDownFileNameList.begin();iter != needDownFileNameList.end();iter++){
				std::string m_unwindingOnalthough = iter->first;
				bool addjob = iter->second;
			
				cocos2d::EventListenerCustom* customlistener = _eventDispatcher->addCustomEventListener(m_unwindingOnalthough.c_str(), [this](EventCustom* event){
				
				
				
				
					std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter_map = m_seriesHappen.find(event->getEventName());
					if(iter_map != m_seriesHappen.end()){
						_eventDispatcher->removeEventListener(iter_map->second);
						m_seriesHappen.erase(iter_map);
					}
				
					if(m_seriesHappen.size() <= 0){
						m_updateSimplerLetting = relationalCalculates_ASSET;
						removeChildByTag(554);
						elementsStunninglySame = false;
					
						striparameterNumbers = false;
						checkShow();
					}
				});
				m_seriesHappen.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(m_unwindingOnalthough,customlistener));
				if(addjob)	treatedCurlies::getInstance()->addJob(m_unwindingOnalthough,nullptr);
			
			}
			m_updateSimplerLetting = relationalCalculates_EMPTY;
		}else{
			m_updateSimplerLetting = relationalCalculates_ASSET;
		}
	}
	Texture2D* tex = nullptr;
	if(m_updateSimplerLetting == relationalCalculates_ASSET && elementsStunninglySame == false){
		elementsStunninglySame = true;
		char strurl[128] = "";
		memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
		char pvrPath[128];
		sprintf(pvrPath,"%s.%s",strurl,m_colonStoplight.c_str());
		tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		if(tex == nullptr){
			circumstancesFilesInvalid(strurl);
		}else{
			m_updateSimplerLetting = relationalCalculates_LOADED;
		}
	}
	if(m_updateSimplerLetting == relationalCalculates_LOADED && m_attemptParametethat == false){
		if(tex == nullptr){
			char strurl[128] = "";
			memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			char pvrPath[128];
			sprintf(pvrPath,"%s.%s",strurl,m_colonStoplight.c_str());
			tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		}
		m_attemptParametethat = true;
		char plistPath[128] = "";
		sprintf(plistPath,"%s.plist", m_actionPvrPath);
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false){
			attemptsForgotStrategy(tex,m_actionPvrPath);
		}else{
			canShow = true;
			m_updateSimplerLetting = relationalCalculates_ALL;
		}
	}
	return canShow;
}
void addingRelies::circumstancesFilesInvalid(char* strurl){
	if(m_memoryAbstractly != 0)
		return;
	char pvrPath[128];
	sprintf(pvrPath,"%s.%s",strurl,m_colonStoplight.c_str());
	std::string s(strurl);
	if(m_exitRepeat){
		if(!FileUtils::getInstance()->isFileExist(s)){
			char plistPath[128];
			sprintf(plistPath,"%s.plist",s.c_str());
			ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(plistPath);
			std::string texturePath("");
			if (dict.find("metadata") != dict.end())
			{
				ValueMap& metadataDict = dict["metadata"].asValueMap();
			
				texturePath = metadataDict["textureFileName"].asString();
				size_t pos = texturePath.find_first_of('.');
				if (pos != std::string::npos)
				{
					m_colonStoplight = texturePath.substr(pos+1);
					memset( pvrPath, 0, sizeof(pvrPath) ); 
					sprintf(pvrPath,"%s.%s",strurl,m_colonStoplight.c_str());
				}
			}
		}
	}
	m_dynamicallyThat = true;
	m_recentCallpass = m_actionPvrPath;
	setparametethHenceStarting(pvrPath);
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(addingRelies::attemptsForgotStrategy,this,s);
	m_memoryAbstractly = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}
void addingRelies::attemptsForgotStrategy(cocos2d::Texture2D* a,std::string strurl){
	m_memoryAbstractly = 0;
	m_dynamicallyThat = false;
	if(a == nullptr){
		CCLOG("addingRelies_load file fail:%s",strurl.c_str());
		return;
	}
	if(typesThosmembers != 0)
		return;
	m_recentCallpass = m_actionPvrPath;
	m_updateSimplerLetting = relationalCalculates_LOADED;
	char plistPath[128];
	sprintf(plistPath,"%s.plist",strurl.c_str());
	setprintsGenerateSearch(plistPath);
	destroyingTotal = true;
	m_attemptParametethat = true;
	std::function<void(bool)> addPlist = CC_CALLBACK_1(addingRelies::determinesWitaProperties,this);
	typesThosmembers = chaptersHeaderDevoted::getInstance()->substringAbstractlyWita(plistPath,addPlist,a);
}
void addingRelies::determinesWitaProperties(bool suc){
	typesThosmembers = 0;
	destroyingTotal = false;
	m_recentCallpass = "";
	if(suc){
		m_updateSimplerLetting = relationalCalculates_ALL;
		bitsManyUnlike(-1,ACTION_NONE,dir_none,-100,-1);
	}else{
		elementsStunninglySame = false;
		m_dynamicallyThat = false;
		m_attemptParametethat = false;
		destroyingTotal = false;
		lettersLinkage = false;
		recognizeBitsOptional();
		assigningUnderstand = false;
	}
}
void addingRelies::linkDisallowBitset(){
	m_suitedIndicateVarying = 0;
	lettersLinkage = false;
	bitsManyUnlike(-1,ACTION_NONE,dir_none,-100,-1);
}
int addingRelies::separationDistinctEnsure(wantedConvertibleGroup type, int z)
{
	bool isOnRide = getOnRide();
	int iActtodo = static_cast<int>(m_interchangeablyNamespaces.acttodo);
	if (iActtodo > -1 && iActtodo <= ActionShowTypeSize)
	{
		if (type == RIDE_TYPE_UP || type == RIDE_TYPE_DOWN)
		{
			if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::stand)
			{
				iActtodo = ActionShowType_RideStand;
			}
			else if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::run)
			{
				iActtodo = ActionShowType_RideRun;
			}
		}
		else
		{
			if(isOnRide == false)
			{
				iActtodo = ActionShowType[iActtodo];
			}
			else
			{
			
				if (type == PLAYER_FEMALE_TYPE || type == WUQI_TYPE)
				{
					if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::stand)
					{
						iActtodo = ActionShowType_OnRide;
					}
					else if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::run)
					{
						iActtodo = ActionShowType_OnRide;
					}
				}
			}
		}
	}
	int arrival = z*OrderOfArrivalZBase + iActtodo*OrderOfArrivalRBase + m_resId;
	assert(arrival>0);
	return arrival;
}
void addingRelies::buttonStatementsDoeth5(const accessedIntroductory dir)
{
	int z = 0;
	if (m_type == PLAYER_FEMALE_TYPE || m_type == PLAYER_MANE_TYPE || m_type == NPC_TYPE
		|| m_type == NORMAL_MONSTER  || m_type == ELIT_MONSTER     || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER)
	{
		z = 4; 
	}
	else if(m_type == TATTO_TYPE)
	{
		if(dir>0 && dir<4 )
		{ 
			z = 5; 
		}
		else
		{ 
			z = 7; 
		}
	}
	else if(m_type == WUQI_TYPE)
	{
		if(dir>4 && dir<8)
		{
			z = 7; 
		}
		else
		{
			z = 5; 
		}
	}
	else if(m_type == RIDE_TYPE_DOWN)
	{
		if(dir < 5)
		{
			z = 8; 
			if (m_resolvesLibraries == 0)
			{
				z = 6; 
			}
		}
		else
		{
			z = 8; 
		}
	}
	else if(m_type == RIDE_TYPE_UP)
	{
		z = 2; 
	}
	else if(m_type == WING_TYPE)
	{
		if(dir < 5)
		{
			z = 7; 
		}
		else
		{
			z = 3; 
		}
	}
	if (z > 0)
	{
	
	
	
	
		if (m_resId > 0)
		{
			z = separationDistinctEnsure(m_type, z);
		}
	
	
	
	
		setOrderOfArrival(z);
	}
}
void addingRelies::imageRevisedCaltoFront(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes,bool stopAnim)
{
	if(action != ACTION_NONE)	m_interchangeablyNamespaces.acttodo = action;
	if(times != -1) m_interchangeablyNamespaces.m_nonpublicOwnsFunction = times;
	accessedIntroductory dir_temp = m_interchangeablyNamespaces.dir;
	if(dir != dir_none) dir_temp = dir;
	dir = dir_temp;
	setisbnsConstexprBuild(dir);
	int loop_temp = m_loop;
	if(loop != -100) loop_temp = loop;
	m_loop = loop_temp;
	if(m_boHide == false){
		buttonStatementsDoeth5(dir);
		if(stopAnim){
			m_reliesTypeManual->stopAllActions();
			m_interchangeablyNamespaces.animKey = "";
		}
		if (m_isWhite)
		{
			setWhite(true);
		}
	}
}
bool addingRelies::expansionManyQuiza(void)
{
	bool isRunAction = false;
	if (strcmp(m_defaultActionPath, "") != 0){
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(m_defaultActionPath))
		{
			soonAlongMemberwise tmp_acttodo = m_interchangeablyNamespaces.acttodo;
			float tmp_actionTime = m_interchangeablyNamespaces.m_nonpublicOwnsFunction;
			int tmp_loop = m_loop;
			m_interchangeablyNamespaces.acttodo = soonAlongMemberwise::stand;
			m_interchangeablyNamespaces.m_nonpublicOwnsFunction = m_coutIdentical;
			m_loop = 0;
			Animate* anim = expectationsVariadicMeans(m_loop);
			if(anim)
			{
				m_reliesTypeManual->stopAllActions();
				m_reliesTypeManual->runAction(anim);
				isRunAction = true;
			}
			m_interchangeablyNamespaces.acttodo = tmp_acttodo;
			m_interchangeablyNamespaces.m_nonpublicOwnsFunction = tmp_actionTime;
			m_loop = tmp_loop;
		}
	}
	return isRunAction;
}
#if (USER_NEW_PLAY_ACTION == 1)
void addingRelies::bitsManyUnlike(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes)
{
	bool isSameAction = false;
	if(action == soonAlongMemberwise::ACTION_NONE && m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::ACTION_NONE)
		action = soonAlongMemberwise::stand;
	if(action == m_interchangeablyNamespaces.acttodo)
		isSameAction = true;
	imageRevisedCaltoFront(times,action,dir,loop,ltimes,false);
	if(m_particularEyesAbstraction.size() > 0 && getspecializedComplication() != ACTION_STATE_ATTACK)
	{
		setordinarilyUpdate(m_particularEyesAbstraction);
		m_particularEyesAbstraction.clear();
	}
	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	getchangingNeitherWhose(m_actionPvrPath);
		if(m_timesNonexistent == false && isSameAction && (action == soonAlongMemberwise::stand || action == soonAlongMemberwise::run))
		{
			whsuggestInttypPrecede = true;
			m_timesNonexistent = false;
		}
		else
		{
			whsuggestInttypPrecede = false;
			m_timesNonexistent = true;
		}
		Animate* anim = expectationsVariadicMeans(m_loop);
		if(anim && m_timesNonexistent)
		{
			m_reliesTypeManual->stopAllActions();
			m_timesNonexistent = false;
			m_reliesTypeManual->runAction(anim);
		
			std::string val = m_actionPvrPath;
		}
		if (anim == nullptr)
		{
			CPLUSLog("[addingRelies::bitsManyUnlike] get anim Fail, file = %s", m_actionPvrPath);
		}
}
#else
void addingRelies::bitsManyUnlike(float times,soonAlongMemberwise action,accessedIntroductory dir,int loop,float ltimes)
{
	bool isPlayDefaultAction = false;
	bool isSameAction = false;
	if(action == soonAlongMemberwise::ACTION_NONE && m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::ACTION_NONE)
		action = soonAlongMemberwise::stand;
	if(action == m_interchangeablyNamespaces.acttodo)
		isSameAction = true;
	imageRevisedCaltoFront(times,action,dir,loop,ltimes,false);
	if(m_boHide){
		return;
	}
	if(m_particularEyesAbstraction.size() > 0 && getspecializedComplication() != ACTION_STATE_ATTACK)
	{
		setordinarilyUpdate(m_particularEyesAbstraction);
		m_particularEyesAbstraction.clear();
		getchangingNeitherWhose(m_actionPvrPath);
	}
	else
	{
		if(returnsLetsOrdianary == false){
		
			getchangingNeitherWhose(m_actionPvrPath);
		
			if(m_recentCallpass.compare(m_actionPvrPath) == 0)
				return;
		
			if(numberedGrades.find(m_actionPvrPath) != numberedGrades.end()){
				char texPath[128] = "";
				sprintf(texPath,"%s.%s", m_actionPvrPath, m_colonStoplight.c_str());
				Texture2D* tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(texPath);
				if (tex == nullptr)
				{
				
					if ((m_type == wantedConvertibleGroup::RIDE_TYPE_UP || m_type == wantedConvertibleGroup::RIDE_TYPE_DOWN) && (action == soonAlongMemberwise::run || action == soonAlongMemberwise::walk))
					{
						isPlayDefaultAction = expansionManyQuiza();
					}
					hierarchyPointDynamic();
					elementsStunninglySame = false;
					m_dynamicallyThat = false;
					m_attemptParametethat = false;
					destroyingTotal = false;
					lettersLinkage = false;
					recognizeBitsOptional();
					m_recentCallpass = m_actionPvrPath;
				
				}
				else
				{
				
					char plistPath[128] = "";
					sprintf(plistPath,"%s.plist", m_actionPvrPath);
					if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false)
					{
					
						if ((m_type == wantedConvertibleGroup::RIDE_TYPE_UP || m_type == wantedConvertibleGroup::RIDE_TYPE_DOWN) && (action == soonAlongMemberwise::run || action == soonAlongMemberwise::walk))
						{
							isPlayDefaultAction = expansionManyQuiza();
						}
						hierarchyPointDynamic();
						elementsStunninglySame = true;
						m_dynamicallyThat = false;
						m_attemptParametethat = false;
						destroyingTotal = false;
						lettersLinkage = false;
						recognizeBitsOptional();
					
						if(!isPlayDefaultAction){
							m_reliesTypeManual->stopAllActions();
							m_interchangeablyNamespaces.animKey = "";
						}
						attemptsForgotStrategy(tex,m_actionPvrPath);
					
						return;
					}
				}
			}
		}
	}
	if(checkShow()){
		if(lettersLinkage)
			return;
		if(m_indicatesCheck){
			m_reliesTypeManual->stopAllActions();
			m_indicatesCheck = false;     
			lettersLinkage = true;
			std::function<void(void)> addRenderList = CC_CALLBACK_0(addingRelies::linkDisallowBitset,this);
			m_suitedIndicateVarying = stackSoonOrdianary::getInstance()->numbersCeaseListed(addRenderList,helpfulLarger::SPRITE_BASE);
		}else{
			if(m_timesNonexistent == false && isSameAction && (action == soonAlongMemberwise::stand || action == soonAlongMemberwise::run)){
				whsuggestInttypPrecede = true;
				m_timesNonexistent = false;
			}else{
				whsuggestInttypPrecede = false;
				m_timesNonexistent = true;
			}
			Animate* anim = expectationsVariadicMeans(m_loop);
			if(anim && m_timesNonexistent){
				m_reliesTypeManual->stopAllActions();
				m_timesNonexistent = false;
				m_reliesTypeManual->runAction(anim);
			
				
			}
		}
	}else{
		if (isPlayDefaultAction == false)
			m_reliesTypeManual->stopAllActions();
	}
}
#endif
void addingRelies::standed()
{
	if(m_incrementallyPostfix&&cerrResultsThroughCeases(ACTION_STATE_IDLE))
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		bitsManyUnlike(m_coutIdentical,stand,m_interchangeablyNamespaces.dir,0);
	}
}
float addingRelies::getthreeLoopsOperatingMatter(){
	return m_coutIdentical;
}
void addingRelies::whateverEvaluatesDerived(float times,int fly_mode,int handler,Vec2 newPos,accessedIntroductory dir,bool stand,bool auto_double_jump_check,bool checkSecondAction, int state){
}
void addingRelies::rewritesRedeclareLooth(float times,Point newpoint,bool stand){
}
void addingRelies::datsuchWhenDefinitions(float times,Point newpoint,bool stand){
}
void addingRelies::moveToPos(float times,Point newpoint,bool stand)
{
	if(getspecializedComplication()<ACTION_STATE_DEAD)
	{
		if(cerrResultsThroughCeases(ACTION_STATE_RUN)||setneedsTreturnDeclaration(newpoint))
		{
			setneedsTreturnDeclaration(newpoint);
			bitsManyUnlike(0.7f,run,m_interchangeablyNamespaces.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newpoint));
	}
}
void addingRelies::walkToPos(float times,Point newpoint,bool stand)
{
	if(getspecializedComplication()<ACTION_STATE_DEAD)
	{
		if(cerrResultsThroughCeases(ACTION_STATE_WALK)||setneedsTreturnDeclaration(newpoint))
		{
			setneedsTreturnDeclaration(newpoint);
			bitsManyUnlike(0.7f,walk,m_interchangeablyNamespaces.dir,0);
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newpoint));
	}
}
bool addingRelies::reasonsHaveBecause(float times,Point newpoint,accessedIntroductory dir,bool stand)
{
	if(getspecializedComplication()<ACTION_STATE_DEAD)
	{
		if(dir == dir_none && newpoint != Vec2::ZERO){
			dir = getmatchSaysValuelike(newpoint);
		}
		if(cerrResultsThroughCeases(ACTION_STATE_RUN)||setisbnsConstexprBuild(dir))
		{
			bitsManyUnlike(0.7f,run,dir,0);
		}
		if(newpoint != Point(0,0)){
			stopActionByTag(ACTION_MOVE_TAG);
			if(stand){
				FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
				auto action = Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}else{
				auto action = MoveTo::create(times,newpoint);
				action->setTag(ACTION_MOVE_TAG);
				runAction(action);
			}
		}
		return true;
	}
	return false;
}
bool addingRelies::existingLargerGrasp(float times,Point newpoint,accessedIntroductory dir)
{
	if(getspecializedComplication()<ACTION_STATE_DEAD)
	{
		if(cerrResultsThroughCeases(ACTION_STATE_WALK)||setisbnsConstexprBuild(dir))
		{
			bitsManyUnlike(0.7f,walk,dir,0);
		}
		if(newpoint != Point(0,0)){
			auto action =  MoveTo::create(times,newpoint);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}
		return true;
	}
	return false;
}
bool addingRelies::copiedMostPreferred(float times,Point newpoint,accessedIntroductory dir)
{
	return false;
}
bool addingRelies::othersBecauseAbstraction(float times,accessedIntroductory dir)
{
	if(cerrResultsThroughCeases(ACTION_STATE_CREATE)||setisbnsConstexprBuild(dir))
	{
		bitsManyUnlike(0.45f,create_,dir,0);
		return true; 
	}
	return false;
}
bool addingRelies::unequalParticularFreed(float times,Point newpoint,bool hasEffect)
{
	if(cerrResultsThroughCeases(ACTION_STATE_ATTACK))
	{
	
		if(newpoint != Point())
			setneedsTreturnDeclaration(newpoint);
		bitsManyUnlike(times,attack,m_interchangeablyNamespaces.dir,1);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;  
	}
	return false;
}
bool addingRelies::waysExonlyBackslashNever(float times,Point newpoint)
{
	if(cerrResultsThroughCeases(ACTION_STATE_ATTACK))
	{
		if(newpoint != Point(0,0))
			setneedsTreturnDeclaration(newpoint);
		bitsManyUnlike(times,attack,m_interchangeablyNamespaces.dir,1);
		return true;
	}
	return false;
}
bool addingRelies::parenthesesRelevant(float times,Point newpoint)
{
	if(cerrResultsThroughCeases(ACTION_STATE_MAGICUP))
	{
	
		if(newpoint != Point())
			setneedsTreturnDeclaration(newpoint);
		bitsManyUnlike(times,magicup,m_interchangeablyNamespaces.dir,1);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;
	}
	return false;
}
void addingRelies::gotoDeath(accessedIntroductory dir)
{
	if(cerrResultsThroughCeases(ACTION_STATE_DEAD))
	{
		setisbnsConstexprBuild(dir);
		float time = 1.5f;
		if (getTypeId() < 20)
			time = 0.3f;
		bitsManyUnlike(time,death,m_interchangeablyNamespaces.dir,1);
	
	
	}
}
void addingRelies::hasHurted(float delay,float times)
{
	if(cerrResultsThroughCeases(ACTION_STATE_HURT))
	{
		FiniteTimeAction* start = CallFunc::create([&](){ setWhite(true);});
		FiniteTimeAction* ended = CallFunc::create([&](){ setWhite(false);});
		runAction(Sequence::create(DelayTime::create(delay),start,DelayTime::create(times),ended,NULL));
	}
}
void addingRelies::failsQuizaMistake(int opac,float animTime){
	attemptsCollections = opac;
	int actionTimes = animTime/0.05f;
	destructorsAlternatively = getOpacity();
	if(attemptsCollections == destructorsAlternatively)
		return;
	if(attemptsCollections > destructorsAlternatively)
		m_subscriptUpdateLookup = 1;
	else
		m_subscriptUpdateLookup = 2;
	m_addsNumber = (attemptsCollections - getOpacity())/actionTimes;
	unschedule(schedule_selector(addingRelies::loopProvideView));
	schedule(schedule_selector(addingRelies::loopProvideView), 0.05f); 
	m_advancedDenoting = true;
}
void addingRelies::loopProvideView(float times){
	destructorsAlternatively += m_addsNumber;
	bool unAction = false;
	if(destructorsAlternatively <= 0)
	{
		unAction = true;
		destructorsAlternatively = 0;
	}
	else if(destructorsAlternatively >= 255)
	{
		unAction = true;
		destructorsAlternatively = 255;
	}else{
		if(m_subscriptUpdateLookup == 1){
			if(destructorsAlternatively >= attemptsCollections){
				unAction = true;
				destructorsAlternatively = attemptsCollections;
			}
		}else{
			if(destructorsAlternatively <= attemptsCollections){
				unAction = true;
				destructorsAlternatively = attemptsCollections;
			}
		}
	}
	setOpacity(destructorsAlternatively);
	if(unAction){
		m_advancedDenoting = false;
		unschedule(schedule_selector(addingRelies::loopProvideView));
	}
}
int addingRelies::setOpacity(int opact,bool update)
{
	if(update){
		for (auto& child : getChildren())
		{
			if(child->getTag()>=40 && child->getTag() < 70)
			{
				addingRelies* children = dynamic_cast<addingRelies*>(child);
				children->setOpacity(opact);
			}
			else if(child->getTag() == 110){
				child->getChildByTag(110)->setOpacity(opact);
			}
			else
			{
				child->setOpacity(opact);
			}
		}
	}
	if(m_dataSeen > 0 && m_actorId != ""){
		mubeReplacement::getInstance()->setOpacity(m_actorId,opact);
	}
	m_opact = opact;
	return 1;
}
int addingRelies::getOpacity()
{
	return m_opact;
}
bool addingRelies::moreIdenticalOperations(Touch* touch)
{
	if(m_positionMismatched == true){
		Point local = m_reliesTypeManual->convertTouchToNodeSpace(touch);
	
		Rect t_rect = Rect(0, 0, 120, 160);
		Size c_size =  m_reliesTypeManual->getContentSize();
	
		Rect r = Rect(c_size.width/2-t_rect.size.width/2,c_size.height/2 - 40,t_rect.size.width,t_rect.size.height);
	
		return r.containsPoint(local); 
	}
	return false;
}
 void addingRelies::setreduceRecognize(bool enabled){
	 m_positionMismatched = enabled;
 }
accessedIntroductory addingRelies::getmatchSaysValuelike(cocos2d::Point newpoint)
{
	accessedIntroductory dir = dir_right_down; 
	Point my_pos = getPosition();
	float dista = newpoint.getDistance(my_pos);
	Point direct = (newpoint - my_pos);
	if(dista<5 || dista>3000) return dir_right_down;
	if(((direct.x >= -0.000001) &&(direct.x <= 0.000001) && (direct.y >= -0.000001)&& (direct.y <= 0.000001)) )
	return dir_right_down;
	{
		double angel = atan2(std::abs(direct.y),std::abs(direct.x));
	
	
		if(angel < PI / 8)
		{
			if(direct.x < 0)
				if (direct.y >= 0.000001)
					dir = dir_left;
				else
					dir = dir_left_down;
			else
				if (direct.y >= 0.00001)
					dir = dir_right;
				else
					dir = dir_right_down;
		}
		else if(angel > PI * 3 / 8)
		{
			if(direct.y > 0)
				dir = dir_up;
			else
				dir = dir_down;
		}
		else
		{
			if(direct.x < 0 && direct.y < 0)
				dir = dir_left_down;
			else if(direct.x < 0 && direct.y > 0)
				dir = dir_left_up;
			else if(direct.x > 0 && direct.y > 0)
				dir = dir_right_up;
			else
				dir = dir_right_down;
		}
	}
	return dir;
}
bool addingRelies::setneedsTreturnDeclaration(Point newpoint)
{
	accessedIntroductory dir = getmatchSaysValuelike(newpoint);
	return setisbnsConstexprBuild(dir);
}
bool addingRelies::setisbnsConstexprBuild(accessedIntroductory dir)
{
	if(m_interchangeablyNamespaces.dir == dir)
		return false;
	else
	{
		m_interchangeablyNamespaces.dir = dir;
	}
	return true;
}
void addingRelies::setColor(const Color3B& color)
{
	for (auto& child : getChildren())
    {
	
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			addingRelies* children = dynamic_cast<addingRelies*>(child);
			if(children)
				children->setColor(color);
		}
		else if(child->getTag() == 110){
			child->getChildByTag(110)->setColor(color);
		}
	}
}
void addingRelies::setWhite(bool isgray)
{
	m_isWhite = isgray;
	for (auto& child : getChildren())
	{
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			addingRelies* children = dynamic_cast<addingRelies*>(child);
			if(children)
				children->setWhite(isgray);
		}
		else if(child->getTag() == 110){
			appliedDifferenceNoted* children = dynamic_cast<appliedDifferenceNoted*>(child->getChildByTag(110));
			if(children)
				children->setfunctiopresentedAssume2(isgray);
		}
	}
	if(hasptrHelp > 0 && m_actorId != ""){
		mubeReplacement::getInstance()->setinsteadCollideConsult(m_actorId,isgray);
	}
}
void addingRelies::setGray(bool isgray)
{
	for (auto& child : getChildren())
    {
	
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			addingRelies* children = dynamic_cast<addingRelies*>(child);
			if(children)
				children->setGray(isgray);
		}
		else if(child->getTag() == 110){
			appliedDifferenceNoted* children = dynamic_cast<appliedDifferenceNoted*>(child->getChildByTag(110));
			if(children)
				children->setcompareisbnRuntime(isgray);
		}
	}
	if(isgray)
	{
		stopAllActions();
		m_reliesTypeManual->stopAllActions();
	}
	else 
		standed();
}
Animate* addingRelies::expectationsVariadicMeans(int RepeatNum)
{
	Animation* donghua = getmainHeadIdentical();
	if(donghua == nullptr) return nullptr;
	if (m_interchangeablyNamespaces.isRepMode && handlesKeyword != m_type)
	{
		int currMaxCut = getDefActionNum(handlesKeyword, soonAlongMemberwise::stand);
		int tmpCut = getDefActionNum(handlesKeyword, m_interchangeablyNamespaces.acttodo);
		if (tmpCut != -1)
		{
			currMaxCut = tmpCut;
		}
		if(whsuggestInttypPrecede && currMaxCut != m_interchangeablyNamespaces.maxcut)
			m_timesNonexistent = true;
		m_interchangeablyNamespaces.maxcut = currMaxCut;
		donghua->setDelayPerUnit(m_interchangeablyNamespaces.m_nonpublicOwnsFunction / m_interchangeablyNamespaces.maxcut);
	}
	else if(m_interchangeablyNamespaces.m_nonpublicOwnsFunction > 0 )
	{
		int currMaxCut = m_interchangeablyNamespaces.intoBindingReallocates;
		int cut = m_interchangeablyNamespaces.m_isfifthPriceImportant;
		switch(m_interchangeablyNamespaces.acttodo)
		{
		case attack:
			switch (m_remainsPosition)
			{
			case 1:
				cut = m_interchangeablyNamespaces.m_exerciseZero;
				break;
			case 2:
				cut = m_interchangeablyNamespaces.m_parametethatNotify;
				break;
			case 3:
				cut = m_interchangeablyNamespaces.m_preprocessorCorrect;
				break;
			case 4:
				cut = m_interchangeablyNamespaces.copyingPassing;
				break;
			case 5:
				cut = m_interchangeablyNamespaces.m_cannotResponses;
				break;
			case 6:
				cut = m_interchangeablyNamespaces.m_cabeBuildsBinds;
				break;
			case 7:
				cut = m_interchangeablyNamespaces.m_onbitsContentColon;
				break;
			case 8:
				cut = m_interchangeablyNamespaces.semicolonNormal;
				break;
			case 9:
				cut = m_interchangeablyNamespaces.allocationSimilarly;
				break;
			case 10:
				cut = m_interchangeablyNamespaces.stoplightPassing;
				break;
			case 11:
				cut = m_interchangeablyNamespaces.m_reasonWrittenElemeis;
				break;
			case 12:
				cut = m_interchangeablyNamespaces.m_initiallyGreatly;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case run:
		case walk:
			if(getOnRide() == false)
				currMaxCut = m_interchangeablyNamespaces.includedIncomplete;
			else
				currMaxCut = m_interchangeablyNamespaces.occasionallyAlways;
			break;
		case stand:
		case standby:
			if(getOnRide() == false)
				currMaxCut = m_interchangeablyNamespaces.intoBindingReallocates;
			else
				currMaxCut = m_interchangeablyNamespaces.m_aliasWhsuggest;
			break;
		case hurt:
			currMaxCut = m_interchangeablyNamespaces.m_warrantFindbook;
			break;
		case magicup:
			currMaxCut = m_interchangeablyNamespaces.interactionEnumerator;
			break;
		case death:
			currMaxCut = m_interchangeablyNamespaces.initialBooks;
			break;
		case fly:
			switch (happensView)
			{
			case 1:
				cut = m_interchangeablyNamespaces.digitsExtensioindicating;
				break;
			case 2:
				cut = m_interchangeablyNamespaces.m_becomeReading;
				break;
			case 3:
				cut = m_interchangeablyNamespaces.unlikeNearlyLegal;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case hurt_idle:
			currMaxCut = m_interchangeablyNamespaces.choiceArticlesSoon;
			break;
		case hurt_kneel:
			currMaxCut = m_interchangeablyNamespaces.m_initializationAround;
			break;
		case attack_03:
			currMaxCut = m_interchangeablyNamespaces.m_coversPresumably;
			break;
		case attack_04:
			currMaxCut = m_interchangeablyNamespaces.supplyGranting;
			break;
		default:
			currMaxCut = m_interchangeablyNamespaces.intoBindingReallocates;
			break;
		}
		if(whsuggestInttypPrecede && currMaxCut != m_interchangeablyNamespaces.maxcut)
			m_timesNonexistent = true;
		m_interchangeablyNamespaces.maxcut = currMaxCut;
		donghua->setDelayPerUnit(m_interchangeablyNamespaces.m_nonpublicOwnsFunction/m_interchangeablyNamespaces.maxcut);
	}
	else  
	{
		donghua->setDelayPerUnit(2.0f/15.0f);
	}
	if(RepeatNum>0)
	{
		donghua->setLoops(RepeatNum);
		donghua->setRestoreOriginalFrame(false);
	}
	else
	{
		donghua->setLoops(-1);
		donghua->setRestoreOriginalFrame(true);
	}
	Animate* playdonghua = Animate::create(donghua);
	return playdonghua;
}
void addingRelies::booksChoseExploit(pushBoundthat toState)
{
	if(cerrResultsThroughCeases(toState))
	{
		stopAllActions();
		getrepresentExpands()->stopAllActions();
	}
}
void addingRelies::removedDetailsKids()
{
	stopAllActions();
	getrepresentExpands()->stopAllActions();
}
void addingRelies::getfriendsAllocateUlong(char* d)
{
	char actionName[128];
	int acttodo = static_cast<int>(m_interchangeablyNamespaces.acttodo);
	if (acttodo > -1 && acttodo <= ActionRescallpassSpeakMimic)
	{
		switch (m_interchangeablyNamespaces.acttodo)
		{
		case run:
		case walk:
		case stand:
		case standby:
			if(getOnRide() == false)
			{
			
				sprintf(actionName,"%s", ActionResName[acttodo]);
			}
			else
			{
			
				sprintf(actionName,"%s", "ride");
			}
			break;
		default:
			sprintf(actionName,"%s", ActionResName[acttodo]);
			break;
		}
	
	
	
	
	
	
	
	
	}
	memcpy(d, actionName, strlen(actionName));
}
void addingRelies::getchangingNeitherWhose(char *strpath)
{
	auto tmpStrUrl = m_interchangeablyNamespaces.spiritUrl;
	auto typeId = m_type;
	if (m_interchangeablyNamespaces.isRepMode)
	{
		tmpStrUrl = m_interchangeablyNamespaces.iostreamWhere;
		typeId = handlesKeyword;
	}
	auto i =  tmpStrUrl.find("/");
	auto sub_str = tmpStrUrl;
	if(std::string::npos != i)
	{
		if( typeId == RIDE_TYPE_UP || typeId == RIDE_TYPE_DOWN)
			sub_str =  sub_str.substr(0,i);
		else
			sub_str =  sub_str.substr(i+1);
	}
	char actionName[128] = "";
	switch (typeId)
	{
	case PLAYER_MANE_TYPE: 
	case PLAYER_FEMALE_TYPE:
		getfriendsAllocateUlong(actionName);
		sprintf(strpath,"res/roleplist/r_%s_%s", sub_str.c_str(), actionName);
		break;
	case WUQI_TYPE:
		getfriendsAllocateUlong(actionName);
		sprintf(strpath,"res/wuqiplist/w_%s_%s", sub_str.c_str(), actionName);
		break;
	case HEAD_TYPE:
		sprintf(strpath,"res/headplist/head");
		break;
	case WING_TYPE:
		getfriendsAllocateUlong(actionName);
		sprintf(strpath,"res/wingplist/wing_%s_%s",sub_str.c_str(), actionName);
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::stand)
		{
			sprintf(strpath,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
		}
		else if (m_interchangeablyNamespaces.acttodo == soonAlongMemberwise::run)
		{
			sprintf(strpath,"res/rideplist/ride_%s_%s",sub_str.c_str(), "run");
		}
		break;
	case SHOW_TYPE:
		sprintf(strpath,"res/showplist/s_%s",sub_str.c_str());
		break;
	case NORMAL_MONSTER:
	case ELIT_MONSTER:
	case BOSS_MONSTER:
	case JUQING_MONSTER:
		sprintf(strpath,"res/monster/m_%s",sub_str.c_str());
		break;
	case NPC_TYPE:
		sprintf(strpath,"res/npcplist/n_%s",sub_str.c_str());
		break;
	case ATTACK_EFFECT:
		sprintf(strpath,"res/skilleffcets/%s",sub_str.c_str());
		break;
	case TATTO_TYPE:
		sprintf(strpath,"res/longwenplist/l_%s",sub_str.c_str());
		break;
	case FAIRY_TYPE:
		sprintf(strpath,"res/fabaoplist/m_%s",sub_str.c_str());
		break;
	case MAGIC_WEAPON_TYPE:
		sprintf(strpath,"res/fabaoplist/sw_%s",sub_str.c_str());
		break;
	default:
		sprintf(strpath,"res/baseplist/b_%s",sub_str.c_str());
		break;
	}
}
void addingRelies::getnothingFlagCould(char *d, char *s, int num, bool old)
{
	if (strcmp(s, "") == 0)
	{
		getchangingNeitherWhose(m_actionPvrPath);
		s = m_actionPvrPath;
	}
	if (old)
		sprintf(d, "%s\0", s);
	else
		sprintf(d, "%s@%d\0", s, num - 1);
}
void addingRelies::setcarsOnlyLetterWithout(void)
{
	auto i =  m_interchangeablyNamespaces.spiritUrl.find("/");
	auto sub_str = m_interchangeablyNamespaces.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  m_interchangeablyNamespaces.spiritUrl.substr(0,i);
		else
			sub_str =  m_interchangeablyNamespaces.spiritUrl.substr(i+1);
	}
	switch (m_type)
	{
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		sprintf(m_defaultActionPath,"res/rideplist/ride_%s_stand.plist",sub_str.c_str());
		break;
	default:
		break;
	}
}
int addingRelies::remainsDifferenbetween(int dir_id)
{
	
		if (dir_id == 0)
			dir_id = 1;
		else if (dir_id == 2)
			dir_id = 1;
		else if(dir_id == 4)
			dir_id = 3;
		
	return dir_id;
}
void addingRelies::loadPlist()
{
	if (m_interchangeablyNamespaces.spiritUrl.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		FileUtils* utils = FileUtils::getInstance();
		static const int s_max_plist_num = 20;
		bool plistExist;
		bool hasFindNewPlistFile = false;
		char newStrUrl[256] = { 0 };
		for (int i = 1; i <= s_max_plist_num; i++)
		{
			getnothingFlagCould(newStrUrl, m_actionPvrPath, i);
			sprintf(newStrUrl, "%s.plist", newStrUrl);
			plistExist = utils->isFileExist(newStrUrl);
			if (!plistExist)
			{
				break;
			}
			hasFindNewPlistFile = true;
			cache->addSpriteFramesWithFileAsync(newStrUrl);
		
		
		
		}
		if (!hasFindNewPlistFile)
		{
			getnothingFlagCould(newStrUrl, m_actionPvrPath, 0, true);
			sprintf(newStrUrl, "%s.plist", newStrUrl);
			plistExist = utils->isFileExist(newStrUrl);
			if (plistExist)
			{
			
			
			
				cache->addSpriteFramesWithFileAsync(newStrUrl);
			}
			else
			{
				CPLUSLog("[addingRelies::loadPlist] ... Plist Not Find: %s", newStrUrl);
			}
		}
	}
}
#if (USER_NEW_PLAY_ACTION == 1)
Animation* addingRelies::setNowAct(const char *sprite_url, int count, int dir_id)
{
	Animation* act = nullptr;
	if (m_expandsBrace)
	{
		dir_id = remainsDifferenbetween(dir_id);
	}
	std::string tmpUrl = m_interchangeablyNamespaces.spiritUrl;
	if (m_interchangeablyNamespaces.isRepMode)
	{
		tmpUrl = m_interchangeablyNamespaces.iostreamWhere;
	}
	char animKey[128] = {0};
	sprintf(animKey, "%s%s%d", tmpUrl.c_str(), sprite_url, dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(whsuggestInttypPrecede && m_interchangeablyNamespaces.animKey.compare(animKey) != 0)
	{
		m_timesNonexistent = true;
	}
	m_interchangeablyNamespaces.animKey = animKey;
	if(cacheAnim)
	{
	
	
		act = cacheAnim;
		if(m_interchangeablyNamespaces.acttodo == death)
		{
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_reliesTypeManual->setSpriteFrame(backFrame);
		}
	}
	if(act == nullptr)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		act = Animation::create();
		char strurl[128] = "";
		bool bLoadPlist = false;
		bool bOutError = false;
		bool has_load_res = false;
		for(int i = 0; i < count ; i++)
		{
			std::string ss = tmpUrl;
			memset(strurl,0,128);
			sprintf(strurl, "%s%d%04d.png", sprite_url, dir_id, i);
			ss.append(strurl);
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if ((!bLoadPlist) && frame == nullptr)
			{
				bLoadPlist = true;
				loadPlist();
			}
		
			frame = cache->getSpriteFrameByName(ss);
			if (frame)
			{
			
			
			
				has_load_res = true;
				act->addSpriteFrame(frame);
				if (m_type > BASE_TYPE)
				{
					if ( (m_interchangeablyNamespaces.acttodo ==  death) && i == (count - 1))
					{
						m_reliesTypeManual->setSpriteFrame(frame);
					}
					else if ( (m_interchangeablyNamespaces.acttodo == attack ) && i==0)
					{
						if ((m_type < NORMAL_MONSTER)||(m_type > PET_MONSTER))
						{
							m_reliesTypeManual->setSpriteFrame(frame);
						}
					}
				}
			
			
			}
			else
			{
				if (!bOutError)
				{
					bOutError = true;
					if (i == 0)
						CPLUSLog("[addingRelies::setNowAct] error: %s", ss.c_str());
				}
			}
		}
		if (has_load_res)
		{
			AnimationCache::getInstance()->addAnimation(act, animKey);
		}
	}
	if(assigningUnderstand == false && m_nothingSelected > 0)
	{
		Vector<AnimationFrame*> frams = act->getFrames();
		if (frams.size() > 0)
		{
			assigningUnderstand = true;
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			if(m_nothingSelected > 0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				pStack->pushString(m_actorId.c_str());
				pStack->pushFloat(firstFrame->getRect().size.height);
				pStack->executeFunctionByHandler(m_nothingSelected, 2);
				pStack->clean();
			}
		}
	}
	return act;
}
#else
Animation* addingRelies::setNowAct(const char *sprite_url,int count,int dir_id)
{
	Animation* act = nullptr;
	if (m_expandsBrace)
	{
		dir_id = remainsDifferenbetween(dir_id);
	}
	char animKey[128];
	sprintf(animKey,"%s%s%d",m_interchangeablyNamespaces.spiritUrl.c_str(),sprite_url,dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(whsuggestInttypPrecede && m_interchangeablyNamespaces.animKey.compare(animKey) != 0){
		m_timesNonexistent = true;
	}
	m_interchangeablyNamespaces.animKey = animKey;
	bool has_load_res = false;
	if(cacheAnim){
	
		
		has_load_res = true;
		act = cacheAnim;
		if(m_interchangeablyNamespaces.acttodo ==  death){
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_reliesTypeManual->setSpriteFrame(backFrame);
		}
	}
	if(act == nullptr){
		bool tryLoadRes = false;   
		act = Animation::create();
		char strurl[128] = "";
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		for(int i = 0; i < count ; i++)
		{
			std::string ss = m_interchangeablyNamespaces.spiritUrl;
			memset(strurl,0,128);
			sprintf(strurl,"%s%d%04d.png",sprite_url,dir_id,i);
			ss.append(strurl);
		
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if(frame)
			{
				has_load_res = true;
				act->addSpriteFrame(frame);
				if(m_interchangeablyNamespaces.acttodo ==  death && i==(count-1))
				{
					m_reliesTypeManual->setSpriteFrame(frame);
				}
			}
			else if(i == 0 && tryLoadRes == false)
			{
			
			
				tryLoadRes = true;
				memset(strurl,0,128);
				if(m_interchangeablyNamespaces.spiritUrl.length()>1)
				{
					if(m_operatesRange > 1)
					{
						for(int i=1;i<=m_operatesRange;i++)
						{
						
							getnothingFlagCould(strurl, m_actionPvrPath, i);
							sprintf(strurl,"%s.plist",strurl);
							cache->addSpriteFramesWithFile(strurl);
						}
					}
					else
					{
					
						memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
						sprintf(strurl,"%s.plist",strurl);
						cache->addSpriteFramesWithFile(strurl);
					}
				}
				i -= 1;
			}
		}
		if(act && has_load_res == true){
		
			AnimationCache::getInstance()->addAnimation(act,animKey);
		}
	}
	if(has_load_res && returnsLetsOrdianary == false){
	
		if(numberedGrades.size() > 0){
			bool find = false;
			for(auto it = numberedGrades.begin();it != numberedGrades.end();){
				std::string info = (*it).first;
				if(info.compare(m_actionPvrPath) == 0){
					find = true;
					numberedGrades.erase(it++);
					break;
				}else{
					it++;
				}
			}
			if(find){
				Vector<AnimationFrame*> frams = act->getFrames();
				SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
				firstFrame->retain();
				m_threeLimits.push_back(firstFrame);
			}
			if(numberedGrades.size() <= 0)
				returnsLetsOrdianary = true;
		}else{
			returnsLetsOrdianary = true;
			Vector<AnimationFrame*> frams = act->getFrames();
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			firstFrame->retain();
			m_threeLimits.push_back(firstFrame);
		}
	}
	if(has_load_res && assigningUnderstand == false){
		Vector<AnimationFrame*> frams = act->getFrames();
		assigningUnderstand = true;
		SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
	
	
		m_reliesTypeManual->setSpriteFrame(firstFrame);
		if(m_interchangeablyNamespaces.acttodo ==  death){
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_reliesTypeManual->setSpriteFrame(backFrame);
		}
		if(m_nothingSelected > 0){
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			pStack->pushString(m_actorId.c_str());
			pStack->pushFloat(firstFrame->getRect().size.height);
			pStack->executeFunctionByHandler(m_nothingSelected, 2);
			pStack->clean();
		}
	}
	return act;
}
#endif
bool addingRelies::getinadvertentlyFragment()
{
	return disallowResult;
}
bool addingRelies::getthoughHighSure()
{
	return assigningUnderstand;
}
Animation* addingRelies::getmainHeadIdentical()
{
	Animation* act = nullptr;
	Node* node = nullptr;
	if (m_type == FAIRY_TYPE)
	{
		node = m_reliesTypeManual;
	}
	else if (m_type == MAGIC_WEAPON_TYPE)
	{
		node = Node::create();
	}
	else
	{
		node = main_node;
	}
	node->setScaleX(1);
	int dir_id = 0;
	switch (m_interchangeablyNamespaces.dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		node->setScaleX(-1);
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		node->setScaleX(-1);
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		node->setScaleX(-1);
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
	 
	switch (m_interchangeablyNamespaces.acttodo)
	{
	case walk:
	case run:
		if(getOnRide() == false){
			if(surprisinglyThrough)
				act = setNowAct("/run/",m_interchangeablyNamespaces.includedIncomplete,dir_id);
		}else{
			if(m_patternsDelegate)
				act = setNowAct("/ride_run/",m_interchangeablyNamespaces.occasionallyAlways,dir_id);
		}
		break;
	case stand:
	case standby:
		if(getOnRide() == false){
			if(m_incrementallyPostfix)
				act = setNowAct("/stand/",m_interchangeablyNamespaces.intoBindingReallocates,dir_id);
		}else{
			if(m_patternsDelegate)
				act = setNowAct("/ride_stand/",m_interchangeablyNamespaces.m_aliasWhsuggest,dir_id);
		}
		break;
	case attack:
		if(causeValueduring)
		{
			char temp[32] = {0};
			if (m_remainsPosition > 0 && m_remainsPosition < 13)
			{
				sprintf(temp,"/attack_%02d/",m_remainsPosition);
			}
			else
			{
				sprintf(temp, "/attack/", "");
			}
			int cut = m_interchangeablyNamespaces.m_isfifthPriceImportant;
			switch (m_remainsPosition)
			{
			case 1:
				cut = m_interchangeablyNamespaces.m_exerciseZero;
				break;
			case 2:
				cut = m_interchangeablyNamespaces.m_parametethatNotify;
				break;
			case 3:
				cut = m_interchangeablyNamespaces.m_preprocessorCorrect;
				break;
			case 4:
				cut = m_interchangeablyNamespaces.copyingPassing;
				break;
			case 5:
				cut = m_interchangeablyNamespaces.m_cannotResponses;
				break;
			case 6:
				cut = m_interchangeablyNamespaces.m_cabeBuildsBinds;
				break;
			case 7:
				cut = m_interchangeablyNamespaces.m_onbitsContentColon;
				break;
			case 8:
				cut = m_interchangeablyNamespaces.semicolonNormal;
				break;
			case 9:
				cut = m_interchangeablyNamespaces.allocationSimilarly;
				break;
			case 10:
				cut = m_interchangeablyNamespaces.stoplightPassing;
				break;
			case 11:
				cut = m_interchangeablyNamespaces.m_reasonWrittenElemeis;
				break;
			case 12:
				cut = m_interchangeablyNamespaces.m_initiallyGreatly;
				break;
			default:
				break;
			}
		
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt:
		if(m_fairlyInitializersNeeded)
			act = setNowAct("/injured/",m_interchangeablyNamespaces.m_warrantFindbook,dir_id);
		break;
	case death:
		if(m_indicateLiteral)
			act = setNowAct("/death/",m_interchangeablyNamespaces.initialBooks,dir_id);
		break;
	case magicup:
	
		if(m_instantiatedRequiresCast)
		{
			char temp[32] = {0};
			if (m_remainsPosition > 0 && m_remainsPosition < 3)
			{
				sprintf(temp,"/attack_%02d/",m_remainsPosition);
			}
			else
			{
				sprintf(temp,"/attack/%s","");
			}
			act = setNowAct(temp,m_interchangeablyNamespaces.interactionEnumerator,dir_id);
		}
		break;
	case fly:
		if(computeIntending){
			char temp[32] = {0};
			sprintf(temp,"/fly_%02d/",happensView);
			int cut = m_interchangeablyNamespaces.digitsExtensioindicating;
			switch (happensView){
			case 1:
				cut = m_interchangeablyNamespaces.digitsExtensioindicating;
				break;
			case 2:
				cut = m_interchangeablyNamespaces.m_becomeReading;
				break;
			case 3:
				cut = m_interchangeablyNamespaces.unlikeNearlyLegal;
				break;
			default:
				break;
			}
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt_idle:
		if(m_loopAffects)
			act = setNowAct("/hurt_idle/",m_interchangeablyNamespaces.choiceArticlesSoon,dir_id);
		break;
	case hurt_kneel:
		if(m_hiddenRefersInitially)
			act = setNowAct("/hurt_kneel/",m_interchangeablyNamespaces.m_initializationAround,dir_id);
		break;
	case attack_03:
		if(omitToolsDerivation)
			act = setNowAct("/attack_03/",m_interchangeablyNamespaces.m_coversPresumably,dir_id);
		break;
	case attack_04:
		if(omitToolsDerivation)
			act = setNowAct("/attack_04/",m_interchangeablyNamespaces.supplyGranting,dir_id);
		break;
	case collide:
		if(m_instantiatedRequiresCast)
			act = setNowAct("/collide/",m_interchangeablyNamespaces.interactionEnumerator,dir_id);
		break;
	case dig:
		act = setNowAct("/dig/",1,dir_id);
		break;
	case excavate:
		act = setNowAct("/excavate/",3,dir_id);
		break;
	case create_:
		act = setNowAct("/create/",4,dir_id);
		break;
	default:
		break;
	}
	return act;
}
void addingRelies::refresh(){
	bitsManyUnlike(-1,ACTION_NONE,dir_none,-100,-1);
}
bool addingRelies::cerrResultsThroughCeases(pushBoundthat actionState)
{
	if( findbookPromotion == actionState && actionState!=ACTION_STATE_IDLE)
	{
		if(findbookPromotion == ACTION_STATE_WALK||findbookPromotion ==ACTION_STATE_RUN)
			return false;
	}
	if((findbookPromotion == ACTION_STATE_DEAD && actionState != ACTION_STATE_REMOVE ))
	{
		this->stopAllActions();
		return false;
	}
	if( beControl() && actionState != ACTION_STATE_DEAD && actionState != ACTION_STATE_IDLE)
	{
		return false;
	}
	if(actionState == ACTION_STATE_DEAD){
		this->stopAllActions();
	}
	findbookPromotion = actionState;
	return true;
}
bool addingRelies::beControl()
{
	if ( findbookPromotion >= ACTION_STATE_CHENMO && findbookPromotion <= ACTION_STATE_CHAOS)
	{
		return true;
	}
	return false;
}
Vec2 addingRelies::getshorttypOrdinaryOught(accessedIntroductory dir) 
{
	switch (dir)
	{
	case dir_up:
		return  Vec2(0,-16);
	case dir_down:
		return  Vec2(0,16);
	case dir_left:
		return  Vec2(24,0);
	case dir_right:
		return  Vec2(-24,0);
	case dir_left_up:
		return  Vec2(24,-16);
	case dir_right_up:
		return  Vec2(-24,-16);
	case dir_left_down:
		return  Vec2(24,16);
	case dir_right_down:
		return  Vec2(-24,16);
	default:
		return  Vec2(0,-16);
	}
	return Vec2::ZERO;
}
Vec2 addingRelies::getimagefifthCompilation5(accessedIntroductory dir){
	return (getshorttypOrdinaryOught(dir)*-1).getNormalized();
}
int addingRelies::getparenthesesPromotion(Sprite* sp,accessedIntroductory dir)
{
	int dir_id = 0;
	switch (dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		dir_id = -2;
		break;
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		dir_id = -1;
		break;
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		dir_id = -3;
		break;
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
	if(m_type == WING_TYPE&&(m_interchangeablyNamespaces.acttodo==attack||m_interchangeablyNamespaces.acttodo==excavate||m_interchangeablyNamespaces.acttodo==collide||m_interchangeablyNamespaces.acttodo==magicup))
	{
		bool unneed_flip = false;
		switch (dir)
		{
			case dir_left:
				dir_id = 6;
				unneed_flip = true;
				break;
			case dir_left_up:
				dir_id = 7;
				unneed_flip = true;
				break;
			case dir_left_down:
				dir_id = 5;
				unneed_flip = true;
				break;
			default:
				break;
		}
		if(unneed_flip&&sp)
			sp->setFlippedX(false);
	}
	return dir_id;
}
bool addingRelies::occurrenceTightlySignals(float times,Vec2 pos,accessedIntroductory dir)
{
	if(getspecializedComplication() != ACTION_STATE_FLY && getspecializedComplication() != ACTION_STATE_SUDDEN && getspecializedComplication()<ACTION_STATE_DEAD)
	{
		stopActionByTag(ACTION_SHADOW_TAG);
		setisbnsConstexprBuild(dir);
		bitsManyUnlike(-1,ACTION_NONE,dir_none,-100,-1);
		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
		
			this->rememberLoothIath(0);
		}),nullptr));
		shadownAction->setTag(ACTION_SHADOW_TAG);
		runAction(shadownAction);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
			this->standed();
			stopActionByTag(ACTION_SHADOW_TAG);
		});
		auto moveAction = MoveTo::create(times,pos);
		auto action = Sequence::create(moveAction,actbackfun,nullptr);
		action->setTag(ACTION_MOVE_TAG);
		runAction(action);
		return true;
	}
	return false;
}
void addingRelies::setOnRide(int ride_id){
	m_intuitiveDecrements = ride_id;
}
bool addingRelies::getOnRide(){
	return !(m_intuitiveDecrements == 0);
}
int addingRelies::getprimaryFactIterator(){
	return m_intuitiveDecrements;
}
int addingRelies::getLocalZOrder()
{
	return this->_localZOrder;
}
void addingRelies::setpatternResultNodefault(int attackMode)
{
	m_remainsPosition = attackMode;
}
int addingRelies::getpatternResultNodefault()
{
	return m_remainsPosition;
}
void addingRelies::setprogrammingQualifying(int flyMode){
	happensView = flyMode;
}
void addingRelies::setResId(int resId)
{
	m_resId = resId;
}
int addingRelies::getResId(void)
{
	return m_resId;
}
void addingRelies::setprvoidExtensioindicating(const bool isReorder) 
{ 
	Node* parent = getParent();
	if (parent != nullptr) 
	{ 
		parent->setReorderChildDirty(isReorder);
	} 
};
void addingRelies::setVisible(bool visible)
{ 
	if(m_boHide)
		visible = false;
	bool old_visible = isVisible();
	if(m_father == nullptr)
	{
		Node::setVisible(visible);
	}
	else
	{
		if(m_father->isVisible()){
			Node::setVisible(visible);
		}
	}
	m_predictCallpass = visible;
	if(visible != old_visible)
	{
	
	
	
	
	
	
	
	
	
	
	
		if(numberedNormallyElemtype > 0 && m_actorId != "")
		{
			mubeReplacement::getInstance()->setVisible(m_actorId,visible);
		}
	}
}
void addingRelies::setshownRatherInitially(bool visible)
{ 
	if(m_constructingUnableIsbns != visible){
		if(m_alsoGeneratesKnew > 0 && m_actorId != ""){
			mubeReplacement::getInstance()->setshownRatherInitially(m_actorId,visible);
		}
	}
	m_constructingUnableIsbns = visible;
}
void addingRelies::setcompilerStoprocessing(bool visible)
{
	Node::setVisible(visible);
}
void addingRelies::printedClosePeppers(int handler)
{
	m_dataSeen = handler;
}
void addingRelies::operationDesigning()
{
	m_dataSeen = 0;
}
void addingRelies::assignReliesSeparator(int handler)
{
	numberedNormallyElemtype = handler;
}
void addingRelies::compilationCerrIntended()
{
	numberedNormallyElemtype = 0;
}
void addingRelies::relativeEcmascriptBuilt(int handler)
{
	 m_alsoGeneratesKnew = handler;
}
void addingRelies::tuplesCandidateTopics()
{
	m_alsoGeneratesKnew = 0;
}
void addingRelies::wilreferKnowsInvolved(int handler)
{
	hasptrHelp = handler;
}
void addingRelies::matrixExecutingCompilers()
{
	hasptrHelp = 0;
}
void addingRelies::strvecCurrentPushed(int handler){
	m_assumesEncapsulation = handler;
}
void addingRelies::unlessSupplyTreated()
{
	m_assumesEncapsulation = 0;
}
void addingRelies::effectEliminatedReference(int handler){
	m_nothingSelected = handler;
}
void addingRelies::parametersunlikeRemoved(){
	m_nothingSelected = 0;
}
void addingRelies::compilerStringsthe(float time){
	auto delayAction = DelayTime::create(time);
	auto westoreWidthTypes = CallFunc::create([&](){
		stopAllActions();
		this->removeFromParent();
	});
	runAction(Sequence::create(delayAction,westoreWidthTypes,nullptr));
}
void addingRelies::rememberLoothIath(float dt)
{
	if(m_boHide)
		return;
	SpriteFrame* spriteFrame = m_reliesTypeManual->getSpriteFrame();
	leftBeganAppear* effect = leftBeganAppear::create(spriteFrame);
	Vec2 m_reliesTypeManual_pos = m_reliesTypeManual->getPosition();
	m_reliesTypeManual_pos.add(this->getPosition());
	effect->setAnchorPoint(m_reliesTypeManual->getAnchorPoint());
	effect->setPosition(m_reliesTypeManual_pos);
	effect->setLocalZOrder(getLocalZOrder());
	effect->setOrderOfArrival(getOrderOfArrival());
	this->getParent()->addChild(effect);
	int dir_id = 0;
	switch (m_interchangeablyNamespaces.dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		effect->setFlippedX(true);
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		effect->setFlippedX(true);
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		effect->setFlippedX(true);
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
}
void addingRelies::setRenderMode(int val)
{
	if (m_reliesTypeManual)
	{
		m_reliesTypeManual->setRenderMode(val);
	}
}
short addingRelies::divideWouldBetterResult(long lifetime,void * despite,char aside)
{
	float legal;
	legal = 919.3f;
	float height;
	height = 366.9f;
	return 52;
}
void addingRelies::tediousEncapsulates(int named)
{
	double destroyed;
	destroyed = 304.19;
	char omits;
	omits = 'E';
	char treats;
	treats = 'O';
}
double addingRelies::askedOptionsConceptually(char empty,void * sale,int whether,unsigned short pointerlike)
{
	bool icase;
	icase = false;
	long pairs;
	pairs = 446;
	return 399.12;
}
char addingRelies::versionInttypAccessible(float prefer,unsigned short accessible,float turns,void * assume)
{
	long effect;
	effect = 25;
	double entire;
	entire = 823.10;
	int enough;
	enough = 143;
	float illustration;
	illustration = 777.17f;
	return '4';
}
int addingRelies::hidesFriendshipMembers(float marker,float included,void * suppress)
{
	bool familiar;
	familiar = false;
	double chapters;
	chapters = 998.9;
	short features;
	features = 688;
	return 673;
}
void addingRelies::programmingSectionsSchema(float problem)
{
	short scopes;
	scopes = 382;
	float movement;
	movement = 825.2f;
}
void addingRelies::functionfunctionNext(short verify,void * entire)
{
	double naturally;
	naturally = 731.4;
	bool points;
	points = true;
}
void addingRelies::considerDescribeUnequal(long overall,bool similarly)
{
	int disadvantages;
	disadvantages = 756;
	unsigned short seen;
	seen = 319;
	unsigned short ordianary;
	ordianary = 151;
}
void addingRelies::classesFullyTypically(double violations,short prefi,double same,short compilers)
{
	int compare;
	compare = 717;
}
int addingRelies::algorithmConstsFind4(float abstract,long revise)
{
	char fail;
	fail = 'F';
	int wants;
	wants = 351;
	void * making;
	making = nullptr;
	return 857;
}
void * addingRelies::treatedOnceEachLook(bool hence)
{
	double rest;
	rest = 918.8;
	void * contadeclarations;
	contadeclarations = nullptr;
	return nullptr;
}
unsigned short addingRelies::definedErrorsDigits(float versions,short normal,bool driven)
{
	unsigned short compareisbn;
	compareisbn = 924;
	return 431;
}
