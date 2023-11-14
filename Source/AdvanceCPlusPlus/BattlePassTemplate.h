// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "BattlePassTemplate.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API UBattlePassTemplate : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ChangeItems(FString Name, UTexture2D* Item, bool Unlock, UMaterial* Texture);
	
	UFUNCTION(BlueprintCallable)
	void RemoveTemplate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UTextBlock* NameTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UImage* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UButton* UnlockButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UMaterial* TextureMaterial;
	


};
