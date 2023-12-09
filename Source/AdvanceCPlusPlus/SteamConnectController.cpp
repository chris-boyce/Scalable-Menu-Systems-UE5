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
		const char* playerName = SteamFriends()->GetFriendPersonaName(MyID);
		FString steamName(playerName);
		SteamName = steamName;
		UE_LOG(LogTemp, Warning, TEXT("Player's Steam Name: %s"), *steamName);

		int iconHandle = SteamFriends()->GetSmallFriendAvatar(MyID);
		uint8* iconData = new uint8[4 * 32 * 32];
		int iconSize = SteamUtils()->GetImageRGBA(iconHandle, iconData, 4 * 32 * 32);

		// Create a UTexture2D
		SteamIconTexture = UTexture2D::CreateTransient(32, 32);

		// Fill the texture with icon data
		FTexture2DMipMap& Mip = SteamIconTexture->PlatformData->Mips[0];
		void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(Data, iconData, 4 * 32 * 32);
		Mip.BulkData.Unlock();
		SteamIconTexture->UpdateResource();
		
	}
		
	
}

void ASteamConnectController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

