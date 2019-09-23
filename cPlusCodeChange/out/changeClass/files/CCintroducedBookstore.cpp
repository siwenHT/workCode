#include "CCintroducedBookstore.h"
#include "emptyOrientedVice.h"
#include "namespacesNeededFails.h"
#include "vsdef.h"
USING_NS_CC;
introducedBookstore::introducedBookstore()
{
	m_referencesDescribe = false;
	plist_num = 1;
	m_ischeck = true;							
	differentManipulateLarger = false;
	m_groupDoubledPrevious = false;
	writeInteraction = false;
	m_argumepassedAssigns = false;
	m_lookupOriginal = false;
	 
	shouldInstantionControl = 0;				
	m_controlsLets = "";
	m_deletedDatabase = true;
	m_working = false;
	m_maxnum = 1;
	m_usersCallable = 1;
	m_loop = 1;
	m_willHaveTest = 0;
	m_opact = 255;
	flagWords = ".png";
	independentlyPackBook = 0;
	manageModify = 0;
	describeMultidimensional = "";
	allowedStrictly = "";
	m_boHide = false;
	m_initiallyPossibly = true;
	m_istreamInteraction = true;
	m_designsResource = Vec2::ZERO;
	somewhatStopsCharacters();
	m_bodiesInadvertently = false;
	m_treeCorrespondingStrings = "effectsplist";
}
introducedBookstore::~introducedBookstore(void){
	for(std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter = fromGivenNumbered.begin();iter != fromGivenNumbered.end();iter++){
		if(iter->second){
			_eventDispatcher->removeEventListener(iter->second);
		}
	}
	differentlyPattern();
}
void introducedBookstore::cleanup(){
	Node::cleanup();
	differentlyPattern();
}
void introducedBookstore::reset(){
	m_argumepassedAssigns = false;
	differentManipulateLarger = false;
	m_groupDoubledPrevious = false;
	m_lookupOriginal = false;
	somewhatStopsCharacters();
	differentlyPattern();
}
void introducedBookstore::differentlyPattern(){
	if(independentlyPackBook != 0 && !describeMultidimensional.empty()){
		bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(describeMultidimensional,independentlyPackBook);
		CCASSERT(isFind == true, "introducedBookstore independentlyPackBook remove Fail");
		independentlyPackBook = 0;
	}
	m_promotesTuple.clear();
	if(manageModify != 0 && !allowedStrictly.empty()){
		bool isFind = namespacesNeededFails::getInstance()->programmerDefininside(allowedStrictly,manageModify);
		CCASSERT(isFind == true, "introducedBookstore allowedStrictly remove Fail");
		manageModify = 0;
	}
}
introducedBookstore *introducedBookstore::create(bool auto_clean,bool onloadPlay, bool boSkillEffect)
{
    introducedBookstore *pRet = new introducedBookstore();
    if (pRet && pRet->initWithFile("res/empty_frame.png") && pRet->init(auto_clean,onloadPlay, boSkillEffect))
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
void introducedBookstore::somewhatStopsCharacters(){
	if(!m_ischeck) 
	
		shouldInstantionControl = 0;
	else{
	
		shouldInstantionControl = 1;
		if(differentManipulateLarger){
			shouldInstantionControl = 2;
			if(m_groupDoubledPrevious)
				shouldInstantionControl = 3;
		}
	}
}
void introducedBookstore::setmightTheareCorrectly(int num)
{
	plist_num = num;
}
#if (USER_NEW_PLAY_ACTION == 1)
void introducedBookstore::parametisPreventAddress(const std::string&m_ableCover,int maxnum,float m_pointImagefifth,int loop,float delaytime)
{
	if(m_controlsLets != ""){
		if(m_controlsLets.compare(m_ableCover) != 0){
			if(writeInteraction) return;
			m_argumepassedAssigns = false;
			differentManipulateLarger = false;
			m_groupDoubledPrevious = false;
			m_lookupOriginal = false;
			differentlyPattern();
			somewhatStopsCharacters();
		}
	}
	m_controlsLets = m_ableCover;
	m_maxnum = maxnum;
	m_usersCallable = m_pointImagefifth;
	m_loop = loop;
	m_willHaveTest = delaytime;
	stopAllActionsByTag(1589);
	if(m_boHide)
		return;
	Animation* m_actions = overloadedAlready3(m_ableCover,maxnum,m_pointImagefifth); 
	if(m_actions!=NULL)
	{
		m_actions->setLoops(loop);
		Animate* playaction = Animate::create(m_actions);
		DelayTime *delay = DelayTime::create(delaytime);
		Hide* hide = Hide::create();
		Show* show = nullptr;
		if(m_working == true){
			show = Show::create();
		}
		if(m_referencesDescribe) 
		{
			FiniteTimeAction *actbackfun = CallFunc::create([&](){ this->moveOver();});
			FiniteTimeAction *actall = nullptr;
			if(show){
				actall = Sequence::create(delay,show,playaction,actbackfun,NULL);
			}else{
				actall = Sequence::create(delay,playaction,actbackfun,NULL);
			}
			runAction(actall);
			actall->setTag(1589);
		}
		else
		{
			FiniteTimeAction *actall = nullptr;
			if(show){
				if(m_initiallyPossibly)
					actall = Sequence::create(delay,show,playaction,hide,NULL);
				else
					actall = Sequence::create(delay,show,playaction,NULL);
			}else{
				if(m_initiallyPossibly)
					actall = Sequence::create(delay,playaction,hide,NULL);
				else
					actall = Sequence::create(delay,playaction,NULL);
			}
			runAction(actall);
			actall->setTag(1589);
		}
		m_working = true;
	}
}
#else
void introducedBookstore::parametisPreventAddress(const std::string&m_ableCover,int maxnum,float m_pointImagefifth,int loop,float delaytime)
{
	if(m_controlsLets != ""){
		if(m_controlsLets.compare(m_ableCover) != 0){
			if(writeInteraction) return;
			m_argumepassedAssigns = false;
			differentManipulateLarger = false;
			m_groupDoubledPrevious = false;
			m_lookupOriginal = false;
			differentlyPattern();
			somewhatStopsCharacters();
		}
	}
	m_controlsLets = m_ableCover;
	m_maxnum = maxnum;
	m_usersCallable = m_pointImagefifth;
	m_loop = loop;
	m_willHaveTest = delaytime;
	stopAllActionsByTag(1589);
	if(m_boHide)
		return;
	if(checkShow()){
		Animation* m_actions = overloadedAlready3(m_ableCover,maxnum,m_pointImagefifth); 
		if(m_actions!=NULL)
		{
			m_actions->setLoops(loop);
			Animate* playaction = Animate::create(m_actions);
			DelayTime *delay = DelayTime::create(delaytime);
			Hide* hide = Hide::create();
			Show* show = nullptr;
			if(m_working == true){
				show = Show::create();
			}
			if(m_referencesDescribe) 
			{
				FiniteTimeAction *actbackfun = CallFunc::create([&](){ this->moveOver();});
				FiniteTimeAction *actall = nullptr;
				if(show){
					actall = Sequence::create(delay,show,playaction,actbackfun,NULL);
				}else{
					actall = Sequence::create(delay,playaction,actbackfun,NULL);
				}
				runAction(actall);
				actall->setTag(1589);
			}
			else
			{
				FiniteTimeAction *actall = nullptr;
				if(show){
					if(m_initiallyPossibly)
						actall = Sequence::create(delay,show,playaction,hide,NULL);
					else
						actall = Sequence::create(delay,show,playaction,NULL);
				}else{
					if(m_initiallyPossibly)
						actall = Sequence::create(delay,playaction,hide,NULL);
					else
						actall = Sequence::create(delay,playaction,NULL);
				}
				runAction(actall);
				actall->setTag(1589);
			}
			m_working = true;
		}
	}
}
#endif
void introducedBookstore::rePlay(){
	parametisPreventAddress(m_controlsLets,m_maxnum,m_usersCallable,m_loop,m_willHaveTest);
}
void introducedBookstore::setVisible(bool visible){
	if(m_boHide)
		visible = false;
	Sprite::setVisible(visible);
}
void introducedBookstore::loadPlist()
{
	if (m_controlsLets.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		FileUtils* utils = FileUtils::getInstance();
		static const int s_max_plist_num = 20;
		bool hasFindNewPlistFile = false;
		bool plistExist = false;
		for (int i = 1; i <= s_max_plist_num; i++)
		{
			std::string plistUrl = markerScopeGenerated(1, i, false);
			plistExist = utils->isFileExist(plistUrl);
			if (!plistExist)
			{
				break;
			}
			hasFindNewPlistFile = true;
			cache->addSpriteFramesWithFileAsync(plistUrl);
		}
		if (!hasFindNewPlistFile)
		{
			std::string plistUrl = markerScopeGenerated(1, 1);
			plistExist = utils->isFileExist(plistUrl);
			if (plistExist)
			{
				cache->addSpriteFramesWithFileAsync(plistUrl);
			}
			else
			{
				CPLUSLog("[introducedBookstore::overloadedAlready3] ... Plist Not Find: %s", plistUrl.c_str());
			}
		}
	}
}
#if (USER_NEW_PLAY_ACTION == 1)
Animation* introducedBookstore::overloadedAlready3(const std::string&m_ableCover,int maxnum,float m_pointImagefifth)
{
	m_controlsLets = m_ableCover;
	m_maxnum = maxnum;
	m_usersCallable = m_pointImagefifth;
	Animation *act = nullptr;
	if (act == nullptr)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		act = Animation::create();
		bool bLoadPlist = false;
		bool bOutError = false;
		char a_url[128] = {0};
		for (int i = 0; i < maxnum; i++)
		{
			sprintf(a_url, "%s/00%03d.png\0", m_ableCover.c_str(),i);
			SpriteFrame *frame =  cache->getSpriteFrameByName(a_url);
			if((!bLoadPlist) && frame == nullptr)
			{
				bLoadPlist = true;
				loadPlist();
			}
			frame = cache->getSpriteFrameByName(a_url);
			if (frame)
			{
				act->addSpriteFrame(frame);
				if (i == 0)
				{
					setSpriteFrame(frame);
				}
			}
			else
			{
				if (!bOutError)
				{
					bOutError = true;
				
				}
			}
		}
	}
	if(m_pointImagefifth>0)
	{
		act->setDelayPerUnit(m_pointImagefifth/maxnum);
	}
	else  
	{
		act->setDelayPerUnit(2.0f/15.0f);
	}
	if(m_istreamInteraction)
		act->setRestoreOriginalFrame(true);
	else
		act->setRestoreOriginalFrame(false);
	return act;
}
#else
Animation* introducedBookstore::overloadedAlready3(const std::string&m_ableCover,int maxnum,float m_pointImagefifth)
{
	m_controlsLets = m_ableCover;
	m_maxnum = maxnum;
	m_usersCallable = m_pointImagefifth;
	Animation *act = nullptr;
	char animKey[128];
	sprintf(animKey,"%s/%s", m_treeCorrespondingStrings.c_str(), m_ableCover.c_str());
	Animation* cacheAnim = AnimationCache::getInstance()->getAnimation(animKey);
	if(cacheAnim)
	{
		act = cacheAnim;
		Vector<AnimationFrame*> frams = cacheAnim->getFrames();
		SpriteFrame* firstFrame = frams.front()->getSpriteFrame();
	
	
		setSpriteFrame(firstFrame);
	}
	if(act == nullptr)
	{
	
		act = Animation::create();
		bool has_init = false;
		bool with_cache = true;
		char a_url[128] = {0};
		sprintf(a_url,"%s/00000.png",m_ableCover.c_str());
		SpriteFrame *frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(a_url);
		if(frame == NULL)
		{
			if(plist_num >1)
			{
				for(int m= 1;m<plist_num;m++)
				{
					std::string plistUrl = markerScopeGenerated(1,m);
					SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistUrl);
				}
			}
			else
			{
				std::string plistUrl = markerScopeGenerated(1,plist_num);
				SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistUrl);
			}
		}
		if(!has_init)
		{
			memset(a_url,0,128);
			sprintf(a_url,"%s/00000.png",m_ableCover.c_str());
			frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(a_url);
			if(frame)
			{
			
			
				setSpriteFrame(frame);
				has_init = true;
			}
			else
			{
				with_cache = false;
			}
		}
		memset(a_url,0,128);
		if(with_cache)
		{
			SpriteFrameCache* cache = SpriteFrameCache::getInstance();
			int j = 0;
			for(int i = 0; i<= maxnum ; i++) 
			{
				sprintf(a_url,"%s/00%03d.png",m_ableCover.c_str(),i);
				SpriteFrame *frame = cache->getSpriteFrameByName(a_url);
				if(frame)
				{
					act->addSpriteFrame(frame);
				}
			}
		}
		else 
		{
			sprintf(a_url,"%s/00%03d.png",m_ableCover.c_str(),0);
			setTexture(a_url);
			for(int i = 0; i<= maxnum ; i++) 
			{
				sprintf(a_url,"%s/00%03d.png",m_ableCover.c_str(),i);
				act->addSpriteFrameWithFile(a_url);
			}
			has_init = true;
		}
		if(has_init)
			AnimationCache::getInstance()->addAnimation(act,animKey);
	}
	if(m_pointImagefifth>0)
	{
		act->setDelayPerUnit(m_pointImagefifth/maxnum);
	}
	else  
	{
		act->setDelayPerUnit(2.0f/15.0f);
	}
	if(m_istreamInteraction)
		act->setRestoreOriginalFrame(true);
	else
		act->setRestoreOriginalFrame(false);
	return act;
}
#endif
bool introducedBookstore::checkShow(){
	if(writeInteraction == true || m_argumepassedAssigns == true || m_lookupOriginal == true)
		return false;
	if(m_ischeck && differentManipulateLarger && m_groupDoubledPrevious) return shouldInstantionControl == 3;
	if(m_controlsLets.size() <= 0) return false;
	if(shouldInstantionControl == 3) return true;
	bool canShow = false;
	if(m_ischeck == false){
		m_ischeck = true;
	
		std::map<std::string,bool> needDownFileNameList;
		for(int i=1;i<=plist_num;i++)
		{
			std::string plistPath = markerScopeGenerated(1,i);
			std::string pvrPath = markerScopeGenerated(2,i);
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
			
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(emptyOrientedVice::getInstance()->thusBehaviorSpecialize(plistPath)){
			
				bool addjob = false;
				writeInteraction = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
			
				bool addjob = true;
				writeInteraction = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(emptyOrientedVice::getInstance()->thusBehaviorSpecialize(pvrPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
			if(needDownFileNameList.size()>0){
			
			
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
						
							writeInteraction = false;
							shouldInstantionControl = 1;
							checkShow();
						}
					});
					fromGivenNumbered.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(m_ableCover,customlistener));
					if(addjob)	emptyOrientedVice::getInstance()->addJob(m_ableCover,nullptr);
				
				}
			}
		}
	}
	Texture2D* tex = nullptr;
	std::string strurl = markerScopeGenerated(3,1);
	if(shouldInstantionControl == 1 && differentManipulateLarger == false){
		differentManipulateLarger = true;
		char pvrPath[128];
		sprintf(pvrPath,"%s%s",strurl.c_str(),flagWords.c_str());
		tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		if(tex == nullptr){
			imageTellAkin(strurl.c_str());
		}else{
			shouldInstantionControl = 2;
		}
	}
	if(shouldInstantionControl == 2 && m_groupDoubledPrevious == false){
		if(tex == nullptr){
			char pvrPath[128];
			sprintf(pvrPath,"%s%s",strurl.c_str(),flagWords.c_str());
			tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		}
		m_groupDoubledPrevious = true;
		char plistPath[128];
		sprintf(plistPath,"%s.plist",strurl.c_str());
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false){
			qualifyingSaid4(tex,strurl);
		}else{
			canShow = true;
			shouldInstantionControl = 3;
		}
	}
	return canShow;
}
void introducedBookstore::imageTellAkin(const char* strurl){
	m_argumepassedAssigns = true;
	char pvrPath[128];
	sprintf(pvrPath,"%s%s",strurl,flagWords.c_str());
	std::string s(strurl);
	setdecrementsCerrRealBits(pvrPath);
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(introducedBookstore::qualifyingSaid4,this,s);
	independentlyPackBook = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}
void introducedBookstore::qualifyingSaid4(cocos2d::Texture2D* a,std::string strurl){
	independentlyPackBook = 0;
	m_argumepassedAssigns = false;
	if(a == nullptr){
		CCLOG("introducedBookstore_load file fail:%s",strurl.c_str());
		return;
	}
	shouldInstantionControl = 2;
	m_lookupOriginal = true;
	m_groupDoubledPrevious = true;
	char plistPath[128];
	sprintf(plistPath,"%s.plist",strurl.c_str());
	setcomputeBenefitEliminated(plistPath);
	std::function<void(bool)> addPlist = CC_CALLBACK_1(introducedBookstore::logicalLabeledUnusual,this);
	manageModify = namespacesNeededFails::getInstance()->clearTogetherForgot1(plistPath,addPlist,a);
}
void introducedBookstore::logicalLabeledUnusual(bool suc){
	manageModify = 0;
	m_lookupOriginal = false;
	if(suc)
	{
		shouldInstantionControl = 3;
		if(m_deletedDatabase)
			rePlay();
	}else{
		m_argumepassedAssigns = false;
		differentManipulateLarger = false;
		m_groupDoubledPrevious = false;
		m_lookupOriginal = false;
		somewhatStopsCharacters();
	}
}
std::string introducedBookstore::markerScopeGenerated(int typeId, int plistNum, bool isOld){
	std::string suffix = ".plist";
	if(typeId == 2) suffix = flagWords;
	if(typeId == 3) suffix = "";
	char url[128];
	int k =  m_controlsLets.find("/");
	if(!isOld)
	{
		if(std::string::npos != k)
		{
			auto sub_str = m_controlsLets.substr(0, k);
			sprintf(url,"res/%s/s_%s@%d%s", m_treeCorrespondingStrings.c_str(), sub_str.c_str(), plistNum - 1, suffix.c_str());
		}
		else
		{
			sprintf(url,"res/%s/%s@%d%s", m_treeCorrespondingStrings.c_str(), m_controlsLets.c_str(), plistNum - 1, suffix.c_str());
		}
	}
	else
	{
		if(std::string::npos != k)
		{
			auto sub_str = m_controlsLets.substr(0, k);
			sprintf(url,"res/%s/s_%s%s", m_treeCorrespondingStrings.c_str(), sub_str.c_str(), suffix.c_str());
		}
		else
		{
			sprintf(url,"res/%s/%s%s", m_treeCorrespondingStrings.c_str(), m_controlsLets.c_str(), suffix.c_str());
		}
	}
	return url;
}
bool introducedBookstore::init(bool auto_clean,bool onloadPlay, bool boSkillEffect)
{
	m_referencesDescribe = auto_clean;
	m_deletedDatabase = onloadPlay;
	m_bodiesInadvertently = boSkillEffect;
	if (m_bodiesInadvertently)
	{
		m_treeCorrespondingStrings = "skilleffcets";
	}
	return true;
}
void introducedBookstore::moveOver(void)
{
	stopAllActions();
	removeFromParent();
}
int introducedBookstore::setpartsCountLargest(int opact,bool update)
{
	if(update){
		setOpacity(opact);
	}
	m_opact = opact;
	return 1;
}
int introducedBookstore::getpartsCountLargest()
{
	return m_opact;
}
void introducedBookstore::setPosition(const Vec2& position)
{
	withDesigned::setPosition(position.x + m_designsResource.x,position.y + m_designsResource.y);
}
void introducedBookstore::setPosition(float x, float y)
{
	withDesigned::setPosition(x + m_designsResource.x, y + m_designsResource.y);
}
void introducedBookstore::setstartingBasicsNamespaces(cocos2d::Vec2 pos){
	m_designsResource = pos;
}

float introducedBookstore::precedeNumberCoverage(float cause,void * turn,double advantage)
{
	m_whatHandleIndicates = 222;
	return 385.7f;
}
void introducedBookstore::algorithmWhatForm(short reflect,unsigned short benefit)
{
	short multiple = reflect % 476;
}
bool introducedBookstore::whetherSuppliedRepresents(short should)
{
	short ordinary = should % 393;
	unsigned short scope = 96 + 21;
	return false;
}
int introducedBookstore::hidesProblemsGive2(void * thcall,float nocopy,bool container,double recognizing)
{
	void * operators = thcall;
	return 922;
}
unsigned short introducedBookstore::decideObjectErrormsg(double functiocontrol,double dealing)
{
	double intend = functiocontrol - 738.1;
	double circumstances = dealing - 623.17;
	short wilrefer = 741 + 490;
	return 493;
}
char introducedBookstore::beginsProvidesIsbns(bool repeatedly,short selects,long generic)
{
	bool deleted = repeatedly;
	return '5';
}
void * introducedBookstore::basisReturningMatterCalls(float correspond,float blobptr,float represent)
{
	float three = correspond + 776.3f;
	float variables = blobptr * 177.20f;
	return nullptr;
}
void introducedBookstore::wideBasisUnlikely(void * none,char meaning,long nonreference,unsigned short adds)
{
	m_stunninglyQuiteThdefines = 139;
}
void * introducedBookstore::convertPurposeParts4(void * allocate,int expression,short multidimensional)
{
	void * stay = allocate;
	return nullptr;
}
long introducedBookstore::enforcesIostream(void * converts,short requirements,unsigned short letters)
{
	void * behave = converts;
	return 742;
}
unsigned short introducedBookstore::wellAlgorithmsStore(bool components,void * record,int give,short nontemplate)
{
	bool flips = components;
	return 926;
}
void introducedBookstore::brieflyTheareExactly(bool efficient)
{
	bool simply = efficient;
	void * names = nullptr;
}
