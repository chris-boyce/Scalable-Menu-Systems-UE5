// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinkedListClass.h"
#include "Components/ScrollBox.h"
#include "BattlePassManager.generated.h"

UCLASS()
class ADVANCECPLUSPLUS_API ABattlePassManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABattlePassManager();

	UPROPERTY()
	ULinkedListClass* BattlePassLinkedList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattlePass")
	TArray<FBattlePassDataStruct> BattlePassArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UScrollBox* ScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> TemplateWidget;

	UFUNCTION(BlueprintCallable)
	void CreateTemplate();

	UFUNCTION(BlueprintCallable)
	void HoverTextureChange(UMaterial* Texture);

	UFUNCTION(BlueprintCallable)
	void ButtonTextureAssign(UMaterial* Texture);

	UFUNCTION(BlueprintCallable)
	void UnHoverTextureChange();

	UPROPERTY()
	UMaterial* EquippedGunTexture;
	
	void LoopWithDelay();

	int CurrentIndex;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
