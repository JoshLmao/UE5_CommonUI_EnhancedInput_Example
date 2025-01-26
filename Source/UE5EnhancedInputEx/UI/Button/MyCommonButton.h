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

	virtual void NativeOnInitialized() override;

protected:
	virtual void NativePreConstruct() override;

public:
	FCommonButtonBaseClicked OnButtonClicked;

	UPROPERTY(EditAnywhere)
	FText ButtonText;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* CustomTextBlock;

private:
	UFUNCTION()
	void OnButtonBaseClicked_Internal(class UCommonButtonBase* Button);
};
