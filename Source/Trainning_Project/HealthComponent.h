#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINNING_PROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float maxHealth = 100.f;

	UPROPERTY()
	float currentHealth{};

	UPROPERTY()
	class AToonTanksGameMode* tanksGameMode;

public:
	UHealthComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);
};
