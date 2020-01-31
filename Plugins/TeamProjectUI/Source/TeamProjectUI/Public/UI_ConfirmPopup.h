// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_ConfirmPopup.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECTUI_API UUI_ConfirmPopup : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* ConfirmationMessage = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UUI_TextButton* ConfirmButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UUI_TextButton* CancelButton = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	void CloseConfirmPopup();
};
