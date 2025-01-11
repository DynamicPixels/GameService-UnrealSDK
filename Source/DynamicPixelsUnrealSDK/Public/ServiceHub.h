// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Models/SystemInfo.h"
#include "Models/User.h"
#include "Utils/WebSocketClient/WebSocketService.h"
#include "ServiceHub.generated.h"

class ULeaderboard;
class UParty;
class UAuthentication;

UCLASS(BlueprintType)
class DYNAMICPIXELSUNREALSDK_API UServiceHub : public UObject
{
public:
	GENERATED_BODY()
	UServiceHub();
	static FString Version() { return FString(TEXT("0.0.1")); }
	static bool DebugMode;
	static bool VerboseMode;
	static FSystemInfo SystemInfo;
	static FString GetClientId() { return ClientId; }
	static void Configure(FString clientId, FString clientSecret, FSystemInfo systemInfo, bool debugMode,
	                      bool developmentMode, bool verboseMode, short reconnectDelay, short maxAttempts);
	static bool IsAuthenticated();
	static void Dispose();
	static bool DevelopmentMode;
	static bool IsAvailable;
	static FUser User;
	static FString ClientId;
	static FString ClientSecret;
	static FString Token;
	static WebSocketService* Agent;
	static UAuthentication* Authentication;
	static UParty* Party;
	static ULeaderboard* Leaderboard;
	UFUNCTION(BlueprintCallable, Category="ServiceHub", BlueprintPure)
	static UAuthentication* GetAuthentication() {return Authentication;};
	UFUNCTION(BlueprintCallable, Category="ServiceHub", BlueprintPure)
	static UParty* GetParty() {return Party;};
	UFUNCTION(BlueprintCallable, Category="ServiceHub", BlueprintPure)
	static ULeaderboard* GetLeaderboard() {return Leaderboard;};
};
