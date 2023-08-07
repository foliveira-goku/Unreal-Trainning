
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameEnd);

UCLASS()
class TRAINNING_PROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGameStart OnGameStart;
	UPROPERTY(BlueprintAssignable)
	FGameEnd OnGameEnd;
	UFUNCTION(BlueprintCallable)
	void CallGameStartEvent();
};
