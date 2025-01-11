#pragma once

#include "CoreMinimal.h"
#include "Models/ConnectionInfo.h"
#include "Models/User.h"
#include "Utils/Models/Parameters.h"
#include "Utils/Models/Responses.h"
#include "Models/DynamicPixelsException.h"
#include "Authentication.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICPIXELSUNREALSDK_API UAuthentication : public UObject
{
	GENERATED_BODY()
public:
	UAuthentication();
	static const FString SignupUrl;
	static const FString SigninUrl;
	static const FString GoogleAuthUrl;
	static const FString GuestAuthUrl;
	static const FString LoginWithTokenUrl;
	static const FString IsOtaReadyUrl;
	static const FString SendOtaUrl;
	static const FString VerifyOtaUrl;
	static const FString SteamAuthUrl;
	
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void RegisterWithEmail(FRegisterWithEmailParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithEmail(FLoginWithEmailParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithGoogleParams(FLoginWithGoogleParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithSteam(FLoginWithSteamParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginAsGuest(FLoginAsGuestParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithToken(FLoginWithTokenParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void IsOtaReady(FIsOtaParams params, FSuccessfulCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void SendOtaToken(FSendOtaTokenParams params, FSuccessfulCallback successResponse, FFailedLoginCallback errorResponse);

	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void VerifyOtaToken(FVerifyOtaToken params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse);

private:
	void SetupSdk(FString Token, FUser User, FConnectionInfo ConnectionInfo, TFunction<void()> Success, TFunction<void()> Fail);
};
