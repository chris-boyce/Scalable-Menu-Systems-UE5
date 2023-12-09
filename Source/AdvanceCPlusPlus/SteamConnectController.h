// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#pragma warning(push)
#pragma warning(disable: 4996)
#include "Steam/steam_api.h"
#pragma warning(pop)

#define RAW_APP_ID "480"



#include "SteamConnectController.generated.h"


UCLASS()
class ADVANCECPLUSPLUS_API ASteamConnectController : public AActor
{
	GENERATED_BODY()
	
public:	
	ASteamConnectController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	const char* APP_ID = RAW_APP_ID;
	CSteamID MyID;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UTexture2D* SteamIconTexture;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString SteamName;
};
