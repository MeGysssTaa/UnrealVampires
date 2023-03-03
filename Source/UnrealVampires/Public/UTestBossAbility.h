// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UCLASS()
class UNREALVAMPIRES_API UTestBossAbility : public UClass
{
	GENERATED_BODY()
	
	float CooldownRemainingSeconds = 5.0f;

public:
	bool Cast(float DeltaTime);
};
