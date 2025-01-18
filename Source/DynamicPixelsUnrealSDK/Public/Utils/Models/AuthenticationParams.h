#pragma once
#include "Models/User.h"
#include "AuthenticationParams.generated.h"

/**
 * Parameters for registering a new user with an email address.
 * Includes the user's name, email, password, and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRegisterWithEmailParams
{
    GENERATED_BODY()

    /** The user's full name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString name;

    /** The user's email address for registration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString email;

    /** The user's password for registration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString password;

    /** Device-specific information for the registration process. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for logging in with an email address.
 * Includes the email, password, and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithEmailParams
{
    GENERATED_BODY()

    /** The email address associated with the user account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString email;

    /** The password associated with the user account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString password;

    /** Device-specific information for the login process. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for logging in with a Google account.
 * Includes an access token and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithGoogleParams
{
    GENERATED_BODY()

    /** The access token retrieved from Google authentication. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString access_token;

    /** Device-specific information for the login process. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for logging in with a Steam account.
 * Includes Steam ID, App ID, username, and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithSteamParams
{
    GENERATED_BODY()

    /** The unique Steam ID of the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString steam_id;

    /** The ID of the application registered on Steam. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString app_id;

    /** The user's name on Steam. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString name;

    /** Device-specific information for the login process. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for logging in as a guest user.
 * Includes the guest name, optional device ID, and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginAsGuestParams
{
    GENERATED_BODY()

    /** The name to assign to the guest user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest")
    FString name;

    /** The unique ID of the device (optional). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest")
    FString device_id = FString();

    /** Device-specific information for the guest login. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for logging in with an authentication token.
 * Includes the token and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithTokenParams
{
    GENERATED_BODY()

    /** The authentication token issued to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    FString token;

    /** Device-specific information for the login process. */
    UPROPERTY()
    FDevice device_info;
};

/**
 * Parameters for checking if a One-Time Authentication (OTA) process is ready.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FIsOtaParams
{
    GENERATED_BODY()
};

/**
 * Parameters for sending a One-Time Authentication (OTA) token to a phone number.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSendOtaTokenParams
{
    GENERATED_BODY()

    /** The phone number to send the OTA token to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString phone_number;
};

/**
 * Parameters for verifying a One-Time Authentication (OTA) token.
 * Includes the phone number, username, token, and device information.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FVerifyOtaToken
{
    GENERATED_BODY()

    /** The phone number used for authentication. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString phone_number;

    /** The user's name (optional). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString name;

    /** The OTP token received by the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString token;

    /** Device-specific information for the token verification process. */
    UPROPERTY()
    FDevice device_info;
};
