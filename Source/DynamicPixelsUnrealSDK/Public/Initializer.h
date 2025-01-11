#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Initializer.generated.h"

UCLASS()
class DYNAMICPIXELSUNREALSDK_API AInitializer : public AActor
{
	GENERATED_BODY()

public:
	AInitializer();
	
protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	static void Dispose();

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	FString ClientId;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	FString ClientSecret;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	int16 ReconnectDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	int16 ReconnectMaxAttempt;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	bool DevelopmentMode;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	bool DebugMode;

	UPROPERTY(EditDefaultsOnly, Category = "Initializer")
	bool VerboseMode;

private:
	static bool IsInit;
};
