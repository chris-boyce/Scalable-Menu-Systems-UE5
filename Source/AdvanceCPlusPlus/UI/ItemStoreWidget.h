// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "AdvanceCPlusPlus/StoreManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ItemStoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API UItemStoreWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void ChangeItems(FStoreDataStructure ItemData);
	
	UFUNCTION(BlueprintCallable)
	void RemoveTemplate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UTextBlock* NameTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UImage* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UTextBlock* PriceTextBlock;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Text")
	UButton* BuyButton;
	
};
