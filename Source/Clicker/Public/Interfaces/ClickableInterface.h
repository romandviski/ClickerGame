
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/ClickerPlayerController.h"
#include "ClickableInterface.generated.h"



UINTERFACE(MinimalAPI)
class UClickableInterface : public UInterface
{
	GENERATED_BODY()
};

class CLICKER_API IClickableInterface
{
	GENERATED_BODY()

public:
	virtual void Click(AClickerPlayerController* WhoClick) = 0;
};
