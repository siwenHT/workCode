
#include "FindPath.h"
#include "iathRest.h"
#include "addingRelies.h"
#include "labelsPointRepresentation.h"
#include "CCknewOverheadSupplied.h"
#include "math/MathUtil.h"
#include "limitEscapeBackslash.h"
#include "yieldsAnswerAlways.h"
#include "andqueryApplies.h"
#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#pragma comment(lib,"Psapi.lib")
	#include "Psapi.h"
#endif
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "programRules.h"
USING_NS_CC;
static	struct completesEven *linkageUpdatesShared = nullptr;
static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
static std::string mapstr;
float imagineUnlikeNeed::m_resourceManageDereference = 0.8f;
imagineUnlikeNeed* imagineUnlikeNeed::findShouldAccessed = nullptr;
void imagineUnlikeNeed::andqueryFunctiwith(std::string mapStr, int posX, int posY,int spanX, int spanY)
{
	char imgstr[128] = {0};
	int xStart = posX / spanX;
	if(xStart - 1 >= 0)
		xStart = xStart - 1;
	int yStart = posY / spanY;
	if (yStart - 1 >= 0)
		yStart = yStart - 1;
	for (int x = 0 ; x < 3 ; x ++)
	{
		for (int y = 0; y < 3; y ++)
		{
			memset(imgstr,0,128);
			sprintf(imgstr, "%sx%d_%d.jpg", mapStr.c_str(), xStart + x, yStart + y);
		
			Director::getInstance()->getTextureCache()->addImageAsync(imgstr, nullptr, nullptr);
		}
	}
}
void imagineUnlikeNeed::setrecentlyIsbnsInput(float _scale)
{ 
	m_resourceManageDereference = _scale; 
}
imagineUnlikeNeed::imagineUnlikeNeed()  
{
	testParam = 0;
	m_pBolck = nullptr;
	m_pMap = nullptr;
	m_isrock = false;
	AStarPath = nullptr;
	AStarMap = nullptr;
	AStarMap2 = nullptr;
	m_effect = nullptr;
	map_speed = 0;
	employeeCreatingProgram = dir_undef;
	m_letsIstream = cocos2d::Vec2::ZERO;
	m_enforcesKids = Vec2::ZERO;
	role_main = nullptr;
	loop_flag = 0;
	m_takingMeddleTimes = 0;
	m_fileTurnsSemicolon = 2;
	m_walk_cb = 0;
	m_rock_cb = 0;
	m_fly_cb = 0;									
	m_realizingProblemsWorry = 0;								
	m_cabePointers = 0;
	m_formOrganizeEquality = 0;
	stunninglyWithfifth = false;
	m_isbnsPresumably = 10;
	nonstaticPrecedingTypeids = 10;
	_m_time = 0;
	usesProperly = 0;
	m_moreovesomeSuccessful = 0;
	m_currentTopics = 0;
	constitutesSupplies = 0;
	normalExpandedIncluding = Vec2::ZERO;
	m_compilationBoth = 5;
	m_smatchWere = m_compilationBoth;
	m_mapId = 0;
	m_encloseProvide = SPEED;
	m_dir = dir_undef;
	load_Thread = nullptr;
	load_Thread1 = nullptr;
	load_Thread2 = nullptr;
	load_Thread3 = nullptr;
	loadall = false;
	m_isNoRes = false;
	separatesSmatchProcessing = true;
	m_isFb = false;
	m_factorialToolsOmitted = true;
	m_movesWhatever = false;
	m_validMatchedExecutable = false;
	doesndifferViolations = false;
	m_debuggingIncludingEasier = 1;
	m_stoprocessingRepeatAsking = Vec2::ZERO;
	_infoMutex.lock();
	if(linkageUpdatesShared != nullptr)
	{
		delete(linkageUpdatesShared);
		linkageUpdatesShared = nullptr;
	}
	mapstr.clear();
	_infoMutex.unlock();
	m_differContainTemporaries = 0;
	m_facilityRepresented = true;
	m_perTileSize = Size::ZERO;
	m_mapSize = Size::ZERO;
	m_winSize = Size::ZERO;
	settingIntendThere = Vec2::ZERO;
	_overTime = 0;
	notingTchangeLegitimate = 0;
	takeIsbnVersion = 0;
	m_operationsEncountersLike = "jpg";
	m_completesRather = nullptr;
	performanceInstantiates.clear();
	codeBinds = false;
}
imagineUnlikeNeed::~imagineUnlikeNeed()
{
	m_factorialToolsOmitted = false;
	if(load_Thread)
	{
		delete load_Thread;
		load_Thread = nullptr;
	}
	if(load_Thread1)
	{
		delete load_Thread1;
		load_Thread1 = nullptr;
	}
	if(load_Thread2)
	{
		delete load_Thread2;
		load_Thread2 = nullptr;
	}
	if(load_Thread3)
	{
		delete load_Thread3;
		load_Thread3 = nullptr;
	}
	if(AStarMap != nullptr)
	{
		delete(AStarMap);
		AStarMap = nullptr;
	}
	if(AStarMap2 != nullptr)
	{
		delete(AStarMap2);
		AStarMap2 = nullptr;
	}
	_infoMutex.lock();
	while (linkageUpdatesShared != nullptr)
	{
		struct completesEven* pNode = linkageUpdatesShared;
		linkageUpdatesShared = linkageUpdatesShared->Next;
		delete(pNode);
	}
	mapstr.clear();
	performanceInstantiates.clear();
	_infoMutex.unlock();
	hierarchyPointDynamic();
	findShouldAccessed = nullptr;
}
void imagineUnlikeNeed::cleanup(){
	Layer::cleanup();
	hierarchyPointDynamic();
	findShouldAccessed = nullptr;
}
void imagineUnlikeNeed::hierarchyPointDynamic(){
	if(m_reversesSoonVectors.size() > 0){
		for(std::unordered_map<int,std::string>::iterator iter = m_reversesSoonVectors.begin();iter != m_reversesSoonVectors.end();iter++){
			bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(iter->second,iter->first);
			CCASSERT(isFind == true, "imagineUnlikeNeed m_asyncconditionChainDoesndiffer2 remove Fail");
		}
	}
	m_reversesSoonVectors.clear();
}
imagineUnlikeNeed *imagineUnlikeNeed::create(const std::string& filename, const int mapId, const bool isMultiMap, const Point pos)
{
	imagineUnlikeNeed *pRet = new imagineUnlikeNeed();
	if (pRet && pRet->init() && pRet->loadMap(filename,filename, mapId, isMultiMap, pos))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}
imagineUnlikeNeed *imagineUnlikeNeed::create()
{
	imagineUnlikeNeed *pRet = new imagineUnlikeNeed();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}
bool imagineUnlikeNeed::getbrowsersActsLiteralsBasic(int x,int y,int x1,int y1)
{
	int screen_width = 72;
	int screen_height = 72;
	int screen_width_half = screen_width/2;
	int screen_height_half = screen_height/2;
	bool status = false;
	if(x<screen_width_half||y<screen_height_half||x>(m_mapSize.width-screen_width_half)||y>(m_mapSize.height-screen_height_half))
	{
	
		if(x<screen_width_half)
		{
		
			if(y<screen_height_half)
			
				status = x1<=screen_width&&y1<=screen_height;
			else if(y>(m_mapSize.height-36))
			
				status = x1<=screen_width&&(y1 + nonstaticPrecedingTypeids)>(m_mapSize.height-screen_height);
			else
			
				status = x1<=screen_width&&abs(y1+nonstaticPrecedingTypeids/2-y)<=(screen_height_half + nonstaticPrecedingTypeids/2);
		}
		else if(x>(m_mapSize.width-screen_width_half))
		{
		
			if(y<screen_height_half)
			
				status = (x1 + m_isbnsPresumably)>=(m_mapSize.width-screen_width)&&y1<=screen_height;
			else if(y>(m_mapSize.height-screen_height_half))
			
				status = (x1 + m_isbnsPresumably)>=(m_mapSize.width-screen_width)&&(y1 + nonstaticPrecedingTypeids)>(m_mapSize.height-screen_height);
			else
			
				status = (x1 + m_isbnsPresumably)>=(m_mapSize.width-screen_width)&& abs(y1+nonstaticPrecedingTypeids/2-y)<=(screen_height_half + nonstaticPrecedingTypeids/2);
		}
		else if(abs(x1+m_isbnsPresumably/2-x)<=(screen_width_half + m_isbnsPresumably/2))
		{
		
			if(y<screen_height_half)
			
				status = y1<=screen_height;
			else 
			
				status = (y1 + nonstaticPrecedingTypeids)>(m_mapSize.height-screen_height);
		}
	}
	else if(abs(x1+m_isbnsPresumably/2-x)<=(screen_width_half + m_isbnsPresumably/2)&&abs(y1+nonstaticPrecedingTypeids/2-y)<=(screen_height_half + nonstaticPrecedingTypeids/2))
	{
	
		status = true;
	}
	return status;
}
void imagineUnlikeNeed::followLargeLabeled(int mapId,bool remove){
	bool find = false;
	vector<int>::iterator it = m_learnedPresence.begin();
	for(;it != m_learnedPresence.end();it++){
		if(*it == mapId){
			find = true;
			break;
		}
	}
	if(remove == false){
	
		if(find == false){
			m_learnedPresence.push_back(mapId);
		}
	}
	else{
	
		if(find == true){
			m_learnedPresence.erase(it);
		}
	}
}
bool imagineUnlikeNeed::forcesUsersGeneric(int mapId){
	bool find = false;
	vector<int>::iterator it = m_learnedPresence.begin();
	for(;it != m_learnedPresence.end();it++){
		if(*it == mapId){
			find = true;
			stunninglyWithfifth = true;
			break;
		}
	}
	return find;
}
void imagineUnlikeNeed::setencloseEqualsResetPrecise(int span_x,int span_y){
	if(span_x <= 0 || span_y <= 0)
		return;
	m_isbnsPresumably = span_x;
	nonstaticPrecedingTypeids = span_y;
}
void imagineUnlikeNeed::scopingAliasTwin(std::vector<completesEven*> list)
{
	_infoMutex.lock();
	if (!m_isNoRes){
		for(std::vector<completesEven*>::iterator iter = list.begin();iter != list.end();iter++){
			completesEven* Dmap = *iter;
			char imgstr[128];
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/m_isbnsPresumably,Dmap->y/nonstaticPrecedingTypeids, m_operationsEncountersLike.c_str());
			if(Dmap->Status&&Dmap->sp == nullptr&&(!Dmap->loaded)&&mapstr.size()>0){
				if(separatesSmatchProcessing == true){
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(imagineUnlikeNeed::queryresultMadeFactLocal,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(imagineUnlikeNeed::calculatesDimensionAlong,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						m_reversesSoonVectors.insert(std::pair<int,std::string>(entryId,imgstr));
				}else if(m_facilityRepresented){
				
					if(doethSelectsExamines(imgstr) == false){
						limitEscapeBackslash *sprite = limitEscapeBackslash::create(imgstr,"res/syncReplace/map_cell.jpg");
						if(sprite)
						{
							sprite->setAnchorPoint(Point(0,1));
							sprite->setPosition(Point(Dmap->x*m_perTileSize.width,(m_mapSize.height-Dmap->y)* m_perTileSize.height));
							m_pMap->addChild(sprite,0,Dmap->tag);
							Dmap->sp = sprite;
						}
					}else{
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(imagineUnlikeNeed::queryresultMadeFactLocal,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(imagineUnlikeNeed::calculatesDimensionAlong,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							m_reversesSoonVectors.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
		}
	}
	_infoMutex.unlock();
}
void imagineUnlikeNeed::setlinkageUpdatesShared(int x,int y,bool updateShow)
{
	if (m_isNoRes)
		return;
	bool need_load = false;
	_infoMutex.lock();
	struct completesEven *Dmap = linkageUpdatesShared;
	std::vector<completesEven*> needLoadDmap;
	while(Dmap!=nullptr)
	{
		if(stunninglyWithfifth){
		
			Dmap->Status = true;
			if(Dmap->Status&&Dmap->sp == nullptr&&loadall&&(!Dmap->loaded))
			{
				need_load = true;
				needLoadDmap.push_back(Dmap);
			}
			if(updateShow && Dmap->sp) Dmap->sp->setVisible(Dmap->Status);
			Dmap = Dmap->Next;
		}
		else{
		
			Dmap->Status = getbrowsersActsLiteralsBasic(x,y,Dmap->x,Dmap->y);
			if(Dmap->Status&&Dmap->sp == nullptr&&loadall&&(!Dmap->loaded))
			{
				need_load = true;
				needLoadDmap.push_back(Dmap);
			}
			if(updateShow && Dmap->sp) Dmap->sp->setVisible(Dmap->Status);
			Dmap = Dmap->Next;
		}
	}
	_infoMutex.unlock();
	if(need_load)
	{
		scopingAliasTwin(needLoadDmap);
	
	
	}
}
bool imagineUnlikeNeed::findAlthoughOkay(int AstarNum){
	loadall = true;
	if (m_movesWhatever)
		findShouldAccessed = this;
	if (AstarNum == 0)
		return m_movesWhatever;
	if (AstarNum == 1)
		return m_validMatchedExecutable;
	if (AstarNum == 2)
		return doesndifferViolations;
	return m_movesWhatever;
}
void imagineUnlikeNeed::setScale(float scale)
{
	Node::setScale(scale);
}
bool imagineUnlikeNeed::loadMap(const std::string& tmxFile,const std::string& resFile,const  int mapId, const bool isMultiMap, const Point mpos)
{
	if(tmxFile.length() <= 0 )
		return true;
	m_mapId = mapId;
	m_pMap = TMXTiledMap::create(tmxFile);
	calculateArraysWhat(tmxFile);
	role_pos = mpos;
	if (m_pMap)
	{
		if (isMultiMap)
		{
		
		}
		win =  Director::getInstance()->getWinSize();
		m_pBolck = m_pMap->getLayer("blockLayer");
		m_pBolck->setVisible(false);
		m_perTileSize = m_pBolck->getMapTileSize();
		m_mapSize = m_pBolck->getLayerSize();
		m_winSize = Director::getInstance()->getWinSize();	
	
		forcesUsersGeneric(mapId);
		Ref* pObject = nullptr;  
		auto& children = m_pMap->getChildren();
		SpriteBatchNode* child = nullptr;
		for(const auto &node : children) {
			child = static_cast<SpriteBatchNode*>(node);
			child->getTexture()->setAntiAliasTexParameters();
		}
		m_heightIndicesSimplify = mpos;
		addChild(m_pMap);
		auto pot = resFile.find_last_of('.');
		_infoMutex.lock();
		mapstr = resFile;
		mapstr.replace(pot,4,"/");
		_infoMutex.unlock();
		load_Thread2 = new std::thread(&imagineUnlikeNeed::newAstar,this);
		load_Thread2->detach();
		load_Thread3 = new std::thread(&imagineUnlikeNeed::newAstar2,this);
		load_Thread3->detach(); 
		loop_flag = 2;
		float scale = imagineUnlikeNeed::m_resourceManageDereference;
		setScale(scale);
		Point space = CC_POINT_PIXELS_TO_POINTS(applicableInstances(role_pos));
		Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
		Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
		if (pos.x > 0.0f) pos.x = 0.0f;
		if (pos.y > 0.0f) pos.y = 0.0f;
		if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
		if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
		setPosition(pos);
		if (programRules::machinesOkay)
		{
			programRules::machinesOkay->loadBack(resFile, mapId);
			programRules::machinesOkay->doubleprecRuleUnnecessary(pos);
		}
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto myListener = EventListenerTouchOneByOne::create();
	
		myListener->setSwallowTouches(true);
		myListener->onTouchBegan = [=](Touch* touch,Event* event)
		{
			if(employeeCreatingProgram < dir_undef)
				return false;
			return true;  
		};
		myListener->onTouchMoved = [=](Touch* touch,Event* event)
		{
		};
		myListener->onTouchEnded = [=](Touch* touch,Event* event)
		{
			if(usesProperly < SPEED)
				return;
			Point start = touch->getStartLocation();
			Point dest = touch->getLocation();
			Point span = dest - start;
			Point tile = actsWishQualify(dest);
			Point tile_orign = tile;
		
			if (role_main != nullptr && !role_main->getActive())
			{
				if (m_noteDigits > 0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != nullptr)
					{
						pStack->pushInt(1);
						pStack->executeFunctionByHandler(m_noteDigits, 1);
						pStack->clean();
					}
				}
			}
			else if(dest.getDistance(start) < 30 && role_main!=nullptr&&role_main->getActive()&&role_main->isAlive() && role_main->getspecializedComplication() != ACTION_STATE_FLY && role_main->getspecializedComplication() != ACTION_STATE_SUDDEN)
			{
				if(isBlock(tile)){
				
					tile = initializingConceptually(m_heightIndicesSimplify,tile);
					if(isBlock(tile) || tile == Vec2::ZERO)
						return;
				}
			
				usesProperly = 0;
			
				#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
					printf("memory %d\r\n",getCurrMemory());
 
				#endif
				inverselyStoredSection(applicableInstances(tile_orign));
				if(employeeCreatingProgram >= dir_undef)
				{
					initializtheTookEven(tile);
					if(m_rock_cb)
					{
						LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
						if (pStack != nullptr)
						{
							pStack->pushInt(1);
							pStack->executeFunctionByHandler(m_rock_cb, 1);
							pStack->clean();
						}
					}	
				}
			}
			else if(abs(span.x)<80&&abs(span.y)>50&&m_cabePointers)  
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->pushBoolean(span.y > 0);
					pStack->executeFunctionByHandler(m_cabePointers, 1);
					pStack->clean();
				}
			}
		};
		dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);
		scheduleUpdate();
		return true;
	}
	return false;
}
void imagineUnlikeNeed::calculateArraysWhat(const std::string tmxFile)
{
	auto pot = tmxFile.find_last_of("/");
	auto tmpTmx = tmxFile.substr(0, pot + 1);
	auto tmpTmx1 = tmxFile.substr(pot + 1);
	tmpTmx.append("block/");
	tmpTmx.append(tmpTmx1);
	performanceInstantiates = FileUtils::getInstance()->getStringFromFile(tmpTmx);
	if (performanceInstantiates.empty())
		return;
	auto first = performanceInstantiates.find_first_of("\n");
	auto last = performanceInstantiates.find_last_of("\n");
	performanceInstantiates = performanceInstantiates.substr(last + 1);
}
void imagineUnlikeNeed::evaluatedCoveredUltimate()
{
		TMXLayer* bg_layer = m_pMap->getLayer("bgLayer");
	
		if(bg_layer == nullptr&&linkageUpdatesShared==nullptr)
		{
			_infoMutex.lock();
			struct completesEven *t_Map;
			for(int i=0;i<m_mapSize.width;i=i+m_isbnsPresumably)
			{
				for(int j=0;j<m_mapSize.height;j=j+nonstaticPrecedingTypeids)
				{
					struct completesEven *D_Map;
					D_Map = (struct completesEven *)malloc(sizeof(struct completesEven));
					D_Map->x = i;
					D_Map->y = j;
					D_Map->tag = i/m_isbnsPresumably*m_mapSize.width+j/nonstaticPrecedingTypeids;
					D_Map->Next = nullptr;
					D_Map->sp = nullptr;
					D_Map->loaded = false;
					D_Map->Status = true;
					if(linkageUpdatesShared == nullptr)
					{
						linkageUpdatesShared = D_Map;
						t_Map = linkageUpdatesShared;
					}
					else
					{
						t_Map->Next = D_Map;
						t_Map = t_Map->Next;
					}
				}
			
			}
			_infoMutex.unlock();
		}
		else
		{
			tickCache(0);
			return;
		}
	
	
		overrideRecursiveDeclares(); 
}
void imagineUnlikeNeed::newAstar()
{
	AStarMap = NewAstarMap(m_mapSize,this);
	m_validMatchedExecutable = true;
}
void imagineUnlikeNeed::newAstar2()
{
	AStarMap2 = NewAstarMap(m_mapSize,this);
	doesndifferViolations = true;
}
void imagineUnlikeNeed::tickCache(float dt)
{
	if(!loadall)
	{
		loadall = true;
		setlinkageUpdatesShared(m_heightIndicesSimplify.x,m_heightIndicesSimplify.y);
	
	
	}
}
bool imagineUnlikeNeed::doethSelectsExamines(std::string key_value){
	bool isDownload = false;
	lua_State* state = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	int top = lua_gettop(state);
	int nResult = 0;
	try
	{
		lua_getglobal(state, "isMapCellDownloaded");
	
		if(!lua_isfunction(state, -1))
		{
			log("invalid function\n");
			goto RFEXIT;
		}
		lua_pushnumber(state, m_mapId);
		lua_pushstring(state, key_value.c_str());
		nResult = lua_pcall(state, 2, 1, 0);
		if(nResult == 0)
		{
			isDownload = (lua_toboolean(state, -1)) > 0?true:false;
		}
		else
		{
			log("[LUA ERROR] %s", lua_tostring(state, - 1));
		}
	}
	catch (...) {
		log("[LUA ERROR]");
	}
RFEXIT:
	lua_settop(state, top);
	if(nResult != 0)
		log("[LuaEngine] call function %s(...) failed\n", "isMapCellDownloaded");        
	return isDownload;
}
void imagineUnlikeNeed::overrideRecursiveDeclares()
{
	_infoMutex.lock();
	struct completesEven *Dmap = linkageUpdatesShared;
	char imgstr[128] = {0};
	if (!m_isNoRes)
	{
		while(Dmap!=nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/m_isbnsPresumably,Dmap->y/nonstaticPrecedingTypeids, m_operationsEncountersLike.c_str());
		
			m_succeedsFound.push_back(imgstr);
			if(Dmap->sp == nullptr&&(getbrowsersActsLiteralsBasic(role_pos.x,role_pos.y,Dmap->x,Dmap->y)))
			{
				if(separatesSmatchProcessing == true)
				{
				
				
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(imagineUnlikeNeed::queryresultMadeFactLocal,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(imagineUnlikeNeed::calculatesDimensionAlong,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						m_reversesSoonVectors.insert(std::pair<int,std::string>(entryId,imgstr));
				}
				else if(m_facilityRepresented)
				{
				
					if(doethSelectsExamines(imgstr) == false)
					{
						limitEscapeBackslash *sprite = limitEscapeBackslash::create(imgstr,"res/syncReplace/map_cell.jpg");
						if(sprite)
						{
							sprite->setAnchorPoint(Point(0,1));
							sprite->setPosition(Point(Dmap->x*m_perTileSize.width,(m_mapSize.height-Dmap->y)* m_perTileSize.height));
							m_pMap->addChild(sprite,0,Dmap->tag);
							Dmap->sp = sprite;
						}
					}
					else
					{
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(imagineUnlikeNeed::queryresultMadeFactLocal,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(imagineUnlikeNeed::calculatesDimensionAlong,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							m_reversesSoonVectors.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
			Dmap = Dmap->Next;
		}
		this->m_movesWhatever = true;
	}
	else
	{
		this->m_movesWhatever = true;
	}
	_infoMutex.unlock();
}
void imagineUnlikeNeed::queryresultMadeFactLocal(cocos2d::Texture2D *a,completesEven* DmapNode)
{
	char imgstr[128] = {0};
	if(DmapNode!=nullptr&&mapstr.size()>0)
	{
		if(DmapNode->sp == nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),DmapNode->x/m_isbnsPresumably,DmapNode->y/nonstaticPrecedingTypeids, m_operationsEncountersLike.c_str());
			Texture2D *text = Director::getInstance()->getTextureCache()->getTextureForKey(imgstr);
			if(text)
			{
				Sprite *sprite = Sprite::createWithTexture(text);
				if(sprite)
				{
					sprite->setAnchorPoint(Point(0,1));
					sprite->setPosition(Point(DmapNode->x*m_perTileSize.width,(m_mapSize.height-DmapNode->y)* m_perTileSize.height));
					m_pMap->addChild(sprite,0,DmapNode->tag);
					DmapNode->sp = sprite;
					Director::getInstance()->getTextureCache()->removeTextureForKey(imgstr);
				}
			}
		}
	}
}
void imagineUnlikeNeed::calculatesDimensionAlong(int entryId){
	if(entryId <= 0) 
		return;
	auto iter = m_reversesSoonVectors.find(entryId);
	if(iter != m_reversesSoonVectors.end()){
		m_reversesSoonVectors.erase(iter);
	}
}
void imagineUnlikeNeed::extensioindicating()
{
	if(role_main!=nullptr){
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
		leastInspiredThing();
	}
}
void imagineUnlikeNeed::modifyEntirePowerful2(Point start,bool isFb)
{
	if(m_isFb == false)
		m_isFb = isFb;
	if(role_main!=nullptr)
	{
		role_main->stop = CC_CALLBACK_0(imagineUnlikeNeed::supplySerialMembers, this); 
		role_main->onWalk = CC_CALLBACK_3(imagineUnlikeNeed::relativePersistDecrement1, this);
		role_main->extensioindicating = CC_CALLBACK_0(imagineUnlikeNeed::extensioindicating, this); 
		role_main->onFly = CC_CALLBACK_5(imagineUnlikeNeed::FlyRocket, this); 
		role_main->alwaysAvoidClassesclick = CC_CALLBACK_4(imagineUnlikeNeed::alwaysAvoidClassesclick, this); 
		Point startpos = role_main->getPosition();
		if(start!=Point())
			m_heightIndicesSimplify = start;
		else
			m_heightIndicesSimplify = inverselyThpositionComes(startpos);
		employeeCreatingProgram = dir_undef;
		incompleteElementsStorage(true);
	}
	if(m_effect==nullptr)
	{
		m_effect = knewOverheadSupplied::create(false);
		addChild(m_effect,1);
	}
}
int imagineUnlikeNeed::getwcouldCoverConstructors(Point tile){
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return 1;
	auto id = m_pBolck->getTileGIDAt(tile);
	Value v = m_pMap->getPropertiesForGID(id);
	if (!v.isNull()){
		ValueMap s = v.asValueMap();
		if (s.find("flag") != s.end())
		{
			return s.at("flag").asInt();
		}
	}
	return 0;
}
int imagineUnlikeNeed::getpromptLookupWrotePosition(Point tile){
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return 0;
	auto id = m_pBolck->getTileGIDAt(tile);
	Value v = m_pMap->getPropertiesForGID(id);
	if (!v.isNull()){
		ValueMap s = v.asValueMap();
		if (s.count("fly_mode") > 0)
		{
			return (*s.find("fly_mode")).second.asInt();
		}
	}
	return -1;
}
bool imagineUnlikeNeed::isBlock(Point tile)
{
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return true;
	int x = tile.x;
	int y = tile.y;
	return (performanceInstantiates.at(x*int(m_mapSize.height) + y) == '1');
}
bool imagineUnlikeNeed::isOpacity(Point tile)
{
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return true;
	auto id = m_pBolck->getTileGIDAt(tile);
	Value v = m_pMap->getPropertiesForGID(id);
	if (!v.isNull()){
		ValueMap s = v.asValueMap();
		if( s.count("flag") > 0 )
		{
			if((*s.find("flag")).second.asInt() == 2)
				return true;
		}
	}
	return false;
}
Point imagineUnlikeNeed::actsWishQualify(Point point)
{
	return inverselyThpositionComes(lastLevelImage(point));
}
Point imagineUnlikeNeed::consistsSubscriptPassing(Point tile)
{
	return answerWordsMutually(applicableInstances(tile));
}
Point imagineUnlikeNeed::lastLevelImage(Point point)
{
	return convertToNodeSpace(point);
}
Point imagineUnlikeNeed::answerWordsMutually(Point pos)
{
	return convertToWorldSpace(pos); 
}
Point imagineUnlikeNeed::applicableInstances(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y+0.5))* m_perTileSize.height;
	return Point(sx,sy);
}
Point imagineUnlikeNeed::inverselyThpositionComes(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y/m_perTileSize.height);
	int tx = floor(pos.x/m_perTileSize.width);
	return Point(tx, ty); 
}
void imagineUnlikeNeed::contextNameEnumeration(Point tile,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	if(speed != -1){
		m_encloseProvide = (speed>0.01)?speed:m_encloseProvide;
	
		if(employeeCreatingProgram>= dir_undef)
		{
			m_heightIndicesSimplify = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ theyKindsFundamental();});
			auto action = Sequence::create(DelayTime::create(m_encloseProvide-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		m_heightIndicesSimplify = tile;
	}
	float scale = imagineUnlikeNeed::m_resourceManageDereference;
	Point space = CC_POINT_PIXELS_TO_POINTS(applicableInstances(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void imagineUnlikeNeed::unwindingAverage(Point pos_,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	auto tile = inverselyThpositionComes(pos_);
	if(speed != -1){
		m_encloseProvide = (speed>0.01)?speed:m_encloseProvide;
	
		if(employeeCreatingProgram>= dir_undef)
		{
			m_heightIndicesSimplify = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
				theyKindsFundamental();
			});
			auto action = Sequence::create(DelayTime::create(m_encloseProvide-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		m_heightIndicesSimplify = tile;
	}
	float scale = imagineUnlikeNeed::m_resourceManageDereference;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void imagineUnlikeNeed::scrollMap(Point pos,float speed)
{
	if (m_pMap)
	{
		pos = dynamicallyOverAffects(pos);
	
		bestViolate(pos);
		leastInspiredThing();
		if(speed != -1){
			FiniteTimeAction* resetfun = CallFunc::create([&](){ incompleteElementsStorage(true);});
			ActionInterval* move = MoveTo::create(m_encloseProvide, pos);
			Action* action = Sequence::create(move,resetfun,nullptr);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}else{
			setPosition(pos);
			incompleteElementsStorage(true);
			if (programRules::machinesOkay)
			{
				programRules::machinesOkay->doubleprecRuleUnnecessary(pos);
			}
		}
	}
}
Vec2 imagineUnlikeNeed::encapsulationSolveSketch(Vec2 pos_){
	float scale = imagineUnlikeNeed::m_resourceManageDereference;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = dynamicallyOverAffects(pos);
	bestViolate(pos);
	return pos;
}
void imagineUnlikeNeed::bestViolate(Vec2& pos){
	float scale = imagineUnlikeNeed::m_resourceManageDereference;
	Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
	Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale-1)/2;
	edgeSize = edgeSize + edgeSize1;
	if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
	if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
	if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
	if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
}
void imagineUnlikeNeed::skip2Tile(Point tile)
{
	m_heightIndicesSimplify = tile;
	float scale = imagineUnlikeNeed::m_resourceManageDereference;
	Point space = CC_POINT_PIXELS_TO_POINTS(applicableInstances(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = dynamicallyOverAffects(pos);
	if (m_pMap)
	{
	
		bestViolate(pos);
		setPosition(pos);
		incompleteElementsStorage(true);
		if (programRules::machinesOkay)
		{
			programRules::machinesOkay->doubleprecRuleUnnecessary(pos);
		}
	}
}
Vec2 imagineUnlikeNeed::dynamicallyOverAffects(Vec2 pos){
	pos.y -= m_perTileSize.height * 5;
	return pos;
}
void imagineUnlikeNeed::incompleteElementsStorage(bool right_away,Vec2 tile)
{
	if(right_away)
	{
		m_debuggingIncludingEasier = 1;
	}
	if(m_debuggingIncludingEasier % 5 == 1)
	{
	
		Node* item_node = getChildByTag(316);
		if(item_node && !m_isFb)
		{
			for (auto& child : item_node->getChildren())
			{
				addingRelies* base = dynamic_cast<addingRelies*>(child);
				if (base == nullptr)
				{
					bool visible_ = priceOperationLike(child);
					child->setVisible(visible_);
				}
				else
				{
					if(role_main && role_main->getrankedClauseHowevewe() == base->getrankedClauseHowevewe())
						continue;
					assumeApproachEmbodies* player = dynamic_cast<assumeApproachEmbodies*>(child);
					wantedConvertibleGroup baseType = base->getTypeId();
					if (baseType == wantedConvertibleGroup::PLAYER_MANE_TYPE || baseType == wantedConvertibleGroup::PLAYER_FEMALE_TYPE
						|| baseType == wantedConvertibleGroup::NORMAL_MONSTER || baseType == wantedConvertibleGroup::ELIT_MONSTER || baseType == wantedConvertibleGroup::BOSS_MONSTER || baseType == wantedConvertibleGroup::JUQING_MONSTER
						|| baseType == wantedConvertibleGroup::PLAYER_MANE_TYPE
						|| baseType == wantedConvertibleGroup::NPC_TYPE)
					{
						bool visible_ = priceOperationLike(child,base);
						if(player == nullptr){
							child->setVisible(visible_);
							base->setshownRatherInitially(visible_);
						}else if (player->getexpressionasInvolveCode() == 0){
							player->setVisible(visible_);
							player->setshownRatherInitially(visible_);
						
						}
					}
				}
			}
		}
	
		item_node = getChildByTag(317);
		if(item_node)
		{
			for (auto& child : item_node->getChildren())
			{
				bool visible_ = priceOperationLike(child);
				child->setVisible(visible_);
			}
		}
	
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr && m_formOrganizeEquality != 0)
		{
			pStack->executeFunctionByHandler(m_formOrganizeEquality, 0);
			pStack->clean();
		}
	
		Vec2 c_tile = Vec2::ZERO;
		if(tile != Vec2::ZERO){
			c_tile = tile;
		}
		else if(role_main && role_main->getexpressionasInvolveCode() != 1 && role_main->getexpressionasInvolveCode() != 3){
			c_tile = inverselyThpositionComes(role_main->getPosition());
		}
	
		if(c_tile != Vec2::ZERO)
			setlinkageUpdatesShared(c_tile.x, c_tile.y, true);
	}
	m_debuggingIncludingEasier++;
}
bool imagineUnlikeNeed::priceOperationLike(Node* child,addingRelies* base)
{
	bool visible_ = true;
	if(stunninglyWithfifth)
	{
		visible_ = true;
	}
	else
	{
		Point n_pos = answerWordsMutually(child->getPosition());
		if(Rect(0,0,win.width,win.height).containsPoint(n_pos))
		{
			visible_ = true;
		}
		else
		{
			visible_ = false;
		}
	}
	return visible_;
}
assumeApproachEmbodies* imagineUnlikeNeed::getupdatesPersistSpecifying3(){
	return role_main;
}
void imagineUnlikeNeed::setupdatesPersistSpecifying3(assumeApproachEmbodies* role){
	role_main = role;
	if(role_main)
		role_main->setimagineUnlikeNeed(this);
}
void imagineUnlikeNeed::controlSpelling(bool stop_rock,bool removeWalCb,bool doStand)
{
	if(role_main){
		AStarPath = nullptr;
		theyKindsFundamental();
	
	
		if(stop_rock)
			supplySerialMembers();
		else if(role_main)
			unnamedAttemptsPurposes(role_main->getinstantiatingBindRegular(),0,Vec2::ZERO,0);
		role_main->leastInspiredThing();
		leastInspiredThing();
		if(doStand){
			if(role_main->getspecializedComplication() != ACTION_STATE_IDLE)
				role_main->standed();
		}
		if(removeWalCb){
			m_walk_cb = 0;
			builtAskingInstances();
		}
		m_stoprocessingRepeatAsking = Vec2::ZERO;
		_m_time = 1000;
	}
}
void imagineUnlikeNeed::insideArgumepassedAngle(){
	AStarPath = nullptr;
	theyKindsFundamental();
	if(role_main)
		role_main->leastInspiredThing();
	_m_time = 1000;
}
void imagineUnlikeNeed::programOperatesListed(cocos2d::Point cp, bool isnear, int spaceNum, bool sendMsg)
{
	if(AStarMap == nullptr)
	{
		CPLUSLog("[imagineUnlikeNeed::programOperatesListed] AStarMap == nullptr");
		return;
	}
	controlSpelling(false,false,false);
	InitAstarMap(AStarMap);
	AStarPath = FindPath(m_heightIndicesSimplify.x, m_heightIndicesSimplify.y, cp.x, cp.y, AStarMap);
	if (isnear)
	{
		struct rightItasSuccessful *path =  AStarPath;
		while(path != NULL ) 
		{
			if (path->Next == NULL)
			{
			
				struct rightItasSuccessful *tmpPath = path;
				for (int i = 0; i < spaceNum; i++)
				{
					struct rightItasSuccessful *tmpPath2 = tmpPath->Father;
					if (tmpPath2 == NULL )
					{
						AStarPath = NULL;
						break;
					}
					tmpPath = tmpPath2;
				}
				tmpPath->Next = NULL;
			}
			path = path->Next;
		}
	}
	striparameterImportance(AStarPath, NULL, sendMsg);
}
void imagineUnlikeNeed::wmustInitializationsSafe(cocos2d::Point cp)
{
	if(loop_flag != 2|| role_main == nullptr ) return ;
	programOperatesListed(cp, false, 0, false);
}
void imagineUnlikeNeed::genericCompletes(Point cp,bool isnear, int spaceNum)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getspecializedComplication()>ACTION_STATE_CHENMO) return ;
	if (role_main != nullptr && !role_main->getActive())
	{
		if (m_noteDigits > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(3);
				pStack->executeFunctionByHandler(m_noteDigits, 1);
				pStack->clean();
			}
		}
		CPLUSLog("[imagineUnlikeNeed::genericCompletes] role cannot Move");
		return;
	}
	programOperatesListed(cp, isnear, spaceNum);
	employeeCreatingProgram = dir_undef;
}
int imagineUnlikeNeed::developedObtainPair(Point cp,labelsPointRepresentation* monster,float sp,bool isnear,Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getspecializedComplication()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	Point m_tile = inverselyThpositionComes(monster->getPosition());
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	struct rightItasSuccessful *path = FindPath(m_tile.x, m_tile.y, cp.x, cp.y, AStarMap2);
	_mapMutex.unlock();
	if(path == nullptr) return 0;
	struct rightItasSuccessful *path1 = path;
	int i = 0;
	striparameterImportance(path,monster);
	path1 = path;
	while(path1!=nullptr)
	{
		tabl[i] = Point(path1->X,path1->Y);
		path1 = path1->Next;
		i++;
	}
	return i;
}
void imagineUnlikeNeed::matterAppliedStrcmp(labelsPointRepresentation* item,cocos2d::Point cp){
	if(cp == Vec2::ZERO)
		cp = inverselyThpositionComes(item->getPosition());
	senseGrades *luaEventMgr = senseGrades::instance();
	yieldsAnswerAlways buffer = luaEventMgr->getoccursInteractsReturning(C2S_MOVE);
	buffer.pushShort(item->getSpeed());
	buffer.pushBool(false);
	buffer.pushShort(m_mapId);
	buffer.pushShort(cp.x);
	buffer.pushShort(cp.y);
	buffer.pushShort(0);
	andqueryApplies::getInstance()->updateSelectsButton(buffer);
}
int imagineUnlikeNeed::getformComparingDirection(Point start,Point dest,bool selfFlg, Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getspecializedComplication()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	if (selfFlg && role_main != nullptr && !role_main->getActive())
	{
		if (m_noteDigits > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(5);
				pStack->executeFunctionByHandler(m_noteDigits, 1);
				pStack->clean();
			}
		}	
		return 0;
	}
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	int i = 0;
	struct rightItasSuccessful *path = FindPath(start.x, start.y, dest.x, dest.y, AStarMap2);
	fixPath(path);
	_mapMutex.unlock();
	while(path!=nullptr)
	{
		tabl[i] = Point(path->X,path->Y);
		path = path->Next;
		i++;
	}
	return i;
}
void imagineUnlikeNeed::initializtheTookEven(Point d_tile)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getspecializedComplication()>ACTION_STATE_CHENMO) return ;
	if(AStarMap == nullptr)
		return;
	controlSpelling(false,true,false);
	InitAstarMap(AStarMap);
	employeeCreatingProgram = dir_undef;
	AStarPath = FindPath(m_heightIndicesSimplify.x, m_heightIndicesSimplify.y, d_tile.x, d_tile.y, AStarMap);
	if(AStarPath!=nullptr)
	{
		striparameterImportance(AStarPath);
	}
}
void imagineUnlikeNeed::fullyOrdinaryTimes(){
	do 
	{
		char filenName[50];
		sprintf(filenName,"res/map/FlyTrigger_%d.cfg",m_mapId);
		if(FileUtils::getInstance()->isFileExist(filenName) == false)
			break;
		string filePath = FileUtils::getInstance()->fullPathForFilename(filenName);
		string jsStr=FileUtils::getInstance()->getStringFromFile(filePath);
		if(jsStr.size() <= 0)
			break;
		rapidjson::Document doc;
		doc.Parse<0>(jsStr.c_str());
		if (doc.HasParseError())
		{
			CCLOG("UserManage::LoadUsers parse json error!");
			break;
		}
		if (doc.HasMember("entities"))
		{
			const rapidjson::Value& triggerListValue=doc["entities"];
			if (triggerListValue.IsArray()&&triggerListValue.Size()>0)
			{
				increasedState.clear();
				int userCount=triggerListValue.Size();
				for (int i=0;i<userCount;i++)
				{
					const rapidjson::Value &trigger=triggerListValue[i];
					if (trigger.IsObject())
					{
						pointerfifthBypass newTrigger;
						newTrigger.m_guideAboveUser = Vec2::ZERO;
						newTrigger.preventsCopiesWide = Vec2::ZERO;
						int x,y;
						const rapidjson::Value &m_guideAboveUser = trigger["m_guideAboveUser"];
						x = m_guideAboveUser["x"].GetInt();
						y = m_guideAboveUser["y"].GetInt();
						newTrigger.m_guideAboveUser = Vec2(x,y);
						const rapidjson::Value &preventsCopiesWide = trigger["preventsCopiesWide"];
						x = preventsCopiesWide["x"].GetInt();
						y = preventsCopiesWide["y"].GetInt();
						newTrigger.preventsCopiesWide = Vec2(x,y);
						increasedState.push_back(newTrigger);
					}
				}
			}
		}
	} while (0);
}
pointerfifthBypass imagineUnlikeNeed::usersEnumsShorttypWorth(cocos2d::Vec2 point){
	for(std::vector<pointerfifthBypass>::iterator iter = increasedState.begin();iter!=increasedState.end();iter++){
		pointerfifthBypass trigger = *iter;
		if(trigger.m_guideAboveUser.x == point.x && trigger.m_guideAboveUser.y == point.y){
			return trigger;
		}
	}
	pointerfifthBypass newTrigger;
	newTrigger.m_guideAboveUser = Vec2::ZERO;
	newTrigger.preventsCopiesWide = Vec2::ZERO;
	return newTrigger;
}
void imagineUnlikeNeed::constraintsModernCentral(){
	if(m_stoprocessingRepeatAsking != Vec2::ZERO){
		genericCompletes(m_stoprocessingRepeatAsking);
		m_stoprocessingRepeatAsking = Vec2::ZERO;
		if(role_main)
			role_main->incrementingPurpose(true);
	}
}
bool imagineUnlikeNeed::becomeThemselvesMaking(int typeId,cocos2d::Vec2 point){
	return false;
	if(role_main == nullptr)
		return false;
	int fly_mode = getpromptLookupWrotePosition(point);
	bool auto_double_jump_check = false;
	if(fly_mode == -1)
		auto_double_jump_check = true;
	if(typeId == 1){
	
		if(getwcouldCoverConstructors(point) == 3){
			Vec2 flyTarget = Vec2::ZERO;
			pointerfifthBypass trigger = usersEnumsShorttypWorth(point);
			flyTarget = trigger.preventsCopiesWide;
			if(flyTarget != Vec2::ZERO){
			
				Vec2 tmp = Vec2::ZERO;
				if(AStarPath && AStarPath->Next != nullptr){
					while (AStarPath->Next != nullptr){
						AStarPath = AStarPath->Next;
					}
				
					if(isBlock(Vec2(AStarPath->X,AStarPath->Y)) == false && getwcouldCoverConstructors(Vec2(AStarPath->X,AStarPath->Y)) != 3)
						tmp = Vec2(AStarPath->X,AStarPath->Y);
				}
				role_main->whateverEvaluatesDerived(0,fly_mode,0,applicableInstances(flyTarget),dir_none,true,auto_double_jump_check);
				role_main->incrementingPurpose(false,flyTarget);
				m_stoprocessingRepeatAsking = tmp;
				return true;
			}
		}
	}else{
	
		if(getwcouldCoverConstructors(point) == 3){
			Vec2 flyTarget = Vec2::ZERO;
			pointerfifthBypass trigger = usersEnumsShorttypWorth(point);
			flyTarget = trigger.preventsCopiesWide;
			if(flyTarget != Vec2::ZERO){
				role_main->whateverEvaluatesDerived(0,1,0,applicableInstances(flyTarget),dir_none,true,auto_double_jump_check);
				role_main->incrementingPurpose(false,flyTarget);
				return true;
			}
		}
	}
	return false;
}
void imagineUnlikeNeed::moreIndicesTypeids4(){
	if(AStarPath && role_main){
		role_main->standed();
		while (AStarPath->Next != nullptr){
			AStarPath = AStarPath->Next;
		}
		genericCompletes(Vec2(AStarPath->X,AStarPath->Y));
	}
}
void imagineUnlikeNeed::flowsFriendsWhyouBehavior(){
	if(AStarPath )
	{
	
		theyKindsFundamental();
		Vec2 checkPoint = Vec2(AStarPath->X,AStarPath->Y);
		AStarPath = nullptr;
		if(becomeThemselvesMaking(1,checkPoint))
			return;
		if(role_main)
			role_main->standed();
		extensioindicating();
		int flg = 3;
		if (m_walk_cb > 0)
		{
			flg = 7;
		}
		if(m_walk_cb)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->executeFunctionByHandler(m_walk_cb, 0);
				pStack->clean();
			}
		}
		if(m_rock_cb)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(flg);
				pStack->executeFunctionByHandler(m_rock_cb, 1);
				pStack->clean();
			}
		}
	
		incompleteElementsStorage(true);
	}
}
void imagineUnlikeNeed::update(float dt)
{
	if(role_main == nullptr)
	{
		return;
	}
	if (dynamic_cast<Node*>(m_completesRather))
	{
		updatePos();
	}
	if(role_main->getspecializedComplication() > ACTION_STATE_CHENMO)
	{
		if (role_main->beControl())
		{
			separatelyFoundAllocated(dt);
		}
		return;
	}
	_m_time += dt;
	usesProperly += dt; 
	m_moreovesomeSuccessful += dt;
	m_currentTopics += dt;
	if(usesProperly>SPEED*8) usesProperly = SPEED*4;
	auto status = role_main->getspecializedComplication();
	if(status != ACTION_STATE_IDLE){
		m_moreovesomeSuccessful = 0;
	}
	if(employeeCreatingProgram < dir_undef && _m_time >= m_encloseProvide)
	{
		_m_time = 0;
		if(role_main->canMove()){
			cocos2d::Vec2 startPos = role_main->getPosition();
			cocos2d::Vec2 targetPos = startPos;
			m_heightIndicesSimplify = inverselyThpositionComes(targetPos);
			targetPos.add(m_letsIstream * 60);
			m_convertingSameHowevewe = inverselyThpositionComes(targetPos);
			m_convertingSameHowevewe = convenientAssumeRecognize4(m_heightIndicesSimplify,m_convertingSameHowevewe);
			if(isBlock(m_convertingSameHowevewe))
			{
				Point tile = getinsideOperandsWhat(m_convertingSameHowevewe,employeeCreatingProgram);
				if(!isBlock(tile) && tile != m_heightIndicesSimplify)
				{
					m_convertingSameHowevewe = tile;
					accessedIntroductory temp_dir = getdebuggingRespective(m_convertingSameHowevewe-m_heightIndicesSimplify);
					m_takingMeddleTimes = m_fileTurnsSemicolon;
					targetPos = applicableInstances(m_convertingSameHowevewe);
					m_letsIstream = (targetPos - startPos).getNormalized();
				}
			}
			if(!isBlock(m_convertingSameHowevewe))
			{
				if(becomeThemselvesMaking(2,m_convertingSameHowevewe) == true){
					return;
				}
				Point role_move_pc = targetPos;
				Point role_move_pc_start = role_main->getPosition();
				Point role_move_pc_send = targetPos;
				role_move_pc_send.add(m_letsIstream * 60);
				Vec2 role_tile_send = inverselyThpositionComes(role_move_pc_send);
				if(isBlock(role_tile_send)){
					role_move_pc_send = role_move_pc;
					role_tile_send = inverselyThpositionComes(role_move_pc_send);
				}
				float distance = role_move_pc_start.distance(role_move_pc);
				m_encloseProvide = distance/map_speed;
				role_main->cleanMove(false);
				role_main->greaterFunctiwith(role_tile_send,false);
				unnamedAttemptsPurposes(accessedIntroductory::dir_none,1,role_tile_send,0);
				AStarPath = nullptr;
			}
		}
	}
	else if(m_isrock == true && AStarPath == nullptr && employeeCreatingProgram ==dir_undef && (status == ACTION_STATE_WALK || status == ACTION_STATE_RUN))
	{
	
		m_isrock = false;
		theyKindsFundamental();
		role_main->cleanMove();
		AStarPath = nullptr;
		_m_time = 10000;
		role_main->standed();
		if(m_rock_cb)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(4);
				pStack->executeFunctionByHandler(m_rock_cb, 1);
				pStack->clean();
			}
		}
		incompleteElementsStorage(true);
	}
	else if(status == ACTION_STATE_WALK || status == ACTION_STATE_RUN || status == ACTION_STATE_FLY || status == ACTION_STATE_SUDDEN){
		incompleteElementsStorage();
	
	
		if(m_currentTopics >= 0.5){
			m_currentTopics = 0;
			if(m_rock_cb)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->pushInt(6);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
		}
	}else if(status == ACTION_STATE_IDLE){
		if(m_moreovesomeSuccessful >= 1){
			m_moreovesomeSuccessful = 0;
			incompleteElementsStorage(true);
		}
	}
	separatelyFoundAllocated(dt);
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
unsigned long imagineUnlikeNeed::getCurrMemory()
{
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	return pmc.WorkingSetSize;
}
#endif
Point imagineUnlikeNeed::getinsideOperandsWhat(Point dir_tile,accessedIntroductory dir,int titleOffset)
{
	Point tile = dir_tile;
	switch (dir)
	{
	case dir_up:
		do
		{
			tile.x = dir_tile.x + 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x - 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y + 1;
			tile.x = dir_tile.x + 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x - 1;
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_down:
		do
		{
			tile.x = dir_tile.x + 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x - 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y - 1;
			tile.x = dir_tile.x + 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x - 1;
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_left:
		do
		{
			tile.y = dir_tile.y + 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y - 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x + 1;
			tile.y = dir_tile.y + 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y - 1;
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_right:
		do
		{
			tile.y = dir_tile.y + 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y - 1;
			if(!isBlock(tile)) break;
			tile.x = dir_tile.x - 1;
			tile.y = dir_tile.y + 1;
			if(!isBlock(tile)) break;
			tile.y = dir_tile.y - 1;
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_right_up:
		do
		{
			tile = Point(dir_tile.x-1, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y + 1);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x-2, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y+2);
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_right_down:
		do
		{
			tile = Point(dir_tile.x-1, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y - 1);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x-2, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y-2);
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_left_down:
		do
		{
			tile = Point(dir_tile.x+1, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y - 1);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x+2, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y-2);
			if(!isBlock(tile)) break;
		}while(0);
		break;
	case dir_left_up:
		do
		{
			tile = Point(dir_tile.x+1, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y + 1);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x+2, dir_tile.y);
			if(!isBlock(tile)) break;
			tile = Point(dir_tile.x, dir_tile.y+2);
			if(!isBlock(tile)) break;
		}while(0);
		break;
	default:
		break;
	}
	return tile;
}
double round(double val)
{
	return (val> 0.0) ? floor(val+ 0.5) : ceil(val- 0.5);
}
bool imagineUnlikeNeed::hasBlock(cocos2d::Point startPoint,cocos2d::Point endPoint){
	bool block = false;
	float _dx = endPoint.x - startPoint.x;
	float _dy = (endPoint.y - startPoint.y);
	float _dist = startPoint.distance(endPoint);
	cocos2d::Point _newCheckPoint = startPoint;
	float _px = _dx / _dist;
	float _py = _dy / _dist;
	float _checkLength = 0;
	while (_checkLength <= _dist)
	{
		if (isBlock(_newCheckPoint))
		{
			block = true;
			break;
		}
		_checkLength += 1;
		_newCheckPoint.x = round(startPoint.x + _checkLength * _px);
		_newCheckPoint.y = round(startPoint.y + _checkLength * _py);
	}
	return block;
}
bool imagineUnlikeNeed::fileReviewEnumeration(cocos2d::Point startPoint,cocos2d::Point endPoint){
	return hasBlock(inverselyThpositionComes(startPoint),inverselyThpositionComes(endPoint));
}
Vec2 imagineUnlikeNeed::convenientAssumeRecognize4(cocos2d::Point startPoint,cocos2d::Point endPoint){
	cocos2d::Point _newCheckPoint = startPoint;
	if(isBlock(_newCheckPoint))
		return _newCheckPoint;
	if(startPoint == endPoint)
		return _newCheckPoint;
	bool block = false;
	float _dx = endPoint.x - startPoint.x;
	float _dy = (endPoint.y - startPoint.y);
	float _dist = startPoint.distance(endPoint);
	float _px = _dx / _dist;
	float _py = _dy / _dist;
	float _checkLength = 0;
	while (_checkLength <= _dist)
	{
		if (isBlock(_newCheckPoint))
		{
			block = true;
			break;
		}
		_checkLength += 1;
		_newCheckPoint.x = round(startPoint.x + _checkLength * _px);
		_newCheckPoint.y = round(startPoint.y + _checkLength * _py);
	}
	return _newCheckPoint;
}
Vec2 imagineUnlikeNeed::followThumbSeveralIntend(cocos2d::Point startPoint,cocos2d::Point endPoint){
	Vec2 endTitle = inverselyThpositionComes(endPoint);
	if(isBlock(endTitle) == false)
		return endPoint;
	float _dx = startPoint.x - endPoint.x;
	float _dy = startPoint.y - endPoint.y;
	float _dist = endPoint.distance(startPoint);
	cocos2d::Point _newCheckPoint = endPoint;
	float _px = _dx / _dist;
	float _py = _dy / _dist;
	float _checkLength = 0;
	float gap = 20;
	bool find = false;
	while (_checkLength <= _dist)
	{
		if (!isBlock(inverselyThpositionComes(_newCheckPoint)))
		{
			find = true;
			break;
		}
		_checkLength += gap;
		_newCheckPoint.x = round(endPoint.x + _checkLength * _px);
		_newCheckPoint.y = round(endPoint.y + _checkLength * _py);
	}
	if(find == false)
		_newCheckPoint = startPoint;
	return _newCheckPoint;
}
Vec2 imagineUnlikeNeed::initializingConceptually(cocos2d::Point startTile,cocos2d::Point endTile){
	if(isBlock(endTile) == false)
		return endTile;
	float _dx = startTile.x - endTile.x;
	float _dy = startTile.y - endTile.y;
	float _dist = endTile.distance(startTile);
	cocos2d::Point _newCheckPoint = endTile;
	float _px = _dx / _dist;
	float _py = _dy / _dist;
	float _checkLength = 0;
	float gap = 1;
	bool find = false;
	while (_checkLength <= _dist)
	{
		if (!isBlock(_newCheckPoint))
		{
			find = true;
			break;
		}
		_checkLength += gap;
		_newCheckPoint.x = round(endTile.x + _checkLength * _px);
		_newCheckPoint.y = round(endTile.y + _checkLength * _py);
	}
	if(find == false)
		_newCheckPoint = startTile;
	return _newCheckPoint;
}
int imagineUnlikeNeed::fixPath(struct rightItasSuccessful *startpath){
	float speed = map_speed;
	int pathNum = 0;
	float allTime = 0;
	struct rightItasSuccessful *rootPath =  startpath;
	struct rightItasSuccessful *path =  startpath;
	if(path == nullptr) return 0;
	struct rightItasSuccessful *path1 =  path->Next;
	if(path1==nullptr) return 0;
	int i = 0,j = 0;
	accessedIntroductory old_dir,new_dir;
	old_dir =  getdebuggingRespective(Point(path1->X,path1->Y)-Point(path->X,path->Y));
	while(path->Next!=nullptr)
	{
		path = path->Next;
		path1 = path->Next;
		if(path1 != nullptr)
		{
			new_dir = getdebuggingRespective(Point(path1->X,path1->Y)-Point(path->X,path->Y));
			if(new_dir != old_dir)
			{   
			
				old_dir = new_dir;
				j++;
			}
		}
	}
	if(j == 0){
	
		rootPath->Next = path;
		pathNum++;
	
	}else{
		struct rightItasSuccessful * pathStart = startpath;
		struct rightItasSuccessful * pathStart2 = nullptr;
		struct rightItasSuccessful * pathEnd = nullptr;
		path =  startpath;
		path1 =  path->Next;
		while(path->Next!=nullptr)
		{
			i++;
			path = path->Next;
			path1 = path->Next;
			if(path1 != nullptr)
			{
				new_dir = getdebuggingRespective(Point(path1->X,path1->Y)-Point(path->X,path->Y));
				if(new_dir != old_dir)
				{   
					if(pathStart2 != nullptr){
					
					
					
						if(hasBlock(cocos2d::Point(pathStart->X,pathStart->Y),cocos2d::Point(path->X,path->Y))){
		
						
							rootPath->Next = pathEnd;
							rootPath = pathEnd;
							pathStart = pathStart2;
							pathNum++;
						}
					}
					pathEnd = path;
					pathStart2 = path;
					old_dir = new_dir;
					i = 0; 
				}
				if(getwcouldCoverConstructors(Vec2(path->X,path->Y)) == 3){
				
				
					rootPath->Next = path;
					rootPath = path;
					pathStart = path;
					pathStart2 = nullptr;
					pathEnd = nullptr;
					pathNum++;
				}
			}
		}
		if(pathStart2 != nullptr){
		
		
		
			if(hasBlock(cocos2d::Point(pathStart->X,pathStart->Y),cocos2d::Point(path->X,path->Y))){
			
			
			
			
			
			
			
				rootPath->Next = pathEnd;
				rootPath = pathEnd;
				pathStart = pathStart2;
				pathNum++;
			}
		}
	
	
	
	
	
	
		rootPath->Next = path;
		pathNum++;
	}
	return pathNum;
}
void imagineUnlikeNeed::striparameterImportance(struct rightItasSuccessful *startpath,labelsPointRepresentation* sendItem, bool sendMsg )
{
	if(sendItem == nullptr){
		sendItem = role_main;
	}
	if(sendItem == nullptr)
		return;
	float allMoveTime = 0;		
	bool isMe = false;
	std::string actorId = sendItem->getrankedClauseHowevewe();
	if(role_main){
		if(actorId == role_main->getrankedClauseHowevewe())
			isMe = true;
	}
	if(startpath == nullptr) 
	{ 
		if(isMe)
		{
			if(m_walk_cb)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->executeFunctionByHandler(m_walk_cb, 0);
					pStack->clean();
				}
			}		
		}
		return;
	}
	int pathNum = fixPath(startpath);						
	struct rightItasSuccessful *path =  startpath;
	if(path && path->Next != nullptr){
	
		senseGrades *luaEventMgr = senseGrades::instance();
		yieldsAnswerAlways buffer = luaEventMgr->getoccursInteractsReturning(C2S_MOVE);
		buffer.pushInt(pathNum + 1);
		buffer.pushInt(startpath->X);
		buffer.pushInt(startpath->Y);
		while (path->Next != nullptr)
		{
			sendItem->greaterFunctiwith(Vec2(path->Next->X,path->Next->Y),false);
			buffer.pushInt(path->Next->X);
			buffer.pushInt(path->Next->Y);
			path = path->Next;
		}
		if (sendMsg)
		{
			andqueryApplies::getInstance()->updateSelectsButton(buffer);
		}
		if(isMe)
		{
			if(AStarPath &&  AStarPath->Next)
				AStarPath = AStarPath->Next;
			if(pathNum == 1)
			{
				Vec2 role_move_pc_start = sendItem->getPosition();
				Vec2 role_move_pc_end = applicableInstances(Vec2(path->X,path->Y));
				if(assumeApproachEmbodies::givesPushCacall(role_move_pc_start,role_move_pc_end) && 
					abs(role_move_pc_start.x - role_move_pc_end.x) > assumeApproachEmbodies::differenceAdvantages * 2 &&
					abs(role_move_pc_start.y - role_move_pc_end.y) > assumeApproachEmbodies::differenceAdvantages * 2)
				{
					sendItem->setharderReferencesthLooking(true);
				}
			}
		}
	}
	else if(path && path->Next == nullptr)
	{
		sendItem->greaterFunctiwith(Vec2(path->X,path->Y),false);
		if(isMe)
			sendItem->setharderReferencesthLooking(true);
	
	
	}
}
void imagineUnlikeNeed::unnamedAttemptsPurposes(accessedIntroductory dir,int step,Vec2 targetPos,float moveTime)
{
	if(role_main == nullptr)
		return;
	if (step == 1)
	{
		senseGrades *luaEventMgr = senseGrades::instance();
		yieldsAnswerAlways buffer = luaEventMgr->getoccursInteractsReturning(C2S_MOVE);
		buffer.pushInt(2);
		buffer.pushInt(m_heightIndicesSimplify.x);
		buffer.pushInt(m_heightIndicesSimplify.y);
		buffer.pushInt(targetPos.x);
		buffer.pushInt(targetPos.y);
		andqueryApplies::getInstance()->updateSelectsButton(buffer);
	}
	else if (step == 0 && role_main->getspecializedComplication() != ACTION_STATE_IDLE) 
	{
		senseGrades *luaEventMgr = senseGrades::instance();
		theyKindsFundamental();
		Vec2 pos;
		pos.x = m_heightIndicesSimplify.x;
		pos.y = m_heightIndicesSimplify.y;
		yieldsAnswerAlways buffer = luaEventMgr->getoccursInteractsReturning(C2S_STOP_MOVING);
		buffer.pushInt(pos.x);
		buffer.pushInt(pos.y);
		andqueryApplies::getInstance()->updateSelectsButton(buffer);
	}
}
void imagineUnlikeNeed::thatVersusPrevented(labelsPointRepresentation* item,Vec2 pos,bool cAstar){
	return;
	if(item->getcontrolsPredicted() == false)
		return;
	bool isMe = false;
	std::string actorId = item->getrankedClauseHowevewe();
	if(role_main){
		if(actorId == role_main->getrankedClauseHowevewe())
			isMe = true;
	}
	if(pos == Vec2::ZERO){
		if(isMe){
			theyKindsFundamental();
			pos.x = m_heightIndicesSimplify.x;
			pos.y = m_heightIndicesSimplify.y;
			if(cAstar && AStarPath && AStarPath->Next)
				AStarPath = AStarPath->Next;
		}else{
			auto tmp_tile = inverselyThpositionComes(item->getPosition());
			pos.x = tmp_tile.x;
			pos.y = tmp_tile.y;
		}
	}
	senseGrades *luaEventMgr = senseGrades::instance();
	yieldsAnswerAlways buffer = luaEventMgr->getoccursInteractsReturning(C2S_SYNC_POS);
	buffer.pushInt(pos.x);
	buffer.pushInt(pos.y);
	andqueryApplies::getInstance()->updateSelectsButton(buffer);
}
void imagineUnlikeNeed::relativePersistDecrement1(accessedIntroductory dir,float distance,cocos2d::Vec2 direction)
{
	if(loop_flag == 2&&role_main!=nullptr&&role_main->getspecializedComplication() <= ACTION_STATE_CHENMO)
	{
	
		m_isrock = true;
		m_letsIstream = direction;
		if(role_main->getspecializedComplication() != ACTION_STATE_FLY && role_main->getspecializedComplication() != ACTION_STATE_SUDDEN){
			if(employeeCreatingProgram != dir){
				m_takingMeddleTimes = 0;
				employeeCreatingProgram = dir;
				_m_time = 10000;
				if(m_rock_cb)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != nullptr)
					{
						pStack->pushInt(2);
						pStack->executeFunctionByHandler(m_rock_cb, 1);
						pStack->clean();
					}
				}
			}
		}else{
		
			if(role_main)
				role_main->setassignBehindSees(m_letsIstream);
		}
	}
}
void imagineUnlikeNeed::FlyRocket(int actionId,int fly_mode,cocos2d::Vec2 newPos,float actionTime,int speed){
	if(role_main == nullptr)
		return;
	if(actionId == 1){
	
		if(fly_mode == 1)
			insideArgumepassedAngle();
		unwindingAverage(newPos,actionTime);
	}else{
	
		theyKindsFundamental();
		thatVersusPrevented(role_main,m_heightIndicesSimplify);
		incompleteElementsStorage(true);
	
		if(becomeThemselvesMaking(2,m_heightIndicesSimplify))
			return;
		else
			constraintsModernCentral();
	}
	if(m_fly_cb && m_fly_cb != 0)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			Vec2 newTile = inverselyThpositionComes(newPos);
			pStack->pushInt(actionId);
			pStack->pushInt(int(newTile.x));							
			pStack->pushInt(int(newTile.y));							
			pStack->pushFloat(actionTime);						
			pStack->pushInt(int(newPos.x));						
			pStack->pushInt(int(newPos.y));						
			pStack->pushInt(speed);						
			pStack->executeFunctionByHandler(m_fly_cb, 7);
			pStack->clean();
		}
	}
}
void imagineUnlikeNeed::supplySerialMembers() 
{
	if(loop_flag == 2 && role_main->getspecializedComplication())
	{
	
		if(role_main)
			role_main->setassignBehindSees(Vec2::ZERO);
		theyKindsFundamental();
		unnamedAttemptsPurposes(employeeCreatingProgram,0,Vec2::ZERO,0);
		m_takingMeddleTimes = 0;
		employeeCreatingProgram = dir_undef;
		if(m_rock_cb)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(5);
				pStack->executeFunctionByHandler(m_rock_cb, 1);
				pStack->clean();
			}
		}
	}
}
void imagineUnlikeNeed::worksBraceRefers(double speed)
{
	if(role_main!=nullptr)
		role_main->setSpeed(speed);
	map_speed = speed;
}
double imagineUnlikeNeed::getSpeed(){
	return map_speed;
}
Point imagineUnlikeNeed::getspecifiesSetsSpecialized(Point pos_dest,int sub) 
{
	Point tile_start = m_heightIndicesSimplify;
	Point tile_dest = inverselyThpositionComes(pos_dest);
	Point sub_tile = tile_dest - tile_start;
	Point r_pos = Point();
	float angle = sub_tile.getAngle();
	float tanAngel = tan(angle);
	accessedIntroductory dir = dir_up;
	if(tanAngel < tan(PI/8))
	{
		if(sub_tile.x < 0)
			dir = dir_left;
		else
			dir = dir_right;
	}
	else if(tanAngel > tan(PI*3/8))
	{
		if(sub_tile.y > 0)
			dir = dir_up;
		else
			dir = dir_down;
	}
	else
	{
		if(sub_tile.x < 0 && sub_tile.y < 0)
			dir = dir_left_down;
		else if(sub_tile.x < 0 && sub_tile.y > 0)
			dir = dir_left_up;
		else if(sub_tile.x > 0 && sub_tile.y > 0)
			dir = dir_right_up;
		else
			dir = dir_right_down;
	}
	r_pos = tile_dest - getshorttypOrdinaryOught(dir)*sub;
	return r_pos;
}
void imagineUnlikeNeed::inverselyStoredSection(Point pos) 
{
}
accessedIntroductory imagineUnlikeNeed::getdebuggingRespective(Point tile) 
{
	if(abs(tile.x) <= 1 && abs(tile.y) <= 1){
		if (tile.x > 0)
			tile.x =1;
		else if (tile.x < 0 )
			tile.x = -1;
		if (tile.y > 0)
			tile.y =1;
		else if (tile.y < 0 )
			tile.y = -1;
		if(tile == Point(0,-1))
			return dir_up;
		else if(tile == Point(0,1))
			return dir_down;
		else if(tile == Point(-1,0))
			return dir_left;
		else if(tile == Point(1,0))
			return dir_right;
		else if(tile == Point(1,-1))
			return dir_right_up;
		else if(tile == Point(1,1))
			return dir_right_down;
		else if(tile == Point(-1,-1))
			return dir_left_up;
		else if(tile == Point(-1,1))
			return dir_left_down;
		return dir_right_up;
	}else{
		tile.x = tile.x * m_perTileSize.width;
		tile.y = -tile.y * m_perTileSize.height;
		return getfocusDefaultsCurlies(tile);
	}
}
accessedIntroductory imagineUnlikeNeed::getfocusDefaultsCurlies(Point direction) 
{
	accessedIntroductory dir = dir_right_up;
	int angle = static_cast<int>( CC_RADIANS_TO_DEGREES(atan2(direction.y, direction.x)) );
	if (angle < 0)
	{
		angle = 360 + angle;
	}
	if (angle >= 0 && angle < 90)
	{
		dir = dir_right_up;
	}
	else if (angle >= 90 && angle < 180)
	{
		dir = dir_left_up;
	}
	else if (angle >= 180 && angle < 270)
	{
		dir = dir_left_down;
	}
	else
	{
		dir = dir_right_down;
	}
	return dir;
}
 Point imagineUnlikeNeed::getshorttypOrdinaryOught(accessedIntroductory dir) 
{
	switch (dir)
	{
	case dir_up:
		return  Point(0,-1);
	case dir_down:
		return  Point(0,1);
	case dir_left:
		return  Point(-1,0);
	case dir_right:
		return  Point(1,0);
	case dir_left_up:
		return  Point(-1,-1);
	case dir_right_up:
		return  Point(1,-1);
	case dir_left_down:
		return  Point(-1,1);
	case dir_right_down:
		return  Point(1,1);
	default:
		return  Point(0,-1);
	}
}
void imagineUnlikeNeed::employeeResulting(int handler){
	m_fly_cb = handler;
}
void imagineUnlikeNeed::existLettersPermitted1(int handler)
{
	m_walk_cb = handler;
}
void imagineUnlikeNeed::ostreamSupportsUser()
{
	m_walk_cb = 0;
}
void imagineUnlikeNeed::accessibleFunctionGoes(int handler)
{
	m_rock_cb = handler;
}
void imagineUnlikeNeed::appropriateAreaDetermine()
{
	m_rock_cb = 0;
}
void imagineUnlikeNeed::headActuallySchema4(int handler)
{
	m_cabePointers = handler;
}
void imagineUnlikeNeed::unorderedOverloaded()
{
	m_cabePointers = 0;
}
void imagineUnlikeNeed::undefinedparameters(int handler)
{
	m_formOrganizeEquality = handler;
}
void imagineUnlikeNeed::guaranteedFallThdefines()
{
	m_formOrganizeEquality = 0;
}
void imagineUnlikeNeed::conventionFollowUnscoped(int handler)
{
	m_noteDigits = handler;
}
 
Size imagineUnlikeNeed::getLayerSize(){
	return m_mapSize;
}
Size imagineUnlikeNeed::getMapTileSize(){
	return m_perTileSize;
}
void imagineUnlikeNeed::examinesStatementResults(int type, Node* node, int objId, int z)
{
	if (node && m_differContainTemporaries)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			pStack->pushInt(type);
			pStack->pushObject(node, "Node");
			pStack->pushInt(objId);
			pStack->pushInt(z);
			pStack->executeFunctionByHandler(m_differContainTemporaries, 4);
			pStack->clean();
		}
	}
}
void imagineUnlikeNeed::readingAgreeGeneral(int handler)
{
	m_differContainTemporaries = handler;
}
void imagineUnlikeNeed::whappearsCastCannotBookno()
{
	m_differContainTemporaries = 0;
}
void imagineUnlikeNeed::theyKindsFundamental(){
	if(role_main)
		m_heightIndicesSimplify = inverselyThpositionComes(role_main->getPosition());
}
void imagineUnlikeNeed::basicsDrivenRandom2(int handler){
	m_realizingProblemsWorry = handler;
}
bool imagineUnlikeNeed::chparameterSpecification(float distance,float minDistance,Vec2 targetPos){
	constitutesSupplies = 0;
	m_stopsSupposeparateGroup = 0;
	normalExpandedIncluding = targetPos;
	m_smatchWere = m_compilationBoth;
	return false;
}
void imagineUnlikeNeed::builtAskingInstances(){
	constitutesSupplies = 0;
	m_stopsSupposeparateGroup = 0;
	normalExpandedIncluding = Vec2::ZERO;
}
bool imagineUnlikeNeed::pointerBitsetheCompilers(){
	if(role_main == nullptr)
		return false;
	if(role_main->getgaveObjectsthBasic()==1 || role_main->getgaveObjectsthBasic()==3)
		return false;
	if(role_main->getspecializedComplication() == ACTION_STATE_FLY || role_main->getspecializedComplication() == ACTION_STATE_SUDDEN)
		return false;
	if(constitutesSupplies > 0 && normalExpandedIncluding != Vec2::ZERO){
		if(m_smatchWere < m_compilationBoth)
			m_smatchWere++;
		else{
			m_smatchWere = 0;
		
			Vec2 targetPos = applicableInstances(normalExpandedIncluding);
			float distance = targetPos.distance(role_main->getPosition());
			if(distance >= m_stopsSupposeparateGroup && distance<=constitutesSupplies){
			
			
			
				controlSpelling(false,false,false);
				builtAskingInstances();
				role_main->discussioofListsHaveWhyou(1,targetPos);
				return true;
			}
		}
	}
	return false;
}
bool imagineUnlikeNeed::alwaysAvoidClassesclick(int actionId,Vec2 newPos,float actionTime,int speed){
	if(actionId == 1){
	
		unwindingAverage(newPos,actionTime);
	
		if(m_realizingProblemsWorry && m_realizingProblemsWorry != 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				Vec2 newTile = inverselyThpositionComes(newPos);
				pStack->pushInt(actionId);
				pStack->pushInt(int(newTile.x));							
				pStack->pushInt(int(newTile.y));							
				pStack->pushFloat(actionTime);						
				pStack->pushInt(int(newPos.x));						
				pStack->pushInt(int(newPos.y));						
				pStack->pushInt(speed);						
				pStack->executeFunctionByHandler(m_realizingProblemsWorry, 7);
				pStack->clean();
			}
		}
		return true;
	}
	else if(actionId == 2){
	
		thatVersusPrevented(role_main);
		if(m_walk_cb > 0){
		
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->executeFunctionByHandler(m_walk_cb, 0);
				pStack->clean();
			}
			return true;
		}
	}
	return false;
}
void imagineUnlikeNeed::setorientedLargerEnds(Node* node)
{
	if (node)
	{
		Node* followNode = dynamic_cast<Node*>(node);
		if (followNode)
		{
			m_completesRather = followNode;
		}
	}
	else
	{
		m_completesRather = nullptr;
	}
}
void imagineUnlikeNeed::updatePos()
{
	if (!role_main && !m_completesRather)
	{
		CPLUSLog("not role_main and follow node");
		return;
	}
	Point point = Point::ZERO;
	if (dynamic_cast<Node*>(m_completesRather))
	{
		point = m_completesRather->getPosition();
	}
	else
	{
		point = role_main->getPosition();
	}
	point = encapsulationSolveSketch(point);
	setPosition(point);
}
void imagineUnlikeNeed::separatelyFoundAllocated(float delaTime)
{
	if (!codeBinds)
	{
		return;
	}
	if(settingIntendThere == Vec2::ZERO)
		return;
	float speed = delaTime * map_speed;
	Vec2 moveDistance = m_enforcesKids * speed;
	Vec2 movePos = getPosition();
	movePos.add(moveDistance);
	bestViolate(movePos);
	setPosition(movePos);
	if (programRules::machinesOkay)
	{
		programRules::machinesOkay->doubleprecRuleUnnecessary(movePos);
	}
	if(takeIsbnVersion > 0)
	{
		delaTime += takeIsbnVersion;
		takeIsbnVersion = 0;
	}
	_overTime+=delaTime;
	if(_overTime >= notingTchangeLegitimate)
	{
	
	
	
	
		settingIntendThere = Vec2::ZERO;
	}
}
void imagineUnlikeNeed::greaterFunctiwith(Vec2 pos)
{
	if (!codeBinds)
	{
		return;
	}
	if(role_main == nullptr){
		cleanMove();
		return;
	}
	Vec2 role_move_pc_start = getPosition();
	Vec2 role_start = inverselyThpositionComes(role_main->getPosition());
	Vec2 pos_ = applicableInstances(pos);
	Vec2 role_move_pc = encapsulationSolveSketch(pos_);
	settingIntendThere = Vec2(1,1);
	m_enforcesKids = (role_move_pc - role_move_pc_start).getNormalized();
	notingTchangeLegitimate = role_move_pc_start.distance(role_move_pc)/map_speed;
	_overTime = 0;
}
void imagineUnlikeNeed::cleanMove()
{
	if (!codeBinds)
	{
		return;
	}
	settingIntendThere = Vec2::ZERO;
	notingTchangeLegitimate = 0;
	_overTime = 0;
	takeIsbnVersion = 0;
}
void imagineUnlikeNeed::leastInspiredThing()
{
	if (!codeBinds)
	{
		return;
	}
	stopActionByTag(ACTION_MOVE_TAG);
	cleanMove();
}
bool imagineUnlikeNeed::staticsBinding(void * dimension)
{
	unsigned short system;
	system = 703;
	return true;
}
char imagineUnlikeNeed::problemsVariadic(long begins,bool forestall)
{
	char compute;
	compute = 'D';
	return 'Z';
}
double imagineUnlikeNeed::includingPreferPossibly(bool review,void * nonexistent,long screen)
{
	bool down;
	down = true;
	char abstractly;
	abstractly = '9';
	float contrpasses;
	contrpasses = 29.19f;
	float protection;
	protection = 549.6f;
	char affects;
	affects = 't';
	return 44.3;
}
char imagineUnlikeNeed::controlsHappens(unsigned short exonly,short redeclare,double scope,double precedes)
{
	void * convert;
	convert = nullptr;
	return 'W';
}
int imagineUnlikeNeed::topicTypesPointConverted(long isbn,char throughout,double specialized)
{
	void * normally;
	normally = nullptr;
	return 206;
}
long imagineUnlikeNeed::transfersPrevented(long fail,float intending,char convenient,long these)
{
	short hence;
	hence = 247;
	return 69;
}
int imagineUnlikeNeed::abstractionArgumentProper(bool omit,bool parametis,unsigned short system,int target)
{
	char extended;
	extended = '8';
	long complex;
	complex = 985;
	int operatorclick;
	operatorclick = 589;
	void * coverage;
	coverage = nullptr;
	return 332;
}
long imagineUnlikeNeed::enclosedNeither(char expressions,int inaccessible)
{
	long program;
	program = 928;
	short possibly;
	possibly = 273;
	short zero;
	zero = 14;
	long prints;
	prints = 312;
	return 972;
}
unsigned short imagineUnlikeNeed::preventingDescription(bool puts,float stored,long head,void * text)
{
	unsigned short characters;
	characters = 15;
	int gives;
	gives = 947;
	void * function;
	function = nullptr;
	return 712;
}
double imagineUnlikeNeed::patternsDifferingSupplied(double convertible)
{
	short programs;
	programs = 57;
	unsigned short implicit;
	implicit = 377;
	void * scope;
	scope = nullptr;
	bool compatible;
	compatible = true;
	return 286.9;
}
double imagineUnlikeNeed::suppressFamiliar(bool bound)
{
	int throws;
	throws = 986;
	bool others;
	others = false;
	bool pointsunlike;
	pointsunlike = false;
	long effect;
	effect = 838;
	double separately;
	separately = 785.11;
	return 872.11;
}
float imagineUnlikeNeed::successfulHasptrMinimal(long correctness)
{
	unsigned short moves;
	moves = 508;
	return 922.0f;
}
