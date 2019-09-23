
#include "FindPath.h"
#include "startsEvaluating.h"
#include "copiedFlipsActual.h"
#include "correspondingFunctional.h"
#include "CCintroducedBookstore.h"
#include "math/MathUtil.h"
#include "isbnsProgramsHair.h"
#include "implementContainingMeans.h"
#include "intendedForwardingMust.h"
#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#pragma comment(lib,"Psapi.lib")
	#include "Psapi.h"
#endif
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "sectionsBlockIntended.h"
USING_NS_CC;
static	struct componentsOperateFeature *overloadReuseAlegal = nullptr;
static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
static std::string mapstr;
float illustrateDiscussion::m_freeCover = 0.8f;
illustrateDiscussion* illustrateDiscussion::resolvesRelying = nullptr;
void illustrateDiscussion::worksTheareAuthor(std::string mapStr, int posX, int posY,int spanX, int spanY)
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
void illustrateDiscussion::setenumeratorsContaiany(float _scale)
{ 
	m_freeCover = _scale; 
}
illustrateDiscussion::illustrateDiscussion()  
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
	systemsData = dir_undef;
	m_wantedEvaluated = cocos2d::Vec2::ZERO;
	m_correspondBlobptr = Vec2::ZERO;
	role_main = nullptr;
	loop_flag = 0;
	debugdeleteStarting = 0;
	m_coveredSpecial = 2;
	m_walk_cb = 0;
	m_rock_cb = 0;
	m_fly_cb = 0;									
	m_overloadEffectively = 0;								
	problemsSequential = 0;
	m_performHead = 0;
	workReadyBeen = false;
	numbersWords = 10;
	m_identifiesRunsComplexity = 10;
	_m_time = 0;
	m_argumentIncreased = 0;
	m_preprocessorIgnore = 0;
	m_compiledCreate = 0;
	leavingDealingShows = 0;
	m_sequentialDirections = Vec2::ZERO;
	m_behaviorOverallOperators = 5;
	temporaryDistinguish = m_behaviorOverallOperators;
	m_mapId = 0;
	natureConverting = SPEED;
	m_dir = dir_undef;
	load_Thread = nullptr;
	load_Thread1 = nullptr;
	load_Thread2 = nullptr;
	load_Thread3 = nullptr;
	loadall = false;
	m_isNoRes = false;
	m_constituteEspecially = true;
	m_isFb = false;
	m_referLiteralTreats = true;
	m_benefitDestroying = false;
	aspectsManipulate = false;
	elsewhereSchema = false;
	needsThgenerates = 1;
	pdataDoeth = Vec2::ZERO;
	_infoMutex.lock();
	if(overloadReuseAlegal != nullptr)
	{
		delete(overloadReuseAlegal);
		overloadReuseAlegal = nullptr;
	}
	mapstr.clear();
	_infoMutex.unlock();
	debuggingToolsLegal = 0;
	m_guaranteeDealingBlob = true;
	m_perTileSize = Size::ZERO;
	m_mapSize = Size::ZERO;
	m_winSize = Size::ZERO;
	m_writtenPassed = Vec2::ZERO;
	_overTime = 0;
	m_applySimilar = 0;
	m_understandListsSystem = 0;
	m_informSeparatorSuccessful = "jpg";
	m_variadicMuensureArrays = nullptr;
	m_prvoidAssociativeLiteral.clear();
	coverContainerGrades = false;
}
illustrateDiscussion::~illustrateDiscussion()
{
	m_referLiteralTreats = false;
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
	while (overloadReuseAlegal != nullptr)
	{
		struct componentsOperateFeature* pNode = overloadReuseAlegal;
		overloadReuseAlegal = overloadReuseAlegal->Next;
		delete(pNode);
	}
	mapstr.clear();
	m_prvoidAssociativeLiteral.clear();
	_infoMutex.unlock();
	differentlyPattern();
	resolvesRelying = nullptr;
}
void illustrateDiscussion::cleanup(){
	Layer::cleanup();
	differentlyPattern();
	resolvesRelying = nullptr;
}
void illustrateDiscussion::differentlyPattern(){
	if(areaConventionsGiven.size() > 0){
		for(std::unordered_map<int,std::string>::iterator iter = areaConventionsGiven.begin();iter != areaConventionsGiven.end();iter++){
			bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(iter->second,iter->first);
			CCASSERT(isFind == true, "illustrateDiscussion m_asyncinstantiationTableTuple remove Fail");
		}
	}
	areaConventionsGiven.clear();
}
illustrateDiscussion *illustrateDiscussion::create(const std::string& filename, const int mapId, const bool isMultiMap, const Point pos)
{
	illustrateDiscussion *pRet = new illustrateDiscussion();
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
illustrateDiscussion *illustrateDiscussion::create()
{
	illustrateDiscussion *pRet = new illustrateDiscussion();
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
bool illustrateDiscussion::getparametisOrdinaryPrefi(int x,int y,int x1,int y1)
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
			
				status = x1<=screen_width&&(y1 + m_identifiesRunsComplexity)>(m_mapSize.height-screen_height);
			else
			
				status = x1<=screen_width&&abs(y1+m_identifiesRunsComplexity/2-y)<=(screen_height_half + m_identifiesRunsComplexity/2);
		}
		else if(x>(m_mapSize.width-screen_width_half))
		{
		
			if(y<screen_height_half)
			
				status = (x1 + numbersWords)>=(m_mapSize.width-screen_width)&&y1<=screen_height;
			else if(y>(m_mapSize.height-screen_height_half))
			
				status = (x1 + numbersWords)>=(m_mapSize.width-screen_width)&&(y1 + m_identifiesRunsComplexity)>(m_mapSize.height-screen_height);
			else
			
				status = (x1 + numbersWords)>=(m_mapSize.width-screen_width)&& abs(y1+m_identifiesRunsComplexity/2-y)<=(screen_height_half + m_identifiesRunsComplexity/2);
		}
		else if(abs(x1+numbersWords/2-x)<=(screen_width_half + numbersWords/2))
		{
		
			if(y<screen_height_half)
			
				status = y1<=screen_height;
			else 
			
				status = (y1 + m_identifiesRunsComplexity)>(m_mapSize.height-screen_height);
		}
	}
	else if(abs(x1+numbersWords/2-x)<=(screen_width_half + numbersWords/2)&&abs(y1+m_identifiesRunsComplexity/2-y)<=(screen_height_half + m_identifiesRunsComplexity/2))
	{
	
		status = true;
	}
	return status;
}
void illustrateDiscussion::reallocatesOpenLonger1(int mapId,bool remove){
	bool find = false;
	vector<int>::iterator it = m_containedOperation.begin();
	for(;it != m_containedOperation.end();it++){
		if(*it == mapId){
			find = true;
			break;
		}
	}
	if(remove == false){
	
		if(find == false){
			m_containedOperation.push_back(mapId);
		}
	}
	else{
	
		if(find == true){
			m_containedOperation.erase(it);
		}
	}
}
bool illustrateDiscussion::furtherArticles(int mapId){
	bool find = false;
	vector<int>::iterator it = m_containedOperation.begin();
	for(;it != m_containedOperation.end();it++){
		if(*it == mapId){
			find = true;
			workReadyBeen = true;
			break;
		}
	}
	return find;
}
void illustrateDiscussion::setallowRepresentingComplex(int span_x,int span_y){
	if(span_x <= 0 || span_y <= 0)
		return;
	numbersWords = span_x;
	m_identifiesRunsComplexity = span_y;
}
void illustrateDiscussion::outputApproachVector(std::vector<componentsOperateFeature*> list)
{
	_infoMutex.lock();
	if (!m_isNoRes){
		for(std::vector<componentsOperateFeature*>::iterator iter = list.begin();iter != list.end();iter++){
			componentsOperateFeature* Dmap = *iter;
			char imgstr[128];
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/numbersWords,Dmap->y/m_identifiesRunsComplexity, m_informSeparatorSuccessful.c_str());
			if(Dmap->Status&&Dmap->sp == nullptr&&(!Dmap->loaded)&&mapstr.size()>0){
				if(m_constituteEspecially == true){
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(illustrateDiscussion::letsEncloseDoing,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(illustrateDiscussion::placedEquivalent,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						areaConventionsGiven.insert(std::pair<int,std::string>(entryId,imgstr));
				}else if(m_guaranteeDealingBlob){
				
					if(addedConstituentPrograms(imgstr) == false){
						isbnsProgramsHair *sprite = isbnsProgramsHair::create(imgstr,"res/syncReplace/map_cell.jpg");
						if(sprite)
						{
							sprite->setAnchorPoint(Point(0,1));
							sprite->setPosition(Point(Dmap->x*m_perTileSize.width,(m_mapSize.height-Dmap->y)* m_perTileSize.height));
							m_pMap->addChild(sprite,0,Dmap->tag);
							Dmap->sp = sprite;
						}
					}else{
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(illustrateDiscussion::letsEncloseDoing,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(illustrateDiscussion::placedEquivalent,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							areaConventionsGiven.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
		}
	}
	_infoMutex.unlock();
}
void illustrateDiscussion::setoverloadReuseAlegal(int x,int y,bool updateShow)
{
	if (m_isNoRes)
		return;
	bool need_load = false;
	_infoMutex.lock();
	struct componentsOperateFeature *Dmap = overloadReuseAlegal;
	std::vector<componentsOperateFeature*> needLoadDmap;
	while(Dmap!=nullptr)
	{
		if(workReadyBeen){
		
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
		
			Dmap->Status = getparametisOrdinaryPrefi(x,y,Dmap->x,Dmap->y);
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
		outputApproachVector(needLoadDmap);
	
	
	}
}
bool illustrateDiscussion::functionalthoughSerial(int AstarNum){
	loadall = true;
	if (m_benefitDestroying)
		resolvesRelying = this;
	if (AstarNum == 0)
		return m_benefitDestroying;
	if (AstarNum == 1)
		return aspectsManipulate;
	if (AstarNum == 2)
		return elsewhereSchema;
	return m_benefitDestroying;
}
void illustrateDiscussion::setScale(float scale)
{
	Node::setScale(scale);
}
bool illustrateDiscussion::loadMap(const std::string& tmxFile,const std::string& resFile,const  int mapId, const bool isMultiMap, const Point mpos)
{
	if(tmxFile.length() <= 0 )
		return true;
	m_mapId = mapId;
	m_pMap = TMXTiledMap::create(tmxFile);
	templatesThumbPrevious(tmxFile);
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
	
		furtherArticles(mapId);
		Ref* pObject = nullptr;  
		auto& children = m_pMap->getChildren();
		SpriteBatchNode* child = nullptr;
		for(const auto &node : children) {
			child = static_cast<SpriteBatchNode*>(node);
			child->getTexture()->setAntiAliasTexParameters();
		}
		m_compilersCompilationJust = mpos;
		addChild(m_pMap);
		auto pot = resFile.find_last_of('.');
		_infoMutex.lock();
		mapstr = resFile;
		mapstr.replace(pot,4,"/");
		_infoMutex.unlock();
		load_Thread2 = new std::thread(&illustrateDiscussion::newAstar,this);
		load_Thread2->detach();
		load_Thread3 = new std::thread(&illustrateDiscussion::newAstar2,this);
		load_Thread3->detach(); 
		loop_flag = 2;
		float scale = illustrateDiscussion::m_freeCover;
		setScale(scale);
		Point space = CC_POINT_PIXELS_TO_POINTS(saysPlaceAggregate(role_pos));
		Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
		Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
		if (pos.x > 0.0f) pos.x = 0.0f;
		if (pos.y > 0.0f) pos.y = 0.0f;
		if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
		if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
		setPosition(pos);
		if (sectionsBlockIntended::m_coversReplacementPrior)
		{
			sectionsBlockIntended::m_coversReplacementPrior->loadBack(resFile, mapId);
			sectionsBlockIntended::m_coversReplacementPrior->createTransPrefix(pos);
		}
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto myListener = EventListenerTouchOneByOne::create();
	
		myListener->setSwallowTouches(true);
		myListener->onTouchBegan = [=](Touch* touch,Event* event)
		{
			if(systemsData < dir_undef)
				return false;
			return true;  
		};
		myListener->onTouchMoved = [=](Touch* touch,Event* event)
		{
		};
		myListener->onTouchEnded = [=](Touch* touch,Event* event)
		{
			if(m_argumentIncreased < SPEED)
				return;
			Point start = touch->getStartLocation();
			Point dest = touch->getLocation();
			Point span = dest - start;
			Point tile = designedWorrySubscript(dest);
			Point tile_orign = tile;
		
			if (role_main != nullptr && !role_main->getActive())
			{
				if (m_sizeNoneRecord > 0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != nullptr)
					{
						pStack->pushInt(1);
						pStack->executeFunctionByHandler(m_sizeNoneRecord, 1);
						pStack->clean();
					}
				}
			}
			else if(dest.getDistance(start) < 30 && role_main!=nullptr&&role_main->getActive()&&role_main->isAlive() && role_main->getappeaanywhereScopedBasic() != ACTION_STATE_FLY && role_main->getappeaanywhereScopedBasic() != ACTION_STATE_SUDDEN)
			{
				if(isBlock(tile)){
				
					tile = recognizingReallocates(m_compilersCompilationJust,tile);
					if(isBlock(tile) || tile == Vec2::ZERO)
						return;
				}
			
				m_argumentIncreased = 0;
			
				#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
					printf("memory %d\r\n",getCurrMemory());
 
				#endif
				allocateCalculated(saysPlaceAggregate(tile_orign));
				if(systemsData >= dir_undef)
				{
					returnsSaveIntroduce(tile);
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
			else if(abs(span.x)<80&&abs(span.y)>50&&problemsSequential)  
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->pushBoolean(span.y > 0);
					pStack->executeFunctionByHandler(problemsSequential, 1);
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
void illustrateDiscussion::templatesThumbPrevious(const std::string tmxFile)
{
	auto pot = tmxFile.find_last_of("/");
	auto tmpTmx = tmxFile.substr(0, pot + 1);
	auto tmpTmx1 = tmxFile.substr(pot + 1);
	tmpTmx.append("block/");
	tmpTmx.append(tmpTmx1);
	m_prvoidAssociativeLiteral = FileUtils::getInstance()->getStringFromFile(tmpTmx);
	if (m_prvoidAssociativeLiteral.empty())
		return;
	auto first = m_prvoidAssociativeLiteral.find_first_of("\n");
	auto last = m_prvoidAssociativeLiteral.find_last_of("\n");
	m_prvoidAssociativeLiteral = m_prvoidAssociativeLiteral.substr(last + 1);
}
void illustrateDiscussion::areaOnceAccumulate4()
{
		TMXLayer* bg_layer = m_pMap->getLayer("bgLayer");
	
		if(bg_layer == nullptr&&overloadReuseAlegal==nullptr)
		{
			_infoMutex.lock();
			struct componentsOperateFeature *t_Map;
			for(int i=0;i<m_mapSize.width;i=i+numbersWords)
			{
				for(int j=0;j<m_mapSize.height;j=j+m_identifiesRunsComplexity)
				{
					struct componentsOperateFeature *D_Map;
					D_Map = (struct componentsOperateFeature *)malloc(sizeof(struct componentsOperateFeature));
					D_Map->x = i;
					D_Map->y = j;
					D_Map->tag = i/numbersWords*m_mapSize.width+j/m_identifiesRunsComplexity;
					D_Map->Next = nullptr;
					D_Map->sp = nullptr;
					D_Map->loaded = false;
					D_Map->Status = true;
					if(overloadReuseAlegal == nullptr)
					{
						overloadReuseAlegal = D_Map;
						t_Map = overloadReuseAlegal;
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
	
	
		argumentsDescriptionPrior(); 
}
void illustrateDiscussion::newAstar()
{
	AStarMap = NewAstarMap(m_mapSize,this);
	aspectsManipulate = true;
}
void illustrateDiscussion::newAstar2()
{
	AStarMap2 = NewAstarMap(m_mapSize,this);
	elsewhereSchema = true;
}
void illustrateDiscussion::tickCache(float dt)
{
	if(!loadall)
	{
		loadall = true;
		setoverloadReuseAlegal(m_compilersCompilationJust.x,m_compilersCompilationJust.y);
	
	
	}
}
bool illustrateDiscussion::addedConstituentPrograms(std::string key_value){
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
void illustrateDiscussion::argumentsDescriptionPrior()
{
	_infoMutex.lock();
	struct componentsOperateFeature *Dmap = overloadReuseAlegal;
	char imgstr[128] = {0};
	if (!m_isNoRes)
	{
		while(Dmap!=nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/numbersWords,Dmap->y/m_identifiesRunsComplexity, m_informSeparatorSuccessful.c_str());
		
			m_operationsComplicated.push_back(imgstr);
			if(Dmap->sp == nullptr&&(getparametisOrdinaryPrefi(role_pos.x,role_pos.y,Dmap->x,Dmap->y)))
			{
				if(m_constituteEspecially == true)
				{
				
				
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(illustrateDiscussion::letsEncloseDoing,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(illustrateDiscussion::placedEquivalent,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						areaConventionsGiven.insert(std::pair<int,std::string>(entryId,imgstr));
				}
				else if(m_guaranteeDealingBlob)
				{
				
					if(addedConstituentPrograms(imgstr) == false)
					{
						isbnsProgramsHair *sprite = isbnsProgramsHair::create(imgstr,"res/syncReplace/map_cell.jpg");
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
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(illustrateDiscussion::letsEncloseDoing,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(illustrateDiscussion::placedEquivalent,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							areaConventionsGiven.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
			Dmap = Dmap->Next;
		}
		this->m_benefitDestroying = true;
	}
	else
	{
		this->m_benefitDestroying = true;
	}
	_infoMutex.unlock();
}
void illustrateDiscussion::letsEncloseDoing(cocos2d::Texture2D *a,componentsOperateFeature* DmapNode)
{
	char imgstr[128] = {0};
	if(DmapNode!=nullptr&&mapstr.size()>0)
	{
		if(DmapNode->sp == nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),DmapNode->x/numbersWords,DmapNode->y/m_identifiesRunsComplexity, m_informSeparatorSuccessful.c_str());
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
void illustrateDiscussion::placedEquivalent(int entryId){
	if(entryId <= 0) 
		return;
	auto iter = areaConventionsGiven.find(entryId);
	if(iter != areaConventionsGiven.end()){
		areaConventionsGiven.erase(iter);
	}
}
void illustrateDiscussion::quizMeansAppearResponses()
{
	if(role_main!=nullptr){
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
		computationalCollection();
	}
}
void illustrateDiscussion::wefifthUnformatted(Point start,bool isFb)
{
	if(m_isFb == false)
		m_isFb = isFb;
	if(role_main!=nullptr)
	{
		role_main->stop = CC_CALLBACK_0(illustrateDiscussion::charactersVectorDoing, this); 
		role_main->onWalk = CC_CALLBACK_3(illustrateDiscussion::coutLogicallyVector, this);
		role_main->quizMeansAppearResponses = CC_CALLBACK_0(illustrateDiscussion::quizMeansAppearResponses, this); 
		role_main->onFly = CC_CALLBACK_5(illustrateDiscussion::FlyRocket, this); 
		role_main->recordThcallIsfifth5 = CC_CALLBACK_4(illustrateDiscussion::recordThcallIsfifth5, this); 
		Point startpos = role_main->getPosition();
		if(start!=Point())
			m_compilersCompilationJust = start;
		else
			m_compilersCompilationJust = indeedScopeHeldSource(startpos);
		systemsData = dir_undef;
		representMatchAllowed(true);
	}
	if(m_effect==nullptr)
	{
		m_effect = introducedBookstore::create(false);
		addChild(m_effect,1);
	}
}
int illustrateDiscussion::getmainHaveRegardless(Point tile){
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
int illustrateDiscussion::getfindProcessesChoseClose(Point tile){
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
bool illustrateDiscussion::isBlock(Point tile)
{
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_prvoidAssociativeLiteral.at(x*int(m_mapSize.height) + y) == '1');
}
bool illustrateDiscussion::isOpacity(Point tile)
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
Point illustrateDiscussion::designedWorrySubscript(Point point)
{
	return indeedScopeHeldSource(highTemporaryTransfers(point));
}
Point illustrateDiscussion::relationshipTranslate(Point tile)
{
	return oargumentsAlphanumeric(saysPlaceAggregate(tile));
}
Point illustrateDiscussion::highTemporaryTransfers(Point point)
{
	return convertToNodeSpace(point);
}
Point illustrateDiscussion::oargumentsAlphanumeric(Point pos)
{
	return convertToWorldSpace(pos); 
}
Point illustrateDiscussion::saysPlaceAggregate(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y+0.5))* m_perTileSize.height;
	return Point(sx,sy);
}
Point illustrateDiscussion::indeedScopeHeldSource(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y/m_perTileSize.height);
	int tx = floor(pos.x/m_perTileSize.width);
	return Point(tx, ty); 
}
void illustrateDiscussion::nodefaultComparePrompt(Point tile,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	if(speed != -1){
		natureConverting = (speed>0.01)?speed:natureConverting;
	
		if(systemsData>= dir_undef)
		{
			m_compilersCompilationJust = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ tpreviousEvaluatedKind();});
			auto action = Sequence::create(DelayTime::create(natureConverting-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		m_compilersCompilationJust = tile;
	}
	float scale = illustrateDiscussion::m_freeCover;
	Point space = CC_POINT_PIXELS_TO_POINTS(saysPlaceAggregate(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void illustrateDiscussion::othersSeriesDiscussioof(Point pos_,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	auto tile = indeedScopeHeldSource(pos_);
	if(speed != -1){
		natureConverting = (speed>0.01)?speed:natureConverting;
	
		if(systemsData>= dir_undef)
		{
			m_compilersCompilationJust = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
				tpreviousEvaluatedKind();
			});
			auto action = Sequence::create(DelayTime::create(natureConverting-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		m_compilersCompilationJust = tile;
	}
	float scale = illustrateDiscussion::m_freeCover;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void illustrateDiscussion::scrollMap(Point pos,float speed)
{
	if (m_pMap)
	{
		pos = compoundInheritance(pos);
	
		comparingNonmember(pos);
		computationalCollection();
		if(speed != -1){
			FiniteTimeAction* resetfun = CallFunc::create([&](){ representMatchAllowed(true);});
			ActionInterval* move = MoveTo::create(natureConverting, pos);
			Action* action = Sequence::create(move,resetfun,nullptr);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}else{
			setPosition(pos);
			representMatchAllowed(true);
			if (sectionsBlockIntended::m_coversReplacementPrior)
			{
				sectionsBlockIntended::m_coversReplacementPrior->createTransPrefix(pos);
			}
		}
	}
}
Vec2 illustrateDiscussion::grantsNontemplateSwapped(Vec2 pos_){
	float scale = illustrateDiscussion::m_freeCover;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = compoundInheritance(pos);
	comparingNonmember(pos);
	return pos;
}
void illustrateDiscussion::comparingNonmember(Vec2& pos){
	float scale = illustrateDiscussion::m_freeCover;
	Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
	Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale-1)/2;
	edgeSize = edgeSize + edgeSize1;
	if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
	if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
	if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
	if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
}
void illustrateDiscussion::skip2Tile(Point tile)
{
	m_compilersCompilationJust = tile;
	float scale = illustrateDiscussion::m_freeCover;
	Point space = CC_POINT_PIXELS_TO_POINTS(saysPlaceAggregate(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = compoundInheritance(pos);
	if (m_pMap)
	{
	
		comparingNonmember(pos);
		setPosition(pos);
		representMatchAllowed(true);
		if (sectionsBlockIntended::m_coversReplacementPrior)
		{
			sectionsBlockIntended::m_coversReplacementPrior->createTransPrefix(pos);
		}
	}
}
Vec2 illustrateDiscussion::compoundInheritance(Vec2 pos){
	pos.y -= m_perTileSize.height * 5;
	return pos;
}
void illustrateDiscussion::representMatchAllowed(bool right_away,Vec2 tile)
{
	if(right_away)
	{
		needsThgenerates = 1;
	}
	if(needsThgenerates % 5 == 1)
	{
	
		Node* item_node = getChildByTag(316);
		if(item_node && !m_isFb)
		{
			for (auto& child : item_node->getChildren())
			{
				copiedFlipsActual* base = dynamic_cast<copiedFlipsActual*>(child);
				if (base == nullptr)
				{
					bool visible_ = incrementsDerivedWhose(child);
					child->setVisible(visible_);
				}
				else
				{
					if(role_main && role_main->getnodefaultDoesPermitted() == base->getnodefaultDoesPermitted())
						continue;
					indexingSales* player = dynamic_cast<indexingSales*>(child);
					extendedUsesMatch baseType = base->getTypeId();
					if (baseType == extendedUsesMatch::PLAYER_MANE_TYPE || baseType == extendedUsesMatch::PLAYER_FEMALE_TYPE
						|| baseType == extendedUsesMatch::NORMAL_MONSTER || baseType == extendedUsesMatch::ELIT_MONSTER || baseType == extendedUsesMatch::BOSS_MONSTER || baseType == extendedUsesMatch::JUQING_MONSTER
						|| baseType == extendedUsesMatch::PLAYER_MANE_TYPE
						|| baseType == extendedUsesMatch::NPC_TYPE)
					{
						bool visible_ = incrementsDerivedWhose(child,base);
						if(player == nullptr){
							child->setVisible(visible_);
							base->setthreeFilesOperand(visible_);
						}else if (player->getbasicsAutomaticHandling1() == 0){
							player->setVisible(visible_);
							player->setthreeFilesOperand(visible_);
						
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
				bool visible_ = incrementsDerivedWhose(child);
				child->setVisible(visible_);
			}
		}
	
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr && m_performHead != 0)
		{
			pStack->executeFunctionByHandler(m_performHead, 0);
			pStack->clean();
		}
	
		Vec2 c_tile = Vec2::ZERO;
		if(tile != Vec2::ZERO){
			c_tile = tile;
		}
		else if(role_main && role_main->getbasicsAutomaticHandling1() != 1 && role_main->getbasicsAutomaticHandling1() != 3){
			c_tile = indeedScopeHeldSource(role_main->getPosition());
		}
	
		if(c_tile != Vec2::ZERO)
			setoverloadReuseAlegal(c_tile.x, c_tile.y, true);
	}
	needsThgenerates++;
}
bool illustrateDiscussion::incrementsDerivedWhose(Node* child,copiedFlipsActual* base)
{
	bool visible_ = true;
	if(workReadyBeen)
	{
		visible_ = true;
	}
	else
	{
		Point n_pos = oargumentsAlphanumeric(child->getPosition());
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
indexingSales* illustrateDiscussion::getconfidentKindActions(){
	return role_main;
}
void illustrateDiscussion::setconfidentKindActions(indexingSales* role){
	role_main = role;
	if(role_main)
		role_main->setillustrateDiscussion(this);
}
void illustrateDiscussion::lookingPresumablyArraythe5(bool stop_rock,bool removeWalCb,bool doStand)
{
	if(role_main){
		AStarPath = nullptr;
		tpreviousEvaluatedKind();
	
	
		if(stop_rock)
			charactersVectorDoing();
		else if(role_main)
			strategyBookstoreAlmost(role_main->getstreamConditionTechniques(),0,Vec2::ZERO,0);
		role_main->computationalCollection();
		computationalCollection();
		if(doStand){
			if(role_main->getappeaanywhereScopedBasic() != ACTION_STATE_IDLE)
				role_main->standed();
		}
		if(removeWalCb){
			m_walk_cb = 0;
			guideRemainderNeither();
		}
		pdataDoeth = Vec2::ZERO;
		_m_time = 1000;
	}
}
void illustrateDiscussion::followGrantsManaging(){
	AStarPath = nullptr;
	tpreviousEvaluatedKind();
	if(role_main)
		role_main->computationalCollection();
	_m_time = 1000;
}
void illustrateDiscussion::aliasesDifferences5(cocos2d::Point cp, bool isnear, int spaceNum, bool sendMsg)
{
	if(AStarMap == nullptr)
	{
		CPLUSLog("[illustrateDiscussion::aliasesDifferences5] AStarMap == nullptr");
		return;
	}
	lookingPresumablyArraythe5(false,false,false);
	InitAstarMap(AStarMap);
	AStarPath = FindPath(m_compilersCompilationJust.x, m_compilersCompilationJust.y, cp.x, cp.y, AStarMap);
	if (isnear)
	{
		struct targetSimilar *path =  AStarPath;
		while(path != NULL ) 
		{
			if (path->Next == NULL)
			{
			
				struct targetSimilar *tmpPath = path;
				for (int i = 0; i < spaceNum; i++)
				{
					struct targetSimilar *tmpPath2 = tmpPath->Father;
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
	whateverOpposedExhasuting(AStarPath, NULL, sendMsg);
}
void illustrateDiscussion::printsTakingHigher(cocos2d::Point cp)
{
	if(loop_flag != 2|| role_main == nullptr ) return ;
	aliasesDifferences5(cp, false, 0, false);
}
void illustrateDiscussion::ofileHeaderPrevented(Point cp,bool isnear, int spaceNum)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getappeaanywhereScopedBasic()>ACTION_STATE_CHENMO) return ;
	if (role_main != nullptr && !role_main->getActive())
	{
		if (m_sizeNoneRecord > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(3);
				pStack->executeFunctionByHandler(m_sizeNoneRecord, 1);
				pStack->clean();
			}
		}
		CPLUSLog("[illustrateDiscussion::ofileHeaderPrevented] role cannot Move");
		return;
	}
	aliasesDifferences5(cp, isnear, spaceNum);
	systemsData = dir_undef;
}
int illustrateDiscussion::relevantCmatchWrite(Point cp,correspondingFunctional* monster,float sp,bool isnear,Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getappeaanywhereScopedBasic()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	Point m_tile = indeedScopeHeldSource(monster->getPosition());
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	struct targetSimilar *path = FindPath(m_tile.x, m_tile.y, cp.x, cp.y, AStarMap2);
	_mapMutex.unlock();
	if(path == nullptr) return 0;
	struct targetSimilar *path1 = path;
	int i = 0;
	whateverOpposedExhasuting(path,monster);
	path1 = path;
	while(path1!=nullptr)
	{
		tabl[i] = Point(path1->X,path1->Y);
		path1 = path1->Next;
		i++;
	}
	return i;
}
void illustrateDiscussion::preserveFixedCollide(correspondingFunctional* item,cocos2d::Point cp){
	if(cp == Vec2::ZERO)
		cp = indeedScopeHeldSource(item->getPosition());
	startingCompile *luaEventMgr = startingCompile::instance();
	implementContainingMeans buffer = luaEventMgr->getlvalueBehavesProcessing(C2S_MOVE);
	buffer.pushShort(item->getSpeed());
	buffer.pushBool(false);
	buffer.pushShort(m_mapId);
	buffer.pushShort(cp.x);
	buffer.pushShort(cp.y);
	buffer.pushShort(0);
	intendedForwardingMust::getInstance()->intvaluesIteratorStyle(buffer);
}
int illustrateDiscussion::getsuppliesLimitedDenote(Point start,Point dest,bool selfFlg, Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getappeaanywhereScopedBasic()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	if (selfFlg && role_main != nullptr && !role_main->getActive())
	{
		if (m_sizeNoneRecord > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(5);
				pStack->executeFunctionByHandler(m_sizeNoneRecord, 1);
				pStack->clean();
			}
		}	
		return 0;
	}
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	int i = 0;
	struct targetSimilar *path = FindPath(start.x, start.y, dest.x, dest.y, AStarMap2);
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
void illustrateDiscussion::returnsSaveIntroduce(Point d_tile)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getappeaanywhereScopedBasic()>ACTION_STATE_CHENMO) return ;
	if(AStarMap == nullptr)
		return;
	lookingPresumablyArraythe5(false,true,false);
	InitAstarMap(AStarMap);
	systemsData = dir_undef;
	AStarPath = FindPath(m_compilersCompilationJust.x, m_compilersCompilationJust.y, d_tile.x, d_tile.y, AStarMap);
	if(AStarPath!=nullptr)
	{
		whateverOpposedExhasuting(AStarPath);
	}
}
void illustrateDiscussion::listedAssociativeDetails(){
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
				m_resolvedDeclaring.clear();
				int userCount=triggerListValue.Size();
				for (int i=0;i<userCount;i++)
				{
					const rapidjson::Value &trigger=triggerListValue[i];
					if (trigger.IsObject())
					{
						evaluatePassed newTrigger;
						newTrigger.userChaptersControls = Vec2::ZERO;
						newTrigger.m_fallConstexpr = Vec2::ZERO;
						int x,y;
						const rapidjson::Value &userChaptersControls = trigger["userChaptersControls"];
						x = userChaptersControls["x"].GetInt();
						y = userChaptersControls["y"].GetInt();
						newTrigger.userChaptersControls = Vec2(x,y);
						const rapidjson::Value &m_fallConstexpr = trigger["m_fallConstexpr"];
						x = m_fallConstexpr["x"].GetInt();
						y = m_fallConstexpr["y"].GetInt();
						newTrigger.m_fallConstexpr = Vec2(x,y);
						m_resolvedDeclaring.push_back(newTrigger);
					}
				}
			}
		}
	} while (0);
}
evaluatePassed illustrateDiscussion::variesParametethat(cocos2d::Vec2 point){
	for(std::vector<evaluatePassed>::iterator iter = m_resolvedDeclaring.begin();iter!=m_resolvedDeclaring.end();iter++){
		evaluatePassed trigger = *iter;
		if(trigger.userChaptersControls.x == point.x && trigger.userChaptersControls.y == point.y){
			return trigger;
		}
	}
	evaluatePassed newTrigger;
	newTrigger.userChaptersControls = Vec2::ZERO;
	newTrigger.m_fallConstexpr = Vec2::ZERO;
	return newTrigger;
}
void illustrateDiscussion::initialAgainCaller3(){
	if(pdataDoeth != Vec2::ZERO){
		ofileHeaderPrevented(pdataDoeth);
		pdataDoeth = Vec2::ZERO;
		if(role_main)
			role_main->friendsSelectedMany(true);
	}
}
bool illustrateDiscussion::greaterClosesSpecifier5(int typeId,cocos2d::Vec2 point){
	return false;
	if(role_main == nullptr)
		return false;
	int fly_mode = getfindProcessesChoseClose(point);
	bool auto_double_jump_check = false;
	if(fly_mode == -1)
		auto_double_jump_check = true;
	if(typeId == 1){
	
		if(getmainHaveRegardless(point) == 3){
			Vec2 flyTarget = Vec2::ZERO;
			evaluatePassed trigger = variesParametethat(point);
			flyTarget = trigger.m_fallConstexpr;
			if(flyTarget != Vec2::ZERO){
			
				Vec2 tmp = Vec2::ZERO;
				if(AStarPath && AStarPath->Next != nullptr){
					while (AStarPath->Next != nullptr){
						AStarPath = AStarPath->Next;
					}
				
					if(isBlock(Vec2(AStarPath->X,AStarPath->Y)) == false && getmainHaveRegardless(Vec2(AStarPath->X,AStarPath->Y)) != 3)
						tmp = Vec2(AStarPath->X,AStarPath->Y);
				}
				role_main->sectionGuaranteeHighest(0,fly_mode,0,saysPlaceAggregate(flyTarget),dir_none,true,auto_double_jump_check);
				role_main->friendsSelectedMany(false,flyTarget);
				pdataDoeth = tmp;
				return true;
			}
		}
	}else{
	
		if(getmainHaveRegardless(point) == 3){
			Vec2 flyTarget = Vec2::ZERO;
			evaluatePassed trigger = variesParametethat(point);
			flyTarget = trigger.m_fallConstexpr;
			if(flyTarget != Vec2::ZERO){
				role_main->sectionGuaranteeHighest(0,1,0,saysPlaceAggregate(flyTarget),dir_none,true,auto_double_jump_check);
				role_main->friendsSelectedMany(false,flyTarget);
				return true;
			}
		}
	}
	return false;
}
void illustrateDiscussion::operationCorresponds(){
	if(AStarPath && role_main){
		role_main->standed();
		while (AStarPath->Next != nullptr){
			AStarPath = AStarPath->Next;
		}
		ofileHeaderPrevented(Vec2(AStarPath->X,AStarPath->Y));
	}
}
void illustrateDiscussion::constraintsCombineThat(){
	if(AStarPath )
	{
	
		tpreviousEvaluatedKind();
		Vec2 checkPoint = Vec2(AStarPath->X,AStarPath->Y);
		AStarPath = nullptr;
		if(greaterClosesSpecifier5(1,checkPoint))
			return;
		if(role_main)
			role_main->standed();
		quizMeansAppearResponses();
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
	
		representMatchAllowed(true);
	}
}
void illustrateDiscussion::update(float dt)
{
	if(role_main == nullptr)
	{
		return;
	}
	if (dynamic_cast<Node*>(m_variadicMuensureArrays))
	{
		updatePos();
	}
	if(role_main->getappeaanywhereScopedBasic() > ACTION_STATE_CHENMO)
	{
		if (role_main->beControl())
		{
			designingConstsArrarecall(dt);
		}
		return;
	}
	_m_time += dt;
	m_argumentIncreased += dt; 
	m_preprocessorIgnore += dt;
	m_compiledCreate += dt;
	if(m_argumentIncreased>SPEED*8) m_argumentIncreased = SPEED*4;
	auto status = role_main->getappeaanywhereScopedBasic();
	if(status != ACTION_STATE_IDLE){
		m_preprocessorIgnore = 0;
	}
	if(systemsData < dir_undef && _m_time >= natureConverting)
	{
		_m_time = 0;
		if(role_main->canMove()){
			cocos2d::Vec2 startPos = role_main->getPosition();
			cocos2d::Vec2 targetPos = startPos;
			m_compilersCompilationJust = indeedScopeHeldSource(targetPos);
			targetPos.add(m_wantedEvaluated * 60);
			m_constsFindbook = indeedScopeHeldSource(targetPos);
			m_constsFindbook = undefinedDifficult(m_compilersCompilationJust,m_constsFindbook);
			if(isBlock(m_constsFindbook))
			{
				Point tile = getprocessControlsSkip3(m_constsFindbook,systemsData);
				if(!isBlock(tile) && tile != m_compilersCompilationJust)
				{
					m_constsFindbook = tile;
					auxiliaryEssential temp_dir = getfollowingPersist(m_constsFindbook-m_compilersCompilationJust);
					debugdeleteStarting = m_coveredSpecial;
					targetPos = saysPlaceAggregate(m_constsFindbook);
					m_wantedEvaluated = (targetPos - startPos).getNormalized();
				}
			}
			if(!isBlock(m_constsFindbook))
			{
				if(greaterClosesSpecifier5(2,m_constsFindbook) == true){
					return;
				}
				Point role_move_pc = targetPos;
				Point role_move_pc_start = role_main->getPosition();
				Point role_move_pc_send = targetPos;
				role_move_pc_send.add(m_wantedEvaluated * 60);
				Vec2 role_tile_send = indeedScopeHeldSource(role_move_pc_send);
				if(isBlock(role_tile_send)){
					role_move_pc_send = role_move_pc;
					role_tile_send = indeedScopeHeldSource(role_move_pc_send);
				}
				float distance = role_move_pc_start.distance(role_move_pc);
				natureConverting = distance/map_speed;
				role_main->cleanMove(false);
				role_main->backDoneDelegate(role_tile_send,false);
				strategyBookstoreAlmost(auxiliaryEssential::dir_none,1,role_tile_send,0);
				AStarPath = nullptr;
			}
		}
	}
	else if(m_isrock == true && AStarPath == nullptr && systemsData ==dir_undef && (status == ACTION_STATE_WALK || status == ACTION_STATE_RUN))
	{
	
		m_isrock = false;
		tpreviousEvaluatedKind();
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
		representMatchAllowed(true);
	}
	else if(status == ACTION_STATE_WALK || status == ACTION_STATE_RUN || status == ACTION_STATE_FLY || status == ACTION_STATE_SUDDEN){
		representMatchAllowed();
	
	
		if(m_compiledCreate >= 0.5){
			m_compiledCreate = 0;
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
		if(m_preprocessorIgnore >= 1){
			m_preprocessorIgnore = 0;
			representMatchAllowed(true);
		}
	}
	designingConstsArrarecall(dt);
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
unsigned long illustrateDiscussion::getCurrMemory()
{
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	return pmc.WorkingSetSize;
}
#endif
Point illustrateDiscussion::getprocessControlsSkip3(Point dir_tile,auxiliaryEssential dir,int titleOffset)
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
bool illustrateDiscussion::hasBlock(cocos2d::Point startPoint,cocos2d::Point endPoint){
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
bool illustrateDiscussion::techniquePromiseConflict2(cocos2d::Point startPoint,cocos2d::Point endPoint){
	return hasBlock(indeedScopeHeldSource(startPoint),indeedScopeHeldSource(endPoint));
}
Vec2 illustrateDiscussion::undefinedDifficult(cocos2d::Point startPoint,cocos2d::Point endPoint){
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
Vec2 illustrateDiscussion::foundGeneralSystemsNature(cocos2d::Point startPoint,cocos2d::Point endPoint){
	Vec2 endTitle = indeedScopeHeldSource(endPoint);
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
		if (!isBlock(indeedScopeHeldSource(_newCheckPoint)))
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
Vec2 illustrateDiscussion::recognizingReallocates(cocos2d::Point startTile,cocos2d::Point endTile){
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
int illustrateDiscussion::fixPath(struct targetSimilar *startpath){
	float speed = map_speed;
	int pathNum = 0;
	float allTime = 0;
	struct targetSimilar *rootPath =  startpath;
	struct targetSimilar *path =  startpath;
	if(path == nullptr) return 0;
	struct targetSimilar *path1 =  path->Next;
	if(path1==nullptr) return 0;
	int i = 0,j = 0;
	auxiliaryEssential old_dir,new_dir;
	old_dir =  getfollowingPersist(Point(path1->X,path1->Y)-Point(path->X,path->Y));
	while(path->Next!=nullptr)
	{
		path = path->Next;
		path1 = path->Next;
		if(path1 != nullptr)
		{
			new_dir = getfollowingPersist(Point(path1->X,path1->Y)-Point(path->X,path->Y));
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
		struct targetSimilar * pathStart = startpath;
		struct targetSimilar * pathStart2 = nullptr;
		struct targetSimilar * pathEnd = nullptr;
		path =  startpath;
		path1 =  path->Next;
		while(path->Next!=nullptr)
		{
			i++;
			path = path->Next;
			path1 = path->Next;
			if(path1 != nullptr)
			{
				new_dir = getfollowingPersist(Point(path1->X,path1->Y)-Point(path->X,path->Y));
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
				if(getmainHaveRegardless(Vec2(path->X,path->Y)) == 3){
				
				
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
void illustrateDiscussion::whateverOpposedExhasuting(struct targetSimilar *startpath,correspondingFunctional* sendItem, bool sendMsg )
{
	if(sendItem == nullptr){
		sendItem = role_main;
	}
	if(sendItem == nullptr)
		return;
	float allMoveTime = 0;		
	bool isMe = false;
	std::string actorId = sendItem->getnodefaultDoesPermitted();
	if(role_main){
		if(actorId == role_main->getnodefaultDoesPermitted())
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
	struct targetSimilar *path =  startpath;
	if(path && path->Next != nullptr){
	
		startingCompile *luaEventMgr = startingCompile::instance();
		implementContainingMeans buffer = luaEventMgr->getlvalueBehavesProcessing(C2S_MOVE);
		buffer.pushInt(pathNum + 1);
		buffer.pushInt(startpath->X);
		buffer.pushInt(startpath->Y);
		while (path->Next != nullptr)
		{
			sendItem->backDoneDelegate(Vec2(path->Next->X,path->Next->Y),false);
			buffer.pushInt(path->Next->X);
			buffer.pushInt(path->Next->Y);
			path = path->Next;
		}
		if (sendMsg)
		{
			intendedForwardingMust::getInstance()->intvaluesIteratorStyle(buffer);
		}
		if(isMe)
		{
			if(AStarPath &&  AStarPath->Next)
				AStarPath = AStarPath->Next;
			if(pathNum == 1)
			{
				Vec2 role_move_pc_start = sendItem->getPosition();
				Vec2 role_move_pc_end = saysPlaceAggregate(Vec2(path->X,path->Y));
				if(indexingSales::eamightFeaturesStatements(role_move_pc_start,role_move_pc_end) && 
					abs(role_move_pc_start.x - role_move_pc_end.x) > indexingSales::m_theyBase * 2 &&
					abs(role_move_pc_start.y - role_move_pc_end.y) > indexingSales::m_theyBase * 2)
				{
					sendItem->setpatternsTypesGrouped(true);
				}
			}
		}
	}
	else if(path && path->Next == nullptr)
	{
		sendItem->backDoneDelegate(Vec2(path->X,path->Y),false);
		if(isMe)
			sendItem->setpatternsTypesGrouped(true);
	
	
	}
}
void illustrateDiscussion::strategyBookstoreAlmost(auxiliaryEssential dir,int step,Vec2 targetPos,float moveTime)
{
	if(role_main == nullptr)
		return;
	if (step == 1)
	{
		startingCompile *luaEventMgr = startingCompile::instance();
		implementContainingMeans buffer = luaEventMgr->getlvalueBehavesProcessing(C2S_MOVE);
		buffer.pushInt(2);
		buffer.pushInt(m_compilersCompilationJust.x);
		buffer.pushInt(m_compilersCompilationJust.y);
		buffer.pushInt(targetPos.x);
		buffer.pushInt(targetPos.y);
		intendedForwardingMust::getInstance()->intvaluesIteratorStyle(buffer);
	}
	else if (step == 0 && role_main->getappeaanywhereScopedBasic() != ACTION_STATE_IDLE) 
	{
		startingCompile *luaEventMgr = startingCompile::instance();
		tpreviousEvaluatedKind();
		Vec2 pos;
		pos.x = m_compilersCompilationJust.x;
		pos.y = m_compilersCompilationJust.y;
		implementContainingMeans buffer = luaEventMgr->getlvalueBehavesProcessing(C2S_STOP_MOVING);
		buffer.pushInt(pos.x);
		buffer.pushInt(pos.y);
		intendedForwardingMust::getInstance()->intvaluesIteratorStyle(buffer);
	}
}
void illustrateDiscussion::markerLearnedDirectly(correspondingFunctional* item,Vec2 pos,bool cAstar){
	return;
	if(item->getunorderedChartypSpelling() == false)
		return;
	bool isMe = false;
	std::string actorId = item->getnodefaultDoesPermitted();
	if(role_main){
		if(actorId == role_main->getnodefaultDoesPermitted())
			isMe = true;
	}
	if(pos == Vec2::ZERO){
		if(isMe){
			tpreviousEvaluatedKind();
			pos.x = m_compilersCompilationJust.x;
			pos.y = m_compilersCompilationJust.y;
			if(cAstar && AStarPath && AStarPath->Next)
				AStarPath = AStarPath->Next;
		}else{
			auto tmp_tile = indeedScopeHeldSource(item->getPosition());
			pos.x = tmp_tile.x;
			pos.y = tmp_tile.y;
		}
	}
	startingCompile *luaEventMgr = startingCompile::instance();
	implementContainingMeans buffer = luaEventMgr->getlvalueBehavesProcessing(C2S_SYNC_POS);
	buffer.pushInt(pos.x);
	buffer.pushInt(pos.y);
	intendedForwardingMust::getInstance()->intvaluesIteratorStyle(buffer);
}
void illustrateDiscussion::coutLogicallyVector(auxiliaryEssential dir,float distance,cocos2d::Vec2 direction)
{
	if(loop_flag == 2&&role_main!=nullptr&&role_main->getappeaanywhereScopedBasic() <= ACTION_STATE_CHENMO)
	{
	
		m_isrock = true;
		m_wantedEvaluated = direction;
		if(role_main->getappeaanywhereScopedBasic() != ACTION_STATE_FLY && role_main->getappeaanywhereScopedBasic() != ACTION_STATE_SUDDEN){
			if(systemsData != dir){
				debugdeleteStarting = 0;
				systemsData = dir;
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
				role_main->settreatedDescribeSeparately(m_wantedEvaluated);
		}
	}
}
void illustrateDiscussion::FlyRocket(int actionId,int fly_mode,cocos2d::Vec2 newPos,float actionTime,int speed){
	if(role_main == nullptr)
		return;
	if(actionId == 1){
	
		if(fly_mode == 1)
			followGrantsManaging();
		othersSeriesDiscussioof(newPos,actionTime);
	}else{
	
		tpreviousEvaluatedKind();
		markerLearnedDirectly(role_main,m_compilersCompilationJust);
		representMatchAllowed(true);
	
		if(greaterClosesSpecifier5(2,m_compilersCompilationJust))
			return;
		else
			initialAgainCaller3();
	}
	if(m_fly_cb && m_fly_cb != 0)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			Vec2 newTile = indeedScopeHeldSource(newPos);
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
void illustrateDiscussion::charactersVectorDoing() 
{
	if(loop_flag == 2 && role_main->getappeaanywhereScopedBasic())
	{
	
		if(role_main)
			role_main->settreatedDescribeSeparately(Vec2::ZERO);
		tpreviousEvaluatedKind();
		strategyBookstoreAlmost(systemsData,0,Vec2::ZERO,0);
		debugdeleteStarting = 0;
		systemsData = dir_undef;
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
void illustrateDiscussion::articlesNoteFollow(double speed)
{
	if(role_main!=nullptr)
		role_main->setSpeed(speed);
	map_speed = speed;
}
double illustrateDiscussion::getSpeed(){
	return map_speed;
}
Point illustrateDiscussion::getaccessibleInvokes(Point pos_dest,int sub) 
{
	Point tile_start = m_compilersCompilationJust;
	Point tile_dest = indeedScopeHeldSource(pos_dest);
	Point sub_tile = tile_dest - tile_start;
	Point r_pos = Point();
	float angle = sub_tile.getAngle();
	float tanAngel = tan(angle);
	auxiliaryEssential dir = dir_up;
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
	r_pos = tile_dest - getpointersSomewhereAssume(dir)*sub;
	return r_pos;
}
void illustrateDiscussion::allocateCalculated(Point pos) 
{
}
auxiliaryEssential illustrateDiscussion::getfollowingPersist(Point tile) 
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
		return getowhichDifferenbetween(tile);
	}
}
auxiliaryEssential illustrateDiscussion::getowhichDifferenbetween(Point direction) 
{
	auxiliaryEssential dir = dir_right_up;
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
 Point illustrateDiscussion::getpointersSomewhereAssume(auxiliaryEssential dir) 
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
void illustrateDiscussion::assignmentChanges3(int handler){
	m_fly_cb = handler;
}
void illustrateDiscussion::writeListedCalc(int handler)
{
	m_walk_cb = handler;
}
void illustrateDiscussion::connectionCalledDynamic()
{
	m_walk_cb = 0;
}
void illustrateDiscussion::placeDestructorGenerates(int handler)
{
	m_rock_cb = handler;
}
void illustrateDiscussion::shouldRelationship()
{
	m_rock_cb = 0;
}
void illustrateDiscussion::thereAbilityOtherwise(int handler)
{
	problemsSequential = handler;
}
void illustrateDiscussion::tokensTreturnValueduring()
{
	problemsSequential = 0;
}
void illustrateDiscussion::machineBracketConstitutes(int handler)
{
	m_performHead = handler;
}
void illustrateDiscussion::runsPropertiesGranting()
{
	m_performHead = 0;
}
void illustrateDiscussion::beginExercisesExpanded(int handler)
{
	m_sizeNoneRecord = handler;
}
 
Size illustrateDiscussion::getLayerSize(){
	return m_mapSize;
}
Size illustrateDiscussion::getMapTileSize(){
	return m_perTileSize;
}
void illustrateDiscussion::whetherAdvancedFact(int type, Node* node, int objId, int z)
{
	if (node && debuggingToolsLegal)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			pStack->pushInt(type);
			pStack->pushObject(node, "Node");
			pStack->pushInt(objId);
			pStack->pushInt(z);
			pStack->executeFunctionByHandler(debuggingToolsLegal, 4);
			pStack->clean();
		}
	}
}
void illustrateDiscussion::forgotMovesOperating(int handler)
{
	debuggingToolsLegal = handler;
}
void illustrateDiscussion::memberRecentlyResetTells()
{
	debuggingToolsLegal = 0;
}
void illustrateDiscussion::tpreviousEvaluatedKind(){
	if(role_main)
		m_compilersCompilationJust = indeedScopeHeldSource(role_main->getPosition());
}
void illustrateDiscussion::varyGetsOverhead(int handler){
	m_overloadEffectively = handler;
}
bool illustrateDiscussion::argumentsUnwindingRewrite(float distance,float minDistance,Vec2 targetPos){
	leavingDealingShows = 0;
	m_bracketCoupled = 0;
	m_sequentialDirections = targetPos;
	temporaryDistinguish = m_behaviorOverallOperators;
	return false;
}
void illustrateDiscussion::guideRemainderNeither(){
	leavingDealingShows = 0;
	m_bracketCoupled = 0;
	m_sequentialDirections = Vec2::ZERO;
}
bool illustrateDiscussion::dynamicQualifySyntax(){
	if(role_main == nullptr)
		return false;
	if(role_main->getbraceTwinThposition()==1 || role_main->getbraceTwinThposition()==3)
		return false;
	if(role_main->getappeaanywhereScopedBasic() == ACTION_STATE_FLY || role_main->getappeaanywhereScopedBasic() == ACTION_STATE_SUDDEN)
		return false;
	if(leavingDealingShows > 0 && m_sequentialDirections != Vec2::ZERO){
		if(temporaryDistinguish < m_behaviorOverallOperators)
			temporaryDistinguish++;
		else{
			temporaryDistinguish = 0;
		
			Vec2 targetPos = saysPlaceAggregate(m_sequentialDirections);
			float distance = targetPos.distance(role_main->getPosition());
			if(distance >= m_bracketCoupled && distance<=leavingDealingShows){
			
			
			
				lookingPresumablyArraythe5(false,false,false);
				guideRemainderNeither();
				role_main->convertibleLegitimate2(1,targetPos);
				return true;
			}
		}
	}
	return false;
}
bool illustrateDiscussion::recordThcallIsfifth5(int actionId,Vec2 newPos,float actionTime,int speed){
	if(actionId == 1){
	
		othersSeriesDiscussioof(newPos,actionTime);
	
		if(m_overloadEffectively && m_overloadEffectively != 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				Vec2 newTile = indeedScopeHeldSource(newPos);
				pStack->pushInt(actionId);
				pStack->pushInt(int(newTile.x));							
				pStack->pushInt(int(newTile.y));							
				pStack->pushFloat(actionTime);						
				pStack->pushInt(int(newPos.x));						
				pStack->pushInt(int(newPos.y));						
				pStack->pushInt(speed);						
				pStack->executeFunctionByHandler(m_overloadEffectively, 7);
				pStack->clean();
			}
		}
		return true;
	}
	else if(actionId == 2){
	
		markerLearnedDirectly(role_main);
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
void illustrateDiscussion::setsupplyingMultidimensional(Node* node)
{
	if (node)
	{
		Node* followNode = dynamic_cast<Node*>(node);
		if (followNode)
		{
			m_variadicMuensureArrays = followNode;
		}
	}
	else
	{
		m_variadicMuensureArrays = nullptr;
	}
}
void illustrateDiscussion::updatePos()
{
	if (!role_main && !m_variadicMuensureArrays)
	{
		CPLUSLog("not role_main and follow node");
		return;
	}
	Point point = Point::ZERO;
	if (dynamic_cast<Node*>(m_variadicMuensureArrays))
	{
		point = m_variadicMuensureArrays->getPosition();
	}
	else
	{
		point = role_main->getPosition();
	}
	point = grantsNontemplateSwapped(point);
	setPosition(point);
}
void illustrateDiscussion::designingConstsArrarecall(float delaTime)
{
	if (!coverContainerGrades)
	{
		return;
	}
	if(m_writtenPassed == Vec2::ZERO)
		return;
	float speed = delaTime * map_speed;
	Vec2 moveDistance = m_correspondBlobptr * speed;
	Vec2 movePos = getPosition();
	movePos.add(moveDistance);
	comparingNonmember(movePos);
	setPosition(movePos);
	if (sectionsBlockIntended::m_coversReplacementPrior)
	{
		sectionsBlockIntended::m_coversReplacementPrior->createTransPrefix(movePos);
	}
	if(m_understandListsSystem > 0)
	{
		delaTime += m_understandListsSystem;
		m_understandListsSystem = 0;
	}
	_overTime+=delaTime;
	if(_overTime >= m_applySimilar)
	{
	
	
	
	
		m_writtenPassed = Vec2::ZERO;
	}
}
void illustrateDiscussion::backDoneDelegate(Vec2 pos)
{
	if (!coverContainerGrades)
	{
		return;
	}
	if(role_main == nullptr){
		cleanMove();
		return;
	}
	Vec2 role_move_pc_start = getPosition();
	Vec2 role_start = indeedScopeHeldSource(role_main->getPosition());
	Vec2 pos_ = saysPlaceAggregate(pos);
	Vec2 role_move_pc = grantsNontemplateSwapped(pos_);
	m_writtenPassed = Vec2(1,1);
	m_correspondBlobptr = (role_move_pc - role_move_pc_start).getNormalized();
	m_applySimilar = role_move_pc_start.distance(role_move_pc)/map_speed;
	_overTime = 0;
}
void illustrateDiscussion::cleanMove()
{
	if (!coverContainerGrades)
	{
		return;
	}
	m_writtenPassed = Vec2::ZERO;
	m_applySimilar = 0;
	_overTime = 0;
	m_understandListsSystem = 0;
}
void illustrateDiscussion::computationalCollection()
{
	if (!coverContainerGrades)
	{
		return;
	}
	stopActionByTag(ACTION_MOVE_TAG);
	cleanMove();
}
short illustrateDiscussion::areaManagingIncludesBuild(char intent,short inspired)
{
	char pushed = intent;
	short funtion = inspired * 916;
	double string = 595.17 - 215.13;
	return 361;
}
void * illustrateDiscussion::instantiating(void * reads,char whis,char exonly)
{
	void * illustrated = reads;
	char scope = whis;
	return nullptr;
}
void * illustrateDiscussion::whversionGetsEnforces(unsigned short soon)
{
	unsigned short statics = soon * 779;
	return nullptr;
}
unsigned short illustrateDiscussion::eitherSubscriptTyhave(char whether)
{
	m_printsOperatorclick = '4';
	return 399;
}
void * illustrateDiscussion::forgetThusSuccessful(float many,short promotes,char deal,long extended)
{
	float have = many * 982.15f;
	return nullptr;
}
