// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestBoss.generated.h"

UCLASS()
class UNREALVAMPIRES_API ATestBoss : public ACharacter
{
	GENERATED_BODY()

	UAbility* abil;

public:
	// Sets default values for this character's properties
	ATestBoss();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};

UCLASS()
class UNREALVAMPIRES_API UAbility : public UObject
{
	GENERATED_BODY()

	float CooldownRemainingSeconds = 5.0f;

public:
	bool Cast(float DeltaTime);
};

