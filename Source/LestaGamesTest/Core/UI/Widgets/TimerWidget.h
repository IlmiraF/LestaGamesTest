// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
	int32 CurrentMinutes = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
	int32 CurrentSeconds = 0.0f;

public:

	UFUNCTION()
	void UpdateTimer(float Time);

	void SetCurrentTime(int32 Minutes, int32 Seconds);

	int32 GetCurrentMinutes() { return CurrentMinutes; }
	int32 GetCurrentSeconds() { return CurrentSeconds; }

private:
	float UnroundSeconds;
};
