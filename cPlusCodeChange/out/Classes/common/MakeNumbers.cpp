#include "MakeNumbers.h"
#include "JIGUsers_ComplexityCtr.h"
#include <string>
using namespace std;  
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
bool MakeNumbers::init(const string&pszFileName,int attckmun,int span,bool symbol,bool cacheAll)
{
	this->pszFileName = pszFileName;
	this->symbol = symbol;
	this->span = span;
	this->num_count = 10;
	if(this->symbol) this->num_count = 11;
	Sprite* number_all = Sprite::create(pszFileName);
	if(number_all==NULL)
		return false;
	allwight= number_all->getContentSize().width;
	allheight= number_all->getContentSize().height;
	onewight = allwight/num_count;
	oneheight = allheight;
	if(cacheAll){
	
	}
	setAttackNum(attckmun,span);
	return true;
}
void MakeNumbers::setAttackNum(int attackNum,int span){
	for(auto iter = m_showNums.begin();iter != m_showNums.end();iter++){
		(*iter)->removeFromParent();
	}
	m_showNums.clear();
	if(span != 10000) this->span = span;
	char char_attckmun[64] = {0};
	sprintf(char_attckmun,"%d",attackNum);
	__String* numberstr = __String::create(char_attckmun);
	string str = numberstr->getCString();
	int start_index = 0;
	Sprite* symbol_s = nullptr;
	numWidth = 0;
	if(this->symbol){
	
		start_index = 1;
		symbol_s = getCacheNum(100);
	}
	for (int i = 0; i < numberstr->length(); i++)
	{
	
		string nownumber =  str.substr(0+i,1);
		__String* cc_nownumber = __String::create(nownumber);
		int numValue = cc_nownumber->intValue();
	
		Sprite* numbers_now = getCacheNum(numValue);
	
	
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
	JIGUsers_ComplexityCtr jigusers_complexityctr_e;
	jigusers_complexityctr_e.chosenDiskStoplight(348.13f,47.20,858.18f,306);

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
	
		v_sprites = new std::vector<Sprite*>();
		m_numsCache.insert(std::map<int,std::vector<Sprite*>*>::value_type(num,v_sprites));
	}
	if(numbers_now == nullptr){
		if(num != 100){
		
			float start_width = 0;
			if(this->symbol){
				start_width = onewight;
			}
			Rect imgrect_moren = Rect(start_width + onewight*num,0,onewight,oneheight);
			numbers_now = Sprite::create(pszFileName,imgrect_moren);
		}else{
		
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
