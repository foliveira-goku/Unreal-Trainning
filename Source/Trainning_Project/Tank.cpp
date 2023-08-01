
#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"

ATank::ATank()
{
	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring"));
	springArmComponent->SetupAttachment(RootComponent);

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(springArmComponent);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* pController = Cast<APlayerController>(Controller))
	{
		playerController = pController;
		if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pController->GetLocalPlayer()))
			subSystem->AddMappingContext(inputMappingContext, 0);
	}
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!playerController)
		return;

	FHitResult hitResult;
	playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,
											 false, hitResult);
	RotateTurret(hitResult.ImpactPoint);
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	isAlive = false;
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponent->BindAction(moveInput, ETriggerEvent::Triggered, this, &ATank::Move);
	enhancedInputComponent->BindAction(turnInput, ETriggerEvent::Triggered, this, &ATank::Turn);
	enhancedInputComponent->BindAction(fireInput, ETriggerEvent::Started, this, &ATank::Fire);
}

void ATank::Move(const FInputActionValue& Value)
{
	float movementInput = Value.Get<float>();
	
	FVector moveVector{movementInput, 0, 0};
	AddActorLocalOffset(moveVector * moveSpeed * world->DeltaTimeSeconds, true);
}

void ATank::Turn(const FInputActionValue& Value)
{
	float turningInput = Value.Get<float>();

	FRotator turnVector{ 0, turningInput, 0 };
	AddActorLocalRotation(turnVector * turnSpeed * world->DeltaTimeSeconds, true);
}

APlayerController* ATank::GetTankPlayerController() const { return playerController; }

const bool ATank::IsAlive() const {	return isAlive; }
