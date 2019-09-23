#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "FindPath.h"
USING_NS_CC;
static int MapWidth;				
static int MapHeight;				
const int DIR_XY[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1},{-1, 1}, {-1, 0}, {-1, -1}};
const int DIR_G[8] = {10, 14, 10, 14, 10, 14, 10, 14};
struct rightItasSuccessful *NewAstarMap(Size mapSize, imagineUnlikeNeed* pMapLayer)
{
	struct rightItasSuccessful *AstarMap;
	AstarMap = (struct rightItasSuccessful *)malloc(mapSize.width * mapSize.height * sizeof(struct rightItasSuccessful));
	if (AstarMap == NULL)
	{
		return(NULL);
	}
	memset(AstarMap, 0, mapSize.width * mapSize.height * sizeof(struct rightItasSuccessful));
	MapWidth = mapSize.width;
	MapHeight = mapSize.height;
	struct rightItasSuccessful *Node = AstarMap;	
	for(int y=0; y<mapSize.height; y++)
	{
		for(int x=0; x<mapSize.width; x++)
		{
			if(pMapLayer->m_factorialToolsOmitted)
			{
				Node->X = x;
				Node->Y = y;
			
				bool flagValue = pMapLayer->isBlock(Point(x,y));
				if(flagValue){
				
					Node->Value = 1;
				}else{
					Node->Value = 0;
				}
				Node ++;
			}
			else
			{
				return AstarMap;
			}
		}
	}
	return(AstarMap);
}
void InitAstarMap(struct rightItasSuccessful *AstarMap)
{
	struct rightItasSuccessful *Node = AstarMap;
	for(int y=0; y<MapHeight; y++)
	{
		for(int x=0; x<MapWidth; x++)
		{
			Node->F = 0;
			Node->G = 0;
			Node->Father = NULL;
			Node->Status = 0;
			Node->Next = NULL;
			Node->time = 0;
			Node ++;
		}
	}
	return;	
}
struct rightItasSuccessful *FindNearNode(struct rightItasSuccessful *AstarNode)
{
	struct rightItasSuccessful *Node;
	struct rightItasSuccessful *Max_Node = NULL;
	unsigned int Max_F = 0;
	for(int i=0; i<8; i++)
	{
	
		int X = AstarNode->X + DIR_XY[i][0];
		int Y = AstarNode->Y + DIR_XY[i][1];
		
	
		if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
		{
			continue;
		}
	
		Node = AstarNode + DIR_XY[i][1] * MapWidth + DIR_XY[i][0];
	
	
		if (Node->Status != 1)
		{
			continue;
		}
	
		if (Node->F > AstarNode->F)
		{
			continue;
		}
		if (Node->F > Max_F)
		{
			Max_F = Node->F;
			Max_Node = Node;
		}
	}
	return(Max_Node);
}
void InsertNode(struct rightItasSuccessful *AstarNode, struct rightItasSuccessful *OpenList)
{
	struct rightItasSuccessful *Node = OpenList->Next;
	struct rightItasSuccessful *PreNode = OpenList;
	struct rightItasSuccessful *NearNode;
	NearNode = FindNearNode(AstarNode);
	if (NearNode != NULL)
	{
		Node = NearNode;
	}
	AstarNode->Status = 1;	
	while(Node != NULL)
	{
		if (Node->F > AstarNode->F)
		{
			PreNode->Next = AstarNode;
			AstarNode->Next = Node;
			return;
		}
		PreNode = Node;
		Node = Node->Next;
	}
	PreNode->Next = AstarNode;
	AstarNode->Next = NULL;
	return;	
}
struct rightItasSuccessful *Pop(struct rightItasSuccessful *OpenList)
{
	struct rightItasSuccessful *P = OpenList->Next;
	if(P != NULL)
	{
		OpenList->Next = P->Next;
		P->Next = NULL;
		P->Status = 2;	
	}
	return(P);
}
struct rightItasSuccessful *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct rightItasSuccessful *AstarMap)
{
	bool IsFounded = false;
	struct rightItasSuccessful *StartNode = AstarMap + SrcY * MapWidth + SrcX;
	struct rightItasSuccessful *StopNode = AstarMap + DstY * MapWidth + DstX;
	struct rightItasSuccessful *CurNode, *ChildNode;
	int G, F, H;
	struct rightItasSuccessful OpenList;
	OpenList.Next = NULL;
	if( SrcX >= MapWidth || SrcY >= MapHeight|| SrcX < 0 || SrcY < 0 )
	{
		return(NULL);
	}
	if( DstX >= MapWidth || DstY >= MapHeight|| DstX < 0 || DstY < 0 )
	{
		return(NULL);
	}
	if (StopNode->Value > 0)
	{
		return(NULL);
	}
	if (StartNode->X == StopNode->X && StartNode->Y == StopNode->Y)
	{
		StartNode->Next = NULL;
		return(StartNode);
	}
	InsertNode(StartNode, &OpenList);
	while(IsFounded == false)
	{
	
		CurNode = Pop(&OpenList);
		if (CurNode == NULL)	
		{
			break;
		}
	
	
	
		static unsigned int DirCount = 0;
		for(int i=0; i<8; i++, DirCount++)
		{
		
			unsigned int DD = DirCount%8;
			int X = CurNode->X + DIR_XY[DD][0];
			int Y = CurNode->Y + DIR_XY[DD][1];
		
		
			if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
			{
				continue;
			}
		
			ChildNode = AstarMap + Y * MapWidth + X;
		
		
			if (ChildNode->Value > 0)
			{
				continue;
			}
		
		
			if (ChildNode->Status == 2)
			{
				continue;
			}
		
		
			G = CurNode->G + DIR_G[DD];
			H = abs(CurNode->X - DstX)*10 + abs(CurNode->Y - DstY)*10;
			F = H + G;
		
			if (ChildNode->Status != 1)
			{
			
				ChildNode->Father = CurNode;
				ChildNode->G = G;
				ChildNode->F = F;
				InsertNode(ChildNode, &OpenList);
			
			
				if (ChildNode->X == StopNode->X && ChildNode->Y == StopNode->Y)
				{
					IsFounded = true;
					break;
				}
			}
			else
			{
			
			
			
				if (ChildNode->G > G)
				{
					ChildNode->G = G;
					ChildNode->F = F;
					ChildNode->Father = CurNode;
				}
			}
		}
		 
	}
	if (IsFounded == true)
	{
		struct rightItasSuccessful *P = StopNode;
		struct rightItasSuccessful *Father;
	
		P->Next = NULL;			
		while(P != NULL)
		{
			Father = P->Father;
			if (Father == NULL)	
			{
				return(NULL);
			}
			Father->Next = P;
			if (Father->X == StartNode->X && Father->Y == StartNode->Y)
			{
				break;
			}
			else
			{
				P = Father;
			}
		}
		return(Father);
	}
	else
	{
		return(NULL);
	}
}
