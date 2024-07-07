#include "MainMenu_Activatable.h"

#include <EnhancedInputSubsystems.h>
#include "InputMappingContext.h"

UMainMenu_Activatable::UMainMenu_Activatable()
{
	bIsFocusable = true;
}

void UMainMenu_Activatable::NativeOnActivated()
{
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(GetOwningLocalPlayer()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMappingContext.IsNull())
			{
				InputSystem->AddMappingContext(InputMappingContext.LoadSynchronous(), GetInputActionPriority());
			}
		}
	}
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return PlayButton;
}
