// Chris Boyce 1908671 - Advanced C++ Module 


#include "UnitTesting.h"


void AUnitTesting::MyTestFunction()
{
	AssertTrue(1 == 1, TEXT("1 should be equal to 1"), this);
}

void AUnitTesting::UT_BinaryTreeInsertData()
{
	AssertTrue(LocalSBM->ScoreBoardBinaryTree != nullptr, TEXT("Binary Tree is Filled"), this);
	UE_LOG(LogTemp, Log, TEXT("This is a log message at Log level"));
}

void AUnitTesting::UT_BinaryTreeInsertionOrder()
{
	TArray<FScoreboardData> InOrderResult;
	LocalSBM->ScoreBoardBinaryTree->InOrderTraversal(LocalSBM->ScoreBoardBinaryTree->Root, InOrderResult );
	AssertTrue(InOrderResult[0].Score < InOrderResult[99].Score, TEXT("Insertion Order is Small to Large"), this);
}

void AUnitTesting::UT_BinarySearchFunction()
{
	UBinaryTreeNode* TestData = LocalSBM->ScoreBoardBinaryTree->BinarySearch(LocalSBM->ScoreBoardBinaryTree->Root, 24456);
	AssertTrue(TestData->Value.Name == "Brayden", TEXT("Return Correct Name Through Binary Search"));
}
	

