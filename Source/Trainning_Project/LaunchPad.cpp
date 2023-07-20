
#include "LaunchPad.h"

ALaunchPad::ALaunchPad()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALaunchPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (ACharacter* character = Cast<ACharacter>(OtherActor))
	{
		LaunchCharacter(character);
	}
}

void ALaunchPad::LaunchCharacter(ACharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor overlaped launchpad!"));
	Character->GetCharacterMovement()->AddImpulse(impulseForce, true);
}
