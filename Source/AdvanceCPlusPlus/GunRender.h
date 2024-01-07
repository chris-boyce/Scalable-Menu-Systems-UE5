// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "GunRender.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API AGunRender : public AActor
{
	GENERATED_BODY()
	
public:	
	AGunRender();
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GunMesh;

	UFUNCTION(BlueprintCallable)
	void ChangeGunTexture(UMaterial* InputTexture);


};
