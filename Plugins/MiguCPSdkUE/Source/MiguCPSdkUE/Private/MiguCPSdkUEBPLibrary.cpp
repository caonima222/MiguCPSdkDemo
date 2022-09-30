// Copyright Epic Games, Inc. All Rights Reserved.

#include "MiguCPSdkUEBPLibrary.h"
#include "MiguCpSdk.h"
#include <string>
#include "Kismet/GameplayStatics.h"
#include "MIGUCPSDKGameInstance.h"

PRAGMA_DISABLE_OPTIMIZATION

UMiguCPSdkUEBPLibrary::UMiguCPSdkUEBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


int UMiguCPSdkUEBPLibrary::CreateInstanceMsg()
{

	return CreateInstance_MsgSDK();
}


void UMiguCPSdkUEBPLibrary::LoginMsg(FString ContentCode, int timeoutSeconds)
{
	Login(TCHAR_TO_UTF8(*ContentCode), &UMiguCPSdkUEBPLibrary::OnLogin, 10);
}

int UMiguCPSdkUEBPLibrary::LoginInforMsg()
{
	return 0;

}

int UMiguCPSdkUEBPLibrary::ReleaseSDKMsg()
{
	return 0;
}

void UMiguCPSdkUEBPLibrary::GetTokenInfor(int timeoutSeconds)
{
	GetToken(&UMiguCPSdkUEBPLibrary::OnTokenInfo, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::OnLogin(const char* data)
{
	FString LoginResult;
	std::string temp = data;
	LoginResult = FString(temp.c_str());
	UE_LOG(LogTemp, Log, TEXT("OnLogin Callback= %s"), *LoginResult);
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnLogin.Broadcast(LoginResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnTokenInfo(const char* data)
{
	FString TokenResult;
	std::string temp = data;
	TokenResult = FString(temp.c_str());

	UE_LOG(LogTemp, Log, TEXT("OnGetToken Callback= %s"), *TokenResult);

	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetToken.Broadcast(TokenResult);
	}
}


PRAGMA_ENABLE_OPTIMIZATION
