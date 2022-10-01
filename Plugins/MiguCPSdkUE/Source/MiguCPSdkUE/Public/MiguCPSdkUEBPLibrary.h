// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <MiguCpSdk.h>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MiguCPSdkUEBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FMiguPayInfo
{
	GENERATED_BODY()

	UPROPERTY()
	FString gameName;     //游戏名称
	UPROPERTY()
	FString contentCode;  //云游戏内容管理平台的内容代码
	UPROPERTY()
	FString gameAccount;  //CP的游戏账户ID
	UPROPERTY()
	FString orderId;      //订单号
	UPROPERTY()
	FString propName;     //道具名称
	UPROPERTY()
	int orderAmount;	  //订单金额（单位：分）
};

UCLASS()
class MIGUCPSDKUE_API UMiguCPSdkUEBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CreateInstanceMsg"), Category = "MiguCPSDK")
	static int CreateInstanceMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu LoginMsg"), Category = "MiguCPSDK")
	static void LoginMsg(FString ContentCode, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu LoginInfoMsg"), Category = "MiguCPSDK")
	static void LoginInfoMsg(FString ContentCode, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu ReleaseSDKMsg"), Category = "MiguCPSDK")
	static void ReleaseSDKMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu GetToken"), Category = "MiguCPSDK")
	static void GetTokenInfoMsg(int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu GetGeneralInfo"), Category = "MiguCPSDK")
	static void GetGeneralInfoMsg(int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu QueryAllAchievement"), Category = "MiguCPSDK")
	static void QueryAllAchievementMsg(int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu SetAchievementBatch"), Category = "MiguCPSDK")
	static void SetAchievementBatchMsg(FString ContentCode, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu QueryAchievement"), Category = "MiguCPSDK")
	static void QueryAchievementMsg(FString AchievementId, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu SetAchievement"), Category = "MiguCPSDK")
	static void SetAchievementMsg(FString AchievementId, int AchievementType, float ReachValue, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu QueryAchievementPercentage"), Category = "MiguCPSDK")
	static void QueryAchievementPercentageMsg(FString AchievementId, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CommonBusiness"), Category = "MiguCPSDK")
	static void CommonBusinessMsg(FString BusinessUrl, FString Data, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CommonBusinessInit"), Category = "MiguCPSDK")
	static int CommonBusinessInitMsg(FString AppId, FString AppSecret);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CloudPayMsg"), Category = "MiguCPSDK")
	static void CloudPayMsg(const FMiguPayInfo PayInfo, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CloudPayToCP"), Category = "MiguCPSDK")
	static void CloudPayToCPMsg(FString PayUrl, int timeoutSeconds = 10);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CommonInterfaceByMsgSDK"), Category = "MiguCPSDK")
	static void CommonInterfaceByMsgSDKMsg(const int Type, FString Data, int timeoutSeconds = 10);
	
public:
	static void OnLogin(const char* data);
	static void OnTokenInfo(const char* data);
	static void OnGetLoginInfo(const char* data);
	static void OnGetGeneralInfo(const char* data);
	static void OnQueryAllAchievement(const char* data);
	static void OnSetAchievementBatch(const char* data);
	static void OnQueryAchievement(const char* data);
	static void OnSetAchievement(const char* data);
	static void OnQueryAchievementPercentage(const char* data);
	static void OnCommonBusiness(const char* data);
	static void OnCloudPay(const char* data);
	static void OnCloudPayToCP(const char* data);
	static void OnCommonInterfaceByMsgSDK(const char* data);

private:
	static void OpenMessageBox(FString Content, FString Title = TEXT("Message"));


private:
	static UWorld* GetCurWorld();
};
