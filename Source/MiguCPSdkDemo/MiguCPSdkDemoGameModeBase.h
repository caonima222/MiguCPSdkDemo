// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MiguCPSdkDemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MIGUCPSDKDEMO_API AMiguCPSdkDemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
	//protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	TSubclassOf<UUserWidget> MyWidgetClass;
	
	// void CreateWidgetInstance(TSubclassOf<UUserWidget> WidgetClass, FName WidgetName)
	void CreateWidgetInstance()
	{
		if(MyWidgetClass)
		{
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(PlayerController, MyWidgetClass);
			if(WidgetInstance)
			{
				WidgetInstance->AddToViewport();
			}
		}
	}
};
