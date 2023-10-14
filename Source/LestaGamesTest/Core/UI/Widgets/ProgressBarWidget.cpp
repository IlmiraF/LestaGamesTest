// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressBarWidget.h"
#include "Components/ProgressBar.h"

void UProgressBarWidget::SetProgressPercentage(float Percentage)
{
	ProgressBar->SetPercent(Percentage);
}
