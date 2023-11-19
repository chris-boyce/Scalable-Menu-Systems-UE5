// Chris Boyce 1908671 - Advanced C++ Module 


#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"

//Saved Functions ---------------------
void USavedGameData::SaveCrosshair(UTexture2D* SelectedCrosshiar)
{
	SaveData(SelectedCrosshiar, nullptr , LoadMouseSense());
}

void USavedGameData::SaveGunTextureData(UMaterial* GunMaterial2)
{
	SaveData(nullptr, GunMaterial2 , LoadMouseSense());
}

void USavedGameData::SaveMouseSens(float MouseSens)
{
	SaveData(nullptr, nullptr , MouseSens);
}

void USavedGameData::SaveData(UTexture2D* Crosshair1, UMaterial* GunMaterial1, float MouseSen1)
{
	USavedGameData* SaveGameInstance = Cast<USavedGameData>(UGameplayStatics::CreateSaveGameObject(USavedGameData::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->Crosshair = (Crosshair1 != nullptr) ? Crosshair1 : LoadCrosshair();
		SaveGameInstance->GunMaterial = (GunMaterial1 != nullptr) ? GunMaterial1 : LoadGunTextureData();
		SaveGameInstance->MouseSensitivity = (MouseSen1 != 0.0f) ? MouseSen1 : LoadMouseSense();
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "SaveData", 0);
		
	}
}
//Load Functions --------------
bool USavedGameData::LoadGameData(USavedGameData*& OutLoadedGame)
{
	OutLoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	return OutLoadedGame != nullptr;
}

UMaterial* USavedGameData::LoadGunTextureData()
{
	USavedGameData* LoadedGame = nullptr;
	if (LoadGameData(LoadedGame))
	{
		return LoadedGame->GunMaterial;
	}
	return nullptr;
}

float USavedGameData::LoadMouseSense()
{
	USavedGameData* LoadedGame = nullptr;
	if (LoadGameData(LoadedGame))
	{
		return LoadedGame->MouseSensitivity;
	}
	return 0.5f;
}

UTexture2D* USavedGameData::LoadCrosshair()
{
	USavedGameData* LoadedGame = nullptr;
	if (LoadGameData(LoadedGame))
	{
		return LoadedGame->Crosshair;
	}
	return nullptr;
}

