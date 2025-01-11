// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConnectionInfo.generated.h"


USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FConnectionInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo", meta = (JsonName = "endpoint"))
	FString Endpoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo", meta = (JsonName = "protocol"))
	FString Protocol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo", meta = (JsonName = "version"))
	FString Version;

};
