// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassManager.h"

#include "BattlePassTemplate.h"

ABattlePassManager::ABattlePassManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABattlePassManager::CreateTemplate()
{
	if(ScrollBox)
	{
		for (int32 i = 0; i < BattlePassArray.Num(); ++i)
		{
			UE_LOG(LogTemp, Warning, TEXT("Has Run template Set up"));
			FBattlePassDataStruct Value = BattlePassArray[i];
			UBattlePassTemplate* NewItem = CreateWidget<UBattlePassTemplate>(GetWorld(), TemplateWidget);
			NewItem->ChangeItems(Value.Name, Value.Image , Value.Unlocked);
			ScrollBox->AddChild(NewItem);
		}
		
	}
}

void ABattlePassManager::BeginPlay()
{
	Super::BeginPlay();
	BattlePassLinkedList = NewObject<ULinkedListClass>(this);
}

void ABattlePassManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

