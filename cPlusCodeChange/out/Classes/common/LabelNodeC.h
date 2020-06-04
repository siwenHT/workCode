#ifndef _LABEL_NODE_C_H_
#define _LABEL_NODE_C_H_
#include "cocos2d.h"
USING_NS_CC;
class LabelNodeC : public cocos2d::Node
{
public:
	LabelNodeC();
	virtual ~LabelNodeC(void);
	static LabelNodeC* create(bool isSystemFont);
	bool init(bool isSystemFont);
	CC_SYNTHESIZE(bool, m_is_system_font, IsSystemFont);
	CC_SYNTHESIZE(Label*, m_label, LabelChild);
	void setAdditionalKerning(float fontMargin);
	void setDimensions(float width,float height);
	void setString(std::string content);
	std::string getString();
	void setHorizontalAlignment(TextHAlignment hAlignmen);
	void setVerticalAlignment(TextVAlignment vAlignment);
	void setLineBreakWithoutSpace(bool breakWithoutSpace);
	void setMaxLineWidth(float width);
	void setSystemFontSize(float fontsize);
	void setColor(const Color3B& color);
	const Color3B& getColor();
	void setOutLineSize(float size);
	void setOutLineColor(const Color4B& outlineColor);
private:
public:
static	std::string intendedUnlessShowsEasy(char specifier,std::string executed,char builds,unsigned short aside); 
static	void * scopeSynonymPreventing(char unnecessary,bool four,short trivial,int realizing); 
static	bool doesImagefifthLinkage(unsigned short ordinary,std::string freed); 
	std::string referencesHigherEqual(std::string muensure,void * fails,std::string initial); 
static	std::string applyTransactioDenoting1(char previous); 
	std::string resetReasonOperateTrans(double preprocessor,void * recompiling,void * conceptually); 
static	short kidsExceptionsThird(unsigned short full,short functional); 
	char referencesThanDebugging(unsigned short types,short range); 
	void * independentComponents(char topics,short across,void * taking,bool essentially); 
	int throwsDetailReading(float across,short argument,bool good); 
	long compilingIgnoreEnds(short doing,long focus); 
	unsigned short implementUnchanged(unsigned short interaction,float covering,std::string programs,short ends); 
private:
	long m_needDesigningReverses;
	unsigned short m_pointerlikeDenote;
	int m_controllingAssignmenclick;
	short m_messageEvenIterates;
	long m_previouslySuobjects;
};
#endif
