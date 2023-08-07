
#include "Crystal.h"
#include "Components/CapsuleComponent.h"
#include "MyPlayerController.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"

ACrystal::ACrystal()
{
 	PrimaryActorTick.bCanEverTick = true;

	capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComponent;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	baseMesh->SetupAttachment(capsuleComponent);

	particleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Particles"));
	particleSystem->SetupAttachment(RootComponent);
}

void ACrystal::BeginPlay()
{
	Super::BeginPlay();
}

void ACrystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACrystal::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);

	if (auto actorPawn = Cast<APawn>(otherActor))
	{
		auto controller = Cast<AMyPlayerController>(actorPawn->GetController());
		if (controller)
		{
			controller->OnGameEnd.Broadcast();
			capsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			particleSystem->Activate();
			UGameplayStatics::PlaySoundAtLocation(this, onTriggeredSound, GetActorLocation());
		}
	}
}


