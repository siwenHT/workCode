#include "stackInput.h"
using namespace std;  
stackInput::stackInput()
{
	m_attentionInstantiations = false;
	m_label = nullptr;
}
stackInput::~stackInput(void)
{
}
stackInput* stackInput::create(bool isSystemFont)
{
	stackInput *pRet = new stackInput();
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
bool stackInput::init(bool isSystemFont){
	m_attentionInstantiations = isSystemFont;
	return true;
}
void stackInput::setAdditionalKerning(float fontMargin){
	if(m_label == nullptr)
		return;
	m_label->setAdditionalKerning(fontMargin);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setDimensions(float width,float height){
	if(m_label == nullptr)
		return;
	m_label->setDimensions(width,height);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setString(std::string content){
	if(m_label == nullptr)
		return;
	m_label->setString(content);
	this->setContentSize(m_label->getContentSize());
}
std::string stackInput::getString(){
	if(m_label == nullptr)
		return "";
	return m_label->getString();
}
void stackInput::setHorizontalAlignment(TextHAlignment hAlignmen){
	if(m_label == nullptr)
		return;
	m_label->setHorizontalAlignment(hAlignmen);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setVerticalAlignment(TextVAlignment vAlignment){
	if(m_label == nullptr)
		return;
	m_label->setVerticalAlignment(vAlignment);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setLineBreakWithoutSpace(bool breakWithoutSpace){
	if(m_label == nullptr)
		return;
	m_label->setLineBreakWithoutSpace(breakWithoutSpace);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setbackCoveredPointers(float width){
	if(m_label == nullptr)
		return;
	m_label->setDimensions(width,0);
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setSystemFontSize(float fontsize){
	if(m_label == nullptr)
		return;
	if(m_attentionInstantiations){
		m_label->setSystemFontSize(fontsize);
	}else{
		cocos2d::TTFConfig config = m_label->getTTFConfig();
		config.fontSize = fontsize;
		m_label->setTTFConfig(config);
	}
	this->setContentSize(m_label->getContentSize());
}
void stackInput::setColor(const Color3B& color){
	if(m_label == nullptr)
		return;
	m_label->setColor(color);
}
const Color3B& stackInput::getColor(){
	if(m_label == nullptr)
		return Color3B::BLACK;
	return m_label->getColor();
}
void stackInput::setnearlyDealingReplacement(float size){
}
void stackInput::setcallSerialWestoreChoice(const Color4B& outlineColor){
}

char stackInput::designsDereferences(void * none)
{
	long another;
	another = 658;
	short purposes;
	purposes = 126;
	short tightly;
	tightly = 994;
	return 'J';
}
long stackInput::smartIostreamConceptually(double synonym,bool major)
{
	unsigned short mark;
	mark = 325;
	char group;
	group = 'f';
	float definitions;
	definitions = 815.8f;
	long explain;
	explain = 952;
	bool computing;
	computing = true;
	return 755;
}
int stackInput::nestHighPasses(long separation,float standard,short rewrite,int typeids)
{
	long cursor;
	cursor = 662;
	bool printed;
	printed = false;
	return 404;
}
double stackInput::computeImportanceDoes4(void * five,int easier)
{
	long cmatch;
	cmatch = 637;
	void * executed;
	executed = nullptr;
	return 74.11;
}
int stackInput::changingOstreamSelects(int forgot,float level)
{
	float iterates;
	iterates = 282.18f;
	return 215;
}
double stackInput::consisSeparatedDeduced5(int difficult,void * instantion,bool whole,unsigned short large)
{
	short ceases;
	ceases = 390;
	return 583.1;
}
char stackInput::complicatedReadingThrough5(unsigned short convention,char incidental,long algorithm,long aside)
{
	float reading;
	reading = 397.4f;
	void * referencesth;
	referencesth = nullptr;
	return 'R';
}
double stackInput::mutuallyGuaranteed(float expects,long warrant)
{
	unsigned short preceded;
	preceded = 167;
	long exhausted;
	exhausted = 828;
	bool element;
	element = true;
	unsigned short contract;
	contract = 39;
	return 479.1;
}
