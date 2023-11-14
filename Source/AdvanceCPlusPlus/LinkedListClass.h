// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "UObject/NoExportTypes.h"
#include "LinkedListClass.generated.h"

USTRUCT(BlueprintType)
struct FBattlePassDataStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Unlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* GunTexture;
};

struct FNode
{
public:
	FBattlePassDataStruct Data;
	FNode* Next;
	FNode(FBattlePassDataStruct InData) : Data(InData), Next(nullptr) {}
};

UCLASS()
class ADVANCECPLUSPLUS_API ULinkedListClass : public UObject
{
	GENERATED_BODY()
public:
	FNode* First;
	ULinkedListClass() : First(nullptr) {}
	void AddNode(FBattlePassDataStruct Data);
	void PrintList();
};
