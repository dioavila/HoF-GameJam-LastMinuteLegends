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
	toExtend = true;
	extensionSpeed = 1.f;
	timeToRetract = 2.f;
}

// Called when the game starts or when spawned
void AModifiablePlatforms::BeginPlay()
{
	Super::BeginPlay();
	originalSize = GetActorScale().Y;
	currentExtension = originalSize;
}

void AModifiablePlatforms::RetractionBegin()
{
	PrimaryActorTick.SetTickFunctionEnable(true);
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

	if(toExtend)
	{
		currentExtension = FMath::Lerp(currentExtension, MaxExtension, DeltaTime * extensionSpeed);
		if (currentExtension >= MaxExtension-.1f)
		{
			toExtend = false;
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AModifiablePlatforms::RetractionBegin, timeToRetract);
			SetActorRelativeScale3D(FVector(this->GetActorRelativeScale3D().X, MaxExtension, GetActorRelativeScale3D().Z));
			PrimaryActorTick.SetTickFunctionEnable(false);
		}
		else {
			SetActorRelativeScale3D(FVector(this->GetActorRelativeScale3D().X, currentExtension, GetActorRelativeScale3D().Z));
		}
	}
	else 
	{
		currentExtension = FMath::Lerp(currentExtension, originalSize, DeltaTime * extensionSpeed);
		if (currentExtension <= originalSize+.1f)
		{
			toExtend = true;
			canMove = true;
			SetActorRelativeScale3D(FVector(this->GetActorRelativeScale3D().X, originalSize, GetActorRelativeScale3D().Z));
			PrimaryActorTick.SetTickFunctionEnable(false);
		}
		else {
			SetActorRelativeScale3D(FVector(this->GetActorRelativeScale3D().X, currentExtension, GetActorRelativeScale3D().Z));
		}
	}
}

