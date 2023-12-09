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
	 * Please Assign this in the Inspector of BP_ScoreboardManager <- Inserted Data CSV File To Data Table
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScoreboardDataTable")
	UDataTable* ScoreBoardDataTable;
	
	//Variable to Create the Scroll Box and the Template, Function to Insert them Called once Scroll Box is Assigned <- Blueprint Called in ScoreBoard Manager
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UScrollBox* ScrollBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> TemplateWidget;
	
	UPROPERTY(BlueprintReadOnly)
	FScoreboardData OutputText;

	UPROPERTY()
	UBinaryTreeClass* ScoreBoardBinaryTree;
	
	UFUNCTION(BlueprintCallable)
	void CreateTemplate();
	
	//Overloaded Functions to Split the Int and the String Searches
	void SearchBinaryTree(int SearchItem);
	void SearchBinaryTree(FString SearchItem);
	
	UFUNCTION()
	void ResultHandler(UBinaryTreeNode* Result);

	UFUNCTION(BlueprintCallable)
	void InitSearch(FString SearchItem);

protected:
	virtual void BeginPlay() override;

	
};
