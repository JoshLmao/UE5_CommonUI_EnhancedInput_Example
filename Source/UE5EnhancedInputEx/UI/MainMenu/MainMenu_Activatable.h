#pragma once

#include <CoreMinimal.h>

#include "CommonActivatableWidget.h"

#include "MainMenu_Activatable.generated.h"

UCLASS(Abstract)
class UMainMenu_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

	UMainMenu_Activatable();

public:
	void NativeOnActivated() override;
	void NativeOnInitialized() override;

	class UWidget* NativeGetDesiredFocusTarget() const override;

private:
	UPROPERTY(meta=(BindWidget))
	class UMyCommonButton* PlayButton;

	UPROPERTY(EditAnywhere)
	class UInputAction* CustomAction;

	UFUNCTION()
	void OnCustomActionTriggered();

	UFUNCTION()
	void OnPlayButtonClicked(class UCommonButtonBase* Button);
};