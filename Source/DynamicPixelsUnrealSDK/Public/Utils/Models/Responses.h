#pragma once

#include "CoreMinimal.h"
#include "Models/ConnectionInfo.h"
#include "Models/DynamicPixelsException.h"
#include "Models/LeaderboardModels.h"
#include "Models/User.h"
#include "Models/PartyModels.h"
#include "Responses.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLoginResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login Response")
    FUser user;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login Response")
    FString token;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Login Response")
    FConnectionInfo connection;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FActionResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Response")
    int Affected;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyMemberArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Member Array Response")
    TArray<FDynamicPartyMember> list;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Member Array Response")
    int totalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRichPartyMemberArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rich Party Member Array Response", meta = (JsonName = "list"))
    TArray<FRichPartyMember> List;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rich Party Member Array Response", meta = (JsonName = "totalCount"))
    int TotalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyModelArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Model Array Response", meta = (JsonName = "list"))
    TArray<FPartyModel> List;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Model Array Response", meta = (JsonName = "totalCount"))
    int TotalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FLeaderboardModelArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard Model Array Response", meta = (JsonName = "list"))
    TArray<FLeaderboardModel> List;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard Model Array Response", meta = (JsonName = "totalCount"))
    int TotalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FPartyScoreArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Score Array Response", meta = (JsonName = "list"))
    TArray<FPartyScore> List;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Party Score Array Response", meta = (JsonName = "totalCount"))
    int TotalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FUserScoreArrayResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Score Array Response", meta = (JsonName = "list"))
    TArray<FUserScore> List;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Score Array Response", meta = (JsonName = "totalCount"))
    int TotalCount;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FBoolResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bool Response", meta = (JsonName = "row"))
    bool Value;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulLoginCallback, FLoginResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartyListResponse, FPartyModelArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulLeaderboardListResponse, FLeaderboardModelArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartiesScoresListResponse, FPartyScoreArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulUsersScoresListResponse, FUserScoreArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulUserScoreResponse, FUserScore, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartyRichMemberListResponse, FRichPartyMemberArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartyResponse, FPartyModel, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartyMemberResponse, FDynamicPartyMember, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulPartyMemberListResponse, FPartyMemberArrayResponse, Response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FSuccessfulCallback, bool, WasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFailedLoginCallback, EErrorCode, ErrorCode, FString, ErrorMessage);
