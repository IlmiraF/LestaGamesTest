// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"

/**
 * 
 */
class UTimerWidget;
class UFinishMenuWidget;
UCLASS()
class LESTAGAMESTEST_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UTimerWidget* GetTimerWidget();
	UFinishMenuWidget* GetFinishMenuWidget();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Names")
	FName TimerWidgetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Names")
	FName FinishMenuWidgetName;
	
};
