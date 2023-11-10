// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LeagueTemplate.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API ULeagueTemplate : public UUserWidget
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	void test();
	
};
