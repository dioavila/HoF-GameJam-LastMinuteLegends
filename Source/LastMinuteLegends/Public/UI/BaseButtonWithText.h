// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseButtonWithText.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonDelegate);

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBaseButtonWithText : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* BackgroundButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Information;

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	FText theText;

public:
	UFUNCTION()
	void HandleButtonClick();

	UPROPERTY()
	FButtonDelegate OnButtonClickedInstance;
};
