
#include "Checkpoint.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
//#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

ACheckpoint::ACheckpoint()
{
 	PrimaryActorTick.bCanEverTick = true;

	triggerComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger"));
	RootComponent = triggerComponent;

	particleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Particles"));
	particleSystem->SetupAttachment(RootComponent);
	
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshComponent->SetupAttachment(RootComponent);
}

void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
}

void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpoint::OnCheckpointReached()
{
	UE_LOG(LogTemp, Warning, TEXT("CheckPointReached at: %f %f"), GetActorLocation().X, GetActorLocation().Y);
	particleSystem->Activate();
	triggerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	meshComponent->SetMaterial(0, activatedMaterial);
}

