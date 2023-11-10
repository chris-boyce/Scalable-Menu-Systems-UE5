// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "LeagueTemplate.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API ULeagueTemplate : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ChangeText(FString Name, int Score);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UTextBlock* NameTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	UTextBlock* ScoreTextBlock;
	
};
