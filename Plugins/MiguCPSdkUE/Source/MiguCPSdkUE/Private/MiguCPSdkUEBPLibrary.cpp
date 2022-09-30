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
	Login(TCHAR_TO_UTF8(*ContentCode), &UMiguCPSdkUEBPLibrary::OnLogin, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::LoginInfoMsg(FString ContentCode, int timeoutSeconds)
{
	GetLoginInfo(TCHAR_TO_UTF8(*ContentCode), &UMiguCPSdkUEBPLibrary::OnLogin, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::ReleaseSDKMsg()
{
	ReleaseInstance();
}

void UMiguCPSdkUEBPLibrary::GetTokenInfoMsg(int timeoutSeconds)
{
	GetToken(&UMiguCPSdkUEBPLibrary::OnTokenInfo, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::GetGeneralInfoMsg(int timeoutSeconds)
{
	GetGeneralInfo(&UMiguCPSdkUEBPLibrary::OnGetGeneralInfo, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::QueryAllAchievementMsg(int timeoutSeconds)
{
	QueryAllAchievement(&UMiguCPSdkUEBPLibrary::OnGetGeneralInfo, timeoutSeconds);
}


//-------------Handle Callback---------------------------------------------------------------

void UMiguCPSdkUEBPLibrary::OnLogin(const char* data)
{
	FString LoginResult;
	std::string temp = data;
	LoginResult = FString(temp.c_str());
	UE_LOG(LogTemp, Warning, TEXT("OnLogin Callback= %s"), *LoginResult);
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnLogin.Broadcast(LoginResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnGetLoginInfo(const char* data)
{
	FString LoginResult;
	std::string temp = data;
	LoginResult = FString(temp.c_str());
	UE_LOG(LogTemp, Warning, TEXT("OnGetLoginInfo: %s"), *LoginResult);
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetLoginInfo.Broadcast(LoginResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnTokenInfo(const char* data)
{
	FString TokenResult;
	std::string temp = data;
	TokenResult = FString(temp.c_str());

	UE_LOG(LogTemp, Warning, TEXT("OnGetToken Callback= %s"), *TokenResult);

	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetToken.Broadcast(TokenResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnGetGeneralInfo(const char* data)
{
	FString TokenResult;
	std::string temp = data;
	TokenResult = FString(temp.c_str());

	UE_LOG(LogTemp, Warning, TEXT("OnGetGeneralInfo: %s"), *TokenResult);

	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetGeneralInfo.Broadcast(TokenResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnQueryAllAchievement(const char* data)
{
	FString TokenResult;
	std::string temp = data;
	TokenResult = FString(temp.c_str());

	UE_LOG(LogTemp, Warning, TEXT("OnQueryAllAchievement: %s"), *TokenResult);

	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(GEngine->GetWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnQueryAllAchievement.Broadcast(TokenResult);
	}
}



PRAGMA_ENABLE_OPTIMIZATION
