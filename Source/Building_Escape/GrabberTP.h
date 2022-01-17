// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberTP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabberTP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberTP();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		float Reach;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void Grab();
	UFUNCTION(BlueprintCallable)
		void Release();

	FVector GetStartVector();
	FVector GetEndVector();
	
private:
	UPROPERTY()
		UPhysicsHandleComponent* PhysicsHandle = nullptr;


};
