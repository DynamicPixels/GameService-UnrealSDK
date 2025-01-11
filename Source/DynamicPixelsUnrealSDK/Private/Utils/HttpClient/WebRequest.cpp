#include "Utils/HttpClient/WebRequest.h"

#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"
#include "Models/DynamicPixelsException.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Utils/Models/Responses.h"
#include "Misc/ConfigCacheIni.h"

template void WebRequest::Post<FLoginResponse>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FLoginResponse>)>);
template void WebRequest::Post<FActionResponse>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FActionResponse>)>);
template void WebRequest::Get<FPartyModelArrayResponse>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyModelArrayResponse>)>);

template void WebRequest::Post<FPartyModel>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyModel>)>);

template void WebRequest::Post<FDynamicPartyMember>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FDynamicPartyMember>)>);

template void WebRequest::Delete<FActionResponse>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FActionResponse>)>);
template void WebRequest::Delete<FDynamicPartyMember>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FDynamicPartyMember>)>);

template void WebRequest::Get<FPartyModel>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyModel>)>);

template void WebRequest::Get<FRichPartyMemberArrayResponse>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FRichPartyMemberArrayResponse>)>);

template void WebRequest::Get<FPartyMemberArrayResponse>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyMemberArrayResponse>)>);
template void WebRequest::Get<FLeaderboardModelArrayResponse>(
	FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FLeaderboardModelArrayResponse>)>);

template void WebRequest::Put<FPartyModel>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyModel>)>);

template void WebRequest::Put<FDynamicPartyMember>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FDynamicPartyMember>)>);

template void WebRequest::Post<FBoolResponse>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FBoolResponse>)>);
template void WebRequest::Post<FPartyScoreArrayResponse>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FPartyScoreArrayResponse>)>);
template void WebRequest::Post<FUserScoreArrayResponse>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FUserScoreArrayResponse>)>);
template void WebRequest::Post<FUserScore>(
	FString, FString, TMap<FString, FString>, TFunction<void(TResponseWrapper<FUserScore>)>);

WebRequest::WebRequest()
{
	GConfig->SetFloat(TEXT("HTTP"), TEXT("HttpTimeout"), TimeOut, GEngineIni);
}

WebRequest::~WebRequest()
{
}

template <typename T>
void WebRequest::Get(FString Url, TMap<FString, FString> Headers, TFunction<void(TResponseWrapper<T>)> ResponseCallback)
{
	DoRequest(Url, TEXT("GET"), TEXT(""), Headers, [ResponseCallback](FRequestResponse Response)
	          {
		          T ResultObject{};
		          if (Response.Successful)
		          {
			          if (!Response.Data.IsEmpty())
			          {
				          TSharedPtr<FJsonObject> JsonObject;
				          TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response.Data);
				          if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				          {
					          FJsonObjectConverter::JsonObjectToUStruct<T>(JsonObject.ToSharedRef(), &ResultObject);
				          }
			          }
		          }
		          ResponseCallback(TResponseWrapper<T>(ResultObject, Response.Successful, Response.ErrorCode,
		                                               Response.ErrorMessage));
	          }
	);
}

template <typename T>
void WebRequest::Put(FString Url, FString Body, TMap<FString, FString> Headers,
                     TFunction<void(TResponseWrapper<T>)> ResponseCallback)
{
	DoRequest(Url, TEXT("PUT"), Body, Headers, [ResponseCallback](FRequestResponse Response)
	          {
		          T ResultObject{};
		          if (Response.Successful)
		          {
			          if (!Response.Data.IsEmpty())
			          {
				          TSharedPtr<FJsonObject> JsonObject;
				          TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response.Data);
				          if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				          {
				          	FJsonObjectConverter::JsonObjectToUStruct<T>(JsonObject.ToSharedRef(), &ResultObject);
				          }
			          }
		          }
		          ResponseCallback(TResponseWrapper<T>(ResultObject, Response.Successful, Response.ErrorCode,
		                                               Response.ErrorMessage));
	          }
	);
}

template <typename T>
void WebRequest::Patch(FString Url, FString Body, TMap<FString, FString> Headers,
                       TFunction<void(TResponseWrapper<T>)> ResponseCallback)
{
	DoRequest(Url, TEXT("PATCH"), Body, Headers, [ResponseCallback](FRequestResponse Response)
	          {
		          T ResultObject{};
		          if (Response.Successful)
		          {
			          if (!Response.Data.IsEmpty())
			          {
				          TSharedPtr<FJsonObject> JsonObject;
				          TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response.Data);
				          if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				          {
				          	FJsonObjectConverter::JsonObjectToUStruct<T>(JsonObject.ToSharedRef(), &ResultObject);
				          }
			          }
		          }
		          ResponseCallback(TResponseWrapper<T>(ResultObject, Response.Successful, Response.ErrorCode,
		                                               Response.ErrorMessage));
	          }
	);
}

template <typename T>
void WebRequest::Post(FString Url, FString Body, TMap<FString, FString> Headers,
                      TFunction<void(TResponseWrapper<T>)> ResponseCallback)
{
	DoRequest(Url, TEXT("POST"), Body, Headers, [ResponseCallback](FRequestResponse Response)
	          {
		          T ResultObject{};
		          if (Response.Successful)
		          {
			          if (!Response.Data.IsEmpty())
			          {
				          TSharedPtr<FJsonObject> JsonObject;
				          TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response.Data);
				          if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				          {
				          	FJsonObjectConverter::JsonObjectToUStruct<T>(JsonObject.ToSharedRef(), &ResultObject);
				          }
			          }
		          }
		          ResponseCallback(TResponseWrapper<T>(ResultObject, Response.Successful, Response.ErrorCode,
		                                               Response.ErrorMessage));
	          }
	);
}

template <typename T>
void WebRequest::Delete(FString Url, TMap<FString, FString> Headers,
                        TFunction<void(TResponseWrapper<T>)> ResponseCallback)
{
	DoRequest(Url, TEXT("DELETE"), TEXT(""), Headers, [ResponseCallback](FRequestResponse Response)
	          {
		          T ResultObject{};
		          if (Response.Successful)
		          {
			          if (!Response.Data.IsEmpty())
			          {
				          TSharedPtr<FJsonObject> JsonObject;
				          TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response.Data);
				          if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				          {
				          	FJsonObjectConverter::JsonObjectToUStruct<T>(JsonObject.ToSharedRef(), &ResultObject);
				          }
			          }
		          }
		          ResponseCallback(TResponseWrapper<T>(ResultObject, Response.Successful, Response.ErrorCode,
		                                               Response.ErrorMessage));
	          }
	);
}

void WebRequest::DoRequest(FString Url, const FString& Method, FString Body, TMap<FString, FString> Headers,
                           TFunction<void(FRequestResponse)> CallbackFunction)
{
	Url = BaseUrl() + Url;
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetURL(Url);
	Request->SetVerb(Method);
	for (auto Header : Headers)
	{
		Request->SetHeader(Header.Key, Header.Value);
	}
	Request->SetContentAsString(Body);
	Request->OnProcessRequestComplete().BindLambda(
		[CallbackFunction](FHttpRequestPtr Request2, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			OnHttpResponseReceived(Request2, Response, bWasSuccessful, CallbackFunction);
		});
	Request->ProcessRequest();
}

void WebRequest::OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful,
                                        TFunction<void(FRequestResponse)> CallbackFunction)
{
	FString Result = Response.Get()->GetContentAsString();
	if (bWasSuccessful && Response.Get()->GetResponseCode() >= 300)
		bWasSuccessful = false;
	if (bWasSuccessful)
	{
		CallbackFunction(FRequestResponse(Result, true, EErrorCode::UnknownError, TEXT("")));
		return;
	}
	auto ErrorResponse = FErrorResponse::FromJson(Result);
	auto ErrorCode = FErrorMapper::GetErrorCode(ErrorResponse.Message);
	if (ErrorCode == EErrorCode::UnknownError)
	{
		CallbackFunction(FRequestResponse(TEXT(""), false, ErrorCode, TEXT("")));
		return;
	}
	CallbackFunction(FRequestResponse(TEXT(""), false, ErrorCode, ErrorResponse.Message));
}
