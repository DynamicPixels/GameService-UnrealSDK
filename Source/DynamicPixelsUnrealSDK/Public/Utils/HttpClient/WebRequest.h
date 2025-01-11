// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ServiceHub.h"
#include "HttpFwd.h"
#include "Tickable.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"
#include "Models/DynamicPixelsException.h"

class DYNAMICPIXELSUNREALSDK_API FRequestResponse
{
public:
	FRequestResponse(const FString& Data, bool bSuccessful, EErrorCode ErrorCode, const FString& ErrorMessage)
		: Data(Data),
		  Successful(bSuccessful),
		  ErrorCode(ErrorCode),
		  ErrorMessage(ErrorMessage)
	{
	}

	FString Data;
	bool Successful;
	EErrorCode ErrorCode;
	FString ErrorMessage;
};

class DYNAMICPIXELSUNREALSDK_API FErrorResponse
{
public:
	FString Message;
	bool Status;
	static FErrorResponse FromJson(const FString& JsonString)
	{
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FString Message = JsonObject->GetStringField(TEXT("msg"));
			bool Status = JsonObject->GetBoolField(TEXT("status"));
			return FErrorResponse(Message, Status);
		}
		return FErrorResponse();
	}
};

template <typename Type>
class DYNAMICPIXELSUNREALSDK_API TResponseWrapper
{
public:
	TResponseWrapper(const Type& Result, bool bSuccessful, EErrorCode ErrorCode, const FString& ErrorMessage)
		: Result(Result),
		  Successful(bSuccessful),
		  ErrorCode(ErrorCode),
		  ErrorMessage(ErrorMessage)
	{
	}
	Type Result;
	bool Successful;
	EErrorCode ErrorCode;
	FString ErrorMessage;
};
class DYNAMICPIXELSUNREALSDK_API FResponseWrapper
{
public:
	bool Successful;
	EErrorCode ErrorCode;
	FString ErrorMessage;
};


class DYNAMICPIXELSUNREALSDK_API WebRequest
{
public:
	WebRequest();
	~WebRequest();
	template<typename T> static void Get(FString Url, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback);
	template<typename T> static void Put(FString Url, FString Body, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback);
	template<typename T> static void Patch(FString Url, FString Body, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback);
	template<typename T> static void Post(FString Url, FString Body, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback);
	template<typename T> static void Delete(FString Url, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback);

private:
	static FString BaseUrl()
	{
		return UServiceHub::DevelopmentMode
			? FString::Printf(TEXT("http://localhost:5286/game/%s"), *UServiceHub::GetClientId())
			: FString::Printf(TEXT("https://link.dynamicpixels.dev/game/%s"), *UServiceHub::GetClientId());
	};
	static FString UserAgent()
	{
		return FString::Printf(TEXT("UnitySDK-%s"), *UServiceHub::Version());
	}

	static constexpr int TimeOut = 15;

	static void DoRequest(FString Url, const FString& Method, FString Body, TMap<FString, FString> Headers, TFunction<void(FRequestResponse)>
	                      CallbackFunction);
	static void OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TFunction<void(FRequestResponse)>
	                                   CallbackFunction);

};

