// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "UI_TitleMenu.h"
#include "UI_TextButton.h"
#include "UI_ConfirmPopup.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

AUI_PlayerController::AUI_PlayerController()
{
	//WidgetBlueprint'/Game/UI_ElyonSample/WB_PluginTitleMenu.WB_PluginTitleMenu'
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_TITLECLASS(TEXT("/Game/UI_ElyonSample/WB_PluginTitleMenu.WB_PluginTitleMenu_C"));
	if (UI_TITLECLASS.Succeeded())
	{
		TitleWidgetClass = UI_TITLECLASS.Class;
	}

	//WidgetBlueprint'/Game/UI_Tested/Ingame_UI.Ingame_UI'
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_INGAMECLASS(TEXT("/Game/UI_Tested/Ingame_UI.Ingame_UI_C"));
	if (UI_INGAMECLASS.Succeeded())
	{
		IngameWidgetClass = UI_INGAMECLASS.Class;
	}
	//WidgetBlueprint'/Game/UI_ElyonSample/WB_PluginPopup.WB_PluginPopup'
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_POPUPCLASS(TEXT("/Game/UI_ElyonSample/WB_PluginPopup.WB_PluginPopup_C"));
	if (UI_POPUPCLASS.Succeeded())
	{
		PopupWidgetClass = UI_POPUPCLASS.Class;
	}

	
	//UUI_TitleMenu* tmp = Cast<UUI_TitleMenu>(MainWidget);
	//tmp->StartButton->InputButton->OnClicked.AddDynamic(this, &AUI_PlayerController::StartIngameScene);
}

void AUI_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	//CreateWidget�� �÷��̾ �پ����� ���� �÷��̾� ��Ʈ�ѷ����� ����� �� �����ϴ�. UI_PlayerController_0�� �پ��ִ� �÷��̾ �����ϴ�.
	TitleWidget = CreateWidget<UUserWidget>(this, TitleWidgetClass);

	IngameHUDWidget = CreateWidget<UUserWidget>(this, IngameWidgetClass);

	PopupWidget = CreateWidget<UUserWidget>(this, PopupWidgetClass);

	MainWidget = TitleWidget;

	StartTitleScene();
	//TitleWidget = CreateWidget<UUserWidget>(this, TitleWidgetClass);
	//TitleWidget->AddToViewport();
	//
	//IngameHUDWidget = CreateWidget<UUserWidget>(this, IngameWidgetClass);
}

//UI_TitleMenu::UI_start_Clicked�� �޾Ƽ� ĳ���� ��Ʈ�ѷ��� �ΰ������� ����. ���� ������ �ΰ��� ������ �ȴ�.

void AUI_PlayerController::StartTitleScene()
{
	ResetViewPort();

	Cast<UUI_ConfirmPopup>(PopupWidget)->ConfirmationMessage->SetText(FText::FromString(FString(TEXT("Want to Quit?"))));
	Cast<UUI_ConfirmPopup>(PopupWidget)->ConfirmButton->ButtonText->SetText(FText::FromString(FString(TEXT("Quit"))));

	PlayerCameraManager->StartCameraFade(1.0, 0.0, 3.0, FLinearColor(FColor(0.0f, 0.0f, 0.0f, 1.0f)));
	SetViewTargetWithBlend(this, 0.0);
	MainWidget->AddToViewport();
	
}

void AUI_PlayerController::StartIngameScene()
{
	ResetViewPort();

	MainWidget = IngameHUDWidget;
	MainWidget->AddToViewport();
}

void AUI_PlayerController::StartEndScene()
{
	ResetViewPort();

}

void AUI_PlayerController::ResetViewPort()
{
	if (MainWidget)
	{
		MainWidget->RemoveFromViewport();
	}
}

void AUI_PlayerController::PopupCalled()
{
	if (PopupWidget)
	{
		PopupWidget->AddToViewport();
	}
}