// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Platforms/ModifiablePlatforms.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AModifiablePlatforms::AModifiablePlatforms()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	//boxComponent = CreateDefaultSubobject<UBoxComponent>("Box Collider");
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	SetRootComponent(staticMesh);
	//staticMesh->SetupAttachment(boxComponent);

	MaxExtension = 3.f;
	canMove = true;
	isMoving = false;
	extensionSpeed = 1.f;
}

// Called when the game starts or when spawned
void AModifiablePlatforms::BeginPlay()
{
	Super::BeginPlay();
	originalSize = GetActorScale().Y;
	currentExtension = originalSize;
}
	
void AModifiablePlatforms::ExtensionBegin()
{
	if (canMove)
	{
		canMove = false;
		PrimaryActorTick.SetTickFunctionEnable(true);
}
}

// Called every frame
void AModifiablePlatforms::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentExtension = FMath::Lerp(currentExtension, MaxExtension, DeltaTime * extensionSpeed);
	if (currentExtension >= MaxExtension)
	{
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
	else {
		SetActorRelativeScale3D(FVector(this->GetActorRelativeScale3D().X, currentExtension, GetActorRelativeScale3D().Z));
	}
}

