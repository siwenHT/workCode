#include "AsyncSprite.h"
#include "AsyncDownloadManager.h"
#include "vsdef.h"
USING_NS_CC;
AsyncSprite::AsyncSprite()
:m_state(NORMAL)
,m_customlistener(nullptr)
{
	int tmpSymbolKey[] = {59,43,38,11,38,55,73,14,45,20,53,27,72,2}; 
	m_defaultFileName = HandleString(tmpSymbolKey, 14);
}
AsyncSprite::~AsyncSprite(){
	if (m_customlistener)
	{
		_eventDispatcher->removeEventListener(m_customlistener);
		m_customlistener = nullptr;
	}
}
AsyncSprite* AsyncSprite::create(const std::string pszFileName,const std::string defaultFileName){
	AsyncSprite *sprite = new (std::nothrow) AsyncSprite();
	if (sprite && sprite->initAsync(pszFileName,defaultFileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
bool AsyncSprite::initAsync(const std::string filename,const std::string defaultFileName){
	m_pszFileName = filename;
	if(defaultFileName != "" && FileUtils::getInstance()->isFileExist(defaultFileName)){
		m_defaultFileName = defaultFileName;
	}
	else{
	
	}
	std::string showPath = m_pszFileName;
	if(!FileUtils::getInstance()->isFileExist(showPath)){
	
	
	
	
		showPath = m_defaultFileName;
		m_state = WAITDOWNLOAD;
		m_customlistener = _eventDispatcher->addCustomEventListener(m_pszFileName.c_str(), [this](EventCustom* event){
		
		
		
		
			_eventDispatcher->removeEventListener(m_customlistener);
			m_customlistener = nullptr;
			m_state = NORMAL;
			addCacheSprites();
		});
		AsyncDownloadManager::getInstance()->addJob(m_pszFileName,nullptr);
	}
	return initWithFile(showPath);
}
void AsyncSprite::addCacheSprites(){
	if(m_state == WAITDOWNLOAD) return;
	std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(AsyncSprite::addTextureSprite,this);
	Director::getInstance()->getTextureCache()->addImageAsync(m_pszFileName,addTexture);
}
void AsyncSprite::addTextureSprite(cocos2d::Texture2D *a){
    if(a != nullptr)
        setTexture(a);
	Director::getInstance()->getTextureCache()->removeTextureForKey(m_pszFileName);
}

int AsyncSprite::readersEqualsImplement(char supported)
{
	m_instantiateHeightSmatch = "tell";
	 int letting = 52323;
	if(letting == 52323)
	{
		std::string letting = "function  [AsyncSprite:readersEqualsImplement] doing!";
	}
	else
	{
		std::string letting;
		letting.append("readersEqualsImplement arguments 1 supported careful!");
	}
	return 471;
}
char AsyncSprite::numbersLargerLooking(unsigned short rewrite,float articles,double larger)
{
	unsigned short preserve = rewrite - 331;
	float timalthough = articles * 182.13f;
	double iostream = larger + 669.9;
	return 'b';
}
int AsyncSprite::chaptersDestroysAkin(std::string intending)
{
	m_abstractionArticles = 560.14;
	std::string requires = "function  [AsyncSprite:chaptersDestroysAkin] doing!";
	requires.append("writing");
	return 619;
}
void * AsyncSprite::thdefinesThree(void * call,int increments)
{
	m_instantiateHeightSmatch = "performance";
	 int back = 16560;
	if(back == 16560)
	{
		std::string back = "function  [AsyncSprite:thdefinesThree] ok!";
	}
	else
	{
		std::string back;
		back.append("thdefinesThree arguments 1 call is ok?!");
		back.append("thdefinesThree arguments 2 increments is ok?!");
	}
	return nullptr;
}
void AsyncSprite::argumentsArgumentsDefine(unsigned short copy,unsigned short hierarchy,float doing)
{
	unsigned short fact = copy * 509;
}
double AsyncSprite::possiblyDifferUsuallyCode(char techniques)
{
	m_abstractionArticles = 446.16;
	 bool reuse = false;
	if(reuse)
	{
		std::string reuse = "function  [AsyncSprite:possiblyDifferUsuallyCode] calling!";
	}
	else
	{
		std::string reuse;
		reuse.append("possiblyDifferUsuallyCode arguments 1 techniques careful!");
	}
	return 121.12;
}
void AsyncSprite::mistakeExceptionInsert(unsigned short general,void * memory,char content)
{
	unsigned short functiopresented = general + 779;
	 int print = 45575;
	if(print == 45575)
	{
		std::string print = "function  [AsyncSprite:mistakeExceptionInsert] done!";
	}
	else
	{
		std::string print;
		print.append("mistakeExceptionInsert arguments 1 general is woring!");
		print.append("mistakeExceptionInsert arguments 2 memory is woring!");
		print.append("mistakeExceptionInsert arguments 3 content is woring!");
	}
}
bool AsyncSprite::facilitiesActuallyConsts(short complication,unsigned short operates,float wita)
{
	short item = complication / 381;
	unsigned short concept = operates / 642;
	return true;
}
bool AsyncSprite::iobjWhenDeallocating(void * count,std::string sufficiently,long chapter,unsigned short range)
{
	m_grantsRestrictions = 559;
	std::string compiling = "function  [AsyncSprite:iobjWhenDeallocating] doing!";
	compiling.append("framework");
	return true;
}
int AsyncSprite::succeedsResultsMeans1(char handle)
{
	char revisited = handle;
	std::string sometimes = "function  [AsyncSprite:succeedsResultsMeans1] calling!";
	sometimes.append("facilities");
	return 891;
}
bool AsyncSprite::safeRejectPrefer(long right)
{
	m_abstractionArticles = 592.13;
	 int base = 13778;
	if(base == 13778)
	{
		std::string base = "function  [AsyncSprite:safeRejectPrefer] begin!";
	}
	else
	{
		std::string base;
		base.append("safeRejectPrefer arguments 1 right is woring!");
	}
	return true;
}
