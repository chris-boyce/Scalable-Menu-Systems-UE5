// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "ScoreboardManager.h"
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

public:
	UPROPERTY(BlueprintReadWrite)
	AScoreboardManager* LocalSBM;
};
