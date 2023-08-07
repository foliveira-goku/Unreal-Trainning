#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Openable.h"
#include "Portal.generated.h"

UCLASS()
class TRAINNING_PROJECT_API APortal : public AActor, public IOpenable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* portalMesh;
	
	UPROPERTY(EditAnywhere)
	class USoundBase* closeSound;

public:
	APortal();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void Open() override;
	UFUNCTION()
	virtual void Close() override;

protected:
	virtual void BeginPlay() override;
};