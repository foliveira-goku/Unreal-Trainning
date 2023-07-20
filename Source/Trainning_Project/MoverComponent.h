#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINNING_PROJECT_API UMoverComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float moveDuration;
	UPROPERTY(EditAnywhere)
	FVector moveOffset;
	
public:
	UPROPERTY(EditAnywhere)
	bool shouldMove;

public:
	UMoverComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	
	UFUNCTION(BlueprintCallable)
	void MoveEssaParada(UStaticMeshComponent* TargetMesh, FVector OriginalPosition, float DeltaTime);
};
