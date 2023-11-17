// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API UGameplayMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseSense;

	UFUNCTION(BlueprintCallable)
	float SetSenseValue();
	
};
