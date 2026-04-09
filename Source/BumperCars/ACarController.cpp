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
}

void AACarController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);
	m_pCurrentACar = Cast<AACar>(PossessedPawn);
}

void AACarController::OnUnPossess()
{
	Super::OnUnPossess();
	m_pCurrentACar = nullptr;
}


/**
 * Reads Controller Input and Casts to Controlled Pawn -> SetInput()
 * @param InputValues Enhanced Input Systems: FInputActionValue struct
 */
void AACarController::Move(const FInputActionValue& InputValues)
{
	FVector2D vInput = InputValues.Get<FVector2D>();
	m_pCurrentACar->SetInput(vInput.Y, vInput.X);
}

void AACarController::Bump(const FInputActionValue& InputValues)
{
	bool ButtonStatus = InputValues.Get<bool>();
	m_pCurrentACar->SetBump(ButtonStatus);
}
void AACarController::Handbrake(const FInputActionValue& InputValues)
{
	bool ButtonStatus = InputValues.Get<bool>();
	m_pCurrentACar->SetHandbreak(ButtonStatus);
}


void AACarController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* pEnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	ULocalPlayer* pLocalPlayer = GetLocalPlayer(); //causes nullptr if not declared here for some reason, even though GetLocalPlayer() works in other functions without issue.
	
	UEnhancedInputLocalPlayerSubsystem* pPlayerSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
   	pPlayerSubsystem->AddMappingContext(m_pCarMappingContext, 0);

	pEnhancedInput->BindAction(m_pMoveAction, ETriggerEvent::Triggered, this, &AACarController::Move);
	pEnhancedInput->BindAction(m_pMoveAction, ETriggerEvent::Completed, this, &AACarController::Move);
	pEnhancedInput->BindAction(m_pBumpAction, ETriggerEvent::Triggered, this, &AACarController::Bump);
	pEnhancedInput->BindAction(m_pBumpAction, ETriggerEvent::Completed, this, &AACarController::Bump);
	pEnhancedInput->BindAction(m_pHandbrakeAction, ETriggerEvent::Triggered, this, &AACarController::Handbrake);
	pEnhancedInput->BindAction(m_pHandbrakeAction, ETriggerEvent::Completed, this, &AACarController::Handbrake);
	
	
}