// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_GunScar.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API ABP_GunScar : public AActor
{
	GENERATED_BODY()
	
public:	
	ABP_GunScar();

protected:
	virtual void BeginPlay() override;

	

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save")
	UMaterial* GunTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	float MouseSense;

};
