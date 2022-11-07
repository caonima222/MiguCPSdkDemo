// Copyright Epic Games, Inc. All Rights Reserved.

#include "MiguCPSdkUEBPLibrary.h"
#include <string>
#include "Kismet/GameplayStatics.h"
#include "MIGUCPSDKGameInstance.h"
#include "Misc/MessageDialog.h"

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
	GetLoginInfo(TCHAR_TO_UTF8(*ContentCode), &UMiguCPSdkUEBPLibrary::OnGetLoginInfo, timeoutSeconds);
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
	QueryAllAchievement(&UMiguCPSdkUEBPLibrary::OnQueryAllAchievement, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::SetAchievementBatchMsg(FString ContentCode, int timeoutSeconds)
{
	SetAchievementBatch(TCHAR_TO_UTF8(*ContentCode), &UMiguCPSdkUEBPLibrary::OnSetAchievementBatch, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::QueryAchievementMsg(FString AchievementId, int timeoutSeconds)
{
	QueryAchievement(TCHAR_TO_UTF8(*AchievementId), &UMiguCPSdkUEBPLibrary::OnQueryAchievement, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::SetAchievementMsg(FString AchievementId, int AchievementType, float ReachValue, int timeoutSeconds)
{
	SetAchievement(TCHAR_TO_UTF8(*AchievementId), AchievementType, (double)ReachValue, &UMiguCPSdkUEBPLibrary::OnSetAchievement, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::QueryAchievementPercentageMsg(FString AchievementId, int timeoutSeconds)
{
	QueryAchievementPercentage(TCHAR_TO_UTF8(*AchievementId), &UMiguCPSdkUEBPLibrary::OnQueryAchievementPercentage, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::CommonBusinessMsg(FString BusinessUrl, FString Data, int timeoutSeconds)
{
	CommonBusiness(TCHAR_TO_UTF8(*BusinessUrl), TCHAR_TO_UTF8(*Data), &UMiguCPSdkUEBPLibrary::OnCommonBusiness, timeoutSeconds);
}

int UMiguCPSdkUEBPLibrary::CommonBusinessInitMsg(FString AppId, FString AppSecret)
{
	return CommonBusinessInit(TCHAR_TO_UTF8(*AppId), TCHAR_TO_UTF8(*AppSecret));
}

void UMiguCPSdkUEBPLibrary::CloudPayMsg(const FMiguPayInfo PayInfo, int timeoutSeconds)
{
	MiguPayInfo FinalPayInfo;
	FinalPayInfo.gameName = TCHAR_TO_ANSI(*PayInfo.gameName);
	FinalPayInfo.contentCode = TCHAR_TO_ANSI(*PayInfo.contentCode);
	FinalPayInfo.gameAccount = TCHAR_TO_ANSI(*PayInfo.gameAccount);
	FinalPayInfo.orderId = TCHAR_TO_ANSI(*PayInfo.orderId);
	FinalPayInfo.propName = TCHAR_TO_ANSI(*PayInfo.propName);
	FinalPayInfo.orderAmount = PayInfo.orderAmount;

	CloudPay(FinalPayInfo, &UMiguCPSdkUEBPLibrary::OnCloudPay, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::CloudPayToCPMsg(FString PayUrl, int timeoutSeconds)
{
	CloudPayToCP(TCHAR_TO_UTF8(*PayUrl), &UMiguCPSdkUEBPLibrary::OnCloudPayToCP, timeoutSeconds);
}

void UMiguCPSdkUEBPLibrary::CommonInterfaceByMsgSDKMsg(const int Type, FString Data, int timeoutSeconds)
{
	CommonInterfaceByMsgSDK(Type, TCHAR_TO_UTF8(*Data), &UMiguCPSdkUEBPLibrary::OnCommonInterfaceByMsgSDK, timeoutSeconds);
}



//-------------Handle Callback---------------------------------------------------------------

void UMiguCPSdkUEBPLibrary::OnLogin(const char* data)
{
	const FString LoginResult(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnLogin Callback= %s"), *LoginResult);
	OpenMessageBox(LoginResult);
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnLogin.Broadcast(LoginResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnGetLoginInfo(const char* data)
{
	const FString LoginResult(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnGetLoginInfo: %s"), *LoginResult);
	OpenMessageBox(LoginResult);
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetLoginInfo.Broadcast(LoginResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnTokenInfo(const char* data)
{
	const FString TokenResult(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnGetToken Callback= %s"), *TokenResult);
	OpenMessageBox(TokenResult);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetToken.Broadcast(TokenResult);
	}
}

void UMiguCPSdkUEBPLibrary::OnGetGeneralInfo(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnGetGeneralInfo: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnGetGeneralInfo.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnQueryAllAchievement(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnQueryAllAchievement: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnQueryAllAchievement.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnSetAchievementBatch(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnSetAchievementBatch: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnSetAchievementBatch.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnQueryAchievement(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnQueryAchievement: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnQueryAchievement.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnSetAchievement(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnSetAchievement: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnSetAchievement.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnQueryAchievementPercentage(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnQueryAchievementPercentage: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnQueryAchievementPercentage.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnCommonBusiness(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnCommonBusiness: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnCommonBusiness.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnCloudPay(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnCloudPay: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnCloudPay.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnCloudPayToCP(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnCloudPayToCP: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnCloudPayToCP.Broadcast(ResultString);
	}
}

void UMiguCPSdkUEBPLibrary::OnCommonInterfaceByMsgSDK(const char* data)
{
	const FString ResultString(UTF8_TO_TCHAR(data));
	UE_LOG(LogTemp, Warning, TEXT("OnCommonInterfaceByMsgSDK: %s"), *ResultString);
	OpenMessageBox(ResultString);
	
	UMIGUCPSDKGameInstance* MIGUSDKGameIns = Cast<UMIGUCPSDKGameInstance>(UGameplayStatics::GetGameInstance(UMiguCPSdkUEBPLibrary::GetCurWorld()));
	if (MIGUSDKGameIns)
	{
		MIGUSDKGameIns->OnCommonInterfaceByMsgSDK.Broadcast(ResultString);
	}
}


void UMiguCPSdkUEBPLibrary::OpenMessageBox(FString Content, FString Title)
{
#if !UE_BUILD_SHIPPING
	const FText DialogTitle = FText::FromString(Title);
	const FText DialogContent = FText::FromString(Content);
	EAppReturnType::Type const ReturnType = FMessageDialog::Open(EAppMsgType::Ok, DialogContent, &DialogTitle);
#endif
}

UWorld* UMiguCPSdkUEBPLibrary::GetCurWorld()
{
	UWorld* FinalWorld = nullptr;

	// Return PIE worlds if there are any
	for (const FWorldContext& Context : GEngine->GetWorldContexts())
	{
		if (Context.WorldType == EWorldType::PIE || Context.WorldType == EWorldType::Game)
		{
			FinalWorld = Context.World();
			return FinalWorld;
		}
	}

	check(FinalWorld);

	return FinalWorld;
}
PRAGMA_ENABLE_OPTIMIZATION
