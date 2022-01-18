// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoorTP.h"

// Sets default values for this component's properties
UOpenDoorTP::UOpenDoorTP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorTP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenDoorTP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ensure(Trigger)) {
		float TotMass = GetTotMass();
		//UE_LOG(LogTemp, Warning, TEXT("%f / %f"), TotMass, MaxMass);
		if (TotMass >= MaxMass) {
			OpenDoor();
		}
		else {
			CloseDoor();
		}
	}
	// ...
}

void UOpenDoorTP::OpenDoor()
{
	OpenDoorRequest.Broadcast();
}

void UOpenDoorTP::CloseDoor()
{
	CloseDoorRequest.Broadcast();
}

float UOpenDoorTP::GetTotMass()
{
	float TotMass = 0.f;

	TArray<AActor*> ActorCollision;
	Trigger->GetOverlappingActors(ActorCollision);

	for (AActor* Actor : ActorCollision) {
		TotMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotMass;
}

