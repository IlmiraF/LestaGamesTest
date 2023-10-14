// Fill out your copyright notice in the Description page of Project Settings.


#include "StartFinishPlatform.h"
#include "../../Character/PlayerCharacter.h"

void AStartFinishPlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	BaseCharacter = Cast<APlayerCharacter>(OtherActor);
	if (BaseCharacter.IsValid())
	{
		if (BaseCharacter->OnWinGameEvent.IsBound() && BaseCharacter->OnStartPlayEvent.IsBound())
		{
			BaseCharacter->OnWinGameEvent.Broadcast();
			BaseCharacter->OnStartPlayEvent.Broadcast(false);
		}
	}
}

void AStartFinishPlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnTriggerOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	BaseCharacter = Cast<APlayerCharacter>(OtherActor);
	if (BaseCharacter.IsValid())
	{
		if (BaseCharacter->OnStartPlayEvent.IsBound())
		{
			BaseCharacter->OnStartPlayEvent.Broadcast(true);
		}
	}
}
