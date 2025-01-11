// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Utils/Models/Parameters.h"
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
		return FString::Printf(TEXT("/api/table/services/leaderboard/user/%d?skip=%d&limit=%d"), leaderboardId, skip, limit);
	}

	static FString GetPartiesScoresUrl(int leaderboardId, int skip, int limit)
	{
		return FString::Printf(TEXT("/api/table/services/leaderboard/party/%d?skip=%d&limit=%d"), leaderboardId, skip, limit);
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
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetLeaderBoards(FGetLeaderboardsParams params, FSuccessfulLeaderboardListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetPartiesScores(FGetScoresParams params, FSuccessfulPartiesScoresListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetUsersScores(FGetScoresParams params, FSuccessfulUsersScoresListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetFriendsScores(FGetFriendsScoresParams params, FSuccessfulUsersScoresListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void GetMyScore(FGetCurrentUserScoreParams params, FSuccessfulUserScoreResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void SubmitScore(FSubmitScoreParams params, FSuccessfulUserScoreResponse successResponse, FFailedLoginCallback errorResponse) const;
	
};
