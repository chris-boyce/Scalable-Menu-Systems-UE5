// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GraphicsSettings.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API UGraphicsSettings : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void ChangeAASetting(FString SettingType);
	
};
