// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlatform.h"
#include "RotatingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API ARotatingPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotation")
	float YawValue = 60.0f;
};
