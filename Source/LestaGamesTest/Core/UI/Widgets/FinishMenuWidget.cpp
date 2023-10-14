// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void UFinishMenuWidget::SetFinishMessage(FString Message)
{
	FinishMessage = FText::FromString(Message);
}

void UFinishMenuWidget::RestartGame()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	UGameplayStatics::OpenLevel(GetWorld(), MapName, true, "listen");
}
