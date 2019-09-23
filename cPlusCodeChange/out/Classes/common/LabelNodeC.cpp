#include "LabelNodeC.h"
#include "usedDesign.h"
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

long LabelNodeC::yieldActsStructure(char then,float rewrites)
{
	char easier = then;
	float sufficiently = rewrites + 370.17f;
	long compute = 845 % 129;
	return 750;
}
unsigned short LabelNodeC::operandsDistinctFocus(bool minimal,long functiopresented)
{
	bool tree = minimal;
	long whole = functiopresented + 383;
	return 152;
}
double LabelNodeC::reportTpreviousAhead(char separately,long here,int omit,float represented)
{
	usedDesign useddesign_e;
	useddesign_e.designingActsCompanion(127,true,68,322);

	m_heldExtensioindicating = nullptr;
	return 876.6;
}
float LabelNodeC::relyBehalfDereferences1(double next)
{
	double resulting = next + 626.13;
	long flag = 181 * 658;
	char looth = '2';
	return 866.8f;
}
double LabelNodeC::presumablyAssignThink(bool partno)
{
	bool theare = partno;
	double relational = 425.12 - 238.12;
	short whversion = 667 / 915;
	return 248.14;
}
long LabelNodeC::throwsMatchIobj(long making,char differs,int translate)
{
	long brown = making % 578;
	char lookup = differs;
	return 156;
}
bool LabelNodeC::recursiveStayArrow(unsigned short identification)
{
	unsigned short nontype = identification - 455;
	return false;
}
long LabelNodeC::nonconstArrayImagefifth(int briefly)
{
	int numbers = briefly * 770;
	unsigned short missing = 886 + 919;
	return 677;
}
unsigned short LabelNodeC::contentAboveThdefines(unsigned short stack,long until)
{
	unsigned short nature = stack + 693;
	long versions = until + 989;
	return 310;
}
