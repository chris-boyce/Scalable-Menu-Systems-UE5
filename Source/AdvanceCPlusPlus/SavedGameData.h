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
	//Values Saved --------
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial* GunMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseSensitivity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Crosshair;

	//Save Function ----------
	UFUNCTION()
	void SaveData(UTexture2D* Crosshair1, UMaterial* GunMaterial1, float MouseSen1);
	
	UFUNCTION()
	void SaveCrosshair(UTexture2D* SelectedCrosshiar);
	
	UFUNCTION()
	void SaveGunTextureData(UMaterial* GunMaterial2);

	UFUNCTION()
	void SaveMouseSens(float MouseSens);

	//Load Function ------------
	UFUNCTION()
	bool LoadGameData(USavedGameData*& OutLoadedGame);
	
	UFUNCTION(BlueprintCallable)
	UMaterial* LoadGunTextureData();
	
	UFUNCTION(BlueprintCallable)
	float LoadMouseSense();
	
	UFUNCTION(BlueprintCallable)
	UTexture2D* LoadCrosshair();

	
	
	
};
