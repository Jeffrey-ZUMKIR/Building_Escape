// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabberTP.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabberTP::UGrabberTP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberTP::BeginPlay()
{
	Super::BeginPlay();

	//Reach = 500.f;

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (ensure(PhysicsHandle))
	{
		UE_LOG(LogTemp, Error, TEXT("%s: PhysicsHandle component found"), *GetOwner()->GetName());
	}
	// ...
	
}


// Called every frame
void UGrabberTP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle){return;}
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetEndVector());
	}
	// ...
}

void UGrabberTP::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab"));
	FHitResult Hit;

	FVector StartV = GetStartVector();
	FVector EndV = GetEndVector();

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	DrawDebugLine(
		GetWorld(),
		StartV,
		EndV,
		FColor::Red,
		false,
		2.f,
		0,
		5
	);

	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		StartV,
		EndV,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	AActor* ActorHit = Hit.GetActor();

	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("%s hit"), *ActorHit->GetName());
		if (!PhysicsHandle) {
			return;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Grab"));
			PhysicsHandle->GrabComponentAtLocation
			(
				Hit.GetComponent(),
				NAME_None,
				EndV
			);
		}
	}
}

void UGrabberTP::Release()
{
	if (!PhysicsHandle) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Grabber released"));
	PhysicsHandle->ReleaseComponent();
}

FVector UGrabberTP::GetStartVector()
{
	//return GetOwner()->GetActorLocation();

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
	return PlayerViewPointLocation;
}

FVector UGrabberTP::GetEndVector()
{
	//return (GetOwner()->GetActorForwardVector() * Reach) + GetOwner()->GetActorLocation();

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}



