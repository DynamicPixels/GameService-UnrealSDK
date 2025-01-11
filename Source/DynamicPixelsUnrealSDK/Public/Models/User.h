#pragma once

#include "CoreMinimal.h"
#include "SystemInfo.h"
#include "User.generated.h"

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FUser
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "name"))
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "email"))
	FString Email;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "phone_number"))
	FString PhoneNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "image"))
	FString Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "username"))
	FString Username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "label"))
	FString Label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "tags"))
	FString Tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "is_ban"))
	bool IsBan = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "is_tester"))
	bool IsTester = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "is_guest"))
	bool IsGuest = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "google_token"))
	FString GoogleToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "fcm_id"))
	FString FcmId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "first_login"))
	TOptional<FDateTime> FirstLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User", meta = (JsonName = "last_login"))
	TOptional<FDateTime> LastLogin;
};

USTRUCT(BlueprintType)
struct DYNAMICPIXELSUNREALSDK_API FDevice
{
	GENERATED_BODY()

	FDevice() = default;
	explicit FDevice(FSystemInfo Info)
	{
		DeviceModel = Info.DeviceModel;
		DeviceName = Info.DeviceName;
		DeviceType = Info.DeviceType;
		DeviceId = Info.DeviceUniqueId;
		GraphicsDeviceName = Info.GraphicsDeviceName;
		GraphicsDeviceVendor = Info.GraphicsDeviceVendor;
		GraphicsMemorySize = FString::FromInt(Info.GraphicsMemorySize);
		ProcessorCount = FString::FromInt(Info.ProcessorCount);
		ProcessorFrequency = FString::FromInt(Info.ProcessorFrequency);
		ProcessorType = Info.ProcessorType;
		NetworkType = Info.NetworkType;
		OperatingSystem = Info.OperatingSystem;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_id"))
	FString DeviceId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "first_login"))
	TOptional<FDateTime> FirstLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "last_login"))
	TOptional<FDateTime> LastLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "package_name"))
	FString PackageName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "sdk_version"))
	FString SdkVersion = TEXT("1.0.0");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "version_name"))
	FString VersionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "version_code"))
	FString VersionCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "os_api_level"))
	FString OsApiLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "from"))
	FString From;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "model"))
	FString Model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "product"))
	FString Product;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "carrier_name"))
	FString CarrierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "manufacturer"))
	FString Manufacturer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "other_tags"))
	FString OtherTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "screen_width"))
	FString ScreenWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "screen_height"))
	FString ScreenHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "sdcard_state"))
	FString SdcardState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "game_orientation"))
	FString GameOrientation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "network_type"))
	FString NetworkType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "mac_address"))
	FString MacAddress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "ip_address"))
	FString IpAddress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_name"))
	FString DeviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_model"))
	FString DeviceModel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "device_type"))
	FString DeviceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "operating_system"))
	FString OperatingSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "processor_type"))
	FString ProcessorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "processor_count"))
	FString ProcessorCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "processor_frequency"))
	FString ProcessorFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "graphic_device_name"))
	FString GraphicsDeviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "graphic_device_vendor"))
	FString GraphicsDeviceVendor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Device", meta = (JsonName = "graphic_memory_size"))
	FString GraphicsMemorySize;
};
