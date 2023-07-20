#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ADoor : public AActor
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
	void Open();
	void Close();

protected:
	virtual void BeginPlay() override;

};