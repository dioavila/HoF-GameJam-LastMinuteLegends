// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseCreditsPlayerController.h"
#include "Blueprint/UserWidget.h"

ABaseCreditsPlayerController::ABaseCreditsPlayerController()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ABaseCreditsPlayerController::BeginPlay()
{
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
