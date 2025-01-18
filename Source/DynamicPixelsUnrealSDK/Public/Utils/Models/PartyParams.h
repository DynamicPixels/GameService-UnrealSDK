#pragma once

#include "PartyParams.generated.h"

/**
 * Structure to hold input data for creating or editing a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyInput
{
    GENERATED_BODY()

    /** Name of the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString name;

    /** Description of the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString desc;

    /** Maximum number of members allowed in the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int max_member_count;

    /** Indicates if the party is private or public. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    bool is_private;

    /** List of team identifiers for the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> teams;

    /** List of channels associated with the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> channels;

    /** Map of additional variables associated with the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TMap<FString, FString> variables;
};

/**
 * Parameters for querying a list of parties.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartiesParams
{
    GENERATED_BODY()

    /** Query string to filter parties by name or description. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    FString Query = FString();

    /** Number of items to skip for pagination. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    int Skip;

    /** Maximum number of parties to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyQuery")
    int Limit;
};

/**
 * Parameters for creating a new party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FCreatePartyParams
{
    GENERATED_BODY()

    /** Input data for the new party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FPartyInput data;
};

/**
 * Parameters for retrieving a list of parties the user is subscribed to.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetSubscribedParties
{
    GENERATED_BODY()

    /** Query string to filter subscribed parties. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString Query = FString();

    /** Number of items to skip for pagination. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int Skip;

    /** Maximum number of parties to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int Limit;
};

/**
 * Parameters for joining a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FJoinToPartyParams
{
    GENERATED_BODY()

    /** Identifier of the party to join. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Name of the team within the party to join. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FString Team;

    /** List of channels to join within the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TArray<FString> Channels;
};

/**
 * Parameters for leaving a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLeavePartyParams
{
    GENERATED_BODY()

    /** Identifier of the party to leave. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
};

/**
 * Parameters for retrieving details of a specific party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyByIdParams
{
    GENERATED_BODY()

    /** Identifier of the party to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;
};

/**
 * Parameters for retrieving members of a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyMembersParams
{
    GENERATED_BODY()

    /** Identifier of the party to retrieve members from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Number of items to skip for pagination. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Skip;

    /** Maximum number of members to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Limit;
};

/**
 * Parameters for setting variables for a party member.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSetMemberVariablesParams
{
    GENERATED_BODY()

    /** Identifier of the party to update. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Map of variables to assign to the member. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    TMap<FString, FString> Data;
};

/**
 * Parameters for retrieving waiting members of a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FGetPartyWaitingMembersParams
{
    GENERATED_BODY()

    /** Identifier of the party to retrieve waiting members from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Number of items to skip for pagination. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Skip;

    /** Maximum number of members to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pagination")
    int Limit;
};

/**
 * Parameters for editing an existing party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FEditPartyParams
{
    GENERATED_BODY()

    /** Identifier of the party to edit. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** New details for the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    FPartyInput Party;
};

/**
 * Parameters for accepting a member's join request to a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FAcceptJoiningParams
{
    GENERATED_BODY()

    /** Identifier of the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Membership ID of the request to accept. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int MembershipId;
};

/**
 * Parameters for rejecting a member's join request to a party.
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRejectJoiningParams
{
    GENERATED_BODY()

    /** Identifier of the party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int PartyId;

    /** Membership ID of the request to reject. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party")
    int MembershipId;
};
