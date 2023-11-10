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

	FScoreboardData P1;
	P1.Name = "Chris";
	P1.Score = 100;

	FScoreboardData P2;
	P2.Name = "Bob";
	P2.Score = 200;
	
	MyBinaryTree->Insert(P1);
	MyBinaryTree->Insert(P2);
	

	TArray<FScoreboardData> InOrderResult;
	MyBinaryTree->InOrderTraversal(MyBinaryTree->Root, InOrderResult);

	for (FScoreboardData Value : InOrderResult)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Value.Name);
		UE_LOG(LogTemp, Warning, TEXT("%d"), Value.Score);
		
	}
	
	
		
	
	
}


