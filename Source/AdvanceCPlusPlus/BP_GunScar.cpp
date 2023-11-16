// Chris Boyce 1908671 - Advanced C++ Module 


#include "BP_GunScar.h"

#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"

ABP_GunScar::ABP_GunScar()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABP_GunScar::BeginPlay()
{
	Super::BeginPlay();
	USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if(LoadedGame)
	{
		if(LoadedGame->LoadGunTextureData())
		{
			GunTexture = LoadedGame->LoadGunTextureData();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No Material on Scar"));
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Load Game Not Loaded From Scar"));
	}
	
	
	
}
void ABP_GunScar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

