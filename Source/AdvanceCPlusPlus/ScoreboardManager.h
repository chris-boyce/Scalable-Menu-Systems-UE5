// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BinaryTreeClass.h"
#include "Components/ScrollBox.h"
#include "ScoreboardManager.generated.h"


UCLASS()
class ADVANCECPLUSPLUS_API AScoreboardManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AScoreboardManager();
	/**
	 * Please Assign this in the Inspector of BP_ScoreboardManager
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScoreboardDataTable")
	UDataTable* ScoreBoardDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UScrollBox* ScrollBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> TemplateWidget;

	UFUNCTION(BlueprintCallable)
	void CreateTemplate();
	
	void SearchBinaryTree1(int SearchItem);
	void SearchBinaryTree1(FString SearchItem); 
	
	UBinaryTreeClass* ScoreBoardBinaryTree;


protected:
	virtual void BeginPlay() override;

	
};
