#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TRAINNING_PROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* projectileMesh{};

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* projectileMovementComponent{};
	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* trailParticleSystemComponent{};

	UPROPERTY(EditAnywhere)
	float damage = 20.f;
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* hitParticles;

	UPROPERTY(EditAnywhere)
	class USoundBase* launchSound;	
	
	UPROPERTY(EditAnywhere)
	USoundBase* hitSound;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> cameraShakeClass;

public:
	AProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};