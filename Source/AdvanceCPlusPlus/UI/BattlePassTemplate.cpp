// Chris Boyce 1908671 - Advanced C++ Module 


#include "BattlePassTemplate.h"

#include "UObject/UnrealTypePrivate.h"

void UBattlePassTemplate::ChangeItems(FString Name, UTexture2D* Item, bool Unlock, UMaterial* Texture)
{
	NameTextBlock->SetText(FText::FromString(Name));
	ItemImage->SetBrushFromTexture(Item);
	TextureMaterial1 = Texture;
}

void UBattlePassTemplate::RemoveTemplate()
{
	
	
	RemoveFromParent();
	ConditionalBeginDestroy();
}


