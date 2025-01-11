// Fill out your copyright notice in the Description page of Project Settings.


#include "ServiceHub.h"

#include "Models/SystemInfo.h"
#include "Services/Authentication.h"
#include "Services/Leaderboard.h"
#include "Services/Party.h"
#include "Utils/WebSocketClient/WebSocketService.h"

bool UServiceHub::DebugMode = false;
bool UServiceHub::DevelopmentMode = false;
bool UServiceHub::VerboseMode = false;
bool UServiceHub::IsAvailable = false;
UAuthentication* UServiceHub::Authentication = nullptr;
UParty* UServiceHub::Party = nullptr;
ULeaderboard* UServiceHub::Leaderboard = nullptr;
FUser UServiceHub::User = FUser();
FSystemInfo UServiceHub::SystemInfo = FSystemInfo();
WebSocketService* UServiceHub::Agent = new WebSocketService();
FString UServiceHub::ClientSecret = TEXT("");
FString UServiceHub::ClientId = TEXT("");
FString UServiceHub::Token = TEXT("");

UServiceHub::UServiceHub()
{
}

void UServiceHub::Configure(FString clientId, FString clientSecret, FSystemInfo systemInfo, bool debugMode,
                           bool developmentMode, bool verboseMode, short reconnectDelay, short maxAttempts)
{
	if (IsAvailable)
		return;
	Agent->Config(
		FWebSocketConfiguration(TEXT("wss://ws-europe.dynamicpixels.dev/ws"), maxAttempts, reconnectDelay, 10));
	ClientId = clientId;
	ClientSecret = clientSecret;
	DebugMode = debugMode;
	VerboseMode = verboseMode;
	DevelopmentMode = developmentMode;
	SystemInfo = systemInfo;
	Authentication = NewObject<UAuthentication>();
	Party = NewObject<UParty>();
	Leaderboard = NewObject<ULeaderboard>();
}

bool UServiceHub::IsAuthenticated()
{
	return !Token.IsEmpty();
}

void UServiceHub::Dispose()
{
	Agent->Dispose();
}

