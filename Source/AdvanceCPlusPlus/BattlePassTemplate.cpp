// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassTemplate.h"

void UBattlePassTemplate::ChangeItems(FString Name, UTexture2D* Item, bool Unlock, UMaterial* Texture)
{
	NameTextBlock->SetText(FText::FromString(Name));
	ItemImage->SetBrushFromTexture(Item);
	TextureMaterial = Texture;
}

void UBattlePassTemplate::RemoveTemplate()
{
	RemoveFromParent();
	ConditionalBeginDestroy();
}


