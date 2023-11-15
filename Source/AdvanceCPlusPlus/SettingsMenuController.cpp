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
	
}

// Called every frame
void ASettingsMenuController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASettingsMenuController::DisplayTopScreen()
{
	auto TopWidget = WidgetStack.Peek();
	if(TopWidget)
	{
		TopWidget->AddToViewport();
	}
}

void ASettingsMenuController::RemoveTopScreen()
{
	auto TopWidget = WidgetStack.Peek();
	if(TopWidget)
	{
		TopWidget->RemoveFromViewport();
	}
	WidgetStack.Pop();
}

void ASettingsMenuController::AddToStack(UUserWidget* WidgetToAdd)
{
	WidgetStack.Push(WidgetToAdd);
	DisplayTopScreen();
}

void ASettingsMenuController::SettingMenuStart()
{
	WidgetStack.Push(SettingMenuWidget);
	DisplayTopScreen();
}

