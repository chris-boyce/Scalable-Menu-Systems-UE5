// Chris Boyce 1908671 - Advanced C++ Module 

#include "LinkedListClass.h"

void ULinkedListClass::AddNode(FBattlePassDataStruct Data)
{
	FNode* NewNode = new FNode(Data);
	if (!First)
	{
		First = NewNode;
	}
	else
	{
		FNode* CurrentNode = First;
		while (CurrentNode->Next)
		{
			CurrentNode = CurrentNode->Next;
		}
		CurrentNode->Next = NewNode;
	}
}

void ULinkedListClass::PrintList()
{
	/*
	FNode* CurrentNode = First;
	while (CurrentNode)
	{
		CurrentNode = CurrentNode->Next;
	}
	*/
}
