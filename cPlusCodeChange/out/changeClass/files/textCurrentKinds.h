#include "cocos2d.h"
USING_NS_CC;
class textCurrentKinds : public cocos2d::Node
{
public:
	textCurrentKinds();
	virtual ~textCurrentKinds(void);
	static textCurrentKinds* create(const std::string&m_ableCover,int attckmun,int span,bool symbol = false,bool cacheAll = false);
	static textCurrentKinds* expectPreceding(const std::string&m_ableCover,int attckmun,int span,bool symbol = true,bool cacheAll = false);
	bool init(const std::string&m_ableCover,int attckmun,int span,bool symbol,bool cacheAll);
	void setexpressionComparingDesign(int attackNum,int span = 10000);	
	int getWidth();
	int getHeight();
protected:
	Sprite* getspellingReverseThough(int num);
private:
	std::map<int,std::vector<Sprite*>*> m_stringBlob;			
	std::vector<Sprite*> m_assigningExtendedConverts;
	std::string m_ableCover;
	float allwight;
	float allheight;
	float num_count;
	int span;
	bool symbol;
	float onewight;
	float oneheight;
	float numWidth;
};
