// Chris Boyce 1908671 - Advanced C++ Module 


#include "LeagueTemplate.h"

void ULeagueTemplate::ChangeText(FString Name, int Score, int Place)
{
	if (NameTextBlock)
	{
		NameTextBlock->SetText(FText::FromString(Name));
		ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), Score)));
		PlacementTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), Place + 1)));
		
	}
}
