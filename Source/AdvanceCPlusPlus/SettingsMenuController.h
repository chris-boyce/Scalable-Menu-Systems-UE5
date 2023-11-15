// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StackClass.h"
#include "SettingsMenuController.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API ASettingsMenuController : public AActor
{
	GENERATED_BODY()
	
public:	
	ASettingsMenuController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	StackClass<UUserWidget*> WidgetStack;

	UFUNCTION()
	void DisplayTopScreen(UUserWidget* TopWidget);
	
	UPROPERTY(EditAnywhere)
	UUserWidget* SettingMenuWidget;

	UPROPERTY(EditAnywhere)
	UUserWidget* GameplayMenuWidget;

};
