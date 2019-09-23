#ifndef  __MapBackLayer_H__
#define  __MapBackLayer_H__
#include "cocos2d.h"

/**
* 地图背景滚动层
*
*/
class MapBackLayer : public cocos2d::Layer
{
public :
	MapBackLayer();
	~MapBackLayer();

	static MapBackLayer* create();
	bool loadBack(const std::string& filename, const int mapId);

	void updatePosition(const cocos2d::Vec2& position);

	CC_SYNTHESIZE(float, m_speedRate, SpeedRate); // 相当示主角速度倍率
public :
	static MapBackLayer* DefaultMapBackLayer;

private :
	cocos2d::Sprite* m_back;  // 背景
};

#endif