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
	/** 获取所有PlayerController列表，然后再找到本地客户端的第一个PlayerController并返回 */
	UFUNCTION(BlueprintCallable, Category = "TD_Test Gameplay")
	static APlayerController* GetLocalPlayerController(UObject* WorldContextObject);
};
