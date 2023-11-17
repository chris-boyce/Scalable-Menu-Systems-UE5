// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SavedGameData.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API USavedGameData : public USaveGame
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* GunMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseSensitivity;

	UFUNCTION()
	void SaveGunTextureData(UMaterial* GunMaterial2);

	UFUNCTION()
	void SaveMouseSens(float MouseSens);

	UFUNCTION(BlueprintCallable)
	UMaterial* LoadGunTextureData();
	
	UFUNCTION(BlueprintCallable)
	float LoadMouseSense();
};
