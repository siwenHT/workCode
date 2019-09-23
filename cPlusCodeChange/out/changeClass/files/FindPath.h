#ifndef _FINDPATH_
#define _FINDPATH_
#include "cocos2d.h"
#include "illustrateDiscussion.h"
struct targetSimilar
{
	unsigned int F, G;				
	struct targetSimilar *Father;		
	struct targetSimilar *Next;		
	unsigned short X, Y;			
	unsigned char Value;			
	unsigned char Status;			
	float time;
};
struct targetSimilar *NewAstarMap(cocos2d::Size mapSize, illustrateDiscussion* pMapLayer);
void InitAstarMap(struct targetSimilar *AstarMap);
struct targetSimilar *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct targetSimilar *AstarMap);
#endif