// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConnectionInfo.generated.h"


USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FConnectionInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo")
	FString endpoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo")
	FString protocol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConnectionInfo")
	FString version;

};
