// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/WebSocketClient/WebSocketService.h"

#include "JsonObjectConverter.h"
#include "WebSocketsModule.h"
#include "Utils/Models/Request.h"

TSharedPtr<IWebSocket> WebSocketService::WebSocketClient = nullptr;
FWebSocketConfiguration WebSocketService::Configuration = FWebSocketConfiguration();
FString WebSocketService::Token = FString();

WebSocketService::WebSocketService()
{
}

WebSocketService::~WebSocketService()
{
	if (TickHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);
	}
}

WebSocketService* WebSocketService::Config(FWebSocketConfiguration Config)
{
	Configuration = Config;
	return this;
	
}

void WebSocketService::SetupForConnect(FString LoginToken)
{
	Token = LoginToken;
	WebSocketClient = FWebSocketsModule::Get().CreateWebSocket(Configuration.WebSocketUrl + TEXT("?token=") + LoginToken);
	WebSocketClient->OnConnected().AddRaw(this, &WebSocketService::OnConnected);
	WebSocketClient->OnConnectionError().AddRaw(this, &WebSocketService::OnConnectionError);
	WebSocketClient->OnClosed().AddRaw(this, &WebSocketService::OnClosed);
	WebSocketClient->OnMessage().AddRaw(this, &WebSocketService::OnMessage);
	WebSocketClient->OnMessageSent().AddRaw(this, &WebSocketService::OnMessageSent);
	Attempts = 0;
	ConnectionStatus = Connecting;
	Connect();
}

void WebSocketService::Dispose()
{
	OnMessageReceived.Clear();
	OnDisconnect.Clear();
}

bool WebSocketService::SendPing(float DeltaTime) const
{
	if (ConnectionStatus == Connected)
	{
		WebSocketClient->Send(TEXT("{\"4\":\"ping\",\"5\":\"ping\"}"));
	}
	return ConnectionStatus == Connected;
}

void WebSocketService::Connect()
{
	Attempts++;
	WebSocketClient->Connect();
	
}

void WebSocketService::OnConnected()
{
	UE_LOG(LogTemp, Warning, TEXT("Connected"))
	ConnectionStatus = Connected;
	OnConnect.Broadcast();
	TickHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &WebSocketService::SendPing), Configuration.PingInterval);
}

void WebSocketService::OnConnectionError(const FString& ErrorMessage)
{
	if (Attempts <= Configuration.MaxReconnectAttempts)
	{
		Connect();
	} else
	{
		OnFailedConnection.Broadcast();
		WebSocketClient->Close();
	}
}

void WebSocketService::OnClosed(int32 StatusCode, const FString& Reason, bool bWasClean)
{
	ConnectionStatus = Disconnected;
}

void WebSocketService::OnMessage(const FString& Message)
{
	if (Message.Compare(TEXT("{\"4\":\"ping\",\"5\":\"ping\"}\n")))
		return;
	FRequest Msg;
	FJsonObjectConverter::JsonObjectStringToUStruct(Message, &Msg);
	OnMessageReceived.Broadcast(Msg);
	
}

void WebSocketService::OnMessageSent(const FString& MessageString)
{
}
