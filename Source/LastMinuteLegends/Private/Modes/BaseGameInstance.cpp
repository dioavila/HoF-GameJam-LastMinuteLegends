// Fill out your copyright notice in the Description page of Project Settings.


#include "Modes/BaseGameInstance.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>

void UBaseGameInstance::MenuGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), GameLevels[0]);
}

void UBaseGameInstance::PlayGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), GameLevels[1]);
}

void UBaseGameInstance::QuitGame()
{
	UWorld* world = GetWorld();
	UKismetSystemLibrary::QuitGame(world, NULL, EQuitPreference::Quit, false);
}

void UBaseGameInstance::CreditsGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), GameLevels[2]);
}
