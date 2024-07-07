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

	class UWidget* NativeGetDesiredFocusTarget() const override;

private:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(meta=(BindWidget))
	class UButton* PlayButton;
};