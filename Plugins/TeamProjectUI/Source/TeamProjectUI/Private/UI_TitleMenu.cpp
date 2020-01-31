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
	//��Ʈ�ѷ� ���� ��
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
	//�ΰ������� ��ȯ. ��������Ʈ
	//ĳ���� ī�޶�� ��ȯ
	StartGame.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Start_Clicked"));

}
void UUI_TitleMenu::UI_Option_Clicked()
{
	//�ɼ� ���� ����
	OptionPopup.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Option_Clicked"));

}
void UUI_TitleMenu::UI_Achievement_Clicked()
{
	//���� ���� ����
	AchievementPopup.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Achieve_Clicked"));

}
void UUI_TitleMenu::UI_Quit_Clicked()
{
	//���� ���� Ȯ��â ����
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
