// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
//#include "MiguCpSdk.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MiguCPSdkUEBPLibrary.generated.h"


UCLASS()
class  UMiguCPSdkUEBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu CreateInstanceMsg"), Category = "MiguCPSDK")
		static int CreateInstanceMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu LoginMsg"), Category = "MiguCPSDK")
		static void LoginMsg(FString ContentCode, int timeoutSeconds);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu LoginInforMsg"), Category = "MiguCPSDK")
		static int LoginInforMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu ReleaseSDKMsg"), Category = "MiguCPSDK")
		static int ReleaseSDKMsg();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MiGu GetToken"), Category = "MiguCPSDK")
		static void GetTokenInfor(int timeoutSeconds);

public:
	static void  OnLogin(const char* data);
	static void  OnTokenInfo(const char* data);

};
