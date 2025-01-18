// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Utils/Models/LeaderboardParams.h"
#include "Utils/Models/Responses.h"
#include "Leaderboard.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICPIXELSUNREALSDK_API ULeaderboard : public UObject
{
	GENERATED_BODY()

public:
	static FString GetLeaderboardsUrl(int skip, int limit, FString label)
	{
		return FString::Printf(TEXT("/api/table/services/leaderboard/?skip=%d&limit=%d&label=%s"), skip, limit, *label);
	}

	static FString GetUsersScoresUrl(int leaderboardId, int skip, int limit)
	{
		return FString::Printf(
			TEXT("/api/table/services/leaderboard/user/%d?skip=%d&limit=%d"), leaderboardId, skip, limit);
	}

	static FString GetPartiesScoresUrl(int leaderboardId, int skip, int limit)
	{
		return FString::Printf(
			TEXT("/api/table/services/leaderboard/party/%d?skip=%d&limit=%d"), leaderboardId, skip, limit);
	}

	static FString GetCurrentUserScoreUrl(int leaderboardId)
	{
		return FString::Printf(TEXT("/api/table/services/leaderboard/%d/me"), leaderboardId);
	}

	static FString GetMyFriendsScoreUrl(int leaderboardId)
	{
		return FString::Printf(TEXT("/api/table/services/leaderboard/%d/friends"), leaderboardId);
	}

	static FString SubmitScoreUrl(int leaderboardId)
	{
		return FString::Printf(TEXT("/api/table/services/leaderboard/%d"), leaderboardId);
	}

	/**
 * Retrieves a list of available leaderboards based on the specified parameters.
 * @param params - Parameters for filtering or fetching leaderboards.
 * @param successResponse - Callback triggered with the list of leaderboards on success.
 * @param errorResponse - Callback triggered if retrieving the leaderboards fails.
 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetLeaderBoards(FGetLeaderboardsParams params, FSuccessfulLeaderboardListResponse successResponse,
	                     FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the scores of parties on a specified leaderboard.
	 * @param params - Parameters including leaderboard and party details.
	 * @param successResponse - Callback triggered with the list of party scores on success.
	 * @param errorResponse - Callback triggered if fetching party scores fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetPartiesScores(FGetScoresParams params, FSuccessfulPartiesScoresListResponse successResponse,
	                      FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the scores of individual users on a specified leaderboard.
	 * @param params - Parameters including leaderboard and user filtering criteria.
	 * @param successResponse - Callback triggered with the list of user scores on success.
	 * @param errorResponse - Callback triggered if fetching user scores fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetUsersScores(FGetScoresParams params, FSuccessfulUsersScoresListResponse successResponse,
	                    FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the scores of friends on a specified leaderboard.
	 * @param params - Parameters including leaderboard and friend group details.
	 * @param successResponse - Callback triggered with the list of friend scores on success.
	 * @param errorResponse - Callback triggered if fetching friend scores fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetFriendsScores(FGetFriendsScoresParams params, FSuccessfulUsersScoresListResponse successResponse,
	                      FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the current user's score on a specified leaderboard.
	 * @param params - Parameters including leaderboard and user details.
	 * @param successResponse - Callback triggered with the user's score details on success.
	 * @param errorResponse - Callback triggered if fetching the user's score fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetMyScore(FGetCurrentUserScoreParams params, FSuccessfulUserScoreResponse successResponse,
	                FFailedLoginCallback errorResponse) const;

	/**
	 * Submits a new score for the current user to a specified leaderboard.
	 * @param params - Parameters including leaderboard, score details, and metadata.
	 * @param successResponse - Callback triggered with confirmation of the submitted score on success.
	 * @param errorResponse - Callback triggered if submitting the score fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void SubmitScore(FSubmitScoreParams params, FSuccessfulUserScoreResponse successResponse,
	                 FFailedLoginCallback errorResponse) const;
};
