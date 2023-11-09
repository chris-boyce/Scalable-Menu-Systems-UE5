// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "ScoreboardManager.generated.h"

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
class ADVANCECPLUSPLUS_API AScoreboardManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AScoreboardManager();
	/**
	 * Please Assign this in the Inspector of BP_ScoreboardManager
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScoreboardDataTable")
	UDataTable* ScoreBoardDataTable;

protected:
	virtual void BeginPlay() override;
};
