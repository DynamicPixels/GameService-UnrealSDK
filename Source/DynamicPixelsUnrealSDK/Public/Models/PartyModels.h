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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "name"))
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "desc"))
	FString Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "image"))
	FString Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "max_member_count"))
	int MaxMemberCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "is_private"))
	int IsPrivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "teams"))
	FString Teams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "channels"))
	FString Channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "variables"))
	TMap<FString, FString> Variables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel")
	int Owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartyModel", meta = (JsonName = "data"))
	FString Data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FDynamicPartyMember : public FRow
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "party"))
	int Party;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "player"))
	int Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "role"))
	EPartyMemberRoles Role;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "status"))
	EPartyMemberStatus Status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "team"))
	FString Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "channels"))
	FString Channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "variables"))
	TMap<FString, FString> Variables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamicPartyMember", meta = (JsonName = "data"))
	FString Data;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRichPartyMember : public FUser
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "role"))
	EPartyMemberRoles Role;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "status"))
	EPartyMemberStatus Status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "team"))
	FString Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "channels"))
	FString Channels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "variables"))
	TMap<FString, FString> Variables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RichPartyMember", meta = (JsonName = "data"))
	FString Data;
};
