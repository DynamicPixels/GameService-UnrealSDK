#pragma once

#include "CoreMinimal.h"
#include "Models/ConnectionInfo.h"
#include "Models/User.h"
#include "Utils/Models/AuthenticationParams.h"
#include "Utils/Models/Responses.h"
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

	/**
 * Registers a new user using their email address.
 * @param params - The parameters required for email registration.
 * @param successResponse - Callback triggered on a successful registration.
 * @param errorResponse - Callback triggered if registration fails.
 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void RegisterWithEmail(FRegisterWithEmailParams params, FSuccessfulLoginCallback successResponse,
	                       FFailedLoginCallback errorResponse);

	/**
	 * Logs in a user using their email address.
	 * @param params - The parameters required for email login.
	 * @param successResponse - Callback triggered on a successful login.
	 * @param errorResponse - Callback triggered if login fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithEmail(FLoginWithEmailParams params, FSuccessfulLoginCallback successResponse,
	                    FFailedLoginCallback errorResponse);

	/**
	 * Logs in a user using their Google account.
	 * @param params - The parameters required for Google login.
	 * @param successResponse - Callback triggered on a successful login.
	 * @param errorResponse - Callback triggered if login fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithGoogleParams(FLoginWithGoogleParams params, FSuccessfulLoginCallback successResponse,
	                           FFailedLoginCallback errorResponse);

	/**
	 * Logs in a user using their Steam account.
	 * @param params - The parameters required for Steam login.
	 * @param successResponse - Callback triggered on a successful login.
	 * @param errorResponse - Callback triggered if login fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithSteam(FLoginWithSteamParams params, FSuccessfulLoginCallback successResponse,
	                    FFailedLoginCallback errorResponse);

	/**
	 * Logs in a user as a guest.
	 * @param params - The parameters required for guest login.
	 * @param successResponse - Callback triggered on a successful login.
	 * @param errorResponse - Callback triggered if login fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginAsGuest(FLoginAsGuestParams params, FSuccessfulLoginCallback successResponse,
	                  FFailedLoginCallback errorResponse);

	/**
	 * Logs in a user using an authentication token.
	 * @param params - The parameters required for token-based login.
	 * @param successResponse - Callback triggered on a successful login.
	 * @param errorResponse - Callback triggered if login fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void LoginWithToken(FLoginWithTokenParams params, FSuccessfulLoginCallback successResponse,
	                    FFailedLoginCallback errorResponse);

	/**
	 * Checks if a One-Time Authentication (OTA) token is ready for use.
	 * @param params - The parameters required to check OTA readiness.
	 * @param successResponse - Callback triggered on a successful check.
	 * @param errorResponse - Callback triggered if the check fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void IsOtaReady(FIsOtaParams params, FSuccessfulCallback successResponse, FFailedLoginCallback errorResponse);

	/**
	 * Sends a One-Time Authentication (OTA) token to the user.
	 * @param params - The parameters required to send the OTA token.
	 * @param successResponse - Callback triggered on a successful token send.
	 * @param errorResponse - Callback triggered if sending fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void SendOtaToken(FSendOtaTokenParams params, FSuccessfulCallback successResponse,
	                  FFailedLoginCallback errorResponse);

	/**
	 * Verifies a One-Time Authentication (OTA) token provided by the user.
	 * @param params - The parameters required to verify the OTA token.
	 * @param successResponse - Callback triggered on a successful verification.
	 * @param errorResponse - Callback triggered if verification fails.
	 */
	UFUNCTION(BlueprintCallable, Category = "Authentication")
	void VerifyOtaToken(FVerifyOtaToken params, FSuccessfulLoginCallback successResponse,
	                    FFailedLoginCallback errorResponse);

private:
	void SetupSdk(FString Token, FUser User, FConnectionInfo ConnectionInfo, TFunction<void()> Success,
	              TFunction<void()> Fail);
};
