#pragma once

#include "CoreMinimal.h"
#include "SystemInfo.h"
#include "User.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FUser
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString email;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString phone_number;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	bool is_ban = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	bool is_tester = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	bool is_guest = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString google_token;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString fcm_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString first_login;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User")
	FString last_login;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FDevice
{
	GENERATED_BODY()

	FDevice() = default;
	
	explicit FDevice(FSystemInfo Info)
	{
		device_model = Info.DeviceModel;
		device_name = Info.DeviceName;
		device_type = Info.DeviceType;
		device_id = Info.DeviceUniqueId;
		graphic_device_name = Info.GraphicsDeviceName;
		graphic_device_vendor = Info.GraphicsDeviceVendor;
		graphic_memory_size = FString::FromInt(Info.GraphicsMemorySize);
		processor_count = FString::FromInt(Info.ProcessorCount);
		processor_frequency = FString::FromInt(Info.ProcessorFrequency);
		processor_type = Info.ProcessorType;
		network_type = Info.NetworkType;
		operating_system = Info.OperatingSystem;
		first_login = TEXT("2025-01-14T10:35:21.1234567"); 
		last_login = TEXT("2025-01-14T10:35:21.1234567"); 
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString device_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString first_login;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString last_login;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString package_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString sdk_version = TEXT("1.0.0");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString version_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString version_code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString os_api_level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString from;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString product;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString carrier_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString manufacturer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString other_tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString screen_width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString screen_height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString sdcard_state;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString game_orientation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString network_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString mac_address;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString ip_address;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString device_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString device_model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString device_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString operating_system;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString processor_type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString processor_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString processor_frequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString graphic_device_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString graphic_device_vendor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device")
	FString graphic_memory_size;
};
