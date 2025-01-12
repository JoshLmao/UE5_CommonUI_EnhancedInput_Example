# UE5_CommonUI_EnhancedInput_Example

Example repo of how to use Enhanced Input with Common UI in UE5

# How it works

Start with [this guide](https://dev.epicgames.com/documentation/en-us/unreal-engine/using-commonui-with-enhnaced-input-in-unreal-engine).

MainMenu_Activatable specifies the Enhanced Input context `IA_Context_Menu`

In my example, I have two input examples:
- MainMenu_Activatable has a UPROPERTY CustomAction which shows how to expose and register an EI with code. 
- The Activatable also has a button which has the `TriggeringInputAction` property to allow for setting an EI action and will trigger the Button's `OnButtonBaseClicked` event.