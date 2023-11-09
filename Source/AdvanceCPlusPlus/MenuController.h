// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuController.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API AMenuController : public APlayerController
{
	GENERATED_BODY()
public:
	AMenuController();

	/**
	 * Ques Functions to chnage and Remove Layers
	 */
	
	UFUNCTION(BlueprintCallable)
	void ShowWidget();
	
	UFUNCTION(BlueprintCallable)
	void ShowTopUI();

	UFUNCTION(BlueprintCallable)
	void AddToUIQueue(UUserWidget* WidgetToAdd);
	
	UFUNCTION(BlueprintCallable)
	void RemoveTopUI();

	/**
	 * Function Needed to Enable the Layer <- Assigned to run on button Click
	 */
	
	UFUNCTION(BlueprintCallable)
	void MainMenuEnable();

	UFUNCTION(BlueprintCallable)
	void LeagueMenuEnable();
	
	UFUNCTION(BlueprintCallable)
	void BattlePassMenuEnable();

	/**
	 * Class Input Needed <- Must be done in BP_MenuController Inspector
	 */

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LeagueMenuWidgetClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> BattlePassMenuWidgetClass;

	
	
protected:
	virtual void BeginPlay() override;
	
	TQueue<UUserWidget*> UIQueue;
private:
	/**
	 * Widget Layers for Each Layer <- Assigned In Begin Play 
	 */
	UUserWidget* UIWidget1;
	UUserWidget* UIWidget2;
	UUserWidget* UIWidget3;
	
	
	
};
