#include "MakeNumbers.h"
//#include "../ImagePaths.h"
#include <string>
using namespace std;  
/*
这个类主要是显示组合自定义图片类型的伤害数值。
*/

MakeNumbers::MakeNumbers()
	:allwight(0)
	,allheight(0)
	,num_count(0)
	,span(0)
	,symbol(false)
	,onewight(0)
	,oneheight(0)
	,pszFileName("")
	,numWidth(0)
{
}
MakeNumbers::~MakeNumbers(void)
{
	//释放缓存的资源
	for(std::map<int,std::vector<Sprite*>*>::iterator iter = m_numsCache.begin();iter != m_numsCache.end();iter++){
		std::vector<Sprite*>* v_sprites = iter->second;
		for(std::vector<Sprite*>::iterator iter_sprites = v_sprites->begin();iter_sprites != v_sprites->end();iter_sprites++){
			Sprite* sprite = *iter_sprites;
			if(sprite){
				sprite->release();
			}
		}
		CC_SAFE_DELETE(v_sprites);
	}
	m_numsCache.clear();
}

MakeNumbers* MakeNumbers::create(const string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll)
{

	MakeNumbers *pRet = new MakeNumbers();
	
    if (pRet && pRet->init(pszFileName,attckmun,span,symbol,cacheAll))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

MakeNumbers* MakeNumbers::createWithSymbol(const string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll)
{

	MakeNumbers *pRet = new MakeNumbers();
	
    if (pRet && pRet->init(pszFileName,attckmun,span,symbol,cacheAll))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

//处理10个字符大小的图片
bool MakeNumbers::init(const string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll)
{
	this->pszFileName = pszFileName;
	this->symbol = symbol;
	this->span = span;
	this->num_count = 10;
	if(this->symbol) this->num_count = 11;
	//获取整张素材图片，图片内容为-0123456789或0123456789；
	Sprite* number_all = Sprite::create(pszFileName);
	if(number_all==NULL)
		return false;
	//获取整张图片长宽
	allwight= number_all->getContentSize().width;
	allheight= number_all->getContentSize().height;
	//获取单张图片长宽
	onewight = allwight/num_count;
	oneheight = allheight;
	if(cacheAll){
		//创建所有显示字符的精灵Cache
	}
	setAttackNum(attckmun,span);

	return true;
}

//处理11个字符的图片
//bool MakeNumbers::initSymbol(const string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll)
//{
//	//解析数值转化为2中格式字符串string和CCString；
//	char char_attckmun[64] = {0};
//	sprintf(char_attckmun,"%d",attckmun);
//	//这个主要用途拿来作为字符和int之间的相互转换
//	__String* numberstr = __String::create(char_attckmun);
//	//这个拿来截取字符
//	string str = numberstr->getCString();
//	
//	//获取整张素材图片，图片内容为-0123456789；
//	Sprite* number_all = Sprite::create(pszFileName);
//	if(number_all==NULL)
//		return false;
//	//获取整张图片长宽
//	float allwight= number_all->getContentSize().width;
//	float allhigth= number_all->getContentSize().height;
//	//获取单张图片长宽
//	float onewight = allwight/11;
//	float onehigth = allhigth;
//	//获取第一个符号扣血-作为首张图片的底图
//	Rect imgrect_moren = Rect(0,0,onewight,onehigth);
//	Sprite* numbers = Sprite::create(pszFileName,imgrect_moren);
//	if(numbers==NULL)
//		return false;
//	//循环解析出“-”符号号后面的具体数值伤害
//	for (int i = 0; i < numberstr->length(); i++)
//	{
//		//依次解析每个数值大小
//		string nownumber =  str.substr(0+i,1);
//		__String* cc_nownumber = __String::create(nownumber);
//		//将解析数值去寻找图片
//		Rect imgrect_moren = Rect(onewight*cc_nownumber->intValue()+onewight,0,onewight,onehigth);
//		Sprite* numbers_now = Sprite::create(pszFileName,imgrect_moren);
//		//将得到的图片依次尾追在“-”图片得后面
//		if(numbers_now)
//		{
//			numbers_now->setPosition(Point(( onewight+span)*(i+1),0));
//			addChild(numbers_now,2,10+i);
//		}
//	}
//	if(symbol == true)
//		addChild(numbers);
//	return true;
//}

void MakeNumbers::setAttackNum(int attackNum,int span){
	//检测缓存的精灵，如果有父亲，将其从父亲移除
	//for(std::map<int,std::vector<Sprite*>*>::iterator iter = m_numsCache.begin();iter != m_numsCache.end();iter++){
	//	std::vector<Sprite*>* v_sprites = iter->second;
	//	for(std::vector<Sprite*>::iterator iter_sprites = v_sprites->begin();iter_sprites != v_sprites->end();iter_sprites++){
	//		Sprite* sprite = *iter_sprites;
	//		if(sprite->getParent()){
	//			sprite->removeFromParent();
	//		}
	//	}
	//}
	for(auto iter = m_showNums.begin();iter != m_showNums.end();iter++){
		(*iter)->removeFromParent();
	}
	m_showNums.clear();
	if(span != 10000) this->span = span;
	//解析数值转化为2中格式字符串string和CCString；
	char char_attckmun[64] = {0};
	sprintf(char_attckmun,"%d",attackNum);
	//这个主要用途拿来作为字符和int之间的相互转换
	__String* numberstr = __String::create(char_attckmun);
	//这个拿来截取字符
	string str = numberstr->getCString();
	//计算起始位置
	int start_index = 0;
	Sprite* symbol_s = nullptr;
	numWidth = 0;
	if(this->symbol){
		//如果标识为真，则需重新计算数字的起始偏移位置，及创建初始标识
		start_index = 1;
		symbol_s = getCacheNum(100);
	}
	for (int i = 0; i < numberstr->length(); i++)
	{
		//依次解析每个数值大小
		string nownumber =  str.substr(0+i,1);
		__String* cc_nownumber = __String::create(nownumber);
		int numValue = cc_nownumber->intValue();
		//将解析数值去寻找图片
		Sprite* numbers_now = getCacheNum(numValue);
		//Rect imgrect_moren = Rect(onewight*cc_nownumber->intValue()+onewight,0,onewight,oneheight);
		//Sprite* numbers_now = Sprite::create(pszFileName,imgrect_moren);
		if(numbers_now)
		{
			numbers_now->setPosition(Point(( onewight+this->span)*(i+start_index),0));
			addChild(numbers_now,2,10+i);

			m_showNums.push_back(numbers_now);
		}
	}
	numWidth += (numberstr->length() * ( onewight+this->span));
	if(symbol_s){
		addChild(symbol_s);
		numWidth += onewight;

		m_showNums.push_back(symbol_s);
	}
	else{
		numWidth -= this->span;
	}
}

int MakeNumbers::getWidth(){
	return numWidth;
}
int MakeNumbers::getHeight(){
	return oneheight;
}

Sprite* MakeNumbers::getCacheNum(int num){
	Sprite* numbers_now = nullptr;

	std::map<int,std::vector<Sprite*>*>::iterator iter = m_numsCache.find(num);
	std::vector<Sprite*>* v_sprites = nullptr;
	if(iter != m_numsCache.end()){
		v_sprites = iter->second;
		for(std::vector<Sprite*>::iterator iter_sprites = v_sprites->begin();iter_sprites != v_sprites->end();iter_sprites++){
			Sprite* sprite_temp = *iter_sprites;
			if(sprite_temp->getParent() == nullptr){
				numbers_now = sprite_temp;
				break;
			}
		}
	}else{
		//创建对应数字的Vector
		v_sprites = new std::vector<Sprite*>();
		m_numsCache.insert(std::map<int,std::vector<Sprite*>*>::value_type(num,v_sprites));
	}
	//缓存中没有，则创建
	if(numbers_now == nullptr){
		if(num != 100){
			//创建普通数字
			float start_width = 0;
			if(this->symbol){
				start_width = onewight;
			}
			Rect imgrect_moren = Rect(start_width + onewight*num,0,onewight,oneheight);
			numbers_now = Sprite::create(pszFileName,imgrect_moren);
		}else{
			//创建标识
			Rect imgrect_moren = Rect(0,0,onewight,oneheight);
			numbers_now = Sprite::create(pszFileName,imgrect_moren);
		}
		if(numbers_now)
		{
			numbers_now->retain();
			v_sprites->push_back(numbers_now);
		}
	}
	if(numbers_now){
		numbers_now->setScale(1);
		numbers_now->setVisible(true);
		numbers_now->setOpacity(255);
		numbers_now->setAnchorPoint(Vec2(0,0.5));
	}
	return numbers_now;
}



