// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassManager.h"

#include "BattlePassTemplate.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

FTimerHandle TimerHandle;

ABattlePassManager::ABattlePassManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABattlePassManager::CreateTemplate()
{
	if(ScrollBox)
	{
		CurrentIndex = 0;
		LoopWithDelay();
	}
}



void ABattlePassManager::LoopWithDelay() //Adds Animation to the Boxes Appearing
{
	if (CurrentIndex < BattlePassArray.Num())
	{
		FBattlePassDataStruct Value = BattlePassArray[CurrentIndex];
		UBattlePassTemplate* NewItem = CreateWidget<UBattlePassTemplate>(GetWorld(), TemplateWidget);
		NewItem->ChangeItems(Value.Name, Value.Image, Value.Unlocked);
		ScrollBox->AddChild(NewItem);
		CurrentIndex++;
		if (CurrentIndex < BattlePassArray.Num())
		{
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ABattlePassManager::LoopWithDelay, 0.1f, false);
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

