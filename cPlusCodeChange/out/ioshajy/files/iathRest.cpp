
#include "iathRest.h"
#include "cocos2d.h"
USING_NS_CC;
iathRest::iathRest(void)
{
}
iathRest::~iathRest(void)
{
}
const char* iathRest::G2U(const char* gb2312)    
{    
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	int len = MultiByteToWideChar(0, 0, gb2312, -1, NULL, 0);    
	wchar_t* wstr = new wchar_t[len+1];    
	memset(wstr, 0, len+1);    
	MultiByteToWideChar(0, 0, gb2312, -1, wstr, len);    
	len = WideCharToMultiByte(65001, 0, wstr, -1, NULL, 0, NULL, NULL);    
	char* str = new char[len+1];    
	memset(str, 0, len+1);    
	WideCharToMultiByte(65001, 0, wstr, -1, str, len, NULL, NULL);    
	if(wstr) delete[] wstr;    
	return str;    
	#endif
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	return gb2312; 
	#endif
} 
float iathRest::drivenManageWant(char supplies,long friendshipfifth)
{
	long specify;
	specify = 715;
	int study;
	study = 127;
	bool view;
	view = false;
	return 766.2f;
}
void iathRest::blobptrVariadicListth(int attempted,int suspended,char operating,long smart)
{
	float commonly;
	commonly = 34.11f;
	char articles;
	articles = 'n';
	short within;
	within = 641;
	void * answer;
	answer = nullptr;
}
short iathRest::reverseParentheses(bool close,long setting)
{
	float supply;
	supply = 156.4f;
	return 375;
}
void iathRest::reuseAdvancedClause(void * precise,void * page,int nontemplate,short count)
{
	void * recursion;
	recursion = nullptr;
	unsigned short deal;
	deal = 713;
	void * contains;
	contains = nullptr;
	bool nonmember;
	nonmember = true;
}
int iathRest::collectionsProhibit(bool total,float keyword,float thathey,double compilation)
{
	int managing;
	managing = 599;
	return 913;
}
bool iathRest::specialPartsTimes(short declared,bool around)
{
	double expectations;
	expectations = 800.20;
	double screen;
	screen = 101.5;
	char matches;
	matches = 'w';
	return true;
}
 