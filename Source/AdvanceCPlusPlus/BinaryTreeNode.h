// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "BinaryTreeNode.generated.h"


//Data Table Struct
USTRUCT(BlueprintType)
struct FScoreboardData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Score;
};


UCLASS()
class ADVANCECPLUSPLUS_API UBinaryTreeNode : public UObject
{
	GENERATED_BODY()
public:
	UBinaryTreeNode();
	UBinaryTreeNode* LeftChild;
	UBinaryTreeNode* RightChild;
	FScoreboardData Value;
	UBinaryTreeNode(FScoreboardData NewValue) : LeftChild(nullptr), RightChild(nullptr), Value(NewValue) {}
	
	
	
};
