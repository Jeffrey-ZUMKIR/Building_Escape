// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoorTP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoorTP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorTP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OpenDoorRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent CloseDoorRequest;

	void OpenDoor();

	void CloseDoor();

	float GetTotMass();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Trigger = nullptr;

	UPROPERTY(EditAnywhere)
		float MaxMass;
};

