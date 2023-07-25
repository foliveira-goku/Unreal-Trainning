
#include "Portal.h"

APortal::APortal()
{
 	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	portalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Portal"));
	portalMesh->SetupAttachment(RootComponent);
}

void APortal::BeginPlay()
{
	Super::BeginPlay();
}

void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APortal::Open()
{
	UE_LOG(LogTemp, Warning, TEXT("The portal opened!"));
	portalMesh->SetVisibility(false);
	portalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APortal::Close()
{
	UE_LOG(LogTemp, Warning, TEXT("The portal closed!"));
	portalMesh->SetVisibility(true);
	portalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

