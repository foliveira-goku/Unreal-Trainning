#include "MoverComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Logging/StructuredLog.h"

UMoverComponent::UMoverComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoverComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMoverComponent::MoveEssaParada(UStaticMeshComponent* TargetMesh, FVector OriginalPosition, float DeltaTime)
{
	UE_LOGFMT(LogTemp, Warning, "MoveEssaParada!");
	FVector currentLocation = TargetMesh->GetRelativeLocation();

	FVector targetLocation = OriginalPosition + moveOffset;
	float moveSpeed = FVector::Distance(OriginalPosition, targetLocation) / moveDuration;

	FVector newLocation = FMath::VInterpConstantTo(currentLocation, targetLocation, DeltaTime, moveSpeed);
	TargetMesh->SetRelativeLocation(newLocation);
}