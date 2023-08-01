
#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ATower : public ABasePawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Combat")
	float fireRange;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float fireRate = 2.f;

	UPROPERTY()
	class ATank* tank;
	
	UPROPERTY()
	FTimerHandle fireRateTimerHandle;
	UPROPERTY()
	bool isTargetInRange{};
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;
private:
	void CheckFireCondition();
};
