#include "Services/Leaderboard.h"

#include "JsonObjectConverter.h"
#include "Utils/HttpClient/WebRequest.h"

void ULeaderboard::GetLeaderBoards(FGetLeaderboardsParams params, FSuccessfulLeaderboardListResponse successResponse,
                                   FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FLeaderboardModelArrayResponse>(GetLeaderboardsUrl(params.Skip, params.Limit, params.Label), TMap<FString, FString>(),
										 [this, errorResponse, successResponse](
										 TResponseWrapper<FLeaderboardModelArrayResponse> Response)
										 {
											 if (!Response.Successful)
											 {
												 errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
												 return;
											 }
											 successResponse.Execute(Response.Result);
										 });
}

void ULeaderboard::GetPartiesScores(FGetScoresParams params, FSuccessfulPartiesScoresListResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FPartyScoreArrayResponse>(GetPartiesScoresUrl(params.LeaderboardId, params.Skip, params.Limit), StringJson, TMap<FString, FString>(),
								  [this, errorResponse, successResponse](TResponseWrapper<FPartyScoreArrayResponse> Response)
								  {
									  if (!Response.Successful)
									  {
										  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
										  return;
									  }
									  successResponse.Execute(Response.Result);
								  });
}

void ULeaderboard::GetUsersScores(FGetScoresParams params, FSuccessfulUsersScoresListResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FUserScoreArrayResponse>(GetUsersScoresUrl(params.LeaderboardId, params.Skip, params.Limit), StringJson, TMap<FString, FString>(),
								  [this, errorResponse, successResponse](TResponseWrapper<FUserScoreArrayResponse> Response)
								  {
									  if (!Response.Successful)
									  {
										  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
										  return;
									  }
									  successResponse.Execute(Response.Result);
								  });
}

void ULeaderboard::GetFriendsScores(FGetFriendsScoresParams params, FSuccessfulUsersScoresListResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FUserScoreArrayResponse>(GetMyFriendsScoreUrl(params.LeaderboardId), StringJson, TMap<FString, FString>(),
								  [this, errorResponse, successResponse](TResponseWrapper<FUserScoreArrayResponse> Response)
								  {
									  if (!Response.Successful)
									  {
										  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
										  return;
									  }
									  successResponse.Execute(Response.Result);
								  });
}

void ULeaderboard::GetMyScore(FGetCurrentUserScoreParams params, FSuccessfulUserScoreResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FUserScore>(GetCurrentUserScoreUrl(params.LeaderboardId), StringJson, TMap<FString, FString>(),
								  [this, errorResponse, successResponse](TResponseWrapper<FUserScore> Response)
								  {
									  if (!Response.Successful)
									  {
										  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
										  return;
									  }
									  successResponse.Execute(Response.Result);
								  });
}

void ULeaderboard::SubmitScore(FSubmitScoreParams params, FSuccessfulUserScoreResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FUserScore>(GetCurrentUserScoreUrl(params.LeaderboardId), StringJson, TMap<FString, FString>(),
								  [this, errorResponse, successResponse](TResponseWrapper<FUserScore> Response)
								  {
									  if (!Response.Successful)
									  {
										  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
										  return;
									  }
									  successResponse.Execute(Response.Result);
								  });
}
