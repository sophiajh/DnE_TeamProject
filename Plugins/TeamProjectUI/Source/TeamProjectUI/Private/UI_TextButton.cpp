// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_TextButton.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UUI_TextButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (ButtonText)
	{
		ButtonText->SetText(FText::FromString(FString(TEXT("TextHere"))));
	}
	//if (InputButton)
	//{
	//	InputButton->OnClicked.AddDynamic(this, &UUI_TextButton::UI_Clicked);
	//}
}

void UUI_TextButton::NativeConstruct()
{
	if (InputButton)
	{
		InputButton->OnClicked.AddDynamic(this, &UUI_TextButton::UI_Clicked);

		//InputButton->OnClicked.AddDynamic(this, &UUI_TextButton::UI_Clicked);
	}
}


void UUI_TextButton::UI_Clicked()
{
	int i = 0;

	//UE_LOG(LogTemp, Warning, TEXT("Start_Clicked"));
}
