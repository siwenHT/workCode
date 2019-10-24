#ifndef  __MapBackLayer_H__
#define  __MapBackLayer_H__
#include "cocos2d.h"
class MapBackLayer : public cocos2d::Layer
{
public :
	MapBackLayer();
	~MapBackLayer();
	static MapBackLayer* create();
	bool loadBack(const std::string& filename, const int mapId);
	void updatePosition(const cocos2d::Vec2& position);
	CC_SYNTHESIZE(float, m_speedRate, SpeedRate); 
public :
	static MapBackLayer* DefaultMapBackLayer;
private :
	cocos2d::Sprite* m_back;  
public:
	std::string includeNextOptionsUseful(void * reduce); 
	float convenientInitialization5(char relational); 
	void independentlyInevitably(bool pointer,int avoid,double behalf,std::string detail); 
static	long indexIntegralAdvantages(unsigned short implementing,short loop); 
static	long gavePrintsFlagEquals(short limited,float pairwise,int care); 
	float basicsAllocatesIsbns(bool preventing); 
private:
	double m_specializesContained3;
};
#endif