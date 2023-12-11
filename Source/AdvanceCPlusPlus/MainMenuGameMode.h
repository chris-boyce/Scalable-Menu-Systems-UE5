// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#pragma warning(push)
#pragma warning(disable: 4996)
#include "Steam/steam_api.h"
#pragma warning(pop)
#define RAW_APP_ID "480"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCECPLUSPLUS_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void InitGameState() override;
};
