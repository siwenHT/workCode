#ifndef _FINDPATH_
#define _FINDPATH_
#include "cocos2d.h"
#include "imagineUnlikeNeed.h"
struct rightItasSuccessful
{
	unsigned int F, G;				
	struct rightItasSuccessful *Father;		
	struct rightItasSuccessful *Next;		
	unsigned short X, Y;			
	unsigned char Value;			
	unsigned char Status;			
	float time;
};
struct rightItasSuccessful *NewAstarMap(cocos2d::Size mapSize, imagineUnlikeNeed* pMapLayer);
void InitAstarMap(struct rightItasSuccessful *AstarMap);
struct rightItasSuccessful *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct rightItasSuccessful *AstarMap);
#endif