// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MIGUCPSDKGameInstance.generated.h"

/**
 *
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoginResponseDelegatge, FString, Data);





UCLASS(BlueprintType)
class MIGUCPSDKUE_API UMIGUCPSDKGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	// 登录返回
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnLogin;

	// 登录返回
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnGetToken;



};
