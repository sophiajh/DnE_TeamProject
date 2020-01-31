// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_TitleMenu.h"
#include "Components/TextBlock.h"
#include "UI_PlayerController.h"
#include "UI_TextButton.h"
#include "Button.h"
#include "UI_ConfirmPopup.h"

void UUI_TitleMenu::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (StartButton)
	{
		StartButton->ButtonText->SetText(FText::FromString(FString(TEXT("Start"))));
		StartButton->InputButton->OnClicked.AddDynamic(this, &UUI_TitleMenu::UI_Start_Clicked);
		//AUI_PlayerController* tmp = Cast<AUI_PlayerController>(GetOwningPlayer());
		//if (tmp)
		//{
		//	StartButton->InputButton->OnClicked.AddDynamic(tmp, &AUI_PlayerController::StartIngameScene);
		//}
	}
	if (OptionButton)
	{
		OptionButton->ButtonText->SetText(FText::FromString(FString(TEXT("Option"))));
		OptionButton->InputButton->OnClicked.AddDynamic(this, &UUI_TitleMenu::UI_Option_Clicked);
	}
	if (AchievementButton)
	{
		AchievementButton->ButtonText->SetText(FText::FromString(FString(TEXT("Achievement"))));
		AchievementButton->InputButton->OnClicked.AddDynamic(this, &UUI_TitleMenu::UI_Achievement_Clicked);
	}
	if (QuitButton)
	{
		QuitButton->ButtonText->SetText(FText::FromString(FString(TEXT("Quit"))));
		QuitButton->InputButton->OnClicked.AddDynamic(this, &UUI_TitleMenu::UI_Quit_Clicked);
	}
}

void UUI_TitleMenu::NativeConstruct()
{
	//컨트롤러 생성 후
	AUI_PlayerController* tmp = Cast<AUI_PlayerController>(GetOwningPlayer());
	if (tmp)
	{
		StartButton->InputButton->OnClicked.AddDynamic(tmp, &AUI_PlayerController::StartIngameScene);
		QuitButton->InputButton->OnClicked.AddDynamic(tmp, &AUI_PlayerController::PopupCalled);
	}
}


void UUI_TitleMenu::NativeOnInitialized()
{
	//AUI_PlayerController* tmp = Cast<AUI_PlayerController>(GetOwningPlayer());
	//if (tmp)
	//{
	//	StartButton->InputButton->OnClicked.AddDynamic(tmp, &AUI_PlayerController::StartIngameScene);
	//}
}

void UUI_TitleMenu::UI_Start_Clicked()
{
	//인게임으로 전환. 델리게이트
	//캐릭터 카메라로 전환
	StartGame.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Start_Clicked"));

}
void UUI_TitleMenu::UI_Option_Clicked()
{
	//옵션 위젯 띄우기
	OptionPopup.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Option_Clicked"));

}
void UUI_TitleMenu::UI_Achievement_Clicked()
{
	//업적 위젯 띄우기
	AchievementPopup.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Achieve_Clicked"));

}
void UUI_TitleMenu::UI_Quit_Clicked()
{
	//게임 종료 확인창 띄우기
	QuitGame.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Quit_Clicked"));
	//if (Quit_PopUp)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Quit_Pop"));
	//
	//	Quit_PopUp->ConfirmationMessage->SetText(FText::FromString(FString(TEXT("Want to Quit?"))));
	//	Quit_PopUp->ConfirmButton->ButtonText->SetText(FText::FromString(FString(TEXT("Quit"))));
	//	Quit_PopUp->AddToViewport();
	//}
}
