
#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startPosition = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
	Rotate(DeltaTime);
}

void AMovingPlatform::Move(const float& DeltaTime)
{
	if (ShouldPlatformTurn())
	{
		CorrectOvershootPosition();
		moveSpeed = -moveSpeed;
	}
	else
	{
		FVector currentPosition = GetActorLocation();
		currentPosition += moveSpeed * DeltaTime;
		SetActorLocation(currentPosition);
	}
}

bool AMovingPlatform::ShouldPlatformTurn() const { return GetDistanceMoved() > moveThreshold; }

void AMovingPlatform::CorrectOvershootPosition()
{
	float overShoot = GetDistanceMoved() - moveThreshold;
	FVector moveDirection = moveSpeed.GetSafeNormal();
	startPosition += moveDirection * moveThreshold;
	SetActorLocation(startPosition);
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(startPosition, GetActorLocation());
}

void AMovingPlatform::Rotate(const float& DeltaTime)
{
	AddActorLocalRotation(rotateSpeed * DeltaTime);
}
