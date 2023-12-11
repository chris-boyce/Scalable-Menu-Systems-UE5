// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "ScoreboardManager.h"
#include "UnitTesting.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API AUnitTesting : public AFunctionalTest
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void MyTestFunction();



	UFUNCTION(BlueprintCallable)
	void UT_BinaryTreeInsertData();

	UFUNCTION(BlueprintCallable)
	void UT_BinaryTreeInsertionOrder();

	UFUNCTION(BlueprintCallable)
	void UT_BinarySearchFunction();

public:
	UPROPERTY(BlueprintReadWrite)
	AScoreboardManager* LocalSBM;
};
