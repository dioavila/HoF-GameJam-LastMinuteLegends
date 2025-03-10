// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/BaseAnimation.h"

UBaseAnimation::UBaseAnimation()
{
	canPoint = true;
	isPointing = false;
}

void UBaseAnimation::PlayPoint()
{
	if(canPoint)
		isPointing = true;
}
