// Chris Boyce 1908671 - Advanced C++ Module 


#include "InGameMenuController.h"

#include "Kismet/GameplayStatics.h"

AInGameMenuController::AInGameMenuController()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AInGameMenuController::BeginPlay()
{
	Super::BeginPlay();
}

void AInGameMenuController::BackToMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Input ReCieved"))
	UGameplayStatics::OpenLevel(this, FName("MainMenuMap"), true);
}

void AInGameMenuController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

