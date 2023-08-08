
#include "LaunchPad.h"
#include "Components/AudioComponent.h"

ALaunchPad::ALaunchPad()
{
 	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	audioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	audioComponent->SetupAttachment(RootComponent);
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
		LaunchCharacter(character);
}

void ALaunchPad::LaunchCharacter(ACharacter* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor overlaped launchpad!"));
	if (audioComponent->Sound)
		audioComponent->Play();
	Character->GetCharacterMovement()->AddImpulse(impulseForce, true);
}
