// Chris Boyce 1908671 - Advanced C++ Module 


#include "MenuController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Queue.h"

TQueue<UUserWidget*> UIQueue;

AMenuController::AMenuController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMenuController::ShowWidget()
{
	try
	{
		if (!MainMenuWidgetClass)
		{
			UE_LOG(LogTemp, Error, TEXT("We Are broken"));
		}
		
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FInputModeUIOnly InputModeData;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		PlayerController->SetInputMode(InputModeData);
		PlayerController->bShowMouseCursor = true;
		
	}
	catch (const FString& ErrorMessage)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
	}
	
	
}

void AMenuController::ShowTopUI()
{
	UUserWidget* TopWidget;
	if (UIQueue.Peek(TopWidget))
	{
		// Show or add the top UI widget to the viewport
		if (!TopWidget->IsInViewport())
		{
			TopWidget->AddToViewport();
		}
	}
}

void AMenuController::AddToUIQueue(UUserWidget* WidgetToAdd)
{
	UIQueue.Enqueue(WidgetToAdd);
	ShowTopUI();
	
}
void AMenuController::RemoveTopUI()
{
	UUserWidget* TopWidget;
	if (UIQueue.Dequeue(TopWidget))
	{
		// Hide or remove the top UI widget
		TopWidget->RemoveFromParent();
	}

	// Show the new top UI widget
	ShowTopUI();
	
}

void AMenuController::MainMenuEnable()
{
	AddToUIQueue(UIWidget1);
	RemoveTopUI();
}

void AMenuController::LeagueMenuEnable()
{
	AddToUIQueue(UIWidget2);
	RemoveTopUI();
}
void AMenuController::BattlePassMenuEnable()
{
	AddToUIQueue(UIWidget3);
	RemoveTopUI();
}

void AMenuController::BeginPlay()
{
	Super::BeginPlay();
	ShowWidget();
	UIWidget1 = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
	UIWidget2 = CreateWidget<UUserWidget>(GetWorld(), LeagueMenuWidgetClass);
	UIWidget3 = CreateWidget<UUserWidget>(GetWorld(), BattlePassMenuWidgetClass);
	AddToUIQueue(UIWidget1);
}

