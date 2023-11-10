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

void AScoreboardManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Has Run Begin Play"));
	// Example usage of BinaryTree
	UBinaryTreeClass* MyBinaryTree = NewObject<UBinaryTreeClass>(this);

	if (ScoreBoardDataTable)
	{
		TArray<FName> RowNames = ScoreBoardDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FScoreboardData* DataRow = ScoreBoardDataTable->FindRow<FScoreboardData>(RowName, "");
			if (DataRow)
			{
				// Access data from DataRow
				FString Name = DataRow->Name;
				int32 Score = DataRow->Score;

				FScoreboardData NewScoreData;
				NewScoreData.Name = Name;
				NewScoreData.Score = Score;

				ScoreboardArray.Add(NewScoreData);
            
				// Use the data as needed
				UE_LOG(LogTemp, Warning, TEXT("Row %s - Name: %s, Score: %d"), *RowName.ToString(), *Name, Score);
			}
		}
	}

	for (const FScoreboardData& ScoreboardData : ScoreboardArray)
	{
		FScoreboardData ScoreboardTemp;
		ScoreboardTemp.Name = ScoreboardData.Name;
		ScoreboardTemp.Score = ScoreboardData.Score;
		MyBinaryTree->Insert(ScoreboardTemp);
	}
	
	TArray<FScoreboardData> InOrderResult;
	MyBinaryTree->InOrderTraversal(MyBinaryTree->Root, InOrderResult);

	for (FScoreboardData Value : InOrderResult)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Value.Name);
		UE_LOG(LogTemp, Warning, TEXT("%d"), Value.Score);
		
	}
	
	
	
		
	
	
}


