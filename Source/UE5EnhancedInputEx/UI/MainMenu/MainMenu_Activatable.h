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
	virtual void NativeOnActivated() override;
	virtual void NativeOnInitialized() override;

	virtual class UWidget* NativeGetDesiredFocusTarget() const override;

private:
	UPROPERTY(meta = (BindWidget))
	class UMyCommonButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	class UMyCommonButton* SettingsButton;

	UPROPERTY(EditAnywhere)
	class UInputAction* CustomAction;

	UFUNCTION()
	void OnCustomActionTriggered();

	UFUNCTION()
	void OnPlayButtonClicked(class UCommonButtonBase* Button);

	UFUNCTION()
	void OnSettingsButtonClicked(class UCommonButtonBase* Button);
};