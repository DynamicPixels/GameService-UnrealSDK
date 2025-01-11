#pragma once

#include "TableModels.generated.h"
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FRow
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Table", meta = (JsonName = "id"))
	int Id;
};