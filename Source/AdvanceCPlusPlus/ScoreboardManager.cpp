// Chris Boyce 1908671 - Advanced C++ Module 

#include "ScoreboardManager.h"
#include "UI/LeagueTemplate.h"

AScoreboardManager::AScoreboardManager()
{
	if(ScoreBoardDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table imported"));
	}
}

void AScoreboardManager::CreateTemplate()
{
	if(ScrollBox)
	{
		TArray<FScoreboardData> InOrderResult; // <- Returns Array of them in order OR in this case reversed HI-Score
		ScoreBoardBinaryTree->ReverseOrderTraversal(ScoreBoardBinaryTree->Root, InOrderResult);

		for (int32 i = 0; i < InOrderResult.Num(); ++i) //Creates the Template and Changes the Text in The Widget. Does this for each entry
		{
			FScoreboardData Value = InOrderResult[i];
			ULeagueTemplate* NewItem = CreateWidget<ULeagueTemplate>(GetWorld(), TemplateWidget);
			NewItem->ChangeText(Value.Name, Value.Score, i);
			ScrollBox->AddChild(NewItem);
		}
	}
}

void AScoreboardManager::SearchBinaryTree(int SearchItem)
{
	UBinaryTreeNode* Result = ScoreBoardBinaryTree->BinarySearch(ScoreBoardBinaryTree->Root , SearchItem);
	ResultHandler(Result);
}

void AScoreboardManager::SearchBinaryTree(FString SearchItem)
{
	UBinaryTreeNode* Result = ScoreBoardBinaryTree->OrderedSearch(ScoreBoardBinaryTree->Root , SearchItem);
	ResultHandler(Result);
	
}

void AScoreboardManager::ResultHandler(UBinaryTreeNode* Result)
{
	if(Result)
	{
		OutputText.Name = Result->Value.Name;
		OutputText.Score = Result->Value.Score;
	}
	else
	{
		OutputText.Name = "There is No Player With This Name";
		OutputText.Score = 0;
	}
}

void AScoreboardManager::InitSearch(FString SearchItem)
{
	if(SearchItem.IsNumeric())
	{
		int temp = FCString::Atoi(*SearchItem);
		SearchBinaryTree(temp);
	}
	else
	{
		SearchBinaryTree(SearchItem);
	}
}


void AScoreboardManager::BeginPlay()
{
	Super::BeginPlay();
	ScoreBoardBinaryTree = NewObject<UBinaryTreeClass>(this); //Creates Binary Tree For this to Use

	if (ScoreBoardDataTable) //Imports Data from Datatable into the Binary Tree (InOrder)
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
}


