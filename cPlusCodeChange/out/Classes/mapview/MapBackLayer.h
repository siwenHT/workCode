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
static	void * strcmpIntroductoryItas(int inlined); 
	int specializationAlgorithms(unsigned short nonpointer,short doing); 
static	char definitionThemExit5(unsigned short manager,void * limit); 
	char knownMenuApplicable(unsigned short should); 
	bool definitionsPresented(std::string aside); 
	int fallModifyList(long owhich,unsigned short initially,long type,short enumerations); 
	float convertedSwappedTaking(unsigned short want); 
	int personExhasuting(std::string stringth,char find,double full,char exhasuting); 
private:
	short m_instantiationSource;
	long m_initializtheReside;
	long m_wordsRefersPointed;
};
#endif