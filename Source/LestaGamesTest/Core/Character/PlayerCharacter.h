// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnStartPlay, bool);
DECLARE_MULTICAST_DELEGATE(FOnWinGame);

class UWidgetComponent;
class UCharacterAttributeComponent;
UCLASS()
class LESTAGAMESTEST_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void MoveForward(float value);
	virtual void MoveRight(float value);
	virtual void Turn(float value);
	virtual void LookUp(float value);
	virtual void Jump();

	bool IsFalling();

	inline UCharacterAttributeComponent* GetCharacterAttributesComponent() { return CharacterAttributesComponent; }

	FOnStartPlay OnStartPlayEvent;
	FOnWinGame OnWinGameEvent;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Camera")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Components")
	UCharacterAttributeComponent* CharacterAttributesComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Character|Components")
	UWidgetComponent* HealthBarProgressComponent;

	virtual void OnDeath();

	void InitializeHealthProgress();
};
