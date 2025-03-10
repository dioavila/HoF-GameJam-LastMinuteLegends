// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseCreditsPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API ABaseCreditsPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABaseCreditsPlayerController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UUserWidget> MenuClass;

	UPROPERTY(BlueprintReadWrite)
	class UUserWidget* widget;
};
