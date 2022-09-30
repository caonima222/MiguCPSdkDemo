// Fill out your copyright notice in the Description page of Project Settings.


#include "MainTestUI.h"

#include "Misc/MessageDialog.h"

void UMainTestUI::NativeOnInitialized()
{
	if(Button_GeneralInfo)
	{
		Button_GeneralInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickGeneralInfo);
	}
	if(Button_AllInfo)
	{
		Button_AllInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickAllInfo);
	}
	if(Button_SingleInfo)
	{
		Button_SingleInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickSingleInfo);
	}
	if(Button_MultiSetting)
	{
		Button_MultiSetting->OnClicked.AddDynamic(this, &UMainTestUI::OnClickMultiSetting);
	}
	if(Button_SingleSetting)
	{
		Button_SingleSetting->OnClicked.AddDynamic(this, &UMainTestUI::OnClickSingleSetting);
	}
	if(Button_AchieveRate)
	{
		Button_AchieveRate->OnClicked.AddDynamic(this, &UMainTestUI::OnClickAchieveRate);
	}
	if(Button_ReleaseInst)
	{
		Button_ReleaseInst->OnClicked.AddDynamic(this, &UMainTestUI::OnClickReleaseInst);
	}
	if(Button_Login)
	{
		Button_Login->OnClicked.AddDynamic(this, &UMainTestUI::OnClickLogin);
	}
	if(Button_LoginInfo)
	{
		Button_LoginInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickLoginInfo);
	}
	if(Button_SendData)
	{
		Button_SendData->OnClicked.AddDynamic(this, &UMainTestUI::OnClickSendData);
	}
	if(Button_GetToken)
	{
		Button_GetToken->OnClicked.AddDynamic(this, &UMainTestUI::OnClickGetToken);
	}	
	if(Button_Pay)
	{
		Button_Pay->OnClicked.AddDynamic(this, &UMainTestUI::OnClickPay);
	}
	if(Button_SaveImage)
	{
		Button_SaveImage->OnClicked.AddDynamic(this, &UMainTestUI::OnClickSaveImage);
	}
	if(Button_Exit)
	{
		Button_Exit->OnClicked.AddDynamic(this, &UMainTestUI::OnClickExit);
	}
	if(Button_CPUrl)
	{
		Button_CPUrl->OnClicked.AddDynamic(this, &UMainTestUI::OnClickCPUrl);
	}
}

void UMainTestUI::OnClickGeneralInfo()
{
	
}

void UMainTestUI::OnClickAllInfo()
{
	
}

void UMainTestUI::OnClickSingleInfo()
{
	
}

void UMainTestUI::OnClickMultiSetting()
{
	
}

void UMainTestUI::OnClickSingleSetting()
{
	
}

void UMainTestUI::OnClickAchieveRate()
{
	
}

void UMainTestUI::OnClickReleaseInst()
{
	
}

void UMainTestUI::OnClickLogin()
{
	
}

void UMainTestUI::OnClickLoginInfo()
{
	
}

void UMainTestUI::OnClickSendData()
{
	
}

void UMainTestUI::OnClickGetToken()
{
	
}

void UMainTestUI::OnClickPay()
{
	OpenMessageBox("PayTitle", "Pay Successfully!");
}

void UMainTestUI::OnClickSaveImage()
{
	
}

void UMainTestUI::OnClickExit()
{
	
}

void UMainTestUI::OnClickCPUrl()
{
	
}


void UMainTestUI::OpenMessageBox(FString Title, FString Content)
{
	const FText DialogTitle = FText::FromString(Title);
	const FText DialogContent = FText::FromString(Content);
	EAppReturnType::Type const ReturnType = FMessageDialog::Open(EAppMsgType::Ok, DialogContent, &DialogTitle);
}

