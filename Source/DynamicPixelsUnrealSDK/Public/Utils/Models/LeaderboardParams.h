#pragma once
#include "Query.h"
#include "LeaderboardParams.generated.h"

/**
 * Parameters for retrieving leaderboards.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetLeaderboardsParams
{
    GENERATED_BODY()

    /** Label or category to filter the leaderboards. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboards")
    FString label;

    /** Number of items to skip for pagination purposes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    /** Maximum number of items to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;
};

/**
 * Parameters for retrieving leaderboard scores.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetScoresParams
{
    GENERATED_BODY()

    /** ID of the leaderboard to retrieve scores from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    /** Number of scores to skip for pagination purposes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    /** Maximum number of scores to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;

    /** Whether to include the current user's score in the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    bool bReturnUserScore = false;

    /** Additional filtering conditions for the query. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FQueryParam conditions;
};

/**
 * Parameters for retrieving the current user's score on a leaderboard.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetCurrentUserScoreParams
{
    GENERATED_BODY()

    /** ID of the leaderboard to retrieve the user's score from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    /** Additional filtering conditions for the query. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FQueryParam conditions;
};

/**
 * Parameters for retrieving friends' scores on a leaderboard.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetFriendsScoresParams
{
    GENERATED_BODY()

    /** ID of the leaderboard to retrieve scores from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    /** Number of scores to skip for pagination purposes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 skip = 0;

    /** Maximum number of scores to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int32 limit = 25;
};

/**
 * Parameters for submitting a score to a leaderboard.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSubmitScoreParams
{
    GENERATED_BODY()

    /** ID of the leaderboard to submit the score to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 leaderboard_id;

    /** Score value to be submitted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 score;

    /** Additional data to associate with the score submission. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    TMap<FString, FString> other_data;

    /** ID of the party associated with this score submission. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    int32 party_id;

    /** Unique identifier for this score submission. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scores")
    FString unique_by;
};
