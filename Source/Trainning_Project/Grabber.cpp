
#include "Grabber.h"

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	physicsHandle = GetOwner()->GetComponentByClass<UPhysicsHandleComponent>();
	world = GetWorld();
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (physicsHandle == nullptr || physicsHandle->GetGrabbedComponent() == nullptr)
		return;

	FVector targetPosition = GetComponentLocation() + GetForwardVector() * holdDistance;
	targetPosition += FVector::UpVector * holdHeight;
	physicsHandle->SetTargetLocationAndRotation(targetPosition, GetComponentRotation());
}

void UGrabber::Grab()
{
	if (physicsHandle == nullptr)
		return;

	FHitResult hitResult{};
	bool hasHit = TryGetGrabbableInReach(hitResult);

	if (hasHit)
		GrabActor(hitResult.GetComponent(), hitResult.ImpactPoint);
	else
		UE_LOG(LogTemp, Warning, TEXT("No Actor hit!"));
}

const bool UGrabber::TryGetGrabbableInReach(FHitResult& HitResult)
{
	FVector start = GetComponentLocation();
	FVector end = start + GetForwardVector() * maxGrabDistance;
	DrawDebugSphere(world, end, 10, 10, FColor::Blue, false, 5);
	FCollisionShape sphereShape = FCollisionShape::MakeSphere(grabRadius);

	return world->SweepSingleByChannel(HitResult, start, end, FQuat::Identity,
		ECC_GameTraceChannel1, sphereShape);
}

void UGrabber::GrabActor(UPrimitiveComponent* TargetComponent, const FVector GrabPoint)
{
	TargetComponent->WakeAllRigidBodies();
	physicsHandle->GrabComponentAtLocationWithRotation(TargetComponent,	NAME_None,
													GrabPoint, GetComponentRotation());
}

void UGrabber::Release()
{
	if (physicsHandle == nullptr || physicsHandle->GetGrabbedComponent() == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("UGrabber::Released!"));
	physicsHandle->ReleaseComponent();
}

