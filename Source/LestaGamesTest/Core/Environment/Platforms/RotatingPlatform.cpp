// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator NewRotation = GetActorRotation();

	NewRotation.Yaw += YawValue * DeltaTime;

	SetActorRotation(NewRotation);
}

void ARotatingPlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ARotatingPlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnTriggerOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}


