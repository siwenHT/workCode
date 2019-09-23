#include "copiedFlipsActual.h"
#include "confusionSwapThrough.h"
#include "startsEvaluating.h"
#include "emptyOrientedVice.h"
#include "CCLuaEngine.h"
#include "namespacesNeededFails.h"
#include "isbnConstructorRecognize.h"
#include "directionsIncidental.h"
USING_NS_CC;
static const int ActionResenumerationOnlyFeatures = 19;
static const char* ActionResName[ActionResenumerationOnlyFeatures] = 
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
static const int ActionShowType[ActionResenumerationOnlyFeatures] = 
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
static int getDefActionNum(extendedUsesMatch typeId, stringsLargeEspecially toDo)
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
copiedFlipsActual::copiedFlipsActual()
{
	everyFunctionfunction = false;
	m_statementsReadNotify = false;
	m_initializerAllocates = false;
	m_meansAkin = false;
	m_extendMachine = false;
	outerBehind = false;
	m_preferAttemptedOmitting = false;
	m_suchMemberwise = false;
	derivedContadeclarations = false;
	recursiveConcludesArgs = false;
	m_curtokArrayCompiler = false;
	m_essentiallyActuasize = false;
	m_isWhite = false;
	failsTrans = true;
	outsideBehaviorSections = false;
	m_givenStatements = false;
	movingRemovedNote = 0;
	m_functionalthoughJumping = NULL;
	callableLookupLimitation = 1;
	m_functionality = 0;
	wholeSpecialObjectsth.dir=  dir_right_up;
	wholeSpecialObjectsth.maxcut = 6;
	wholeSpecialObjectsth.acttodo = ACTION_NONE;
	wholeSpecialObjectsth.m_pointImagefifth = 1.0f;
	wholeSpecialObjectsth.animKey = "";
	m_loop = 0;
	m_wantedEvaluated = Vec2::ZERO;
	m_correspondBlobptr = Vec2::ZERO;
	m_type = BASE_TYPE;
	diskSelects = true;
	rolesPreceding.clear();
	tokensVariableInteresting = 0;
	m_whifPassingIncreased = 1;
	m_mightRunsWords = 0;
	shouldInstantionControl = actionsThgenerates_EMPTY;
	itselfProperlyRemoved = extendedUsesMatch::BASE_TYPE;
	m_ischeck = true;
	differentManipulateLarger = false;
	m_groupDoubledPrevious = false;
	writeInteraction = false;
	m_argumepassedAssigns = false;
	m_lookupOriginal = false;
	abstractCentral = false;
	manageModify = 0;
	independentlyPackBook = 0;
	techniqueResource = 0;
	somewhatStopsCharacters();
	languagePrefi = nullptr;
	m_askingExecuted = ACTION_STATE_NONE;
	normallyAlgorithmsPersist = isVisible(); 
	flagWords = "png";
	encapsulationArguments = false;
	allowedStrictly = "";
	describeMultidimensional = "";
	includeRealizing = "";
	m_powerfulProtection = false;
	m_mismatchedRationale = 255;
	m_cerrQualifying = 255;
	tyhaveAdvance = 255;
	m_yourUninitialized = 1;   
	m_resId = 0;
	m_actorId = "";
	independentlyEnumerations = 0;
	m_convertingSequenceProvide.x = 0;
	m_convertingSequenceProvide.y = 0;
	m_especiallyIath = 0;
	unchangedIntended = 0;
	m_wroteRatherRecently = 0;
	m_simplyElemeisAggregate = 0;
	m_father = nullptr;
	m_opact = 255;
	m_rememberExecutes = 0;
	m_cmatchSeparatorMatter = 0;
	m_boHide = false;
	m_primaryIand = true;
	m_typcanPrevents = 0;
	m_employeeInaccessible = true;
	m_variableSmart = false;
	wholeSpecialObjectsth.isRepMode = false;
	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	memset(m_defaultActionPath, 0, sizeof(m_defaultActionPath));
	m_peopleSettingReplaces = false;
}
copiedFlipsActual::~copiedFlipsActual(void)
{
	rolesPreceding.clear();
	m_promotesTuple.clear();
	for(std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter = fromGivenNumbered.begin();iter != fromGivenNumbered.end();iter++){
		if(iter->second){
			_eventDispatcher->removeEventListener(iter->second);
		}
	}
	fromGivenNumbered.clear();
	minimizeDiscussioofWithin4();
	differentlyPattern();
}
void copiedFlipsActual::cleanup(){
	Node::cleanup();
	differentlyPattern();
}
void copiedFlipsActual::differentlyPattern(){
	if(independentlyPackBook != 0 && !describeMultidimensional.empty()){
		bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(describeMultidimensional,independentlyPackBook);
		CCASSERT(isFind == true, "copiedFlipsActual independentlyPackBook remove Fail");
		independentlyPackBook = 0;
	}
	m_promotesTuple.clear();
	if(manageModify != 0 && !allowedStrictly.empty()){
		bool isFind = namespacesNeededFails::getInstance()->programmerDefininside(allowedStrictly,manageModify);
		CCASSERT(isFind == true, "copiedFlipsActual manageModify remove Fail");
		manageModify = 0;
	}
	if(techniqueResource != 0){
		directionsIncidental::getInstance()->zeroInitializingRefer(techniqueResource);
		techniqueResource = 0;
	}
	includeRealizing = "";
}
bool copiedFlipsActual::initWithFile(const std::string&m_ableCover, std::string actorId)
{
	main_node = Node::create();
	addChild(main_node,4,110);
	m_functionalthoughJumping = withDesigned::create();
	wholeSpecialObjectsth.spiritUrl = m_ableCover;
	m_actorId = actorId;
	if(m_functionalthoughJumping == NULL)
	{
		return false;
	}
	main_node->addChild(m_functionalthoughJumping,4,110);
	return true;
}
void copiedFlipsActual::setTypeId(extendedUsesMatch typeId,bool initDepend){
	m_type = typeId;
	if(initDepend)
		leadsEntireConcludes();
}
void copiedFlipsActual::setIsHide(bool hide){
	m_boHide = hide;
	m_functionalthoughJumping->stopAllActions();
	wholeSpecialObjectsth.animKey = "";
}
void copiedFlipsActual::somewhatStopsCharacters(){
	if(!m_ischeck) 
	
		shouldInstantionControl = actionsThgenerates_EMPTY;
	else{
	
		shouldInstantionControl = actionsThgenerates_ASSET;
		if(differentManipulateLarger){
		
			shouldInstantionControl = actionsThgenerates_LOADED;
			if(m_groupDoubledPrevious)
				shouldInstantionControl = actionsThgenerates_ALL;
		}
	}
}
bool copiedFlipsActual::elementMattersApplication1(){
	return shouldInstantionControl == actionsThgenerates_ALL;
}
void copiedFlipsActual::reset(){
	differentlyPattern();
	differentManipulateLarger = false;
	m_argumepassedAssigns = false;
	m_groupDoubledPrevious = false;
	m_lookupOriginal = false;
	abstractCentral = false;
	somewhatStopsCharacters();
	m_variableSmart = false;
}
void copiedFlipsActual::minimizeDiscussioofWithin4(){
	for(auto iter = m_whversionEncapsulates.begin();iter != m_whversionEncapsulates.end();iter++){
		(*iter)->release();
	}
	m_whversionEncapsulates.clear();
}
void copiedFlipsActual::leadsEntireConcludes(){
	minimizeDiscussioofWithin4();
	if (true)
	{
		return;
	}
	m_peopleSettingReplaces = false;
	m_obtainOmitting.clear();
	char strurl[128] = "";
	char strurl_action[128] = "";
	auto i =  wholeSpecialObjectsth.spiritUrl.find("/");
	auto sub_str = wholeSpecialObjectsth.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  wholeSpecialObjectsth.spiritUrl.substr(0,i);
		else
			sub_str =  wholeSpecialObjectsth.spiritUrl.substr(i+1);
	}
	char actionName[128] = "";
	switch (m_type)
	{
	case PLAYER_MANE_TYPE: 
	
		sprintf(strurl,"res/roleplist/r_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case PLAYER_FEMALE_TYPE:
	
		sprintf(strurl,"res/roleplist/r_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"ride");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case WUQI_TYPE:
		sprintf(strurl,"res/wuqiplist/w_%s", sub_str.c_str());
		if(itselfProperlyRemoved != extendedUsesMatch::BASE_TYPE && itselfProperlyRemoved == extendedUsesMatch::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action,"%s_%s",strurl,"attack");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"normal");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
			sprintf(strurl_action,"%s_%s",strurl,"attack");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"normal");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		
		
		
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"%s_%s",strurl,"ride");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		}
		break;
	case HEAD_TYPE:
		break;
	case WING_TYPE:
		sprintf(strurl,"res/wingplist/wing_%s", sub_str.c_str());
		sprintf(strurl_action,"%s_%s",strurl,"attack");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"normal");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
	
	
	
		memset( strurl_action, 0, sizeof(strurl_action) );
		sprintf(strurl_action,"%s_%s",strurl,"ride");
		m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if(itselfProperlyRemoved != extendedUsesMatch::BASE_TYPE && itselfProperlyRemoved == extendedUsesMatch::PLAYER_MANE_TYPE){
		
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
		}else{
		
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
			memset( strurl_action, 0, sizeof(strurl_action) );
			sprintf(strurl_action,"res/rideplist/ride_%s_%s",sub_str.c_str(), "run");
			m_obtainOmitting.insert(std::pair<std::string,int>(strurl_action,1));
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
void copiedFlipsActual::setknowPdataOrganize(const std::string&m_ableCover)
{
	if(getappeaanywhereScopedBasic() == ACTION_STATE_ATTACK){
		rolesPreceding = m_ableCover;
		return;
	}
	if(wholeSpecialObjectsth.spiritUrl.compare(m_ableCover) != 0){
		differentlyPattern();
	
	
	
	
	
		somewhatStopsCharacters();
		m_variableSmart = false;
		wholeSpecialObjectsth.spiritUrl = m_ableCover; 
		leadsEntireConcludes();
	}
	wholeSpecialObjectsth.spiritUrl = m_ableCover; 
	if (m_type == extendedUsesMatch::RIDE_TYPE_UP || m_type == extendedUsesMatch::RIDE_TYPE_DOWN)
	{
		setindirectNonexistentWish();
	}
}
void copiedFlipsActual::setconversionchapterModel(cocos2d::Point anchorPoint){
	m_functionalthoughJumping->setAnchorPoint(anchorPoint);
}
void copiedFlipsActual::setstartingBasicsNamespaces(cocos2d::Point pos){
	m_functionalthoughJumping->setPosition(pos);
}
copiedFlipsActual *copiedFlipsActual::create(const std::string&m_ableCover)
{
    copiedFlipsActual *pRet = new copiedFlipsActual();
    if (pRet && pRet->initWithFile(m_ableCover))
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
copiedFlipsActual* copiedFlipsActual::create(const std::string&m_ableCover, std::string actorId)
{
	copiedFlipsActual *pRet = new copiedFlipsActual();
	if (pRet && pRet->initWithFile(m_ableCover, actorId))
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
copiedFlipsActual *copiedFlipsActual::create(const std::string&m_ableCover,Size touch_size)
{
    copiedFlipsActual *pRet = new copiedFlipsActual();
    if (pRet && pRet->initWithFile(m_ableCover))
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
void copiedFlipsActual::distinctEndingLiteral(int standcut,int runcut, int attackcut, int gethitcut, int deathcut, int maxcut2,float times,auxiliaryEssential dir)
{
	wholeSpecialObjectsth.m_pointsunlikeUnrelated = standcut;
	m_couldMismatched = times;
	if((int)dir != -1)
		wholeSpecialObjectsth.dir=  dir;
	everyFunctionfunction = true;
	headExecutableUnique("",runcut);
	actionsEntryLanguage("",attackcut);
	overloadedThemselves("",maxcut2);
	anotherWholeTypically("",maxcut2);
	bypassControlsTakes("",deathcut);
}
void copiedFlipsActual::bypassControlsTakes(const std::string&m_ableCover,int maxcut)
{
	if(maxcut != -1){
		wholeSpecialObjectsth.m_askedThgenerates = maxcut;
		m_preferAttemptedOmitting = true;
	}
}
void copiedFlipsActual::headExecutableUnique(const std::string&m_ableCover,int maxcut)
{
	if(maxcut != -1){
		wholeSpecialObjectsth.incompletePrintValuelike = maxcut;
		m_initializerAllocates = true;
	}
}
void copiedFlipsActual::actionsEntryLanguage(const std::string&m_ableCover,int maxcut)
{
	if(maxcut != -1){
		wholeSpecialObjectsth.m_shareNatureLargest = maxcut;
		m_meansAkin = true;
	}
}
void copiedFlipsActual::overloadedThemselves(const std::string&m_ableCover,int maxcut)
{ 
	if(maxcut != -1){
		wholeSpecialObjectsth.m_differenceReduceThird = maxcut;
		m_extendMachine = true;
	}
}
void copiedFlipsActual::anotherWholeTypically(const std::string&m_ableCover,int maxcut)
{
	if(maxcut != -1){
		wholeSpecialObjectsth.m_destructionRemaining = maxcut;
		outerBehind = true;
	}
}
void copiedFlipsActual::throughoutDigitsExtent(int m_alsoCompletesReferencwhat,int compareisbnLiterals,int seenDigitsPresented)
{
	wholeSpecialObjectsth.m_alsoCompletesReferencwhat = m_alsoCompletesReferencwhat;
	wholeSpecialObjectsth.compareisbnLiterals = compareisbnLiterals;
	wholeSpecialObjectsth.seenDigitsPresented = seenDigitsPresented;
	m_suchMemberwise = true;
}
void copiedFlipsActual::leavingNumberAccessible2(const std::string&m_ableCover,int maxcut)
{
	wholeSpecialObjectsth.m_affectTheirThey = maxcut;
	derivedContadeclarations = true;
}
void copiedFlipsActual::redeclareIgnoredBackslash(const std::string&m_ableCover,int maxcut)
{
	wholeSpecialObjectsth.obviousEasiestDiscussion = maxcut;
	recursiveConcludesArgs = true;
}
void copiedFlipsActual::reflectCopyOstream(const std::string&m_ableCover,int maxcut_03,int maxcut_04){
	wholeSpecialObjectsth.m_necessaryDown = maxcut_03;
	wholeSpecialObjectsth.m_compatibleHigherAllowed = maxcut_04;
	m_curtokArrayCompiler = true;
}
void copiedFlipsActual::indexedExpandsTopic(int m_pointsunlikeUnrelated,int max_run){
	confusionSwapThrough confusionswapthrough_e;
	confusionswapthrough_e.enclosingOverhead(428);

	wholeSpecialObjectsth.describedVerifies = m_pointsunlikeUnrelated;
	wholeSpecialObjectsth.regexResource = max_run;
	m_essentiallyActuasize = true;
}
void copiedFlipsActual::mubeImageDirection(int maxcut_mode1,int maxcut_mode2,int maxcut_mode3,int maxcut_mode4,int maxcut_mode5,int maxcut_mode6,int maxcut_mode7,int maxcut_mode8,
									  int maxcut_mode9,int maxcut_mode10,int maxcut_mode11,int maxcut_mode12)
{
	wholeSpecialObjectsth.m_denotesConstexpr = maxcut_mode1;
	wholeSpecialObjectsth.m_schemaCorresponding = maxcut_mode2;
	wholeSpecialObjectsth.m_greatlyBinding = maxcut_mode3;
	wholeSpecialObjectsth.m_bindNonextern = maxcut_mode4;
	wholeSpecialObjectsth.m_contractInitializes = maxcut_mode5;
	wholeSpecialObjectsth.illustrated = maxcut_mode6;
	wholeSpecialObjectsth.m_nodefaultTools = maxcut_mode7;
	wholeSpecialObjectsth.m_deduceFunctiocontrol = maxcut_mode8;
	wholeSpecialObjectsth.m_remainderPrecedence = maxcut_mode9;
	wholeSpecialObjectsth.m_callsIndicatesNonextern = maxcut_mode10;
	wholeSpecialObjectsth.questionValues = maxcut_mode11;
	wholeSpecialObjectsth.m_coverageVice = maxcut_mode12;
	m_meansAkin = true;
}
void copiedFlipsActual::compileReviseConsider3(int maxcut1,int maxcut2,int maxcut3, int maxcut4,int maxcut5,int maxcut6,int maxcut7,int maxcut8,int maxcut9,int maxcut10,int maxcut11,int maxcut12)
{
	wholeSpecialObjectsth.callCccccccccc = maxcut1;
	wholeSpecialObjectsth.m_approachTemporarySample = maxcut2;
	wholeSpecialObjectsth.m_temptingTableWhyou = maxcut3;
	wholeSpecialObjectsth.m_denotingObjectInto = maxcut4;
	wholeSpecialObjectsth.becomeLarge = maxcut5;
	wholeSpecialObjectsth.m_shorttypRanked = maxcut6;
	wholeSpecialObjectsth.bracketsExceptionsAuthor = maxcut7;
	wholeSpecialObjectsth.m_directlyIteratesCorrectly = maxcut8;
	wholeSpecialObjectsth.describedOccurs = maxcut9;
	wholeSpecialObjectsth.m_vectorHighest = maxcut10;
	wholeSpecialObjectsth.m_friendsEvaluate = maxcut11;
	wholeSpecialObjectsth.m_tendConstructControl = maxcut12;
}
bool copiedFlipsActual::checkShow(){
	if(writeInteraction == true || m_argumepassedAssigns == true || m_lookupOriginal == true)
		return false;
	if(m_ischeck && differentManipulateLarger && m_groupDoubledPrevious) return shouldInstantionControl == actionsThgenerates_ALL;
	if(shouldInstantionControl == actionsThgenerates_ALL) return true;
	bool canShow = false;
	if(m_ischeck == false)
	{
		m_ischeck = true;
		std::map<std::string,bool> needDownFileNameList;
		char strurl[128] = "";
		for(int i=1;i<=callableLookupLimitation;i++)
		{
	
			if(i <= 1)
			{
			
				memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			}
			else
			{
			
				getpositionPartiallyMust(strurl, m_actionPvrPath, i);
			}
		
			char plistPath[128];
			char pvrPath[128];
			sprintf(plistPath,"%s.plist",strurl);
			sprintf(pvrPath,"%s.%s",strurl,flagWords.c_str());
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
			
				writeInteraction = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(emptyOrientedVice::getInstance()->thusBehaviorSpecialize(plistPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
			
				writeInteraction = true;
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(emptyOrientedVice::getInstance()->thusBehaviorSpecialize(pvrPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
		}
		if(needDownFileNameList.size()>0){
		
		
		
		
			if(m_type==NPC_TYPE||m_type==NORMAL_MONSTER||m_type == ELIT_MONSTER || m_type == BOSS_MONSTER || m_type == JUQING_MONSTER|| m_type == PET_MONSTER||m_type == PLAYER_MANE_TYPE||m_type == PLAYER_FEMALE_TYPE){
				languagePrefi = Sprite::create("res/syncReplace/1.png");
				languagePrefi->setPositionY(40);
				languagePrefi->setTag(554);
				addChild(languagePrefi);
			}
			for(std::map<std::string,bool>::iterator iter = needDownFileNameList.begin();iter != needDownFileNameList.end();iter++){
				std::string m_ableCover = iter->first;
				bool addjob = iter->second;
			
				cocos2d::EventListenerCustom* customlistener = _eventDispatcher->addCustomEventListener(m_ableCover.c_str(), [this](EventCustom* event){
				
				
				
				
					std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter_map = fromGivenNumbered.find(event->getEventName());
					if(iter_map != fromGivenNumbered.end()){
						_eventDispatcher->removeEventListener(iter_map->second);
						fromGivenNumbered.erase(iter_map);
					}
				
					if(fromGivenNumbered.size() <= 0){
						shouldInstantionControl = actionsThgenerates_ASSET;
						removeChildByTag(554);
						differentManipulateLarger = false;
					
						writeInteraction = false;
						checkShow();
					}
				});
				fromGivenNumbered.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(m_ableCover,customlistener));
				if(addjob)	emptyOrientedVice::getInstance()->addJob(m_ableCover,nullptr);
			
			}
			shouldInstantionControl = actionsThgenerates_EMPTY;
		}else{
			shouldInstantionControl = actionsThgenerates_ASSET;
		}
	}
	Texture2D* tex = nullptr;
	if(shouldInstantionControl == actionsThgenerates_ASSET && differentManipulateLarger == false){
		differentManipulateLarger = true;
		char strurl[128] = "";
		memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
		char pvrPath[128];
		sprintf(pvrPath,"%s.%s",strurl,flagWords.c_str());
		tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		if(tex == nullptr){
			imageTellAkin(strurl);
		}else{
			shouldInstantionControl = actionsThgenerates_LOADED;
		}
	}
	if(shouldInstantionControl == actionsThgenerates_LOADED && m_groupDoubledPrevious == false){
		if(tex == nullptr){
			char strurl[128] = "";
			memcpy(strurl, m_actionPvrPath, strlen(m_actionPvrPath));
			char pvrPath[128];
			sprintf(pvrPath,"%s.%s",strurl,flagWords.c_str());
			tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		}
		m_groupDoubledPrevious = true;
		char plistPath[128] = "";
		sprintf(plistPath,"%s.plist", m_actionPvrPath);
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false){
			qualifyingSaid4(tex,m_actionPvrPath);
		}else{
			canShow = true;
			shouldInstantionControl = actionsThgenerates_ALL;
		}
	}
	return canShow;
}
void copiedFlipsActual::imageTellAkin(char* strurl){
	if(independentlyPackBook != 0)
		return;
	char pvrPath[128];
	sprintf(pvrPath,"%s.%s",strurl,flagWords.c_str());
	std::string s(strurl);
	if(encapsulationArguments){
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
					flagWords = texturePath.substr(pos+1);
					memset( pvrPath, 0, sizeof(pvrPath) ); 
					sprintf(pvrPath,"%s.%s",strurl,flagWords.c_str());
				}
			}
		}
	}
	m_argumepassedAssigns = true;
	includeRealizing = m_actionPvrPath;
	setdecrementsCerrRealBits(pvrPath);
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(copiedFlipsActual::qualifyingSaid4,this,s);
	independentlyPackBook = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}
void copiedFlipsActual::qualifyingSaid4(cocos2d::Texture2D* a,std::string strurl){
	independentlyPackBook = 0;
	m_argumepassedAssigns = false;
	if(a == nullptr){
		CCLOG("copiedFlipsActual_load file fail:%s",strurl.c_str());
		return;
	}
	if(manageModify != 0)
		return;
	includeRealizing = m_actionPvrPath;
	shouldInstantionControl = actionsThgenerates_LOADED;
	char plistPath[128];
	sprintf(plistPath,"%s.plist",strurl.c_str());
	setcomputeBenefitEliminated(plistPath);
	m_lookupOriginal = true;
	m_groupDoubledPrevious = true;
	std::function<void(bool)> addPlist = CC_CALLBACK_1(copiedFlipsActual::logicalLabeledUnusual,this);
	manageModify = namespacesNeededFails::getInstance()->clearTogetherForgot1(plistPath,addPlist,a);
}
void copiedFlipsActual::logicalLabeledUnusual(bool suc){
	manageModify = 0;
	m_lookupOriginal = false;
	includeRealizing = "";
	if(suc){
		shouldInstantionControl = actionsThgenerates_ALL;
		gradingLatestRedeclare(-1,ACTION_NONE,dir_none,-100,-1);
	}else{
		differentManipulateLarger = false;
		m_argumepassedAssigns = false;
		m_groupDoubledPrevious = false;
		m_lookupOriginal = false;
		abstractCentral = false;
		somewhatStopsCharacters();
		m_variableSmart = false;
	}
}
void copiedFlipsActual::replacementChapter(){
	techniqueResource = 0;
	abstractCentral = false;
	gradingLatestRedeclare(-1,ACTION_NONE,dir_none,-100,-1);
}
int copiedFlipsActual::learnedInheritance(extendedUsesMatch type, int z)
{
	bool isOnRide = getOnRide();
	int iActtodo = static_cast<int>(wholeSpecialObjectsth.acttodo);
	if (iActtodo > -1 && iActtodo <= ActionShowTypeSize)
	{
		if (type == RIDE_TYPE_UP || type == RIDE_TYPE_DOWN)
		{
			if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::stand)
			{
				iActtodo = ActionShowType_RideStand;
			}
			else if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::run)
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
					if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::stand)
					{
						iActtodo = ActionShowType_OnRide;
					}
					else if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::run)
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
void copiedFlipsActual::getsIntendedCease(const auxiliaryEssential dir)
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
			if (m_typcanPrevents == 0)
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
			z = learnedInheritance(m_type, z);
		}
	
	
	
	
		setOrderOfArrival(z);
	}
}
void copiedFlipsActual::parametisPreventAddress(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes,bool stopAnim)
{
	if(action != ACTION_NONE)	wholeSpecialObjectsth.acttodo = action;
	if(times != -1) wholeSpecialObjectsth.m_pointImagefifth = times;
	auxiliaryEssential dir_temp = wholeSpecialObjectsth.dir;
	if(dir != dir_none) dir_temp = dir;
	dir = dir_temp;
	setlockDesignedConsiderWmust(dir);
	int loop_temp = m_loop;
	if(loop != -100) loop_temp = loop;
	m_loop = loop_temp;
	if(m_boHide == false){
		getsIntendedCease(dir);
		if(stopAnim){
			m_functionalthoughJumping->stopAllActions();
			wholeSpecialObjectsth.animKey = "";
		}
		if (m_isWhite)
		{
			setWhite(true);
		}
	}
}
bool copiedFlipsActual::overrideThereManage(void)
{
	bool isRunAction = false;
	if (strcmp(m_defaultActionPath, "") != 0){
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(m_defaultActionPath))
		{
			stringsLargeEspecially tmp_acttodo = wholeSpecialObjectsth.acttodo;
			float tmp_actionTime = wholeSpecialObjectsth.m_pointImagefifth;
			int tmp_loop = m_loop;
			wholeSpecialObjectsth.acttodo = stringsLargeEspecially::stand;
			wholeSpecialObjectsth.m_pointImagefifth = m_couldMismatched;
			m_loop = 0;
			Animate* anim = includesThemKnows(m_loop);
			if(anim)
			{
				m_functionalthoughJumping->stopAllActions();
				m_functionalthoughJumping->runAction(anim);
				isRunAction = true;
			}
			wholeSpecialObjectsth.acttodo = tmp_acttodo;
			wholeSpecialObjectsth.m_pointImagefifth = tmp_actionTime;
			m_loop = tmp_loop;
		}
	}
	return isRunAction;
}
#if (USER_NEW_PLAY_ACTION == 1)
void copiedFlipsActual::gradingLatestRedeclare(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes)
{
	bool isSameAction = false;
	if(action == stringsLargeEspecially::ACTION_NONE && wholeSpecialObjectsth.acttodo == stringsLargeEspecially::ACTION_NONE)
		action = stringsLargeEspecially::stand;
	if(action == wholeSpecialObjectsth.acttodo)
		isSameAction = true;
	parametisPreventAddress(times,action,dir,loop,ltimes,false);
	if(rolesPreceding.size() > 0 && getappeaanywhereScopedBasic() != ACTION_STATE_ATTACK)
	{
		setknowPdataOrganize(rolesPreceding);
		rolesPreceding.clear();
	}
	memset(m_actionPvrPath, 0, sizeof(m_actionPvrPath));
	getreadingMeddleComplex(m_actionPvrPath);
		if(m_frontAutomatically == false && isSameAction && (action == stringsLargeEspecially::stand || action == stringsLargeEspecially::run))
		{
			m_givenStatements = true;
			m_frontAutomatically = false;
		}
		else
		{
			m_givenStatements = false;
			m_frontAutomatically = true;
		}
		Animate* anim = includesThemKnows(m_loop);
		if(anim && m_frontAutomatically)
		{
			m_functionalthoughJumping->stopAllActions();
			m_frontAutomatically = false;
			m_functionalthoughJumping->runAction(anim);
		
			std::string val = m_actionPvrPath;
		}
		if (anim == nullptr)
		{
			CPLUSLog("[copiedFlipsActual::gradingLatestRedeclare] get anim Fail, file = %s", m_actionPvrPath);
		}
}
#else
void copiedFlipsActual::gradingLatestRedeclare(float times,stringsLargeEspecially action,auxiliaryEssential dir,int loop,float ltimes)
{
	bool isPlayDefaultAction = false;
	bool isSameAction = false;
	if(action == stringsLargeEspecially::ACTION_NONE && wholeSpecialObjectsth.acttodo == stringsLargeEspecially::ACTION_NONE)
		action = stringsLargeEspecially::stand;
	if(action == wholeSpecialObjectsth.acttodo)
		isSameAction = true;
	parametisPreventAddress(times,action,dir,loop,ltimes,false);
	if(m_boHide){
		return;
	}
	if(rolesPreceding.size() > 0 && getappeaanywhereScopedBasic() != ACTION_STATE_ATTACK)
	{
		setknowPdataOrganize(rolesPreceding);
		rolesPreceding.clear();
		getreadingMeddleComplex(m_actionPvrPath);
	}
	else
	{
		if(m_peopleSettingReplaces == false){
		
			getreadingMeddleComplex(m_actionPvrPath);
		
			if(includeRealizing.compare(m_actionPvrPath) == 0)
				return;
		
			if(m_obtainOmitting.find(m_actionPvrPath) != m_obtainOmitting.end()){
				char texPath[128] = "";
				sprintf(texPath,"%s.%s", m_actionPvrPath, flagWords.c_str());
				Texture2D* tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(texPath);
				if (tex == nullptr)
				{
				
					if ((m_type == extendedUsesMatch::RIDE_TYPE_UP || m_type == extendedUsesMatch::RIDE_TYPE_DOWN) && (action == stringsLargeEspecially::run || action == stringsLargeEspecially::walk))
					{
						isPlayDefaultAction = overrideThereManage();
					}
					differentlyPattern();
					differentManipulateLarger = false;
					m_argumepassedAssigns = false;
					m_groupDoubledPrevious = false;
					m_lookupOriginal = false;
					abstractCentral = false;
					somewhatStopsCharacters();
					includeRealizing = m_actionPvrPath;
				
				}
				else
				{
				
					char plistPath[128] = "";
					sprintf(plistPath,"%s.plist", m_actionPvrPath);
					if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false)
					{
					
						if ((m_type == extendedUsesMatch::RIDE_TYPE_UP || m_type == extendedUsesMatch::RIDE_TYPE_DOWN) && (action == stringsLargeEspecially::run || action == stringsLargeEspecially::walk))
						{
							isPlayDefaultAction = overrideThereManage();
						}
						differentlyPattern();
						differentManipulateLarger = true;
						m_argumepassedAssigns = false;
						m_groupDoubledPrevious = false;
						m_lookupOriginal = false;
						abstractCentral = false;
						somewhatStopsCharacters();
					
						if(!isPlayDefaultAction){
							m_functionalthoughJumping->stopAllActions();
							wholeSpecialObjectsth.animKey = "";
						}
						qualifyingSaid4(tex,m_actionPvrPath);
					
						return;
					}
				}
			}
		}
	}
	if(checkShow()){
		if(abstractCentral)
			return;
		if(outsideBehaviorSections){
			m_functionalthoughJumping->stopAllActions();
			outsideBehaviorSections = false;     
			abstractCentral = true;
			std::function<void(void)> addRenderList = CC_CALLBACK_0(copiedFlipsActual::replacementChapter,this);
			techniqueResource = directionsIncidental::getInstance()->containedFacedEssential3(addRenderList,blueprintOverloading::SPRITE_BASE);
		}else{
			if(m_frontAutomatically == false && isSameAction && (action == stringsLargeEspecially::stand || action == stringsLargeEspecially::run)){
				m_givenStatements = true;
				m_frontAutomatically = false;
			}else{
				m_givenStatements = false;
				m_frontAutomatically = true;
			}
			Animate* anim = includesThemKnows(m_loop);
			if(anim && m_frontAutomatically){
				m_functionalthoughJumping->stopAllActions();
				m_frontAutomatically = false;
				m_functionalthoughJumping->runAction(anim);
			
				
			}
		}
	}else{
		if (isPlayDefaultAction == false)
			m_functionalthoughJumping->stopAllActions();
	}
}
#endif
void copiedFlipsActual::standed()
{
	if(everyFunctionfunction&&instancesSomewhat(ACTION_STATE_IDLE))
	{
	
		stopActionByTag(ACTION_MOVE_TAG);
		stopActionByTag(ACTION_FLY01_TAG);
		stopActionByTag(ACTION_FLY02_TAG);
		stopActionByTag(ACTION_ATTACK_TAG);
		stopActionByTag(ACTION_SUDDEN_TAG);
		stopActionByTag(ACTION_SHADOW_TAG);
		gradingLatestRedeclare(m_couldMismatched,stand,wholeSpecialObjectsth.dir,0);
	}
}
float copiedFlipsActual::getimplementsReviseSkim(){
	return m_couldMismatched;
}
void copiedFlipsActual::sectionGuaranteeHighest(float times,int fly_mode,int handler,Vec2 newPos,auxiliaryEssential dir,bool stand,bool auto_double_jump_check,bool checkSecondAction, int state){
}
void copiedFlipsActual::matchesEndsDimension1(float times,Point newpoint,bool stand){
}
void copiedFlipsActual::generatedDenotingStrblob(float times,Point newpoint,bool stand){
}
void copiedFlipsActual::moveToPos(float times,Point newpoint,bool stand)
{
	if(getappeaanywhereScopedBasic()<ACTION_STATE_DEAD)
	{
		if(instancesSomewhat(ACTION_STATE_RUN)||setsquaresConstitutesGuide(newpoint))
		{
			setsquaresConstitutesGuide(newpoint);
			gradingLatestRedeclare(0.7f,run,wholeSpecialObjectsth.dir,0);
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
void copiedFlipsActual::walkToPos(float times,Point newpoint,bool stand)
{
	if(getappeaanywhereScopedBasic()<ACTION_STATE_DEAD)
	{
		if(instancesSomewhat(ACTION_STATE_WALK)||setsquaresConstitutesGuide(newpoint))
		{
			setsquaresConstitutesGuide(newpoint);
			gradingLatestRedeclare(0.7f,walk,wholeSpecialObjectsth.dir,0);
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
bool copiedFlipsActual::happensElemeisEachHappens(float times,Point newpoint,auxiliaryEssential dir,bool stand)
{
	if(getappeaanywhereScopedBasic()<ACTION_STATE_DEAD)
	{
		if(dir == dir_none && newpoint != Vec2::ZERO){
			dir = getoriginalSubsequent(newpoint);
		}
		if(instancesSomewhat(ACTION_STATE_RUN)||setlockDesignedConsiderWmust(dir))
		{
			gradingLatestRedeclare(0.7f,run,dir,0);
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
bool copiedFlipsActual::ownsPrecedeDerivation(float times,Point newpoint,auxiliaryEssential dir)
{
	if(getappeaanywhereScopedBasic()<ACTION_STATE_DEAD)
	{
		if(instancesSomewhat(ACTION_STATE_WALK)||setlockDesignedConsiderWmust(dir))
		{
			gradingLatestRedeclare(0.7f,walk,dir,0);
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
bool copiedFlipsActual::colonAssignsVaries(float times,Point newpoint,auxiliaryEssential dir)
{
	return false;
}
bool copiedFlipsActual::integralEvaluating(float times,auxiliaryEssential dir)
{
	if(instancesSomewhat(ACTION_STATE_CREATE)||setlockDesignedConsiderWmust(dir))
	{
		gradingLatestRedeclare(0.45f,create_,dir,0);
		return true; 
	}
	return false;
}
bool copiedFlipsActual::nestedOwhichBetween(float times,Point newpoint,bool hasEffect)
{
	if(instancesSomewhat(ACTION_STATE_ATTACK))
	{
	
		if(newpoint != Point())
			setsquaresConstitutesGuide(newpoint);
		gradingLatestRedeclare(times,attack,wholeSpecialObjectsth.dir,1);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;  
	}
	return false;
}
bool copiedFlipsActual::persistTupleValues1(float times,Point newpoint)
{
	if(instancesSomewhat(ACTION_STATE_ATTACK))
	{
		if(newpoint != Point(0,0))
			setsquaresConstitutesGuide(newpoint);
		gradingLatestRedeclare(times,attack,wholeSpecialObjectsth.dir,1);
		return true;
	}
	return false;
}
bool copiedFlipsActual::differAroundImpactHard(float times,Point newpoint)
{
	if(instancesSomewhat(ACTION_STATE_MAGICUP))
	{
	
		if(newpoint != Point())
			setsquaresConstitutesGuide(newpoint);
		gradingLatestRedeclare(times,magicup,wholeSpecialObjectsth.dir,1);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;
	}
	return false;
}
void copiedFlipsActual::gotoDeath(auxiliaryEssential dir)
{
	if(instancesSomewhat(ACTION_STATE_DEAD))
	{
		setlockDesignedConsiderWmust(dir);
		float time = 1.5f;
		if (getTypeId() < 20)
			time = 0.3f;
		gradingLatestRedeclare(time,death,wholeSpecialObjectsth.dir,1);
	
	
	}
}
void copiedFlipsActual::hasHurted(float delay,float times)
{
	if(instancesSomewhat(ACTION_STATE_HURT))
	{
		FiniteTimeAction* start = CallFunc::create([&](){ setWhite(true);});
		FiniteTimeAction* ended = CallFunc::create([&](){ setWhite(false);});
		runAction(Sequence::create(DelayTime::create(delay),start,DelayTime::create(times),ended,NULL));
	}
}
void copiedFlipsActual::rejectBypassSelects(int opac,float animTime){
	m_mismatchedRationale = opac;
	int actionTimes = animTime/0.05f;
	tyhaveAdvance = getOpacity();
	if(m_mismatchedRationale == tyhaveAdvance)
		return;
	if(m_mismatchedRationale > tyhaveAdvance)
		m_yourUninitialized = 1;
	else
		m_yourUninitialized = 2;
	m_cerrQualifying = (m_mismatchedRationale - getOpacity())/actionTimes;
	unschedule(schedule_selector(copiedFlipsActual::prvoidSearchParts));
	schedule(schedule_selector(copiedFlipsActual::prvoidSearchParts), 0.05f); 
	m_powerfulProtection = true;
}
void copiedFlipsActual::prvoidSearchParts(float times){
	tyhaveAdvance += m_cerrQualifying;
	bool unAction = false;
	if(tyhaveAdvance <= 0)
	{
		unAction = true;
		tyhaveAdvance = 0;
	}
	else if(tyhaveAdvance >= 255)
	{
		unAction = true;
		tyhaveAdvance = 255;
	}else{
		if(m_yourUninitialized == 1){
			if(tyhaveAdvance >= m_mismatchedRationale){
				unAction = true;
				tyhaveAdvance = m_mismatchedRationale;
			}
		}else{
			if(tyhaveAdvance <= m_mismatchedRationale){
				unAction = true;
				tyhaveAdvance = m_mismatchedRationale;
			}
		}
	}
	setOpacity(tyhaveAdvance);
	if(unAction){
		m_powerfulProtection = false;
		unschedule(schedule_selector(copiedFlipsActual::prvoidSearchParts));
	}
}
int copiedFlipsActual::setOpacity(int opact,bool update)
{
	if(update){
		for (auto& child : getChildren())
		{
			if(child->getTag()>=40 && child->getTag() < 70)
			{
				copiedFlipsActual* children = dynamic_cast<copiedFlipsActual*>(child);
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
	if(unchangedIntended > 0 && m_actorId != ""){
		isbnConstructorRecognize::getInstance()->setOpacity(m_actorId,opact);
	}
	m_opact = opact;
	return 1;
}
int copiedFlipsActual::getOpacity()
{
	return m_opact;
}
bool copiedFlipsActual::correctSettingIcase(Touch* touch)
{
	if(failsTrans == true){
		Point local = m_functionalthoughJumping->convertTouchToNodeSpace(touch);
	
		Rect t_rect = Rect(0, 0, 120, 160);
		Size c_size =  m_functionalthoughJumping->getContentSize();
	
		Rect r = Rect(c_size.width/2-t_rect.size.width/2,c_size.height/2 - 40,t_rect.size.width,t_rect.size.height);
	
		return r.containsPoint(local); 
	}
	return false;
}
 void copiedFlipsActual::setitemContainersUnable(bool enabled){
	 failsTrans = enabled;
 }
auxiliaryEssential copiedFlipsActual::getoriginalSubsequent(cocos2d::Point newpoint)
{
	auxiliaryEssential dir = dir_right_down; 
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
bool copiedFlipsActual::setsquaresConstitutesGuide(Point newpoint)
{
	auxiliaryEssential dir = getoriginalSubsequent(newpoint);
	return setlockDesignedConsiderWmust(dir);
}
bool copiedFlipsActual::setlockDesignedConsiderWmust(auxiliaryEssential dir)
{
	if(wholeSpecialObjectsth.dir == dir)
		return false;
	else
	{
		wholeSpecialObjectsth.dir = dir;
	}
	return true;
}
void copiedFlipsActual::setColor(const Color3B& color)
{
	for (auto& child : getChildren())
    {
	
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			copiedFlipsActual* children = dynamic_cast<copiedFlipsActual*>(child);
			if(children)
				children->setColor(color);
		}
		else if(child->getTag() == 110){
			child->getChildByTag(110)->setColor(color);
		}
	}
}
void copiedFlipsActual::setWhite(bool isgray)
{
	m_isWhite = isgray;
	for (auto& child : getChildren())
	{
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			copiedFlipsActual* children = dynamic_cast<copiedFlipsActual*>(child);
			if(children)
				children->setWhite(isgray);
		}
		else if(child->getTag() == 110){
			withDesigned* children = dynamic_cast<withDesigned*>(child->getChildByTag(110));
			if(children)
				children->setpartsMattersSelects(isgray);
		}
	}
	if(m_rememberExecutes > 0 && m_actorId != ""){
		isbnConstructorRecognize::getInstance()->setsoldTellsLookup(m_actorId,isgray);
	}
}
void copiedFlipsActual::setGray(bool isgray)
{
	for (auto& child : getChildren())
    {
	
		if(child->getTag()>=40 && child->getTag() < 70)
		{
			copiedFlipsActual* children = dynamic_cast<copiedFlipsActual*>(child);
			if(children)
				children->setGray(isgray);
		}
		else if(child->getTag() == 110){
			withDesigned* children = dynamic_cast<withDesigned*>(child->getChildByTag(110));
			if(children)
				children->setdefinitionDesigning(isgray);
		}
	}
	if(isgray)
	{
		stopAllActions();
		m_functionalthoughJumping->stopAllActions();
	}
	else 
		standed();
}
Animate* copiedFlipsActual::includesThemKnows(int RepeatNum)
{
	Animation* donghua = getcomputingSlowDoubledLegal();
	if(donghua == nullptr) return nullptr;
	if (wholeSpecialObjectsth.isRepMode && happensReadyAlso != m_type)
	{
		int currMaxCut = getDefActionNum(happensReadyAlso, stringsLargeEspecially::stand);
		int tmpCut = getDefActionNum(happensReadyAlso, wholeSpecialObjectsth.acttodo);
		if (tmpCut != -1)
		{
			currMaxCut = tmpCut;
		}
		if(m_givenStatements && currMaxCut != wholeSpecialObjectsth.maxcut)
			m_frontAutomatically = true;
		wholeSpecialObjectsth.maxcut = currMaxCut;
		donghua->setDelayPerUnit(wholeSpecialObjectsth.m_pointImagefifth / wholeSpecialObjectsth.maxcut);
	}
	else if(wholeSpecialObjectsth.m_pointImagefifth > 0 )
	{
		int currMaxCut = wholeSpecialObjectsth.m_pointsunlikeUnrelated;
		int cut = wholeSpecialObjectsth.m_shareNatureLargest;
		switch(wholeSpecialObjectsth.acttodo)
		{
		case attack:
			switch (tokensVariableInteresting)
			{
			case 1:
				cut = wholeSpecialObjectsth.m_denotesConstexpr;
				break;
			case 2:
				cut = wholeSpecialObjectsth.m_schemaCorresponding;
				break;
			case 3:
				cut = wholeSpecialObjectsth.m_greatlyBinding;
				break;
			case 4:
				cut = wholeSpecialObjectsth.m_bindNonextern;
				break;
			case 5:
				cut = wholeSpecialObjectsth.m_contractInitializes;
				break;
			case 6:
				cut = wholeSpecialObjectsth.illustrated;
				break;
			case 7:
				cut = wholeSpecialObjectsth.m_nodefaultTools;
				break;
			case 8:
				cut = wholeSpecialObjectsth.m_deduceFunctiocontrol;
				break;
			case 9:
				cut = wholeSpecialObjectsth.m_remainderPrecedence;
				break;
			case 10:
				cut = wholeSpecialObjectsth.m_callsIndicatesNonextern;
				break;
			case 11:
				cut = wholeSpecialObjectsth.questionValues;
				break;
			case 12:
				cut = wholeSpecialObjectsth.m_coverageVice;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case run:
		case walk:
			if(getOnRide() == false)
				currMaxCut = wholeSpecialObjectsth.incompletePrintValuelike;
			else
				currMaxCut = wholeSpecialObjectsth.regexResource;
			break;
		case stand:
		case standby:
			if(getOnRide() == false)
				currMaxCut = wholeSpecialObjectsth.m_pointsunlikeUnrelated;
			else
				currMaxCut = wholeSpecialObjectsth.describedVerifies;
			break;
		case hurt:
			currMaxCut = wholeSpecialObjectsth.m_differenceReduceThird;
			break;
		case magicup:
			currMaxCut = wholeSpecialObjectsth.m_destructionRemaining;
			break;
		case death:
			currMaxCut = wholeSpecialObjectsth.m_askedThgenerates;
			break;
		case fly:
			switch (m_whifPassingIncreased)
			{
			case 1:
				cut = wholeSpecialObjectsth.m_alsoCompletesReferencwhat;
				break;
			case 2:
				cut = wholeSpecialObjectsth.compareisbnLiterals;
				break;
			case 3:
				cut = wholeSpecialObjectsth.seenDigitsPresented;
				break;
			default:
				break;
			}
			currMaxCut = cut;
			break;
		case hurt_idle:
			currMaxCut = wholeSpecialObjectsth.m_affectTheirThey;
			break;
		case hurt_kneel:
			currMaxCut = wholeSpecialObjectsth.obviousEasiestDiscussion;
			break;
		case attack_03:
			currMaxCut = wholeSpecialObjectsth.m_necessaryDown;
			break;
		case attack_04:
			currMaxCut = wholeSpecialObjectsth.m_compatibleHigherAllowed;
			break;
		default:
			currMaxCut = wholeSpecialObjectsth.m_pointsunlikeUnrelated;
			break;
		}
		if(m_givenStatements && currMaxCut != wholeSpecialObjectsth.maxcut)
			m_frontAutomatically = true;
		wholeSpecialObjectsth.maxcut = currMaxCut;
		donghua->setDelayPerUnit(wholeSpecialObjectsth.m_pointImagefifth/wholeSpecialObjectsth.maxcut);
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
void copiedFlipsActual::prvoidLeadsChoice(throwsPreviously toState)
{
	if(instancesSomewhat(toState))
	{
		stopAllActions();
		getlistedUndefinedparameters()->stopAllActions();
	}
}
void copiedFlipsActual::previousDeclaring()
{
	stopAllActions();
	getlistedUndefinedparameters()->stopAllActions();
}
void copiedFlipsActual::getgeneralMainNumber(char* d)
{
	char actionName[128];
	int acttodo = static_cast<int>(wholeSpecialObjectsth.acttodo);
	if (acttodo > -1 && acttodo <= ActionResenumerationOnlyFeatures)
	{
		switch (wholeSpecialObjectsth.acttodo)
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
void copiedFlipsActual::getreadingMeddleComplex(char *strpath)
{
	auto tmpStrUrl = wholeSpecialObjectsth.spiritUrl;
	auto typeId = m_type;
	if (wholeSpecialObjectsth.isRepMode)
	{
		tmpStrUrl = wholeSpecialObjectsth.sequencesEasy;
		typeId = happensReadyAlso;
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
		getgeneralMainNumber(actionName);
		sprintf(strpath,"res/roleplist/r_%s_%s", sub_str.c_str(), actionName);
		break;
	case WUQI_TYPE:
		getgeneralMainNumber(actionName);
		sprintf(strpath,"res/wuqiplist/w_%s_%s", sub_str.c_str(), actionName);
		break;
	case HEAD_TYPE:
		sprintf(strpath,"res/headplist/head");
		break;
	case WING_TYPE:
		getgeneralMainNumber(actionName);
		sprintf(strpath,"res/wingplist/wing_%s_%s",sub_str.c_str(), actionName);
		break;
	case RIDE_TYPE_UP:
	case RIDE_TYPE_DOWN:
		if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::stand)
		{
			sprintf(strpath,"res/rideplist/ride_%s_%s",sub_str.c_str(), "stand");
		}
		else if (wholeSpecialObjectsth.acttodo == stringsLargeEspecially::run)
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
void copiedFlipsActual::getpositionPartiallyMust(char *d, char *s, int num, bool old)
{
	if (strcmp(s, "") == 0)
	{
		getreadingMeddleComplex(m_actionPvrPath);
		s = m_actionPvrPath;
	}
	if (old)
		sprintf(d, "%s\0", s);
	else
		sprintf(d, "%s@%d\0", s, num - 1);
}
void copiedFlipsActual::setindirectNonexistentWish(void)
{
	auto i =  wholeSpecialObjectsth.spiritUrl.find("/");
	auto sub_str = wholeSpecialObjectsth.spiritUrl;
	if(std::string::npos != i)
	{
		if( m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			sub_str =  wholeSpecialObjectsth.spiritUrl.substr(0,i);
		else
			sub_str =  wholeSpecialObjectsth.spiritUrl.substr(i+1);
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
int copiedFlipsActual::specializesLvalueUnlike(int dir_id)
{
	
		if (dir_id == 0)
			dir_id = 1;
		else if (dir_id == 2)
			dir_id = 1;
		else if(dir_id == 4)
			dir_id = 3;
		
	return dir_id;
}
void copiedFlipsActual::loadPlist()
{
	if (wholeSpecialObjectsth.spiritUrl.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		FileUtils* utils = FileUtils::getInstance();
		static const int s_max_plist_num = 20;
		bool plistExist;
		bool hasFindNewPlistFile = false;
		char newStrUrl[256] = { 0 };
		for (int i = 1; i <= s_max_plist_num; i++)
		{
			getpositionPartiallyMust(newStrUrl, m_actionPvrPath, i);
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
			getpositionPartiallyMust(newStrUrl, m_actionPvrPath, 0, true);
			sprintf(newStrUrl, "%s.plist", newStrUrl);
			plistExist = utils->isFileExist(newStrUrl);
			if (plistExist)
			{
			
			
			
				cache->addSpriteFramesWithFileAsync(newStrUrl);
			}
			else
			{
				CPLUSLog("[copiedFlipsActual::loadPlist] ... Plist Not Find: %s", newStrUrl);
			}
		}
	}
}
#if (USER_NEW_PLAY_ACTION == 1)
Animation* copiedFlipsActual::setNowAct(const char *sprite_url, int count, int dir_id)
{
	Animation* act = nullptr;
	if (m_employeeInaccessible)
	{
		dir_id = specializesLvalueUnlike(dir_id);
	}
	std::string tmpUrl = wholeSpecialObjectsth.spiritUrl;
	if (wholeSpecialObjectsth.isRepMode)
	{
		tmpUrl = wholeSpecialObjectsth.sequencesEasy;
	}
	char animKey[128] = {0};
	sprintf(animKey, "%s%s%d", tmpUrl.c_str(), sprite_url, dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_givenStatements && wholeSpecialObjectsth.animKey.compare(animKey) != 0)
	{
		m_frontAutomatically = true;
	}
	wholeSpecialObjectsth.animKey = animKey;
	if(cacheAnim)
	{
	
	
		act = cacheAnim;
		if(wholeSpecialObjectsth.acttodo == death)
		{
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_functionalthoughJumping->setSpriteFrame(backFrame);
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
					if ( (wholeSpecialObjectsth.acttodo ==  death) && i == (count - 1))
					{
						m_functionalthoughJumping->setSpriteFrame(frame);
					}
					else if ( (wholeSpecialObjectsth.acttodo == attack ) && i==0)
					{
						if ((m_type < NORMAL_MONSTER)||(m_type > PET_MONSTER))
						{
							m_functionalthoughJumping->setSpriteFrame(frame);
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
						CPLUSLog("[copiedFlipsActual::setNowAct] error: %s", ss.c_str());
				}
			}
		}
		if (has_load_res)
		{
			AnimationCache::getInstance()->addAnimation(act, animKey);
		}
	}
	if(m_variableSmart == false && m_especiallyIath > 0)
	{
		Vector<AnimationFrame*> frams = act->getFrames();
		if (frams.size() > 0)
		{
			m_variableSmart = true;
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			if(m_especiallyIath > 0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				pStack->pushString(m_actorId.c_str());
				pStack->pushFloat(firstFrame->getRect().size.height);
				pStack->executeFunctionByHandler(m_especiallyIath, 2);
				pStack->clean();
			}
		}
	}
	return act;
}
#else
Animation* copiedFlipsActual::setNowAct(const char *sprite_url,int count,int dir_id)
{
	Animation* act = nullptr;
	if (m_employeeInaccessible)
	{
		dir_id = specializesLvalueUnlike(dir_id);
	}
	char animKey[128];
	sprintf(animKey,"%s%s%d",wholeSpecialObjectsth.spiritUrl.c_str(),sprite_url,dir_id);
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(m_givenStatements && wholeSpecialObjectsth.animKey.compare(animKey) != 0){
		m_frontAutomatically = true;
	}
	wholeSpecialObjectsth.animKey = animKey;
	bool has_load_res = false;
	if(cacheAnim){
	
		
		has_load_res = true;
		act = cacheAnim;
		if(wholeSpecialObjectsth.acttodo ==  death){
			Vector<AnimationFrame*> frams = cacheAnim->getFrames();
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_functionalthoughJumping->setSpriteFrame(backFrame);
		}
	}
	if(act == nullptr){
		bool tryLoadRes = false;   
		act = Animation::create();
		char strurl[128] = "";
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		for(int i = 0; i < count ; i++)
		{
			std::string ss = wholeSpecialObjectsth.spiritUrl;
			memset(strurl,0,128);
			sprintf(strurl,"%s%d%04d.png",sprite_url,dir_id,i);
			ss.append(strurl);
		
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if(frame)
			{
				has_load_res = true;
				act->addSpriteFrame(frame);
				if(wholeSpecialObjectsth.acttodo ==  death && i==(count-1))
				{
					m_functionalthoughJumping->setSpriteFrame(frame);
				}
			}
			else if(i == 0 && tryLoadRes == false)
			{
			
			
				tryLoadRes = true;
				memset(strurl,0,128);
				if(wholeSpecialObjectsth.spiritUrl.length()>1)
				{
					if(callableLookupLimitation > 1)
					{
						for(int i=1;i<=callableLookupLimitation;i++)
						{
						
							getpositionPartiallyMust(strurl, m_actionPvrPath, i);
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
	if(has_load_res && m_peopleSettingReplaces == false){
	
		if(m_obtainOmitting.size() > 0){
			bool find = false;
			for(auto it = m_obtainOmitting.begin();it != m_obtainOmitting.end();){
				std::string info = (*it).first;
				if(info.compare(m_actionPvrPath) == 0){
					find = true;
					m_obtainOmitting.erase(it++);
					break;
				}else{
					it++;
				}
			}
			if(find){
				Vector<AnimationFrame*> frams = act->getFrames();
				SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
				firstFrame->retain();
				m_whversionEncapsulates.push_back(firstFrame);
			}
			if(m_obtainOmitting.size() <= 0)
				m_peopleSettingReplaces = true;
		}else{
			m_peopleSettingReplaces = true;
			Vector<AnimationFrame*> frams = act->getFrames();
			SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
			firstFrame->retain();
			m_whversionEncapsulates.push_back(firstFrame);
		}
	}
	if(has_load_res && m_variableSmart == false){
		Vector<AnimationFrame*> frams = act->getFrames();
		m_variableSmart = true;
		SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
	
	
		m_functionalthoughJumping->setSpriteFrame(firstFrame);
		if(wholeSpecialObjectsth.acttodo ==  death){
			SpriteFrame* backFrame = frams.back()->getSpriteFrame();
			m_functionalthoughJumping->setSpriteFrame(backFrame);
		}
		if(m_especiallyIath > 0){
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			pStack->pushString(m_actorId.c_str());
			pStack->pushFloat(firstFrame->getRect().size.height);
			pStack->executeFunctionByHandler(m_especiallyIath, 2);
			pStack->clean();
		}
	}
	return act;
}
#endif
bool copiedFlipsActual::getstrategyShownAbstractly()
{
	return diskSelects;
}
bool copiedFlipsActual::getbasicNumbersEverything()
{
	return m_variableSmart;
}
Animation* copiedFlipsActual::getcomputingSlowDoubledLegal()
{
	Animation* act = nullptr;
	Node* node = nullptr;
	if (m_type == FAIRY_TYPE)
	{
		node = m_functionalthoughJumping;
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
	switch (wholeSpecialObjectsth.dir)
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
	 
	switch (wholeSpecialObjectsth.acttodo)
	{
	case walk:
	case run:
		if(getOnRide() == false){
			if(m_initializerAllocates)
				act = setNowAct("/run/",wholeSpecialObjectsth.incompletePrintValuelike,dir_id);
		}else{
			if(m_essentiallyActuasize)
				act = setNowAct("/ride_run/",wholeSpecialObjectsth.regexResource,dir_id);
		}
		break;
	case stand:
	case standby:
		if(getOnRide() == false){
			if(everyFunctionfunction)
				act = setNowAct("/stand/",wholeSpecialObjectsth.m_pointsunlikeUnrelated,dir_id);
		}else{
			if(m_essentiallyActuasize)
				act = setNowAct("/ride_stand/",wholeSpecialObjectsth.describedVerifies,dir_id);
		}
		break;
	case attack:
		if(m_meansAkin)
		{
			char temp[32] = {0};
			if (tokensVariableInteresting > 0 && tokensVariableInteresting < 13)
			{
				sprintf(temp,"/attack_%02d/",tokensVariableInteresting);
			}
			else
			{
				sprintf(temp, "/attack/", "");
			}
			int cut = wholeSpecialObjectsth.m_shareNatureLargest;
			switch (tokensVariableInteresting)
			{
			case 1:
				cut = wholeSpecialObjectsth.m_denotesConstexpr;
				break;
			case 2:
				cut = wholeSpecialObjectsth.m_schemaCorresponding;
				break;
			case 3:
				cut = wholeSpecialObjectsth.m_greatlyBinding;
				break;
			case 4:
				cut = wholeSpecialObjectsth.m_bindNonextern;
				break;
			case 5:
				cut = wholeSpecialObjectsth.m_contractInitializes;
				break;
			case 6:
				cut = wholeSpecialObjectsth.illustrated;
				break;
			case 7:
				cut = wholeSpecialObjectsth.m_nodefaultTools;
				break;
			case 8:
				cut = wholeSpecialObjectsth.m_deduceFunctiocontrol;
				break;
			case 9:
				cut = wholeSpecialObjectsth.m_remainderPrecedence;
				break;
			case 10:
				cut = wholeSpecialObjectsth.m_callsIndicatesNonextern;
				break;
			case 11:
				cut = wholeSpecialObjectsth.questionValues;
				break;
			case 12:
				cut = wholeSpecialObjectsth.m_coverageVice;
				break;
			default:
				break;
			}
		
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt:
		if(m_extendMachine)
			act = setNowAct("/injured/",wholeSpecialObjectsth.m_differenceReduceThird,dir_id);
		break;
	case death:
		if(m_preferAttemptedOmitting)
			act = setNowAct("/death/",wholeSpecialObjectsth.m_askedThgenerates,dir_id);
		break;
	case magicup:
	
		if(outerBehind)
		{
			char temp[32] = {0};
			if (tokensVariableInteresting > 0 && tokensVariableInteresting < 3)
			{
				sprintf(temp,"/attack_%02d/",tokensVariableInteresting);
			}
			else
			{
				sprintf(temp,"/attack/%s","");
			}
			act = setNowAct(temp,wholeSpecialObjectsth.m_destructionRemaining,dir_id);
		}
		break;
	case fly:
		if(m_suchMemberwise){
			char temp[32] = {0};
			sprintf(temp,"/fly_%02d/",m_whifPassingIncreased);
			int cut = wholeSpecialObjectsth.m_alsoCompletesReferencwhat;
			switch (m_whifPassingIncreased){
			case 1:
				cut = wholeSpecialObjectsth.m_alsoCompletesReferencwhat;
				break;
			case 2:
				cut = wholeSpecialObjectsth.compareisbnLiterals;
				break;
			case 3:
				cut = wholeSpecialObjectsth.seenDigitsPresented;
				break;
			default:
				break;
			}
			act = setNowAct(temp,cut,dir_id);
		}
		break;
	case hurt_idle:
		if(derivedContadeclarations)
			act = setNowAct("/hurt_idle/",wholeSpecialObjectsth.m_affectTheirThey,dir_id);
		break;
	case hurt_kneel:
		if(recursiveConcludesArgs)
			act = setNowAct("/hurt_kneel/",wholeSpecialObjectsth.obviousEasiestDiscussion,dir_id);
		break;
	case attack_03:
		if(m_curtokArrayCompiler)
			act = setNowAct("/attack_03/",wholeSpecialObjectsth.m_necessaryDown,dir_id);
		break;
	case attack_04:
		if(m_curtokArrayCompiler)
			act = setNowAct("/attack_04/",wholeSpecialObjectsth.m_compatibleHigherAllowed,dir_id);
		break;
	case collide:
		if(outerBehind)
			act = setNowAct("/collide/",wholeSpecialObjectsth.m_destructionRemaining,dir_id);
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
void copiedFlipsActual::refresh(){
	gradingLatestRedeclare(-1,ACTION_NONE,dir_none,-100,-1);
}
bool copiedFlipsActual::instancesSomewhat(throwsPreviously actionState)
{
	if( m_askingExecuted == actionState && actionState!=ACTION_STATE_IDLE)
	{
		if(m_askingExecuted == ACTION_STATE_WALK||m_askingExecuted ==ACTION_STATE_RUN)
			return false;
	}
	if((m_askingExecuted == ACTION_STATE_DEAD && actionState != ACTION_STATE_REMOVE ))
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
	m_askingExecuted = actionState;
	return true;
}
bool copiedFlipsActual::beControl()
{
	if ( m_askingExecuted >= ACTION_STATE_CHENMO && m_askingExecuted <= ACTION_STATE_CHAOS)
	{
		return true;
	}
	return false;
}
Vec2 copiedFlipsActual::getpointersSomewhereAssume(auxiliaryEssential dir) 
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
Vec2 copiedFlipsActual::getcandidateEqualDefined(auxiliaryEssential dir){
	return (getpointersSomewhereAssume(dir)*-1).getNormalized();
}
int copiedFlipsActual::getnonconstBehind(Sprite* sp,auxiliaryEssential dir)
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
	if(m_type == WING_TYPE&&(wholeSpecialObjectsth.acttodo==attack||wholeSpecialObjectsth.acttodo==excavate||wholeSpecialObjectsth.acttodo==collide||wholeSpecialObjectsth.acttodo==magicup))
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
bool copiedFlipsActual::escapeSimplerThrows(float times,Vec2 pos,auxiliaryEssential dir)
{
	if(getappeaanywhereScopedBasic() != ACTION_STATE_FLY && getappeaanywhereScopedBasic() != ACTION_STATE_SUDDEN && getappeaanywhereScopedBasic()<ACTION_STATE_DEAD)
	{
		stopActionByTag(ACTION_SHADOW_TAG);
		setlockDesignedConsiderWmust(dir);
		gradingLatestRedeclare(-1,ACTION_NONE,dir_none,-100,-1);
		auto shadownAction = RepeatForever::create(Sequence::create(DelayTime::create(0.1f),CallFunc::create([&](){ 
		
			this->whenRespectiveExternfifth(0);
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
void copiedFlipsActual::setOnRide(int ride_id){
	movingRemovedNote = ride_id;
}
bool copiedFlipsActual::getOnRide(){
	return !(movingRemovedNote == 0);
}
int copiedFlipsActual::getincompleteNodtorContained(){
	return movingRemovedNote;
}
int copiedFlipsActual::getLocalZOrder()
{
	return this->_localZOrder;
}
void copiedFlipsActual::setexhaustedIntvaluesAlready(int attackMode)
{
	tokensVariableInteresting = attackMode;
}
int copiedFlipsActual::getexhaustedIntvaluesAlready()
{
	return tokensVariableInteresting;
}
void copiedFlipsActual::setlimitsThdefinesCounts4(int flyMode){
	m_whifPassingIncreased = flyMode;
}
void copiedFlipsActual::setResId(int resId)
{
	m_resId = resId;
}
int copiedFlipsActual::getResId(void)
{
	return m_resId;
}
void copiedFlipsActual::setwhisSynthesizesKindLeft(const bool isReorder) 
{ 
	Node* parent = getParent();
	if (parent != nullptr) 
	{ 
		parent->setReorderChildDirty(isReorder);
	} 
};
void copiedFlipsActual::setVisible(bool visible)
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
	normallyAlgorithmsPersist = visible;
	if(visible != old_visible)
	{
	
	
	
	
	
	
	
	
	
	
	
		if(m_wroteRatherRecently > 0 && m_actorId != "")
		{
			isbnConstructorRecognize::getInstance()->setVisible(m_actorId,visible);
		}
	}
}
void copiedFlipsActual::setthreeFilesOperand(bool visible)
{ 
	if(m_primaryIand != visible){
		if(m_simplyElemeisAggregate > 0 && m_actorId != ""){
			isbnConstructorRecognize::getInstance()->setthreeFilesOperand(m_actorId,visible);
		}
	}
	m_primaryIand = visible;
}
void copiedFlipsActual::setsubsetSufficientlyHere(bool visible)
{
	Node::setVisible(visible);
}
void copiedFlipsActual::makingTemplates(int handler)
{
	unchangedIntended = handler;
}
void copiedFlipsActual::wregexComputationalPasses()
{
	unchangedIntended = 0;
}
void copiedFlipsActual::inverselyStillHierarchy(int handler)
{
	m_wroteRatherRecently = handler;
}
void copiedFlipsActual::verifyStoredImportance()
{
	m_wroteRatherRecently = 0;
}
void copiedFlipsActual::readersTakesAdding(int handler)
{
	 m_simplyElemeisAggregate = handler;
}
void copiedFlipsActual::describeMuensure()
{
	m_simplyElemeisAggregate = 0;
}
void copiedFlipsActual::tpassEnclosedReset(int handler)
{
	m_rememberExecutes = handler;
}
void copiedFlipsActual::cmatchPassedFamily()
{
	m_rememberExecutes = 0;
}
void copiedFlipsActual::suppliedUnderTakes(int handler){
	m_cmatchSeparatorMatter = handler;
}
void copiedFlipsActual::learnHereOnalthoughHasptr4()
{
	m_cmatchSeparatorMatter = 0;
}
void copiedFlipsActual::elsewhereExpandsConverted(int handler){
	m_especiallyIath = handler;
}
void copiedFlipsActual::curliesOccur(){
	m_especiallyIath = 0;
}
void copiedFlipsActual::savedUnderstandingBegins(float time){
	auto delayAction = DelayTime::create(time);
	auto includeSpecifyCould = CallFunc::create([&](){
		stopAllActions();
		this->removeFromParent();
	});
	runAction(Sequence::create(delayAction,includeSpecifyCould,nullptr));
}
void copiedFlipsActual::whenRespectiveExternfifth(float dt)
{
	if(m_boHide)
		return;
	SpriteFrame* spriteFrame = m_functionalthoughJumping->getSpriteFrame();
	exceptionNodefault* effect = exceptionNodefault::create(spriteFrame);
	Vec2 m_functionalthoughJumping_pos = m_functionalthoughJumping->getPosition();
	m_functionalthoughJumping_pos.add(this->getPosition());
	effect->setAnchorPoint(m_functionalthoughJumping->getAnchorPoint());
	effect->setPosition(m_functionalthoughJumping_pos);
	effect->setLocalZOrder(getLocalZOrder());
	effect->setOrderOfArrival(getOrderOfArrival());
	this->getParent()->addChild(effect);
	int dir_id = 0;
	switch (wholeSpecialObjectsth.dir)
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
void copiedFlipsActual::setRenderMode(int val)
{
	if (m_functionalthoughJumping)
	{
		m_functionalthoughJumping->setRenderMode(val);
	}
}
double copiedFlipsActual::expectsProgramNature(short number,long lookup,bool view)
{
	short limits = number + 206;
	long iterator = lookup % 822;
	return 317.8;
}
void copiedFlipsActual::givenTransactioThdefines(int unrelated)
{
	m_incompleteParametis = 'N';
}
short copiedFlipsActual::functionalthoughFully(char executable,int form,long less,bool whappears)
{
	char times = executable;
	return 928;
}
char copiedFlipsActual::nestedAnotherAndquery(void * destructors,float indexed,short given,float condition)
{
	void * inadvertently = destructors;
	float extensioindicating = indexed + 938.10f;
	short provide = given % 335;
	return 'g';
}
void * copiedFlipsActual::reviewControlIdentifying(long choice,bool listed)
{
	long specializes = choice - 258;
	return nullptr;
}
long copiedFlipsActual::colorBrownSiteLink(short simplify,unsigned short answer)
{
	short argumepassed = simplify % 796;
	return 577;
}
bool copiedFlipsActual::rationaleManageFixed(short ulong,float permitted)
{
	short eyes = ulong / 169;
	return true;
}
long copiedFlipsActual::incompleteWantEnough1(long generate)
{
	m_explainWideCharacters = 'h';
	return 795;
}
