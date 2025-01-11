// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Table.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICPIXELSUNREALSDK_API UTable : public UObject
{
	GENERATED_BODY()

public:
	static FString AggregationUrl(const FString& TableId)
	{
		return FString::Printf(TEXT("/api/table/%s/aggregation"), *TableId);
	}
	static FString FindUrl(const FString& TableId, const int Skip, const int Limit)
	{
		return FString::Printf(TEXT("/api/table/%s?skip=%d&limit=%d"), *TableId, Skip, Limit);
	}
	static FString FindByIdUrl(const FString& TableId, const int RowId)
	{
		return FString::Printf(TEXT("/api/table/%s/%d"), *TableId, RowId);
	}
	static FString FindByIdAndDeleteUrl(const FString& TableId, const int RowId)
	{
		return FString::Printf(TEXT("/api/table/%s/%d"), *TableId, RowId);
	}
	static FString FindByIdAndUpdateUrl(const FString& TableId, const int RowId)
	{
		return FString::Printf(TEXT("/api/table/%s/%d"), *TableId, RowId);
	}
	static FString InsertUrl(const FString& TableId)
	{
		return FString::Printf(TEXT("/api/table/%s"), *TableId);
	}
	static FString InsertManyUrl(const FString& TableId)
	{
		return FString::Printf(TEXT("/api/table/%s/insert"), *TableId);
	}
	static FString UpdateManyUrl(const FString& TableId)
	{
		return FString::Printf(TEXT("/api/table/%s/update"), *TableId);
	}
	static FString DeleteUrl(const FString& TableId, const int RowId)
	{
		return FString::Printf(TEXT("/api/table/%s/%d"), *TableId, RowId);
	}
	static FString DeleteManyUrl(const FString& TableId)
	{
		return FString::Printf(TEXT("/api/table/%s/delete"), *TableId);
	}
};
