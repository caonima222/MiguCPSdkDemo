// Fill out your copyright notice in the Description page of Project Settings.


#include "MiguBlueprintFunctionLibrary.h"

APlayerController* UMiguBlueprintFunctionLibrary::GetLocalPlayerController(UObject* WorldContextObject)
{
	// if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	// {
	// 	for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
	// 	{
	// 		APlayerController* PlayerController = *Iterator;
	// 		if (PlayerController->IsLocalController())
	// 		{
	// 			// For this project, we will only ever have one local player.
	// 			return PlayerController;
	// 		}
	// 	}
	// }
	return nullptr;
}