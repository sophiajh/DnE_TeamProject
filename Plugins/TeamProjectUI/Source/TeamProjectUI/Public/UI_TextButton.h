// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_TextButton.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TEAMPROJECTUI_API UUI_TextButton : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* InputButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ButtonText = nullptr;

	UFUNCTION()
	void UI_Clicked();
};
