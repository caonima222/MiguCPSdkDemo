// Fill out your copyright notice in the Description page of Project Settings.


#include "MainTestUI.h"

#include <string>

#include "MiguCPSdkUEBPLibrary.h"
#include "Misc/MessageDialog.h"

void UMainTestUI::NativeOnInitialized()
{
	if(Button_GeneralInfo)
	{
		Button_GeneralInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickGeneralInfo);
	}
	if(Button_AllAchievementInfo)
	{
		Button_AllAchievementInfo->OnClicked.AddDynamic(this, &UMainTestUI::OnClickAllAchievementInfo);
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
	if(Button_CommonBusiness)
	{
		Button_CommonBusiness->OnClicked.AddDynamic(this, &UMainTestUI::OnClickCommonBusiness);
	}
	if(Button_GetToken)
	{
		Button_GetToken->OnClicked.AddDynamic(this, &UMainTestUI::OnClickGetToken);
	}	
	if(Button_Pay)
	{
		Button_Pay->OnClicked.AddDynamic(this, &UMainTestUI::OnClickPay);
	}
	if(Button_CommonBusInit)
	{
		Button_CommonBusInit->OnClicked.AddDynamic(this, &UMainTestUI::OnClickCommonBusInit);
	}
	if(Button_CommonInterface)
	{
		Button_CommonInterface->OnClicked.AddDynamic(this, &UMainTestUI::OnClickCommonInterface);
	}
	if(Button_CPUrl)
	{
		Button_CPUrl->OnClicked.AddDynamic(this, &UMainTestUI::OnClickCPUrl);
	}
	if(Button_Init)
	{
		Button_Init->OnClicked.AddDynamic(this, &UMainTestUI::OnClickInit);
	}
}

void UMainTestUI::OnClickGeneralInfo()
{
	UMiguCPSdkUEBPLibrary::GetGeneralInfoMsg();
}

void UMainTestUI::OnClickAllAchievementInfo()
{
	UMiguCPSdkUEBPLibrary::QueryAllAchievementMsg();
}

void UMainTestUI::OnClickSingleInfo()
{
	UMiguCPSdkUEBPLibrary::QueryAchievementMsg("Achiement_KuaiBuYanXi");
}

void UMainTestUI::OnClickMultiSetting()
{
	std::string data=
		"{\
			'achievementSettingBean':\
			[\
				{'achievementId':'Achiement_DefeatMengZhang', 'type':1, 'reachValue':1.0},\
				{'achievementId': 'Achiement_KuaiBuYanXi', 'type':13, 'reachValue':13.0}\
			]\
		}";
	UMiguCPSdkUEBPLibrary::SetAchievementBatchMsg(data.c_str());
}

void UMainTestUI::OnClickSingleSetting()
{
	std::string id ="Achiement_KuaiBuYanXi";
	int type = 3;
	float value = 13;
	UMiguCPSdkUEBPLibrary::SetAchievementMsg(id.c_str(), type, value);
}

void UMainTestUI::OnClickAchieveRate()
{
	UMiguCPSdkUEBPLibrary::QueryAchievementPercentageMsg("Achiement_KuaiBuYanXi");
}

void UMainTestUI::OnClickReleaseInst()
{
	UMiguCPSdkUEBPLibrary::ReleaseSDKMsg();
}

void UMainTestUI::OnClickLogin()
{
	UMiguCPSdkUEBPLibrary::LoginMsg(TEXT("006206763000"));
}

void UMainTestUI::OnClickLoginInfo()
{
	UMiguCPSdkUEBPLibrary::LoginInfoMsg(TEXT("006206763000"));
}

void UMainTestUI::OnClickCommonBusiness()
{
	std::string data=
		"{\
		'dataList' : [{\
		'areaId': '1000', 'dataId' : 'occupation', 'dataType':1, 'dataValue':'3' }, {\
		'areaId': '1000', 'dataId' : 'aboutme', 'dataType':2, 'dataValue':'Hello, Hero' }, {\
		'areaId': '1000', 'dataId' : 'gamelevel', 'dataType':3, 'dataValue':'25' }\
		]\
		}";
	const char* bussinessUrl = "/data/save";
	UMiguCPSdkUEBPLibrary::CommonBusinessMsg(bussinessUrl, data.c_str());
}

void UMainTestUI::OnClickGetToken()
{
	UMiguCPSdkUEBPLibrary::GetTokenInfoMsg();
}

void UMainTestUI::OnClickPay()
{
	FMiguPayInfo info_temp;
	info_temp.contentCode = "006211535000";
	info_temp.gameName = "senyou";
	info_temp.gameAccount = "testuser2";
	info_temp.orderAmount = 1;
	info_temp.orderId = "92637865e1e28e7b";
	info_temp.propName = "道具名称";
	UMiguCPSdkUEBPLibrary::CloudPayMsg(info_temp);
}

void UMainTestUI::OnClickCommonBusInit()
{
	const char* appId = "cpsdkApiSecret";
	const char* appSecret = "@WSX!QAZ";
	UMiguCPSdkUEBPLibrary::CommonBusinessInitMsg(appId, appSecret);
}

void UMainTestUI::OnClickCommonInterface()
{
	UMiguCPSdkUEBPLibrary::CommonInterfaceByMsgSDKMsg(210001,"fileId:C:\\Users\\Administrator\\Desktop\\VNC 链 接 \\123.jpg,");
}

void UMainTestUI::OnClickCPUrl()
{
	UMiguCPSdkUEBPLibrary::CloudPayToCPMsg("http://payurl");
}

void UMainTestUI::OnClickInit()
{
	UMiguCPSdkUEBPLibrary::CreateInstanceMsg();
}


void UMainTestUI::OpenMessageBox(FString Title, FString Content)
{
	const FText DialogTitle = FText::FromString(Title);
	const FText DialogContent = FText::FromString(Content);
	EAppReturnType::Type const ReturnType = FMessageDialog::Open(EAppMsgType::Ok, DialogContent, &DialogTitle);
}

