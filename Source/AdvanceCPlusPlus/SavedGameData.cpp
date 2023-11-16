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
		UE_LOG(LogTemp, Error, TEXT("Saved Gun"));
	}
}

UMaterial* USavedGameData::LoadGunTextureData()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if (LoadedGame)
	{
		if (LoadedGame->GunMaterial)
		{
			return  LoadedGame->GunMaterial;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No Material Found"));
			return nullptr;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Loaded Game"));
		return nullptr;
	}
}
