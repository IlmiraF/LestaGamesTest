// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PlayerCharacter.h"
#include "../UI/Widgets/PlayerHUDWidget.h"
#include "../UI/Widgets/TimerWidget.h"
#include "../UI/Widgets/FinishMenuWidget.h"
#include "Components/CharacterAttributeComponent.h"

void AMyPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<APlayerCharacter>(InPawn);
	if (CachedBaseCharacter.IsValid())
	{
		CreateAndInitializeWidgets();
		CachedBaseCharacter->OnStartPlayEvent.AddUObject(this, &AMyPlayerController::StartPlaying);
		CachedBaseCharacter->OnWinGameEvent.AddUObject(this, &AMyPlayerController::WinGame);
		UCharacterAttributeComponent* CharacterAttributeComponent = CachedBaseCharacter->GetCharacterAttributesComponent();
		if (IsValid(CharacterAttributeComponent))
		{
			CharacterAttributeComponent->OnDeathEvent.AddUObject(this, &AMyPlayerController::OnDeath);
		}
	}
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsValid(PlayerHUDWidget) && bIsPlaying)
	{
		PlayerHUDWidget->GetTimerWidget()->UpdateTimer(GetWorld()->GetDeltaSeconds());
	}
	if (CachedBaseCharacter->IsFalling())
	{
		bIsPlaying = false;
		OnDeath();
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("Move Forward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("Move Right", this, &AMyPlayerController::MoveRight);
	InputComponent->BindAxis("Turn Right", this, &AMyPlayerController::Turn);
	InputComponent->BindAxis("Look Up", this, &AMyPlayerController::LookUp);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMyPlayerController::Jump);
}

void AMyPlayerController::MoveForward(float value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(value);
	}
}

void AMyPlayerController::MoveRight(float value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(value);
	}
}

void AMyPlayerController::Turn(float value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Turn(value);
	}
}

void AMyPlayerController::LookUp(float value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(value);
	}
}

void AMyPlayerController::Jump()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}

void AMyPlayerController::CreateAndInitializeWidgets()
{
	if (!IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget = CreateWidget<UPlayerHUDWidget>(GetWorld(), PlayerHUDWidgetClass);

		if (IsValid(PlayerHUDWidget))
		{
			PlayerHUDWidget->AddToViewport();
			PlayerHUDWidget->GetFinishMenuWidget()->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AMyPlayerController::StartPlaying(bool bIsPlaying_In)
{
	bIsPlaying = bIsPlaying_In;
}

void AMyPlayerController::OnDeath()
{
	if (IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget->GetTimerWidget()->SetVisibility(ESlateVisibility::Hidden);
		UFinishMenuWidget* FinishMenuWidget = PlayerHUDWidget->GetFinishMenuWidget();
		FinishMenuWidget->SetFinishMessage("You Lose!");
		FinishMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
	SetPause(true);
	bShowMouseCursor = true;
}

void AMyPlayerController::WinGame()
{
	if (IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget->GetTimerWidget()->SetVisibility(ESlateVisibility::Hidden);
		UFinishMenuWidget* FinishMenuWidget = PlayerHUDWidget->GetFinishMenuWidget();
		FinishMenuWidget->SetFinishMessage("You Win!");
		PlayerHUDWidget->GetTimerWidget()->SetVisibility(ESlateVisibility::Visible);
		FinishMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
	SetPause(true);
	bShowMouseCursor = true;
}
