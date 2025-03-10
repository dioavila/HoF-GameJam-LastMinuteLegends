// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseMainMenu.h"
#include "UI/BaseButtonWithText.h"
#include "Modes/BaseGameInstance.h"

void UBaseMainMenu::NativeConstruct()
{
	UWorld* world = GetWorld();
	gameInstance = Cast<UBaseGameInstance>(world->GetGameInstance());

	if (gameInstance) {
		PlayButton->OnButtonClickedInstance.AddDynamic(gameInstance, &UBaseGameInstance::PlayGame);
		QuitButton->OnButtonClickedInstance.AddDynamic(gameInstance, &UBaseGameInstance::QuitGame);
		CreditsButton->OnButtonClickedInstance.AddDynamic(gameInstance, &UBaseGameInstance::CreditsGame);
	}
}
