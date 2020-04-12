// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppSideScrollerCharacter.h"

#include "Camera.generated.h"

UCLASS()
class CPPSIDESCROLLER_API ACamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACamera();
	
	ACppSideScrollerCharacter* player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RootComponent)
		USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SpringArm)
		class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		FVector targetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float lerpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float leftEdge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float rightEdge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float topEdge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float bottumEdge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float YOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float ZOffset;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Reset)
		void ResetCamera();
	virtual void ResetCamera_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void followingPlayer();
};
