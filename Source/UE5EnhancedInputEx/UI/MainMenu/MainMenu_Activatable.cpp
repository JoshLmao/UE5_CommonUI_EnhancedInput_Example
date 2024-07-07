#include "MainMenu_Activatable.h"

#include <EnhancedInputSubsystems.h>
#include <Components/Button.h>
#include <EnhancedInputComponent.h>
#include <InputAction.h>
#include <UE5EnhancedInputEx/UI/Button/MyCommonButton.h>

UMainMenu_Activatable::UMainMenu_Activatable()
{
	SetIsFocusable(true);
}

void UMainMenu_Activatable::NativeOnActivated()
{
	auto EIC = Cast<UEnhancedInputComponent>(GetOwningPlayer()->InputComponent);
	if (IsValid(EIC))
	{
		FScriptDelegate MyScriptDelegate;
		MyScriptDelegate.BindUFunction(this, "OnActionTriggered");
		EIC->BindAction(Action, ETriggerEvent::Triggered, this, &UMainMenu_Activatable::OnActionTriggered);
	}
}

void UMainMenu_Activatable::NativeOnInitialized()
{
	PlayButton->OnButtonClicked.AddDynamic(this, &UMainMenu_Activatable::OnPlayButtonClicked);
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return PlayButton;
}

void UMainMenu_Activatable::OnActionTriggered(const FInputActionInstance& Instance)
{
	/*
	FVector VectorValue = Instance.GetValue().Get<FVector>();
	FVector2D 2DAxisValue = Instance.GetValue().Get<FVector2D>();
	float FloatValue = Instance.GetValue().Get<float>();
	bool BoolValue = Instance.GetValue().Get<bool>();
	*/

	UE_LOG(LogTemp, Log, TEXT("KJHFGSUKHFD"));
}

void UMainMenu_Activatable::OnPlayButtonClicked(UCommonButtonBase* Button)
{
	UE_LOG(LogTemp, Log, TEXT("CLICKED"));
}