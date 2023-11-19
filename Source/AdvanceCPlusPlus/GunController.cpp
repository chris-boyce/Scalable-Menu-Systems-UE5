// Chris Boyce 1908671 - Advanced C++ Module 


#include "GunController.h"

#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGunController::UGunController()
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}



void UGunController::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	TArray<UStaticMeshComponent*> Components;
	Owner->GetComponents<UStaticMeshComponent>(Components);
	for( int32 i=0; i < Components.Num(); i++ )
	{
		if(Components[i]->GetName() == "GunMesh")
		{
			GunMesh = Components[i];
		}
	}
	if(GunMesh)
	{
		USavedGameData* LoadedGame = Cast<USavedGameData>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
		if(LoadedGame->LoadGunTextureData())
		{
			GunTexture = LoadedGame->LoadGunTextureData();
			if(GunTexture)
			{
				GunMesh->SetMaterial(0, GunTexture);
				UE_LOG(LogTemp, Warning, TEXT("WARNING RUNNING"));
			}
		}
		
	}
	

	
		
			
		
	
	
}


// Called every frame
void UGunController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

