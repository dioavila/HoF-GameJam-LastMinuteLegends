// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "BasePlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBasePlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	FVector2D GetPixelLocation();

	UPROPERTY(BlueprintReadOnly)
	FVector2D PixelPosition;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* CrosshairOuter;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* CrosshairInner;
};
