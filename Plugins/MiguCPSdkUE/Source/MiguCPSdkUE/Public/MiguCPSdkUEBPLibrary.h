// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MiguCPSdkUEBPLibrary.generated.h"


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
		static void LoginInfoMsg(FString ContentCode, int timeoutSeconds);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu ReleaseSDKMsg"), Category = "MiguCPSDK")
		static void ReleaseSDKMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu GetToken"), Category = "MiguCPSDK")
		static void GetTokenInfo(int timeoutSeconds = 10);

public:
	static void  OnLogin(const char* data);
	static void  OnTokenInfo(const char* data);
	static void OnGetLoginInfo(const char* data);

};
