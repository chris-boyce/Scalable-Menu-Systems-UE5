// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BinaryTreeNode.h"
#include "BinaryTreeClass.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API UBinaryTreeClass : public UObject
{
	GENERATED_BODY()
public:
	UBinaryTreeNode* Root;
	UBinaryTreeClass() : Root(nullptr) {}

	// Function to insert a value into the binary tree
	void Insert(FScoreboardData Value);

	// Function to perform an inorder traversal of the binary tree
	void InOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result);
	
};
