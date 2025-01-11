// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SystemInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FSystemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "DeviceModel"))
	FString DeviceModel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "DeviceName"))
	FString DeviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "DeviceType"))
	FString DeviceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "DeviceId"))
	FString DeviceUniqueId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "GraphicsDeviceName"))
	FString GraphicsDeviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "GraphicsDeviceVendor"))
	FString GraphicsDeviceVendor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "GraphicsMemorySize"))
	int32 GraphicsMemorySize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "NetworkType"))
	FString NetworkType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "OperatingSystem"))
	FString OperatingSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "ProcessorCount"))
	int32 ProcessorCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "ProcessorFrequency"))
	int32 ProcessorFrequency = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SystemInfo", meta = (JsonName = "ProcessorType"))
	FString ProcessorType;
};
