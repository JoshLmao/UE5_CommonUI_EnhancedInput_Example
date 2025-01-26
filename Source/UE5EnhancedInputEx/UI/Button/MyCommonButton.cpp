#include "MyCommonButton.h"

#include "CommonTextBlock.h"

UMyCommonButton::UMyCommonButton()
{
	bDisplayInActionBar = true;
}

void UMyCommonButton::NativeOnInitialized()
{
	OnButtonBaseClicked.AddDynamic(this, &UMyCommonButton::OnButtonBaseClicked_Internal);
}

void UMyCommonButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	CustomTextBlock->SetText(ButtonText);
}

void UMyCommonButton::OnButtonBaseClicked_Internal(UCommonButtonBase* Button)
{
	OnButtonClicked.Broadcast(Button);
	UE_LOG(LogTemp, Display, TEXT("%s: Button Base Clicked"), *GetName());
}