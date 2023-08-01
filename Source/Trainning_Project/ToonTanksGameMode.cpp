
#include "ToonTanksGameMode.h"
#include "TanksPlayerController.h"
#include "Tank.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == tank)
	{
		tank->HandleDestruction();
		if (tanksPlayerController)
			tanksPlayerController->SetPlayerEnabledState(false);

		GameOver(false);
	}
	else if (ATower* tower = Cast<ATower>(DeadActor))
	{
		tower->HandleDestruction();
		towerCount--;
		if (towerCount <= 0)
			GameOver(true);
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	towerCount = GetTowerActorsCount();
	HandleGameStart();
}

int32 AToonTanksGameMode::GetTowerActorsCount()
{
	TArray<AActor*> towerActors{};
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), towerActors);
	return towerActors.Num();
}

void AToonTanksGameMode::HandleGameStart()
{
	tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	tanksPlayerController = Cast<ATanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (tanksPlayerController)
	{
		tanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle timerHandle{};
		FTimerDelegate timerDelegate
		{
			FTimerDelegate::CreateUObject(tanksPlayerController,
										 &ATanksPlayerController::SetPlayerEnabledState, 
										 true)
		};
		GetWorldTimerManager().SetTimer(timerHandle, timerDelegate, startDelay, false);
	}
}
