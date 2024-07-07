#include "MyCommonButton.h"

void UMyCommonButton::NativeOnInitialized()
{
	OnButtonBaseClicked.AddDynamic(this, &UMyCommonButton::OnButtonBaseClicked_Internal);
}

void UMyCommonButton::OnButtonBaseClicked_Internal(UCommonButtonBase* Button)
{
	OnButtonClicked.Broadcast(Button);
}