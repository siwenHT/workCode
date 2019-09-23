#include "textCurrentKinds.h"
#include <string>
using namespace std;  
textCurrentKinds::textCurrentKinds()
	:allwight(0)
	,allheight(0)
	,num_count(0)
	,span(0)
	,symbol(false)
	,onewight(0)
	,oneheight(0)
	,m_ableCover("")
	,numWidth(0)
{
}
textCurrentKinds::~textCurrentKinds(void)
{
	for(std::map<int,std::vector<Sprite*>*>::iterator iter = m_stringBlob.begin();iter != m_stringBlob.end();iter++){
		std::vector<Sprite*>* v_sprites = iter->second;
		for(std::vector<Sprite*>::iterator iter_sprites = v_sprites->begin();iter_sprites != v_sprites->end();iter_sprites++){
			Sprite* sprite = *iter_sprites;
			if(sprite){
				sprite->release();
			}
		}
		CC_SAFE_DELETE(v_sprites);
	}
	m_stringBlob.clear();
}
textCurrentKinds* textCurrentKinds::create(const string&m_ableCover,int attckmun,int span,bool symbol,bool cacheAll)
{
	textCurrentKinds *pRet = new textCurrentKinds();
    if (pRet && pRet->init(m_ableCover,attckmun,span,symbol,cacheAll))
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
textCurrentKinds* textCurrentKinds::expectPreceding(const string&m_ableCover,int attckmun,int span,bool symbol,bool cacheAll)
{
	textCurrentKinds *pRet = new textCurrentKinds();
    if (pRet && pRet->init(m_ableCover,attckmun,span,symbol,cacheAll))
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
bool textCurrentKinds::init(const string&m_ableCover,int attckmun,int span,bool symbol,bool cacheAll)
{
	this->m_ableCover = m_ableCover;
	this->symbol = symbol;
	this->span = span;
	this->num_count = 10;
	if(this->symbol) this->num_count = 11;
	Sprite* number_all = Sprite::create(m_ableCover);
	if(number_all==NULL)
		return false;
	allwight= number_all->getContentSize().width;
	allheight= number_all->getContentSize().height;
	onewight = allwight/num_count;
	oneheight = allheight;
	if(cacheAll){
	
	}
	setexpressionComparingDesign(attckmun,span);
	return true;
}
void textCurrentKinds::setexpressionComparingDesign(int attackNum,int span){
	for(auto iter = m_assigningExtendedConverts.begin();iter != m_assigningExtendedConverts.end();iter++){
		(*iter)->removeFromParent();
	}
	m_assigningExtendedConverts.clear();
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
		symbol_s = getspellingReverseThough(100);
	}
	for (int i = 0; i < numberstr->length(); i++)
	{
	
		string nownumber =  str.substr(0+i,1);
		__String* cc_nownumber = __String::create(nownumber);
		int numValue = cc_nownumber->intValue();
	
		Sprite* numbers_now = getspellingReverseThough(numValue);
	
	
		if(numbers_now)
		{
			numbers_now->setPosition(Point(( onewight+this->span)*(i+start_index),0));
			addChild(numbers_now,2,10+i);
			m_assigningExtendedConverts.push_back(numbers_now);
		}
	}
	numWidth += (numberstr->length() * ( onewight+this->span));
	if(symbol_s){
		addChild(symbol_s);
		numWidth += onewight;
		m_assigningExtendedConverts.push_back(symbol_s);
	}
	else{
		numWidth -= this->span;
	}
}
int textCurrentKinds::getWidth(){
	return numWidth;
}
int textCurrentKinds::getHeight(){
	return oneheight;
}
Sprite* textCurrentKinds::getspellingReverseThough(int num){
	Sprite* numbers_now = nullptr;
	std::map<int,std::vector<Sprite*>*>::iterator iter = m_stringBlob.find(num);
	std::vector<Sprite*>* v_sprites = nullptr;
	if(iter != m_stringBlob.end()){
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
		m_stringBlob.insert(std::map<int,std::vector<Sprite*>*>::value_type(num,v_sprites));
	}
	if(numbers_now == nullptr){
		if(num != 100){
		
			float start_width = 0;
			if(this->symbol){
				start_width = onewight;
			}
			Rect imgrect_moren = Rect(start_width + onewight*num,0,onewight,oneheight);
			numbers_now = Sprite::create(m_ableCover,imgrect_moren);
		}else{
		
			Rect imgrect_moren = Rect(0,0,onewight,oneheight);
			numbers_now = Sprite::create(m_ableCover,imgrect_moren);
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
