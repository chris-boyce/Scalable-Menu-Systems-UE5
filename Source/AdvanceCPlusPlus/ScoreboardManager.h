// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "BinaryTreeClass.h"
#include "ScoreboardManager.generated.h"


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
