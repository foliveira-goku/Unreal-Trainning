// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::CallGameStartEvent()
{
	OnGameStart.Broadcast();
	SetShowMouseCursor(false);
}
