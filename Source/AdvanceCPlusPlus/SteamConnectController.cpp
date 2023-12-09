// Chris Boyce 1908671 - Advanced C++ Module 


#include "SteamConnectController.h"


ASteamConnectController::ASteamConnectController()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASteamConnectController::BeginPlay()
{
	Super::BeginPlay();
	FFileHelper::SaveStringToFile(TEXT(RAW_APP_ID), TEXT("steam_appid.txt"));
	SteamAPI_RestartAppIfNecessary(atoi(APP_ID));
	if(SteamAPI_Init())
	{
		MyID = SteamUser()->GetSteamID();
	}
		
	
}

void ASteamConnectController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

