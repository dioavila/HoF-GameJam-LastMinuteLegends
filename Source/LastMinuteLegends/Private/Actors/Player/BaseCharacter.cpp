// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Player/BaseCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <UserSettings/EnhancedInputUserSettings.h>
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	springArm->SetupAttachment(GetRootComponent());
	cameraPlayer = CreateDefaultSubobject<UCameraComponent>("Camera");
	cameraPlayer->SetupAttachment(springArm);
	
	jumpVelocity = 600;
	walkSpeed = 600;
	airControl = 1.0f;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	APawn* pawnMode = CastChecked<APawn>(this);
	APlayerController* pCon = CastChecked<APlayerController>(pawnMode->GetController());
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(pCon->GetLocalPlayer()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMapping)
			{
				InputSystem->AddMappingContext(InputMapping, 0);
			}
		}
	}
	GetCharacterMovement()->JumpZVelocity = jumpVelocity;
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	GetCharacterMovement()->AirControl = airControl;
}

void ABaseCharacter::HandleClick(const FInputActionValue& val)
{
}

void ABaseCharacter::HandleMovement(const FInputActionValue& val)
{
	FVector contextualForwardVector = FVector::CrossProduct(GetActorRightVector(), FVector(0, 0, 1));

	AddMovementInput(contextualForwardVector, val.Get<FVector2D>().X * 1000.f);
	AddMovementInput(GetActorRightVector(), val.Get<FVector2D>().Y);
	//AddMovementInput(FRotator(0, GetControlRotation().Yaw, 0).Vector(), val.Get<FVector2D>().X);
	//AddMovementInput(FRotator(0,GetControlRotation().Yaw, 0).Vector(), val.Get<FVector2D>().Y);
}

void ABaseCharacter::HandleCamera(const FInputActionValue& val)
{
	AddControllerYawInput(-val.Get<FVector2D>().X);
	AddControllerPitchInput(val.Get<FVector2D>().Y);
}

void ABaseCharacter::HandleJump(const FInputActionValue& val)
{
	Jump();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* eInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (eInput) {
		eInput->BindAction(RegMovement, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleMovement);
		eInput->BindAction(CamMovement, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleCamera);
		eInput->BindAction(playerJump, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleJump);
		eInput->BindAction(MouseClick, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleClick);
	}
}

