// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
	void MainMenuEnable();

	UFUNCTION(BlueprintCallable)
	void RemoveTopUI();

	UFUNCTION(BlueprintCallable)
	void LeagueMenuEnable();
	
	UFUNCTION(BlueprintCallable)
	void BattlePassMenuEnable();

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
	UUserWidget* UIWidget1;
	UUserWidget* UIWidget2;
	UUserWidget* UIWidget3;
	
	
	
};
