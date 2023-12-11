// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "IDamageable.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API ATarget : public AActor , public IIDamageable
{
	GENERATED_BODY()
	
public:	
	ATarget();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Damage")
	void ApplyDamage(float DamageAmount) ;

};
