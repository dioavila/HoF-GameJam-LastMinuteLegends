// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API ABaseMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABaseMenuPlayerController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UUserWidget> MenuClass;

	UPROPERTY(BlueprintReadWrite)
	class UUserWidget* widget;
};
