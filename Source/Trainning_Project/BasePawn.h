#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ABasePawn : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float lookAtSpeed = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* capsuleComponent{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* baseMesh{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* turretMesh{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	USceneComponent* projectileSpawnPoint;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AProjectile> projectileClass;
	UPROPERTY(EditAnywhere)
	class UParticleSystem* deathParticles;

	UPROPERTY(EditAnywhere)
	class USoundBase* deathSound;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> cameraShakeClass;

protected:
	UPROPERTY()
	UWorld* world{};

public:
	ABasePawn();
	virtual void HandleDestruction();

protected:
	virtual void BeginPlay() override;
	void RotateTurret(const FVector& LookAtTarget);
	void Fire();
};
