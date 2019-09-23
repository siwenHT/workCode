
#include <stdio.h>  
#include "cocos2d.h"  
 USING_NS_CC;
class ClipboardHelper : public cocos2d::Node
{
public:
	ClipboardHelper(void);
	~ClipboardHelper(void);
   static void copyLua(std::string str);
};