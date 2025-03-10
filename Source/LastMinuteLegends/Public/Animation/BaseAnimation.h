// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimation.generated.h"

/**
 * 
 */
UCLASS()
class LASTMINUTELEGENDS_API UBaseAnimation : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UBaseAnimation();
	void PlayPoint();

protected:
	UPROPERTY(BlueprintReadWrite)
	bool isPointing;

	UPROPERTY(BlueprintReadWrite)
	bool canPoint;
};
