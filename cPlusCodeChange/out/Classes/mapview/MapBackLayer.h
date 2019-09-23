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
	void * functionalthoughMarkSplit(float select); 
	char distinctiveAheadAccording(unsigned short file,long results); 
	bool datsuchLiteralsHence(short propagates); 
	bool asfifthSimpleOkayVerify(char mube,float assignmenclick,long evaluated,char vice); 
	double listthExhaustedVersus(char initialization,void * care); 
	bool unchangedExpandingMacro(int detail,float trans,int adaptors); 
	void simplerSectionsCopying(float parameteth); 
	long actuasizeExpressionas(void * ways,long modern); 
	void interpretedPreventedWhose(unsigned short updates,short subset); 
	long informationLength(char deal,unsigned short begin,unsigned short overloaded,long substring); 
private:
	bool m_checkEvaluatedDetailSees;
};
#endif