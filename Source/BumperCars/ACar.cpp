// Fill out your copyright notice in the Description page of Project Settings.

/*
	Damping ratio:

			   D
	zeta = -----------
		   2 * sqrt(K*M)

	D = damper stiffness
	K = spring stiffness
	M = car mass
	**Note: that Zeta should fall between 0.2 and 0.8. Most Car manufacturers seem to aim for somewhere between 0.5-0.7
	**Higher is Stiffer.
*/


#include "ACar.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AACar::AACar()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0;
	bAsyncPhysicsTickEnabled = true; //Better to Run Physics according to Unreal (Blueprints seem to inherit this but the BP Designer still shows it as disabled, (it will run the node, weird.)

	//Create Physics Body and Assign Root Object
	m_pPhysicsBody = CreateDefaultSubobject<UBoxComponent>(TEXT("PhysicsBody"));
	RootComponent = m_pPhysicsBody;

	//Create Spring Arm & Camera Component.
	m_pSpringArm = CreateDefaultSubobject	<USpringArmComponent>(TEXT("SpringArm"));
	m_pPlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	m_pSpringArm->SetupAttachment	(m_pPhysicsBody);
	m_pPlayerCamera->SetupAttachment(m_pSpringArm);
}

void AACar::BeginPlay()
{
	Super::BeginPlay();
	//Call Super to Run Parent
}

void AACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			1,
			0.f,
			FColor::Green,
			FString::Printf(
				TEXT("Steering: %.2f | Throttle: %.2f | Handbrake: %s | Bump: %s"),
				m_fInput_XAxis,
				m_fInput_YAxis,
				m_bIsHandbreaking ? TEXT("True") : TEXT("False"),
				m_bIsBumping ? TEXT("True") : TEXT("False")
			)
		);
	}
	
}

void AACar::AsyncPhysicsTickActor(float DeltaTime, float SimTime)
{
	Super::AsyncPhysicsTickActor(DeltaTime, SimTime);
}


/**
 *  Reads Internal Movement Values from Controller and Applies Force in Appropriate Direction
 */
void AACar::WheelInput()
{
	
}

/**
 *  Reads Internal Movement Values from Controller and Applies Force in Appropriate Direction
 */
void AACar::PedalInput()
{
	
}

void AACar::SimulateSuspension()
{
	
}

/**
 * Sets the Cars Internal Y (Forward) & X (Turn)  Input Values
 * The Car later Reads these values to Apply Force
 *
 *  @param fXAxis float
 *  @param fYAxis float
 */
void AACar::SetInput(float fYAxis, float fXAxis)
{
	m_fInput_YAxis = fYAxis;
	m_fInput_XAxis = fXAxis;
}

void AACar::SetHandbreak(bool bNewHandbrakeState)
{
    m_bIsHandbreaking = bNewHandbrakeState;
}

void AACar::SetBump(bool bNewBumpState)
{
    m_bIsBumping = bNewBumpState;
	//Implement Bump/Speed Logic
}


// Called to bind functionality to input
void AACar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

