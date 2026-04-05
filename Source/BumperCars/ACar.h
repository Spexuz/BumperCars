// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ACar.generated.h"

class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BUMPERCARS_API AACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AACar();
	// Read Input Storage and Apply Force to Car. Called by ACarController.
	void SetInput(float fYAxis, float fXAxis);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Car Physics")
	UBoxComponent* m_pPhysicsBody;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AsyncPhysicsTickActor(float DeltaTime, float SimTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Functions
	void PedalInput();
	void WheelInput();
	void SimulateSuspension();

	//Input Storage
	float m_fInput_YAxis;
	float m_fInput_XAxis;

	//ENGINE VALUES TODO: Torque Curve
	UPROPERTY(EditAnywhere, Category = "Engine")
	float m_fEngineForce = 120000.0f;

	//COMPONENTS
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* m_pSpringArm;
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* m_pPlayerCamera;
	
};
