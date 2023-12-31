// Fill out your copyright notice in the Description page of Project Settings.


#include "WindPlatform.h"
#include "GameFramework/Character.h"
#include "../../Character/PlayerCharacter.h"

void AWindPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PlatformTimeline.TickTimeline(DeltaTime);
}

void AWindPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(MovementCurve))
	{
		FOnTimelineFloatStatic OnTimelineUpdate;
		OnTimelineUpdate.BindUFunction(this, FName("TickPlatformTimeline"));
		PlatformTimeline.AddInterpFloat(MovementCurve, OnTimelineUpdate);
	}
}

void AWindPlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	BaseCharacter = Cast<APlayerCharacter>(OtherActor);
	if (!BaseCharacter.IsValid())
	{
		return;
	}
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AWindPlatform::BlowWind, WindDelay, true);
}

void AWindPlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GetWorldTimerManager().ClearTimer(TimerHandle);
	Super::OnTriggerOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AWindPlatform::TickPlatformTimeline(float Value)
{
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Value);
	if (BaseCharacter.IsValid())
	{
		BaseCharacter->SetActorLocation(NewLocation);
	}
}

void AWindPlatform::BlowWind()
{
	StartLocation = BaseCharacter->GetActorLocation();
	FVector WindDirection = FVector::ForwardVector * FMath::RandRange(-1, 1) + FVector::RightVector * FMath::RandRange(-1, 1);
	EndLocation = StartLocation + WindDirection * WindForce;
	PlatformTimeline.PlayFromStart();
}
