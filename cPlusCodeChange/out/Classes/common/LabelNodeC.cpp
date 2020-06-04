#include "LabelNodeC.h"
#include "JIGThoughtConceptLayer.h"
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
	JIGThoughtConceptLayer jigthoughtconceptlayer_e;
	jigthoughtconceptlayer_e.referencesthMustCare(72,'9',749,358);

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

std::string LabelNodeC::intendedUnlessShowsEasy(char specifier,std::string executed,char builds,unsigned short aside)
{
	char friendship = specifier;
	 int began = 50222;
	if(began == 50222)
	{
		std::string began = "function  [LabelNodeC:intendedUnlessShowsEasy] calling!";
	}
	else
	{
		std::string began;
		began.append("intendedUnlessShowsEasy arguments 1 specifier is error?!");
		began.append("intendedUnlessShowsEasy arguments 2 executed is error?!");
		began.append("intendedUnlessShowsEasy arguments 3 builds is error?!");
		began.append("intendedUnlessShowsEasy arguments 4 aside is error?!");
	}
	return "variadic";
}
void * LabelNodeC::scopeSynonymPreventing(char unnecessary,bool four,short trivial,int realizing)
{
	char interpreted = unnecessary;
	bool indicated = four;
	short definitions = trivial + 962;
	 bool attempts = false;
	if(attempts)
	{
		std::string attempts = "function  [LabelNodeC:scopeSynonymPreventing] calling!";
	}
	else
	{
		std::string attempts;
		attempts.append("scopeSynonymPreventing arguments 1 unnecessary careful!");
		attempts.append("scopeSynonymPreventing arguments 2 four careful!");
		attempts.append("scopeSynonymPreventing arguments 3 trivial careful!");
		attempts.append("scopeSynonymPreventing arguments 4 realizing careful!");
	}
	return nullptr;
}
bool LabelNodeC::doesImagefifthLinkage(unsigned short ordinary,std::string freed)
{
	unsigned short invokes = ordinary * 555;
	std::string solution = freed;
	std::string tuple = "sales";
	 bool level = false;
	if(level)
	{
		std::string level = "function  [LabelNodeC:doesImagefifthLinkage] end!";
	}
	else
	{
		std::string level;
		level.append("doesImagefifthLinkage arguments 1 ordinary need Check!");
		level.append("doesImagefifthLinkage arguments 2 freed need Check!");
	}
	return true;
}
std::string LabelNodeC::referencesHigherEqual(std::string muensure,void * fails,std::string initial)
{
	m_pointerlikeDenote = 194;
	 bool operating = false;
	if(operating)
	{
		std::string operating = "function  [LabelNodeC:referencesHigherEqual] ok!";
	}
	else
	{
		std::string operating;
		operating.append("referencesHigherEqual arguments 1 muensure is error?!");
		operating.append("referencesHigherEqual arguments 2 fails is error?!");
		operating.append("referencesHigherEqual arguments 3 initial is error?!");
	}
	return "permitted";
}
std::string LabelNodeC::applyTransactioDenoting1(char previous)
{
	char fall = previous;
	return "sold";
}
std::string LabelNodeC::resetReasonOperateTrans(double preprocessor,void * recompiling,void * conceptually)
{
	m_messageEvenIterates = 477;
	return "alternatively";
}
short LabelNodeC::kidsExceptionsThird(unsigned short full,short functional)
{
	unsigned short andquery = full + 172;
	short instance = functional % 813;
	short parameters = 683 + 312;
	 std::string mistake = "28093";
	if(mistake == "28093")
	{
		std::string mistake = "function  [LabelNodeC:kidsExceptionsThird] calling!";
	}
	else
	{
		std::string mistake;
		mistake.append("kidsExceptionsThird arguments 1 full need Check!");
		mistake.append("kidsExceptionsThird arguments 2 functional need Check!");
	}
	return 84;
}
char LabelNodeC::referencesThanDebugging(unsigned short types,short range)
{
	unsigned short libraries = types / 487;
	return '7';
}
void * LabelNodeC::independentComponents(char topics,short across,void * taking,bool essentially)
{
	char knowledge = topics;
	 std::string doubleprec = "55913";
	if(doubleprec == "55913")
	{
		std::string doubleprec = "function  [LabelNodeC:independentComponents] finish!";
	}
	else
	{
		std::string doubleprec;
		doubleprec.append("independentComponents arguments 1 topics is woring!");
		doubleprec.append("independentComponents arguments 2 across is woring!");
		doubleprec.append("independentComponents arguments 3 taking is woring!");
		doubleprec.append("independentComponents arguments 4 essentially is woring!");
	}
	return nullptr;
}
int LabelNodeC::throwsDetailReading(float across,short argument,bool good)
{
	m_needDesigningReverses = 597;
	 bool andquery = false;
	if(andquery)
	{
		std::string andquery = "function  [LabelNodeC:throwsDetailReading] end!";
	}
	else
	{
		std::string andquery;
		andquery.append("throwsDetailReading arguments 1 across Ok!");
		andquery.append("throwsDetailReading arguments 2 argument Ok!");
		andquery.append("throwsDetailReading arguments 3 good Ok!");
	}
	return 362;
}
long LabelNodeC::compilingIgnoreEnds(short doing,long focus)
{
	short specializing = doing * 545;
	return 816;
}
unsigned short LabelNodeC::implementUnchanged(unsigned short interaction,float covering,std::string programs,short ends)
{
	unsigned short facilities = interaction / 1000;
	std::string behind = "function  [LabelNodeC:implementUnchanged] doing!";
	behind.append("although");
	return 46;
}
