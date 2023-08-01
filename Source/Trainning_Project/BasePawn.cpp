
#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComponent;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	baseMesh->SetupAttachment(capsuleComponent);

	turretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	turretMesh->SetupAttachment(baseMesh);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(turretMesh);
}

void ABasePawn::HandleDestruction()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, deathParticles, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySoundAtLocation(this, deathSound, GetActorLocation());
	GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(cameraShakeClass);
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
}

void ABasePawn::RotateTurret(const FVector& LookAtTarget)
{
	FVector target = LookAtTarget - turretMesh->GetComponentLocation();
	FRotator lookAtRotation{ 0.f, target.Rotation().Yaw, 0.f };

	turretMesh->SetWorldRotation(FMath::RInterpTo(turretMesh->GetComponentRotation(),
								lookAtRotation, world->DeltaRealTimeSeconds, lookAtSpeed));
}

void ABasePawn::Fire()
{
	auto projectile = world->SpawnActor<AProjectile>(projectileClass,
								   projectileSpawnPoint->GetComponentLocation(),
								   projectileSpawnPoint->GetComponentRotation());
	projectile->SetOwner(this);
}