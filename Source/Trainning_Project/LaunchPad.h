#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LaunchPad.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FVector impulseForce;

public:
	ALaunchPad();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	void LaunchCharacter(ACharacter* Character);

};