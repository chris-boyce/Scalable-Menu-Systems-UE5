// Chris Boyce 1908671 - Advanced C++ Module 


#include "GunRender.h"

AGunRender::AGunRender()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AGunRender::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AGunRender::ChangeGunTexture(UMaterial* InputTexture)
{
	GunMesh = FindComponentByClass<UStaticMeshComponent>();
	UE_LOG(LogTemp, Warning, TEXT("ChangeGunTexture called"));
    
	if (GunMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("GunMesh is valid"));
	}

	if (InputTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("InputTexture is valid"));
	}
    
	if (GunMesh && InputTexture)
	{
		GunMesh->SetMaterial(0, InputTexture);
		UE_LOG(LogTemp, Warning, TEXT("Material set successfully"));
	}
}


