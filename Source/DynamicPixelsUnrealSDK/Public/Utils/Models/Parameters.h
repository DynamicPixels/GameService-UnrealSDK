#pragma once
#include "Query.h"
#include "ServiceHub.h"
#include "Models/User.h"
#include "Parameters.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRegisterWithEmailParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration", meta = (JsonName = "name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration", meta = (JsonName = "email"))
    FString Email;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration", meta = (JsonName = "password"))
    FString Password;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithEmailParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "email"))
    FString Email;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "password"))
    FString Password;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithGoogleParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "access_token"))
    FString AccessToken;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithSteamParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "steam_id"))
    FString SteamId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "app_id"))
    FString AppId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login", meta = (JsonName = "name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginAsGuestParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest", meta = (JsonName = "name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest", meta = (JsonName = "device_id"))
    FString DeviceId = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithTokenParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token", meta = (JsonName = "token"))
    FString Token;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FIsOtaParams
{
    GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSendOtaTokenParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA", meta = (JsonName = "phone_number"))
    FString PhoneNumber;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FVerifyOtaToken
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA", meta = (JsonName = "phone_number"))
    FString PhoneNumber;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA", meta = (JsonName = "name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA", meta = (JsonName = "token"))
    FString Token;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_info"))
    FDevice DeviceInfo = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyInput
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "desc"))
    FString Desc;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "max_member_count"))
    int MaxMemberCount;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "is_private"))
    int IsPrivate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "teams"))
    int Teams;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "channels"))
    TArray<FString> Channels;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "variables"))
    TMap<FString, FString> Variables;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartiesParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery", meta = (JsonName = "Query"))
    FString Query = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery", meta = (JsonName = "Skip"))
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery", meta = (JsonName = "Limit"))
    int Limit;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FCreatePartyParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FPartyInput Data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetSubscribedParties
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "Query"))
    FString Query = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "Skip"))
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party", meta = (JsonName = "Limit"))
    int Limit;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FJoinToPartyParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString Team;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> Channels;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLeavePartyParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyByIdParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyMembersParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Limit;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSetMemberVariablesParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TMap<FString, FString> Data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyWaitingMembersParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Limit;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FEditPartyParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FPartyInput Party;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FAcceptJoiningParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int MembershipId;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRejectJoiningParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int MembershipId;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetLeaderboardsParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboards", meta = (JsonName = "label"))
    FString Label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "skip"))
    int32 Skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "limit"))
    int32 Limit = 25;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetScoresParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "leaderboardid"))
    int32 LeaderboardId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "skip"))
    int32 Skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "limit"))
    int32 Limit = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "return_me"))
    bool bReturnUserScore = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "conditions"))
    FQueryParam Conditions;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetCurrentUserScoreParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "leaderboard_id"))
    int32 LeaderboardId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "conditions"))
    FQueryParam Conditions;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetFriendsScoresParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "leaderboard_id"))
    int32 LeaderboardId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "skip"))
    int32 Skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination", meta = (JsonName = "limit"))
    int32 Limit = 25;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSubmitScoreParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "leaderboard_id"))
    int32 LeaderboardId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "score", JsonDefault = 0))
    int32 Score;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "other_data"))
    TMap<FString, FString> OtherData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "party_id"))
    int32 PartyId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores", meta = (JsonName = "unique_by"))
    FString UniqueBy;
};
