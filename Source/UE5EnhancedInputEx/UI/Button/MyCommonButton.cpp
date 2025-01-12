#include "MyCommonButton.h"

UMyCommonButton::UMyCommonButton()
{
	bDisplayInActionBar = true;
}

void UMyCommonButton::NativeOnInitialized()
{
	OnButtonBaseClicked.AddDynamic(this, &UMyCommonButton::OnButtonBaseClicked_Internal);
}

void UMyCommonButton::OnButtonBaseClicked_Internal(UCommonButtonBase* Button)
{
	OnButtonClicked.Broadcast(Button);
	UE_LOG(LogTemp, Display, TEXT("%s: Button Base Clicked"), *GetName());
}