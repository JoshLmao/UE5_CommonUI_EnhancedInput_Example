# UE5_CommonUI_EnhancedInput_Example

Example repo of how to use Enhanced Input with Common UI in UE5

# How it works

Start with [this guide](https://dev.epicgames.com/documentation/en-us/unreal-engine/using-commonui-with-enhnaced-input-in-unreal-engine).

MainMenu_Activatable specifies the Enhanced Input context `IA_Context_Menu`

In my example, I have two input examples:
- MainMenu_Activatable has a UPROPERTY CustomAction which shows how to expose and register an EI with code. 
- The Activatable also has a button which has the `TriggeringInputAction` property to allow for setting an EI action and will trigger the Button's `OnButtonBaseClicked` event.

# Explanation of elements

## Setting an Activatable's EI IMC

You can create an EI IMC and have it set in the activatable. That context allows you to define what actions could and can be bound under that activatable to show. For example, a context might have `IA_Back`, `IA_Confirm` and `IA_CloseGame` input actions. However, you could just dynamically bind `IA_Back` and `IA_Confirm`. This allows for reusing of contexts across activatables.

You can make IMC specific to an activatable's use case. For example, you could have an Inventory IMC that doesn't contain `IA_CloseGame` but have more like `IA_Equip` or `IA_DropItem`. The important thing is the context will contain IAs that can be bind. If you try to bind an IA that isnt in the context, it won't trigger
