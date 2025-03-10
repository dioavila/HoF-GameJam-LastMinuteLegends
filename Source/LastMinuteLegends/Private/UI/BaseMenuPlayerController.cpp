// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseMenuPlayerController.h"
#include "Blueprint/UserWidget.h"

ABaseMenuPlayerController::ABaseMenuPlayerController()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ABaseMenuPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	widget = CreateWidget<UUserWidget>(this, MenuClass);
	widget->AddToViewport();
	if (this != nullptr) {

		FInputModeUIOnly InputMode;
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);

		if (widget != nullptr) {
			InputMode.SetWidgetToFocus(widget->TakeWidget());
		}
		this->SetInputMode(InputMode);
	}
}