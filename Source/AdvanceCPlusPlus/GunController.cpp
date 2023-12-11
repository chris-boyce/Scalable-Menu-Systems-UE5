// Chris Boyce 1908671 - Advanced C++ Module 


#include "GunController.h"

#include "IDamageable.h"
#include "SavedGameData.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGunController::UGunController()
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}


void UGunController::FireGun()
{
	FVector StartLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(StartLocation, PlayerViewpointRotation);
	FVector EndLocation = StartLocation + PlayerViewpointRotation.Vector() * 10000;
	
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	
	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);
	
	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();

		// Check if the hit actor implements the IDamageable interface
		if (HitActor->GetClass()->ImplementsInterface(UIDamageable::StaticClass()))
		{
			// Apply damage to the hit actor through the interface
			IIDamageable::Execute_ApplyDamage(HitActor, 10);

			// Example: Draw a debug line for visualization
			DrawDebugLine(GetWorld(), StartLocation, HitResult.ImpactPoint, FColor::Red, false, 1.0f, 0, 1.0f);
		}
		
		DrawDebugLine(GetWorld(), StartLocation, HitResult.ImpactPoint, FColor::Red, false, 1.0f, 0, 1.0f);
	}
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
		if(LoadedGame->MouseSensitivity)
		{
			Sense = LoadedGame->MouseSensitivity;
		}
	}
	
}



// Called every frame
void UGunController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

