// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CommonActivatableWidget.h"
#include "CoreMinimal.h"
#include "Settings_Activatable.generated.h"

/**
 *
 */
UCLASS(Abstract)
class UE5ENHANCEDINPUTEX_API USettings_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()
public:
	USettings_Activatable();

protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnReturnButtonClicked(class UCommonButtonBase* Button);

	UPROPERTY(meta = (BindWidget))
	class UMyCommonButton* ReturnButton;
};
