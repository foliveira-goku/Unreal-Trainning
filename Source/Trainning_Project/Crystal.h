#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crystal.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ACrystal : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* capsuleComponent{};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* baseMesh{};

	UPROPERTY(VisibleAnywhere)
	class UNiagaraComponent* particleSystem;

	UPROPERTY(EditAnywhere)
	class USoundBase* onTriggeredSound;
	
public:
	ACrystal();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;
};