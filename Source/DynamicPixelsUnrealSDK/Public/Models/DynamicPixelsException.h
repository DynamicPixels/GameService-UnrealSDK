#pragma once
#include "CoreMinimal.h"
#include "DynamicPixelsException.generated.h"

UENUM(BlueprintType)
enum class EErrorCode : uint8
{
	InvalidToken,
	UserAlreadyExist,
	UserNotFound,
	InvalidAccessToken,
	PayloadNotValid,
	UserIdNotFoundFromToken,
	TargetUserNotValid,
	CannotRequestYourself,
	RequestAlreadyExist,
	RequestNotFound,
	FriendshipNotFound,
	LeaderboardParticipantsNotUser,
	LeaderboardNotFound,
	LeaderboardParticipantsNotParty,
	PartyNotFound,
	InvalidTeam,
	InvalidChannels,
	MembershipAlreadyExist,
	PermissionDenied,
	MembershipNotFound,
	RowNotFound,
	InvalidSortOrder,
	EmailAlreadyExist,
	PhoneNumberAlreadyExist,
	UsernameAlreadyExist,
	InvalidResponse,
	AchievementNotFound,
	ConnectionNotReady,
	SdkAlreadyInitialized,
	UnknownError
};

class FErrorMapper
{
private:
	static const TMap<FString, EErrorCode> ErrorMap;
public:
	static EErrorCode GetErrorCode(const FString& ErrorMessage)
	{
		if (const EErrorCode* FoundErrorCode = ErrorMap.Find(ErrorMessage))
		{
			return *FoundErrorCode;
		}
		return EErrorCode::UnknownError; // Default error code for unknown errors
	}
};