// Fill out your copyright notice in the Description page of Project Settings.

#include "UI_GenericMetadataIMC.h"

const UCommonInputMetadata *UUI_GenericMetadataIMC::GetCommonInputMetadata(const UInputAction *InInputAction) const
{
  auto* Metadata = NewObject<UCommonInputMetadata>();

  return Metadata;
}