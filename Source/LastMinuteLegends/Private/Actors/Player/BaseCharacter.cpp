// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Player/BaseCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <UserSettings/EnhancedInputUserSettings.h>
#include "Actors/Platforms/ModifiablePlatforms.h"
#include "UI/BasePlayerHUD.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/BaseAnimation.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	springArm->SetupAttachment(GetRootComponent());
	cameraPlayer = CreateDefaultSubobject<UCameraComponent>("Camera");
	cameraPlayer->SetupAttachment(springArm);

	jumpVelocity = 600;
	walkSpeed = 600;
	airControl = 1.0f;
	lineDistance = 3000;
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
	FInputModeGameOnly inputMode;
	//inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	pCon->SetInputMode(inputMode);
	anim = Cast<UBaseAnimation>(GetMesh()->GetAnimInstance());

	HUD = CreateWidget<UBasePlayerHUD>(pCon, playerHUD, "Player UI");
	HUD->AddToViewport();

	GetCharacterMovement()->JumpZVelocity = jumpVelocity;
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	GetCharacterMovement()->AirControl = airControl;
}

void ABaseCharacter::MagicTouch()
{
	FHitResult touchCast;
	FVector endpoint = cameraPlayer->GetForwardVector();
	FCollisionObjectQueryParams params;
	params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);

	GetWorld()->LineTraceSingleByObjectType(touchCast, cameraPlayer->GetComponentLocation(), cameraPlayer->GetComponentLocation() + (endpoint * lineDistance), params);
	if(touchCast.bBlockingHit)
	{
		AModifiablePlatforms* Platform = Cast<AModifiablePlatforms>(touchCast.GetActor());
		if (Platform)
		{
			anim->PlayPoint();
			Platform->ExtensionBegin();
		}
	}
	
}

void ABaseCharacter::HandleClick(const FInputActionValue& val)
{
	MagicTouch();
}

void ABaseCharacter::HandleMovX(const FInputActionValue& val)
{
	FVector contextualForwardVector = FVector::CrossProduct(GetActorRightVector(), FVector(0, 0, 1));
	AddMovementInput(contextualForwardVector, val.Get<float>()*100);
}

void ABaseCharacter::HandleMovY(const FInputActionValue& val)
{
	FVector contextualForwardVector = FVector::CrossProduct(GetActorRightVector(), FVector(0, 0, 1));
	AddMovementInput(GetActorRightVector(), val.Get<float>()*100);
}

//void ABaseCharacter::HandleMovement(const FInputActionValue& val)
//{
//	FVector contextualForwardVector = FVector::CrossProduct(GetActorRightVector(), FVector(0, 0, 1));
//	AddMovementInput(contextualForwardVector, val.Get<FVector2D>().X);
//	AddMovementInput(GetActorRightVector(), val.Get<FVector2D>().Y);
//	//AddMovementInput(contextualForwardVector, val.Get<float>());
//	//AddMovementInput(GetActorRightVector(), val.Get<float>());
//
//}

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
		//eInput->BindAction(RegMovement, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleMovement);
		eInput->BindAction(movX, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleMovX);
		eInput->BindAction(movY, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleMovY);
		eInput->BindAction(CamMovement, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleCamera);
		eInput->BindAction(playerJump, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleJump);
		eInput->BindAction(MouseClick, ETriggerEvent::Triggered, this, &ABaseCharacter::HandleClick);
	}
}

