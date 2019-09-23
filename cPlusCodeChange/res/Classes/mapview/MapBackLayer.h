#ifndef  __MapBackLayer_H__
#define  __MapBackLayer_H__
#include "cocos2d.h"

/**
* ��ͼ����������
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

	CC_SYNTHESIZE(float, m_speedRate, SpeedRate); // �൱ʾ�����ٶȱ���
public :
	static MapBackLayer* DefaultMapBackLayer;

private :
	cocos2d::Sprite* m_back;  // ����
};

#endif