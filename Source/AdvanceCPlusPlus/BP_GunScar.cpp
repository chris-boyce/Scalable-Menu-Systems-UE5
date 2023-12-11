// Chris Boyce 1908671 - Advanced C++ Module 


#include "BP_GunScar.h"

#include "Kismet/GameplayStatics.h"

ABP_GunScar::ABP_GunScar()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABP_GunScar::BeginPlay()
{
	Super::BeginPlay();
}



void ABP_GunScar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

