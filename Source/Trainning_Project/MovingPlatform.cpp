
#include "MovingPlatform.h"
#include "Components/AudioComponent.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	audioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	audioComponent->SetupAttachment(RootComponent);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startPosition = GetActorLocation();
	audioComponent->SetPitchMultiplier(1/moveSpeed.Size());
	audioComponent->Play();
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
		if (audioComponent->Sound)
		{
			audioComponent->Stop();
			audioComponent->Play(0.f);
		}
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
