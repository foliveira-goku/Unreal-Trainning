
#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AProjectile::AProjectile()
{
 	PrimaryActorTick.bCanEverTick = false;

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = projectileMesh;

	trailParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Trail"));
	trailParticleSystemComponent->SetupAttachment(RootComponent);

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	projectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	UGameplayStatics::PlaySoundAtLocation(this, launchSound, GetActorLocation());
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("HIT!"));

	auto owner = GetOwner();
	if (!owner)
	{
		Destroy();
		return;
	}

	auto instigatorController = owner->GetInstigatorController();
	auto damageTypeClass = UDamageType::StaticClass();

	if(OtherActor && OtherActor != this && OtherActor != owner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, damage, instigatorController, this, damageTypeClass);
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(cameraShakeClass);
	}
	UGameplayStatics::PlaySoundAtLocation(this, hitSound, GetActorLocation());
	UGameplayStatics::SpawnEmitterAtLocation(this, hitParticles, GetActorLocation(), GetActorRotation());
	Destroy();
}

