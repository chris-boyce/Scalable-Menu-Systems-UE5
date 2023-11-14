// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
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
	
};
