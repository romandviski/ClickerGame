// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ClickableActor.h"


// Sets default values
AClickableActor::AClickableActor()
{
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->SetCollisionResponseToAllChannels(ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	SetRootComponent(Collision);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	StaticMesh->SetupAttachment(Collision);
}

void AClickableActor::Click(AClickerPlayerController* WhoClick)
{
	if(!WhoClick) return;
	
	OnClick();
}

// Called when the game starts or when spawned
void AClickableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClickableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

