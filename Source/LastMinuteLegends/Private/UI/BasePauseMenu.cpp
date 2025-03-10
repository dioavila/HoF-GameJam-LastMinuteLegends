// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BasePauseMenu.h"
#include "UI/BaseButtonWithText.h"
#include "Modes/BaseGameInstance.h"
#include <Kismet/GameplayStatics.h>

void UBasePauseMenu::NativeConstruct()
{
	UWorld* world = GetWorld();
	gameInstance = Cast<UBaseGameInstance>(world->GetGameInstance());

	if (gameInstance) {

		PauseMenuWidget = this;

		gameInstance = Cast<UBaseGameInstance>(world->GetGameInstance());
		ResumeButton->OnButtonClickedInstance.AddDynamic(this, &UBasePauseMenu::ResumeGame);
		MenuButton->OnButtonClickedInstance.AddDynamic(gameInstance, &UBaseGameInstance::MenuGame);
	}
}

void UBasePauseMenu::ResumeGame()
{
	if (PauseMenuWidget) {
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	}
}
