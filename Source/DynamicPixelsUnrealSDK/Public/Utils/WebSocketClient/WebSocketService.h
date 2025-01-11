// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IWebSocket.h"
#include "Containers/Ticker.h"
#include "Utils/Models/Request.h"

struct FWebSocketConfiguration
{
	FString WebSocketUrl;
	short MaxReconnectAttempts;
	short ReconnectDelay;
	short PingInterval;
};

enum EWebSocketStatus
{
	Disconnected = 0,
	Connecting = 1,
	Connected = 2
};

class DYNAMICPIXELSUNREALSDK_API WebSocketService
{
public:
	WebSocketService();
	~WebSocketService();
	WebSocketService* Config(FWebSocketConfiguration Config);
	void SetupForConnect(FString LoginToken);
	DECLARE_EVENT_OneParam(WebSocketService, FOnMessageReceived, const FRequest&);
	FOnMessageReceived OnMessageReceived;
	DECLARE_EVENT(WebSocketService, FOnDisconnect)
	FOnDisconnect OnDisconnect;
	DECLARE_EVENT(WebSocketService, FOnConnected)
	FOnConnected OnConnect;
	DECLARE_EVENT(WebSocketService, FOnConnectionFailed)
	FOnConnectionFailed OnFailedConnection;
	void Dispose();
	void Connect();
	

private:
	static TSharedPtr<IWebSocket> WebSocketClient;
	static FWebSocketConfiguration Configuration;
	static FString Token;
	short Attempts;
	bool SendPing(float DeltaTime) const;
	void OnConnected();
	void OnConnectionError(const FString& ErrorMessage);
	void OnClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
	void OnMessage(const FString& Message);
	void OnMessageSent(const FString& MessageString);
	FTSTicker::FDelegateHandle TickHandle;
	EWebSocketStatus ConnectionStatus;
};
