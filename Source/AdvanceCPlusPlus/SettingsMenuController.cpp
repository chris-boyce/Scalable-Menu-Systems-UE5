// Chris Boyce 1908671 - Advanced C++ Module 


#include "SettingsMenuController.h"

#include "Blueprint/UserWidget.h"

ASettingsMenuController::ASettingsMenuController()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASettingsMenuController::BeginPlay()
{
	Super::BeginPlay();
	
}

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

