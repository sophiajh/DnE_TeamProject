// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ingame_MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECTUI_API UIngame_MainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UScaleBox* HealthSlot;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* StamiaBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Minimap;
};
