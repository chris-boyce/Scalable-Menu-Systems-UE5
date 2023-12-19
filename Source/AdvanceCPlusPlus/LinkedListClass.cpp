// Chris Boyce 1908671 - Advanced C++ Module 

#include "LinkedListClass.h"

void ULinkedListClass::AddNode(FBattlePassDataStruct Data)
{
	FNode* NewNode = new FNode(Data);
	if (!First)
	{
		First = NewNode;
	}
	else
	{
		FNode* CurrentNode = First;
		while (CurrentNode->Next)
		{
			CurrentNode = CurrentNode->Next;
		}
		CurrentNode->Next = NewNode;
	}
}

void ULinkedListClass::InsertAtBeginning(FBattlePassDataStruct Data)
{
	FNode* newNode = new FNode(Data);
	newNode->Next = First;
	First = newNode;
}

void ULinkedListClass::DeleteAtPosition(int Pos)
{
	if (Pos < 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid position"));
		return;
	}

	if (Pos == 0)
		{
			if (First != nullptr)
			{
				FNode* temp = First;
				First = First->Next;
				delete temp;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("List is empty"));
			}
	}
	else
	{
		FNode* current = First;
		FNode* previous = nullptr;
		int32 currentPosition = 0;

		while (current != nullptr && currentPosition < Pos)
		{
			previous = current;
			current = current->Next;
			currentPosition++;
		}

		if (current != nullptr)
		{
			previous->Next = current->Next;
			delete current;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Position exceeds the length of the list"));
		}
	}
}

int ULinkedListClass::GetPosition(FString Name)
{
	FNode* current = First;
	int32 position = 0;

	while (current != nullptr) {
		if (current->Data.Name == Name) {
			return position;
		}

		current = current->Next;
		position++;
	}
	
	return -1;
}



