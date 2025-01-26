#include "MyActionButton.h"

#include "CommonTextBlock.h"

void UMyActionButton::SetRepresentedAction(FUIActionBindingHandle InBindingHandle)
{
	ActionNameTextBlock->SetText(InBindingHandle.GetDisplayName());
}
