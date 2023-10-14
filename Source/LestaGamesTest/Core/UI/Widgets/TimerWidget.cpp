// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"

void UTimerWidget::UpdateTimer(float Time)
{
	UnroundSeconds += Time;
	CurrentSeconds = FMath::RoundToInt32(UnroundSeconds);
	if (UnroundSeconds >= 60.0f)
	{
		UnroundSeconds = 0.0f;
		CurrentSeconds = 0.0f;
		++CurrentMinutes;
	}
}

void UTimerWidget::SetCurrentTime(int32 Minutes, int32 Seconds)
{
	CurrentMinutes = Minutes;
	CurrentSeconds = Seconds;
}
