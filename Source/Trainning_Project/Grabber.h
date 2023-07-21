#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINNING_PROJECT_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float maxGrabDistance = 300.f;
	UPROPERTY(EditAnywhere)
	float grabRadius = 100.f;
	UPROPERTY(EditAnywhere)
	float holdDistance = 200.f;
	UPROPERTY(EditAnywhere)
	float holdHeight = 200.f;

	UPhysicsHandleComponent* physicsHandle{};
	UWorld* world{};

public:
	UGrabber();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void Grab();
	UFUNCTION(BlueprintCallable)
	void Release();

protected:
	virtual void BeginPlay() override;

private:
	const bool TryGetGrabbableInReach(FHitResult& HitResult);
	void GrabActor(UPrimitiveComponent* TargetComponent, const FVector GrabPoint);
};
