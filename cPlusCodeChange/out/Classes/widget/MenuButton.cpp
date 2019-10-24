#include "MenuButton.h"
#include "JIGCompilersTildeMG.h"
USING_NS_CC;
MenuButton::MenuButton()
{
	m_smalltobig = true;
	m_select_action = NULL;
	m_unselect_action = NULL;
	m_scale = 0;
}
MenuButton::~MenuButton(void)
{
}
MenuButton* MenuButton::create(const std::string& normalImage)
{
    return MenuButton::create(normalImage,(const ccMenuCallback&)nullptr);
}
MenuButton* MenuButton::create(const std::string& normalImage,const ccMenuCallback& callback)
{
	MenuButton* ret = new MenuButton();
    if (ret && ret->initWithNormalImage(normalImage, "", "", callback))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}
void  MenuButton::setImages(const std::string& normalImage)
{
	 setNormalImage(Sprite::create(normalImage));
	 setSelectedImage(Sprite::create(normalImage));
}
void  MenuButton::setSelectAction(Action* action)
{
	m_select_action = action;
}
void  MenuButton::setUnSelectAction(Action* action)
{
	JIGCompilersTildeMG jigcompilerstildemg_e;
	jigcompilerstildemg_e.overallDifficultGrammar(890.0,'H',418,true);

	m_unselect_action = action;
}
void MenuButton::selected()
{
	if(m_scale < 0.001)
		m_scale = this->getScale();
	MenuItemImage::selected();
	if(m_select_action == NULL)
	{
		if(m_smalltobig)
			runAction(ScaleTo::create(0.15,1.10*m_scale));
		else
			runAction(ScaleTo::create(0.15,0.85*m_scale));
	}
	else
	{
	
	}
}
void MenuButton::unselected()
{
	MenuItemImage::unselected();
	if(m_select_action == NULL)
	{
		if(m_smalltobig)
			runAction(Sequence::create(ScaleTo::create(0.15,0.85*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
		else
			runAction(Sequence::create(ScaleTo::create(0.15,1.1*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
	}
	else
	{
	
	}
}
