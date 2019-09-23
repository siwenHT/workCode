#ifndef  __SCENE_VIEW_H__
#define  __SCENE_VIEW_H__


//#include "FindPath.h"
#include "cocos2d.h"
#include "SpritePlayer.h"
#include "CCEffects.h"
#include <queue>
#include <thread>
#define PI				3.14159
#define SPEED				0.1f

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

//#ifndef min
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
//#endif

#define CC_CALLBACK_4(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,std::placeholders::_4, ##__VA_ARGS__)
#define CC_CALLBACK_5(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,std::placeholders::_4,std::placeholders::_5, ##__VA_ARGS__)

struct _DisplayNode
{
	unsigned int x, y;					// F, G值
	unsigned int tag;			// 父亲指针
	cocos2d::Sprite* sp;
	bool Status;				// false:不显示  true:显示
	bool loaded;				// false:不显示  true:显示
	struct _DisplayNode *Next;			// OpenList中下一个节点
};

struct _FlyTriggers{
	cocos2d::Vec2 triggerPoint;						//触发点
	cocos2d::Vec2 targetPoint;						//目标位置
};

class MapView : public cocos2d::Layer
{
public:
	MapView();
	virtual ~MapView();

	//创建一个场景层
	static MapView *create();
	static MapView *create(const std::string& filename, const int mapId, const bool isMultiMap, const cocos2d::Point pos = cocos2d::Point());
	static float getMapScale() { return m_mapScale; };
	static void setMapScale(float _scale);// { m_mapScale = _scale; };
	static void preAsyncLoadImg(std::string mapStr, int posX, int posY, int spanX = 30, int spanY = 30);
	void loadSpritesPre();
	void setScale(float scale) override;
	//该tile位置是否阻挡  1和4表示阻档
	bool isBlock(cocos2d::Point tile);
	//该tile位置是否透明
	bool isOpacity(cocos2d::Point tile);	
	//该tileFlag值
	int getFlagValue(cocos2d::Point tile);
	//该tile fly_mode值
	int getFlyModeValue(cocos2d::Point tile);
	cocos2d::Size getLayerSize();
	cocos2d::Size getMapTileSize();

	//屏幕坐标转空间坐标
	cocos2d::Point screen2Space(cocos2d::Point point);
	//空间坐标转屏幕坐标
	cocos2d::Point space2Screen(cocos2d::Point pos);

	//屏幕坐标转tile坐标
	cocos2d::Point screen2Tile(cocos2d::Point point);
	//tile坐标转屏幕坐标
	cocos2d::Point tile2Screen(cocos2d::Point tile);

	//tile坐标转空间坐标
	cocos2d::Point tile2Space(cocos2d::Point tile);
	//空间坐标转tile坐标
	cocos2d::Point space2Tile(cocos2d::Point pos);

	//tile坐标转位置坐标
	//cocos2d::Point tile2Point(cocos2d::Point tile);

	//滚屏到指定tile为中心的位置
	void scroll2Tile(cocos2d::Point tile,float speed = 0.0f);
	void scroll2Pos(cocos2d::Point pos,float speed = 0.0f);

	void skip2Tile(cocos2d::Point tile);

	//返回场景layer Size
	cocos2d::Size getMapSize() { return m_mapSize; }

	//添加或者移除全地图加载地图ID
	void updateAllAddMapId(int mapId,bool remove = false);
	//检查地图Id是否在全地图加载列表当中
	bool checkMapIdInAllAdd(int mapId);
	void setMapSpan(int span_x,int span_y);

	//获取寻路对象
	//AStarFinder* getPathFinder() { return &m_pathFinder; }
	cocos2d::Vec2 fixMapPosOffset(cocos2d::Vec2 pos);
	void roleMoveOnMapByPos(cocos2d::Point cp, bool isnear = false, int spaceNum = 1, bool sendMsg = true);
	void systemMoveRoleToPos(cocos2d::Point cp);
	void moveMapByTouch(cocos2d::Point t);
	void moveMapByPos(cocos2d::Point cp,bool isnear = false, int spaceNum = 1);
	void moveMapByPath(float dt);
	int moveMonsterByPos(cocos2d::Point cp,SpriteMonster*,float sp = 3.0,bool isnear = true,cocos2d::Point*tabl = NULL);
	void stopMonsterByPos(SpriteMonster* item,cocos2d::Point cp = Vec2::ZERO);
	void update(float dt);

	//cocos2d::Point roleMoveInDirection(Commen_Direction dir);
	Commen_Direction getDirByTile(cocos2d::Point tile) ;
	Commen_Direction getDirByDirection(cocos2d::Point direction) ;
	cocos2d::Point getTileByDir(Commen_Direction dir);

	void startRocker(Commen_Direction dir, float distance,cocos2d::Vec2 direction);
	void stopRocker();
	void resetSpeed(double distance);
	double getSpeed();
	cocos2d::Point getSideTilePos(cocos2d::Point,int);

	void FlyRocket(int actionId,int fly_mode,cocos2d::Vec2 newPos,float actionTime,int speed);

	//CC_SYNTHESIZE(SpritePlayer*, role_main, MainRole);
	SpritePlayer* getMainRole();
	void setMainRole(SpritePlayer* role);
	void addTextureSprite1(cocos2d::Texture2D *a,_DisplayNode* DmapNode);
	void asyncEntryIdCallBack(int entryId);
	void cleanAsync();
	virtual void cleanup() override;

	void initDataAndFunc(cocos2d::Point start = cocos2d::Point(),bool isFb=false);
	void initMapData(float time);
	void addMapSprites(std::vector<_DisplayNode*> list);
	void newAstar();
	void newAstar2();
	bool hasBlock(cocos2d::Point startPoint,cocos2d::Point endPoint);
	bool hasBlockPos(cocos2d::Point startPoint,cocos2d::Point endPoint);
	Vec2 hasBlockAlong(cocos2d::Point startPoint,cocos2d::Point endPoint);
	cocos2d::Vec2 checkCanWalkabled(cocos2d::Point startPoint,cocos2d::Point endPoint);
	cocos2d::Vec2 checkCanWalkabledTile(cocos2d::Point startTile,cocos2d::Point endTile);
	int fixPath(struct _AstarNode *startpath);
	bool checkFlyPath(int typeId,cocos2d::Vec2 point);
	void checkFlyAutoPathTarget();
	void syncPosToServer(SpriteMonster* item,Vec2 pos = Vec2::ZERO,bool cAstar = false);
	void sendPointsByPath(Commen_Direction dir,int step,Vec2 targetPos,float moveTime);
	void sendPointsByAstarPath(struct _AstarNode *startpath,SpriteMonster* monster = NULL, bool sendMsg = true);
	void registerFlyCb(int handler);
	void registerWalkCb(int handler);
	void registerRockerCb(int handler);
	void registerTouchMoveCb(int handler);
	void registerResetDisplayCb(int handler);
	void registerNoMoveCb(int handler);

	void removeWalkCb();
	void removeTouchMoveCb();
	void removeRockerCb();
	void removeResetDisplayCb();
	
	void registerSuddenCb(int handler);
	bool registerSuddenDistance(float distance,float minDistance,Vec2 targetPos);
	void removeSuddenDistance();
	bool checkSuddenDistance();
	bool onSuddenFinish(int actionId,Vec2 newPos,float actionTime,int speed);

	void cleanAstarPath(bool stop = false,bool removeWalCb = true,bool doStand = true);
	void cleanPathByFly();

	void onMoveSpeedChangeAction();							//移动速度改变时，重新移动

	cocos2d::Point getNearTiled( cocos2d::Point dir_tile,Commen_Direction dir,int titleOffset=1);
	float getLeftTime(){ return (move_speed-_m_time);};
	void stopMapAction();
	int getPathByPos(cocos2d::Point start,cocos2d::Point dest,bool selfFlg, cocos2d::Point*t);
	bool loadMap(const std::string& tmxFile,const std::string& resFile, const int mapId, const bool isMultiMap, const cocos2d::Point pos = cocos2d::Point());
	void loadMapStr(const std::string tmxFile);
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		unsigned long getCurrMemory();
	#endif
	bool isLoadFinished(int AstarNum = 0);
	void setIsLoadFinished(bool isNoRes){m_isNoRes = isNoRes;}
	void setIsResReady(bool isReady){m_resReady = isReady;}
	bool checkMapCellIsDownloaded(std::string key_value);
	void checkMainRoleTile();
	std::thread *load_Thread;
	std::thread *load_Thread1;
	std::thread *load_Thread2;
	std::thread *load_Thread3;
	bool m_thread_quit;
	bool m_isActive;
	bool m_isNoRes;
	bool m_resReady;

	CC_SYNTHESIZE(int, resetDisplayGap, ResetDisplayGap);
	void resetDisplay(bool right_away = false,Vec2 tile = Vec2::ZERO);
	bool checkVisible(Node* child,SpriteBase* base = nullptr);

	CC_SYNTHESIZE(bool, m_isrock, IsRock);
	CC_SYNTHESIZE(bool, m_userOldMovePos, UserOldMoveMap);

	void loadFlyTrigger();
	_FlyTriggers findTriggerByPoint(cocos2d::Vec2 point);

	void addTopHeadNodeToMap(int type, Node* node, int objId, int z);
	void registerAddTopHeadNodeToMapCb(int handler);
	void removeAddTopHeadNodeToMapCb();

	void onRoleMoveFinish();

	void updatePos();                                       //新的地图移动逻辑
	void setFollowNode(Node* node);

	void updateMove(float delaTime);						//移动循环
	void addMoveTarget(Vec2 pos);							//添加移动目标点
	void cleanMove();										//停止移动
	void stopMoveAction();
	Vec2 convertRoleMovePosToMapPos(Vec2 pos_);
	void convertMapPos2EdagePos(Vec2& pos);
private:
	void tickCache(float dt);
	void addCacheSpritesPre();
	//void addMapSpritesPre();
	void scrollMap(cocos2d::Point pos,float speed = 0.0f);
	void playStandEffect(cocos2d::Point pos) ;
	void setDisplayMap(int x,int y,bool updateShow = false);
	bool getDisplayStatus(int x,int y,int x1,int y1);
	//bool getDisplayStatus_ex(int x,int y,int x1,int y1);
public:
	int m_noMove_cb;
	static float m_mapScale;
	static MapView* DefaultMapView;
private:
	cocos2d::Size			m_mapSize;
	cocos2d::Size			m_winSize;
	cocos2d::Size			m_perTileSize;

	cocos2d::TMXTiledMap*	m_pMap;
	cocos2d::TMXLayer*		m_pBolck;
	std::string             m_blockStr;

	cocos2d::Vec2 m_curTargetPos;							//当前要行径的目标点
	float _remainTime;										//当前路径所需时间
	float _overTime;										//当前路径经历过的时间
	float _deltaTimeTmp;

	int loop_flag;
	bool loadall;
	bool auto_download;								//是否自动下载地图切块
	struct _AstarNode *AStarMap;
	struct _AstarNode *AStarMap2;
	struct _AstarNode *AStarPath;

	bool m_allShowWithoutCheck;						//场景中的地图切块全部创建和显示，场景中的全部物体显示
	int MAP_SPAN_X;
	int MAP_SPAN_Y;

	//struct _DisplayNode *DisplayMap;

	cocos2d::Point start_tile;
	cocos2d::Point dir_next_tile;
	//cocos2d::Point dir_temp_tile;
	Commen_Direction m_rocker_dir;
	cocos2d::Vec2 m_rocker_direction;
	cocos2d::Vec2 m_move_direction;
	Commen_Direction m_dir;

	float m_suddenDistance;
	float m_suddenDistanceMin;
	Vec2 m_suddenTargetPos;
	int m_suddenCheckGap;
	int m_suddenCheckGapMax;

	float map_speed;
	float move_speed;
	float _m_time;
	float _m_touch_time;
	float _m_stand_time;
	float _m_move_time;
	int m_steps;
	bool m_isFb;
	Effects *m_effect;
	int rocker_loop;
	int rocker_loop_max;
	int m_fly_cb;
	int m_sudden_cb;
	int m_walk_cb;
	int m_rock_cb;
	int m_touch_move_cb;
	int m_reset_display_cb;
	int m_mapId;
	bool m_isLoadFinished;
	bool m_isAstar1Finished;
	bool m_isAstar2Finished;
	SpritePlayer* role_main;
	cocos2d::Point role_pos;
	//std::string mapstr;
	cocos2d::Size win;

	//全地图加载 地图ID列表
	std::vector<int> m_map_allAdd;
	std::vector<std::string> m_mapTextureList;				//已加载的地图切块纹理路径列表

	cocos2d::Vec2 autoPathFlyTargetPos;
	std::vector<_FlyTriggers> flyTriggerList;

	int m_addTopHeadNodeToMapCb;

	float testParam;
	std::unordered_map<int,std::string> m_asyncEntryIdList;

	std::string m_cellImageSuffix;

	Node* m_followNode;
};	

#endif