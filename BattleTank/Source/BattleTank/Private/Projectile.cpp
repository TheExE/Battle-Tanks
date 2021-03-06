// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile movement component"));
	if (MovementComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error something went siriously wrong and movement component failed to create !"));
	}
	else
	{
		MovementComponent->bAutoActivate = false;
	}
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{
	if (MovementComponent != nullptr)
	{
		MovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
		MovementComponent->Activate();
	}
}

