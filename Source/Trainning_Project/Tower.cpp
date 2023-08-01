
#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(fireRateTimerHandle, this, &ATower::CheckFireCondition, fireRate, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!tank)
		return;
	
	float distanceToTank = FVector::Dist(GetActorLocation(), tank->GetActorLocation());
	isTargetInRange = distanceToTank <= fireRange;
	if(isTargetInRange)
		RotateTurret(tank->GetActorLocation());
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::CheckFireCondition()
{
	if(isTargetInRange && tank->IsAlive())
		Fire();
}
