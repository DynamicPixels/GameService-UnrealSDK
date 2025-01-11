#pragma once

#include "CoreMinimal.h"
#include "Query.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FQueryParam
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueryParam", meta = (JsonName = "op"))
	FString Op;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueryParam", meta = (JsonName = "field"))
	FString Field;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueryParam", meta = (JsonName = "value"))
	FString Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueryParam", meta = (JsonName = "values"))
	TArray<FString> Values;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (JsonName = "list"))
	// TArray<FQueryParam> List;

};
