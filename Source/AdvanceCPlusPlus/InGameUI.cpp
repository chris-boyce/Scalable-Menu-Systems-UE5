// Chris Boyce 1908671 - Advanced C++ Module 


#include "InGameUI.h"
#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"


void UInGameUI::SetCrosshair()
{
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	CrosshairImage->SetBrushFromTexture(LoadedGame->Crosshair);
	
}
