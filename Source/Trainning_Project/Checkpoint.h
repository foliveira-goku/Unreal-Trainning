#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

class UCapsuleComponent;
class UNiagaraComponent;
class UAudioComponent;

UCLASS()
class TRAINNING_PROJECT_API ACheckpoint : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* triggerComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UNiagaraComponent* particleSystem;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* meshComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* audioComponent;

	UPROPERTY(EditAnywhere, Category = "Visual")
	UMaterialInstance* activatedMaterial;

public:
	ACheckpoint();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void OnCheckpointReached();

protected:
	virtual void BeginPlay() override;
};