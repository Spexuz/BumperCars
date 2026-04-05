// Fill out your copyright notice in the Description page of Project Settings.

#include "ACarController.h"

#include "ACar.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AACarController::AACarController()
{
	m_pCarMappingContext = nullptr;
	m_pMoveAction = nullptr;
	m_pBumpAction = nullptr;
	m_pHandbrakeAction = nullptr;
}

void AACarController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* pPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	pPlayerSubsystem->AddMappingContext(m_pCarMappingContext, 0);
}

/**
 * Reads Controller Input and Casts to Controlled Pawn -> SetInput()
 * @param InputValues Enhanced Input Systems: FInputActionValue struct
 */
void AACarController::Move(const FInputActionValue& InputValues)
{
	//Get Input Values
	FVector2D vInput = InputValues.Get<FVector2D>();
	//Find our Controlled Pawn
	AACar* pCar = Cast<AACar>(GetPawn());
	pCar->SetInput(vInput.Y, vInput.X);
		
}


void AACarController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* pEnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);

	pEnhancedInput->BindAction(m_pMoveAction, ETriggerEvent::Triggered, this, &AACarController::Move);
	pEnhancedInput->BindAction(m_pMoveAction, ETriggerEvent::Completed, this, &AACarController::Move);
	
	
}