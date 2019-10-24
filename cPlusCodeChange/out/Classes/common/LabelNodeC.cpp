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

float LabelNodeC::ellipsisSubstringWere(float iostream)
{
	float promotes = iostream * 235.4f;
	void * distinctive = nullptr;
	return 704.3f;
}
long LabelNodeC::functionalInsertConstruct(char next)
{
	m_executesGradesLanguage = 624;
	std::string akin = "function  [LabelNodeC:functionalInsertConstruct] finish!";
	akin.append("compute");
	return 146;
}
int LabelNodeC::emptyOperationWritten(float original,float programmer,double ignored)
{
	float should = original * 266.13f;
	float arrarecall = programmer + 205.7f;
	double prompt = ignored - 568.2;
	std::string about = "function  [LabelNodeC:emptyOperationWritten] end!";
	about.append("want2");
	return 652;
}
float LabelNodeC::generatedRandomGrammar(char opposed,short differences,void * making,long intvaluesenum)
{
	char results = opposed;
	short smaller = differences + 288;
	 std::string returning = "9482";
	if(returning == "9482")
	{
		std::string returning = "function  [LabelNodeC:generatedRandomGrammar] doing!";
	}
	else
	{
		std::string returning;
		returning.append("generatedRandomGrammar arguments 1 opposed is ok?!");
		returning.append("generatedRandomGrammar arguments 2 differences is ok?!");
		returning.append("generatedRandomGrammar arguments 3 making is ok?!");
		returning.append("generatedRandomGrammar arguments 4 intvaluesenum is ok?!");
	}
	return 87.20f;
}
void * LabelNodeC::divideNotingVariable(long remaining,void * regular,void * tokens)
{
	long these = remaining % 467;
	return nullptr;
}
void LabelNodeC::treturnLargerThem(short allocates,short including)
{
	m_executesGradesLanguage = 744;
}
short LabelNodeC::avoidRemovedRead(void * find,unsigned short better,long entry,bool constituent)
{
	void * begun = find;
	return 203;
}
void * LabelNodeC::objectsUnderstandUnequal(unsigned short intvalues,char completes,int easier,bool assignmenclick)
{
	unsigned short indexing = intvalues / 573;
	char accumulate = completes;
	int reused = easier + 341;
	std::string whyou = "function  [LabelNodeC:objectsUnderstandUnequal] calling!";
	whyou.append("skip");
	return nullptr;
}
short LabelNodeC::fixedPositionsPrefix(bool hold,void * generates)
{
	bool marker = hold;
	void * tedious = generates;
	 int labels = 42539;
	if(labels == 42539)
	{
		std::string labels = "function  [LabelNodeC:fixedPositionsPrefix] end!";
	}
	else
	{
		std::string labels;
		labels.append("fixedPositionsPrefix arguments 1 hold Ok!");
		labels.append("fixedPositionsPrefix arguments 2 generates Ok!");
	}
	return 15;
}
std::string LabelNodeC::letterNextAcross(void * usable,bool brace,void * compareisbn)
{
	void * containing = usable;
	 int hold = 2255;
	if(hold == 2255)
	{
		std::string hold = "function  [LabelNodeC:letterNextAcross] doing!";
	}
	else
	{
		std::string hold;
		hold.append("letterNextAcross arguments 1 usable Error!");
		hold.append("letterNextAcross arguments 2 brace Error!");
		hold.append("letterNextAcross arguments 3 compareisbn Error!");
	}
	return "tells";
}
long LabelNodeC::nonmemberAlthoughDerived(double previous,bool mismatched,std::string occurs,float uses)
{
	double strblob = previous + 457.17;
	 int oriented = 75607;
	if(oriented == 75607)
	{
		std::string oriented = "function  [LabelNodeC:nonmemberAlthoughDerived] ok!";
	}
	else
	{
		std::string oriented;
		oriented.append("nonmemberAlthoughDerived arguments 1 previous is woring!");
		oriented.append("nonmemberAlthoughDerived arguments 2 mismatched is woring!");
		oriented.append("nonmemberAlthoughDerived arguments 3 occurs is woring!");
		oriented.append("nonmemberAlthoughDerived arguments 4 uses is woring!");
	}
	return 615;
}
void LabelNodeC::appliesEncapsulateElement(unsigned short perform,int redefines,std::string grades,long supplying)
{
	unsigned short instantiating = perform * 540;
	int redeclares = redefines % 21;
	std::string parametersunlike = "function  [LabelNodeC:appliesEncapsulateElement] begin!";
	parametersunlike.append("sections");
}
