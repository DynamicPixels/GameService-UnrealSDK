#pragma once
#include "TableModels.h"
#include "User.h"
#include "PartyModels.generated.h"

UENUM(BlueprintType)
enum class EPartyMemberStatus : uint8
{
    Waiting = 0,
    Accepted = 1,
};

UENUM(BlueprintType)
enum class EPartyMemberRoles : uint8
{
    None = 0,
    Owner = 1,
    Admin = 2,
    Member = 3,
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyModel : public FRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    int max_member_count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    int is_private;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString teams;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString channels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    TMap<FString, FString> variables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    int owner;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
    FString data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FDynamicPartyMember : public FRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    int party;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    int player;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    EPartyMemberRoles role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    EPartyMemberStatus status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    FString team;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    FString channels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    TMap<FString, FString> variables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember")
    FString data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRichPartyMember : public FUser
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    EPartyMemberRoles role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    EPartyMemberStatus status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    FString team;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    FString channels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    TMap<FString, FString> variables;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember")
    FString data;
};
