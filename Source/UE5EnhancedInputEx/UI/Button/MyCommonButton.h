#pragma once

#include <CoreMinimal.h>

#include <CommonButtonBase.h>

#include "MyCommonButton.generated.h"

UCLASS(Abstract)
class UMyCommonButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UMyCommonButton();
	
	void NativeOnInitialized() override;

	FCommonButtonBaseClicked OnButtonClicked;

private:
	UFUNCTION()
	void OnButtonBaseClicked_Internal(class UCommonButtonBase* Button);
};
