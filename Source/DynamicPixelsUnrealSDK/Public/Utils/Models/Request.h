#pragma once

#include "CoreMinimal.h"
#include "Serialization/JsonTypes.h"
#include "Serialization/JsonWriter.h"
#include "Request.generated.h"

USTRUCT(BlueprintType)
struct FRequest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "1"))
	FString GameId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "2"))
	FString Protocol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "3"))
	int32 ReceiverId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "4"))
	FString Method;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "5"))
	FString Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Request", meta = (JsonName = "6"))
	int32 SenderId;

};
