// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatform::MovePlatform(float DeltaTime) {
	CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	float DistanceMoved = FVector::Distance(CurrentLocation, StartLocation);
	if (shouldPlatformReturn(DistanceMoved)) {
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (PathDistance * MoveDirection);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime) {
	FRotator CurrentRotation = GetActorRotation();
	int direction = bIsClockwise ? 1 : -1;
	CurrentRotation= CurrentRotation + (direction * RotationSpeed * DeltaTime);
	SetActorRotation(CurrentRotation);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

bool AMovingPlatform::shouldPlatformReturn(float distanceMoved) {
	return distanceMoved > PathDistance;
}

