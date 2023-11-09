// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Containers/Queue.h"
#include "MenuController.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API AMenuController : public APlayerController
{
	GENERATED_BODY()
public:
	AMenuController();

	
	UFUNCTION(BlueprintCallable)
	void ShowWidget();
	
	UFUNCTION(BlueprintCallable)
	void ShowTopUI();

	UFUNCTION(BlueprintCallable)
	void AddToUIQueue(UUserWidget* WidgetToAdd);

	UFUNCTION(BlueprintCallable)
	void Example();

	UFUNCTION(BlueprintCallable)
	void RemoveTopUI();
	
	
protected:
	virtual void BeginPlay() override;
private:
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;
	TSubclassOf<class UUserWidget> LeagueMenuWidgetClass;
	
};
