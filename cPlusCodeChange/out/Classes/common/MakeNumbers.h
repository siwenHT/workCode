#include "cocos2d.h"
USING_NS_CC;
class MakeNumbers : public cocos2d::Node
{
public:
	MakeNumbers();
	virtual ~MakeNumbers(void);
	static MakeNumbers* create(const std::string&pszFileName,int attckmun,int span,bool symbol = false,bool cacheAll = false);
	static MakeNumbers* createWithSymbol(const std::string&pszFileName,int attckmun,int span,bool symbol = true,bool cacheAll = false);
	bool init(const std::string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll);
	void setAttackNum(int attackNum,int span = 10000);	
	int getWidth();
	int getHeight();
protected:
	Sprite* getCacheNum(int num);
private:
	std::map<int,std::vector<Sprite*>*> m_numsCache;			
	std::vector<Sprite*> m_showNums;
	std::string pszFileName;
	float allwight;
	float allheight;
	float num_count;
	int span;
	bool symbol;
	float onewight;
	float oneheight;
	float numWidth;
};
