// Chris Boyce 1908671 - Advanced C++ Module 


#include "StoreManager.h"

#include "ItemStoreWidget.h"

FTimerHandle TimerHandle2;

AStoreManager::AStoreManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStoreManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStoreManager::CreateTemplate()
{
	if(ScrollBox)
	{
		CurrentIndex = 0;
		LoopWithDelay();
	}
}

void AStoreManager::LoopWithDelay()
{
	
	if (CurrentIndex < StoreMap.Num())
	{
		FStoreDataStructure Value = StoreMap[CurrentIndex];
		UItemStoreWidget* NewItem = CreateWidget<UItemStoreWidget>(GetWorld(), TemplateWidget);
		NewItem->ChangeItems(Value);
		ScrollBox->AddChild(NewItem);
		CurrentIndex++;
		if (CurrentIndex < StoreMap.Num())
		{
			GetWorldTimerManager().SetTimer(TimerHandle2, this, &AStoreManager::LoopWithDelay, 0.1f, false);
		}
		
	}
	
}

void AStoreManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

