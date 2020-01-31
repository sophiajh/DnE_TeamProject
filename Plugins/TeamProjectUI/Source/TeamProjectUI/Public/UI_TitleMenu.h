// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_ConfirmPopup.h"
#include "UI_TitleMenu.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FStartGameDelegate);
DECLARE_MULTICAST_DELEGATE(FMenuOptionDelegate);
DECLARE_MULTICAST_DELEGATE(FAchievementDelegate);
DECLARE_MULTICAST_DELEGATE(FQuitGameDelegate);


UCLASS()
class TEAMPROJECTUI_API UUI_TitleMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UVerticalBox* MenuList = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUI_TextButton* StartButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUI_TextButton* OptionButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUI_TextButton* AchievementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUI_TextButton* QuitButton = nullptr;

public:

	FStartGameDelegate		StartGame;
	FMenuOptionDelegate		OptionPopup;
	FAchievementDelegate	AchievementPopup;
	FQuitGameDelegate		QuitGame;
	
	UFUNCTION(BlueprintCallable)
	void UI_Start_Clicked();
	
	UFUNCTION(BlueprintCallable)
	void UI_Option_Clicked();
	
	UFUNCTION(BlueprintCallable)
	void UI_Achievement_Clicked();
	
	UFUNCTION(BlueprintCallable)
	void UI_Quit_Clicked();

public:
	UUI_ConfirmPopup* Quit_PopUp;
};
