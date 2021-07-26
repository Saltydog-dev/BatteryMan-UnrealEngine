/**
* \File BatteryMan.cpp
* \Author Stéphane Boulanger
* \Source https://www.youtube.com/watch?v=LsNW4FPHuZE&t=4573s
* \Version 0.1
* \date juillet 2021
*/

#include "BatteryMan.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABatteryMan::ABatteryMan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Camera of the player 
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	bUseControllerRotationPitch = false; 
	bUseControllerRotationYaw = false; 
	bUseControllerRotationRoll = false; 

	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f; 
	GetCharacterMovement()->AirControl = 0.2f; 

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 300.0f; 
	CameraBoom->bUsePawnControlRotation = true; 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; 

	// Movement of the player to know if he can move or not 
	bDead = false; 

	Power = 100.0f;

}





// Called when the game starts or when spawned
void ABatteryMan::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABatteryMan::OnBeginOverlap);

	if (Player_Power_Widget_Class != nullptr)
	{
		Player_Power_Widget = CreateWidget(GetWorld(), Player_Power_Widget_Class);
		Player_Power_Widget->AddToViewport();
	}
	
}

// Called every frame
void ABatteryMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Power -= DeltaTime * Power_Treshold; // The life bar going down 

	if (Power <= 0)
	{
		if (!bDead)
		{
			bDead = true; 

			GetMesh()->SetSimulatePhysics(true);

			FTimerHandle UnusedHandle; 
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryMan::RestartGame, 3.0f, false);
		}

	}


}

// Called to bind functionality to input
void ABatteryMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Player can turn with the mouse action 
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Player can jump with the space key 
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Player can move right left froward backward 
	PlayerInputComponent->BindAxis("MoveForward", this, &ABatteryMan::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABatteryMan::MoveRight);


}


// Called by SetupPlayerInputComponent
void ABatteryMan::MoveForward(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}



// Called by SetupPlayerInputComponent
void ABatteryMan::MoveRight(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

void ABatteryMan::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);

}


void ABatteryMan::OnBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Recharge"))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Collided with"));

		Power += 10.0f;

		if (Power > 100.0f)
			Power = 100.0f;

		OtherActor->Destroy();
	}


}