#include "LabelNodeC.h"

using namespace std;  

LabelNodeC::LabelNodeC()
{
	m_is_system_font = false;
	m_label = nullptr;
}
LabelNodeC::~LabelNodeC(void)
{
}

LabelNodeC* LabelNodeC::create(bool isSystemFont)
{
	LabelNodeC *pRet = new LabelNodeC();
    if (pRet && pRet->init(isSystemFont))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}

bool LabelNodeC::init(bool isSystemFont){
	m_is_system_font = isSystemFont;
	return true;
}

void LabelNodeC::setAdditionalKerning(float fontMargin){
	if(m_label == nullptr)
		return;
	m_label->setAdditionalKerning(fontMargin);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setDimensions(float width,float height){
	if(m_label == nullptr)
		return;
	m_label->setDimensions(width,height);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setString(std::string content){
	if(m_label == nullptr)
		return;
	m_label->setString(content);
	this->setContentSize(m_label->getContentSize());
}

std::string LabelNodeC::getString(){
	if(m_label == nullptr)
		return "";
	return m_label->getString();
}

void LabelNodeC::setHorizontalAlignment(TextHAlignment hAlignmen){
	if(m_label == nullptr)
		return;
	m_label->setHorizontalAlignment(hAlignmen);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setVerticalAlignment(TextVAlignment vAlignment){
	if(m_label == nullptr)
		return;
	m_label->setVerticalAlignment(vAlignment);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setLineBreakWithoutSpace(bool breakWithoutSpace){
	if(m_label == nullptr)
		return;
	m_label->setLineBreakWithoutSpace(breakWithoutSpace);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setMaxLineWidth(float width){
	if(m_label == nullptr)
		return;
	m_label->setDimensions(width,0);
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setSystemFontSize(float fontsize){
	if(m_label == nullptr)
		return;
	if(m_is_system_font){
		m_label->setSystemFontSize(fontsize);
	}else{
		cocos2d::TTFConfig config = m_label->getTTFConfig();
		config.fontSize = fontsize;
		m_label->setTTFConfig(config);
	}
	this->setContentSize(m_label->getContentSize());
}

void LabelNodeC::setColor(const Color3B& color){
	if(m_label == nullptr)
		return;
	m_label->setColor(color);
}

const Color3B& LabelNodeC::getColor(){
	if(m_label == nullptr)
		return Color3B::BLACK;
	return m_label->getColor();
}

void LabelNodeC::setOutLineSize(float size){

}

void LabelNodeC::setOutLineColor(const Color4B& outlineColor){

}





