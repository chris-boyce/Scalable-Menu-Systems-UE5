// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassTemplate.h"

void UBattlePassTemplate::ChangeItems(FString Name, UTexture2D* Item, bool Unlock)
{
	NameTextBlock->SetText(FText::FromString(Name));
	ItemImage->SetBrushFromTexture(Item);
	
}
