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
	if (GunMesh && InputTexture)
	{
		GunMesh->SetMaterial(0, InputTexture);
	}
}


