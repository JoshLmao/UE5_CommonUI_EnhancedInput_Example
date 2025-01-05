// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CommonUITypes.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UI_GenericMetadataIMC.generated.h"

/**
 * 
 */
UCLASS()
class UE5ENHANCEDINPUTEX_API UUI_GenericMetadataIMC : public UObject, public ICommonMappingContextMetadataInterface
{
    GENERATED_BODY()
    
    const UCommonInputMetadata* GetCommonInputMetadata(const UInputAction* InInputAction) const;
};
