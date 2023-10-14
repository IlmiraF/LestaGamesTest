// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FinishMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class LESTAGAMESTEST_API UFinishMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetFinishMessage(FString Message);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FinishMessage")
	FText FinishMessage;

	UFUNCTION(BlueprintCallable)
	void RestartGame();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName MapName;
	
};
