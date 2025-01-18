// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Utils/Models/PartyParams.h"
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
	static const FString GetPartiesUrl;
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

	/**
 * Retrieves the list of all parties that the user can interact with.
 * @param successResponse - Callback triggered with the list of parties on success.
 * @param errorResponse - Callback triggered if retrieving the party list fails.
 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetParties(FSuccessfulPartyListResponse successResponse, FFailedLoginCallback errorResponse) const;

	/**
	 * Creates a new party based on the provided parameters.
	 * @param params - The parameters required to create the party.
	 * @param successResponse - Callback triggered with details of the created party on success.
	 * @param errorResponse - Callback triggered if creating the party fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void CreateParty(FCreatePartyParams params, FSuccessfulPartyResponse successResponse,
	                 FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the list of parties the user is subscribed to.
	 * @param successResponse - Callback triggered with the list of subscribed parties on success.
	 * @param errorResponse - Callback triggered if retrieving the subscribed party list fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetSubscribedParties(FSuccessfulPartyListResponse successResponse, FFailedLoginCallback errorResponse) const;

	/**
	 * Joins the user to an existing party.
	 * @param params - The parameters required to join the party.
	 * @param successResponse - Callback triggered with party member details on success.
	 * @param errorResponse - Callback triggered if joining the party fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void JoinToParty(FJoinToPartyParams params, FSuccessfulPartyMemberResponse successResponse,
	                 FFailedLoginCallback errorResponse) const;

	/**
	 * Allows the user to leave a party.
	 * @param params - The parameters required to leave the party.
	 * @param successResponse - Callback triggered on successful leaving of the party.
	 * @param errorResponse - Callback triggered if leaving the party fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void LeaveParty(FLeavePartyParams params, FSuccessfulCallback successResponse,
	                FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the details of a specific party by its ID.
	 * @param params - The parameters containing the party ID to fetch.
	 * @param successResponse - Callback triggered with the party's details on success.
	 * @param errorResponse - Callback triggered if retrieving the party details fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyById(FGetPartyByIdParams params, FSuccessfulPartyResponse successResponse,
	                  FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the list of members in a specified party.
	 * @param params - The parameters containing the party ID.
	 * @param successResponse - Callback triggered with the list of party members on success.
	 * @param errorResponse - Callback triggered if retrieving the party members fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyMembers(FGetPartyMembersParams params, FSuccessfulPartyRichMemberListResponse successResponse,
	                     FFailedLoginCallback errorResponse) const;

	/**
	 * Sets variables specific to a member of a party.
	 * @param params - The parameters containing member information and variables to update.
	 * @param successResponse - Callback triggered on success.
	 * @param errorResponse - Callback triggered if setting member variables fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void SetMemberVariables(FSetMemberVariablesParams params, FSuccessfulLoginCallback successResponse,
	                        FFailedLoginCallback errorResponse) const;

	/**
	 * Retrieves the list of members waiting to join a specified party.
	 * @param params - The parameters containing the party ID.
	 * @param successResponse - Callback triggered with the list of waiting members on success.
	 * @param errorResponse - Callback triggered if retrieving waiting members fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void GetPartyWaitingMembers(FGetPartyWaitingMembersParams params,
	                            FSuccessfulPartyMemberListResponse successResponse,
	                            FFailedLoginCallback errorResponse) const;

	/**
	 * Edits the settings or information of a party.
	 * @param params - The parameters with the updated party details.
	 * @param successResponse - Callback triggered with the updated party details on success.
	 * @param errorResponse - Callback triggered if editing the party fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void EditParty(FEditPartyParams params, FSuccessfulPartyResponse successResponse,
	               FFailedLoginCallback errorResponse) const;

	/**
	 * Accepts a pending request from a user to join a party.
	 * @param params - The parameters containing the joining request details.
	 * @param successResponse - Callback triggered with the member's updated party information on success.
	 * @param errorResponse - Callback triggered if accepting the joining request fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void AcceptJoining(FAcceptJoiningParams params, FSuccessfulPartyMemberResponse successResponse,
	                   FFailedLoginCallback errorResponse) const;

	/**
	 * Rejects a pending request from a user to join a party.
	 * @param params - The parameters containing the joining request details.
	 * @param successResponse - Callback triggered with the updated party member information on success.
	 * @param errorResponse - Callback triggered if rejecting the joining request fails.
	 */
	UFUNCTION(BlueprintCallable, Category="Party")
	void RejectJoining(FRejectJoiningParams params, FSuccessfulPartyMemberResponse successResponse,
	                   FFailedLoginCallback errorResponse) const;
};
