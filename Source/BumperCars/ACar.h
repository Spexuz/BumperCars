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
	void SetHandbreak(bool bNewHandbrakeState);
	void SetBump(bool bNewBumpState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Car Physics")
	UBoxComponent* m_pPhysicsBody;
	UPROPERTY(BlueprintReadOnly, Category="Input")
	float m_fInput_YAxis = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category="Input")
	float m_fInput_XAxis = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category="Input")
	bool m_bIsHandbreaking = false;
	UPROPERTY(BlueprintReadOnly,  Category="Input")
    bool m_bIsBumping = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* m_pSpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* m_pPlayerCamera;

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
};
