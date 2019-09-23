#include "CCEffects.h"
#include "AsyncDownloadManager.h"
#include "AsyncLoadPlist.h"
#include "vsdef.h"
USING_NS_CC;
Effects::Effects()
{
	m_auto_clean = false;
	plist_num = 1;
	m_ischeck = true;							
	m_isLoadTexture = false;
	m_isLoadPlist = false;
	m_ischecking = false;
	m_isLoadTexturing = false;
	m_isLoadPlisting = false;
	 
	m_showState = 0;				
	m_pszFileName = "";
	m_onloadPlay = true;
	m_working = false;
	m_maxnum = 1;
	m_actiontime = 1;
	m_loop = 1;
	m_delaytime = 0;
	m_opact = 255;
	m_resSuffix = ".png";
	m_loadTextureEntryId = 0;
	m_loadPlistEntryId = 0;
	m_show_texture_path = "";
	m_show_plist_path = "";
	m_boHide = false;
	m_actionHide = true;
	m_restoreFirstFrame = true;
	m_baseOffset = Vec2::ZERO;
	updateShowState();
	m_boSkillEffect = false;
	m_sDirectoryName = "effectsplist";
}
Effects::~Effects(void){
	for(std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter = m_downloadListenerList.begin();iter != m_downloadListenerList.end();iter++){
		if(iter->second){
			_eventDispatcher->removeEventListener(iter->second);
		}
	}
	cleanAsync();
}
void Effects::cleanup(){
	Node::cleanup();
	cleanAsync();
}
void Effects::reset(){
	m_isLoadTexturing = false;
	m_isLoadTexture = false;
	m_isLoadPlist = false;
	m_isLoadPlisting = false;
	updateShowState();
	cleanAsync();
}
void Effects::cleanAsync(){
	if(m_loadTextureEntryId != 0 && !m_show_texture_path.empty()){
		bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(m_show_texture_path,m_loadTextureEntryId);
		CCASSERT(isFind == true, "Effects m_loadTextureEntryId remove Fail");
		m_loadTextureEntryId = 0;
	}
	m_needLoadTextureList.clear();
	if(m_loadPlistEntryId != 0 && !m_show_plist_path.empty()){
		bool isFind = AsyncLoadPlist::getInstance()->unbindPlistAsyncWithEntryId(m_show_plist_path,m_loadPlistEntryId);
		CCASSERT(isFind == true, "Effects m_show_plist_path remove Fail");
		m_loadPlistEntryId = 0;
	}
}
Effects *Effects::create(bool auto_clean,bool onloadPlay, bool boSkillEffect)
{
    Effects *pRet = new Effects();
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
void Effects::updateShowState(){
	if(!m_ischeck) 
	
		m_showState = 0;
	else{
	
		m_showState = 1;
		if(m_isLoadTexture){
			m_showState = 2;
			if(m_isLoadPlist)
				m_showState = 3;
		}
	}
}
void Effects::setPlistNum(int num)
{
	plist_num = num;
}
#if (USER_NEW_PLAY_ACTION == 1)
void Effects::playActionData(const std::string&pszFileName,int maxnum,float actiontime,int loop,float delaytime)
{
	if(m_pszFileName != ""){
		if(m_pszFileName.compare(pszFileName) != 0){
			if(m_ischecking) return;
			m_isLoadTexturing = false;
			m_isLoadTexture = false;
			m_isLoadPlist = false;
			m_isLoadPlisting = false;
			cleanAsync();
			updateShowState();
		}
	}
	m_pszFileName = pszFileName;
	m_maxnum = maxnum;
	m_actiontime = actiontime;
	m_loop = loop;
	m_delaytime = delaytime;
	stopAllActionsByTag(1589);
	if(m_boHide)
		return;
	Animation* m_actions = createEffect(pszFileName,maxnum,actiontime); 
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
		if(m_auto_clean) 
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
				if(m_actionHide)
					actall = Sequence::create(delay,show,playaction,hide,NULL);
				else
					actall = Sequence::create(delay,show,playaction,NULL);
			}else{
				if(m_actionHide)
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
void Effects::playActionData(const std::string&pszFileName,int maxnum,float actiontime,int loop,float delaytime)
{
	if(m_pszFileName != ""){
		if(m_pszFileName.compare(pszFileName) != 0){
			if(m_ischecking) return;
			m_isLoadTexturing = false;
			m_isLoadTexture = false;
			m_isLoadPlist = false;
			m_isLoadPlisting = false;
			cleanAsync();
			updateShowState();
		}
	}
	m_pszFileName = pszFileName;
	m_maxnum = maxnum;
	m_actiontime = actiontime;
	m_loop = loop;
	m_delaytime = delaytime;
	stopAllActionsByTag(1589);
	if(m_boHide)
		return;
	if(checkShow()){
		Animation* m_actions = createEffect(pszFileName,maxnum,actiontime); 
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
			if(m_auto_clean) 
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
					if(m_actionHide)
						actall = Sequence::create(delay,show,playaction,hide,NULL);
					else
						actall = Sequence::create(delay,show,playaction,NULL);
				}else{
					if(m_actionHide)
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
void Effects::rePlay(){
	playActionData(m_pszFileName,m_maxnum,m_actiontime,m_loop,m_delaytime);
}
void Effects::setVisible(bool visible){
	if(m_boHide)
		visible = false;
	Sprite::setVisible(visible);
}
void Effects::loadPlist()
{
	if (m_pszFileName.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		FileUtils* utils = FileUtils::getInstance();
		static const int s_max_plist_num = 20;
		bool hasFindNewPlistFile = false;
		bool plistExist = false;
		for (int i = 1; i <= s_max_plist_num; i++)
		{
			std::string plistUrl = calculateAssetPath(1, i, false);
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
			std::string plistUrl = calculateAssetPath(1, 1);
			plistExist = utils->isFileExist(plistUrl);
			if (plistExist)
			{
				cache->addSpriteFramesWithFileAsync(plistUrl);
			}
			else
			{
				CPLUSLog("[Effects::createEffect] ... Plist Not Find: %s", plistUrl.c_str());
			}
		}
	}
}
#if (USER_NEW_PLAY_ACTION == 1)
Animation* Effects::createEffect(const std::string&pszFileName,int maxnum,float actiontime)
{
	m_pszFileName = pszFileName;
	m_maxnum = maxnum;
	m_actiontime = actiontime;
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
			sprintf(a_url, "%s/00%03d.png\0", pszFileName.c_str(),i);
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
	if(actiontime>0)
	{
		act->setDelayPerUnit(actiontime/maxnum);
	}
	else  
	{
		act->setDelayPerUnit(2.0f/15.0f);
	}
	if(m_restoreFirstFrame)
		act->setRestoreOriginalFrame(true);
	else
		act->setRestoreOriginalFrame(false);
	return act;
}
#else
Animation* Effects::createEffect(const std::string&pszFileName,int maxnum,float actiontime)
{
	m_pszFileName = pszFileName;
	m_maxnum = maxnum;
	m_actiontime = actiontime;
	Animation *act = nullptr;
	char animKey[128];
	sprintf(animKey,"%s/%s", m_sDirectoryName.c_str(), pszFileName.c_str());
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
		sprintf(a_url,"%s/00000.png",pszFileName.c_str());
		SpriteFrame *frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(a_url);
		if(frame == NULL)
		{
			if(plist_num >1)
			{
				for(int m= 1;m<plist_num;m++)
				{
					std::string plistUrl = calculateAssetPath(1,m);
					SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistUrl);
				}
			}
			else
			{
				std::string plistUrl = calculateAssetPath(1,plist_num);
				SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistUrl);
			}
		}
		if(!has_init)
		{
			memset(a_url,0,128);
			sprintf(a_url,"%s/00000.png",pszFileName.c_str());
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
				sprintf(a_url,"%s/00%03d.png",pszFileName.c_str(),i);
				SpriteFrame *frame = cache->getSpriteFrameByName(a_url);
				if(frame)
				{
					act->addSpriteFrame(frame);
				}
			}
		}
		else 
		{
			sprintf(a_url,"%s/00%03d.png",pszFileName.c_str(),0);
			setTexture(a_url);
			for(int i = 0; i<= maxnum ; i++) 
			{
				sprintf(a_url,"%s/00%03d.png",pszFileName.c_str(),i);
				act->addSpriteFrameWithFile(a_url);
			}
			has_init = true;
		}
		if(has_init)
			AnimationCache::getInstance()->addAnimation(act,animKey);
	}
	if(actiontime>0)
	{
		act->setDelayPerUnit(actiontime/maxnum);
	}
	else  
	{
		act->setDelayPerUnit(2.0f/15.0f);
	}
	if(m_restoreFirstFrame)
		act->setRestoreOriginalFrame(true);
	else
		act->setRestoreOriginalFrame(false);
	return act;
}
#endif
bool Effects::checkShow(){
	if(m_ischecking == true || m_isLoadTexturing == true || m_isLoadPlisting == true)
		return false;
	if(m_ischeck && m_isLoadTexture && m_isLoadPlist) return m_showState == 3;
	if(m_pszFileName.size() <= 0) return false;
	if(m_showState == 3) return true;
	bool canShow = false;
	if(m_ischeck == false){
		m_ischeck = true;
	
		std::map<std::string,bool> needDownFileNameList;
		for(int i=1;i<=plist_num;i++)
		{
			std::string plistPath = calculateAssetPath(1,i);
			std::string pvrPath = calculateAssetPath(2,i);
			if(!FileUtils::getInstance()->isFileExist(plistPath)){
			
				bool addjob = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(plistPath)){
			
				bool addjob = false;
				m_ischecking = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(plistPath,addjob));
			}
			if(!FileUtils::getInstance()->isFileExist(pvrPath)){
			
				bool addjob = true;
				m_ischecking = true;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}else if(AsyncDownloadManager::getInstance()->isDownloadingOrJob(pvrPath)){
			
				bool addjob = false;
				needDownFileNameList.insert(std::map<std::string,bool>::value_type(pvrPath,addjob));
			}
			if(needDownFileNameList.size()>0){
			
			
				for(std::map<std::string,bool>::iterator iter = needDownFileNameList.begin();iter != needDownFileNameList.end();iter++){
					std::string pszFileName = iter->first;
					bool addjob = iter->second;
				
					cocos2d::EventListenerCustom* customlistener = _eventDispatcher->addCustomEventListener(pszFileName.c_str(), [this](EventCustom* event){
					
					
					
					
						std::map<std::string,cocos2d::EventListenerCustom*>::iterator iter_map = m_downloadListenerList.find(event->getEventName());
						if(iter_map != m_downloadListenerList.end()){
							_eventDispatcher->removeEventListener(iter_map->second);
							m_downloadListenerList.erase(iter_map);
						}
					
						if(m_downloadListenerList.size() <= 0){
						
							m_ischecking = false;
							m_showState = 1;
							checkShow();
						}
					});
					m_downloadListenerList.insert(std::map<std::string,cocos2d::EventListenerCustom*>::value_type(pszFileName,customlistener));
					if(addjob)	AsyncDownloadManager::getInstance()->addJob(pszFileName,nullptr);
				
				}
			}
		}
	}
	Texture2D* tex = nullptr;
	std::string strurl = calculateAssetPath(3,1);
	if(m_showState == 1 && m_isLoadTexture == false){
		m_isLoadTexture = true;
		char pvrPath[128];
		sprintf(pvrPath,"%s%s",strurl.c_str(),m_resSuffix.c_str());
		tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		if(tex == nullptr){
			addSpriteFrameListAsync(strurl.c_str());
		}else{
			m_showState = 2;
		}
	}
	if(m_showState == 2 && m_isLoadPlist == false){
		if(tex == nullptr){
			char pvrPath[128];
			sprintf(pvrPath,"%s%s",strurl.c_str(),m_resSuffix.c_str());
			tex = Director::getInstance()->getTextureCache()->getTextureForKeyCustom(pvrPath);
		}
		m_isLoadPlist = true;
		char plistPath[128];
		sprintf(plistPath,"%s.plist",strurl.c_str());
		if(SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(plistPath) == false){
			addSpriteFrameListCallBack(tex,strurl);
		}else{
			canShow = true;
			m_showState = 3;
		}
	}
	return canShow;
}
void Effects::addSpriteFrameListAsync(const char* strurl){
	m_isLoadTexturing = true;
	char pvrPath[128];
	sprintf(pvrPath,"%s%s",strurl,m_resSuffix.c_str());
	std::string s(strurl);
	setShowTexturePath(pvrPath);
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(Effects::addSpriteFrameListCallBack,this,s);
	m_loadTextureEntryId = Director::getInstance()->getTextureCache()->addImageAsync(pvrPath,addTexture);
}
void Effects::addSpriteFrameListCallBack(cocos2d::Texture2D* a,std::string strurl){
	m_loadTextureEntryId = 0;
	m_isLoadTexturing = false;
	if(a == nullptr){
		CCLOG("Effects_load file fail:%s",strurl.c_str());
		return;
	}
	m_showState = 2;
	m_isLoadPlisting = true;
	m_isLoadPlist = true;
	char plistPath[128];
	sprintf(plistPath,"%s.plist",strurl.c_str());
	setShowPlistPath(plistPath);
	std::function<void(bool)> addPlist = CC_CALLBACK_1(Effects::addSpriteFramePlistCallBack,this);
	m_loadPlistEntryId = AsyncLoadPlist::getInstance()->loadPlistAsync(plistPath,addPlist,a);
}
void Effects::addSpriteFramePlistCallBack(bool suc){
	m_loadPlistEntryId = 0;
	m_isLoadPlisting = false;
	if(suc)
	{
		m_showState = 3;
		if(m_onloadPlay)
			rePlay();
	}else{
		m_isLoadTexturing = false;
		m_isLoadTexture = false;
		m_isLoadPlist = false;
		m_isLoadPlisting = false;
		updateShowState();
	}
}
std::string Effects::calculateAssetPath(int typeId, int plistNum, bool isOld){
	std::string suffix = ".plist";
	if(typeId == 2) suffix = m_resSuffix;
	if(typeId == 3) suffix = "";
	char url[128];
	int k =  m_pszFileName.find("/");
	if(!isOld)
	{
		if(std::string::npos != k)
		{
			auto sub_str = m_pszFileName.substr(0, k);
			sprintf(url,"res/%s/s_%s@%d%s", m_sDirectoryName.c_str(), sub_str.c_str(), plistNum - 1, suffix.c_str());
		}
		else
		{
			sprintf(url,"res/%s/%s@%d%s", m_sDirectoryName.c_str(), m_pszFileName.c_str(), plistNum - 1, suffix.c_str());
		}
	}
	else
	{
		if(std::string::npos != k)
		{
			auto sub_str = m_pszFileName.substr(0, k);
			sprintf(url,"res/%s/s_%s%s", m_sDirectoryName.c_str(), sub_str.c_str(), suffix.c_str());
		}
		else
		{
			sprintf(url,"res/%s/%s%s", m_sDirectoryName.c_str(), m_pszFileName.c_str(), suffix.c_str());
		}
	}
	return url;
}
bool Effects::init(bool auto_clean,bool onloadPlay, bool boSkillEffect)
{
	m_auto_clean = auto_clean;
	m_onloadPlay = onloadPlay;
	m_boSkillEffect = boSkillEffect;
	if (m_boSkillEffect)
	{
		m_sDirectoryName = "skilleffcets";
	}
	return true;
}
void Effects::moveOver(void)
{
	stopAllActions();
	removeFromParent();
}
int Effects::setOpacityCustom(int opact,bool update)
{
	if(update){
		setOpacity(opact);
	}
	m_opact = opact;
	return 1;
}
int Effects::getOpacityCustom()
{
	return m_opact;
}
void Effects::setPosition(const Vec2& position)
{
	GraySprite::setPosition(position.x + m_baseOffset.x,position.y + m_baseOffset.y);
}
void Effects::setPosition(float x, float y)
{
	GraySprite::setPosition(x + m_baseOffset.x, y + m_baseOffset.y);
}
void Effects::setBasePosition(cocos2d::Vec2 pos){
	m_baseOffset = pos;
}

float Effects::precedeNumberCoverage(float cause,void * turn,double advantage)
{
	m_whatHandleIndicates = 222;
	return 385.7f;
}
void Effects::algorithmWhatForm(short reflect,unsigned short benefit)
{
	short multiple = reflect % 476;
}
bool Effects::whetherSuppliedRepresents(short should)
{
	short ordinary = should % 393;
	unsigned short scope = 96 + 21;
	return false;
}
int Effects::hidesProblemsGive2(void * thcall,float nocopy,bool container,double recognizing)
{
	void * operators = thcall;
	return 922;
}
unsigned short Effects::decideObjectErrormsg(double functiocontrol,double dealing)
{
	double intend = functiocontrol - 738.1;
	double circumstances = dealing - 623.17;
	short wilrefer = 741 + 490;
	return 493;
}
char Effects::beginsProvidesIsbns(bool repeatedly,short selects,long generic)
{
	bool deleted = repeatedly;
	return '5';
}
void * Effects::basisReturningMatterCalls(float correspond,float blobptr,float represent)
{
	float three = correspond + 776.3f;
	float variables = blobptr * 177.20f;
	return nullptr;
}
void Effects::wideBasisUnlikely(void * none,char meaning,long nonreference,unsigned short adds)
{
	m_stunninglyQuiteThdefines = 139;
}
void * Effects::convertPurposeParts4(void * allocate,int expression,short multidimensional)
{
	void * stay = allocate;
	return nullptr;
}
long Effects::enforcesIostream(void * converts,short requirements,unsigned short letters)
{
	void * behave = converts;
	return 742;
}
unsigned short Effects::wellAlgorithmsStore(bool components,void * record,int give,short nontemplate)
{
	bool flips = components;
	return 926;
}
void Effects::brieflyTheareExactly(bool efficient)
{
	bool simply = efficient;
	void * names = nullptr;
}
