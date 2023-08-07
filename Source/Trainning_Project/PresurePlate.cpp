#include "PresurePlate.h"
#include "Logging/StructuredLog.h"
#include "Components/AudioComponent.h"

APresurePlate::APresurePlate()
{
	PrimaryActorTick.bCanEverTick = true;

	audioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	audioComponent->SetupAttachment(RootComponent);
}

void APresurePlate::BeginPlay()
{
	Super::BeginPlay();

	IOpenable* _openable = Cast<IOpenable>(openableActor);
	openable.SetObject(openableActor);
	openable.SetInterface(_openable);
}

void APresurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APresurePlate::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);
	OnActivate();
}

void APresurePlate::NotifyActorEndOverlap(AActor* otherActor)
{
	Super::NotifyActorEndOverlap(otherActor);

	TArray<AActor*> actors{};
	GetOverlappingActors(actors);
	
	if(actors.Num() <= 0)
		OnDeactivate();
}

void APresurePlate::OnActivate()
{
	UE_LOG(LogTemp, Warning, TEXT("APresurePlate::OnActivate"));

	if (audioComponent->Sound)
		audioComponent->Play();

	openable->Open();
}

void APresurePlate::OnDeactivate()
{
	UE_LOG(LogTemp, Warning, TEXT("APresurePlate::OnDeactivate"));

	GetWorldTimerManager().SetTimer(timerHandle, this, &APresurePlate::OnDeactivateTimerEnd, closeDelay);
}


void APresurePlate::OnDeactivateTimerEnd() { openable->Close(); }