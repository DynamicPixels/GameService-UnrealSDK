// Fill out your copyright notice in the Description page of Project Settings.


#include "Services/Authentication.h"

#include "JsonObjectConverter.h"
#include "ServiceHub.h"
#include "Models/ConnectionInfo.h"
#include "Models/User.h"
#include "Utils/HttpClient/WebRequest.h"
#include "Utils/WebSocketClient/WebSocketService.h"

const FString UAuthentication::SignupUrl = TEXT("/api/auth/email/register");
const FString UAuthentication::SigninUrl = TEXT("/api/auth/email/login");
const FString UAuthentication::GoogleAuthUrl = TEXT("/api/auth/oauth/google");
const FString UAuthentication::SteamAuthUrl = TEXT("/api/auth/oauth/steam");
const FString UAuthentication::GuestAuthUrl = TEXT("/api/auth/guest");
const FString UAuthentication::LoginWithTokenUrl = TEXT("/api/auth/login");
const FString UAuthentication::IsOtaReadyUrl = TEXT("/api/auth/ota");
const FString UAuthentication::SendOtaUrl = TEXT("/api/auth/ota");
const FString UAuthentication::VerifyOtaUrl = TEXT("/api/auth/ota/verify");


UAuthentication::UAuthentication()
{
}

void UAuthentication::RegisterWithEmail(FRegisterWithEmailParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(SignupUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::LoginWithEmail(FLoginWithEmailParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(SigninUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::LoginWithGoogleParams(FLoginWithGoogleParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(GoogleAuthUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::LoginWithSteam(FLoginWithSteamParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(SteamAuthUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::LoginAsGuest(FLoginAsGuestParams params, FSuccessfulLoginCallback successResponse,
                                   FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(GuestAuthUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::LoginWithToken(FLoginWithTokenParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(LoginWithTokenUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}

void UAuthentication::IsOtaReady(FIsOtaParams params, FSuccessfulCallback successResponse, FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FBoolResponse>(IsOtaReadyUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FBoolResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
		} else
		{
			successResponse.Execute(Response.Result.Value);
		}
	});
}

void UAuthentication::SendOtaToken(FSendOtaTokenParams params, FSuccessfulCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FActionResponse>(SendOtaUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FActionResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
		} else
		{
			successResponse.Execute(Response.Result.Affected > 0);
		}
	});
}

void UAuthentication::VerifyOtaToken(FVerifyOtaToken params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse)
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FLoginResponse>(LoginWithTokenUrl, StringJson, TMap<FString, FString>(), [this, errorResponse, successResponse](TResponseWrapper<FLoginResponse> Response)
	{
		if (!Response.Successful)
		{
			errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			return;
		}
		this->SetupSdk(Response.Result.Token, Response.Result.User, Response.Result.ConnectionInfo, [successResponse, Response]()
		{
			successResponse.Execute(Response.Result);
		}, [errorResponse]()
		{
			errorResponse.Execute(EErrorCode::UnknownError, TEXT("SDK Setup Failed"));
		});
	});
}


void UAuthentication::SetupSdk(FString Token, FUser User, FConnectionInfo ConnectionInfo, TFunction<void()> Success,
                               TFunction<void()> Fail)
{
	UServiceHub::IsAvailable = true;
	UServiceHub::Token = Token;
	UServiceHub::User = User;
	if (ConnectionInfo.Protocol == "wss")
	{
		UServiceHub::Agent->OnConnect.AddLambda([Success]()
		{
			Success();
			UServiceHub::Agent->OnConnect.Clear();
		});
		UServiceHub::Agent->OnConnect.AddLambda([Fail]()
		{
			Fail();
			UServiceHub::Agent->OnFailedConnection.Clear();
		});
	}
	UServiceHub::Agent->SetupForConnect(Token);
}
