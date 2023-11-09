// Chris Boyce 1908671 - Advanced C++ Module 

#include "ScoreboardManager.h"
#include "UObject/ConstructorHelpers.h"

AScoreboardManager::AScoreboardManager()
{
	PrimaryActorTick.bCanEverTick = true;
	if(ScoreBoardDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table imported"));
	}
}

void AScoreboardManager::BeginPlay()
{
	Super::BeginPlay();
	
}


