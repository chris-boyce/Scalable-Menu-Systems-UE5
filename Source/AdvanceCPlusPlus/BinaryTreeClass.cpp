// Chris Boyce 1908671 - Advanced C++ Module 


#include "BinaryTreeClass.h"

void UBinaryTreeClass::Insert(FScoreboardData Value)
{
	if(Root == nullptr) //Checks on the Root Being Null
	{
		Root = NewObject<UBinaryTreeNode>(this);
		Root->Value = Value;
	}
	else //Node isnt Null
	{
		UBinaryTreeNode* CurrentNode = Root; 
		while (CurrentNode) //Recursive Loop
		{
			if(Value.Score < CurrentNode->Value.Score) //Checks is value is Smaller
			{
				if(CurrentNode->LeftChild == nullptr) //Checks if there a left node
				{
					CurrentNode->LeftChild = NewObject<UBinaryTreeNode>(this); //If empty its assigns the left node to it
					CurrentNode->LeftChild->Value = Value; 
					return;
				}
				else //If there is a node it then traverses over to it
				{
					CurrentNode = CurrentNode->LeftChild;
				}
			}
			else //Else it is a Bigger
			{
				if (CurrentNode->RightChild == nullptr) //Checks for right Child
				{
					CurrentNode->RightChild = NewObject<UBinaryTreeNode>(this); //If Empty Assigns the right node
					CurrentNode->RightChild->Value = Value;
					return;
				}
				else //If there is a node it then traverses over to it
				{
					CurrentNode = CurrentNode->RightChild;
				}
			}
		}
	}
}

void UBinaryTreeClass::InOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result)
{
	if (Node)
	{
		InOrderTraversal(Node->LeftChild, Result);
		Result.Add(Node->Value);
		InOrderTraversal(Node->RightChild, Result);
	}
	
}

