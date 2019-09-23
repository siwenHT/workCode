#include "ideaDelegates.h"
USING_NS_CC;
ideaDelegates::ideaDelegates()
{
	m_objectsEntireThexercises = true;
	m_convertingFrontSection = NULL;
	termsExpects = NULL;
	m_scale = 0;
}
ideaDelegates::~ideaDelegates(void)
{
}
ideaDelegates* ideaDelegates::create(const std::string& normalImage)
{
    return ideaDelegates::create(normalImage,(const ccMenuCallback&)nullptr);
}
ideaDelegates* ideaDelegates::create(const std::string& normalImage,const ccMenuCallback& callback)
{
	ideaDelegates* ret = new ideaDelegates();
    if (ret && ret->initWithNormalImage(normalImage, "", "", callback))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}
void  ideaDelegates::setImages(const std::string& normalImage)
{
	 setNormalImage(Sprite::create(normalImage));
	 setSelectedImage(Sprite::create(normalImage));
}
void  ideaDelegates::setcodeFullyException(Action* action)
{
	m_convertingFrontSection = action;
}
void  ideaDelegates::setassumeManageLittle(Action* action)
{
	termsExpects = action;
}
void ideaDelegates::selected()
{
	if(m_scale < 0.001)
		m_scale = this->getScale();
	MenuItemImage::selected();
	if(m_convertingFrontSection == NULL)
	{
		if(m_objectsEntireThexercises)
			runAction(ScaleTo::create(0.15,1.10*m_scale));
		else
			runAction(ScaleTo::create(0.15,0.85*m_scale));
	}
	else
	{
	
	}
}
void ideaDelegates::unselected()
{
	MenuItemImage::unselected();
	if(m_convertingFrontSection == NULL)
	{
		if(m_objectsEntireThexercises)
			runAction(Sequence::create(ScaleTo::create(0.15,0.85*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
		else
			runAction(Sequence::create(ScaleTo::create(0.15,1.1*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
	}
	else
	{
	
	}
}
