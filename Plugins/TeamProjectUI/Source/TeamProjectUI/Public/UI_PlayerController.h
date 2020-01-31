// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECTUI_API AUI_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AUI_PlayerController();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> TitleWidgetClass;

	UPROPERTY()
	class UUserWidget* TitleWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> IngameWidgetClass;

	UPROPERTY(VisibleAnywhere)
	class UUserWidget* IngameHUDWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> PopupWidgetClass;

	UPROPERTY(VisibleAnywhere)
		class UUserWidget* PopupWidget;

	UUserWidget* MainWidget;

protected:
	virtual void BeginPlay() override;

public:

	//각 씬에 필요한 위젯을 배치
	UFUNCTION(BlueprintCallable)
	void StartTitleScene();

	UFUNCTION(BlueprintCallable)
	void StartIngameScene();
	
	UFUNCTION(BlueprintCallable)
	void StartEndScene();

	UFUNCTION(BlueprintCallable)
	void PopupCalled();

	//뷰포트의 모든 위젯을 제거
	UFUNCTION(BlueprintCallable)
	void ResetViewPort();
};
