// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MiguBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MIGUCPSDKDEMO_API UMiguBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Custom")
	static void Migu_Pay();
};
