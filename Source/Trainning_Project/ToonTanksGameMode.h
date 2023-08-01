
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

UCLASS()
class TRAINNING_PROJECT_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float startDelay = 3.f;

	UPROPERTY()
	class ATank* tank{};

	UPROPERTY()
	class ATanksPlayerController* tanksPlayerController{};

	UPROPERTY()
	int32 towerCount{};

public:
	void ActorDied(AActor* DeadActor);
	void HandleGameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool WonGame);
protected:
	virtual void BeginPlay() override;

private:
	int32 GetTowerActorsCount();
};
