#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TanksPlayerController.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ATanksPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void SetPlayerEnabledState(bool playerEnabled);
};
