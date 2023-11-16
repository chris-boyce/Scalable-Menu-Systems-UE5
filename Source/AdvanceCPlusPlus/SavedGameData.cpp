// Chris Boyce 1908671 - Advanced C++ Module 


#include "SavedGameData.h"

#include "Kismet/GameplayStatics.h"

void USavedGameData::SaveData()
{
	USavedGameData* SaveGameInstance = Cast<USavedGameData>(UGameplayStatics::CreateSaveGameObject(USavedGameData::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->SavedIntData = 20; 
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "SaveData", 0);
		UE_LOG(LogTemp, Warning, TEXT("Save Game Called"))
	}
}

void USavedGameData::LoadData()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if (LoadedGame)
	{
		int32 LoadedIntData = LoadedGame->SavedIntData;
	}
}
