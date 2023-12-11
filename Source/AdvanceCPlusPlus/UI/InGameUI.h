// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "InGameUI.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* CrosshairImage;

	

	UFUNCTION(BlueprintCallable)
	void SetCrosshair();
	
};
