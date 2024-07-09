// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnyWhere, Category="Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category="Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.0f;

	void Move(float Value);
	void Turn(float Value);
	APlayerController* PlayerControllerRef;
};
