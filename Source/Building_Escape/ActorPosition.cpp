// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPosition.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UActorPosition::UActorPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorPosition::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GEngine != nullptr) {
		//GEngine->AddOnScreenDebugMessage(0, 2, FColor::Green, *GetName());

		//GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, *GetLocation().ToString());
	}

	//UE_LOG(LogTemp, Warning, TEXT("Name: %s, Position: %s"), *GetName(), *GetLocation().ToString());
	

	// ...
}

FString UActorPosition::GetName() const
{
	return GetOwner()->GetName();
}

FVector UActorPosition::GetLocation() const
{
	return GetOwner()->GetActorLocation();
}

