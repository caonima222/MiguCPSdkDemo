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
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnLogin"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnLogin;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnGetLoginInfo"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnGetLoginInfo;

	// 获取Token返回
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnGetToken"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnGetToken;

	// 获取通用信息
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnGetGeneralInfo"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnGetGeneralInfo;

	// 获取所有成就
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnQueryAllAchievement"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnQueryAllAchievement;

	// 批量设置用户成就
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnSetAchievementBatch"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnSetAchievementBatch;

	// 查询用户单个成就状态
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnQueryAchievement"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnQueryAchievement;

	// 设置用户单个成就
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnSetAchievement"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnSetAchievement;

	// 查询用户单个成就完成进度
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnQueryAchievementPercentage"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnQueryAchievementPercentage;

	// 通用接口
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnCommonBusiness"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnCommonBusiness;

	// 支付
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnCloudPay"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnCloudPay;

	// 拉起CP支付Url
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnCloudPayToCP"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnCloudPayToCP;

	// 通用接口-MsgSDK
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "MiGu OnCommonInterfaceByMsgSDK"), Category = "MiguCPSDK")
	FLoginResponseDelegatge OnCommonInterfaceByMsgSDK;

	
};
