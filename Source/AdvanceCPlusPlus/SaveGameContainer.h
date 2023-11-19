// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SavedGameData.h"
#include "SaveGameContainer.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API ASaveGameContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	ASaveGameContainer();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USavedGameData* SaveGameData;
	
	UFUNCTION(BlueprintCallable)
	void SaveGunSkin(UMaterial* GunTexture);

	UFUNCTION(BlueprintCallable)
	void SaveMouseSense(float MouseSens);

	UFUNCTION(BlueprintCallable)
	void SaveCrosshairSelected(UTexture2D* Crosshair);


};
