// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBarWidget.generated.h"

/**
 * 
 */
class UProgressBar;
UCLASS()
class LESTAGAMESTEST_API UProgressBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetProgressPercentage(float Percentage);

protected:

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBar;

};
