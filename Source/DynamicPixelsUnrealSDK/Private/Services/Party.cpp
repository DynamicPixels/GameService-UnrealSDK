// Fill out your copyright notice in the Description page of Project Settings.


#include "Services/Party.h"

#include "JsonObjectConverter.h"
#include "Utils/HttpClient/WebRequest.h"

const FString UParty::GetPartiesUrl = TEXT("/api/table/services/parties");
const FString UParty::CreatePartyUrl = TEXT("/api/table/services/parties");
const FString UParty::GetSubscribedPartiesUrl = TEXT("/api/table/services/parties/me");

void UParty::GetParties(FSuccessfulPartyListResponse successResponse, FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FPartyModelArrayResponse>(GetPartiesUrl, TMap<FString, FString>(),
	                                     [this, errorResponse, successResponse](
	                                     TResponseWrapper<FPartyModelArrayResponse> Response)
	                                     {
		                                     if (!Response.Successful)
		                                     {
			                                     errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                                     return;
		                                     }
		                                     successResponse.Execute(Response.Result);
	                                     });
}

void UParty::CreateParty(FCreatePartyParams params, FSuccessfulPartyResponse successResponse,
                         FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FPartyModel>(CreatePartyUrl, StringJson, TMap<FString, FString>(),
	                              [this, errorResponse, successResponse](TResponseWrapper<FPartyModel> Response)
	                              {
		                              if (!Response.Successful)
		                              {
			                              errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                              return;
		                              }
		                              successResponse.Execute(Response.Result);
	                              });
}

void UParty::GetSubscribedParties(FSuccessfulPartyListResponse successResponse,
                                  FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FPartyModelArrayResponse>(GetSubscribedPartiesUrl, TMap<FString, FString>(),
	                                     [this, errorResponse, successResponse](
	                                     TResponseWrapper<FPartyModelArrayResponse> Response)
	                                     {
		                                     if (!Response.Successful)
		                                     {
			                                     errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                                     return;
		                                     }
		                                     successResponse.Execute(Response.Result);
	                                     });
}

void UParty::JoinToParty(FJoinToPartyParams params, FSuccessfulPartyMemberResponse successResponse,
                         FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Post<FDynamicPartyMember>(JoinToPartyUrl(params.PartyId), StringJson, TMap<FString, FString>(),
	                               [this, errorResponse, successResponse](TResponseWrapper<FDynamicPartyMember> Response)
	                               {
		                               if (!Response.Successful)
		                               {
			                               errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                               return;
		                               }
		                               successResponse.Execute(Response.Result);
	                               });
}

void UParty::LeaveParty(FLeavePartyParams params, FSuccessfulCallback successResponse,
                        FFailedLoginCallback errorResponse) const
{
	WebRequest::Delete<FActionResponse>(LeavePartyUrl(params.PartyId), TMap<FString, FString>(),
	                                    [this, errorResponse, successResponse](
	                                    TResponseWrapper<FActionResponse> Response)
	                                    {
		                                    if (!Response.Successful)
		                                    {
			                                    errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                                    return;
		                                    }
		                                    successResponse.Execute(Response.Result.Affected > 0);
	                                    });
}

void UParty::GetPartyById(FGetPartyByIdParams params, FSuccessfulPartyResponse successResponse,
                          FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FPartyModel>(GetPartyByIdUrl(params.PartyId), TMap<FString, FString>(),
	                             [this, errorResponse, successResponse](TResponseWrapper<FPartyModel> Response)
	                             {
		                             if (!Response.Successful)
		                             {
			                             errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                             return;
		                             }
		                             successResponse.Execute(Response.Result);
	                             });
}

void UParty::GetPartyMembers(FGetPartyMembersParams params, FSuccessfulPartyRichMemberListResponse successResponse,
                             FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FRichPartyMemberArrayResponse>(GetPartyMembersUrl(params.PartyId), TMap<FString, FString>(),
	                                          [this, errorResponse, successResponse](
	                                          TResponseWrapper<FRichPartyMemberArrayResponse> Response)
	                                          {
		                                          if (!Response.Successful)
		                                          {
			                                          errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
			                                          return;
		                                          }
		                                          successResponse.Execute(Response.Result);
	                                          });
}

void UParty::SetMemberVariables(FSetMemberVariablesParams params, FSuccessfulLoginCallback successResponse,
	FFailedLoginCallback errorResponse) const
{
}

void UParty::GetPartyWaitingMembers(FGetPartyWaitingMembersParams params, FSuccessfulPartyMemberListResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	WebRequest::Get<FPartyMemberArrayResponse>(GetPartyWaitingMembersUrl(params.PartyId), TMap<FString, FString>(),
											  [this, errorResponse, successResponse](
											  TResponseWrapper<FPartyMemberArrayResponse> Response)
											  {
												  if (!Response.Successful)
												  {
													  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
													  return;
												  }
												  successResponse.Execute(Response.Result);
											  });
}

void UParty::EditParty(FEditPartyParams params, FSuccessfulPartyResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Put<FPartyModel>(EditPartyUrl(params.PartyId), StringJson, TMap<FString, FString>(),
											  [this, errorResponse, successResponse](
											  TResponseWrapper<FPartyModel> Response)
											  {
												  if (!Response.Successful)
												  {
													  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
													  return;
												  }
												  successResponse.Execute(Response.Result);
											  });
}

void UParty::AcceptJoining(FAcceptJoiningParams params, FSuccessfulPartyMemberResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	FString StringJson;
	FJsonObjectConverter::UStructToJsonObjectString(params, StringJson);
	WebRequest::Put<FDynamicPartyMember>(AcceptJoiningUrl(params.PartyId, params.MembershipId), StringJson, TMap<FString, FString>(),
											  [this, errorResponse, successResponse](
											  TResponseWrapper<FDynamicPartyMember> Response)
											  {
												  if (!Response.Successful)
												  {
													  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
													  return;
												  }
												  successResponse.Execute(Response.Result);
											  });
}

void UParty::RejectJoining(FRejectJoiningParams params, FSuccessfulPartyMemberResponse successResponse,
	FFailedLoginCallback errorResponse) const
{
	WebRequest::Delete<FDynamicPartyMember>(RejectJoiningUrl(params.PartyId, params.MembershipId), TMap<FString, FString>(),
											  [this, errorResponse, successResponse](
											  TResponseWrapper<FDynamicPartyMember> Response)
											  {
												  if (!Response.Successful)
												  {
													  errorResponse.Execute(Response.ErrorCode, Response.ErrorMessage);
													  return;
												  }
												  successResponse.Execute(Response.Result);
											  });
}

