// Fill out your copyright notice in the Description page of Project Settings.
///ERROR DO NOT USE THIS YOU ARE NOT SMART

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MenuManager.generated.h"


UCLASS()
class ADVANCECPLUSPLUS_API AMenuManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AMenuManager();
	

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	
};
