// Chris Boyce 1908671 - Advanced C++ Module 


#include "MainMenuGameMode.h"

void AMainMenuGameMode::InitGameState()
{
	Super::InitGameState();
	if(SteamAPI_Init())
	{
		UE_LOG(LogTemp, Warning, TEXT("Steam Start"));
	}
}
