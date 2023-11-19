// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InGameMenuController.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API AInGameMenuController : public AActor
{
	GENERATED_BODY()
	
public:	
	AInGameMenuController();
	UFUNCTION(BlueprintCallable)
	void BackToMenu();

protected:
	virtual void BeginPlay() override;

	

	

public:	
	virtual void Tick(float DeltaTime) override;

};
