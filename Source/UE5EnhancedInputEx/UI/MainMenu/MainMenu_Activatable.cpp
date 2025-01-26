#include "MainMenu_Activatable.h"

#include "Input/CommonUIActionRouterBase.h"
#include "Input/CommonUIInputTypes.h"
#include "UE5EnhancedInputEx/Setup/MainMenuHUD.h"

#include <Components/Button.h>
#include <UE5EnhancedInputEx/UI/Button/MyCommonButton.h>

UMainMenu_Activatable::UMainMenu_Activatable()
{
	SetIsFocusable(true);
}

void UMainMenu_Activatable::NativeOnActivated()
{
	Super::NativeOnActivated();

	if (IsValid(CustomAction))
	{
		if (auto* ActionRouter = UCommonUIActionRouterBase::Get(*this))
		{
			FSimpleDelegate Callback = FSimpleDelegate::CreateUObject(
				this, &UMainMenu_Activatable::OnCustomActionTriggered);
			FBindUIActionArgs Args(CustomAction, Callback);
			ActionRouter->RegisterUIActionBinding(*this, Args);
		}
	}
}

void UMainMenu_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	PlayButton->OnButtonClicked.AddDynamic(this, &UMainMenu_Activatable::OnPlayButtonClicked);
	SettingsButton->OnButtonClicked.AddDynamic(this, &UMainMenu_Activatable::OnSettingsButtonClicked);
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return PlayButton;
}

void UMainMenu_Activatable::OnCustomActionTriggered()
{
	/*
	FVector VectorValue = Instance.GetValue().Get<FVector>();
	FVector2D 2DAxisValue = Instance.GetValue().Get<FVector2D>();
	float FloatValue = Instance.GetValue().Get<float>();
	bool BoolValue = Instance.GetValue().Get<bool>();
	*/

	UE_LOG(LogTemp, Log, TEXT("On Activatable CustomAction triggered"));
}

void UMainMenu_Activatable::OnPlayButtonClicked(UCommonButtonBase* Button)
{
	UE_LOG(LogTemp, Log, TEXT("CLICKED"));
}

void UMainMenu_Activatable::OnSettingsButtonClicked(UCommonButtonBase* Button)
{
	if (auto MenuHUD = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD()))
	{
		MenuHUD->OpenWidget(
			FGameplayTag::RequestGameplayTag("UI.MainMenu.Settings"));
	}
}