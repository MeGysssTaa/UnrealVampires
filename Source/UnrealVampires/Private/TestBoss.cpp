// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBoss.h"

// Sets default values
ATestBoss::ATestBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	abil = NewObject<UAbility>();
}

// Called when the game starts or when spawned
void ATestBoss::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

// Called every frame
void ATestBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	abil->Cast(DeltaTime);
}

// Called to bind functionality to input
void ATestBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}





bool UAbility::Cast(float DeltaTime)
{
	CooldownRemainingSeconds -= DeltaTime;

	if (CooldownRemainingSeconds > 0.0f)
	{
		return false;
	}

	CooldownRemainingSeconds = 5.0f;
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(DeltaTime));

	return true;
}

