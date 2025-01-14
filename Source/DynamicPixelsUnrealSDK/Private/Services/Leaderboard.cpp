#include "Services/Leaderboard.h"

#include "JsonObjectConverter.h"
#include "Utils/HttpClient/WebRequest.h"

void ULeaderboard::GetLeaderBoards(FGetLeaderboardsParams params, FSuccessfulLeaderboardListResponse successResponse,
                                   FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FLeaderboardModelArrayResponse>(GetLeaderboardsUrl(params.skip, params.limit, params.label), TMap<FString, FString>(),
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
	WebRequest::Post<FPartyScoreArrayResponse>(GetPartiesScoresUrl(params.leaderboard_id, params.skip, params.limit), StringJson, TMap<FString, FString>(),
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
	WebRequest::Post<FUserScoreArrayResponse>(GetUsersScoresUrl(params.leaderboard_id, params.skip, params.limit), StringJson, TMap<FString, FString>(),
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
	WebRequest::Post<FUserScoreArrayResponse>(GetMyFriendsScoreUrl(params.leaderboard_id), StringJson, TMap<FString, FString>(),
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
	WebRequest::Post<FUserScore>(GetCurrentUserScoreUrl(params.leaderboard_id), StringJson, TMap<FString, FString>(),
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
	WebRequest::Post<FUserScore>(SubmitScoreUrl(params.leaderboard_id), StringJson, TMap<FString, FString>(),
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
