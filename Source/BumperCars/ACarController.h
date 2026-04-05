// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Controller.h"
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

	//Controller Functions
	void Move(const FInputActionValue& InputValues);
	void Turn(const FInputActionValue& InputValues);
};
