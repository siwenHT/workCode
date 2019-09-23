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
};

#endif

