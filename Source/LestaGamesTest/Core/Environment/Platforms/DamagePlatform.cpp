// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagePlatform.h"
#include "../../Character/PlayerCharacter.h"

void ADamagePlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	Reload();
	BaseCharacter = Cast<APlayerCharacter>(OtherActor);
	if (!BaseCharacter.IsValid())
	{
		return;
	}
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADamagePlatform::MakeDamage, DamageDelay, true, 1.0f);
}

void ADamagePlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GetWorldTimerManager().ClearTimer(TimerHandle);
	SetColor(BaseColor);
	Super::OnTriggerOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void ADamagePlatform::MakeDamage()
{
	SetColor(DamageColor);
	FPointDamageEvent DamageEvent;

	BaseCharacter->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);
	GetWorld()->GetTimerManager().SetTimer(ColorHandle, this, &ADamagePlatform::Reload, 1.0f, false);
}

void ADamagePlatform::SetColor(FVector NewColor)
{
	BaseMaterial->SetVectorParameterValue(FName("BaseColor"), NewColor);
}

void ADamagePlatform::Reload()
{
	SetColor(ReloadColor);
}
