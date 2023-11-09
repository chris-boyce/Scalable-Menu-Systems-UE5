// Chris Boyce 1908671 - Advanced C++ Module 


#include "MenuController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

TQueue<UUserWidget*> UIQueue;

AMenuController::AMenuController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidget(TEXT("/Game/Chris/UI/MainMenu"));
	if(!ensure (MainMenuWidget.Class != nullptr)) return ;

	static ConstructorHelpers::FClassFinder<UUserWidget> LeagueMenuWidget(TEXT("/Game/Chris/UI/LeaugueMenu"));
	if(!ensure (LeagueMenuWidget.Class != nullptr)) return ;

	MainMenuWidgetClass = MainMenuWidget.Class;
	LeagueMenuWidgetClass = LeagueMenuWidget.Class;
	PrimaryActorTick.bCanEverTick = true;
}

void AMenuController::ShowWidget()
{
	
	try
	{
		if (!MainMenuWidgetClass || !LeagueMenuWidgetClass)
		{
			throw FString("MainMenuWidgetClass is not set.");
		}
		Example();
		/*
		UUserWidget* MainMenu = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (!MainMenu)
		{
			throw FString("Failed to create MainMenu widget.");
		}
		MainMenu->AddToViewport();
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		PlayerController->SetInputMode(InputModeData);
		PlayerController->bShowMouseCursor = true;
		*/
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

void AMenuController::Example()
{
	// Create and add UI elements to the queue
	UUserWidget* UIWidget1 = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
	UUserWidget* UIWidget2 = CreateWidget<UUserWidget>(GetWorld(), LeagueMenuWidgetClass);

	AddToUIQueue(UIWidget1);
	AddToUIQueue(UIWidget2);

	// Remove the top UI element after some time (simulating a pop)
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMenuController::RemoveTopUI, 3.0f, false);
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

void AMenuController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("We Have Found Class %s"), *MainMenuWidgetClass->GetName());
	ShowWidget();
}

