// Fill out your copyright notice in the Description page of Project Settings.


#include "DisappearPlatform.h"
#include "GameFramework/Character.h"

void ADisappearPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PlatformTimeline.TickTimeline(DeltaTime);
}

void ADisappearPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(ShineCurve))
	{
		FOnTimelineFloatStatic OnTimelineUpdate;
		OnTimelineUpdate.BindUFunction(this, FName("TickPlatformTimeline"));
		PlatformTimeline.AddInterpFloat(ShineCurve, OnTimelineUpdate);
	}
}

void ADisappearPlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADisappearPlatform::Disappear, ShineDelay, true);
	PlatformTimeline.Play();
}

void ADisappearPlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//PlatformTimeline.Reverse();
	GetWorldTimerManager().ClearTimer(TimerHandle);
	Super::OnTriggerOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void ADisappearPlatform::TickPlatformTimeline(float Value)
{
	BaseMaterial->SetScalarParameterValue(FName("Shine"), Value * ShineIntensity);
}

void ADisappearPlatform::Disappear()
{
	Destroy();
}
