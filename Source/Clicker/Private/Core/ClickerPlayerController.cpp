// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/ClickerPlayerController.h"

#include "Interfaces/ClickableInterface.h"

AClickerPlayerController::AClickerPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void AClickerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// If we have a valid InputComponent...
	if (InputComponent)
	{
		// Bind an action to it
		InputComponent->BindAction
		(
			"LeftClick", // The input identifier (specified in DefaultInput.ini)
			IE_Pressed, // React when button pressed (or on release, etc., if desired)
			this, // The object instance that is going to react to the input
			&ThisClass::ClickCallback // The function that will fire when input is received
		); 
	}
}

void AClickerPlayerController::ClickCallback()
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Кнопка нажата!"));
	
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if(!HitResult.bBlockingHit) return;

	if(const auto Clickable = Cast<IClickableInterface>(HitResult.GetActor()))
	{
		Clickable->Click(this);
	}
}
