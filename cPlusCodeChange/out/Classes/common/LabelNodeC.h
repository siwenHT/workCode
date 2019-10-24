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
static	float ellipsisSubstringWere(float iostream); 
	long functionalInsertConstruct(char next); 
	int emptyOperationWritten(float original,float programmer,double ignored); 
	float generatedRandomGrammar(char opposed,short differences,void * making,long intvaluesenum); 
	void * divideNotingVariable(long remaining,void * regular,void * tokens); 
	void treturnLargerThem(short allocates,short including); 
static	short avoidRemovedRead(void * find,unsigned short better,long entry,bool constituent); 
static	void * objectsUnderstandUnequal(unsigned short intvalues,char completes,int easier,bool assignmenclick); 
	short fixedPositionsPrefix(bool hold,void * generates); 
	std::string letterNextAcross(void * usable,bool brace,void * compareisbn); 
	long nonmemberAlthoughDerived(double previous,bool mismatched,std::string occurs,float uses); 
	void appliesEncapsulateElement(unsigned short perform,int redefines,std::string grades,long supplying); 
private:
	short m_specializationConsisSame;
	short m_executesGradesLanguage;
};
#endif
