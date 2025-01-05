#include "MainMenu_Activatable.h"

#include "Input/CommonUIActionRouterBase.h"
#include "Input/CommonUIInputTypes.h"

#include <Components/Button.h>
#include <UE5EnhancedInputEx/UI/Button/MyCommonButton.h>

UMainMenu_Activatable::UMainMenu_Activatable()
{
	SetIsFocusable(true);
}

void UMainMenu_Activatable::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	// if (auto* ActionRouter = UCommonUIActionRouterBase::Get(*this))
	// {
	// 	FSimpleDelegate Callback = FSimpleDelegate::CreateUObject(this, &UMainMenu_Activatable::OnActionTriggered);
	// 	FBindUIActionArgs Args(Action, Callback);
	// 	ActionRouter->RegisterUIActionBinding(*this, Args);
	// }
}

void UMainMenu_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	PlayButton->OnButtonClicked.AddDynamic(this, &UMainMenu_Activatable::OnPlayButtonClicked);
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return PlayButton;
}

void UMainMenu_Activatable::OnActionTriggered()
{
	/*
	FVector VectorValue = Instance.GetValue().Get<FVector>();
	FVector2D 2DAxisValue = Instance.GetValue().Get<FVector2D>();
	float FloatValue = Instance.GetValue().Get<float>();
	bool BoolValue = Instance.GetValue().Get<bool>();
	*/

	UE_LOG(LogTemp, Log, TEXT("KJHFGS0UKHFD"));
}

void UMainMenu_Activatable::OnPlayButtonClicked(UCommonButtonBase* Button)
{
	UE_LOG(LogTemp, Log, TEXT("CLICKED"));
}