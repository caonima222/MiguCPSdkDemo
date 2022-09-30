// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainTestUI.generated.h"

/**
 * 
 */
UCLASS()
class MIGUCPSDKDEMO_API UMainTestUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_GeneralInfo;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_AllInfo;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_SingleInfo;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_MultiSetting;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_SingleSetting;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_AchieveRate;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_ReleaseInst;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Login;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_LoginInfo;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_SendData;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_GetToken;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Pay;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_SaveImage;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Exit;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_CPUrl;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Init;


	UFUNCTION()
	void OnClickGeneralInfo();

	UFUNCTION()
	void OnClickAllInfo();

	UFUNCTION()
	void OnClickSingleInfo();

	UFUNCTION()
	void OnClickMultiSetting();

	UFUNCTION()
	void OnClickSingleSetting();

	UFUNCTION()
	void OnClickAchieveRate();

	UFUNCTION()
	void OnClickReleaseInst();

	UFUNCTION()
	void OnClickLogin();

	UFUNCTION()
	void OnClickLoginInfo();

	UFUNCTION()
	void OnClickSendData();

	UFUNCTION()
	void OnClickGetToken();

	UFUNCTION()
	void OnClickPay();
	
	UFUNCTION()
	void OnClickSaveImage();

	UFUNCTION()
	void OnClickExit();

	UFUNCTION()
	void OnClickCPUrl();

	UFUNCTION()
	void OnClickInit();

	UFUNCTION()
	void OpenMessageBox(FString Title, FString Content);
};
