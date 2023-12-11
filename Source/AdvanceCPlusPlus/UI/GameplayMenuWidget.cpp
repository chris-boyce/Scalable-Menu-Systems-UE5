// Chris Boyce 1908671 - Advanced C++ Module 


#include "GameplayMenuWidget.h"
#include "AdvanceCPlusPlus/SavedGameData.h"
#include "Kismet/GameplayStatics.h"


float UGameplayMenuWidget::SetSenseValue()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if(LoadedGame->LoadMouseSense())
	{
		return LoadedGame->LoadMouseSense();
	}
	return 0.5;
}
