#pragma once
#include "Query.h"
#include "ServiceHub.h"
#include "Models/User.h"
#include "Parameters.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRegisterWithEmailParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString email;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Registration")
    FString password;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithEmailParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString email;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString password;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithGoogleParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString access_token;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithSteamParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString steam_id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString app_id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login")
    FString name;
    UPROPERTY()
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginAsGuestParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest")
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guest")
    FString device_id = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginWithTokenParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    FString token;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString phone_number;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FVerifyOtaToken
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString phone_number;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OTA")
    FString token;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
    FDevice device_info = FDevice(UServiceHub::SystemInfo);
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyInput
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString desc;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int max_member_count;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    bool is_private;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> teams;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> channels;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TMap<FString, FString> variables;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartiesParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    FString Query = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    int Limit;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FCreatePartyParams
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FPartyInput data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetSubscribedParties
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString Query = FString();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int Skip;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboards")
    FString label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetScoresParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    bool bReturnUserScore = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FQueryParam conditions;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetCurrentUserScoreParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FQueryParam conditions;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetFriendsScoresParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSubmitScoreParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 score;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    TMap<FString, FString> other_data;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 party_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FString unique_by;
};
