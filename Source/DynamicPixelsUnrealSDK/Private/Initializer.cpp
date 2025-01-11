// Fill out your copyright notice in the Description page of Project Settings.


#include "Initializer.h"

#include "ServiceHub.h"
#include "Models/SystemInfo.h"

bool AInitializer::IsInit = false;
// Sets default values
AInitializer::AInitializer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AInitializer::BeginPlay()
{
	Super::BeginPlay();
	if (IsInit || UServiceHub::IsAuthenticated())
		return;
	auto SI = FSystemInfo();
	SI.DeviceUniqueId = FPlatformMisc::GetLoginId();
	SI.DeviceModel = FPlatformMisc::GetDeviceMakeAndModel();
	SI.DeviceName = FPlatformMisc::GetDeviceId();
#if PLATFORM_DESKTOP
	SI.DeviceType = "Desktop";
#elif PLATFORM_ANDROID
	SI->DeviceType = "Android";
#elif PLATFORM_IOS
	SI->DeviceType = "iOS";
#else
	SI->DeviceType = "Unknown";
#endif
	SI.OperatingSystem = FPlatformMisc::GetOSVersion();
	SI.NetworkType = FString();
	SI.ProcessorCount = FPlatformMisc::NumberOfCoresIncludingHyperthreads();
	SI.ProcessorFrequency = -1;
	SI.ProcessorType = FPlatformMisc::GetCPUBrand();
	SI.GraphicsDeviceName = FPlatformMisc::GetPrimaryGPUBrand();
	SI.GraphicsDeviceVendor = FString();
	SI.GraphicsMemorySize = -1;
	UServiceHub::Configure(ClientId, ClientSecret, SI, DebugMode, DevelopmentMode, VerboseMode, ReconnectDelay,
	                      ReconnectMaxAttempt);
	IsInit = true;
}

void AInitializer::BeginDestroy()
{
	Super::BeginDestroy();
	Dispose();
}

void AInitializer::Dispose()
{
	if (!IsInit)return;
	IsInit = false;
	UServiceHub::Dispose();
}

// Called every frame
void AInitializer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
