
#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Core/ClickerPlayerController.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ClickableInterface.h"
#include "ClickableActor.generated.h"

UCLASS()
class CLICKER_API AClickableActor : public AActor, public IClickableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AClickableActor();

	// Interface
	UFUNCTION(BlueprintCallable)
	virtual void Click(AClickerPlayerController* WhoClick) override;
	// Interface End
	
	protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* Collision;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;

	UFUNCTION(BlueprintImplementableEvent)
	void OnClick();

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
