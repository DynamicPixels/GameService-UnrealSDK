#pragma once

#include "CoreMinimal.h"
#include "LeaderboardModels.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLeaderboardModel
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "name"))
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "desc"))
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "label"))
    FString Label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "unique_by"))
    FString UniqueBy;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "actions"))
    FString Actions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "extend_table"))
    FString ExtendTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "course"))
    int32 Course;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "timeframe"))
    int32 TimeFrame;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "ttl"))
    int32 TTL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "round"))
    int32 Round;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "winners_count"))
    int32 WinnersCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard", meta = (JsonName = "last_wipe"))
    FDateTime LastWipe;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore", meta = (JsonName = "value", JsonDefault = 0))
    int32 Value;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore", meta = (JsonName = "tries", JsonDefault = 0))
    int32 Tries;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore", meta = (JsonName = "rank", JsonDefault = 0))
    int32 Rank;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FUserScore : public FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "name"))
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "image"))
    FString Image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "username"))
    FString Username;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "label"))
    FString Label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "tags"))
    FString Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "is_ban"))
    bool bIsBan;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "is_tester"))
    bool bIsTester;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "is_guest"))
    bool bIsGuest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "first_login"))
    FDateTime FirstLogin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "last_login"))
    FDateTime LastLogin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "is_me"))
    bool bIsMe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore", meta = (JsonName = "is_friend"))
    bool bIsFriend;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyScore : public FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "name"))
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "desc"))
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "image"))
    FString Image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "is_me"))
    bool bIsMe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "is_private"))
    bool bIsPrivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "data"))
    FString Data = TEXT("{}");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "variables"))
    TMap<FString, FString> Variables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore", meta = (JsonName = "owner"))
    int32 Owner;
};
