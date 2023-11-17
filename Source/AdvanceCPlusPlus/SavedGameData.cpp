// Chris Boyce 1908671 - Advanced C++ Module 


#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"




void USavedGameData::SaveGunTextureData(UMaterial* GunMaterial2)
{
	USavedGameData* SaveGameInstance = Cast<USavedGameData>(UGameplayStatics::CreateSaveGameObject(USavedGameData::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->GunMaterial = GunMaterial2;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "SaveData", 0);
	}
}

void USavedGameData::SaveMouseSens(float MouseSens)
{
	USavedGameData* SaveGameInstance = Cast<USavedGameData>(UGameplayStatics::CreateSaveGameObject(USavedGameData::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->MouseSensitivity = MouseSens;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "SaveData", 0);
	}
}

UMaterial* USavedGameData::LoadGunTextureData()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if (LoadedGame->GunMaterial)
	{
		return  LoadedGame->GunMaterial;
	}
	else
	{
		return nullptr;
	}
	
}
float USavedGameData::LoadMouseSense()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	return LoadedGame->MouseSensitivity;
}
