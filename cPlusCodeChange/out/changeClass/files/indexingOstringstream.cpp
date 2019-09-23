#include "indexingOstringstream.h"
USING_NS_CC;
indexingOstringstream::indexingOstringstream()
{
	assumesPreventingDeclare = true;
	m_essentialBotherReview = NULL;
	m_preventInfrequently = NULL;
	m_scale = 0;
}
indexingOstringstream::~indexingOstringstream(void)
{
}
indexingOstringstream* indexingOstringstream::create(const std::string& normalImage)
{
    return indexingOstringstream::create(normalImage,(const ccMenuCallback&)nullptr);
}
indexingOstringstream* indexingOstringstream::create(const std::string& normalImage,const ccMenuCallback& callback)
{
	indexingOstringstream* ret = new indexingOstringstream();
    if (ret && ret->initWithNormalImage(normalImage, "", "", callback))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}
void  indexingOstringstream::setImages(const std::string& normalImage)
{
	 setNormalImage(Sprite::create(normalImage));
	 setSelectedImage(Sprite::create(normalImage));
}
void  indexingOstringstream::sethashPointerIndeedMovement4(Action* action)
{
	m_essentialBotherReview = action;
}
void  indexingOstringstream::setbecauseProblemThenReady(Action* action)
{
	m_preventInfrequently = action;
}
void indexingOstringstream::selected()
{
	if(m_scale < 0.001)
		m_scale = this->getScale();
	MenuItemImage::selected();
	if(m_essentialBotherReview == NULL)
	{
		if(assumesPreventingDeclare)
			runAction(ScaleTo::create(0.15,1.10*m_scale));
		else
			runAction(ScaleTo::create(0.15,0.85*m_scale));
	}
	else
	{
	
	}
}
void indexingOstringstream::unselected()
{
	MenuItemImage::unselected();
	if(m_essentialBotherReview == NULL)
	{
		if(assumesPreventingDeclare)
			runAction(Sequence::create(ScaleTo::create(0.15,0.85*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
		else
			runAction(Sequence::create(ScaleTo::create(0.15,1.1*m_scale),ScaleTo::create(0.05,1.0*m_scale),NULL));
	}
	else
	{
	
	}
}
