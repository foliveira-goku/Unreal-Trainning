#pragma once

#include "CoreMinimal.h"
#include "Openable.h"
#include "Door.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ADoor : public AActor, public IOpenable
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* leftDoor;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* rightDoor;

	UPROPERTY(EditAnywhere)
	FRotator openedDoorRoration{};
	
public:
	ADoor();
	virtual void Tick(float DeltaTime) override;
	virtual void Open() override;
	virtual void Close() override;

protected:
	virtual void BeginPlay() override;

};