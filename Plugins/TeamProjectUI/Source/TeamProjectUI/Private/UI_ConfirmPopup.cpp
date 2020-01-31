// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ConfirmPopup.h"
#include "Components/TextBlock.h"
#include "UI_TextButton.h"
#include "Button.h"

void UUI_ConfirmPopup::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ConfirmationMessage)
	{
		ConfirmationMessage->SetText(FText::FromString(FString(TEXT("Message Here"))));
	}

	if (ConfirmButton)
	{
		ConfirmButton->ButtonText->SetText(FText::FromString(FString(TEXT("Here"))));
		//ConfirmButton->InputButton->OnClicked.AddDynamic(this, &UUI_TitleMenu::UI_Start_Clicked);
	}

	if (CancelButton)
	{
		CancelButton->ButtonText->SetText(FText::FromString(FString(TEXT("Close"))));
		CancelButton->InputButton->OnClicked.AddDynamic(this, &UUI_ConfirmPopup::CloseConfirmPopup);
	}
}

void UUI_ConfirmPopup::CloseConfirmPopup()
{
	RemoveFromViewport();
	UE_LOG(LogTemp, Warning, TEXT("ConfirmClose_Clicked"));
}