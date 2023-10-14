// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlatform.h"
#include "StartFinishPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API AStartFinishPlatform : public ABasePlatform
{
	GENERATED_BODY()

protected:
	virtual void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

private:
	TWeakObjectPtr<APlayerCharacter> BaseCharacter;
	
};
