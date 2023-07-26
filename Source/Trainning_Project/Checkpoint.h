#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
	
public:
	ACheckpoint();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};