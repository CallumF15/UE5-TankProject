// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h" //place headers before this otherwise crash


UCLASS()
class NEWTANKPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComp;


	//Input variables
	FVector2D MovementInput;
	FVector2D CameraInput;
	float ZoomFactor;
	bool bZoomingIn;

	//Input functions
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	void ZoomIn();
	void ZoomOut();
	 

private:
	UPROPERTY(EditAnywhere)
		float tankMaxSpeed; //maximum speed tank can go

	
	UPROPERTY(EditAnywhere) 
		float tankRotationSpeed; //

	UPROPERTY(EditAnywhere)
		float tankTurretRotSpeed; //speed in which tank turret can turn

	UPROPERTY(EditAnywhere)
		float tankBarrelVertSpeed; // speed in which tank barrel can elevate

	int numberOfCrew; //affects tanks speed/rotation/elevation
	struct gameMode;  //GameMode type -> Arcade/Realistic -> Impacts above

	//Tank Chasis
	float tankForwardSpeed;
	float tankReverseSpeed;
	float tankAccerlation;


	//Tank Turret
	float tankTurretRotationSpeed;
	bool turretIsRotating;

	//Tank Barrel
	float GunBarrelElevationSpeed;


	//void tankMovement();
	//void tankRotation();
	//void tankBarrelElevation();

	//FVector m_startPos;
	void MoveCharacter(float Value);
	//void MoveRight(float Value);
	void RotateCharacter(float Value);
	void CheckPressedKeys();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
