// Chris Boyce 1908671 - Advanced C++ Module 


#include "UnitTesting.h"

#include "LinkedListClass.h"

void AUnitTesting::UT_BinaryTreeInsertData()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	FScoreboardData Data4;
	Data4.Name = "Player4";
	Data4.Score = 120;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);
	BinaryTree->Insert(Data4);

	TArray<FScoreboardData> Result2;
	BinaryTree->InOrderTraversal(BinaryTree->Root, Result2);
	

	bool check = true;
	int size1 = sizeof(Result2) / sizeof(Result2[0]);
	
	for (int i = 0; i < size1; ++i)
		{
			if (Result2[i].Score == NULL)
			{
				check = false;
			}
	}

	AssertTrue(check == true, TEXT("Insert Function Sucess"));
}

void AUnitTesting::UT_BinaryTreeInsertionOrder()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);

	TArray<FScoreboardData> Result2;
	BinaryTree->InOrderTraversal(BinaryTree->Root, Result2);

	TArray<FScoreboardData> ExpectedOrder;
	ExpectedOrder.Add(Data2); // Smallest
	ExpectedOrder.Add(Data3);
	ExpectedOrder.Add(Data1); // Largest

	int size1 = sizeof(Result2) / sizeof(Result2[0]);
	int size2 = sizeof(ExpectedOrder) / sizeof(ExpectedOrder[0]);
	bool check = true;
	
	for (int i = 0; i < size1; ++i) {
		if (Result2[i].Score != ExpectedOrder[i].Score)
		{
			check = false;
		}
	}

	AssertTrue(check == true, TEXT("InsertionOrder Success"));
}

void AUnitTesting::UT_BinarySearchFunction()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);

	UBinaryTreeNode* SearchResult = BinaryTree->BinarySearch(BinaryTree->Root, 50);
	AssertTrue(SearchResult->Value.Name == "Player2", TEXT("BinarySearch Sucessful"));
}

void AUnitTesting::UT_OrderSearchFunction()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);

	UBinaryTreeNode* SearchResult = BinaryTree->OrderedSearch(BinaryTree->Root, "Player2");
	AssertTrue(SearchResult->Value.Score == 50, TEXT("OrderedSearchFuntion Sucessful"));
	
	
}

void AUnitTesting::UT_InOrderTraversal()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);

	TArray<FScoreboardData> Result2;
	BinaryTree->InOrderTraversal(BinaryTree->Root, Result2);

	TArray<FScoreboardData> ExpectedOrder;
	ExpectedOrder.Add(Data2); // Smallest
	ExpectedOrder.Add(Data3);
	ExpectedOrder.Add(Data1); // Largest

	int size1 = sizeof(Result2) / sizeof(Result2[0]);
	int size2 = sizeof(ExpectedOrder) / sizeof(ExpectedOrder[0]);
	bool check = true;
	
	for (int i = 0; i < size1; ++i) {
		if (Result2[i].Score != ExpectedOrder[i].Score)
		{
			check = false;
		}
	}

	AssertTrue(check == true, TEXT("InOrderTraversal Success"));
	
}

void AUnitTesting::UT_ReverseOrderTraversal()
{
	UBinaryTreeClass* BinaryTree = NewObject<UBinaryTreeClass>();
	
	FScoreboardData Data1;
	Data1.Name = "Player1";
	Data1.Score = 100;

	FScoreboardData Data2;
	Data2.Name = "Player2";
	Data2.Score = 50;

	FScoreboardData Data3;
	Data3.Name = "Player3";
	Data3.Score = 75;

	FScoreboardData Data4;
	Data4.Name = "Player4";
	Data4.Score = 120;

	BinaryTree->Insert(Data1);
	BinaryTree->Insert(Data2);
	BinaryTree->Insert(Data3);
	BinaryTree->Insert(Data4);

	TArray<FScoreboardData> Result2;
	BinaryTree->ReverseOrderTraversal(BinaryTree->Root, Result2);

	TArray<FScoreboardData> ExpectedOrder;
	ExpectedOrder.Add(Data4); // Largest
	ExpectedOrder.Add(Data1);
	ExpectedOrder.Add(Data3);
	ExpectedOrder.Add(Data2); // Smallest

	int size1 = sizeof(Result2) / sizeof(Result2[0]);
	int size2 = sizeof(ExpectedOrder) / sizeof(ExpectedOrder[0]);
	bool check = true;
	
	for (int i = 0; i < size1; ++i) {
		if (Result2[i].Score != ExpectedOrder[i].Score)
		{
			check = false;
		}
	}
	AssertTrue(check == true, TEXT("ReverseOrderTraversal Success"));
}

void AUnitTesting::UT_LinkListAddNode()
{
	ULinkedListClass* MyList = NewObject<ULinkedListClass>();
	FBattlePassDataStruct TestData;
	TestData.Image = nullptr;
	TestData.Name = "TD1";
	TestData.Unlocked = true;
	TestData.GunTexture = nullptr;
		
	MyList->AddNode(TestData);

	AssertTrue(MyList->First  != nullptr, TEXT("Checked Not Null"));
	AssertTrue(MyList->First->Data.Name == TestData.Name, TEXT("Add Node Sucess"));
	
}

void AUnitTesting::UT_LinklistInsertStart()
{
	ULinkedListClass* MyList = NewObject<ULinkedListClass>();
	FBattlePassDataStruct TestData;
	TestData.Image = nullptr;
	TestData.Name = "TD1";
	TestData.Unlocked = true;
	TestData.GunTexture = nullptr;

	FBattlePassDataStruct TestData2;
	TestData2.Image = nullptr;
	TestData2.Name = "TD2";
	TestData2.Unlocked = true;
	TestData2.GunTexture = nullptr;
		
	MyList->AddNode(TestData);
	MyList->InsertAtBeginning(TestData2);
	
	AssertTrue(MyList->First->Data.Name == TestData2.Name, TEXT("Insert At First Sucess"));
}

void AUnitTesting::UT_LinkListDelAtPos()
{
	ULinkedListClass* MyList = NewObject<ULinkedListClass>();
	FBattlePassDataStruct TestData;
	TestData.Image = nullptr;
	TestData.Name = "TD1";
	TestData.Unlocked = true;
	TestData.GunTexture = nullptr;

	FBattlePassDataStruct TestData2;
	TestData2.Image = nullptr;
	TestData2.Name = "TD2";
	TestData2.Unlocked = true;
	TestData2.GunTexture = nullptr;

	FBattlePassDataStruct TestData3;
	TestData3.Image = nullptr;
	TestData3.Name = "TD3";
	TestData3.Unlocked = true;
	TestData3.GunTexture = nullptr;

	MyList->AddNode(TestData);
	MyList->AddNode(TestData2);
	MyList->AddNode(TestData3);

	MyList->DeleteAtPosition(2);
	AssertTrue(MyList->First->Next->Next == nullptr, TEXT("Delete At Pos Correct"));
}

void AUnitTesting::UT_GetPos()
{
	ULinkedListClass* MyList = NewObject<ULinkedListClass>();
	FBattlePassDataStruct TestData;
	TestData.Image = nullptr;
	TestData.Name = "TD1";
	TestData.Unlocked = true;
	TestData.GunTexture = nullptr;

	FBattlePassDataStruct TestData2;
	TestData2.Image = nullptr;
	TestData2.Name = "TD2";
	TestData2.Unlocked = true;
	TestData2.GunTexture = nullptr;

	FBattlePassDataStruct TestData3;
	TestData3.Image = nullptr;
	TestData3.Name = "TD3";
	TestData3.Unlocked = true;
	TestData3.GunTexture = nullptr;

	MyList->AddNode(TestData);
	MyList->AddNode(TestData2);
	MyList->AddNode(TestData3);
	
	int32 PositionNode2 = MyList->GetPosition(TEXT("TD2"));
	AssertTrue(PositionNode2 == 1, TEXT("Find Pos Success"));
}

void AUnitTesting::UT_StackPush()
{
	StackClass<int> IntStack;
	IntStack.Push(10);
	AssertTrue(IntStack.Peek() == 10 ,TEXT("Push Onto the Stack"));
}

void AUnitTesting::UT_StackPop()
{
	StackClass<int> IntStack;
	IntStack.Push(10);
	IntStack.Pop();
	AssertTrue(IntStack.Peek() == NULL ,TEXT("Pop Operation Sucessful"));
}

void AUnitTesting::UT_StackIsEmpty()
{
	StackClass<int> IntStack;
	IntStack.Push(10);
	AssertTrue(IntStack.IsEmpty() == false ,TEXT("Stack Not Empty"));
	IntStack.Pop();
	AssertTrue(IntStack.IsEmpty() == true ,TEXT("Stack is Empty"));
}

void AUnitTesting::UT_StackPeek()
{
	StackClass<int> IntStack;
	IntStack.Push(10);
	auto Answer = IntStack.Peek();
	AssertTrue(Answer == 10 ,TEXT("Peek Operation Successful"));
}

