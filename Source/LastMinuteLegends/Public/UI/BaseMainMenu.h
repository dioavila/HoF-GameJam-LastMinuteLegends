// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBaseMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY()
	class UBaseGameInstance* gameInstance;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UBaseButtonWithText* PlayButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UBaseButtonWithText* QuitButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UBaseButtonWithText* CreditsButton;
};
