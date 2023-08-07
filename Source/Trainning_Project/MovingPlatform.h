#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class TRAINNING_PROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)	FVector moveSpeed;
	UPROPERTY(EditAnywhere)	float moveThreshold;
	UPROPERTY(EditAnywhere)	FRotator rotateSpeed;

	UPROPERTY(VisibleAnywhere)
	class UAudioComponent* audioComponent;

	UPROPERTY()
	FVector startPosition;
	UPROPERTY()
	bool canMove = false;
	
public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void CorrectOvershootPosition();
	void Move(const float& DeltaTime);
	void Rotate(const float& DeltaTime);
	bool ShouldPlatformTurn() const;
	float GetDistanceMoved() const;
	UFUNCTION()
	void StartMoving();
};