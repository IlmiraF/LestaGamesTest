// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlatform.h"
#include "Components/TimelineComponent.h"
#include "WindPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API AWindPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	virtual void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform movement")
	UCurveFloat* MovementCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wind Settings")
	float WindForce = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wind Settings")
	float WindDelay = 2.0f;

private:
	TWeakObjectPtr<APlayerCharacter> BaseCharacter;

	FTimerHandle TimerHandle;
	FTimeline PlatformTimeline;

	UFUNCTION()
	void TickPlatformTimeline(float Value);

	void BlowWind();

	FVector StartLocation = FVector::ZeroVector;
	FVector EndLocation = FVector::ZeroVector;
	
};
