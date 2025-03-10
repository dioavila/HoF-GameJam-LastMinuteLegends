// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "BaseCharacter.generated.h"

class UBasePlayerHUD;

UCLASS()
class LASTMINUTELEGENDS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void HandleClick(const FInputActionValue& val);
	//UFUNCTION()
	//virtual void HandleMovement(const FInputActionValue& val);
	UFUNCTION()
	virtual void HandleMovX(const FInputActionValue& val);
	UFUNCTION()
	virtual void HandleMovY(const FInputActionValue& val);
	UFUNCTION()
	virtual void HandleCamera(const FInputActionValue& val);
	UFUNCTION()
	virtual void HandleJump(const FInputActionValue& val);

	UFUNCTION()
	virtual void MagicTouch();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* springArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* cameraPlayer;

	UPROPERTY(BlueprintReadWrite)
	class UInputMappingContext* InputMapping;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* MouseClick;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* CamMovement;
	//UPROPERTY(BlueprintReadWrite)
	//class UInputAction* RegMovement;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* movX;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* movY;
	UPROPERTY(BlueprintReadWrite)
	class UInputAction* playerJump;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TSubclassOf<UBasePlayerHUD> playerHUD;

	UPROPERTY()
	UBasePlayerHUD* HUD;

	UPROPERTY()
	class UBaseAnimation* anim;

	UPROPERTY(BlueprintReadWrite, Category = "Player Settings")
	float jumpVelocity;
	UPROPERTY(BlueprintReadWrite, Category = "Player Settings")
	float walkSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "Player Settings")
	float airControl;
	UPROPERTY(BlueprintReadWrite, Category = "Player Settings")
	float lineDistance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
