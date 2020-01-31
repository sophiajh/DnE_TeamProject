// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECTUI_API AUI_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
//public:
//	AUI_GameModeBase();
//
//public:

	UUserWidget* MainWidget;


public:
	void ShowTitleWidget();

	void ShowIngameHUD();
};
