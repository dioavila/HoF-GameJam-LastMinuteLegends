// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseButtonWithText.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UBaseButtonWithText::NativePreConstruct()
{
	Information->SetText(theText);
}

void UBaseButtonWithText::NativeConstruct()
{
	BackgroundButton->OnClicked.AddDynamic(this, &UBaseButtonWithText::HandleButtonClick);
}

void UBaseButtonWithText::HandleButtonClick()
{
	OnButtonClickedInstance.Broadcast();
}
