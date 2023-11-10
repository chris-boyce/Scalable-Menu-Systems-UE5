// Chris Boyce 1908671 - Advanced C++ Module 

#include "ScoreboardManager.h"

#include "UObject/ConstructorHelpers.h"

AScoreboardManager::AScoreboardManager()
{
	PrimaryActorTick.bCanEverTick = true;
	if(ScoreBoardDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table imported"));
	}
}

void AScoreboardManager::CreateTemplate()
{
	if(MyScrollBox)
	{
		TArray<FScoreboardData> InOrderResult;
		ScoreBoardBinaryTree->InOrderTraversal(ScoreBoardBinaryTree->Root, InOrderResult);

		for (FScoreboardData Value : InOrderResult)
		{
			// Create an instance of your custom widget
			UUserWidget* NewItem = CreateWidget<UUserWidget>(GetWorld(), TemplateWidget);
			// Add the new item to the scroll box
			MyScrollBox->AddChild(NewItem);
		}
	}
}

void AScoreboardManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Has Run Begin Play"));
	ScoreBoardBinaryTree = NewObject<UBinaryTreeClass>(this);

	if (ScoreBoardDataTable)
	{
		TArray<FName> RowNames = ScoreBoardDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FScoreboardData* DataRow = ScoreBoardDataTable->FindRow<FScoreboardData>(RowName, "");
			if (DataRow)
			{
				FScoreboardData ScoreboardTemp;
				ScoreboardTemp.Name = DataRow->Name;
				ScoreboardTemp.Score = DataRow->Score;
				ScoreBoardBinaryTree->Insert(ScoreboardTemp);
			}
		}
	}
	
	//Display the Binary Tree in the Console Inorder
	TArray<FScoreboardData> InOrderResult;
	ScoreBoardBinaryTree->InOrderTraversal(ScoreBoardBinaryTree->Root, InOrderResult);

	for (FScoreboardData Value : InOrderResult)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Value.Name);
		UE_LOG(LogTemp, Warning, TEXT("%d"), Value.Score);
	}
	
	
}


