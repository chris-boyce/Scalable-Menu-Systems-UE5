// Chris Boyce 1908671 - Advanced C++ Module 


#include "FriendsController.h"

// Sets default values
AFriendsController::AFriendsController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFriendsController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFriendsController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

