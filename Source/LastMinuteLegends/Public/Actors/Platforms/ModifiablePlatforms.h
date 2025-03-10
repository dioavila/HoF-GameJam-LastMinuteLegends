// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModifiablePlatforms.generated.h"

UCLASS()
class LASTMINUTELEGENDS_API AModifiablePlatforms : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModifiablePlatforms();
	void ExtensionBegin();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(BlueprintReadWrite, Category = "Platforming Settings")
	float MaxExtension;

	UPROPERTY(VisibleAnywhere, Category = "Platforming Settings")
	float originalSize;

	UPROPERTY(BlueprintReadWrite, Category = "Platforming Settings")
	float extensionSpeed;

private:
	bool isMoving;
	bool canMove;
	float currentExtension;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
