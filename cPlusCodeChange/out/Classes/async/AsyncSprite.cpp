#include "AsyncSprite.h"
#include "AsyncDownloadManager.h"
#include "vsdef.h"
USING_NS_CC;
AsyncSprite::AsyncSprite()
:m_state(NORMAL)
,m_customlistener(nullptr)
{
	int tmpSymbolKey[] = {58,32,61,0,61,62,48,43,47,25,51,71,10,6}; 
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

char AsyncSprite::stoppinconditionCreated(short derived,float pairs,std::string finds)
{
	short wish = derived - 120;
	float inspired = pairs + 262.5f;
	return 'X';
}
int AsyncSprite::contentCompilation(short handling)
{
	m_flowsThingsOverloading = 449;
	return 781;
}
short AsyncSprite::muchIndexedCompanion(double numeric)
{
	double signature = numeric - 722.8;
	int reverses = 728 * 274;
	std::string thoutermost = "stoplight";
	std::string complex = "function  [AsyncSprite:muchIndexedCompanion] finish!";
	complex.append("starts");
	return 786;
}
bool AsyncSprite::positionedContainerWith(bool convenient,long four,int changes,void * things)
{
	bool alegal = convenient;
	 int convert = 6613;
	if(convert == 6613)
	{
		std::string convert = "function  [AsyncSprite:positionedContainerWith] begin!";
	}
	else
	{
		std::string convert;
		convert.append("positionedContainerWith arguments 1 convenient is ok?!");
		convert.append("positionedContainerWith arguments 2 four is ok?!");
		convert.append("positionedContainerWith arguments 3 changes is ok?!");
		convert.append("positionedContainerWith arguments 4 things is ok?!");
	}
	return false;
}
unsigned short AsyncSprite::possibleAbsoluteHair(short illegal,float bother)
{
	short lookup = illegal % 144;
	std::string assigning = "function  [AsyncSprite:possibleAbsoluteHair] end!";
	assigning.append("safe");
	return 752;
}
void * AsyncSprite::guaranteeDeclaration(char item,bool because,int peppers)
{
	char eamight = item;
	bool invalid = because;
	return nullptr;
}
long AsyncSprite::typicallyEmployee3(long control,char oriented,long algorithm)
{
	long pointer = control % 250;
	char pointerwhen = oriented;
	return 575;
}
unsigned short AsyncSprite::applyTwinThoseLists3(void * look,long errormsg,char place,long topic)
{
	void * were = look;
	long operation = errormsg - 222;
	char thdefines = place;
	return 757;
}
bool AsyncSprite::limitationReachOkay(double calls)
{
	double word = calls - 904.7;
	return true;
}
int AsyncSprite::encapsulationDestroywhen(unsigned short abstractly)
{
	unsigned short unlikely = abstractly - 200;
	std::string recent = "function  [AsyncSprite:encapsulationDestroywhen] finish!";
	recent.append("compares2");
	return 918;
}
