// Chris Boyce 1908671 - Advanced C++ Module 


#include "SettingsMenuController.h"

#include "Blueprint/UserWidget.h"

// Sets default values
ASettingsMenuController::ASettingsMenuController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASettingsMenuController::BeginPlay()
{
	Super::BeginPlay();
	WidgetStack.Push(SettingMenuWidget);
	WidgetStack.Push(GameplayMenuWidget);
	WidgetStack.Pop();
	
	auto Temp = WidgetStack.Peek();

	DisplayTopScreen(Temp);
}

// Called every frame
void ASettingsMenuController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASettingsMenuController::DisplayTopScreen(UUserWidget* TopWidget)
{
	if(TopWidget)
	{
		TopWidget->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("Has Tried"));
	}
	
}

