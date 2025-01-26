// Fill out your copyright notice in the Description page of Project Settings.

#include "Settings_Activatable.h"

#include "UE5EnhancedInputEx/Setup/MainMenuHUD.h"
#include "UE5EnhancedInputEx/UI/Button/MyCommonButton.h"

USettings_Activatable::USettings_Activatable()
{
	SetIsFocusable(true);
}

UWidget* USettings_Activatable::NativeGetDesiredFocusTarget() const
{
	return ReturnButton;
}

void USettings_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ReturnButton->OnButtonClicked.AddDynamic(this, &ThisClass::OnReturnButtonClicked);
}

void USettings_Activatable::OnReturnButtonClicked(UCommonButtonBase* Button)
{
	if (auto MenuHUD = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD()))
	{
		MenuHUD->OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
	}
}