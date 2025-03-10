// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BasePlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBasePlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* CrosshairOuter;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* CrosshairInner;
};
