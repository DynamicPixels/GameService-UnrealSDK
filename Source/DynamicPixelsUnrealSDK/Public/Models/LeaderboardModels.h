#pragma once

#include "CoreMinimal.h"
#include "LeaderboardModels.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLeaderboardModel
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString unique_by;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString actions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FString extend_table;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    int32 course;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    int32 timeframe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    int32 ttl;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    int32 round;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    int32 winners_count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard")
    FDateTime last_wipe;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore")
    int32 value;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore")
    int32 tries;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseScore")
    int32 rank;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FUserScore : public FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FString image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FString username;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FString label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FString tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    bool is_ban;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    bool is_tester;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    bool is_guest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FDateTime first_login;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    FDateTime last_login;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    bool is_me;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserScore")
    bool is_friend;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyScore : public FBaseScore
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    FString desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    FString image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    bool is_me;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    bool is_private;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    FString data = TEXT("{}");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    TMap<FString, FString> variables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyScore")
    int32 owner;
};
