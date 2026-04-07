// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACar.h"
#include "InputActionValue.h"
#include "ACarController.generated.h"

/**
 * 
 */

//Declare IMC, IA and Input Struct
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class BUMPERCARS_API AACarController : public APlayerController
{
	GENERATED_BODY()

public:
	//Call Constructor
	AACarController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* PossessedPawn) override;
	virtual void OnUnPossess() override;
	
private:
	//Variables
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* m_pCarMappingContext;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_pMoveAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_pBumpAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_pHandbrakeAction;

	//Pawn Reference
	UPROPERTY(EditAnywhere)
	TObjectPtr<AACar> m_pCurrentACar = nullptr;

	//Controller Functions
	void Move(const FInputActionValue& InputValues);
	void Bump(const FInputActionValue& InputValues);
	void Handbrake(const FInputActionValue& InputValues);
};
