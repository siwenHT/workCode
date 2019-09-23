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
	long yieldActsStructure(char then,float rewrites); 
	unsigned short operandsDistinctFocus(bool minimal,long functiopresented); 
	double reportTpreviousAhead(char separately,long here,int omit,float represented); 
	float relyBehalfDereferences1(double next); 
	double presumablyAssignThink(bool partno); 
	long throwsMatchIobj(long making,char differs,int translate); 
	bool recursiveStayArrow(unsigned short identification); 
static	long nonconstArrayImagefifth(int briefly); 
	unsigned short contentAboveThdefines(unsigned short stack,long until); 
private:
	long m_stayAsfifthHairChoice;
	short m_calledThenComplexity;
	void * m_heldExtensioindicating;
};
#endif
