// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "GameFramework/Actor.h"
#include "StoreManager.generated.h"

USTRUCT(BlueprintType)
struct FStoreDataStructure
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Purchased;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Price;
};

UCLASS()
class ADVANCECPLUSPLUS_API AStoreManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AStoreManager();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Map")
	TMap<int32, FStoreDataStructure> StoreMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> TemplateWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UScrollBox* ScrollBox;

	UFUNCTION(BlueprintCallable)
	void BroughtItem(FString NameOfItemBrought);

	UFUNCTION(BlueprintCallable)
	void CreateTemplate();

	UFUNCTION()
	void LoopWithDelay();

	int CurrentIndex;
	
	virtual void Tick(float DeltaTime) override;

};
