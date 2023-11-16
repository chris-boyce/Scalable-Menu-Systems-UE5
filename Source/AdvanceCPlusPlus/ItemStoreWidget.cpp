// Chris Boyce 1908671 - Advanced C++ Module 


#include "ItemStoreWidget.h"

void UItemStoreWidget::ChangeItems(FStoreDataStructure ItemData)
{
	NameTextBlock->SetText(FText::FromString(ItemData.Name));
	ItemImage->SetBrushFromTexture(ItemData.Image);
	PriceTextBlock->SetText(FText::AsNumber(ItemData.Price));
}
void UItemStoreWidget::RemoveTemplate()
{
	RemoveFromParent();
	ConditionalBeginDestroy();
}
