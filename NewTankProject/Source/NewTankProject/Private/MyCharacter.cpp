// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h" 
#include "Camera/CameraComponent.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	StaticMeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	//Attach our components
	StaticMeshComp->SetupAttachment(RootComponent);
	SpringArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	//Assign SpringArm class variables.
	SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 400.f;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 3.0f;

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Zoom in if ZoomIn button is down, zoom back out if it's not
	{
		if (bZoomingIn)
		{
			ZoomFactor += DeltaTime / 0.5f;         //Zoom in over half a second
		}
		else
		{
			ZoomFactor -= DeltaTime / 0.25f;        //Zoom out over a quarter of a second
		}

		ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);
		//Blend our camera's FOV and our SpringArm's length based on ZoomFactor
		CameraComp->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
		SpringArmComp->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);
	}

	//Rotate our actor's yaw, which will turn our camera because we're attached to it
	{
/*		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation)*/;

		FRotator NewRotation = SpringArmComp->GetComponentRotation();
		//NewRotation.Yaw = FMath::Clamp(NewRotation.Yaw + CameraInput.X, 0, 360);
		NewRotation.Yaw += CameraInput.X * 30.0f * DeltaTime; //30.0f = camera speed -> adjust as needed
		SpringArmComp->SetWorldRotation(NewRotation);
	}

	//Rotate our camera's pitch, but limit it so we're always looking downward
	{
		FRotator NewRotation = SpringArmComp->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f);
		SpringArmComp->SetWorldRotation(NewRotation);
	}

	//Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!MovementInput.IsZero())
		{
			//Scale our movement input axis values by 100 units per second
			MovementInput = MovementInput.GetSafeNormal() * 100.0f;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//text in quotes -> has to match project settings axis mapping name
	//PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); //rotate player
	//PlayerInputComponent->BindAxis("left-right", this, &AMyCharacter::RotateCharacter); //rotate player
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); //vertical camera
	//PlayerInputComponent->BindAxis("forward-backward", this, &AMyCharacter::MoveCharacter); 
	//PlayerInputComponent->BindAxis("left-right", this, &AMyCharacter::MoveRight);

	//Hook up events for "ZoomIn"
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AMyCharacter::ZoomIn);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &AMyCharacter::ZoomOut);

	//Hook up every-frame handling for our four axes
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &AMyCharacter::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AMyCharacter::YawCamera);
}


void AMyCharacter::MoveCharacter(float Value) {
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		
		if (UWorld* World = GetWorld())
		{
			APlayerCameraManager* PlayerCamera = World->GetFirstPlayerController()->PlayerCameraManager;
		}

		const FVector Direction = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}
void AMyCharacter::RotateCharacter(float Value)
{
	//FRotator Rotation = Controller->GetControlRotation();
	//FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	//
	//if(Value) //if not null
	//	AddActorLocalRotation(FRotator(0, Value, 0)); //doesn't work

	if (Value) //if not null
		AddControllerYawInput(Value);

}


//Input functions
void AMyCharacter::MoveForward(float AxisValue)
{
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AMyCharacter::MoveRight(float AxisValue)
{
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AMyCharacter::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void AMyCharacter::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void AMyCharacter::ZoomIn()
{
	bZoomingIn = true;
}

void AMyCharacter::ZoomOut()
{
	bZoomingIn = false;
}