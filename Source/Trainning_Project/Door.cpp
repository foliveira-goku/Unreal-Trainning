
#include "Door.h"

ADoor::ADoor()
{
 	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	leftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Door"));
	leftDoor->SetupAttachment(RootComponent);
	rightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Door"));
	rightDoor->SetupAttachment(RootComponent);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoor::Open()
{
	UE_LOG(LogTemp, Warning, TEXT("ADoor::Open"));
	leftDoor->SetRelativeRotation(openedDoorRoration * -1);
	rightDoor->SetRelativeRotation(openedDoorRoration);
}

void ADoor::Close()
{
	leftDoor->SetRelativeRotation(FRotator::ZeroRotator);
	rightDoor->SetRelativeRotation(FRotator::ZeroRotator);
}

