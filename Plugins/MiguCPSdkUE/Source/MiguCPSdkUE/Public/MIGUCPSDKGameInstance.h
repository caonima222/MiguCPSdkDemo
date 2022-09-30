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

	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnGetLoginInfo;

	// 获取Token返回
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnGetToken;

	// 获取通用信息
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnGetGeneralInfo;

	// 获取所有成就
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnQueryAllAchievement;

	// 批量设置用户成就
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnSetAchievementBatch;

	// 查询用户单个成就状态
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnQueryAchievement;

	// 设置用户单个成就
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnSetAchievement;

	// 查询用户单个成就完成进度
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnQueryAchievementPercentage;

	// 通用接口
	UPROPERTY(BlueprintAssignable)
	FLoginResponseDelegatge OnCommonBusiness;

	
};
