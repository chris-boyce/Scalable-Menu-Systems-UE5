// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GunController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVANCECPLUSPLUS_API UGunController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGunController();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	UMaterial* GunTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	UStaticMeshComponent* GunMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	float Sense;
	

protected:
	virtual void BeginPlay() override;
	
private:
	


	

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
