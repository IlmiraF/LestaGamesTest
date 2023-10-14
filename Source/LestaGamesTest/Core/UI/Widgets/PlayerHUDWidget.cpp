// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"
#include "Blueprint/WidgetTree.h"
#include "TimerWidget.h"
#include "FinishMenuWidget.h"

UTimerWidget* UPlayerHUDWidget::GetTimerWidget()
{
	return WidgetTree->FindWidget<UTimerWidget>(TimerWidgetName);
}

UFinishMenuWidget* UPlayerHUDWidget::GetFinishMenuWidget()
{
	return WidgetTree->FindWidget<UFinishMenuWidget>(FinishMenuWidgetName);
}
