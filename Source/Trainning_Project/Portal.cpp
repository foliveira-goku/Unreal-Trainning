
#include "Portal.h"
#include "Kismet/GameplayStatics.h"

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
	portalMesh->SetVisibility(false);
	portalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APortal::Close()
{
	UGameplayStatics::PlaySoundAtLocation(this, closeSound, GetActorLocation());
	portalMesh->SetVisibility(true);
	portalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

