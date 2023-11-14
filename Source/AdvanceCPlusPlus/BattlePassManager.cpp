// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassManager.h"

#include "BattlePassTemplate.h"
#include "GunRender.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

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

void ABattlePassManager::HoverTextureChange(UMaterial* Texture)
{
	AGunRender* GunRenderActor = Cast<AGunRender>(UGameplayStatics::GetActorOfClass(GetWorld(), AGunRender::StaticClass()));
	GunRenderActor->ChangeGunTexture(Texture);
}

void ABattlePassManager::ButtonTextureAssign(UMaterial* Texture)
{
	EquippedGunTexture = Texture;
}

void ABattlePassManager::UnHoverTextureChange()
{
	AGunRender* GunRenderActor = Cast<AGunRender>(UGameplayStatics::GetActorOfClass(GetWorld(), AGunRender::StaticClass()));
	GunRenderActor->ChangeGunTexture(EquippedGunTexture);
}


void ABattlePassManager::LoopWithDelay() //Adds Animation to the Boxes Appearing
{
	if (CurrentIndex < BattlePassArray.Num())
	{
		FBattlePassDataStruct Value = BattlePassArray[CurrentIndex];
		UBattlePassTemplate* NewItem = CreateWidget<UBattlePassTemplate>(GetWorld(), TemplateWidget);
		NewItem->ChangeItems(Value.Name, Value.Image, Value.Unlocked, Value.GunTexture);
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
	EquippedGunTexture = BattlePassArray[0].GunTexture;
}

void ABattlePassManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

