#include "PresurePlate.h"
#include "Logging/StructuredLog.h"

APresurePlate::APresurePlate()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APresurePlate::BeginPlay()
{
	Super::BeginPlay();
}

void APresurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APresurePlate::OnActivate()
{
	UE_LOG(LogTemp, Warning, TEXT("APresurePlate::OnActivate"));
}

void APresurePlate::OnDeactivate()
{
	UE_LOG(LogTemp, Warning, TEXT("APresurePlate::OnDeactivate"));
}

void APresurePlate::NotifyActorBeginOverlap(AActor* otherActor)
{
	OnActivate();
}

void APresurePlate::NotifyActorEndOverlap(AActor* otherActor)
{
	OnDeactivate();
}





