// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Utils/Models/Parameters.h"
#include "Utils/Models/Responses.h"
#include "Party.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICPIXELSUNREALSDK_API UParty : public UObject
{
	GENERATED_BODY()

public:
	static const  FString GetPartiesUrl;
	static const FString CreatePartyUrl;
	static const FString GetSubscribedPartiesUrl;

	static FString GetPartyByIdUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d"), partyId);
	}

	static FString JoinToPartyUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d"), partyId);
	}

	static FString EditPartyUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d"), partyId);
	}

	static FString LeavePartyUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d"), partyId);
	}

	static FString GetPartyMembersUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d/members"), partyId);
	}

	static FString GetPartyWaitingMembersUrl(int partyId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d/waiting"), partyId);
	}

	static FString AcceptJoiningUrl(int partyId, int membershipId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d/waiting/%d"), partyId, membershipId);
	}

	static FString RejectJoiningUrl(int partyId, int membershipId)
	{
		return FString::Printf(TEXT("/api/table/services/parties/%d/waiting/%d"), partyId, membershipId);
	}
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetParties(FSuccessfulPartyListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void CreateParty(FCreatePartyParams params, FSuccessfulPartyResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetSubscribedParties(FSuccessfulPartyListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void JoinToParty(FJoinToPartyParams params, FSuccessfulPartyMemberResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void LeaveParty(FLeavePartyParams params, FSuccessfulCallback successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyById(FGetPartyByIdParams params, FSuccessfulPartyResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyMembers(FGetPartyMembersParams params, FSuccessfulPartyRichMemberListResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void SetMemberVariables(FLoginWithTokenParams params, FSuccessfulLoginCallback successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyWaitingMembers(FGetPartyWaitingMembersParams params, FSuccessfulPartyMemberListResponse successResponse, FFailedLoginCallback
	                            errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void EditParty(FEditPartyParams params, FSuccessfulPartyResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void AcceptJoining(FAcceptJoiningParams params, FSuccessfulPartyMemberResponse successResponse, FFailedLoginCallback errorResponse) const;
	UFUNCTION(BlueprintCallable, Category="Party")
	void RejectJoining(FRejectJoiningParams params, FSuccessfulPartyMemberResponse successResponse, FFailedLoginCallback errorResponse) const;
	
};
