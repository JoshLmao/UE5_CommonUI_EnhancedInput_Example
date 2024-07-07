#pragma once

#include <CoreMinimal.h>

#include <CommonButtonBase.h>
#include <Input/CommonBoundActionButtonInterface.h>

#include "MyActionButton.generated.h"

UCLASS(Abstract)
class UMyActionButton : public UCommonButtonBase, public ICommonBoundActionButtonInterface
{
	GENERATED_BODY()

public:
	virtual void SetRepresentedAction(struct FUIActionBindingHandle InBindingHandle);
};