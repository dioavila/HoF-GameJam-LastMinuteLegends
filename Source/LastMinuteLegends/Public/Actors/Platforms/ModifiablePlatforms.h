// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModifiablePlatforms.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlatformMove);

UCLASS()
class LASTMINUTELEGENDS_API AModifiablePlatforms : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModifiablePlatforms();
	void ExtensionBegin();

	UPROPERTY(BlueprintAssignable)
	FOnPlatformMove OnPlatformMove;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void RetractionBegin();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Platforming Settings")
	float MaxExtension;

	UPROPERTY(VisibleAnywhere, Category = "Platforming Settings")
	float originalSize;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Platforming Settings")
	float extensionSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platforming Settings")
	float timeToRetract;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platforming Settings")
	float currentExtension;
private:
	bool toExtend;
	bool canMove;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
