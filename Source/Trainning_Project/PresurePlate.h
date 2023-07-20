#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.h"
#include "PresurePlate.generated.h"

UCLASS()
class TRAINNING_PROJECT_API APresurePlate : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	ADoor* doorActor;

	UPROPERTY(EditAnywhere)
	float closeDelay{};

	FTimerHandle timerHandle{};

public:
	APresurePlate();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnActivate();
	UFUNCTION()
	void OnDeactivate();
protected:

	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;
	virtual void NotifyActorEndOverlap(AActor* otherActor) override;
	virtual void BeginPlay() override;
};
