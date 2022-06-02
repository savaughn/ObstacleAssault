// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity{};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector CurrentLocation{};

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float PathDistance{100.f};

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FRotator RotationSpeed{};

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	bool bIsClockwise{true};

	FVector StartLocation{};
	void MovePlatform(float deltaTime);
	void RotatePlatform(float deltaTime);
	bool shouldPlatformReturn(float distanceMoved);
};
