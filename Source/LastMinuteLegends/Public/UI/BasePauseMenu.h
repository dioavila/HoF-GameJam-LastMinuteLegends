// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BasePauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBasePauseMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void ResumeGame();

	UUserWidget* PauseMenuWidget;

	UPROPERTY()
	class UBaseGameInstance* gameInstance;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UBaseButtonWithText* ResumeButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UBaseButtonWithText* QuitButton;
};
