#include "ClipboardHelper.h"
#include "CCLuaEngine.h"

ClipboardHelper::ClipboardHelper(void)
{
}


ClipboardHelper::~ClipboardHelper(void)
{
}

void ClipboardHelper::copyLua(std::string str) {  
    CCLOG("%s",str.c_str()); 
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)  
	//iOSƽ̨  
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
    //Androidƽ̨  
#endif
}  
