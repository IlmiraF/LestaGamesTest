// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/CharacterAttributeComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../UI/Widgets/ProgressBarWidget.h"

// Sets default values
APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer)
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	CharacterAttributesComponent = CreateDefaultSubobject<UCharacterAttributeComponent>(TEXT("CharacterAttributes"));
	HealthBarProgressComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarProgressComponent"));
	HealthBarProgressComponent->SetupAttachment(GetCapsuleComponent());
}

void APlayerCharacter::MoveForward(float value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, value);
	}
}

void APlayerCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void APlayerCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void APlayerCharacter::Jump()
{
	Super::Jump();
}

bool APlayerCharacter::IsFalling()
{
	return GetActorLocation().Z <= 0.0f;
}

void APlayerCharacter::InitializeHealthProgress()
{
	UProgressBarWidget* Widget = Cast<UProgressBarWidget>(HealthBarProgressComponent->GetUserWidgetObject());
	if (!IsValid(Widget))
	{
		HealthBarProgressComponent->SetVisibility(false);
		return;
	}

	CharacterAttributesComponent->OnHealthChangedEvent.AddUObject(Widget, &UProgressBarWidget::SetProgressPercentage);
	CharacterAttributesComponent->OnDeathEvent.AddLambda([=]() {HealthBarProgressComponent->SetVisibility(false);});
	Widget->SetProgressPercentage(CharacterAttributesComponent->GetHealthPercent());
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CharacterAttributesComponent->OnDeathEvent.AddUObject(this, &APlayerCharacter::OnDeath);
	InitializeHealthProgress();
}

void APlayerCharacter::OnDeath()
{
	GetCharacterMovement()->DisableMovement();
	if (OnStartPlayEvent.IsBound())
	{
		OnStartPlayEvent.Broadcast(false);
	}
}
