
#include "FindPath.h"
#include "JIGActuallyNocopyCtr.h"
#include "FontChina.h"
#include "SpriteBase.h"
#include "SpriteMonster.h"
#include "CCEffects.h"
#include "math/MathUtil.h"
#include "AsyncSprite.h"
#include "LuaMsgBuffer.h"
#include "LuaSocket.h"
#include "CCLuaEngine.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#pragma comment(lib,"Psapi.lib")
	#include "Psapi.h"
#endif
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "MapBackLayer.h"
USING_NS_CC;
static	struct _DisplayNode *DisplayMap = nullptr;
static	std::mutex _infoMutex;
static	std::mutex _mapMutex;
static std::string mapstr;
float MapView::m_mapScale = 0.8f;
MapView* MapView::DefaultMapView = nullptr;
void MapView::preAsyncLoadImg(std::string mapStr, int posX, int posY,int spanX, int spanY)
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
void MapView::setMapScale(float _scale)
{ 
	m_mapScale = _scale; 
}
MapView::MapView()  
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
	m_rocker_dir = dir_undef;
	m_rocker_direction = cocos2d::Vec2::ZERO;
	m_move_direction = Vec2::ZERO;
	role_main = nullptr;
	loop_flag = 0;
	rocker_loop = 0;
	rocker_loop_max = 2;
	m_walk_cb = 0;
	m_rock_cb = 0;
	m_fly_cb = 0;									
	m_sudden_cb = 0;								
	m_touch_move_cb = 0;
	m_reset_display_cb = 0;
	m_allShowWithoutCheck = false;
	MAP_SPAN_X = 10;
	MAP_SPAN_Y = 10;
	_m_time = 0;
	_m_touch_time = 0;
	_m_stand_time = 0;
	_m_move_time = 0;
	m_suddenDistance = 0;
	m_suddenTargetPos = Vec2::ZERO;
	m_suddenCheckGapMax = 5;
	m_suddenCheckGap = m_suddenCheckGapMax;
	m_mapId = 0;
	move_speed = SPEED;
	m_dir = dir_undef;
	load_Thread = nullptr;
	load_Thread1 = nullptr;
	load_Thread2 = nullptr;
	load_Thread3 = nullptr;
	loadall = false;
	m_isNoRes = false;
	m_resReady = true;
	m_isFb = false;
	m_isActive = true;
	m_isLoadFinished = false;
	m_isAstar1Finished = false;
	m_isAstar2Finished = false;
	resetDisplayGap = 1;
	autoPathFlyTargetPos = Vec2::ZERO;
	_infoMutex.lock();
	if(DisplayMap != nullptr)
	{
		delete(DisplayMap);
		DisplayMap = nullptr;
	}
	mapstr.clear();
	_infoMutex.unlock();
	m_addTopHeadNodeToMapCb = 0;
	auto_download = true;
	m_perTileSize = Size::ZERO;
	m_mapSize = Size::ZERO;
	m_winSize = Size::ZERO;
	m_curTargetPos = Vec2::ZERO;
	_overTime = 0;
	_remainTime = 0;
	_deltaTimeTmp = 0;
	m_cellImageSuffix = "jpg";
	m_followNode = nullptr;
	m_blockStr.clear();
	m_userOldMovePos = false;
}
MapView::~MapView()
{
	m_isActive = false;
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
	while (DisplayMap != nullptr)
	{
		struct _DisplayNode* pNode = DisplayMap;
		DisplayMap = DisplayMap->Next;
		delete(pNode);
	}
	mapstr.clear();
	m_blockStr.clear();
	_infoMutex.unlock();
	cleanAsync();
	DefaultMapView = nullptr;
}
void MapView::cleanup(){
	Layer::cleanup();
	cleanAsync();
	DefaultMapView = nullptr;
}
void MapView::cleanAsync(){
	if(m_asyncEntryIdList.size() > 0){
		for(std::unordered_map<int,std::string>::iterator iter = m_asyncEntryIdList.begin();iter != m_asyncEntryIdList.end();iter++){
			bool isFind = Director::getInstance()->getTextureCache()->unbindImageAsyncCustom(iter->second,iter->first);
			CCASSERT(isFind == true, "MapView m_asyncEntryId remove Fail");
		}
	}
	m_asyncEntryIdList.clear();
}
MapView *MapView::create(const std::string& filename, const int mapId, const bool isMultiMap, const Point pos)
{
	MapView *pRet = new MapView();
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
MapView *MapView::create()
{
	MapView *pRet = new MapView();
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
bool MapView::getDisplayStatus(int x,int y,int x1,int y1)
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
			
				status = x1<=screen_width&&(y1 + MAP_SPAN_Y)>(m_mapSize.height-screen_height);
			else
			
				status = x1<=screen_width&&abs(y1+MAP_SPAN_Y/2-y)<=(screen_height_half + MAP_SPAN_Y/2);
		}
		else if(x>(m_mapSize.width-screen_width_half))
		{
		
			if(y<screen_height_half)
			
				status = (x1 + MAP_SPAN_X)>=(m_mapSize.width-screen_width)&&y1<=screen_height;
			else if(y>(m_mapSize.height-screen_height_half))
			
				status = (x1 + MAP_SPAN_X)>=(m_mapSize.width-screen_width)&&(y1 + MAP_SPAN_Y)>(m_mapSize.height-screen_height);
			else
			
				status = (x1 + MAP_SPAN_X)>=(m_mapSize.width-screen_width)&& abs(y1+MAP_SPAN_Y/2-y)<=(screen_height_half + MAP_SPAN_Y/2);
		}
		else if(abs(x1+MAP_SPAN_X/2-x)<=(screen_width_half + MAP_SPAN_X/2))
		{
		
			if(y<screen_height_half)
			
				status = y1<=screen_height;
			else 
			
				status = (y1 + MAP_SPAN_Y)>(m_mapSize.height-screen_height);
		}
	}
	else if(abs(x1+MAP_SPAN_X/2-x)<=(screen_width_half + MAP_SPAN_X/2)&&abs(y1+MAP_SPAN_Y/2-y)<=(screen_height_half + MAP_SPAN_Y/2))
	{
	
		status = true;
	}
	return status;
}
void MapView::updateAllAddMapId(int mapId,bool remove){
	bool find = false;
	vector<int>::iterator it = m_map_allAdd.begin();
	for(;it != m_map_allAdd.end();it++){
		if(*it == mapId){
			find = true;
			break;
		}
	}
	if(remove == false){
	
		if(find == false){
			m_map_allAdd.push_back(mapId);
		}
	}
	else{
	
		if(find == true){
			m_map_allAdd.erase(it);
		}
	}
}
bool MapView::checkMapIdInAllAdd(int mapId){
	bool find = false;
	vector<int>::iterator it = m_map_allAdd.begin();
	for(;it != m_map_allAdd.end();it++){
		if(*it == mapId){
			find = true;
			m_allShowWithoutCheck = true;
			break;
		}
	}
	return find;
}
void MapView::setMapSpan(int span_x,int span_y){
	if(span_x <= 0 || span_y <= 0)
		return;
	MAP_SPAN_X = span_x;
	MAP_SPAN_Y = span_y;
}
void MapView::addMapSprites(std::vector<_DisplayNode*> list)
{
	_infoMutex.lock();
	if (!m_isNoRes){
		for(std::vector<_DisplayNode*>::iterator iter = list.begin();iter != list.end();iter++){
			_DisplayNode* Dmap = *iter;
			char imgstr[128];
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/MAP_SPAN_X,Dmap->y/MAP_SPAN_Y, m_cellImageSuffix.c_str());
			if(Dmap->Status&&Dmap->sp == nullptr&&(!Dmap->loaded)&&mapstr.size()>0){
				if(m_resReady == true){
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(MapView::asyncEntryIdCallBack,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						m_asyncEntryIdList.insert(std::pair<int,std::string>(entryId,imgstr));
				}else if(auto_download){
				
					if(checkMapCellIsDownloaded(imgstr) == false){
						int tmpSymbolKey[] = {59,43,38,11,38,37,72,9,32,43,27,47,73,9,43,11,7,73,27,62,9,43,47,47,53,41,27,2}; 
						std::string keyA = HandleString(tmpSymbolKey, 28);
						AsyncSprite *sprite = AsyncSprite::create(imgstr, keyA.c_str());
						if(sprite)
						{
							sprite->setAnchorPoint(Point(0,1));
							sprite->setPosition(Point(Dmap->x*m_perTileSize.width,(m_mapSize.height-Dmap->y)* m_perTileSize.height));
							m_pMap->addChild(sprite,0,Dmap->tag);
							Dmap->sp = sprite;
						}
					}else{
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(MapView::asyncEntryIdCallBack,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							m_asyncEntryIdList.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
		}
	}
	_infoMutex.unlock();
}
void MapView::setDisplayMap(int x,int y,bool updateShow)
{
	if (m_isNoRes)
		return;
	bool need_load = false;
	_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	std::vector<_DisplayNode*> needLoadDmap;
	while(Dmap!=nullptr)
	{
		if(m_allShowWithoutCheck){
		
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
		
			Dmap->Status = getDisplayStatus(x,y,Dmap->x,Dmap->y);
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
		addMapSprites(needLoadDmap);
	
	
	}
}
bool MapView::isLoadFinished(int AstarNum){
	loadall = true;
	if (m_isLoadFinished)
		DefaultMapView = this;
	if (AstarNum == 0)
		return m_isLoadFinished;
	if (AstarNum == 1)
		return m_isAstar1Finished;
	if (AstarNum == 2)
		return m_isAstar2Finished;
	return m_isLoadFinished;
}
void MapView::setScale(float scale)
{
	Node::setScale(scale);
}
bool MapView::loadMap(const std::string& tmxFile,const std::string& resFile,const  int mapId, const bool isMultiMap, const Point mpos)
{
	if(tmxFile.length() <= 0 )
		return true;
	m_mapId = mapId;
	m_pMap = TMXTiledMap::create(tmxFile);
	loadMapStr(tmxFile);
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
	
		checkMapIdInAllAdd(mapId);
		Ref* pObject = nullptr;  
		auto& children = m_pMap->getChildren();
		SpriteBatchNode* child = nullptr;
		for(const auto &node : children) {
			child = static_cast<SpriteBatchNode*>(node);
			child->getTexture()->setAntiAliasTexParameters();
		}
		start_tile = mpos;
		addChild(m_pMap);
		auto pot = resFile.find_last_of('.');
		_infoMutex.lock();
		mapstr = resFile;
		mapstr.replace(pot,4,"/");
		_infoMutex.unlock();
		load_Thread2 = new std::thread(&MapView::newAstar,this);
		load_Thread2->detach();
		load_Thread3 = new std::thread(&MapView::newAstar2,this);
		load_Thread3->detach(); 
		loop_flag = 2;
		float scale = MapView::m_mapScale;
		setScale(scale);
		Point space = CC_POINT_PIXELS_TO_POINTS(tile2Space(role_pos));
		Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
		Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
		if (pos.x > 0.0f) pos.x = 0.0f;
		if (pos.y > 0.0f) pos.y = 0.0f;
		if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
		if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
		setPosition(pos);
		if (MapBackLayer::DefaultMapBackLayer)
		{
			MapBackLayer::DefaultMapBackLayer->loadBack(resFile, mapId);
			MapBackLayer::DefaultMapBackLayer->updatePosition(pos);
		}
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto myListener = EventListenerTouchOneByOne::create();
	
		myListener->setSwallowTouches(true);
		myListener->onTouchBegan = [=](Touch* touch,Event* event)
		{
			if(m_rocker_dir < dir_undef)
				return false;
			return true;  
		};
		myListener->onTouchMoved = [=](Touch* touch,Event* event)
		{
		};
		myListener->onTouchEnded = [=](Touch* touch,Event* event)
		{
			if(_m_touch_time < SPEED)
				return;
			Point start = touch->getStartLocation();
			Point dest = touch->getLocation();
			Point span = dest - start;
			Point tile = screen2Tile(dest);
			Point tile_orign = tile;
		
			if (role_main != nullptr && !role_main->getActive())
			{
				if (m_noMove_cb > 0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != nullptr)
					{
						pStack->pushInt(1);
						pStack->executeFunctionByHandler(m_noMove_cb, 1);
						pStack->clean();
					}
				}
			}
			else if(dest.getDistance(start) < 30 && role_main!=nullptr&&role_main->getActive()&&role_main->isAlive() && role_main->getCurrActionState() != ACTION_STATE_FLY && role_main->getCurrActionState() != ACTION_STATE_SUDDEN)
			{
				if(isBlock(tile)){
				
					tile = checkCanWalkabledTile(start_tile,tile);
					if(isBlock(tile) || tile == Vec2::ZERO)
						return;
				}
			
				_m_touch_time = 0;
			
				#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
					printf("memory %d\r\n",getCurrMemory());
 
				#endif
				playStandEffect(tile2Space(tile_orign));
				if(m_rocker_dir >= dir_undef)
				{
					moveMapByTouch(tile);
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
			else if(abs(span.x)<80&&abs(span.y)>50&&m_touch_move_cb)  
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != nullptr)
				{
					pStack->pushBoolean(span.y > 0);
					pStack->executeFunctionByHandler(m_touch_move_cb, 1);
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
void MapView::loadMapStr(const std::string tmxFile)
{
	auto pot = tmxFile.find_last_of("/");
	auto tmpTmx = tmxFile.substr(0, pot + 1);
	auto tmpTmx1 = tmxFile.substr(pot + 1);
	tmpTmx.append("block/");
	tmpTmx.append(tmpTmx1);
	m_blockStr = FileUtils::getInstance()->getStringFromFile(tmpTmx);
	if (m_blockStr.empty())
		return;
	auto first = m_blockStr.find_first_of("\n");
	auto last = m_blockStr.find_last_of("\n");
	m_blockStr = m_blockStr.substr(last + 1);
}
void MapView::loadSpritesPre()
{
		TMXLayer* bg_layer = m_pMap->getLayer("bgLayer");
	
		if(bg_layer == nullptr&&DisplayMap==nullptr)
		{
			_infoMutex.lock();
			struct _DisplayNode *t_Map;
			for(int i=0;i<m_mapSize.width;i=i+MAP_SPAN_X)
			{
				for(int j=0;j<m_mapSize.height;j=j+MAP_SPAN_Y)
				{
					struct _DisplayNode *D_Map;
					D_Map = (struct _DisplayNode *)malloc(sizeof(struct _DisplayNode));
					D_Map->x = i;
					D_Map->y = j;
					D_Map->tag = i/MAP_SPAN_X*m_mapSize.width+j/MAP_SPAN_Y;
					D_Map->Next = nullptr;
					D_Map->sp = nullptr;
					D_Map->loaded = false;
					D_Map->Status = true;
					if(DisplayMap == nullptr)
					{
						DisplayMap = D_Map;
						t_Map = DisplayMap;
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
	
	
		addCacheSpritesPre(); 
}
void MapView::newAstar()
{
	AStarMap = NewAstarMap(m_mapSize,this);
	m_isAstar1Finished = true;
}
void MapView::newAstar2()
{
	AStarMap2 = NewAstarMap(m_mapSize,this);
	m_isAstar2Finished = true;
}
void MapView::tickCache(float dt)
{
	if(!loadall)
	{
		loadall = true;
		setDisplayMap(start_tile.x,start_tile.y);
	
	
	}
}
bool MapView::checkMapCellIsDownloaded(std::string key_value){
	JIGActuallyNocopyCtr jigactuallynocopyctr_e;
	jigactuallynocopyctr_e.comparingCurliesWhsuggest(nullptr,441,770);

	bool isDownload = false;
	lua_State* state = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	int top = lua_gettop(state);
	int nResult = 0;
	int tmpSymbolKey[] = {58,38,76,73,27,51,43,47,47,35,45,20,72,47,45,73,14,43,14}; 
	std::string keyA = HandleString(tmpSymbolKey, 19);
	try
	{
	
	
		lua_getglobal(state, keyA.c_str());
	
		if(!lua_isfunction(state, -1))
		{
		
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
		log("[LuaEngine] call function %s(...) failed\n", keyA.c_str());        
	return isDownload;
}
void MapView::addCacheSpritesPre()
{
	_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	char imgstr[128] = {0};
	if (!m_isNoRes)
	{
		while(Dmap!=nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),Dmap->x/MAP_SPAN_X,Dmap->y/MAP_SPAN_Y, m_cellImageSuffix.c_str());
		
			m_mapTextureList.push_back(imgstr);
			if(Dmap->sp == nullptr&&(getDisplayStatus(role_pos.x,role_pos.y,Dmap->x,Dmap->y)))
			{
				if(m_resReady == true)
				{
				
				
					std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this,Dmap);
					std::function<void(int)> asyncEntry = CC_CALLBACK_1(MapView::asyncEntryIdCallBack,this);
					int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
					if(entryId > 0)
						m_asyncEntryIdList.insert(std::pair<int,std::string>(entryId,imgstr));
				}
				else if(auto_download)
				{
				
					if(checkMapCellIsDownloaded(imgstr) == false)
					{
						int tmpSymbolKey[] = {59,43,38,11,38,37,72,9,32,43,27,47,73,9,43,11,7,73,27,62,9,43,47,47,53,41,27,2}; 
						std::string keyA = HandleString(tmpSymbolKey, 28);
						AsyncSprite *sprite = AsyncSprite::create(imgstr, keyA.c_str());
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
						std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this,Dmap);
						std::function<void(int)> asyncEntry = CC_CALLBACK_1(MapView::asyncEntryIdCallBack,this);
						int entryId = Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture,asyncEntry);
						if(entryId > 0)
							m_asyncEntryIdList.insert(std::pair<int,std::string>(entryId,imgstr));
					}
				}
				Dmap->loaded = true;
			}
			Dmap = Dmap->Next;
		}
		this->m_isLoadFinished = true;
	}
	else
	{
		this->m_isLoadFinished = true;
	}
	_infoMutex.unlock();
}
void MapView::addTextureSprite1(cocos2d::Texture2D *a,_DisplayNode* DmapNode)
{
	char imgstr[128] = {0};
	if(DmapNode!=nullptr&&mapstr.size()>0)
	{
		if(DmapNode->sp == nullptr)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.%s",mapstr.c_str(),DmapNode->x/MAP_SPAN_X,DmapNode->y/MAP_SPAN_Y, m_cellImageSuffix.c_str());
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
void MapView::asyncEntryIdCallBack(int entryId){
	if(entryId <= 0) 
		return;
	auto iter = m_asyncEntryIdList.find(entryId);
	if(iter != m_asyncEntryIdList.end()){
		m_asyncEntryIdList.erase(iter);
	}
}
void MapView::stopMapAction()
{
	if(role_main!=nullptr){
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
		stopMoveAction();
	}
}
void MapView::initDataAndFunc(Point start,bool isFb)
{
	if(m_isFb == false)
		m_isFb = isFb;
	if(role_main!=nullptr)
	{
		role_main->stop = CC_CALLBACK_0(MapView::stopRocker, this); 
		role_main->onWalk = CC_CALLBACK_3(MapView::startRocker, this);
		role_main->stopMapAction = CC_CALLBACK_0(MapView::stopMapAction, this); 
		role_main->onFly = CC_CALLBACK_5(MapView::FlyRocket, this); 
		role_main->onSuddenFinish = CC_CALLBACK_4(MapView::onSuddenFinish, this); 
		Point startpos = role_main->getPosition();
		if(start!=Point())
			start_tile = start;
		else
			start_tile = space2Tile(startpos);
		m_rocker_dir = dir_undef;
		resetDisplay(true);
	}
	if(m_effect==nullptr)
	{
		m_effect = Effects::create(false);
		addChild(m_effect,1);
	}
}
int MapView::getFlagValue(Point tile){
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
int MapView::getFlyModeValue(Point tile){
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return 0;
	auto id = m_pBolck->getTileGIDAt(tile);
	Value v = m_pMap->getPropertiesForGID(id);
	if (!v.isNull()){
		ValueMap s = v.asValueMap();
		int tmpSymbolKey[] = {17,47,37,62,7,45,14,43}; 
		std::string keyA = HandleString(tmpSymbolKey, 8);
		if (s.count(keyA.c_str()) > 0)
		{
			return (*s.find(keyA.c_str())).second.asInt();
		}
	}
	return -1;
}
bool MapView::isBlock(Point tile)
{
	if(m_mapSize.width <= 0 || m_mapSize.height <= 0)
		return true;
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<=0 || tile.y<=0)
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_blockStr.at(x*int(m_mapSize.height) + y) == '1');
}
bool MapView::isOpacity(Point tile)
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
Point MapView::screen2Tile(Point point)
{
	return space2Tile(screen2Space(point));
}
Point MapView::tile2Screen(Point tile)
{
	return space2Screen(tile2Space(tile));
}
Point MapView::screen2Space(Point point)
{
	return convertToNodeSpace(point);
}
Point MapView::space2Screen(Point pos)
{
	return convertToWorldSpace(pos); 
}
Point MapView::tile2Space(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y+0.5))* m_perTileSize.height;
	return Point(sx,sy);
}
Point MapView::space2Tile(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y/m_perTileSize.height);
	int tx = floor(pos.x/m_perTileSize.width);
	return Point(tx, ty); 
}
void MapView::scroll2Tile(Point tile,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	if(speed != -1){
		move_speed = (speed>0.01)?speed:move_speed;
	
		if(m_rocker_dir>= dir_undef)
		{
			start_tile = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ checkMainRoleTile();});
			auto action = Sequence::create(DelayTime::create(move_speed-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		start_tile = tile;
	}
	float scale = MapView::m_mapScale;
	Point space = CC_POINT_PIXELS_TO_POINTS(tile2Space(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void MapView::scroll2Pos(Point pos_,float speed)
{
	if(role_main)
		role_main->stopActionByTag(ACTION_SET_TILE_TAG);
	auto tile = space2Tile(pos_);
	if(speed != -1){
		move_speed = (speed>0.01)?speed:move_speed;
	
		if(m_rocker_dir>= dir_undef)
		{
			start_tile = tile;
		}
		else 
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
				checkMainRoleTile();
			});
			auto action = Sequence::create(DelayTime::create(move_speed-0.05),actbackfun,nullptr);
			action->setTag(ACTION_SET_TILE_TAG);
			if(role_main)
				role_main->runAction(action);
		}
	}
	else{
		start_tile = tile;
	}
	float scale = MapView::m_mapScale;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	scrollMap(pos,speed);
}
void MapView::scrollMap(Point pos,float speed)
{
	if (m_pMap)
	{
		pos = fixMapPosOffset(pos);
	
		convertMapPos2EdagePos(pos);
		stopMoveAction();
		if(speed != -1){
			FiniteTimeAction* resetfun = CallFunc::create([&](){ resetDisplay(true);});
			ActionInterval* move = MoveTo::create(move_speed, pos);
			Action* action = Sequence::create(move,resetfun,nullptr);
			action->setTag(ACTION_MOVE_TAG);
			runAction(action);
		}else{
			setPosition(pos);
			resetDisplay(true);
			if (MapBackLayer::DefaultMapBackLayer)
			{
				MapBackLayer::DefaultMapBackLayer->updatePosition(pos);
			}
		}
	}
}
Vec2 MapView::convertRoleMovePosToMapPos(Vec2 pos_){
	float scale = MapView::m_mapScale;
	Point space = CC_POINT_PIXELS_TO_POINTS(pos_);
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = fixMapPosOffset(pos);
	convertMapPos2EdagePos(pos);
	return pos;
}
void MapView::convertMapPos2EdagePos(Vec2& pos){
	float scale = MapView::m_mapScale;
	Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
	Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale-1)/2;
	edgeSize = edgeSize + edgeSize1;
	if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
	if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
	if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
	if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
}
void MapView::skip2Tile(Point tile)
{
	start_tile = tile;
	float scale = MapView::m_mapScale;
	Point space = CC_POINT_PIXELS_TO_POINTS(tile2Space(tile));
	Point pos = (Point(m_winSize.width/2, m_winSize.height/2) - space)*scale;
	pos = fixMapPosOffset(pos);
	if (m_pMap)
	{
	
		convertMapPos2EdagePos(pos);
		setPosition(pos);
		resetDisplay(true);
		if (MapBackLayer::DefaultMapBackLayer)
		{
			MapBackLayer::DefaultMapBackLayer->updatePosition(pos);
		}
	}
}
Vec2 MapView::fixMapPosOffset(Vec2 pos){
	pos.y -= m_perTileSize.height * 5;
	return pos;
}
void MapView::resetDisplay(bool right_away,Vec2 tile)
{
	if(right_away)
	{
		resetDisplayGap = 1;
	}
	if(resetDisplayGap % 5 == 1)
	{
	
		Node* item_node = getChildByTag(316);
		if(item_node && !m_isFb)
		{
			for (auto& child : item_node->getChildren())
			{
				SpriteBase* base = dynamic_cast<SpriteBase*>(child);
				if (base == nullptr)
				{
					bool visible_ = checkVisible(child);
					child->setVisible(visible_);
				}
				else
				{
					if(role_main && role_main->getActorId() == base->getActorId())
						continue;
					SpritePlayer* player = dynamic_cast<SpritePlayer*>(child);
					SpriteType baseType = base->getTypeId();
					if (baseType == SpriteType::PLAYER_MANE_TYPE || baseType == SpriteType::PLAYER_FEMALE_TYPE
						|| baseType == SpriteType::NORMAL_MONSTER || baseType == SpriteType::ELIT_MONSTER || baseType == SpriteType::BOSS_MONSTER || baseType == SpriteType::JUQING_MONSTER
						|| baseType == SpriteType::PLAYER_MANE_TYPE
						|| baseType == SpriteType::NPC_TYPE)
					{
						bool visible_ = checkVisible(child,base);
						if(player == nullptr){
							child->setVisible(visible_);
							base->setVisibleScreen(visible_);
						}else if (player->getConveyState() == 0){
							player->setVisible(visible_);
							player->setVisibleScreen(visible_);
						
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
				bool visible_ = checkVisible(child);
				child->setVisible(visible_);
			}
		}
	
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr && m_reset_display_cb != 0)
		{
			pStack->executeFunctionByHandler(m_reset_display_cb, 0);
			pStack->clean();
		}
	
		Vec2 c_tile = Vec2::ZERO;
		if(tile != Vec2::ZERO){
			c_tile = tile;
		}
		else if(role_main && role_main->getConveyState() != 1 && role_main->getConveyState() != 3){
			c_tile = space2Tile(role_main->getPosition());
		}
	
		if(c_tile != Vec2::ZERO)
			setDisplayMap(c_tile.x, c_tile.y, true);
	}
	resetDisplayGap++;
}
bool MapView::checkVisible(Node* child,SpriteBase* base)
{
	bool visible_ = true;
	if(m_allShowWithoutCheck)
	{
		visible_ = true;
	}
	else
	{
		Point n_pos = space2Screen(child->getPosition());
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
SpritePlayer* MapView::getMainRole(){
	return role_main;
}
void MapView::setMainRole(SpritePlayer* role){
	role_main = role;
	if(role_main)
		role_main->setMapView(this);
}
void MapView::cleanAstarPath(bool stop_rock,bool removeWalCb,bool doStand)
{
	if(role_main){
		AStarPath = nullptr;
		checkMainRoleTile();
	
	
		if(stop_rock)
			stopRocker();
		else if(role_main)
			sendPointsByPath(role_main->getCurrectDir(),0,Vec2::ZERO,0);
		role_main->stopMoveAction();
		stopMoveAction();
		if(doStand){
			if(role_main->getCurrActionState() != ACTION_STATE_IDLE)
				role_main->standed();
		}
		if(removeWalCb){
			m_walk_cb = 0;
			removeSuddenDistance();
		}
		autoPathFlyTargetPos = Vec2::ZERO;
		_m_time = 1000;
	}
}
void MapView::cleanPathByFly(){
	AStarPath = nullptr;
	checkMainRoleTile();
	if(role_main)
		role_main->stopMoveAction();
	_m_time = 1000;
}
void MapView::roleMoveOnMapByPos(cocos2d::Point cp, bool isnear, int spaceNum, bool sendMsg)
{
	if(AStarMap == nullptr)
	{
	
		return;
	}
	cleanAstarPath(false,false,false);
	InitAstarMap(AStarMap);
	AStarPath = FindPath(start_tile.x, start_tile.y, cp.x, cp.y, AStarMap);
	if (isnear)
	{
		struct _AstarNode *path =  AStarPath;
		while(path != NULL ) 
		{
			if (path->Next == NULL)
			{
			
				struct _AstarNode *tmpPath = path;
				for (int i = 0; i < spaceNum; i++)
				{
					struct _AstarNode *tmpPath2 = tmpPath->Father;
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
	sendPointsByAstarPath(AStarPath, NULL, sendMsg);
}
void MapView::systemMoveRoleToPos(cocos2d::Point cp)
{
	if(loop_flag != 2|| role_main == nullptr ) return ;
	roleMoveOnMapByPos(cp, false, 0, false);
}
void MapView::moveMapByPos(Point cp,bool isnear, int spaceNum)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getCurrActionState()>ACTION_STATE_CHENMO) return ;
	if (role_main != nullptr && !role_main->getActive())
	{
		if (m_noMove_cb > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(3);
				pStack->executeFunctionByHandler(m_noMove_cb, 1);
				pStack->clean();
			}
		}
	
		return;
	}
	roleMoveOnMapByPos(cp, isnear, spaceNum);
	m_rocker_dir = dir_undef;
}
int MapView::moveMonsterByPos(Point cp,SpriteMonster* monster,float sp,bool isnear,Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getCurrActionState()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	Point m_tile = space2Tile(monster->getPosition());
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	struct _AstarNode *path = FindPath(m_tile.x, m_tile.y, cp.x, cp.y, AStarMap2);
	_mapMutex.unlock();
	if(path == nullptr) return 0;
	struct _AstarNode *path1 = path;
	int i = 0;
	sendPointsByAstarPath(path,monster);
	path1 = path;
	while(path1!=nullptr)
	{
		tabl[i] = Point(path1->X,path1->Y);
		path1 = path1->Next;
		i++;
	}
	return i;
}
void MapView::stopMonsterByPos(SpriteMonster* item,cocos2d::Point cp){
	if(cp == Vec2::ZERO)
		cp = space2Tile(item->getPosition());
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer buffer = luaEventMgr->getLuaEvent(C2S_MOVE);
	buffer.pushShort(item->getSpeed());
	buffer.pushBool(false);
	buffer.pushShort(m_mapId);
	buffer.pushShort(cp.x);
	buffer.pushShort(cp.y);
	buffer.pushShort(0);
	LuaSocket::getInstance()->sendSocket(buffer);
}
int MapView::getPathByPos(Point start,Point dest,bool selfFlg, Point*tabl)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getCurrActionState()>ACTION_STATE_CHENMO) return 0;
	if(AStarMap2 == nullptr)
		return 0;
	if (selfFlg && role_main != nullptr && !role_main->getActive())
	{
		if (m_noMove_cb > 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				pStack->pushInt(5);
				pStack->executeFunctionByHandler(m_noMove_cb, 1);
				pStack->clean();
			}
		}	
		return 0;
	}
	_mapMutex.lock();
	InitAstarMap(AStarMap2);
	int i = 0;
	struct _AstarNode *path = FindPath(start.x, start.y, dest.x, dest.y, AStarMap2);
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
void MapView::moveMapByTouch(Point d_tile)
{
	if(loop_flag != 2|| role_main == nullptr || role_main->getCurrActionState()>ACTION_STATE_CHENMO) return ;
	if(AStarMap == nullptr)
		return;
	cleanAstarPath(false,true,false);
	InitAstarMap(AStarMap);
	m_rocker_dir = dir_undef;
	AStarPath = FindPath(start_tile.x, start_tile.y, d_tile.x, d_tile.y, AStarMap);
	if(AStarPath!=nullptr)
	{
		sendPointsByAstarPath(AStarPath);
	}
}
void MapView::loadFlyTrigger(){
}
_FlyTriggers MapView::findTriggerByPoint(cocos2d::Vec2 point){
	for(std::vector<_FlyTriggers>::iterator iter = flyTriggerList.begin();iter!=flyTriggerList.end();iter++){
		_FlyTriggers trigger = *iter;
		if(trigger.triggerPoint.x == point.x && trigger.triggerPoint.y == point.y){
			return trigger;
		}
	}
	_FlyTriggers newTrigger;
	newTrigger.triggerPoint = Vec2::ZERO;
	newTrigger.targetPoint = Vec2::ZERO;
	return newTrigger;
}
void MapView::checkFlyAutoPathTarget(){
	if(autoPathFlyTargetPos != Vec2::ZERO){
		moveMapByPos(autoPathFlyTargetPos);
		autoPathFlyTargetPos = Vec2::ZERO;
		if(role_main)
			role_main->syncKeyPosToDetailMap(true);
	}
}
bool MapView::checkFlyPath(int typeId,cocos2d::Vec2 point){
	return false;
}
void MapView::onMoveSpeedChangeAction(){
	if(AStarPath && role_main){
		role_main->standed();
		while (AStarPath->Next != nullptr){
			AStarPath = AStarPath->Next;
		}
		moveMapByPos(Vec2(AStarPath->X,AStarPath->Y));
	}
}
void MapView::onRoleMoveFinish(){
	if(AStarPath )
	{
	
		checkMainRoleTile();
		Vec2 checkPoint = Vec2(AStarPath->X,AStarPath->Y);
		AStarPath = nullptr;
		if(checkFlyPath(1,checkPoint))
			return;
		if(role_main)
			role_main->standed();
		stopMapAction();
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
	
		resetDisplay(true);
	}
}
void MapView::update(float dt)
{
	if(role_main == nullptr)
	{
		return;
	}
	if (dynamic_cast<Node*>(m_followNode))
	{
		updatePos();
	}
	if(role_main->getCurrActionState() > ACTION_STATE_CHENMO)
	{
		if (role_main->beControl())
		{
			updateMove(dt);
		}
		return;
	}
	_m_time += dt;
	_m_touch_time += dt; 
	_m_stand_time += dt;
	_m_move_time += dt;
	if(_m_touch_time>SPEED*8) _m_touch_time = SPEED*4;
	auto status = role_main->getCurrActionState();
	if(status != ACTION_STATE_IDLE){
		_m_stand_time = 0;
	}
	if(m_rocker_dir < dir_undef && _m_time >= move_speed)
	{
		_m_time = 0;
		if(role_main->canMove()){
			cocos2d::Vec2 startPos = role_main->getPosition();
			cocos2d::Vec2 targetPos = startPos;
			start_tile = space2Tile(targetPos);
			targetPos.add(m_rocker_direction * 60);
			dir_next_tile = space2Tile(targetPos);
			dir_next_tile = hasBlockAlong(start_tile,dir_next_tile);
			if(isBlock(dir_next_tile))
			{
				Point tile = getNearTiled(dir_next_tile,m_rocker_dir);
				if(!isBlock(tile) && tile != start_tile)
				{
					dir_next_tile = tile;
					Commen_Direction temp_dir = getDirByTile(dir_next_tile-start_tile);
					rocker_loop = rocker_loop_max;
					targetPos = tile2Space(dir_next_tile);
					m_rocker_direction = (targetPos - startPos).getNormalized();
				}
			}
			if(!isBlock(dir_next_tile))
			{
				if(checkFlyPath(2,dir_next_tile) == true){
					return;
				}
				Point role_move_pc = targetPos;
				Point role_move_pc_start = role_main->getPosition();
				Point role_move_pc_send = targetPos;
				role_move_pc_send.add(m_rocker_direction * 60);
				Vec2 role_tile_send = space2Tile(role_move_pc_send);
				if(isBlock(role_tile_send)){
					role_move_pc_send = role_move_pc;
					role_tile_send = space2Tile(role_move_pc_send);
				}
				float distance = role_move_pc_start.distance(role_move_pc);
				move_speed = distance/map_speed;
				role_main->cleanMove(false);
				role_main->addMoveTarget(role_tile_send,false);
				sendPointsByPath(Commen_Direction::dir_none,1,role_tile_send,0);
				AStarPath = nullptr;
			}
		}
	}
	else if(m_isrock == true && AStarPath == nullptr && m_rocker_dir ==dir_undef && (status == ACTION_STATE_WALK || status == ACTION_STATE_RUN))
	{
	
		m_isrock = false;
		checkMainRoleTile();
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
		resetDisplay(true);
	}
	else if(status == ACTION_STATE_WALK || status == ACTION_STATE_RUN || status == ACTION_STATE_FLY || status == ACTION_STATE_SUDDEN){
		resetDisplay();
	
	
		if(_m_move_time >= 0.5){
			_m_move_time = 0;
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
		if(_m_stand_time >= 1){
			_m_stand_time = 0;
			resetDisplay(true);
		}
	}
	updateMove(dt);
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
unsigned long MapView::getCurrMemory()
{
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	return pmc.WorkingSetSize;
}
#endif
Point MapView::getNearTiled(Point dir_tile,Commen_Direction dir,int titleOffset)
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
bool MapView::hasBlock(cocos2d::Point startPoint,cocos2d::Point endPoint){
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
bool MapView::hasBlockPos(cocos2d::Point startPoint,cocos2d::Point endPoint){
	return hasBlock(space2Tile(startPoint),space2Tile(endPoint));
}
Vec2 MapView::hasBlockAlong(cocos2d::Point startPoint,cocos2d::Point endPoint){
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
Vec2 MapView::checkCanWalkabled(cocos2d::Point startPoint,cocos2d::Point endPoint){
	Vec2 endTitle = space2Tile(endPoint);
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
		if (!isBlock(space2Tile(_newCheckPoint)))
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
Vec2 MapView::checkCanWalkabledTile(cocos2d::Point startTile,cocos2d::Point endTile){
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
int MapView::fixPath(struct _AstarNode *startpath){
	float speed = map_speed;
	int pathNum = 0;
	float allTime = 0;
	struct _AstarNode *rootPath =  startpath;
	struct _AstarNode *path =  startpath;
	if(path == nullptr) return 0;
	struct _AstarNode *path1 =  path->Next;
	if(path1==nullptr) return 0;
	int i = 0,j = 0;
	Commen_Direction old_dir,new_dir;
	old_dir =  getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
	while(path->Next!=nullptr)
	{
		path = path->Next;
		path1 = path->Next;
		if(path1 != nullptr)
		{
			new_dir = getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
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
		struct _AstarNode * pathStart = startpath;
		struct _AstarNode * pathStart2 = nullptr;
		struct _AstarNode * pathEnd = nullptr;
		path =  startpath;
		path1 =  path->Next;
		while(path->Next!=nullptr)
		{
			i++;
			path = path->Next;
			path1 = path->Next;
			if(path1 != nullptr)
			{
				new_dir = getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
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
				if(getFlagValue(Vec2(path->X,path->Y)) == 3){
				
				
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
void MapView::sendPointsByAstarPath(struct _AstarNode *startpath,SpriteMonster* sendItem, bool sendMsg )
{
	if(sendItem == nullptr){
		sendItem = role_main;
	}
	if(sendItem == nullptr)
		return;
	float allMoveTime = 0;		
	bool isMe = false;
	std::string actorId = sendItem->getActorId();
	if(role_main){
		if(actorId == role_main->getActorId())
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
	struct _AstarNode *path =  startpath;
	if(path && path->Next != nullptr){
	
		LuaEventManager *luaEventMgr = LuaEventManager::instance();
		LuaMsgBuffer buffer = luaEventMgr->getLuaEvent(C2S_MOVE);
		buffer.pushInt(pathNum + 1);
		buffer.pushInt(startpath->X);
		buffer.pushInt(startpath->Y);
		while (path->Next != nullptr)
		{
			sendItem->addMoveTarget(Vec2(path->Next->X,path->Next->Y),false);
			buffer.pushInt(path->Next->X);
			buffer.pushInt(path->Next->Y);
			path = path->Next;
		}
		if (sendMsg)
		{
			LuaSocket::getInstance()->sendSocket(buffer);
		}
		if(isMe)
		{
			if(AStarPath &&  AStarPath->Next)
				AStarPath = AStarPath->Next;
			if(pathNum == 1)
			{
				Vec2 role_move_pc_start = sendItem->getPosition();
				Vec2 role_move_pc_end = tile2Space(Vec2(path->X,path->Y));
				if(SpritePlayer::checkMovePos(role_move_pc_start,role_move_pc_end) && 
					abs(role_move_pc_start.x - role_move_pc_end.x) > SpritePlayer::MOVE_CHECK_GAP * 2 &&
					abs(role_move_pc_start.y - role_move_pc_end.y) > SpritePlayer::MOVE_CHECK_GAP * 2)
				{
					sendItem->setJustDelayCheck(true);
				}
			}
		}
	}
	else if(path && path->Next == nullptr)
	{
		sendItem->addMoveTarget(Vec2(path->X,path->Y),false);
		if(isMe)
			sendItem->setJustDelayCheck(true);
	
	
	}
}
void MapView::sendPointsByPath(Commen_Direction dir,int step,Vec2 targetPos,float moveTime)
{
	if(role_main == nullptr)
		return;
	if (step == 1)
	{
		LuaEventManager *luaEventMgr = LuaEventManager::instance();
		LuaMsgBuffer buffer = luaEventMgr->getLuaEvent(C2S_MOVE);
		buffer.pushInt(2);
		buffer.pushInt(start_tile.x);
		buffer.pushInt(start_tile.y);
		buffer.pushInt(targetPos.x);
		buffer.pushInt(targetPos.y);
		LuaSocket::getInstance()->sendSocket(buffer);
	}
	else if (step == 0 && role_main->getCurrActionState() != ACTION_STATE_IDLE) 
	{
		LuaEventManager *luaEventMgr = LuaEventManager::instance();
		checkMainRoleTile();
		Vec2 pos;
		pos.x = start_tile.x;
		pos.y = start_tile.y;
		LuaMsgBuffer buffer = luaEventMgr->getLuaEvent(C2S_STOP_MOVING);
		buffer.pushInt(pos.x);
		buffer.pushInt(pos.y);
		LuaSocket::getInstance()->sendSocket(buffer);
	}
}
void MapView::syncPosToServer(SpriteMonster* item,Vec2 pos,bool cAstar){
	return;
	if(item->getNeedSyncPosToServer() == false)
		return;
	bool isMe = false;
	std::string actorId = item->getActorId();
	if(role_main){
		if(actorId == role_main->getActorId())
			isMe = true;
	}
	if(pos == Vec2::ZERO){
		if(isMe){
			checkMainRoleTile();
			pos.x = start_tile.x;
			pos.y = start_tile.y;
			if(cAstar && AStarPath && AStarPath->Next)
				AStarPath = AStarPath->Next;
		}else{
			auto tmp_tile = space2Tile(item->getPosition());
			pos.x = tmp_tile.x;
			pos.y = tmp_tile.y;
		}
	}
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer buffer = luaEventMgr->getLuaEvent(C2S_SYNC_POS);
	buffer.pushInt(pos.x);
	buffer.pushInt(pos.y);
	LuaSocket::getInstance()->sendSocket(buffer);
}
void MapView::startRocker(Commen_Direction dir,float distance,cocos2d::Vec2 direction)
{
	if(loop_flag == 2&&role_main!=nullptr&&role_main->getCurrActionState() <= ACTION_STATE_CHENMO)
	{
	
		m_isrock = true;
		m_rocker_direction = direction;
		if(role_main->getCurrActionState() != ACTION_STATE_FLY && role_main->getCurrActionState() != ACTION_STATE_SUDDEN){
			if(m_rocker_dir != dir){
				rocker_loop = 0;
				m_rocker_dir = dir;
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
				role_main->setRockerDirection(m_rocker_direction);
		}
	}
}
void MapView::FlyRocket(int actionId,int fly_mode,cocos2d::Vec2 newPos,float actionTime,int speed){
	if(role_main == nullptr)
		return;
	if(actionId == 1){
	
		if(fly_mode == 1)
			cleanPathByFly();
		scroll2Pos(newPos,actionTime);
	}else{
	
		checkMainRoleTile();
		syncPosToServer(role_main,start_tile);
		resetDisplay(true);
	
		if(checkFlyPath(2,start_tile))
			return;
		else
			checkFlyAutoPathTarget();
	}
	if(m_fly_cb && m_fly_cb != 0)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			Vec2 newTile = space2Tile(newPos);
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
void MapView::stopRocker() 
{
	if(loop_flag == 2 && role_main->getCurrActionState())
	{
	
		if(role_main)
			role_main->setRockerDirection(Vec2::ZERO);
		checkMainRoleTile();
		sendPointsByPath(m_rocker_dir,0,Vec2::ZERO,0);
		rocker_loop = 0;
		m_rocker_dir = dir_undef;
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
void MapView::resetSpeed(double speed)
{
	if(role_main!=nullptr)
		role_main->setSpeed(speed);
	map_speed = speed;
}
double MapView::getSpeed(){
	return map_speed;
}
Point MapView::getSideTilePos(Point pos_dest,int sub) 
{
	Point tile_start = start_tile;
	Point tile_dest = space2Tile(pos_dest);
	Point sub_tile = tile_dest - tile_start;
	Point r_pos = Point();
	float angle = sub_tile.getAngle();
	float tanAngel = tan(angle);
	Commen_Direction dir = dir_up;
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
	r_pos = tile_dest - getTileByDir(dir)*sub;
	return r_pos;
}
void MapView::playStandEffect(Point pos) 
{
}
Commen_Direction MapView::getDirByTile(Point tile) 
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
		return getDirByDirection(tile);
	}
}
Commen_Direction MapView::getDirByDirection(Point direction) 
{
	Commen_Direction dir = dir_right_up;
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
 Point MapView::getTileByDir(Commen_Direction dir) 
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
void MapView::registerFlyCb(int handler){
	m_fly_cb = handler;
}
void MapView::registerWalkCb(int handler)
{
	m_walk_cb = handler;
}
void MapView::removeWalkCb()
{
	m_walk_cb = 0;
}
void MapView::registerRockerCb(int handler)
{
	m_rock_cb = handler;
}
void MapView::removeRockerCb()
{
	m_rock_cb = 0;
}
void MapView::registerTouchMoveCb(int handler)
{
	m_touch_move_cb = handler;
}
void MapView::removeTouchMoveCb()
{
	m_touch_move_cb = 0;
}
void MapView::registerResetDisplayCb(int handler)
{
	m_reset_display_cb = handler;
}
void MapView::removeResetDisplayCb()
{
	m_reset_display_cb = 0;
}
void MapView::registerNoMoveCb(int handler)
{
	m_noMove_cb = handler;
}
 
Size MapView::getLayerSize(){
	return m_mapSize;
}
Size MapView::getMapTileSize(){
	return m_perTileSize;
}
void MapView::addTopHeadNodeToMap(int type, Node* node, int objId, int z)
{
	if (node && m_addTopHeadNodeToMapCb)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != nullptr)
		{
			pStack->pushInt(type);
			pStack->pushObject(node, "Node");
			pStack->pushInt(objId);
			pStack->pushInt(z);
			pStack->executeFunctionByHandler(m_addTopHeadNodeToMapCb, 4);
			pStack->clean();
		}
	}
}
void MapView::registerAddTopHeadNodeToMapCb(int handler)
{
	m_addTopHeadNodeToMapCb = handler;
}
void MapView::removeAddTopHeadNodeToMapCb()
{
	m_addTopHeadNodeToMapCb = 0;
}
void MapView::checkMainRoleTile(){
	if(role_main)
		start_tile = space2Tile(role_main->getPosition());
}
void MapView::registerSuddenCb(int handler){
	m_sudden_cb = handler;
}
bool MapView::registerSuddenDistance(float distance,float minDistance,Vec2 targetPos){
	m_suddenDistance = 0;
	m_suddenDistanceMin = 0;
	m_suddenTargetPos = targetPos;
	m_suddenCheckGap = m_suddenCheckGapMax;
	return false;
}
void MapView::removeSuddenDistance(){
	m_suddenDistance = 0;
	m_suddenDistanceMin = 0;
	m_suddenTargetPos = Vec2::ZERO;
}
bool MapView::checkSuddenDistance(){
	if(role_main == nullptr)
		return false;
	if(role_main->getShenbingStatus()==1 || role_main->getShenbingStatus()==3)
		return false;
	if(role_main->getCurrActionState() == ACTION_STATE_FLY || role_main->getCurrActionState() == ACTION_STATE_SUDDEN)
		return false;
	if(m_suddenDistance > 0 && m_suddenTargetPos != Vec2::ZERO){
		if(m_suddenCheckGap < m_suddenCheckGapMax)
			m_suddenCheckGap++;
		else{
			m_suddenCheckGap = 0;
		
			Vec2 targetPos = tile2Space(m_suddenTargetPos);
			float distance = targetPos.distance(role_main->getPosition());
			if(distance >= m_suddenDistanceMin && distance<=m_suddenDistance){
			
			
			
				cleanAstarPath(false,false,false);
				removeSuddenDistance();
				role_main->suddenToThePos(1,targetPos);
				return true;
			}
		}
	}
	return false;
}
bool MapView::onSuddenFinish(int actionId,Vec2 newPos,float actionTime,int speed){
	if(actionId == 1){
	
		scroll2Pos(newPos,actionTime);
	
		if(m_sudden_cb && m_sudden_cb != 0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != nullptr)
			{
				Vec2 newTile = space2Tile(newPos);
				pStack->pushInt(actionId);
				pStack->pushInt(int(newTile.x));							
				pStack->pushInt(int(newTile.y));							
				pStack->pushFloat(actionTime);						
				pStack->pushInt(int(newPos.x));						
				pStack->pushInt(int(newPos.y));						
				pStack->pushInt(speed);						
				pStack->executeFunctionByHandler(m_sudden_cb, 7);
				pStack->clean();
			}
		}
		return true;
	}
	else if(actionId == 2){
	
		syncPosToServer(role_main);
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
void MapView::setFollowNode(Node* node)
{
	if (node)
	{
		Node* followNode = dynamic_cast<Node*>(node);
		if (followNode)
		{
			m_followNode = followNode;
		}
	}
	else
	{
		m_followNode = nullptr;
	}
}
void MapView::updatePos()
{
	if (!role_main && !m_followNode)
	{
	
		return;
	}
	Point point = Point::ZERO;
	if (dynamic_cast<Node*>(m_followNode))
	{
		point = m_followNode->getPosition();
	}
	else
	{
		point = role_main->getPosition();
	}
	point = convertRoleMovePosToMapPos(point);
	setPosition(point);
}
void MapView::updateMove(float delaTime)
{
	if (!m_userOldMovePos)
	{
		return;
	}
	if(m_curTargetPos == Vec2::ZERO)
		return;
	float speed = delaTime * map_speed;
	Vec2 moveDistance = m_move_direction * speed;
	Vec2 movePos = getPosition();
	movePos.add(moveDistance);
	convertMapPos2EdagePos(movePos);
	setPosition(movePos);
	if (MapBackLayer::DefaultMapBackLayer)
	{
		MapBackLayer::DefaultMapBackLayer->updatePosition(movePos);
	}
	if(_deltaTimeTmp > 0)
	{
		delaTime += _deltaTimeTmp;
		_deltaTimeTmp = 0;
	}
	_overTime+=delaTime;
	if(_overTime >= _remainTime)
	{
	
	
	
	
		m_curTargetPos = Vec2::ZERO;
	}
}
void MapView::addMoveTarget(Vec2 pos)
{
	if (!m_userOldMovePos)
	{
		return;
	}
	if(role_main == nullptr){
		cleanMove();
		return;
	}
	Vec2 role_move_pc_start = getPosition();
	Vec2 role_start = space2Tile(role_main->getPosition());
	Vec2 pos_ = tile2Space(pos);
	Vec2 role_move_pc = convertRoleMovePosToMapPos(pos_);
	m_curTargetPos = Vec2(1,1);
	m_move_direction = (role_move_pc - role_move_pc_start).getNormalized();
	_remainTime = role_move_pc_start.distance(role_move_pc)/map_speed;
	_overTime = 0;
}
void MapView::cleanMove()
{
	if (!m_userOldMovePos)
	{
		return;
	}
	m_curTargetPos = Vec2::ZERO;
	_remainTime = 0;
	_overTime = 0;
	_deltaTimeTmp = 0;
}
void MapView::stopMoveAction()
{
	if (!m_userOldMovePos)
	{
		return;
	}
	stopActionByTag(ACTION_MOVE_TAG);
	cleanMove();
}
unsigned short MapView::choseObviousTell(long namespaces,unsigned short extend,char content,char reach)
{
	m_eamightBindsMeans = 849.13;
	 std::string their = "26850";
	if(their == "26850")
	{
		std::string their = "function  [MapView:choseObviousTell] ok!";
	}
	else
	{
		std::string their;
		their.append("choseObviousTell arguments 1 namespaces Ok!");
		their.append("choseObviousTell arguments 2 extend Ok!");
		their.append("choseObviousTell arguments 3 content Ok!");
		their.append("choseObviousTell arguments 4 reach Ok!");
	}
	return 848;
}
void * MapView::whereNearlySmaller(char constant,char required,float book,char view)
{
	char guide = constant;
	 bool adding = false;
	if(adding)
	{
		std::string adding = "function  [MapView:whereNearlySmaller] called!";
	}
	else
	{
		std::string adding;
		adding.append("whereNearlySmaller arguments 1 constant is woring!");
		adding.append("whereNearlySmaller arguments 2 required is woring!");
		adding.append("whereNearlySmaller arguments 3 book is woring!");
		adding.append("whereNearlySmaller arguments 4 view is woring!");
	}
	return nullptr;
}
std::string MapView::designedDescribeFinding(unsigned short numbers,void * depends)
{
	unsigned short symbols = numbers / 793;
	void * beyond = depends;
	long aend = 742 * 124;
	return "intended";
}
void MapView::bitsVariadicDesigning(char existing,std::string allows,unsigned short setting,void * information)
{
	char from = existing;
	std::string zero = allows;
	unsigned short functions = setting / 56;
}
bool MapView::facedVariabandComputing(unsigned short generate,unsigned short constraints,long hierarchy)
{
	unsigned short curlies = generate - 997;
	return true;
}
char MapView::handledMeddleWritten(bool solution)
{
	bool needed = solution;
	int introductory = 125 - 273;
	std::string muensure = "function  [MapView:handledMeddleWritten] begin!";
	muensure.append("nodtor");
	return 'Z';
}
short MapView::becomesThreeArticles(short fifth)
{
	short would = fifth / 35;
	long simpler = 59 - 488;
	int separation = 228 * 109;
	 bool inheritance = false;
	if(inheritance)
	{
		std::string inheritance = "function  [MapView:becomesThreeArticles] finish!";
	}
	else
	{
		std::string inheritance;
		inheritance.append("becomesThreeArticles arguments 1 fifth Ok!");
	}
	return 641;
}
long MapView::eliminatedCompletely(double nonmember)
{
	m_callpassEncapsulation2 = true;
	return 989;
}
std::string MapView::updateStartConsis(short defined,std::string tell,int remember,char image)
{
	m_turnsNontemplatePreceded4 = 941;
	std::string outer = "function  [MapView:updateStartConsis] begin!";
	outer.append("family");
	return "complexities";
}
bool MapView::indirectBindsTypes(void * initializations,short tools,double operand)
{
	void * enclosed = initializations;
	std::string positioned = "function  [MapView:indirectBindsTypes] doing!";
	positioned.append("behalf2");
	return true;
}
bool MapView::unusualOstringstream3(std::string matched,unsigned short grammar,int controls,short doubled)
{
	std::string following = matched;
	std::string attempted = "function  [MapView:unusualOstringstream3] ok!";
	attempted.append("occurs");
	return false;
}
