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
	void Insert(FScoreboardData Value);
	void InOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result);
	void ReverseOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result);
	UBinaryTreeNode* OrderedSearch(UBinaryTreeNode* Node, FString SearchString);
	UBinaryTreeNode* BinarySearch(UBinaryTreeNode* Node, int SearchInt);
	
};
