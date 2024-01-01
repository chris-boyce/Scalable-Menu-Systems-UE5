// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "ScoreboardManager.h"
#include "StackClass.h"
#include "UnitTesting.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API AUnitTesting : public AFunctionalTest
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void UT_BinaryTreeInsertData();

	UFUNCTION(BlueprintCallable)
	void UT_BinaryTreeInsertionOrder();

	UFUNCTION(BlueprintCallable)
	void UT_BinarySearchFunction();

	UFUNCTION(BlueprintCallable)
	void UT_OrderSearchFunction();

	UFUNCTION(BlueprintCallable)
	void UT_InOrderTraversal();

	UFUNCTION(BlueprintCallable)
	void UT_ReverseOrderTraversal();
	
	UFUNCTION(BlueprintCallable)
	void UT_LinkListAddNode();

	UFUNCTION(BlueprintCallable)
	void UT_LinklistInsertStart();

	UFUNCTION(BlueprintCallable)
	void UT_LinkListDelAtPos();

	UFUNCTION(BlueprintCallable)
	void UT_GetPos();

	UFUNCTION(BlueprintCallable)
	void UT_StackPush();

	UFUNCTION(BlueprintCallable)
	void UT_StackPop();

	UFUNCTION(BlueprintCallable)
	void UT_StackIsEmpty();

	UFUNCTION(BlueprintCallable)
	void UT_StackPeek();

	

public:
	UPROPERTY(BlueprintReadWrite)
	AScoreboardManager* LocalSBM;
};
