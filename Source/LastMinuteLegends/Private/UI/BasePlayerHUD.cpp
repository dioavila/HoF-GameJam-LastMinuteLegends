// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BasePlayerHUD.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"

void UBasePlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();
}

FVector2D UBasePlayerHUD::GetPixelLocation()
{
	CrosshairInner->GetCachedGeometry();
	FVector2D view;
	USlateBlueprintLibrary::LocalToViewport(GetWorld(), CrosshairInner->GetCachedGeometry(), FVector2D(0, 0), PixelPosition, view);
	return PixelPosition;
}
