// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TargetRangePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API ATargetRangePlayerState : public APlayerState
{
	GENERATED_BODY()
	ATargetRangePlayerState();
public:
	UPROPERTY(BlueprintReadWrite, Category = "RangeScore")
	int32 RangeScore;
};
