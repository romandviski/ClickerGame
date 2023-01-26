// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClickerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CLICKER_API AClickerPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AClickerPlayerController();
protected:
	virtual void BeginPlay() override;
private:
	void ClickCallback();
};
