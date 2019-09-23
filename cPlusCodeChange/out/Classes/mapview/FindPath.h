#ifndef _FINDPATH_
#define _FINDPATH_
#include "cocos2d.h"
#include "MapView.h"
struct _AstarNode
{
	unsigned int F, G;				
	struct _AstarNode *Father;		
	struct _AstarNode *Next;		
	unsigned short X, Y;			
	unsigned char Value;			
	unsigned char Status;			
	float time;
};
struct _AstarNode *NewAstarMap(cocos2d::Size mapSize, MapView* pMapLayer);
void InitAstarMap(struct _AstarNode *AstarMap);
struct _AstarNode *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct _AstarNode *AstarMap);
#endif