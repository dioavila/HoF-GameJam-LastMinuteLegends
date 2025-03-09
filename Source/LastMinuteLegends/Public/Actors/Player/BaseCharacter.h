// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UCLASS()
class LASTMINUTELEGENDS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(BlueprintReadWrite)
	class UInputMappingContext* InputMapping;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* MouseClick;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* CamMovement;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* RegMovement;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* Jump;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
