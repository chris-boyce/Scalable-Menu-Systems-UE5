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
			UE_LOG(LogTemp, Error, TEXT("Failed Menu Load"));
		}
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FInputModeUIOnly InputModeData;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
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
		if(TopWidget)
		{
			// Show or add the top UI widget to the viewport
			if (!TopWidget->IsInViewport())
			{
				TopWidget->AddToViewport();
			}
		}
		
	}
}

void AMenuController::AddToUIQueue(UUserWidget* WidgetToAdd)
{
	if(WidgetToAdd)
	{
		UIQueue.Enqueue(WidgetToAdd);
		ShowTopUI();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WIDGET IS NULL"));
	}
	
}

void AMenuController::RemoveTopUI()
{
	UUserWidget* TopWidget;
	if (UIQueue.Dequeue(TopWidget))
	{
		if (TopWidget && TopWidget->IsInViewport())
		{
			TopWidget->RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Trying to remove a widget that is not in the viewport or is nullptr."));
		}
	}
	ShowTopUI();
	
}


/**
 * Queues Functions for Each Widget
 */
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
void AMenuController::StoreMenuEnable()
{
	AddToUIQueue(UIWidget4);
	RemoveTopUI();
}

void AMenuController::ClearAllUI()
{
	UUserWidget* TopWidget;
	if (UIQueue.Dequeue(TopWidget))
	{
		if (TopWidget && TopWidget->IsInViewport())
		{
			TopWidget->RemoveFromParent();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Trying to remove a widget that is not in the viewport or is nullptr."));
		}
	}
}

void AMenuController::BeginPlay()
{
	Super::BeginPlay();
	ShowWidget();
	UIWidget1 = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
	UIWidget2 = CreateWidget<UUserWidget>(GetWorld(), LeagueMenuWidgetClass);
	UIWidget3 = CreateWidget<UUserWidget>(GetWorld(), BattlePassMenuWidgetClass);
	UIWidget4 = CreateWidget<UUserWidget>(GetWorld(), StoreMenuWidgetClass);
	AddToUIQueue(UIWidget1);
}

