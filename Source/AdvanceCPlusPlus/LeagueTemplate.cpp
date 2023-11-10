// Chris Boyce 1908671 - Advanced C++ Module 


#include "LeagueTemplate.h"

void ULeagueTemplate::ChangeText(FString Name, int Score)
{
	if (NameTextBlock)
	{
		NameTextBlock->SetText(FText::FromString(Name));
		ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), Score)));
		
	}
}
