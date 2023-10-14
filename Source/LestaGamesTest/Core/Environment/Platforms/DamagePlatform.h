// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlatform.h"
#include "Components/TimelineComponent.h"
#include "DamagePlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API ADamagePlatform : public ABasePlatform
{
	GENERATED_BODY()

protected:

	virtual void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Colors")
	FVector BaseColor = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Colors")
	FVector ReloadColor = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Colors")
	FVector DamageColor = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float Damage = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float DamageDelay = 5.0f;

private:

	TWeakObjectPtr<APlayerCharacter> BaseCharacter;

	FTimerHandle TimerHandle;
	FTimerHandle ColorHandle;

	void Reload();
	void MakeDamage();
	void SetColor(FVector NewColor);
};
