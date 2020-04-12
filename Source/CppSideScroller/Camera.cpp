// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "CppSideScrollerCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACamera::ACamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootComp;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetupAttachment(RootComp);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<ACppSideScrollerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	followingPlayer();
}

void ACamera::followingPlayer()
{
	if (player != nullptr)
	{
		FVector playerLocation = player->GetActorLocation();

		targetLocation = FMath::Lerp(targetLocation, playerLocation, lerpSpeed);

		targetLocation.Y = FMath::Clamp(targetLocation.Y + YOffset, rightEdge, leftEdge);
		targetLocation.Z = FMath::Clamp(targetLocation.Z + ZOffset, bottumEdge, topEdge);

		SetActorLocation(targetLocation);
	}
}

void ACamera::ResetCamera_Implementation()
{
	player = Cast<ACppSideScrollerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}