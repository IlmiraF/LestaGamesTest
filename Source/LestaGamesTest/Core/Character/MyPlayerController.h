// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
class UPlayerHUDWidget;
class UFinishMenuWidget;
UCLASS()
class LESTAGAMESTEST_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetupInputComponent() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
	void Jump();

	TSoftObjectPtr<class APlayerCharacter> CachedBaseCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UPlayerHUDWidget> PlayerHUDWidgetClass;

private:
	void CreateAndInitializeWidgets();

	UPlayerHUDWidget* PlayerHUDWidget = nullptr;

	bool bIsPlaying = false;

	void StartPlaying(bool bIsPlaying_In);

	void OnDeath();
	void WinGame();
};
