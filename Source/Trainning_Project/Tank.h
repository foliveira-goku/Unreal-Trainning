#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"
#include "Tank.generated.h"

UCLASS()
class TRAINNING_PROJECT_API ATank : public ABasePawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float moveSpeed = 300.f;
	UPROPERTY(EditAnywhere)
	float turnSpeed = 200.f;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* springArmComponent{};

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* cameraComponent{};

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputMappingContext* inputMappingContext{};
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* moveInput {};
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* turnInput{};
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* fireInput{};

	UPROPERTY()
	APlayerController* playerController{};

	UPROPERTY()
	bool isAlive{ true };

public:
	ATank();
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);
	APlayerController* GetTankPlayerController() const;
	const bool IsAlive() const;
protected:
	virtual void BeginPlay() override;
};
